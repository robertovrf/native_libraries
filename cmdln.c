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
			
			LiveArray *newArray = malloc(sizeof(LiveArray));
			memset(newArray, '\0', sizeof(LiveArray));
			
			newArray -> data = (unsigned char*) fullText;
			newArray -> length = length;
			
			newArray -> gtLink = charArrayGT;
			api -> incrementGTRefCount(newArray -> gtLink);
			newArray -> owner = cframe -> blocking -> instance;
			
			VVarLivePTR *ptrh = (VVarLivePTR*) ((LiveData*) ((VVarLivePTR*) getVariableContent(cframe, 0)) -> content) -> data;
			
			ptrh -> content = (unsigned char*) newArray;
			newArray -> refCount ++;
			ptrh -> typeLink = newArray -> gtLink -> typeLink;
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
