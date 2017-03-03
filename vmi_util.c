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
	DanaType *spec = &((DanaType*)((StructuredType*) t -> scopes[0].scope.etype) -> structure.content)[index+1];
	return &t -> localsData[spec -> offset];
	}

void getVariableContentIn(VFrame *t, unsigned int index, VVarR *reg)
	{
	DanaType *spec = &((DanaType*) ((StructuredType*) t -> scopes[0].scope.etype) -> structure.content)[index+1];
	unsigned char *data = &t -> localsData[spec -> offset];
	
	memset(reg, '\0', sizeof(VVarR));
	
	if (spec -> container == X_POINTER)
		{
		VVarLivePTR *ptr = (VVarLivePTR*) data;
		
		reg -> PR.content = ptr -> content;
		reg -> PR.vsize = ptr -> vsize;
		reg -> PR.lsize = ptr -> lsize;
		reg -> PR.vlf = ptr -> vlf;
		reg -> PR.vlTop = ptr -> vlTop;
		reg -> PR.vlBot = ptr -> vlBot;
		
		reg -> type = spec -> typeClass;
		reg -> etype = spec -> typeClass == TYPE_LITERAL ? ptr -> typeLink -> esize : (size_t) ptr -> typeLink -> definition.content;
		reg -> xtype = ptr -> typeLink -> container;
		}
		else if (spec -> container == X_VLIST_CNT)
		{
		
		}
		else if (spec -> container == X_VLIST_LNK)
		{
		
		}
		else
		{
		reg -> PR.content = data;
		}
	}
