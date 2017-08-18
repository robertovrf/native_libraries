#include "dana_lib_defs.h"
#include <string.h>
DanaType emptyType = {TYPE_PATTERN, 0, 0, 0, 0, 0};
#define ADDRESS_ALIGN true
#define ADDRESS_WIDTH sizeof(size_t)
static const StructuredType object_Object_def;
static const DanaType function_Object_clone_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 1, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const StructuredType function_Object_clone_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_Object_clone_def, NULL, 0, sizeof(function_Object_clone_def)}, 0};
static const DanaType function_Object_equals_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 1, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const StructuredType function_Object_equals_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_Object_equals_def, NULL, 0, sizeof(function_Object_equals_def)}, 0};
static const DanaType array_char_spec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static const StructuredType array_char_def = {{NULL, NULL, 0, 0}, {(unsigned char*) array_char_spec, NULL, 0, sizeof(array_char_spec)}, sizeof(VVarLivePTR)};
static const DanaType data_char_array_map_def = 
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}};
static const DanaType function_Object_toString_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_Object_toString_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_Object_toString_def, NULL, 0, sizeof(function_Object_toString_def)}, 0};
static const DanaType function_Object_getID_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_Object_getID_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_Object_getID_def, NULL, 0, sizeof(function_Object_getID_def)}, 0};
static const DanaType object_Object_spec[] = {
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &function_Object_clone_spec}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &function_Object_equals_spec}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &function_Object_toString_spec}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &function_Object_getID_spec}}};
static const StructuredType object_Object_def = {{NULL, NULL, 0, 0}, {(unsigned char*) object_Object_spec, NULL, 0, sizeof(object_Object_spec)}, sizeof(VVarLivePTR)};
static const DanaType data_VC_spec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType data_VC_def = {{NULL, NULL, 0, 0}, {(unsigned char*) data_VC_spec, NULL, 0, sizeof(data_VC_spec)}, 0};
static const DanaType data_VC_map_def = 
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_VC_def}};
static const DanaType function_SystemLib_clone_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 1, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const StructuredType function_SystemLib_clone_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_clone_def, NULL, 0, sizeof(function_SystemLib_clone_def)}, 0};
static const DanaType function_SystemLib_equals_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 1, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const StructuredType function_SystemLib_equals_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_equals_def, NULL, 0, sizeof(function_SystemLib_equals_def)}, 0};
static const DanaType function_SystemLib_toString_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_SystemLib_toString_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_toString_def, NULL, 0, sizeof(function_SystemLib_toString_def)}, 0};
static const DanaType function_SystemLib_getID_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_SystemLib_getID_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_getID_def, NULL, 0, sizeof(function_SystemLib_getID_def)}, 0};
static const DanaType function_SystemLib_getPlatformName_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_VC_def}}};
static const StructuredType function_SystemLib_getPlatformName_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_getPlatformName_def, NULL, 0, sizeof(function_SystemLib_getPlatformName_def)}, 0};
static const DanaType function_SystemLib_getPlatformVersion_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_VC_def}}};
static const StructuredType function_SystemLib_getPlatformVersion_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_getPlatformVersion_def, NULL, 0, sizeof(function_SystemLib_getPlatformVersion_def)}, 0};
static const DanaType function_SystemLib_getChipName_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_VC_def}}};
static const StructuredType function_SystemLib_getChipName_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_getChipName_def, NULL, 0, sizeof(function_SystemLib_getChipName_def)}, 0};
static const DanaType function_SystemLib_getHostName_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_VC_def}}};
static const StructuredType function_SystemLib_getHostName_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_getHostName_def, NULL, 0, sizeof(function_SystemLib_getHostName_def)}, 0};
static const DanaType function_SystemLib_getVar_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_VC_def}}};
static const StructuredType function_SystemLib_getVar_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_getVar_def, NULL, 0, sizeof(function_SystemLib_getVar_def)}, 0};
static const DanaType function_SystemLib_getSystemFont_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_VC_def}}};
static const StructuredType function_SystemLib_getSystemFont_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_getSystemFont_def, NULL, 0, sizeof(function_SystemLib_getSystemFont_def)}, 0};
static const StructuredFunctionType intf_fnc[] = {
{{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_clone_def, NULL, 0, sizeof(function_SystemLib_clone_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_equals_def, NULL, 0, sizeof(function_SystemLib_equals_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_toString_def, NULL, 0, sizeof(function_SystemLib_toString_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_getID_def, NULL, 0, sizeof(function_SystemLib_getID_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_getPlatformName_def, NULL, 0, sizeof(function_SystemLib_getPlatformName_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_getPlatformVersion_def, NULL, 0, sizeof(function_SystemLib_getPlatformVersion_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_getChipName_def, NULL, 0, sizeof(function_SystemLib_getChipName_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_getHostName_def, NULL, 0, sizeof(function_SystemLib_getHostName_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_getVar_def, NULL, 0, sizeof(function_SystemLib_getVar_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_SystemLib_getSystemFont_def, NULL, 0, sizeof(function_SystemLib_getSystemFont_def)}, 0}};
static const DanaType intf_def[] = {
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[0]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[1]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[2]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[3]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[4]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[5]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[6]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[7]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[8]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[9]}}};
static StructuredInterfaceType ILib = {{(unsigned char*) "SystemLib", NULL, 0, 9}, {(unsigned char*) intf_def, NULL, 0, sizeof(intf_def)}, 0};
static DanaType cloneLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 1, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static StructuredType cloneLocalsDef = {{}, {(unsigned char*) cloneLocalsSpec, NULL, 0, sizeof(cloneLocalsSpec)}, 0};
static DanaType equalsLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 1, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static StructuredType equalsLocalsDef = {{}, {(unsigned char*) equalsLocalsSpec, NULL, 0, sizeof(equalsLocalsSpec)}, 0};
static DanaType toStringLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType toStringLocalsDef = {{}, {(unsigned char*) toStringLocalsSpec, NULL, 0, sizeof(toStringLocalsSpec)}, 0};
static DanaType getIDLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType getIDLocalsDef = {{}, {(unsigned char*) getIDLocalsSpec, NULL, 0, sizeof(getIDLocalsSpec)}, 0};
static DanaType getPlatformNameLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_VC_def}}};
static StructuredType getPlatformNameLocalsDef = {{}, {(unsigned char*) getPlatformNameLocalsSpec, NULL, 0, sizeof(getPlatformNameLocalsSpec)}, 0};
static DanaType getPlatformVersionLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_VC_def}}};
static StructuredType getPlatformVersionLocalsDef = {{}, {(unsigned char*) getPlatformVersionLocalsSpec, NULL, 0, sizeof(getPlatformVersionLocalsSpec)}, 0};
static DanaType getChipNameLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_VC_def}}};
static StructuredType getChipNameLocalsDef = {{}, {(unsigned char*) getChipNameLocalsSpec, NULL, 0, sizeof(getChipNameLocalsSpec)}, 0};
static DanaType getHostNameLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_VC_def}}};
static StructuredType getHostNameLocalsDef = {{}, {(unsigned char*) getHostNameLocalsSpec, NULL, 0, sizeof(getHostNameLocalsSpec)}, 0};
static DanaType getVarLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_VC_def}}};
static StructuredType getVarLocalsDef = {{}, {(unsigned char*) getVarLocalsSpec, NULL, 0, sizeof(getVarLocalsSpec)}, 0};
static DanaType getSystemFontLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_VC_def}}};
static StructuredType getSystemFontLocalsDef = {{}, {(unsigned char*) getSystemFontLocalsSpec, NULL, 0, sizeof(getSystemFontLocalsSpec)}, 0};
static unsigned char op_clone_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_equals_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_toString_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getID_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getPlatformName_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getPlatformVersion_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getChipName_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getHostName_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getVar_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getSystemFont_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static SourceHeader header;
static Component self;
static size_t interfaceFunctions[] = {
(size_t) op_clone_thread_spec,
(size_t) op_equals_thread_spec,
(size_t) op_toString_thread_spec,
(size_t) op_getID_thread_spec,
(size_t) op_getPlatformName_thread_spec,
(size_t) op_getPlatformVersion_thread_spec,
(size_t) op_getChipName_thread_spec,
(size_t) op_getHostName_thread_spec,
(size_t) op_getVar_thread_spec,
(size_t) op_getSystemFont_thread_spec};
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
populateOffsets(getIDLocalsSpec, sizeof(getIDLocalsSpec) / sizeof(DanaType), &getIDLocalsDef);
populateOffsets(getPlatformNameLocalsSpec, sizeof(getPlatformNameLocalsSpec) / sizeof(DanaType), &getPlatformNameLocalsDef);
populateOffsets(getPlatformVersionLocalsSpec, sizeof(getPlatformVersionLocalsSpec) / sizeof(DanaType), &getPlatformVersionLocalsDef);
populateOffsets(getChipNameLocalsSpec, sizeof(getChipNameLocalsSpec) / sizeof(DanaType), &getChipNameLocalsDef);
populateOffsets(getHostNameLocalsSpec, sizeof(getHostNameLocalsSpec) / sizeof(DanaType), &getHostNameLocalsDef);
populateOffsets(getVarLocalsSpec, sizeof(getVarLocalsSpec) / sizeof(DanaType), &getVarLocalsDef);
populateOffsets(getSystemFontLocalsSpec, sizeof(getSystemFontLocalsSpec) / sizeof(DanaType), &getSystemFontLocalsDef);
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
((VFrameHeader*) op_getID_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + getIDLocalsDef.size;
((VFrameHeader*) op_getID_thread_spec) -> formalParamsCount = (getIDLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_getID_thread_spec)[1])[0] = (size_t) &getIDLocalsDef;
((VFrameHeader*) op_getID_thread_spec) -> functionName = "getID";
((VFrameHeader*) op_getPlatformName_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + getPlatformNameLocalsDef.size;
((VFrameHeader*) op_getPlatformName_thread_spec) -> formalParamsCount = (getPlatformNameLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_getPlatformName_thread_spec)[1])[0] = (size_t) &getPlatformNameLocalsDef;
((VFrameHeader*) op_getPlatformName_thread_spec) -> functionName = "getPlatformName";
((VFrameHeader*) op_getPlatformVersion_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + getPlatformVersionLocalsDef.size;
((VFrameHeader*) op_getPlatformVersion_thread_spec) -> formalParamsCount = (getPlatformVersionLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_getPlatformVersion_thread_spec)[1])[0] = (size_t) &getPlatformVersionLocalsDef;
((VFrameHeader*) op_getPlatformVersion_thread_spec) -> functionName = "getPlatformVersion";
((VFrameHeader*) op_getChipName_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + getChipNameLocalsDef.size;
((VFrameHeader*) op_getChipName_thread_spec) -> formalParamsCount = (getChipNameLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_getChipName_thread_spec)[1])[0] = (size_t) &getChipNameLocalsDef;
((VFrameHeader*) op_getChipName_thread_spec) -> functionName = "getChipName";
((VFrameHeader*) op_getHostName_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + getHostNameLocalsDef.size;
((VFrameHeader*) op_getHostName_thread_spec) -> formalParamsCount = (getHostNameLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_getHostName_thread_spec)[1])[0] = (size_t) &getHostNameLocalsDef;
((VFrameHeader*) op_getHostName_thread_spec) -> functionName = "getHostName";
((VFrameHeader*) op_getVar_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + getVarLocalsDef.size;
((VFrameHeader*) op_getVar_thread_spec) -> formalParamsCount = (getVarLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_getVar_thread_spec)[1])[0] = (size_t) &getVarLocalsDef;
((VFrameHeader*) op_getVar_thread_spec) -> functionName = "getVar";
((VFrameHeader*) op_getSystemFont_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + getSystemFontLocalsDef.size;
((VFrameHeader*) op_getSystemFont_thread_spec) -> formalParamsCount = (getSystemFontLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_getSystemFont_thread_spec)[1])[0] = (size_t) &getSystemFontLocalsDef;
((VFrameHeader*) op_getSystemFont_thread_spec) -> functionName = "getSystemFont";
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
{"getID", (VFrameHeader*) op_getID_thread_spec},
{"getPlatformName", (VFrameHeader*) op_getPlatformName_thread_spec},
{"getPlatformVersion", (VFrameHeader*) op_getPlatformVersion_thread_spec},
{"getChipName", (VFrameHeader*) op_getChipName_thread_spec},
{"getHostName", (VFrameHeader*) op_getHostName_thread_spec},
{"getVar", (VFrameHeader*) op_getVar_thread_spec},
{"getSystemFont", (VFrameHeader*) op_getSystemFont_thread_spec}};
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
{"VC", &data_VC_map_def},
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

