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

static GlobalTypeLink *charArrayGT = NULL;

#define MAX_VAR_NAME 2048

INSTRUCTION_DEF op_get_platform_name(INSTRUCTION_PARAM_LIST)
	{
	char *name = "Unknown";
	
	#ifdef WINDOWS
	name = "Windows";
	#endif
	
	#ifdef LINUX
	struct utsname nm;
	if (uname(&nm) == 0)
		{
		name = nm.sysname;
		}
	#endif
	
	LiveArray *newArray = malloc(sizeof(LiveArray));
	memset(newArray, '\0', sizeof(LiveArray));
	
	newArray -> data = (unsigned char*) strdup(name);
	newArray -> length = strlen(name);
	
	newArray -> gtLink = charArrayGT;
	api -> incrementGTRefCount(newArray -> gtLink);
	
	newArray -> owner = cframe -> blocking -> instance;
	
	VVarLivePTR *ptrh = (VVarLivePTR*) ((LiveData*) ((VVarLivePTR*) getVariableContent(cframe, 0)) -> content) -> data;
	
	ptrh -> content = (unsigned char*) newArray;
	attachPointer(ptrh, &newArray -> scope.scopePointers);
	newArray -> refCount = 1;
	ptrh -> typeLink = newArray -> gtLink -> typeLink;
	
	return RETURN_DIRECT;
	}

INSTRUCTION_DEF op_get_platform_version(INSTRUCTION_PARAM_LIST)
	{
	char sres[MAX_VAR_NAME];
	memset(sres, '\0', sizeof(sres));
	
	#ifdef WINDOWS
	char ires[MAX_VAR_NAME];
	memset(ires, '\0', sizeof(ires));
	
	OSVERSIONINFO osvi;
	osvi.dwOSVersionInfoSize = sizeof(osvi);
	
	GetVersionEx(&osvi);
	
	size_t majorVer = osvi.dwMajorVersion;
	size_t minorVer = osvi.dwMinorVersion;
	size_t buildNum = osvi.dwBuildNumber;
	
	itoa(majorVer, ires, 10);
	strcat(sres, ires);
	
	memset(ires, '\0', sizeof(ires));
	strcat(sres, ".");
	
	itoa(minorVer, ires, 10);
	strcat(sres, ires);
	
	memset(ires, '\0', sizeof(ires));
	strcat(sres, " [");
	
	itoa(buildNum, ires, 10);
	strcat(sres, ires);
	
	strcat(sres, "]");
	#endif
	
	#ifdef LINUX
	struct utsname name;
	if (uname(&name) == 0)
		{
		snprintf(sres, MAX_VAR_NAME, "%s [%s]", name.release, name.version);
		}
	#endif
	
	LiveArray *newArray = malloc(sizeof(LiveArray));
	memset(newArray, '\0', sizeof(LiveArray));
	
	newArray -> data = (unsigned char*) strdup(sres);
	newArray -> length = strlen(sres);
	
	newArray -> gtLink = charArrayGT;
	api -> incrementGTRefCount(newArray -> gtLink);
	
	newArray -> owner = cframe -> blocking -> instance;
	
	VVarLivePTR *ptrh = (VVarLivePTR*) ((LiveData*) ((VVarLivePTR*) getVariableContent(cframe, 0)) -> content) -> data;
	
	ptrh -> content = (unsigned char*) newArray;
	attachPointer(ptrh, &newArray -> scope.scopePointers);
	newArray -> refCount = 1;
	ptrh -> typeLink = newArray -> gtLink -> typeLink;
	
	return RETURN_DIRECT;
	}

INSTRUCTION_DEF op_get_chip_name(INSTRUCTION_PARAM_LIST)
	{
	LiveArray *newArray = malloc(sizeof(LiveArray));
	memset(newArray, '\0', sizeof(LiveArray));
	
	newArray -> data = (unsigned char*) strdup(CHIP_NAME);
	newArray -> length = strlen(CHIP_NAME);
	
	newArray -> gtLink = charArrayGT;
	api -> incrementGTRefCount(newArray -> gtLink);
	
	newArray -> owner = cframe -> blocking -> instance;
	
	VVarLivePTR *ptrh = (VVarLivePTR*) ((LiveData*) ((VVarLivePTR*) getVariableContent(cframe, 0)) -> content) -> data;
	
	ptrh -> content = (unsigned char*) newArray;
	attachPointer(ptrh, &newArray -> scope.scopePointers);
	newArray -> refCount = 1;
	ptrh -> typeLink = newArray -> gtLink -> typeLink;
	
	return RETURN_DIRECT;
	}

