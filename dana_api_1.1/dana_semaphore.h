#ifndef _DANA_SEMAPHORE_
#define _DANA_SEMAPHORE_

#ifdef WINDOWS
#include <Windows.h>
#endif

#ifdef LINUX
#include <semaphore.h>
#endif

#ifdef OSX
#include <dispatch/dispatch.h>
#endif

typedef struct _pi_semaphore{
	#ifdef WINDOWS
	#include <Windows.h>
	HANDLE sem;
	#endif
	#ifdef OSX
	dispatch_semaphore_t sem;
	#else
	#ifdef LINUX
	sem_t sem;
	#endif
	#endif
	} Semaphore;

Semaphore sleepSem;
Semaphore intSem;

void semaphore_init(Semaphore *s, unsigned int initialValue);
void semaphore_wait(Semaphore *s);
void semaphore_post(Semaphore *s);

#endif
