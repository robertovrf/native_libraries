//Written by Barry Porter, 2016

#include "dana_lib_defs.h"

//http://msdn.microsoft.com/en-us/library/ms724421%28v=vs.85%29.aspx
//http://msdn.microsoft.com/en-us/library/ms724318(v=vs.85).aspx

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef WINDOWS
#include <Windows.h>
#endif

#ifdef LINUX
#include <time.h>
#endif

#include <time.h>
#include <sys/time.h>
#include <sys/timeb.h>

#include <pthread.h>

#include "nli_util.h"
#include "vmi_util.h"

static CoreAPI *api;

INSTRUCTION_DEF op_get_local_time(VFrame *cframe)
	{
	unsigned char *cnt = ((LiveData*) ((VVarLivePTR*) getVariableContent(cframe, 0)) -> content) -> data;
	
	uint16 *year = (uint16*) &cnt[0];
	unsigned char *month = &cnt[2];
	unsigned char *day = &cnt[3];
	unsigned char *hour = &cnt[4];
	unsigned char *minute = &cnt[5];
	unsigned char *second = &cnt[6];
	uint16 *millisecond = (uint16*) &cnt[7];
	
	#ifdef WINDOWS
	/*
	SYSTEMTIME systemTime;
	//http://msdn.microsoft.com/en-us/library/ms724390(VS.85).aspx
	GetLocalTime(&systemTime); // <-- your computer
	//GetSystemTime(&systemTime); // <-- UTC
	
	size_t ci = 0;
	copyToDanaInteger((unsigned char*) &ci, (unsigned char*) &systemTime.wYear, sizeof(systemTime.wYear));
	
	*modifiedYear = ((uint16*) &ci)[(sizeof(ci)/2)-1];
	*modifiedMonth = systemTime.wMonth;
	*modifiedDay = systemTime.wDay;
	*modifiedHour = systemTime.wHour;
	*modifiedMinute = systemTime.wMinute;
	*modifiedSecond = systemTime.wSecond;
	*/
	
	struct timeb theTime;
	ftime(&theTime);
	time_t now = theTime.time;
	
	struct tm modified; memset(&modified, '\0', sizeof(modified));
	modified = *localtime(&now); //local
	
	modified.tm_year += 1900;
	modified.tm_mon += 1;
	
	size_t tMillisecond = theTime.millitm;
	size_t tMicrosecond = 0;
	
	size_t cMillisecond = 0;
	size_t cMicrosecond = 0;
	copyToDanaInteger((unsigned char*) &cMillisecond, (unsigned char*) &tMillisecond, sizeof(tMillisecond));
	copyToDanaInteger((unsigned char*) &cMicrosecond, (unsigned char*) &tMicrosecond, sizeof(tMicrosecond));
	
	size_t cYear = 0;
	copyToDanaInteger((unsigned char*) &cYear, (unsigned char*) &modified.tm_year, sizeof(modified.tm_year));
	
	*year = ((uint16*) &cYear)[(sizeof(cYear)/2)-1];
	*month = modified.tm_mon;
	*day = modified.tm_mday;
	*hour = modified.tm_hour;
	*minute = modified.tm_min;
	*second = modified.tm_sec;
	*millisecond = ((uint16*) &cMillisecond)[(sizeof(cMillisecond)/2)-1];
	#endif
	
	#ifdef LINUX
	struct timeval tv;
	gettimeofday(&tv,NULL);
	time_t now = tv.tv_sec;
	
	struct tm modified; memset(&modified, '\0', sizeof(modified));
	modified = *localtime(&now); //local
	
	modified.tm_year += 1900;
	modified.tm_mon += 1;
	
	size_t tMillisecond = tv.tv_usec / 1000;
	size_t tMicrosecond = tv.tv_usec - (tMillisecond * 1000);
	
	size_t cMillisecond = 0;
	size_t cMicrosecond = 0;
	copyToDanaInteger((unsigned char*) &cMillisecond, (unsigned char*) &tMillisecond, sizeof(tMillisecond));
	copyToDanaInteger((unsigned char*) &cMicrosecond, (unsigned char*) &tMicrosecond, sizeof(tMicrosecond));
	
	size_t cYear = 0;
	copyToDanaInteger((unsigned char*) &cYear, (unsigned char*) &modified.tm_year, sizeof(modified.tm_year));
	
	*year = ((uint16*) &cYear)[(sizeof(cYear)/2)-1];
	*month = modified.tm_mon;
	*day = modified.tm_mday;
	
	*hour = modified.tm_hour;
	*minute = modified.tm_min;
	*second = modified.tm_sec;
	*millisecond = ((uint16*) &cMillisecond)[(sizeof(cMillisecond)/2)-1];
	//*microsecond = ((uint16*) &cMicrosecond)[(sizeof(cMicrosecond)/2)-1];
	#endif
	
	return RETURN_OK;
	}

