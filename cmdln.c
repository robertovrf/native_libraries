//Written by Barry Porter, 2016

#include "dana_lib_defs.h"

#ifdef WINDOWS
#include <Windows.h>
#else
#include <pthread.h>
#endif

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "nli_util.h"
#include "vmi_util.h"

static CoreAPI *api;

static GlobalTypeLink *charArrayGT = NULL;

#define MAX_BUF 32

static void returnByteArray(VFrame *f, unsigned char *data, size_t len)
	{
	LiveArray *array = malloc(sizeof(LiveArray));
	memset(array, '\0', sizeof(LiveArray));
	
	array -> data = data;
	array -> length = len;
	
	array -> gtLink = charArrayGT;
	api -> incrementGTRefCount(array -> gtLink);
	array -> owner = f -> blocking -> instance;
	
	array -> refCount ++;
	
	VVarLivePTR *ptrh = (VVarLivePTR*) &f -> localsData[((DanaType*) ((StructuredType*) f -> localsDef) -> structure.content)[0].offset];
	ptrh -> content = (unsigned char*) array;
	ptrh -> typeLink = array -> gtLink -> typeLink;
	}

INSTRUCTION_DEF op_get_line(INSTRUCTION_PARAM_LIST)
	{
	char buf[MAX_BUF];
	memset(buf, '\0', MAX_BUF);
	
	char *p = fgets (buf, MAX_BUF, stdin);
	char *fullText = NULL;
	size_t length = 0;
	
	while (p != NULL && strchr(p, '\n') == NULL)
		{
		fullText = realloc(fullText, length + strlen(p));
		memcpy(fullText + length, p, strlen(p));
		length += strlen(p);
		
		p = fgets (buf, MAX_BUF, stdin);
		}
	
	if (p != NULL)
		{
		strchr(p, '\n')[0] = '\0';
		
		if (strlen(p) != 0)
			{
			fullText = realloc(fullText, length + strlen(p));
			memcpy(fullText + length, p, strlen(p));
			length += strlen(p);
			
			returnByteArray(cframe, (unsigned char*) fullText, length);
			}
		}
	
	return RETURN_DIRECT;
	}

Interface* load(CoreAPI *capi)
	{
	api = capi;
	
	// grab global type mappings for anything that we generate here
	charArrayGT = api -> resolveGlobalTypeMapping(getTypeDefinition("char[]"));
	api -> incrementGTRefCount(charArrayGT);
	
	setInterfaceFunction("getLine", op_get_line);
	
	return getPublicInterface();
	}

void unload()
	{
	api -> decrementGTRefCount(charArrayGT);
	}
