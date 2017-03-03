#ifndef __VMI__UTIL
#define __VMI__UTIL

#include "dana_lib_defs.h"

#define TYPE_BYTE {TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}
#define TYPE_CHAR_ARRAY {TYPE_ARRAY, X_FLAT, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &charDef}}
static const DanaType charSpec[] = {
					TYPE_BYTE
					};
static StructuredType charDef = {{(unsigned char*) "char", NULL, 0, 4}, {(unsigned char*) charSpec, NULL, 0, sizeof(charSpec)}, 1};
static const DanaType std_stringDef[] = {
					TYPE_CHAR_ARRAY
					};

void copyHostInteger(unsigned char *dst, unsigned char *src, size_t srcsz);
void copyToDanaInteger(unsigned char *dst, unsigned char *src, size_t srcsz);

unsigned char* getVariableContent(VFrame *t, unsigned int index);
void getVariableContentIn(VFrame *t, unsigned int index, VVarR *reg);

#endif