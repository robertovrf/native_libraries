//Written by Antreas Antoniou, 2016

#include "dana_lib_defs.h"
#include "nli_util.h"
#include "vmi_util.h"

#ifdef WINDOWS
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")
#endif

#ifdef LINUX
#include <stdio.h> //printf
#include <string.h> //memset
#include <stdlib.h> //for exit(0);
#include <sys/socket.h>
#include <errno.h> //For errno - the error number
#include <netdb.h> //hostent
#include <arpa/inet.h>
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
static int initialise(void)
{
	// Initialize Winsock
			WSADATA wsaData;
			int iResult;
	    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	    if (iResult != 0) {
	        printf("WSAStartup failed: %d\n", iResult);
	        return 1;
	    }
		return 0;
}

static void uninitialise (void)
{
    WSACleanup ();
}
#endif

#define MAX_VAR_NAME 2048

INSTRUCTION_DEF op_get_host_by_name(VFrame *cframe)
	{
	char *vn = getParam_char_array(cframe, 0);

	char ip[100];
	
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_in *h;
    int rv;
    memset(&hints, '\0', sizeof(hints));
    hints.ai_family = AF_INET; // use AF_INET6 to force IPv6
    hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	#ifdef WINDOWS
	initialise();
	#endif
	
    if ((rv = getaddrinfo( vn , NULL , &hints , &servinfo)) != 0)
		{
		api -> throwException(cframe, gai_strerror(rv));
		free(vn);
        return RETURN_OK;
		}
	
	#ifdef WINDOWS
	uninitialise();
	#endif
	
    //loop through all the results and connect to the first we can
    for (p = servinfo; p != NULL; p = p->ai_next)
		{
        h = (struct sockaddr_in *) p->ai_addr;
        strcpy(ip, inet_ntoa(h->sin_addr));
		}

    freeaddrinfo(servinfo); // all done with this structure
	
	char *val = ip;
	
	if (val != NULL)
		{
		return_char_array(cframe, api, val);
		}

	free(vn);

	return RETURN_OK;
	}

Interface* load(CoreAPI *capi)
	{
	api = capi;
	
	setInterfaceFunction("getHostIP", op_get_host_by_name);
	
	return getPublicInterface();
	}

void unload()
	{
	}
