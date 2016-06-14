//Written by Barry Porter, 2016

#include "dana_lib_defs.h"
#include "nli_util.h"
#include "vmi_util.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef WINDOWS
#include <Windows.h>
#endif

#ifdef LINUX
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#endif

#include <sys/stat.h>

#include <math.h>

#include "alu.h"

#include "int_util.h"

typedef struct __sf{
	unsigned int byteWidth; //this is how many bytes the scaling factor number is (i.e. the below array length)
	unsigned char *factor;
	unsigned int zeroCount;
	} ScalingFactor;

//we index into this array by (totalByteWidth/2)-1:
//TODO: fill this with literal unsigned char arrays representing the Dana-endian scaling factors for decimals 16 bits an upwards (100, 10000, 1000000000, ...)
static ScalingFactor scalingFactors[] = {
										{1, (unsigned char[]){100}, 2}, //100 (16 bit numbers)
										{2, (unsigned char[]){39, 16}, 4}, //10000 (32 bit numbers)
										{0, 0, 0},
										{4, (unsigned char[]){59, 154, 202, 0}, 9}, //10000000000 (64 bit numbers)
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{8, (unsigned char[]){138, 199, 35, 4, 137, 232, 0, 0}, 19}, //10000000000 (128 bit numbers)
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{16, (unsigned char[]){75, 59, 76, 168, 90, 134, 196, 122, 9, 138, 34, 64, 0, 0, 0, 0}, 38}, //10000000000 (256 bit numbers)
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{32, (unsigned char[]){221, 21, 254, 134, 175, 250, 217, 18, 73, 239, 14, 183, 19, 243, 158, 190, 170, 152, 123, 110, 111, 210, 160, 0, 0, 0, 0, 0, 0, 0, 0,0}, 77}, //10000000000 (512 bit numbers)
										{64, (unsigned char[]){190, 238, 251, 88, 74, 255, 134, 3, 170, 251, 85, 15, 250, 207, 216, 250, 92, 164, 126, 79, 136, 212, 83, 113, 39, 203, 210, 254, 98, 20, 95, 8, 69, 68, 182, 83, 53, 81, 85, 182, 175, 153, 212, 10, 228, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 154} //10000000000 (1024 bit numbers)
										};

static CoreAPI *api;

static bool isZero(unsigned char *b, size_t s)
	{
	size_t i = 0;
	for (i = 0; i < s; i++)
		{
		if (b[i] != 0) return false;
		}
	
	return true;
	}

static void be_memcpy(unsigned char *to, unsigned char *from, size_t len)
	{
	to --;
	from --;
	for (; len > 0; len --)
		{
		*to = *from;
		to --;
		from --;
		}
	}

static void assignDecimal(unsigned char *a, size_t esizeA, unsigned char *b, size_t esizeB)
	{
	if (esizeA == esizeB)
		{
		size_t copySize = esizeA;
		memset(a, '\0', esizeA);
		be_memcpy(a + esizeA, b + esizeB, copySize);
		}
		else if (esizeA > esizeB)
		{
		size_t copySize = esizeB;
		
		//printf("scaling up [%u:%u -- %u]...\n", esizeA, esizeB, copySize);
		
		//we're scaling up into a
		memset(a, '\0', esizeA);
		be_memcpy(a + esizeA, b + esizeB, copySize);
		
		ScalingFactor *factorA = &scalingFactors[(esizeA/2)-1];
		ScalingFactor *factorB = &scalingFactors[(esizeB/2)-1];
		
		unsigned char *dfactor = malloc(factorA -> byteWidth);
		memcpy(dfactor, factorA -> factor, factorA -> byteWidth);
		hw_div(dfactor, factorA -> byteWidth, factorB -> factor, factorB -> byteWidth);
		hw_mul(a, esizeA, dfactor, factorA -> byteWidth);
		free(dfactor);
		}
		else if (esizeB > esizeA)
		{
		size_t copySize = esizeA;
		
		//printf("scaling down [%u:%u -- %u]...\n", esizeA, esizeB, copySize);
		
		//we're scaling down into a
		ScalingFactor *factorA = &scalingFactors[(esizeA/2)-1];
		ScalingFactor *factorB = &scalingFactors[(esizeB/2)-1];
		
		unsigned char *tmp = malloc(esizeB);
		memcpy(tmp, b, esizeB);
		
		unsigned char *dfactor = malloc(factorB -> byteWidth);
		memcpy(dfactor, factorB -> factor, factorB -> byteWidth);
		hw_div(dfactor, factorB -> byteWidth, factorA -> factor, factorA -> byteWidth);
		hw_div(tmp, esizeB, dfactor, factorB -> byteWidth);
		free(dfactor);
		
		memset(a, '\0', esizeA);
		be_memcpy(a + esizeA, tmp + esizeB, copySize);
		
		free(tmp);
		
		//TODO: rounding...?
		}
	}

static void hw_dec_mul(uint8 *x, size_t xs, uint8 *y, size_t ys)
	{
	size_t xrs = xs * 2;
	uint8 *xr = malloc(xrs);
	
	assignDecimal(xr, xrs, x, xs);
	
	ScalingFactor *sf = &scalingFactors[(ys/2)-1];
	hw_div(xr, xrs, (uint8*) sf -> factor, sf -> byteWidth);
	
	hw_mul(xr, xrs, y, ys);
	
	assignDecimal(x, xs, xr, xrs);
	
	free(xr);
	}

static void hw_dec_div(uint8 *x, size_t xs, uint8 *y, size_t ys)
	{
	size_t xrs = xs * 2;
	uint8 *xr = malloc(xrs);
	
	assignDecimal(xr, xrs, x, xs);
	
	hw_div(xr, xrs, y, ys);
	
	ScalingFactor *sf = &scalingFactors[(ys/2)-1];
	hw_mul(xr, xrs, (uint8*) sf -> factor, sf -> byteWidth);
	
	assignDecimal(x, xs, xr, xrs);
	
	free(xr);
	}

static void hw_pow(uint8 *x, size_t xs, uint8 *y, size_t ys)
	{
	unsigned char one = 1;
	unsigned char *tx = malloc(xs);
	memcpy(tx, x, xs);
	hw_sub(y, ys, &one, 1);
	while (! isZero(y, ys))
		{
		hw_mul(x, xs, tx, xs);
		hw_sub(y, ys, &one, 1);
		}
	free(tx);
	}

static bool hw_gt(uint8 *x, size_t xs, uint8 *y, size_t ys)
	{
	size_t i = 0;
	
	for (i = 0; i < xs; i++)
		{
		if (x[i] > y[i])
			return true;
			else if (y[i] > x[i])
			return false;
		}
	
	return false;
	}

static bool hw_gr_eq(uint8 *x, size_t xs, uint8 *y, size_t ys)
	{
	size_t i = 0;
	
	for (i = 0; i < xs; i++)
		{
		if (x[i] > y[i])
			return true;
			else if (x[i] < y[i])
			return false;
		}
	
	return true;
	}

static void printBinary(unsigned char *b, size_t s)
	{
	size_t i = 0;
	for (i = 0; i < s; i++)
		{
		if (i != 0) printf(".");
		printf("%u", b[i]);
		}
	}

#define INT_WIDTH (sizeof(size_t))

INSTRUCTION_DEF op_sqrt_int(INSTRUCTION_PARAM_LIST)
	{
	//TODO: allow this to work on 1024-bit integers, but make it fast so that it ignores any empty bytes from the left
	// - also figure out what size of integer it can return
	
	//the below version is one that will work with any size of integer
	/*
	//http://stackoverflow.com/questions/1623375/writing-your-own-square-root-function
	//NOTE: in the below pseudocode, "floor" just means use integer division
	x = 2^ceil(numbits(N)/2)
	loop:
		y = floor((x + floor(N/x))/2)
		if y >= x
			return x
		x = y
	*/
	
	unsigned char *val = getVariableContent(cframe, 0);
	//char *str;
	
	unsigned char t1[INT_WIDTH];
	memset(t1, '\0', INT_WIDTH);
	
	unsigned char x[INT_WIDTH];
	memset(x, '\0', INT_WIDTH);
	
	unsigned char y[INT_WIDTH];
	memset(y, '\0', INT_WIDTH);
	
	//NOTE: these first three steps are always the same, so should be precomputed!
	//numbits(N)
	unsigned char nb[INT_WIDTH];
	memset(nb, '\0', INT_WIDTH);
	nb[INT_WIDTH-1] = INT_WIDTH * 8;
	
	//q = numbits(N)/2
	unsigned char two = 2;
	hw_div(nb, INT_WIDTH, &two, 1);
	
	//str = int_toString(nb, INT_WIDTH);
	//printf("Int dv: %s\n", str);
	
	//x = 2 ^ q
	x[INT_WIDTH-1] = 2;
	
	hw_pow(x, INT_WIDTH, nb, INT_WIDTH);
	
	//TODO: x generally starts at a number that's surely too large for most input values (why start at any value larger than the input??)
	// - should we check for x greater than the input value here, and if so set x to the input value?
	
	//str = int_toString(x, INT_WIDTH);
	//printf("Int pw: %s\n", str);
	
	//printf("2^q: "); printBinary(x, INT_WIDTH); printf("\n");
	
	while (true)
		{
		//y = floor((x + floor(N/x))/2)
		
		memcpy(t1, val, INT_WIDTH);
		hw_div(t1, INT_WIDTH, x, INT_WIDTH);
		hw_add(t1, INT_WIDTH, x, INT_WIDTH);
		hw_div(t1, INT_WIDTH, &two, 1);
		
		memcpy(y, t1, INT_WIDTH);
		
		//printf(" -- y: "); printBinary(y, INT_WIDTH); printf("\n");
		//str = int_toString(y, INT_WIDTH); printf(" -- |  %s\n", str);
		//printf(" -- x: "); printBinary(x, INT_WIDTH); printf("\n");
		//str = int_toString(x, INT_WIDTH); printf(" -- |  %s\n", str);
		
		//if y >= x
		if (hw_gr_eq(y, INT_WIDTH, x, INT_WIDTH))
			{
			//printf(" -- done\n");
			break;
			}
		
		//x = y
		memcpy(x, y, INT_WIDTH);
		}
	
	unsigned char *result = &cframe -> localsData[((DanaType*) ((StructuredType*) cframe -> scopes[0].scope.etype) -> structure.content)[0].offset];
	memcpy(result, x, INT_WIDTH);
	
	return RETURN_DIRECT;
	}

static char* dec_toString(unsigned char *val, size_t len)
	{
	char *res = NULL;
	size_t reslen = 0;
	
	unsigned char *value = val;
	unsigned int esize = len;
	
	unsigned int scalingFactor = scalingFactors[(esize/2)-1].zeroCount;
	
	if (isZero(value, esize))
		{
		res = malloc(sizeof(char) * 3);
		memcpy(res, "0.0", 3);
		reslen = 3;
		}
		else
		{
		// - integer part -
		unsigned char *val = malloc(esize);
		unsigned char *cpy = malloc(esize);
		
		memcpy(val, value, esize);
		
		uint8 divisor = 10;
		
		while (!isZero(val, esize))
			{
			memcpy(cpy, val, esize);
			
			hw_div(val, esize, &divisor, 1);
			hw_mod(cpy, esize, &divisor, 1);
			
			//"cpy" must be <= 9; get the last byte
			uint8 rk = cpy[esize - 1];
			
			char s = "0123456789"[rk];
			
			reslen ++;
			res = realloc(res, reslen);
			
			//copy up
			size_t j = 0;
			for (j = reslen-1; j > 0; j--)
				{
				res[j] = res[j-1];
				}
			
			res[0] = s;
			}
		
		//insert a decimal point
		
		int remainingDigits = reslen;
		if (remainingDigits <= scalingFactor)
			{
			int diff = scalingFactor - reslen;
			char *tr = malloc(reslen + diff);
			tr[0] = '0';
			tr[1] = '.';
			
			int i = 2;
			int j = 0;
			for (j = 0; j < diff; j++)
				{
				tr[i] = '0';
				i ++;
				}
			
			for (j = 0; j < reslen; j++)
				{
				tr[i] = res[j];
				i ++;
				}
			
			free(res);
			reslen += diff;
			res = tr;;
			res = tr;
			}
			else
			{
			int i = 0;
			int j = 0;
			char *tr = malloc(reslen + 1);
			
			for (j = 0; j < reslen; j++)
				{
				if (remainingDigits == scalingFactor)
					{
					tr[i] = '.';
					i ++;
					}
				
				tr[i] = res[j];
				
				remainingDigits --;
				i ++;
				}
			
			free(res);
			reslen ++;
			res = tr;
			}
		
		//clean up trailing zeros
		while (res[reslen - 1] == '0' && res[reslen - 2] != '.')
			{
			//res[reslen - 1] = '\0';
			reslen --;
			}
		
		free(val);
		free(cpy);
		}
	
	//res[reslen] = '\0';
	
	return res;
	}

#define DEC_WIDTH (sizeof(size_t)*2)

//NOTE: the Nth root and Nth power functions are in some way the inverse of each other
// - raising something to the power of 0.5 is the same as applying the square root
// - so we either need an Nth root function, or an Nth power function (that works on fractional powers), and then we have both
INSTRUCTION_DEF op_sqrt_dec(INSTRUCTION_PARAM_LIST)
	{
	//char *str;
	
	//this is a *SLOW* way to do this: first we get the square root of the integer part (which is fast), reusing op_sqrt_int for this
	// - then we get the square root of the integer+fraction part (slowly!!!) by homing in on the correct fraction using an up/down search
	// - the performance of the fraction part needs to be massively improved!! [TODO]
	
	unsigned char *val = getVariableContent(cframe, 0);
	
	unsigned char va[DEC_WIDTH];
	memset(va, '\0', DEC_WIDTH);
	
	unsigned char vb[DEC_WIDTH];
	memset(vb, '\0', DEC_WIDTH);
	
	unsigned char vc[DEC_WIDTH];
	memset(vc, '\0', DEC_WIDTH);
	
	memcpy(va, val, DEC_WIDTH);
	memcpy(vb, val, DEC_WIDTH);
	memcpy(vc, val, DEC_WIDTH);
	
	ScalingFactor *sf = &scalingFactors[sizeof(size_t)-1];
	hw_div(val, DEC_WIDTH, (uint8*) sf -> factor, sf -> byteWidth);
	
	hw_lshift(val, DEC_WIDTH, sizeof(size_t) * 8);
	
	op_sqrt_int(cframe);
	
	unsigned char *result = &cframe -> localsData[((DanaType*) ((StructuredType*) cframe -> scopes[0].scope.etype) -> structure.content)[0].offset];
	hw_rshift(result, DEC_WIDTH, sizeof(size_t) * 8);
	hw_mul(result, DEC_WIDTH, (uint8*) sf -> factor, sf -> byteWidth);
	
	//now square root the fractional part (really slowly!!! - TODO, increase performance!)
	unsigned char ten = 10;
	
	unsigned char x[DEC_WIDTH];
	memset(x, '\0', DEC_WIDTH);
	
	unsigned char y[DEC_WIDTH];
	memset(y, '\0', DEC_WIDTH);
	
	unsigned char z[DEC_WIDTH];
	memset(z, '\0', DEC_WIDTH);
	
	unsigned char zc[DEC_WIDTH];
	memset(zc, '\0', DEC_WIDTH);
	
	x[DEC_WIDTH-1] = 1;
	hw_mul(x, DEC_WIDTH, sf -> factor, sf -> byteWidth);
	hw_div(x, DEC_WIDTH, &ten, 1);
	
	// - grab the fractional part by subtracting the integer part (after truncating it by scaling down then up)
	hw_div(vb, DEC_WIDTH, (uint8*) sf -> factor, sf -> byteWidth);
	hw_mul(vb, DEC_WIDTH, (uint8*) sf -> factor, sf -> byteWidth);
	hw_sub(vc, DEC_WIDTH, vb, DEC_WIDTH);
	
	// - now find the square root of this fractional part
	
	// - add the integer part for the comparison
	hw_add(z, DEC_WIDTH, result, DEC_WIDTH);
	
	bool up = true;
	while (memcmp(z, va, DEC_WIDTH) != 0)
		{
		if (up)
			hw_add(y, DEC_WIDTH, x, DEC_WIDTH);
			else
			hw_sub(y, DEC_WIDTH, x, DEC_WIDTH);
		
		// - multiply the two together to see if this gives us the original input value
		memcpy(z, y, DEC_WIDTH);
		hw_add(z, DEC_WIDTH, result, DEC_WIDTH);
		memcpy(zc, z, DEC_WIDTH);
		
		hw_dec_mul(z, DEC_WIDTH, zc, DEC_WIDTH);
		
		//if we've gone "past" the answer in the direction of travel, start adding/subtracting a 10th of the previous fraction value, and reverse the direction of travel
		if (up)
			{
			if (hw_gt(z, DEC_WIDTH, va, DEC_WIDTH))
				{
				up = false;
				hw_div(x, DEC_WIDTH, &ten, 1);
				
				if (isZero(x, DEC_WIDTH))
					break;
				}
			}
			else
			{
			if (hw_gt(va, DEC_WIDTH, z, DEC_WIDTH))
				{
				up = true;
				hw_div(x, DEC_WIDTH, &ten, 1);
				
				if (isZero(x, DEC_WIDTH))
					break;
				}
			}
		}
	
	// - copy the fractional part into the full result
	hw_add(result, DEC_WIDTH, y, DEC_WIDTH);
	
	return RETURN_DIRECT;
	}

Interface* load(CoreAPI *capi)
	{
	api = capi;
	
	setInterfaceFunction("sqrt", op_sqrt_int);
	setInterfaceFunction("sqrtDec", op_sqrt_dec);
	
	return getPublicInterface();
	}

void unload()
	{
	}
