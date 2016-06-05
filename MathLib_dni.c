#include "dana_lib_defs.h"
#include <string.h>
DanaType emptyType = {TYPE_PATTERN, 0, 0, 0, 0, 0};
#define ADDRESS_ALIGN true
#define ADDRESS_WIDTH sizeof(size_t)
static const StructuredType object_Object_def;
static const DanaType function_Object_clone_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const DanaType function_Object_equals_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const DanaType array_char_spec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static const StructuredType array_char_def = {{NULL, NULL, 0, 0}, {(unsigned char*) array_char_spec, NULL, 0, sizeof(array_char_spec)}, sizeof(VVarLivePTR)};
static const DanaType data_char_array_map_def = 
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}};
static const DanaType function_Object_toString_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const DanaType object_Object_spec[] = {
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &function_Object_clone_def}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &function_Object_equals_def}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &function_Object_toString_def}}};
static const StructuredType object_Object_def = {{NULL, NULL, 0, 0}, {(unsigned char*) object_Object_spec, NULL, 0, sizeof(object_Object_spec)}, sizeof(VVarLivePTR)};
static const DanaType function_MathLib_clone_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const DanaType function_MathLib_equals_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const DanaType function_MathLib_toString_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const DanaType function_MathLib_sqrt_def[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const DanaType function_MathLib_sqrtDec_def[] = {
{TYPE_DECIMAL, X_FLAT, 0, sizeof(size_t)*2, sizeof(size_t)*2, 0},
{TYPE_DECIMAL, X_FLAT, 0, sizeof(size_t)*2, sizeof(size_t)*2, 0}};
static const StructuredFunctionType intf_fnc[] = {
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_clone_def, NULL, 0, sizeof(function_MathLib_clone_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_equals_def, NULL, 0, sizeof(function_MathLib_equals_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_toString_def, NULL, 0, sizeof(function_MathLib_toString_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_sqrt_def, NULL, 0, sizeof(function_MathLib_sqrt_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_sqrtDec_def, NULL, 0, sizeof(function_MathLib_sqrtDec_def)}, 0}};
static const DanaType intf_def[] = {
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[0]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[1]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[2]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[3]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[4]}}};
static StructuredInterfaceType ILib = {{(unsigned char*) "MathLib", NULL, 0, 7}, {(unsigned char*) intf_def, NULL, 0, sizeof(intf_def)}, 0};
static DanaType cloneLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static StructuredType cloneLocalsDef = {{}, {(unsigned char*) cloneLocalsSpec, NULL, 0, sizeof(cloneLocalsSpec)}, 0};
static DanaType equalsLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static StructuredType equalsLocalsDef = {{}, {(unsigned char*) equalsLocalsSpec, NULL, 0, sizeof(equalsLocalsSpec)}, 0};
static DanaType toStringLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType toStringLocalsDef = {{}, {(unsigned char*) toStringLocalsSpec, NULL, 0, sizeof(toStringLocalsSpec)}, 0};
static DanaType sqrtLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType sqrtLocalsDef = {{}, {(unsigned char*) sqrtLocalsSpec, NULL, 0, sizeof(sqrtLocalsSpec)}, 0};
static DanaType sqrtDecLocalsSpec[] = {
{TYPE_DECIMAL, X_FLAT, 0, sizeof(size_t)*2, sizeof(size_t)*2, 0},
{TYPE_DECIMAL, X_FLAT, 0, sizeof(size_t)*2, sizeof(size_t)*2, 0}};
static StructuredType sqrtDecLocalsDef = {{}, {(unsigned char*) sqrtDecLocalsSpec, NULL, 0, sizeof(sqrtDecLocalsSpec)}, 0};
static unsigned char op_clone_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_equals_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_toString_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_sqrt_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_sqrtDec_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static SourceHeader header;
static Component self;
static size_t interfaceFunctions[] = {
(size_t) op_clone_thread_spec,
(size_t) op_equals_thread_spec,
(size_t) op_toString_thread_spec,
(size_t) op_sqrt_thread_spec,
(size_t) op_sqrtDec_thread_spec};
static DanaType libType = {TYPE_OBJECT, 0, 0, 0, 0, 0, {(unsigned char*) &ILib}};
static InterfaceDetails ids[] = {{(size_t) &libType, (size_t) &libType, 0, NULL}};
static Interface objectInterfaces[] = {{&ids[0], {&self, NULL, NULL, interfaceFunctions, NULL, NULL}}		};
static ObjectSpec objects[] = {{objectInterfaces, 1, 0, 0, 0, 0, (size_t) &emptyType}};
static void populateOffsets(DanaType *list, size_t length, StructuredType *def){
int i = 0; unsigned int totalSize = 0;
for (i = 0; i < length; i++){
list[i].offset = totalSize; totalSize += list[i].length;
#ifdef ADDRESS_ALIGN
totalSize += totalSize % ADDRESS_WIDTH != 0 ? (ADDRESS_WIDTH - (totalSize % ADDRESS_WIDTH)) : 0;
#endif
}
def -> size = totalSize;}

Interface* getPublicInterface(){
populateOffsets(cloneLocalsSpec, sizeof(cloneLocalsSpec) / sizeof(DanaType), &cloneLocalsDef);
populateOffsets(equalsLocalsSpec, sizeof(equalsLocalsSpec) / sizeof(DanaType), &equalsLocalsDef);
populateOffsets(toStringLocalsSpec, sizeof(toStringLocalsSpec) / sizeof(DanaType), &toStringLocalsDef);
populateOffsets(sqrtLocalsSpec, sizeof(sqrtLocalsSpec) / sizeof(DanaType), &sqrtLocalsDef);
populateOffsets(sqrtDecLocalsSpec, sizeof(sqrtDecLocalsSpec) / sizeof(DanaType), &sqrtDecLocalsDef);
((VFrameHeader*) op_clone_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + cloneLocalsDef.size;
((VFrameHeader*) op_clone_thread_spec) -> formalParamsCount = (cloneLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_clone_thread_spec)[1])[0] = (size_t) &cloneLocalsDef;
((VFrameHeader*) op_clone_thread_spec) -> functionName = "clone";
((VFrameHeader*) op_equals_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + equalsLocalsDef.size;
((VFrameHeader*) op_equals_thread_spec) -> formalParamsCount = (equalsLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_equals_thread_spec)[1])[0] = (size_t) &equalsLocalsDef;
((VFrameHeader*) op_equals_thread_spec) -> functionName = "equals";
((VFrameHeader*) op_toString_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + toStringLocalsDef.size;
((VFrameHeader*) op_toString_thread_spec) -> formalParamsCount = (toStringLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_toString_thread_spec)[1])[0] = (size_t) &toStringLocalsDef;
((VFrameHeader*) op_toString_thread_spec) -> functionName = "toString";
((VFrameHeader*) op_sqrt_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + sqrtLocalsDef.size;
((VFrameHeader*) op_sqrt_thread_spec) -> formalParamsCount = (sqrtLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_sqrt_thread_spec)[1])[0] = (size_t) &sqrtLocalsDef;
((VFrameHeader*) op_sqrt_thread_spec) -> functionName = "sqrt";
((VFrameHeader*) op_sqrtDec_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + sqrtDecLocalsDef.size;
((VFrameHeader*) op_sqrtDec_thread_spec) -> formalParamsCount = (sqrtDecLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_sqrtDec_thread_spec)[1])[0] = (size_t) &sqrtDecLocalsDef;
((VFrameHeader*) op_sqrtDec_thread_spec) -> functionName = "sqrtDec";
memset(&self, '\0', sizeof(self));
self.objects = objects; self.header = &header; self.header -> objectsCount = sizeof(objects) / sizeof(ObjectSpec);
objectInterfaces[0].lbp.spec = &objects[0];
return &objectInterfaces[0];
}

typedef struct{
char *name;
VFrameHeader *hdr;
} Fable;

static Fable interfaceMappings[] = {
{"clone", (VFrameHeader*) op_clone_thread_spec},
{"equals", (VFrameHeader*) op_equals_thread_spec},
{"toString", (VFrameHeader*) op_toString_thread_spec},
{"sqrt", (VFrameHeader*) op_sqrt_thread_spec},
{"sqrtDec", (VFrameHeader*) op_sqrtDec_thread_spec}};
void setInterfaceFunction(char *name, void *ptr){
int i = 0;
for (i = 0; i < sizeof(interfaceMappings) / sizeof(Fable); i ++){
if (strcmp(interfaceMappings[i].name, name) == 0){
interfaceMappings[i].hdr -> pcLoc = (unsigned char*) ptr;
interfaceMappings[i].hdr -> registerCount = 1;
interfaceMappings[i].hdr -> scopeCount = 1;
break;
}
}
}

typedef struct{
char *name;
const DanaType *dataType;
} Ex;

static Ex dataMappings[] = {
{"char[]", &data_char_array_map_def}};
const DanaType* getTypeDefinition(char *name){
int i = 0;
for (i = 0; i < sizeof(dataMappings) / sizeof(Ex); i ++){
if (strcmp(dataMappings[i].name, name) == 0){
return dataMappings[i].dataType;
}
}
return NULL;
}

