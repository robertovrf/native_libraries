//software-based arithmetic unit

#include "alu.h"

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

uint8 hw_add_u8(uint8 *x, uint8 y, uint8 ic)
	{
	uint8 i = 0;
	uint8 zr = 0;
	
	for (i = 0; i < 8; i++)
		{
		//extract the next bit of each side
		uint8 xb = *x >> i;
		xb = xb & 0x1;
		
		uint8 yb = y >> i;
		yb = yb & 0x1;
		
		//printf("bit comp %u: x %u y %u c %u\n", i, xb, yb, ic);
		
		//c/x/y:
		//1/1/1 = x1 c1
		//1/1/0 = x0 c1
		//1/0/0 = x1 c0
		//0/1/1 = x0 c1
		//0/1/0 = x1 c0
		
		uint8 res = (xb ^ yb) ^ ic;
		ic = ((xb ^ yb) & ic) | (xb & yb);
		
		zr = zr | (res << i);
		
		//printf(" - z gets a %u to be %u\n", res, zr);
		}
	
	*x = zr;
	return ic;
	}

//ys MUST be <= xs
void hw_add(uint8 *x, size_t xs, uint8 *y, size_t ys)
	{
	xs --;
	ys --;
	
	uint8 c = 0;
	
	while (ys != SIZE_MAX)
		{
		c = hw_add_u8(&x[xs], y[ys], c);
		ys --;
		xs --;
		}
	
	while (xs != SIZE_MAX)
		{
		c = hw_add_u8(&x[xs], 0, c);
		xs --;
		}
	}

//big-endian any-size left-shift
void hw_lshift(uint8 *b, size_t sz, size_t amt)
	{
	size_t i = 0;
	
	for (i = 0; i < sz; i++)
		{
		//things start to get screwy if we shift by greater than 31 (who knew!?), so we constrain the machine-shift to 8
		b[i] = amt < 8 ? b[i] << amt : 0;
		
		size_t j = 0;
		size_t lj = 8;
		for (j = i+1; j < sz; j++)
			{
			if (amt > lj) //I want the *lower* (or left-hand-side) part of this byte
				b[i] |= amt - lj < 8 ? b[j] << (amt - lj) : 0;
				else //I want the *upper* (or right-hand-side) part of this byte
				b[i] |= lj - amt < 8 ? b[j] >> (lj - amt) : 0;
			lj += 8;
			}
		}
	}

//big-endian any-size right-shift
void hw_rshift(uint8 *b, size_t sz, size_t amt)
	{
	size_t i = 0;
	
	for (i = sz-1; i != SIZE_MAX; i--)
		{
		//things start to get screwy if we shift by greater than 31 (who knew!?), so we constrain the machine-shift to 8
		b[i] = amt < 8 ? b[i] >> amt : 0;
		
		size_t j = 0;
		size_t lj = 8;
		for (j = i-1; j != SIZE_MAX; j--)
			{
			if (amt > lj) //I want the *upper* (or left-hand-side) part of this byte
				b[i] |= amt - lj < 8 ? b[j] >> (amt - lj) : 0;
				else //I want the *lower* (or right-hand-side) part of this byte
				b[i] |= lj - amt < 8 ? b[j] << (lj - amt) : 0;
			lj += 8;
			}
		}
	}

//xs and yx can be any sizes
void hw_mul(uint8 *x, size_t xs, uint8 *y, size_t ys)
	{
	uint8 i = 0;
	uint8 j = 0;
	size_t k = 0;
	size_t p = 0;
	uint8 *zr = malloc(xs);
	uint8 *br = malloc(xs);
	
	memset(zr, '\0', xs);
	
	//printf("MUL %u x %u; starting @ %u\n", x[0], y[0], ((unsigned int*) z)[0]);
	
	ys --;
	
	for (k = ys; k != SIZE_MAX; k--)
		{
		for (i = 0; i < 8; i++)
			{
			uint8 yb = y[k] >> i;
			yb = yb & 0x1;
			
			memset(br, '\0', xs);
			for (p = xs - 1; p != SIZE_MAX; p--)
				{
				for (j = 0; j < 8; j++)
					{
					//extract the next bit of each side
					uint8 xb = x[p] >> j;
					xb = xb & 0x1;
					
					//printf("bit comp %u: x %u y %u c %u\n", i, xb, yb, ic);
					
					uint8 res = xb & yb;
					
					br[p] = br[p] | (res << j);
					
					//printf(" - z gets a %u\n", res);
					}
				}
			
			//printf("|br| Round %u/%u : %u << %u\n", k, i, ((unsigned int*) br)[0], (k*8) + i);
			
			//perform the any-size bitshift (br << (k*8) + i)
			hw_lshift(br, xs, ((ys - k)*8) + i);
			
			//printf("|brpp| Round %u/%u : %u\n", k, i, ((unsigned int*) br)[0]);
			
			//printf("Round %u/%u\n", k, i);
			
			//perform the any-size summation for this round
			hw_add(zr, xs, br, xs);
			
			//printf("Round %u/%u : %u\n", k, i, ((unsigned int*) z)[0]);
			}
		}
	
	memcpy(x, zr, xs);
	
	free(br);
	free(zr);
	}

