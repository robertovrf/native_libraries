#ifndef _DANA_LIB_DEFS
#define _DANA_LIB_DEFS

#define INSTRUCTION_DEF static int
#define INSTRUCTION_PARAM_LIST VFrame *cframe

#include <stddef.h>
#include "machine_types.h"
#include "dana_types.h"
#include "dana_lib_api.h"

static const StructuredInterfaceType IDCIF = {{(unsigned char*) "IDC", NULL, 0, 3}, {NULL, NULL, 0, 0}, 0, 0};

static const DanaType IDCDT = {TYPE_OBJECT, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &IDCIF}};

static const InterfaceDetails IDCID = {(size_t) &IDCDT, 0, 0, NULL};

#define IDC (size_t) &IDCDT, 0, 0, NULL

#endif