INSTRUCTION_DEF op_get_host_name(INSTRUCTION_PARAM_LIST)
	{
	char sres[MAX_VAR_NAME];
	memset(sres, 0, sizeof(sres));
	
	#ifdef WINDOWS
	DWORD len = MAX_VAR_NAME;
	GetComputerNameEx(ComputerNameDnsFullyQualified, sres, &len);
	#endif
	
	#ifdef LINUX
	gethostname(sres, MAX_VAR_NAME);
	#endif
	
	LiveArray *newArray = malloc(sizeof(LiveArray));
	memset(newArray, '\0', sizeof(LiveArray));
	
	newArray -> data = (unsigned char*) strdup(sres);
	newArray -> length = strlen(sres);
	
	newArray -> gtLink = charArrayGT;
	api -> incrementGTRefCount(newArray -> gtLink);
	
	newArray -> owner = cframe -> blocking -> instance;
	
	VVarLivePTR *ptrh = (VVarLivePTR*) ((LiveData*) ((VVarLivePTR*) getVariableContent(cframe, 0)) -> content) -> data;
	
	ptrh -> content = (unsigned char*) newArray;
	attachPointer(ptrh, &newArray -> scope.scopePointers);
	newArray -> refCount = 1;
	ptrh -> typeLink = newArray -> gtLink -> typeLink;
	
	return RETURN_DIRECT;
	}

INSTRUCTION_DEF op_get_variable(INSTRUCTION_PARAM_LIST)
	{
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
	
	char *val = getenv(vn);
	
	unsigned char ok = 0;
	
	if (val != NULL)
		{
		LiveArray *newArray = malloc(sizeof(LiveArray));
		memset(newArray, '\0', sizeof(LiveArray));
		
		newArray -> data = (unsigned char*) strdup(val);
		newArray -> length = strlen(val);
		
		newArray -> gtLink = charArrayGT;
		api -> incrementGTRefCount(newArray -> gtLink);
		
		newArray -> owner = cframe -> blocking -> instance;
		
		VVarLivePTR *ptrh = (VVarLivePTR*) ((LiveData*) ((VVarLivePTR*) getVariableContent(cframe, 1)) -> content) -> data;
		
		ptrh -> content = (unsigned char*) newArray;
		attachPointer(ptrh, &newArray -> scope.scopePointers);
		newArray -> refCount = 1;
		ptrh -> typeLink = newArray -> gtLink -> typeLink;
		
	    ok = 1;
    	}
    
	size_t *result = (size_t*) &cframe -> localsData[((DanaType*) ((StructuredType*) cframe -> scopes[0].scope.etype) -> structure.content)[0].offset];
	copyHostInteger((unsigned char*) result, (unsigned char*) &ok, sizeof(ok));
	
	free(vn);
	
	return RETURN_DIRECT;
	}

INSTRUCTION_DEF op_get_system_font(INSTRUCTION_PARAM_LIST)
	{
	unsigned char monospaced = getVariableContent(cframe, 0)[0];
	
	char *home = getenv("DANA_HOME");
	
	if (home != NULL)
		{
		char *fontPath = NULL;
		
		if (monospaced)
			{
			fontPath = malloc(strlen(home) + strlen("/resources-ext/fonts/LiberationMono.ttf") + 1);
			memset(fontPath, '\0', strlen(home) + strlen("/resources-ext/fonts/LiberationMono.ttf") + 1);
			strcpy(fontPath, home);
			strcat(fontPath, "/resources-ext/fonts/LiberationMono.ttf");
			}
			else
			{
			fontPath = malloc(strlen(home) + strlen("/resources-ext/fonts/SourceSansPro.ttf") + 1);
			memset(fontPath, '\0', strlen(home) + strlen("/resources-ext/fonts/SourceSansPro.ttf") + 1);
			strcpy(fontPath, home);
			strcat(fontPath, "/resources-ext/fonts/SourceSansPro.ttf");
			}
		
		struct stat st;
		if (stat(fontPath, &st) == 0)
			{
			LiveArray *newArray = malloc(sizeof(LiveArray));
			memset(newArray, '\0', sizeof(LiveArray));
			
			newArray -> data = (unsigned char*) strdup(fontPath);
			newArray -> length = strlen(fontPath);
			
			newArray -> gtLink = charArrayGT;
			api -> incrementGTRefCount(newArray -> gtLink);
			
			newArray -> owner = cframe -> blocking -> instance;
			
			VVarLivePTR *ptrh = (VVarLivePTR*) ((LiveData*) ((VVarLivePTR*) getVariableContent(cframe, 1)) -> content) -> data;
			
			ptrh -> content = (unsigned char*) newArray;
			attachPointer(ptrh, &newArray -> scope.scopePointers);
			newArray -> refCount = 1;
			ptrh -> typeLink = newArray -> gtLink -> typeLink;
			}
		
		free(fontPath);
		}
	
	return RETURN_DIRECT;
	}

Interface* load(CoreAPI *capi)
	{
	api = capi;
	
	// grab global type mappings for anything that we generate here
	charArrayGT = api -> resolveGlobalTypeMapping(getTypeDefinition("char[]"));
	api -> incrementGTRefCount(charArrayGT);
	
	setInterfaceFunction("getPlatformName", op_get_platform_name);
	setInterfaceFunction("getPlatformVersion", op_get_platform_version);
	setInterfaceFunction("getChipName", op_get_chip_name);
	setInterfaceFunction("getHostName", op_get_host_name);
	setInterfaceFunction("getVar", op_get_variable);
	setInterfaceFunction("getSystemFont", op_get_system_font);
	
	return getPublicInterface();
	}

void unload()
	{
	api -> decrementGTRefCount(charArrayGT);
	}
