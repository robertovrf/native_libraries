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
static const DanaType data_FileEntry_spec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType data_FileEntry_def = {{NULL, NULL, 0, 0}, {(unsigned char*) data_FileEntry_spec, NULL, 0, sizeof(data_FileEntry_spec)}, 0};
static const DanaType data_FileEntry_map_def = 
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_FileEntry_def}};
static const DanaType array_FileEntry_spec[] = {
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_FileEntry_def}}};
static const StructuredType array_FileEntry_def = {{NULL, NULL, 0, 0}, {(unsigned char*) array_FileEntry_spec, NULL, 0, sizeof(array_FileEntry_spec)}, sizeof(VVarLivePTR)};
static const DanaType data_FileEntry_array_map_def = 
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_FileEntry_def}};
static const DanaType data_DCQ_spec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_FileEntry_def}}};
static const StructuredType data_DCQ_def = {{NULL, NULL, 0, 0}, {(unsigned char*) data_DCQ_spec, NULL, 0, sizeof(data_DCQ_spec)}, 0};
static const DanaType data_DCQ_map_def = 
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_DCQ_def}};
static const DanaType data_DateTime_spec[] = {
{TYPE_LITERAL, X_FLAT, 0, 2, 2, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 2, 2, 0}};
static const StructuredType data_DateTime_def = {{NULL, NULL, 0, 0}, {(unsigned char*) data_DateTime_spec, NULL, 0, sizeof(data_DateTime_spec)}, 0};
static const DanaType data_DateTime_map_def = 
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_DateTime_def}};
static const DanaType data_FileInfo_spec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_DateTime_def}}};
static const StructuredType data_FileInfo_def = {{NULL, NULL, 0, 0}, {(unsigned char*) data_FileInfo_spec, NULL, 0, sizeof(data_FileInfo_spec)}, 0};
static const DanaType data_FileInfo_map_def = 
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_FileInfo_def}};
static const DanaType function_IIOFileLib_clone_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 1, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const StructuredType function_IIOFileLib_clone_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_clone_def, NULL, 0, sizeof(function_IIOFileLib_clone_def)}, 0};
static const DanaType function_IIOFileLib_equals_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 1, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const StructuredType function_IIOFileLib_equals_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_equals_def, NULL, 0, sizeof(function_IIOFileLib_equals_def)}, 0};
static const DanaType function_IIOFileLib_toString_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_IIOFileLib_toString_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_toString_def, NULL, 0, sizeof(function_IIOFileLib_toString_def)}, 0};
static const DanaType function_IIOFileLib_getID_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_IIOFileLib_getID_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_getID_def, NULL, 0, sizeof(function_IIOFileLib_getID_def)}, 0};
static const DanaType function_IIOFileLib_open_def[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static const StructuredType function_IIOFileLib_open_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_open_def, NULL, 0, sizeof(function_IIOFileLib_open_def)}, 0};
static const DanaType function_IIOFileLib_write_def[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_byte_def}}};
static const StructuredType function_IIOFileLib_write_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_write_def, NULL, 0, sizeof(function_IIOFileLib_write_def)}, 0};
static const DanaType function_IIOFileLib_read_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_byte_def}},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_IIOFileLib_read_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_read_def, NULL, 0, sizeof(function_IIOFileLib_read_def)}, 0};
static const DanaType function_IIOFileLib_setPos_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_IIOFileLib_setPos_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_setPos_def, NULL, 0, sizeof(function_IIOFileLib_setPos_def)}, 0};
static const DanaType function_IIOFileLib_getSize_def[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_IIOFileLib_getSize_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_getSize_def, NULL, 0, sizeof(function_IIOFileLib_getSize_def)}, 0};
static const DanaType function_IIOFileLib_eof_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_IIOFileLib_eof_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_eof_def, NULL, 0, sizeof(function_IIOFileLib_eof_def)}, 0};
static const DanaType function_IIOFileLib_close_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_IIOFileLib_close_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_close_def, NULL, 0, sizeof(function_IIOFileLib_close_def)}, 0};
static const DanaType function_IIOFileLib_getDirectoryContents_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_DCQ_def}}};
static const StructuredType function_IIOFileLib_getDirectoryContents_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_getDirectoryContents_def, NULL, 0, sizeof(function_IIOFileLib_getDirectoryContents_def)}, 0};
static const DanaType function_IIOFileLib_getInfo_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_FileInfo_def}}};
static const StructuredType function_IIOFileLib_getInfo_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_getInfo_def, NULL, 0, sizeof(function_IIOFileLib_getInfo_def)}, 0};
static const DanaType function_IIOFileLib_exists_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_IIOFileLib_exists_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_exists_def, NULL, 0, sizeof(function_IIOFileLib_exists_def)}, 0};
static const DanaType function_IIOFileLib_delete_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_IIOFileLib_delete_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_delete_def, NULL, 0, sizeof(function_IIOFileLib_delete_def)}, 0};
static const DanaType function_IIOFileLib_move_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_IIOFileLib_move_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_move_def, NULL, 0, sizeof(function_IIOFileLib_move_def)}, 0};
static const DanaType function_IIOFileLib_copy_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static const StructuredType function_IIOFileLib_copy_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_copy_def, NULL, 0, sizeof(function_IIOFileLib_copy_def)}, 0};
static const DanaType function_IIOFileLib_createDirectory_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_IIOFileLib_createDirectory_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_createDirectory_def, NULL, 0, sizeof(function_IIOFileLib_createDirectory_def)}, 0};
static const DanaType function_IIOFileLib_deleteDirectory_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_IIOFileLib_deleteDirectory_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_deleteDirectory_def, NULL, 0, sizeof(function_IIOFileLib_deleteDirectory_def)}, 0};
static const StructuredFunctionType intf_fnc[] = {
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_clone_def, NULL, 0, sizeof(function_IIOFileLib_clone_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_equals_def, NULL, 0, sizeof(function_IIOFileLib_equals_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_toString_def, NULL, 0, sizeof(function_IIOFileLib_toString_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_getID_def, NULL, 0, sizeof(function_IIOFileLib_getID_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_open_def, NULL, 0, sizeof(function_IIOFileLib_open_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_write_def, NULL, 0, sizeof(function_IIOFileLib_write_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_read_def, NULL, 0, sizeof(function_IIOFileLib_read_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_setPos_def, NULL, 0, sizeof(function_IIOFileLib_setPos_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_getSize_def, NULL, 0, sizeof(function_IIOFileLib_getSize_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_eof_def, NULL, 0, sizeof(function_IIOFileLib_eof_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_close_def, NULL, 0, sizeof(function_IIOFileLib_close_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_getDirectoryContents_def, NULL, 0, sizeof(function_IIOFileLib_getDirectoryContents_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_getInfo_def, NULL, 0, sizeof(function_IIOFileLib_getInfo_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_exists_def, NULL, 0, sizeof(function_IIOFileLib_exists_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_delete_def, NULL, 0, sizeof(function_IIOFileLib_delete_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_move_def, NULL, 0, sizeof(function_IIOFileLib_move_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_copy_def, NULL, 0, sizeof(function_IIOFileLib_copy_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_createDirectory_def, NULL, 0, sizeof(function_IIOFileLib_createDirectory_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_IIOFileLib_deleteDirectory_def, NULL, 0, sizeof(function_IIOFileLib_deleteDirectory_def)}, 0}};
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
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[12]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[13]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[14]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[15]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[16]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[17]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[18]}}};
static StructuredInterfaceType ILib = {{(unsigned char*) "IIOFileLib", NULL, 0, 10}, {(unsigned char*) intf_def, NULL, 0, sizeof(intf_def)}, 0};
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
static DanaType openLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static StructuredType openLocalsDef = {{}, {(unsigned char*) openLocalsSpec, NULL, 0, sizeof(openLocalsSpec)}, 0};
static DanaType writeLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_byte_def}}};
static StructuredType writeLocalsDef = {{}, {(unsigned char*) writeLocalsSpec, NULL, 0, sizeof(writeLocalsSpec)}, 0};
static DanaType readLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_byte_def}},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType readLocalsDef = {{}, {(unsigned char*) readLocalsSpec, NULL, 0, sizeof(readLocalsSpec)}, 0};
static DanaType setPosLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType setPosLocalsDef = {{}, {(unsigned char*) setPosLocalsSpec, NULL, 0, sizeof(setPosLocalsSpec)}, 0};
static DanaType getSizeLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType getSizeLocalsDef = {{}, {(unsigned char*) getSizeLocalsSpec, NULL, 0, sizeof(getSizeLocalsSpec)}, 0};
static DanaType eofLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType eofLocalsDef = {{}, {(unsigned char*) eofLocalsSpec, NULL, 0, sizeof(eofLocalsSpec)}, 0};
static DanaType closeLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType closeLocalsDef = {{}, {(unsigned char*) closeLocalsSpec, NULL, 0, sizeof(closeLocalsSpec)}, 0};
static DanaType getDirectoryContentsLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_DCQ_def}}};
static StructuredType getDirectoryContentsLocalsDef = {{}, {(unsigned char*) getDirectoryContentsLocalsSpec, NULL, 0, sizeof(getDirectoryContentsLocalsSpec)}, 0};
static DanaType getInfoLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_FileInfo_def}}};
static StructuredType getInfoLocalsDef = {{}, {(unsigned char*) getInfoLocalsSpec, NULL, 0, sizeof(getInfoLocalsSpec)}, 0};
static DanaType existsLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType existsLocalsDef = {{}, {(unsigned char*) existsLocalsSpec, NULL, 0, sizeof(existsLocalsSpec)}, 0};
static DanaType deleteLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType deleteLocalsDef = {{}, {(unsigned char*) deleteLocalsSpec, NULL, 0, sizeof(deleteLocalsSpec)}, 0};
static DanaType moveLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType moveLocalsDef = {{}, {(unsigned char*) moveLocalsSpec, NULL, 0, sizeof(moveLocalsSpec)}, 0};
static DanaType copyLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static StructuredType copyLocalsDef = {{}, {(unsigned char*) copyLocalsSpec, NULL, 0, sizeof(copyLocalsSpec)}, 0};
static DanaType createDirectoryLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType createDirectoryLocalsDef = {{}, {(unsigned char*) createDirectoryLocalsSpec, NULL, 0, sizeof(createDirectoryLocalsSpec)}, 0};
static DanaType deleteDirectoryLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType deleteDirectoryLocalsDef = {{}, {(unsigned char*) deleteDirectoryLocalsSpec, NULL, 0, sizeof(deleteDirectoryLocalsSpec)}, 0};
static unsigned char op_clone_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_equals_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_toString_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getID_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_open_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_write_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_read_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_setPos_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getSize_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_eof_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_close_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getDirectoryContents_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getInfo_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_exists_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_delete_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_move_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_copy_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_createDirectory_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_deleteDirectory_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static SourceHeader header;
static Component self;
static size_t interfaceFunctions[] = {
(size_t) op_clone_thread_spec,
(size_t) op_equals_thread_spec,
(size_t) op_toString_thread_spec,
(size_t) op_getID_thread_spec,
(size_t) op_open_thread_spec,
(size_t) op_write_thread_spec,
(size_t) op_read_thread_spec,
(size_t) op_setPos_thread_spec,
(size_t) op_getSize_thread_spec,
(size_t) op_eof_thread_spec,
(size_t) op_close_thread_spec,
(size_t) op_getDirectoryContents_thread_spec,
(size_t) op_getInfo_thread_spec,
(size_t) op_exists_thread_spec,
(size_t) op_delete_thread_spec,
(size_t) op_move_thread_spec,
(size_t) op_copy_thread_spec,
(size_t) op_createDirectory_thread_spec,
(size_t) op_deleteDirectory_thread_spec};
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
populateOffsets(openLocalsSpec, sizeof(openLocalsSpec) / sizeof(DanaType), &openLocalsDef);
populateOffsets(writeLocalsSpec, sizeof(writeLocalsSpec) / sizeof(DanaType), &writeLocalsDef);
populateOffsets(readLocalsSpec, sizeof(readLocalsSpec) / sizeof(DanaType), &readLocalsDef);
populateOffsets(setPosLocalsSpec, sizeof(setPosLocalsSpec) / sizeof(DanaType), &setPosLocalsDef);
populateOffsets(getSizeLocalsSpec, sizeof(getSizeLocalsSpec) / sizeof(DanaType), &getSizeLocalsDef);
populateOffsets(eofLocalsSpec, sizeof(eofLocalsSpec) / sizeof(DanaType), &eofLocalsDef);
populateOffsets(closeLocalsSpec, sizeof(closeLocalsSpec) / sizeof(DanaType), &closeLocalsDef);
populateOffsets(getDirectoryContentsLocalsSpec, sizeof(getDirectoryContentsLocalsSpec) / sizeof(DanaType), &getDirectoryContentsLocalsDef);
populateOffsets(getInfoLocalsSpec, sizeof(getInfoLocalsSpec) / sizeof(DanaType), &getInfoLocalsDef);
populateOffsets(existsLocalsSpec, sizeof(existsLocalsSpec) / sizeof(DanaType), &existsLocalsDef);
populateOffsets(deleteLocalsSpec, sizeof(deleteLocalsSpec) / sizeof(DanaType), &deleteLocalsDef);
populateOffsets(moveLocalsSpec, sizeof(moveLocalsSpec) / sizeof(DanaType), &moveLocalsDef);
populateOffsets(copyLocalsSpec, sizeof(copyLocalsSpec) / sizeof(DanaType), &copyLocalsDef);
populateOffsets(createDirectoryLocalsSpec, sizeof(createDirectoryLocalsSpec) / sizeof(DanaType), &createDirectoryLocalsDef);
populateOffsets(deleteDirectoryLocalsSpec, sizeof(deleteDirectoryLocalsSpec) / sizeof(DanaType), &deleteDirectoryLocalsDef);
((VFrameHeader*) op_clone_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + cloneLocalsDef.size;
((VFrameHeader*) op_clone_thread_spec) -> formalParamsCount = (cloneLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_clone_thread_spec) -> localsDef = (size_t) &cloneLocalsDef;
((VFrameHeader*) op_clone_thread_spec) -> functionName = "clone";
((VFrameHeader*) op_equals_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + equalsLocalsDef.size;
((VFrameHeader*) op_equals_thread_spec) -> formalParamsCount = (equalsLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_equals_thread_spec) -> localsDef = (size_t) &equalsLocalsDef;
((VFrameHeader*) op_equals_thread_spec) -> functionName = "equals";
((VFrameHeader*) op_toString_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + toStringLocalsDef.size;
((VFrameHeader*) op_toString_thread_spec) -> formalParamsCount = (toStringLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_toString_thread_spec) -> localsDef = (size_t) &toStringLocalsDef;
((VFrameHeader*) op_toString_thread_spec) -> functionName = "toString";
((VFrameHeader*) op_getID_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + getIDLocalsDef.size;
((VFrameHeader*) op_getID_thread_spec) -> formalParamsCount = (getIDLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_getID_thread_spec) -> localsDef = (size_t) &getIDLocalsDef;
((VFrameHeader*) op_getID_thread_spec) -> functionName = "getID";
((VFrameHeader*) op_open_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + openLocalsDef.size;
((VFrameHeader*) op_open_thread_spec) -> formalParamsCount = (openLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_open_thread_spec) -> localsDef = (size_t) &openLocalsDef;
((VFrameHeader*) op_open_thread_spec) -> functionName = "open";
((VFrameHeader*) op_write_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + writeLocalsDef.size;
((VFrameHeader*) op_write_thread_spec) -> formalParamsCount = (writeLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_write_thread_spec) -> localsDef = (size_t) &writeLocalsDef;
((VFrameHeader*) op_write_thread_spec) -> functionName = "write";
((VFrameHeader*) op_read_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + readLocalsDef.size;
((VFrameHeader*) op_read_thread_spec) -> formalParamsCount = (readLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_read_thread_spec) -> localsDef = (size_t) &readLocalsDef;
((VFrameHeader*) op_read_thread_spec) -> functionName = "read";
((VFrameHeader*) op_setPos_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + setPosLocalsDef.size;
((VFrameHeader*) op_setPos_thread_spec) -> formalParamsCount = (setPosLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_setPos_thread_spec) -> localsDef = (size_t) &setPosLocalsDef;
((VFrameHeader*) op_setPos_thread_spec) -> functionName = "setPos";
((VFrameHeader*) op_getSize_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + getSizeLocalsDef.size;
((VFrameHeader*) op_getSize_thread_spec) -> formalParamsCount = (getSizeLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_getSize_thread_spec) -> localsDef = (size_t) &getSizeLocalsDef;
((VFrameHeader*) op_getSize_thread_spec) -> functionName = "getSize";
((VFrameHeader*) op_eof_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + eofLocalsDef.size;
((VFrameHeader*) op_eof_thread_spec) -> formalParamsCount = (eofLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_eof_thread_spec) -> localsDef = (size_t) &eofLocalsDef;
((VFrameHeader*) op_eof_thread_spec) -> functionName = "eof";
((VFrameHeader*) op_close_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + closeLocalsDef.size;
((VFrameHeader*) op_close_thread_spec) -> formalParamsCount = (closeLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_close_thread_spec) -> localsDef = (size_t) &closeLocalsDef;
((VFrameHeader*) op_close_thread_spec) -> functionName = "close";
((VFrameHeader*) op_getDirectoryContents_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + getDirectoryContentsLocalsDef.size;
((VFrameHeader*) op_getDirectoryContents_thread_spec) -> formalParamsCount = (getDirectoryContentsLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_getDirectoryContents_thread_spec) -> localsDef = (size_t) &getDirectoryContentsLocalsDef;
((VFrameHeader*) op_getDirectoryContents_thread_spec) -> functionName = "getDirectoryContents";
((VFrameHeader*) op_getInfo_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + getInfoLocalsDef.size;
((VFrameHeader*) op_getInfo_thread_spec) -> formalParamsCount = (getInfoLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_getInfo_thread_spec) -> localsDef = (size_t) &getInfoLocalsDef;
((VFrameHeader*) op_getInfo_thread_spec) -> functionName = "getInfo";
((VFrameHeader*) op_exists_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + existsLocalsDef.size;
((VFrameHeader*) op_exists_thread_spec) -> formalParamsCount = (existsLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_exists_thread_spec) -> localsDef = (size_t) &existsLocalsDef;
((VFrameHeader*) op_exists_thread_spec) -> functionName = "exists";
((VFrameHeader*) op_delete_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + deleteLocalsDef.size;
((VFrameHeader*) op_delete_thread_spec) -> formalParamsCount = (deleteLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_delete_thread_spec) -> localsDef = (size_t) &deleteLocalsDef;
((VFrameHeader*) op_delete_thread_spec) -> functionName = "delete";
((VFrameHeader*) op_move_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + moveLocalsDef.size;
((VFrameHeader*) op_move_thread_spec) -> formalParamsCount = (moveLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_move_thread_spec) -> localsDef = (size_t) &moveLocalsDef;
((VFrameHeader*) op_move_thread_spec) -> functionName = "move";
((VFrameHeader*) op_copy_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + copyLocalsDef.size;
((VFrameHeader*) op_copy_thread_spec) -> formalParamsCount = (copyLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_copy_thread_spec) -> localsDef = (size_t) &copyLocalsDef;
((VFrameHeader*) op_copy_thread_spec) -> functionName = "copy";
((VFrameHeader*) op_createDirectory_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + createDirectoryLocalsDef.size;
((VFrameHeader*) op_createDirectory_thread_spec) -> formalParamsCount = (createDirectoryLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_createDirectory_thread_spec) -> localsDef = (size_t) &createDirectoryLocalsDef;
((VFrameHeader*) op_createDirectory_thread_spec) -> functionName = "createDirectory";
((VFrameHeader*) op_deleteDirectory_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + deleteDirectoryLocalsDef.size;
((VFrameHeader*) op_deleteDirectory_thread_spec) -> formalParamsCount = (deleteDirectoryLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_deleteDirectory_thread_spec) -> localsDef = (size_t) &deleteDirectoryLocalsDef;
((VFrameHeader*) op_deleteDirectory_thread_spec) -> functionName = "deleteDirectory";
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
{"open", (VFrameHeader*) op_open_thread_spec},
{"write", (VFrameHeader*) op_write_thread_spec},
{"read", (VFrameHeader*) op_read_thread_spec},
{"setPos", (VFrameHeader*) op_setPos_thread_spec},
{"getSize", (VFrameHeader*) op_getSize_thread_spec},
{"eof", (VFrameHeader*) op_eof_thread_spec},
{"close", (VFrameHeader*) op_close_thread_spec},
{"getDirectoryContents", (VFrameHeader*) op_getDirectoryContents_thread_spec},
{"getInfo", (VFrameHeader*) op_getInfo_thread_spec},
{"exists", (VFrameHeader*) op_exists_thread_spec},
{"delete", (VFrameHeader*) op_delete_thread_spec},
{"move", (VFrameHeader*) op_move_thread_spec},
{"copy", (VFrameHeader*) op_copy_thread_spec},
{"createDirectory", (VFrameHeader*) op_createDirectory_thread_spec},
{"deleteDirectory", (VFrameHeader*) op_deleteDirectory_thread_spec}};
void setInterfaceFunction(char *name, void *ptr){
int i = 0;
for (i = 0; i < sizeof(interfaceMappings) / sizeof(Fable); i ++){
if (strcmp(interfaceMappings[i].name, name) == 0){
interfaceMappings[i].hdr -> pcLoc = (unsigned char*) ptr;
interfaceMappings[i].hdr -> registerCount = 1;
interfaceMappings[i].hdr -> localsDef = 0;
break;
}
}
}

typedef struct{
char *name;
const DanaType *dataType;
} Ex;

static Ex dataMappings[] = {
{"FileInfo", &data_FileInfo_map_def},
{"DateTime", &data_DateTime_map_def},
{"DCQ", &data_DCQ_map_def},
{"FileEntry[]", &data_FileEntry_array_map_def},
{"FileEntry", &data_FileEntry_map_def},
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

