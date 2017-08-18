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
static const DanaType data_BC_spec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_byte_def}}};
static const StructuredType data_BC_def = {{NULL, NULL, 0, 0}, {(unsigned char*) data_BC_spec, NULL, 0, sizeof(data_BC_spec)}, 0};
static const DanaType data_BC_map_def = 
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_BC_def}};
static const DanaType data_NetworkEndpoint_spec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType data_NetworkEndpoint_def = {{NULL, NULL, 0, 0}, {(unsigned char*) data_NetworkEndpoint_spec, NULL, 0, sizeof(data_NetworkEndpoint_spec)}, 0};
static const DanaType data_NetworkEndpoint_map_def = 
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_NetworkEndpoint_def}};
static const DanaType function_IOTCPLib_clone_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 1, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const StructuredType function_IOTCPLib_clone_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_clone_def, NULL, 0, sizeof(function_IOTCPLib_clone_def)}, 0};
static const DanaType function_IOTCPLib_equals_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 1, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const StructuredType function_IOTCPLib_equals_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_equals_def, NULL, 0, sizeof(function_IOTCPLib_equals_def)}, 0};
static const DanaType function_IOTCPLib_toString_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_IOTCPLib_toString_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_toString_def, NULL, 0, sizeof(function_IOTCPLib_toString_def)}, 0};
static const DanaType function_IOTCPLib_getID_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_IOTCPLib_getID_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_getID_def, NULL, 0, sizeof(function_IOTCPLib_getID_def)}, 0};
static const DanaType function_IOTCPLib_connect_def[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_IOTCPLib_connect_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_connect_def, NULL, 0, sizeof(function_IOTCPLib_connect_def)}, 0};
static const DanaType function_IOTCPLib_disconnect_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_IOTCPLib_disconnect_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_disconnect_def, NULL, 0, sizeof(function_IOTCPLib_disconnect_def)}, 0};
static const DanaType function_IOTCPLib_send_def[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_byte_def}}};
static const StructuredType function_IOTCPLib_send_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_send_def, NULL, 0, sizeof(function_IOTCPLib_send_def)}, 0};
static const DanaType function_IOTCPLib_recv_def[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_BC_def}}};
static const StructuredType function_IOTCPLib_recv_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_recv_def, NULL, 0, sizeof(function_IOTCPLib_recv_def)}, 0};
static const DanaType function_IOTCPLib_accept_def[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_IOTCPLib_accept_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_accept_def, NULL, 0, sizeof(function_IOTCPLib_accept_def)}, 0};
static const DanaType function_IOTCPLib_bind_def[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_IOTCPLib_bind_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_bind_def, NULL, 0, sizeof(function_IOTCPLib_bind_def)}, 0};
static const DanaType function_IOTCPLib_unbind_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_IOTCPLib_unbind_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_unbind_def, NULL, 0, sizeof(function_IOTCPLib_unbind_def)}, 0};
static const DanaType function_IOTCPLib_getLocalAddress_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_NetworkEndpoint_def}}};
static const StructuredType function_IOTCPLib_getLocalAddress_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_getLocalAddress_def, NULL, 0, sizeof(function_IOTCPLib_getLocalAddress_def)}, 0};
static const DanaType function_IOTCPLib_getRemoteAddress_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_NetworkEndpoint_def}}};
static const StructuredType function_IOTCPLib_getRemoteAddress_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_getRemoteAddress_def, NULL, 0, sizeof(function_IOTCPLib_getRemoteAddress_def)}, 0};
static const StructuredFunctionType intf_fnc[] = {
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_clone_def, NULL, 0, sizeof(function_IOTCPLib_clone_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_equals_def, NULL, 0, sizeof(function_IOTCPLib_equals_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_toString_def, NULL, 0, sizeof(function_IOTCPLib_toString_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_getID_def, NULL, 0, sizeof(function_IOTCPLib_getID_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_connect_def, NULL, 0, sizeof(function_IOTCPLib_connect_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_disconnect_def, NULL, 0, sizeof(function_IOTCPLib_disconnect_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_send_def, NULL, 0, sizeof(function_IOTCPLib_send_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_recv_def, NULL, 0, sizeof(function_IOTCPLib_recv_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_accept_def, NULL, 0, sizeof(function_IOTCPLib_accept_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_bind_def, NULL, 0, sizeof(function_IOTCPLib_bind_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_unbind_def, NULL, 0, sizeof(function_IOTCPLib_unbind_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_getLocalAddress_def, NULL, 0, sizeof(function_IOTCPLib_getLocalAddress_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IOTCPLib_getRemoteAddress_def, NULL, 0, sizeof(function_IOTCPLib_getRemoteAddress_def)}, 0}};
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
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[9]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[10]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[11]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[12]}}};
static StructuredInterfaceType ILib = {{(unsigned char*) "IOTCPLib", NULL, 0, 8}, {(unsigned char*) intf_def, NULL, 0, sizeof(intf_def)}, 0};
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
static DanaType connectLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType connectLocalsDef = {{}, {(unsigned char*) connectLocalsSpec, NULL, 0, sizeof(connectLocalsSpec)}, 0};
static DanaType disconnectLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType disconnectLocalsDef = {{}, {(unsigned char*) disconnectLocalsSpec, NULL, 0, sizeof(disconnectLocalsSpec)}, 0};
static DanaType sendLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_byte_def}}};
static StructuredType sendLocalsDef = {{}, {(unsigned char*) sendLocalsSpec, NULL, 0, sizeof(sendLocalsSpec)}, 0};
static DanaType recvLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_BC_def}}};
static StructuredType recvLocalsDef = {{}, {(unsigned char*) recvLocalsSpec, NULL, 0, sizeof(recvLocalsSpec)}, 0};
static DanaType acceptLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType acceptLocalsDef = {{}, {(unsigned char*) acceptLocalsSpec, NULL, 0, sizeof(acceptLocalsSpec)}, 0};
static DanaType bindLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType bindLocalsDef = {{}, {(unsigned char*) bindLocalsSpec, NULL, 0, sizeof(bindLocalsSpec)}, 0};
static DanaType unbindLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType unbindLocalsDef = {{}, {(unsigned char*) unbindLocalsSpec, NULL, 0, sizeof(unbindLocalsSpec)}, 0};
static DanaType getLocalAddressLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_NetworkEndpoint_def}}};
static StructuredType getLocalAddressLocalsDef = {{}, {(unsigned char*) getLocalAddressLocalsSpec, NULL, 0, sizeof(getLocalAddressLocalsSpec)}, 0};
static DanaType getRemoteAddressLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_NetworkEndpoint_def}}};
static StructuredType getRemoteAddressLocalsDef = {{}, {(unsigned char*) getRemoteAddressLocalsSpec, NULL, 0, sizeof(getRemoteAddressLocalsSpec)}, 0};
static unsigned char op_clone_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_equals_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_toString_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getID_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_connect_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_disconnect_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_send_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_recv_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_accept_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_bind_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_unbind_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getLocalAddress_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getRemoteAddress_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static SourceHeader header;
static Component self;
static size_t interfaceFunctions[] = {
(size_t) op_clone_thread_spec,
(size_t) op_equals_thread_spec,
(size_t) op_toString_thread_spec,
(size_t) op_getID_thread_spec,
(size_t) op_connect_thread_spec,
(size_t) op_disconnect_thread_spec,
(size_t) op_send_thread_spec,
(size_t) op_recv_thread_spec,
(size_t) op_accept_thread_spec,
(size_t) op_bind_thread_spec,
(size_t) op_unbind_thread_spec,
(size_t) op_getLocalAddress_thread_spec,
(size_t) op_getRemoteAddress_thread_spec};
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
populateOffsets(connectLocalsSpec, sizeof(connectLocalsSpec) / sizeof(DanaType), &connectLocalsDef);
populateOffsets(disconnectLocalsSpec, sizeof(disconnectLocalsSpec) / sizeof(DanaType), &disconnectLocalsDef);
populateOffsets(sendLocalsSpec, sizeof(sendLocalsSpec) / sizeof(DanaType), &sendLocalsDef);
populateOffsets(recvLocalsSpec, sizeof(recvLocalsSpec) / sizeof(DanaType), &recvLocalsDef);
populateOffsets(acceptLocalsSpec, sizeof(acceptLocalsSpec) / sizeof(DanaType), &acceptLocalsDef);
populateOffsets(bindLocalsSpec, sizeof(bindLocalsSpec) / sizeof(DanaType), &bindLocalsDef);
populateOffsets(unbindLocalsSpec, sizeof(unbindLocalsSpec) / sizeof(DanaType), &unbindLocalsDef);
populateOffsets(getLocalAddressLocalsSpec, sizeof(getLocalAddressLocalsSpec) / sizeof(DanaType), &getLocalAddressLocalsDef);
populateOffsets(getRemoteAddressLocalsSpec, sizeof(getRemoteAddressLocalsSpec) / sizeof(DanaType), &getRemoteAddressLocalsDef);
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
((VFrameHeader*) op_connect_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + connectLocalsDef.size;
((VFrameHeader*) op_connect_thread_spec) -> formalParamsCount = (connectLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_connect_thread_spec)[1])[0] = (size_t) &connectLocalsDef;
((VFrameHeader*) op_connect_thread_spec) -> functionName = "connect";
((VFrameHeader*) op_disconnect_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + disconnectLocalsDef.size;
((VFrameHeader*) op_disconnect_thread_spec) -> formalParamsCount = (disconnectLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_disconnect_thread_spec)[1])[0] = (size_t) &disconnectLocalsDef;
((VFrameHeader*) op_disconnect_thread_spec) -> functionName = "disconnect";
((VFrameHeader*) op_send_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + sendLocalsDef.size;
((VFrameHeader*) op_send_thread_spec) -> formalParamsCount = (sendLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_send_thread_spec)[1])[0] = (size_t) &sendLocalsDef;
((VFrameHeader*) op_send_thread_spec) -> functionName = "send";
((VFrameHeader*) op_recv_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + recvLocalsDef.size;
((VFrameHeader*) op_recv_thread_spec) -> formalParamsCount = (recvLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_recv_thread_spec)[1])[0] = (size_t) &recvLocalsDef;
((VFrameHeader*) op_recv_thread_spec) -> functionName = "recv";
((VFrameHeader*) op_accept_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + acceptLocalsDef.size;
((VFrameHeader*) op_accept_thread_spec) -> formalParamsCount = (acceptLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_accept_thread_spec)[1])[0] = (size_t) &acceptLocalsDef;
((VFrameHeader*) op_accept_thread_spec) -> functionName = "accept";
((VFrameHeader*) op_bind_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + bindLocalsDef.size;
((VFrameHeader*) op_bind_thread_spec) -> formalParamsCount = (bindLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_bind_thread_spec)[1])[0] = (size_t) &bindLocalsDef;
((VFrameHeader*) op_bind_thread_spec) -> functionName = "bind";
((VFrameHeader*) op_unbind_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + unbindLocalsDef.size;
((VFrameHeader*) op_unbind_thread_spec) -> formalParamsCount = (unbindLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_unbind_thread_spec)[1])[0] = (size_t) &unbindLocalsDef;
((VFrameHeader*) op_unbind_thread_spec) -> functionName = "unbind";
((VFrameHeader*) op_getLocalAddress_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + getLocalAddressLocalsDef.size;
((VFrameHeader*) op_getLocalAddress_thread_spec) -> formalParamsCount = (getLocalAddressLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_getLocalAddress_thread_spec)[1])[0] = (size_t) &getLocalAddressLocalsDef;
((VFrameHeader*) op_getLocalAddress_thread_spec) -> functionName = "getLocalAddress";
((VFrameHeader*) op_getRemoteAddress_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + getRemoteAddressLocalsDef.size;
((VFrameHeader*) op_getRemoteAddress_thread_spec) -> formalParamsCount = (getRemoteAddressLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_getRemoteAddress_thread_spec)[1])[0] = (size_t) &getRemoteAddressLocalsDef;
((VFrameHeader*) op_getRemoteAddress_thread_spec) -> functionName = "getRemoteAddress";
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
{"connect", (VFrameHeader*) op_connect_thread_spec},
{"disconnect", (VFrameHeader*) op_disconnect_thread_spec},
{"send", (VFrameHeader*) op_send_thread_spec},
{"recv", (VFrameHeader*) op_recv_thread_spec},
{"accept", (VFrameHeader*) op_accept_thread_spec},
{"bind", (VFrameHeader*) op_bind_thread_spec},
{"unbind", (VFrameHeader*) op_unbind_thread_spec},
{"getLocalAddress", (VFrameHeader*) op_getLocalAddress_thread_spec},
{"getRemoteAddress", (VFrameHeader*) op_getRemoteAddress_thread_spec}};
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
{"NetworkEndpoint", &data_NetworkEndpoint_map_def},
{"BC", &data_BC_map_def},
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

