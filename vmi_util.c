#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "vmi_util.h"
#include "dana_lib_api.h"

unsigned char getLibAPIVersion()
	{
	return LIB_API_VERSION;
	}

void dtoh(unsigned char *x, unsigned int len)
	{
	#ifdef MACHINE_ENDIAN_LITTLE
	unsigned int i = 0;
	unsigned int top = len - 1;
	unsigned int mid = len / 2;
	for (i = 0; i < mid; i++)
		{
		unsigned char b = x[top-i];
		x[top-i] = x[i];
		x[i] = b;
		}
	#endif
	}

void htod(unsigned char *x, unsigned int len)
	{
	#ifdef MACHINE_ENDIAN_LITTLE
	unsigned int i = 0;
	unsigned int top = len - 1;
	unsigned int mid = len / 2;
	for (i = 0; i < mid; i++)
		{
		unsigned char b = x[top-i];
		x[top-i] = x[i];
		x[i] = b;
		}
	#endif
	}

void bos(unsigned char *x, unsigned int len)
	{
	unsigned int i = 0;
	unsigned int top = len - 1;
	unsigned int mid = len / 2;
	for (i = 0; i < mid; i++)
		{
		unsigned char b = x[top-i];
		x[top-i] = x[i];
		x[i] = b;
		}
	}

void be_memcpy(unsigned char *to, unsigned char *from, unsigned int len)
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

void copyHostInteger(unsigned char *dst, unsigned char *src, size_t srcsz)
	{
	be_memcpy(dst + sizeof(size_t), src + srcsz, srcsz > sizeof(size_t) ? sizeof(size_t) : srcsz);
	
	#ifdef MACHINE_ENDIAN_LITTLE
	bos(dst, sizeof(size_t));
	#endif
	}

void copyToDanaInteger(unsigned char *dst, unsigned char *src, size_t srcsz)
	{
	size_t fs = srcsz > sizeof(size_t) ? sizeof(size_t) : srcsz;
	be_memcpy(dst + sizeof(size_t), src + srcsz, fs);
	
	#ifdef MACHINE_ENDIAN_LITTLE
	bos(dst + (sizeof(size_t) - fs), fs);
	#endif
	}

unsigned char* getVariableContent(VFrame *t, unsigned int index)
	{
	return &t -> localsData[((DanaType*) t -> localsDef) -> fields[index+1].offset];
	}
