#ifndef _DANA_LIB_API
#define _DANA_LIB_API

#define LIB_API_VERSION 11

#define RETURN_DIRECT	0

typedef struct _CoreAPI{
	int (*callFunction)(void *object, unsigned int index, void *params, unsigned int paramCount);
	GlobalTypeLink* (*resolveGlobalTypeMapping)(const DanaType *d);
	void (*decrementGTRefCount)(GlobalTypeLink *d);
	void (*incrementGTRefCount)(GlobalTypeLink *d);
	unsigned char* (*getDecimalScalingFactor)(size_t byteWidth);
	void (*throwException)(VFrame *frame, char *reason);
	} CoreAPI;

typedef Interface* (*dlLoad)(CoreAPI *capi);
typedef unsigned char (*dlGetAPIVersion)();
typedef void (*dlUnload)();

typedef int (*dlFunc)(VFrame *cframe);

#endif
