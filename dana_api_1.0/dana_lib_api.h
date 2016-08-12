#ifndef _DANA_LIB_API
#define _DANA_LIB_API

#define LIB_API_VERSION 10

#define RETURN_DIRECT	0
#define RETURN_DEFERRED	1

#define STAT_TYPE_INSTRUCTIONS_EXECUTED			1
#define STAT_TYPE_DXU_CALLS_MADE				2
#define STAT_TYPE_OBJECT_CALLS_MADE				3
#define STAT_TYPE_LOCAL_CALLS_MADE				4

typedef struct _CoreAPI{
	void (*prepRegister)(VVarR *r);
	size_t (*readList)(VVarR *r, unsigned char *buf, size_t len);
	size_t (*writeList)(unsigned char *buf, VVarR *r, size_t len);
	size_t (*getLength)(VVarR *r);
	void (*deferredReturn)(VFrame *vt);
	int (*callFunction)(void *object, void *scopeRef, unsigned int index, void *es, void *params, unsigned int paramCount);
	GlobalTypeLink* (*resolveGlobalTypeMapping)(const DanaType *d);
	void (*decrementGTRefCount)(GlobalTypeLink *d);
	size_t (*getStat)(int type);
	void (*incrementGTRefCount)(GlobalTypeLink *d);
	unsigned char* (*getDecimalScalingFactor)(size_t byteWidth);
	} CoreAPI;

typedef Interface* (*dlLoad)(CoreAPI *capi);
typedef unsigned char (*dlGetAPIVersion)();
typedef void (*dlUnload)();

typedef int (*dlFunc)(VFrame *cframe);

#endif
