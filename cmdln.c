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

#ifdef WINDOWS
DWORD WINAPI gl_thread( LPVOID ptr ) 
#else
static void * gl_thread(void *ptr)
#endif
	{
	#ifdef LINUX
	pthread_detach(pthread_self());
	#endif
	
	VFrame *cframe = (VFrame*) ptr;
	
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
			attachPointer(ptrh, &newArray -> scope.scopePointers);
			newArray -> refCount ++;
			ptrh -> typeLink = newArray -> gtLink -> typeLink;
			}
		}
	
	api -> deferredReturn(cframe);
	
	#ifdef WINDOWS
	return 0;
	#else
	return NULL;
	#endif
	}

INSTRUCTION_DEF op_get_line(INSTRUCTION_PARAM_LIST)
	{
	#ifdef WINDOWS
	HANDLE th = CreateThread( 
            NULL,                   // default security attributes
            0,                      // use default stack size  
            gl_thread,  		     // thread function name
            cframe,          // argument to thread function 
            0,                      // use default creation flags 
            NULL);   // returns the thread identifier
	
	CloseHandle(th);
	#else
	int err = 0;
	pthread_t th;
	memset(&th, '\0', sizeof(pthread_t));
	
	if ((err = pthread_create(&th, NULL, gl_thread, cframe)) != 0)
		{
		/*
		api -> debugOutput(callingThread, "TCPlib::Starting accept thread failed [%s]", strerror(errno));
		return NULL;
		*/
		}
	#endif
	
	return RETURN_DEFERRED;
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
