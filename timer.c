//Written by Barry Porter, 2016

#include "dana_lib_defs.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static CoreAPI *api;

#ifdef WINDOWS
#include <Windows.h>
#endif

#ifdef LINUX
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#endif

#include "nli_util.h"
#include "vmi_util.h"

#ifdef WINDOWS
DWORD WINAPI ithread( LPVOID ptr ) 
#else
static void * ithread(void *ptr)
#endif
	{
	#ifdef LINUX
	pthread_detach(pthread_self());
	#endif
	
	VFrame *cframe = (VFrame*) ptr;
	
	size_t ms = 0;
	copyHostInteger((unsigned char*) &ms, getVariableContent(cframe, 0), sizeof(size_t));
	
	#ifdef WINDOWS
	Sleep(ms);
	#endif
	#ifdef LINUX
	struct timespec ts;
	ts.tv_sec = ms / 1000;
	ts.tv_nsec = (ms - (ts.tv_sec * 1000)) * 1000000;
	nanosleep(&ts, NULL);
	#endif
	
	api -> deferredReturn(cframe);
	
	#ifdef WINDOWS
	return 0;
	#else
	return NULL;
	#endif
	}

INSTRUCTION_DEF op_timer_sleep(INSTRUCTION_PARAM_LIST)
	{
	#ifdef WINDOWS
	HANDLE th = CreateThread( 
            NULL,                   // default security attributes
            0,                      // use default stack size  
            ithread,  		     // thread function name
            cframe,          // argument to thread function 
            0,                      // use default creation flags 
            NULL);   // returns the thread identifier
	
	CloseHandle(th);
	#else
	pthread_t th;
	pthread_create(&th, NULL, ithread, cframe);
	#endif
	
	return RETURN_DEFERRED;
	}

Interface* load(CoreAPI *capi)
	{
	api = capi;
	
	setInterfaceFunction("sleep", op_timer_sleep);
	
	return getPublicInterface();
	}

void unload()
	{
	
	}
