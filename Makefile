CC = gcc

API_PATH = "dana_api_1.4"
STD_INCLUDE = -I $(API_PATH)
CCFLAGS = -Wall -fno-strict-aliasing
OUTPUT_FILE=
MYSQL_INCLUDE = `mysql_config --cflags --libs`

INSTALL_PATH=
CP_CMD=
CHIP=
PLATFORM=
SDL_FLAGS=
NET_FLAGS=
MATH_FLAGS=
ALL_RULES = calendar cmdln iofile iotcp ioudp dns sysinfo timer run math

ifeq ($(OS),Windows_NT)
    CCFLAGS += -DWINDOWS
	CCFLAGS += -DPC
	CCFLAGS += -DLIB_PLATFORM_NAME=\"win7\"
	CCFLAGS += -DMACHINE_ENDIAN_LITTLE
	OUTPUT_FILE = dana.exe
	PRECOMPILE = windres cmdres.rc cmdres.o
	EXTRA_O_FILES = cmdres.o
	INSTALL_PATH = "c:\programfiles\dana\"
	CP_CMD = copy
	PLATFORM = win7
	CCFLAGS += -shared
	NET_FLAGS = -lws2_32
	ALL_RULES += uiplane
    ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
        CCFLAGS += -DMACHINE_64
		CCFLAGS += -DLIB_CHIP_NAME=\"x64\"
		CHIP = x64
		SDL_FLAGS = -L"C:/SDL/x86_64-w64-mingw32/lib" -lSDL2main -lSDL2 -lSDL2_ttf -I "C:/SDL/i686-w64-mingw32/include" -lmingw32 -mwindows -I . -I ../../compiler/ -static-libgcc"
    endif
    ifeq ($(PROCESSOR_ARCHITECTURE),x86)
        CCFLAGS += -DMACHINE_32
		CCFLAGS += -DLIB_CHIP_NAME=\"x86\"
		CHIP = x86
		SDL_FLAGS = -L"C:/SDL/i686-w64-mingw32/lib" -lSDL2main -lSDL2 -lSDL2_ttf -I "C:/SDL/i686-w64-mingw32/include" -lmingw32 -mwindows -I . -I ../../compiler/ -static-libgcc
    endif
else
    UNAME_S := $(shell uname -s)
	OUTPUT_FILE = dana
	CCFLAGS += -ldl
	CCFLAGS += -DPC
	CCFLAGS += -DMACHINE_ENDIAN_LITTLE
	INSTALL_PATH = ~/dana/
	CP_CMD = cp
	PLATFORM = deb
	CCFLAGS += -shared -fPIC
	MATH_FLAGS = -lm
    ifeq ($(UNAME_S),Linux)
        CCFLAGS += -DLINUX
		CCFLAGS += -DLIB_PLATFORM_NAME=\"deb\"
    endif
    ifeq ($(UNAME_S),Darwin)
        CCFLAGS += -DOSX
        CCFLAGS += -DLINUX
        PLATFORM = osx
		CCFLAGS += -DLIB_PLATFORM_NAME=\"osx\"
        CCFLAGS += -DMACHINE_64
		SDL_FLAGS = -lSDL2main -lSDL2 -lSDL2_ttf
		CCFLAGS += -DLIB_CHIP_NAME=\"x64\"
		CHIP = x64
    endif
    ifneq ($(UNAME_S),Darwin)
        UNAME_P := $(shell uname -p)
        ifeq ($(UNAME_P),x86_64)
            CCFLAGS += -DMACHINE_64
            CCFLAGS += -DLIB_CHIP_NAME=\"x64\"
            CHIP = x64
			SDL_FLAGS = -lSDL2main -lSDL2 -lSDL2_ttf
        endif
        ifneq ($(filter %86,$(UNAME_P)),)
            CCFLAGS += -DMACHINE_32
            CCFLAGS += -DLIB_CHIP_NAME=\"x86\"
            CHIP = x86
			SDL_FLAGS = -lSDL2main -lSDL2 -lSDL2_ttf
        endif
        ifneq ($(filter arm%,$(UNAME_P)),)
            CCFLAGS += -DARM
        endif
        UNAME_N := $(shell uname -n)
        ifneq ($(filter %raspberrypi,$(UNAME_N)),)
            CCFLAGS += -DMACHINE_32
            CCFLAGS += -DLIB_CHIP_NAME=\"armv6\"
            CHIP = armv6
        endif
    endif
endif