//ys MUST be <= xs
void hw_sub(uint8 *x, size_t xs, uint8 *y, size_t ys)
	{
	uint8 xa = 1;
	
	unsigned char *ox = x;
	uint8 oxs = xs;
	
	uint8 c = 0;
	
	ys --;
	xs --;
	
	while (ys != SIZE_MAX)
		{
		c = hw_add_u8(&x[xs], ~y[ys], c);
		ys --;
		xs --;
		}
	
	while (xs != SIZE_MAX)
		{
		c = hw_add_u8(&x[xs], 255, c);
		xs --;
		}
	
	hw_add(ox, oxs, &xa, 1);
	}

//ys MUST be <= xs
bool hw_gteq(uint8 *x, size_t xs, uint8 *y, size_t ys)
	{
	xs --;
	ys --;
	
	while (xs > ys)
		{
		if (x[0] != 0)
			{
			return true;
			}
		
		xs --;
		x ++;
		}
	
	while (xs != SIZE_MAX)
		{
		if (x[0] > y[0])
			{
			return true;
			}
			else if (x[0] < y[0])
			{
			return false;
			}
		
		xs --;
		x ++;
		y ++;
		}
	
	return true;
	}

//http://en.wikipedia.org/wiki/Division_(digital)

//ys MUST be <= xs
void hw_div(uint8 *x, size_t xs, uint8 *y, size_t ys)
	{
	//if D == 0 then throw DivisionByZeroException end
	
	//initialize quotient and remainder to zero
	uint8 *Q = malloc(xs);
	uint8 *R = malloc(xs);
	uint8 *YC = malloc(ys);
	
	memset(Q, '\0', xs);
	memset(R, '\0', xs);
	
	//uint8 *q = &Q[xs-1];
	uint8 *q = Q;
	uint8 qi = 7;
	
	/*
	unsigned int qn = 0;
	unsigned int rn = 0;
	unsigned int yn = 0;
	memcpy(&qn, Q, 2);
	memcpy(&rn, R, 2);
	memcpy(&yn, y, 2);
	printf(".Q: %u\n", qn);
	printf(".R: %u\n", rn);
	printf(".D: %u\n", yn);
	*/
	
	size_t i;
	for (i = 0; i < xs; i++)
		{
		uint8 bc = 0;
		for (bc = 0; bc < 8; bc ++)
			{
			//R = R << 1; //left-shift R by 1 bit     
			hw_lshift(R, xs, 1);
			
			//printf("bit %u n: %u\n", i, x[0] & 0x80 ? 0x01 : 0x00);
			
			R[xs-1] |= x[0] & 0x80 ? 0x01 : 0x00; //set the least-significant bit of R equal to bit i of the numerator
			hw_lshift(x, xs, 1);
			
			/*
			memcpy(&qn, Q, 2);
			memcpy(&rn, R, 2);
			memcpy(&yn, y, 2);
			printf("Q: %u\n", qn);
			printf("R: %u\n", rn);
			printf("D: %u\n", yn);
			*/
			
			if (hw_gteq(R, xs, y, ys))
				{
				//printf("GTy bit %u @ qi %u\n", i, qi);
				
				memcpy(YC, y, ys);
				hw_sub(R, xs, YC, ys);
				*q |= 0x01 << qi;
				
				/*
				memcpy(&qn, Q, 2);
				memcpy(&rn, R, 2);
				memcpy(&yn, y, 2);
				printf(" - Q: %u\n", qn);
				printf(" - R: %u\n", rn);
				printf(" - D: %u\n", yn);
				*/
				}
			
			qi --;
			if (qi == 255)
				{
				q ++;
				qi = 7;
				}
			}
		}
	
	memcpy(x, Q, xs);
	
	/*
	unsigned int h = 0;
	for (h = 0; h < xs; h++)
		printf("H: %u\n", x[h]);
	*/
	
	/*
	memcpy(&qn, Q, 2);
	memcpy(&rn, R, 2);
	printf("--\n");
	printf("Q: %u\n", qn);
	printf("R: %u\n", rn);
	*/
	
	free(Q);
	free(R);
	free(YC);
	}

