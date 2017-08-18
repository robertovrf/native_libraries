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
static const DanaType array_byte_spec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static const StructuredType array_byte_def = {{NULL, NULL, 0, 0}, {(unsigned char*) array_byte_spec, NULL, 0, sizeof(array_byte_spec)}, sizeof(VVarLivePTR)};
static const DanaType data_byte_array_map_def = 
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_byte_def}};
static const DanaType data_Datagram_spec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_byte_def}}};
static const StructuredType data_Datagram_def = {{NULL, NULL, 0, 0}, {(unsigned char*) data_Datagram_spec, NULL, 0, sizeof(data_Datagram_spec)}, 0};
static const DanaType data_Datagram_map_def = 
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_Datagram_def}};
static const DanaType function_IOUDPLib_clone_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 1, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const StructuredType function_IOUDPLib_clone_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOUDPLib_clone_def, NULL, 0, sizeof(function_IOUDPLib_clone_def)}, 0};
static const DanaType function_IOUDPLib_equals_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 1, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const StructuredType function_IOUDPLib_equals_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOUDPLib_equals_def, NULL, 0, sizeof(function_IOUDPLib_equals_def)}, 0};
static const DanaType function_IOUDPLib_toString_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_IOUDPLib_toString_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOUDPLib_toString_def, NULL, 0, sizeof(function_IOUDPLib_toString_def)}, 0};
static const DanaType function_IOUDPLib_getID_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_IOUDPLib_getID_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOUDPLib_getID_def, NULL, 0, sizeof(function_IOUDPLib_getID_def)}, 0};
static const DanaType function_IOUDPLib_send_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_byte_def}}};
static const StructuredType function_IOUDPLib_send_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOUDPLib_send_def, NULL, 0, sizeof(function_IOUDPLib_send_def)}, 0};
static const DanaType function_IOUDPLib_recv_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_Datagram_def}}};
static const StructuredType function_IOUDPLib_recv_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOUDPLib_recv_def, NULL, 0, sizeof(function_IOUDPLib_recv_def)}, 0};
static const DanaType function_IOUDPLib_bind_def[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_IOUDPLib_bind_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOUDPLib_bind_def, NULL, 0, sizeof(function_IOUDPLib_bind_def)}, 0};
static const DanaType function_IOUDPLib_unbind_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_IOUDPLib_unbind_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOUDPLib_unbind_def, NULL, 0, sizeof(function_IOUDPLib_unbind_def)}, 0};
static const StructuredFunctionType intf_fnc[] = {
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOUDPLib_clone_def, NULL, 0, sizeof(function_IOUDPLib_clone_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOUDPLib_equals_def, NULL, 0, sizeof(function_IOUDPLib_equals_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOUDPLib_toString_def, NULL, 0, sizeof(function_IOUDPLib_toString_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOUDPLib_getID_def, NULL, 0, sizeof(function_IOUDPLib_getID_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOUDPLib_send_def, NULL, 0, sizeof(function_IOUDPLib_send_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOUDPLib_recv_def, NULL, 0, sizeof(function_IOUDPLib_recv_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOUDPLib_bind_def, NULL, 0, sizeof(function_IOUDPLib_bind_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOUDPLib_unbind_def, NULL, 0, sizeof(function_IOUDPLib_unbind_def)}, 0}};
static const DanaType intf_def[] = {
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[0]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[1]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[2]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[3]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[4]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[5]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[6]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[7]}}};
static StructuredInterfaceType ILib = {{(unsigned char*) "IOUDPLib", NULL, 0, 8}, {(unsigned char*) intf_def, NULL, 0, sizeof(intf_def)}, 0};
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
static DanaType sendLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_byte_def}}};
static StructuredType sendLocalsDef = {{}, {(unsigned char*) sendLocalsSpec, NULL, 0, sizeof(sendLocalsSpec)}, 0};
static DanaType recvLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_Datagram_def}}};
static StructuredType recvLocalsDef = {{}, {(unsigned char*) recvLocalsSpec, NULL, 0, sizeof(recvLocalsSpec)}, 0};
static DanaType bindLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType bindLocalsDef = {{}, {(unsigned char*) bindLocalsSpec, NULL, 0, sizeof(bindLocalsSpec)}, 0};
static DanaType unbindLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType unbindLocalsDef = {{}, {(unsigned char*) unbindLocalsSpec, NULL, 0, sizeof(unbindLocalsSpec)}, 0};
static unsigned char op_clone_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_equals_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_toString_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getID_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_send_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_recv_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_bind_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_unbind_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static SourceHeader header;
static Component self;
static size_t interfaceFunctions[] = {
(size_t) op_clone_thread_spec,
(size_t) op_equals_thread_spec,
(size_t) op_toString_thread_spec,
(size_t) op_getID_thread_spec,
(size_t) op_send_thread_spec,
(size_t) op_recv_thread_spec,
(size_t) op_bind_thread_spec,
(size_t) op_unbind_thread_spec};
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
populateOffsets(sendLocalsSpec, sizeof(sendLocalsSpec) / sizeof(DanaType), &sendLocalsDef);
populateOffsets(recvLocalsSpec, sizeof(recvLocalsSpec) / sizeof(DanaType), &recvLocalsDef);
populateOffsets(bindLocalsSpec, sizeof(bindLocalsSpec) / sizeof(DanaType), &bindLocalsDef);
populateOffsets(unbindLocalsSpec, sizeof(unbindLocalsSpec) / sizeof(DanaType), &unbindLocalsDef);
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
((VFrameHeader*) op_send_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + sendLocalsDef.size;
((VFrameHeader*) op_send_thread_spec) -> formalParamsCount = (sendLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_send_thread_spec)[1])[0] = (size_t) &sendLocalsDef;
((VFrameHeader*) op_send_thread_spec) -> functionName = "send";
((VFrameHeader*) op_recv_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + recvLocalsDef.size;
((VFrameHeader*) op_recv_thread_spec) -> formalParamsCount = (recvLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_recv_thread_spec)[1])[0] = (size_t) &recvLocalsDef;
((VFrameHeader*) op_recv_thread_spec) -> functionName = "recv";
((VFrameHeader*) op_bind_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + bindLocalsDef.size;
((VFrameHeader*) op_bind_thread_spec) -> formalParamsCount = (bindLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_bind_thread_spec)[1])[0] = (size_t) &bindLocalsDef;
((VFrameHeader*) op_bind_thread_spec) -> functionName = "bind";
((VFrameHeader*) op_unbind_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + unbindLocalsDef.size;
((VFrameHeader*) op_unbind_thread_spec) -> formalParamsCount = (unbindLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_unbind_thread_spec)[1])[0] = (size_t) &unbindLocalsDef;
((VFrameHeader*) op_unbind_thread_spec) -> functionName = "unbind";
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
{"send", (VFrameHeader*) op_send_thread_spec},
{"recv", (VFrameHeader*) op_recv_thread_spec},
{"bind", (VFrameHeader*) op_bind_thread_spec},
{"unbind", (VFrameHeader*) op_unbind_thread_spec}};
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
{"Datagram", &data_Datagram_map_def},
{"byte[]", &data_byte_array_map_def},
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