//NOTE: the below function isn't finished, but would return the time in milliseconds and microseconds
INSTRUCTION_DEF op_get_time_hd(VFrame *cframe)
	{
	unsigned char *cnt = ((LiveData*) ((VVarLivePTR*) getVariableContent(cframe, 0)) -> content) -> data;
	
	unsigned char *hour = &cnt[0];
	unsigned char *minute = &cnt[1];
	unsigned char *second = &cnt[2];
	uint16 *millisecond = (uint16*) &cnt[3];
	uint16 *microsecond = (uint16*) &cnt[5];
	
	#ifdef WINDOWS
	//NOTE: the commented out version below SHOULD work for Windows, but mingw doesn't seem to have a link for GetSystemTimePreciseAsFileTime
	// - for now this function therefore has a maximum precision of milliseconds on Windows
	/*
	FILETIME hqTime;
	GetSystemTimePreciseAsFileTime(&hqTime);
	
	unsigned long long tt = hqTime.dwHighDateTime;
    tt <<=32;
    tt |= hqTime.dwLowDateTime;
    tt /=10;
    tt -= 11644473600000000ULL;
	
	SYSTEMTIME systemTime;
	SYSTEMTIME localTime;
	
	FileTimeToSystemTime(&hqTime, &systemTime);
	SystemTimeToTzSpecificLocalTime(NULL, &systemTime, &localTime);
	
	size_t tMillisecond = localTime.wMilliseconds;
	size_t tMicrosecond = tt; //??
	
	size_t cMillisecond = 0;
	size_t cMicrosecond = 0;
	copyToDanaInteger((unsigned char*) &cMillisecond, (unsigned char*) &tMillisecond, sizeof(tMillisecond));
	copyToDanaInteger((unsigned char*) &cMicrosecond, (unsigned char*) &tMicrosecond, sizeof(tMicrosecond));
	
	*hour = localTime.wHour;
	*minute = localTime.wMinute;
	*second = localTime.wSecond;
	*millisecond = ((uint16*) &cMillisecond)[(sizeof(cMillisecond)/2)-1];
	*microsecond = ((uint16*) &cMicrosecond)[(sizeof(cMicrosecond)/2)-1];
	*/
	
	struct timeb theTime;
	ftime(&theTime);
	time_t now = theTime.time;
	
	struct tm modified; memset(&modified, '\0', sizeof(modified));
	modified = *localtime(&now); //local
	
	modified.tm_year += 1900;
	modified.tm_mon += 1;
	
	size_t tMillisecond = theTime.millitm;
	size_t tMicrosecond = 0;
	
	size_t cMillisecond = 0;
	size_t cMicrosecond = 0;
	copyToDanaInteger((unsigned char*) &cMillisecond, (unsigned char*) &tMillisecond, sizeof(tMillisecond));
	copyToDanaInteger((unsigned char*) &cMicrosecond, (unsigned char*) &tMicrosecond, sizeof(tMicrosecond));
	
	*hour = modified.tm_hour;
	*minute = modified.tm_min;
	*second = modified.tm_sec;
	*millisecond = ((uint16*) &cMillisecond)[(sizeof(cMillisecond)/2)-1];
	*microsecond = ((uint16*) &cMicrosecond)[(sizeof(cMicrosecond)/2)-1];
	#endif
	
	#ifdef LINUX
	struct timeval tv;
	gettimeofday(&tv,NULL);
	time_t now = tv.tv_sec;
	
	struct tm modified; memset(&modified, '\0', sizeof(modified));
	modified = *localtime(&now); //local
	
	modified.tm_year += 1900;
	modified.tm_mon += 1;
	
	size_t tMillisecond = tv.tv_usec / 1000;
	size_t tMicrosecond = tv.tv_usec - (tMillisecond * 1000);
	
	size_t cMillisecond = 0;
	size_t cMicrosecond = 0;
	copyToDanaInteger((unsigned char*) &cMillisecond, (unsigned char*) &tMillisecond, sizeof(tMillisecond));
	copyToDanaInteger((unsigned char*) &cMicrosecond, (unsigned char*) &tMicrosecond, sizeof(tMicrosecond));
	
	*hour = modified.tm_hour;
	*minute = modified.tm_min;
	*second = modified.tm_sec;
	*millisecond = ((uint16*) &cMillisecond)[(sizeof(cMillisecond)/2)-1];
	*microsecond = ((uint16*) &cMicrosecond)[(sizeof(cMicrosecond)/2)-1];
	#endif
	
	return RETURN_OK;
	}

Interface* load(CoreAPI *capi)
	{
	api = capi;
	
	setInterfaceFunction("getLocalTime", op_get_local_time);
	
	return getPublicInterface();
	}

void unload()
	{
	}
