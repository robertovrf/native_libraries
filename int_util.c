#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "int_util.h"
#include "machine_types.h"
#include "alu.h"

static bool isZero(unsigned char *a, size_t len)
	{
	size_t i = 0;
	for (i = 0; i < len; i ++) if (a[i] != '\0') return false;
	
	return true;
	}

char* int_toString(unsigned char *integer, unsigned int bytes)
	{
	char *res = NULL;
	size_t reslen = 0;
	
	unsigned char *value = integer;
	unsigned int esize = bytes;
	
	if (isZero(value, esize))
		{
		res = malloc(sizeof(char) * 1);
		memcpy(res, "0", 1);
		reslen = 1;
		}
		else
		{
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
		
		free(val);
		free(cpy);
		}
	
	reslen ++;
	res = realloc(res, reslen);
	res[reslen - 1] = '\0';
	
	return res;
	}

static size_t strndx(char *str, char c)
	{
	size_t i = 0;
	for (i = 0; i < strlen(str); i++)
		{
		if (str[i] == c) return i;
		}
	
	return 0;
	}

unsigned char* stringToInt(char *data, unsigned int returnBytes)
	{
	size_t i = 0;
	
	unsigned char *ftop = NULL;
	
	while (i < strlen(data))
		{
		//printf("%c", registers[1].PR.content[i]);
		if (data[i] != '0' && data[i] != '1' && data[i] != '2' && data[i] != '3' && data[i] != '4' && data[i] != '5' && data[i] != '6' && data[i] != '7' && data[i] != '8' && data[i] != '9')
			//stop
			{
			ftop = (unsigned char*) &data[i-1];
			break;
			}
		
		ftop = (unsigned char*) &data[i];
		i ++;
		}
	
	unsigned char *mul = malloc(returnBytes);
	unsigned char *mlr = malloc(returnBytes);
	unsigned char *result = malloc(returnBytes);
	memset(result, '\0', returnBytes);
	
	uint8 base = 10;
	
	memset(mul, '\0', returnBytes);
	mul[returnBytes - 1] = 1;
	
	while (ftop != (unsigned char*) data - 1)
		{
		uint8 ndx = strndx("0123456789", ftop[0]);
		
		memcpy(mlr, mul, returnBytes);
		
		hw_mul(mlr, returnBytes, &ndx, 1);
		
		hw_add(result, returnBytes, mlr, returnBytes);
		
		hw_mul(mul, returnBytes, &base, 1);
		
		ftop --;
		}
	
	free(mlr);
	free(mul);
	
	return result;
	}
