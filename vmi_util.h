#ifndef __VMI__UTIL
#define __VMI__UTIL

#include "dana_lib_defs.h"

void copyHostInteger(unsigned char *dst, unsigned char *src, size_t srcsz);
void copyToDanaInteger(unsigned char *dst, unsigned char *src, size_t srcsz);

unsigned char* getVariableContent(VFrame *t, unsigned int index);

#endif