//Written by Barry Porter, 2016

#include "dana_lib_defs.h"
#include "nli_util.h"
#include "vmi_util.h"

#ifdef WINDOWS
#include <Windows.h>
#endif

#ifdef LINUX
#include <sys/utsname.h>
#include <unistd.h>
#endif

#include <sys/stat.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <pthread.h>

static CoreAPI *api;

#ifdef WINDOWS
DWORD WINAPI execute_thread( LPVOID ptr ) 
#else
static void * execute_thread(void *ptr)
#endif
	{
	//NOTE: this is a very simple implementation; eventually we'll want a version that allows the launching program to interact with the launched program, reading its console output and sending it input
	// - an approach to this on Windows may be: http://support.microsoft.com/kb/190351
	
	#ifdef LINUX
	pthread_detach(pthread_self());
	#endif
	
	VFrame *cframe = (VFrame*) ptr;
	
	LiveArray *array = (LiveArray*) ((VVarLivePTR*) getVariableContent(cframe, 0)) -> content;
	
	char *vn = NULL;
	
	if (array != NULL)
		{
		vn = malloc(array -> length + 1);
		memset(vn, '\0', array -> length + 1);
		memcpy(vn, array -> data, array -> length);
		}
		else
		{
		vn = strdup("");
		}
	
	int k = system(vn);
	unsigned char ok = 0;
	
	if (true)
		{
		size_t *resultValue = (size_t*) ((LiveData*) ((VVarLivePTR*) getVariableContent(cframe, 1)) -> content) -> data;
		
		size_t res = k;
		
		copyHostInteger((unsigned char*) resultValue, (unsigned char*) &res, sizeof(size_t));
		
	    ok = 1;
    	}
    
	size_t *result = (size_t*) &cframe -> localsData[((DanaType*) ((StructuredType*) cframe -> scopes[0].scope.etype) -> structure.content)[0].offset];
	copyHostInteger((unsigned char*) result, (unsigned char*) &ok, sizeof(ok));
	
	free(vn);
	
	api -> deferredReturn(cframe);
	
	#ifdef WINDOWS
	return 0;
	#else
	return NULL;
	#endif
	}

INSTRUCTION_DEF op_execute(INSTRUCTION_PARAM_LIST)
	{
	#ifdef WINDOWS
	HANDLE th = CreateThread( 
            NULL,                   // default security attributes
            0,                      // use default stack size  
            execute_thread,  		     // thread function name
            cframe,          // argument to thread function 
            0,                      // use default creation flags 
            NULL);   // returns the thread identifier
	
	CloseHandle(th);
	#else
	int err = 0;
	pthread_t th;
	memset(&th, '\0', sizeof(pthread_t));
	
	if ((err = pthread_create(&th, NULL, execute_thread, cframe)) != 0)
		{
		}
	#endif
	
	return RETURN_DEFERRED;
	}

Interface* load(CoreAPI *capi)
	{
	api = capi;
	
	setInterfaceFunction("execute", op_execute);
	
	return getPublicInterface();
	}

void unload()
	{
	}
