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
		
		//we're scaling up into a
		memset(a, '\0', esizeA);
		be_memcpy(a + esizeA, b + esizeB, copySize);
		
		unsigned char *factorA = api -> getDecimalScalingFactor(esizeA);
		unsigned char *factorB = api -> getDecimalScalingFactor(esizeB);
		
		unsigned char *dfactor = malloc(esizeA);
		memcpy(dfactor, factorA, esizeA);
		hw_div(dfactor, esizeA, factorB, esizeB);
		hw_mul(a, esizeA, dfactor, esizeA);
		free(dfactor);
		}
		else if (esizeB > esizeA)
		{
		size_t copySize = esizeA;
		
		//we're scaling down into a
		unsigned char *factorA = api -> getDecimalScalingFactor(esizeA);
		unsigned char *factorB = api -> getDecimalScalingFactor(esizeB);
		
		unsigned char *tmp = malloc(esizeB);
		memcpy(tmp, b, esizeB);
		
		unsigned char *dfactor = malloc(esizeB);
		memcpy(dfactor, factorB, esizeB);
		hw_div(dfactor, esizeB, factorA, esizeA);
		hw_div(tmp, esizeB, dfactor, esizeB);
		free(dfactor);
		
		memset(a, '\0', esizeA);
		be_memcpy(a + esizeA, tmp + esizeB, copySize);
		
		free(tmp);
		}
	}

static uint8 xr[sizeof(size_t)*4];
static void hw_dec_mul(uint8 *x, size_t xs, uint8 *y, size_t ys)
	{
	size_t xrs = xs * 2;
	//generic version (for any size input) would allocate xs*2; we avoid this for efficiency, instead using the static xr declared above
	//uint8 *xr = malloc(xrs);
	
	assignDecimal(xr, xrs, x, xs);
	
	unsigned char *sf = api -> getDecimalScalingFactor(ys);
	hw_div(xr, xrs, (uint8*) sf, ys);
	
	hw_mul(xr, xrs, y, ys);
	
	assignDecimal(x, xs, xr, xrs);
	
	//free(xr);
	}

static void hw_dec_div(uint8 *x, size_t xs, uint8 *y, size_t ys)
	{
	size_t xrs = xs * 2;
	uint8 *xr = malloc(xrs);
	
	assignDecimal(xr, xrs, x, xs);
	
	hw_div(xr, xrs, y, ys);
	
	unsigned char *sf = api -> getDecimalScalingFactor(ys);
	hw_mul(xr, xrs, (uint8*) sf, ys);
	
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

#define DEC_WIDTH (sizeof(size_t)*2)

//NOTE: the Nth root and Nth power functions are in some way the inverse of each other
// - raising something to the power of 0.5 is the same as applying the square root
// - so we either need an Nth root function, or an Nth power function (that works on fractional powers), and then we have both
INSTRUCTION_DEF op_sqrt_dec(INSTRUCTION_PARAM_LIST)
	{
	//char *str;
	
	//this is a *SLOW* way to do this: first we get the square root of the integer part (which is fast), reusing op_sqrt_int for this
	// - then we get the square root of the integer+fraction part (slowly!!!) by homing in on the correct fraction using an up/down search
	// - the fraction part is just brute force and its performance needs to be massively improved!! [TODO]
	
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
	
	unsigned char *sf = api -> getDecimalScalingFactor(DEC_WIDTH);
	hw_div(val, DEC_WIDTH, (uint8*) sf, DEC_WIDTH);
	
	hw_lshift(val, DEC_WIDTH, sizeof(size_t) * 8);
	
	op_sqrt_int(cframe);
	
	unsigned char *result = &cframe -> localsData[((DanaType*) ((StructuredType*) cframe -> scopes[0].scope.etype) -> structure.content)[0].offset];
	hw_rshift(result, DEC_WIDTH, sizeof(size_t) * 8);
	hw_mul(result, DEC_WIDTH, (uint8*) sf, DEC_WIDTH);
	
	//now square root the fractional part (really slowly!!! - TODO, increase performance!)
	unsigned char ten = 10;
	
	unsigned char x[DEC_WIDTH];
	memset(x, '\0', DEC_WIDTH);
	
	unsigned char y[DEC_WIDTH];
	memset(y, '\0', DEC_WIDTH);
	
	unsigned char z[DEC_WIDTH];
	memset(z, '\0', DEC_WIDTH);
	
	x[DEC_WIDTH-1] = 1;
	hw_mul(x, DEC_WIDTH, sf, DEC_WIDTH);
	hw_div(x, DEC_WIDTH, &ten, 1);
	
	memcpy(y, result, DEC_WIDTH);
	
	/*
	// - grab the fractional part in "vc" by subtracting the integer part (after truncating it by scaling down then up)
	hw_div(vb, DEC_WIDTH, (uint8*) sf -> factor, sf -> byteWidth);
	hw_mul(vb, DEC_WIDTH, (uint8*) sf -> factor, sf -> byteWidth);
	hw_sub(vc, DEC_WIDTH, vb, DEC_WIDTH);
	*/
	
	// - now find the square root of this fractional part, starting from the integer root with no fraction
	memcpy(z, result, DEC_WIDTH);
	
	bool up = true;
	while (memcmp(z, va, DEC_WIDTH) != 0)
		{
		if (up)
			hw_add(y, DEC_WIDTH, x, DEC_WIDTH);
			else
			hw_sub(y, DEC_WIDTH, x, DEC_WIDTH);
		
		// - multiply the two together to see if this gives us the original input value
		memcpy(z, y, DEC_WIDTH);
		hw_dec_mul(z, DEC_WIDTH, y, DEC_WIDTH);
		
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
	
	// - update the result with the full integer+fraction
	memcpy(result, y, DEC_WIDTH);
	
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