calendar:
	$(CC) -Os -s ICalLib_dni.c vmi_util.c calendar.c -o calendar[$(PLATFORM).$(CHIP)].dnl $(STD_INCLUDE) $(CCFLAGS)
	$(CP_CMD) calendar[$(PLATFORM).$(CHIP)].dnl "$(DANA_HOME)/resources-ext"

cmdln:
	$(CC) -Os -s ICmdLib_dni.c vmi_util.c cmdln.c -o cmdln[$(PLATFORM).$(CHIP)].dnl $(STD_INCLUDE) $(CCFLAGS)
	$(CP_CMD) cmdln[$(PLATFORM).$(CHIP)].dnl "$(DANA_HOME)/resources-ext"

iofile:
	$(CC) -Os -s IIOFileLib_dni.c vmi_util.c io_file.c -o io_file[$(PLATFORM).$(CHIP)].dnl $(STD_INCLUDE) $(CCFLAGS)
	$(CP_CMD) io_file[$(PLATFORM).$(CHIP)].dnl "$(DANA_HOME)/resources-ext"

iotcp:
	$(CC) -Os -s IOTCPLib_dni.c vmi_util.c io_tcp_thread_per_recv.c -o io_tcp[$(PLATFORM).$(CHIP)].dnl $(STD_INCLUDE) $(CCFLAGS) $(NET_FLAGS)
	$(CP_CMD) io_tcp[$(PLATFORM).$(CHIP)].dnl "$(DANA_HOME)/resources-ext"

ioudp:
	$(CC) -Os -s IOUDPLib_dni.c vmi_util.c io_udp.c -o io_udp[$(PLATFORM).$(CHIP)].dnl $(STD_INCLUDE) $(CCFLAGS) $(NET_FLAGS)
	$(CP_CMD) io_udp[$(PLATFORM).$(CHIP)].dnl "$(DANA_HOME)/resources-ext"

dns:
	$(CC) -Os -s DNSLib_dni.c vmi_util.c dns.c -o dns[$(PLATFORM).$(CHIP)].dnl $(STD_INCLUDE) $(CCFLAGS) $(NET_FLAGS) -DCHIP_NAME=\"$(CHIP)\"
	$(CP_CMD) dns[$(PLATFORM).$(CHIP)].dnl "$(DANA_HOME)/resources-ext"

sysinfo:
	$(CC) -Os -s SystemLib_dni.c vmi_util.c sysinfo.c -o sysinfo[$(PLATFORM).$(CHIP)].dnl $(STD_INCLUDE) $(CCFLAGS) -DCHIP_NAME=\"$(CHIP)\"
	$(CP_CMD) sysinfo[$(PLATFORM).$(CHIP)].dnl "$(DANA_HOME)/resources-ext"

timer:
	$(CC) -Os -s Timer_dni.c vmi_util.c timer.c -o timer[$(PLATFORM).$(CHIP)].dnl $(STD_INCLUDE) $(CCFLAGS)
	$(CP_CMD) timer[$(PLATFORM).$(CHIP)].dnl "$(DANA_HOME)/resources-ext"

uiplane:
	$(CC) -Os -s UIPlaneLib_dni.c vmi_util.c $(API_PATH)/platform_utils.c uiplane.c -o uiplane[$(PLATFORM).$(CHIP)].dnl $(STD_INCLUDE) $(CCFLAGS) $(SDL_FLAGS)
	$(CP_CMD) uiplane[$(PLATFORM).$(CHIP)].dnl "$(DANA_HOME)/resources-ext"

run:
	$(CC) -Os -s RunLib_dni.c vmi_util.c run.c -o run[$(PLATFORM).$(CHIP)].dnl $(STD_INCLUDE) $(CCFLAGS)
	$(CP_CMD) run[$(PLATFORM).$(CHIP)].dnl "$(DANA_HOME)/resources-ext"

math:
	$(CC) -Os -s MathLib_dni.c vmi_util.c alu.c int_util.c math.c -o math[$(PLATFORM).$(CHIP)].dnl $(STD_INCLUDE) $(CCFLAGS) $(MATH_FLAGS)
	$(CP_CMD) math[$(PLATFORM).$(CHIP)].dnl "$(DANA_HOME)/resources-ext"

mysql_lib:
	$(CC) -Os -s MySQLLib_dni.c vmi_util.c mysqllib.c -o mysqllib[$(PLATFORM).$(CHIP)].dnl $(STD_INCLUDE) $(MYSQL_INCLUDE) $(CCFLAGS)
	$(CP_CMD) mysqllib[$(PLATFORM).$(CHIP)].dnl "$(DANA_HOME)/resources-ext"

all: $(ALL_RULES)