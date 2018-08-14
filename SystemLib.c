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

#define MAX_VAR_NAME 2048

INSTRUCTION_DEF op_get_platform_name(VFrame *cframe)
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
	
	return_char_array(cframe, api, name);
	
	return RETURN_OK;
	}

INSTRUCTION_DEF op_get_platform_version(VFrame *cframe)
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
	
	return_char_array(cframe, api, sres);
	
	return RETURN_OK;
	}

INSTRUCTION_DEF op_get_chip_name(VFrame *cframe)
	{
	return_char_array(cframe, api, CHIP_NAME);
	
	return RETURN_OK;
	}

INSTRUCTION_DEF op_get_host_name(VFrame *cframe)
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
	
	return_char_array(cframe, api, sres);
	
	return RETURN_OK;
	}

INSTRUCTION_DEF op_get_variable(VFrame *cframe)
	{
	char *vn = getParam_char_array(cframe, 0);
	
	char *val = getenv(vn);
	
	if (val != NULL)
		{
		return_char_array(cframe, api, val);
    	}
    
	free(vn);
	
	return RETURN_OK;
	}

INSTRUCTION_DEF op_get_system_font(VFrame *cframe)
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
			return_char_array(cframe, api, fontPath);
			}
		
		free(fontPath);
		}
	
	return RETURN_OK;
	}

Interface* load(CoreAPI *capi)
	{
	api = capi;
	
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
	}