void hw_mod(uint8 *x, size_t xs, uint8 *y, size_t ys)
	{
	//if D == 0 then throw DivisionByZeroException end
	
	//initialize quotient and remainder to zero
	uint8 *Q = malloc(xs);
	uint8 *R = malloc(xs);
	uint8 *YC = malloc(ys);
	
	memset(Q, '\0', xs);
	memset(R, '\0', xs);
	
	//uint8 *q = &Q[xs-1];
	uint8 *q = Q;
	uint8 qi = 7;
	
	/*
	unsigned int qn = 0;
	unsigned int rn = 0;
	unsigned int yn = 0;
	memcpy(&qn, Q, 2);
	memcpy(&rn, R, 2);
	memcpy(&yn, y, 2);
	printf(".Q: %u\n", qn);
	printf(".R: %u\n", rn);
	printf(".D: %u\n", yn);
	*/
	
	size_t i;
	for (i = 0; i < xs; i++)
		{
		uint8 bc = 0;
		for (bc = 0; bc < 8; bc ++)
			{
			//R = R << 1; //left-shift R by 1 bit     
			hw_lshift(R, xs, 1);
			
			//printf("bit %u n: %u\n", i, x[0] & 0x80 ? 0x01 : 0x00);
			
			R[xs-1] |= x[0] & 0x80 ? 0x01 : 0x00; //set the least-significant bit of R equal to bit i of the numerator
			hw_lshift(x, xs, 1);
			
			/*
			memcpy(&qn, Q, 2);
			memcpy(&rn, R, 2);
			memcpy(&yn, y, 2);
			printf("Q: %u\n", qn);
			printf("R: %u\n", rn);
			printf("D: %u\n", yn);
			*/
			
			if (hw_gteq(R, xs, y, ys))
				{
				//printf("GTy bit %u @ qi %u\n", i, qi);
				
				memcpy(YC, y, ys);
				hw_sub(R, xs, YC, ys);
				*q |= 0x01 << qi;
				
				/*
				memcpy(&qn, Q, 2);
				memcpy(&rn, R, 2);
				memcpy(&yn, y, 2);
				printf(" - Q: %u\n", qn);
				printf(" - R: %u\n", rn);
				printf(" - D: %u\n", yn);
				*/
				}
			
			qi --;
			if (qi == 255)
				{
				q ++;
				qi = 7;
				}
			}
		}
	
	memcpy(x, R, xs);
	
	/*
	unsigned int h = 0;
	for (h = 0; h < xs; h++)
		printf("H: %u\n", x[h]);
	*/
	
	/*
	memcpy(&qn, Q, 2);
	memcpy(&rn, R, 2);
	printf("--\n");
	printf("Q: %u\n", qn);
	printf("R: %u\n", rn);
	*/
	
	free(Q);
	free(R);
	free(YC);
	}

void hw_not(uint8 *x, size_t xs)
	{
	size_t i = 0;
	for (i = 0; i < xs; i++)
		{
		x[i] = ~x[i];
		}
	}

void hw_and(uint8 *x, size_t xs, uint8 *y, size_t ys)
	{
	uint8 i = 0;
	for (i = 0; i < ys; i++)
		{
		x[i] = x[i] & y[i];
		}
	
	for (; i < xs; i++)
		{
		x[i] = 0;
		}
	}

void hw_or(uint8 *x, size_t xs, uint8 *y, size_t ys)
	{
	uint8 i = 0;
	for (i = 0; i < ys; i++)
		{
		x[i] = x[i] | y[i];
		}
	}
