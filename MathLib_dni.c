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
static const DanaType function_MathLib_clone_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 1, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const StructuredType function_MathLib_clone_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_clone_def, NULL, 0, sizeof(function_MathLib_clone_def)}, 0};
static const DanaType function_MathLib_equals_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 1, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const StructuredType function_MathLib_equals_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_equals_def, NULL, 0, sizeof(function_MathLib_equals_def)}, 0};
static const DanaType function_MathLib_toString_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_toString_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_toString_def, NULL, 0, sizeof(function_MathLib_toString_def)}, 0};
static const DanaType function_MathLib_getID_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_getID_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_getID_def, NULL, 0, sizeof(function_MathLib_getID_def)}, 0};
static const DanaType function_MathLib_sqrt_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_sqrt_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_sqrt_def, NULL, 0, sizeof(function_MathLib_sqrt_def)}, 0};
static const DanaType function_MathLib_pow_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_pow_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_pow_def, NULL, 0, sizeof(function_MathLib_pow_def)}, 0};
static const DanaType function_MathLib_root_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_root_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_root_def, NULL, 0, sizeof(function_MathLib_root_def)}, 0};
static const DanaType function_MathLib_log_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_log_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_log_def, NULL, 0, sizeof(function_MathLib_log_def)}, 0};
static const DanaType function_MathLib_natlog_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_natlog_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_natlog_def, NULL, 0, sizeof(function_MathLib_natlog_def)}, 0};
static const DanaType function_MathLib_natexp_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_natexp_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_natexp_def, NULL, 0, sizeof(function_MathLib_natexp_def)}, 0};
static const DanaType function_MathLib_cos_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_cos_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_cos_def, NULL, 0, sizeof(function_MathLib_cos_def)}, 0};
static const DanaType function_MathLib_sin_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_sin_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_sin_def, NULL, 0, sizeof(function_MathLib_sin_def)}, 0};
static const DanaType function_MathLib_tan_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_tan_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_tan_def, NULL, 0, sizeof(function_MathLib_tan_def)}, 0};
static const DanaType function_MathLib_acos_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_acos_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_acos_def, NULL, 0, sizeof(function_MathLib_acos_def)}, 0};
static const DanaType function_MathLib_asin_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_asin_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_asin_def, NULL, 0, sizeof(function_MathLib_asin_def)}, 0};
static const DanaType function_MathLib_atan_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_atan_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_atan_def, NULL, 0, sizeof(function_MathLib_atan_def)}, 0};
static const DanaType function_MathLib_cosh_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_cosh_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_cosh_def, NULL, 0, sizeof(function_MathLib_cosh_def)}, 0};
static const DanaType function_MathLib_sinh_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_sinh_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_sinh_def, NULL, 0, sizeof(function_MathLib_sinh_def)}, 0};
static const DanaType function_MathLib_tanh_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_tanh_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_tanh_def, NULL, 0, sizeof(function_MathLib_tanh_def)}, 0};
static const DanaType function_MathLib_acosh_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_acosh_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_acosh_def, NULL, 0, sizeof(function_MathLib_acosh_def)}, 0};
static const DanaType function_MathLib_asinh_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_asinh_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_asinh_def, NULL, 0, sizeof(function_MathLib_asinh_def)}, 0};
static const DanaType function_MathLib_atanh_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_MathLib_atanh_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_atanh_def, NULL, 0, sizeof(function_MathLib_atanh_def)}, 0};
static const StructuredFunctionType intf_fnc[] = {
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_clone_def, NULL, 0, sizeof(function_MathLib_clone_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_equals_def, NULL, 0, sizeof(function_MathLib_equals_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_toString_def, NULL, 0, sizeof(function_MathLib_toString_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_getID_def, NULL, 0, sizeof(function_MathLib_getID_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_sqrt_def, NULL, 0, sizeof(function_MathLib_sqrt_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_pow_def, NULL, 0, sizeof(function_MathLib_pow_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_root_def, NULL, 0, sizeof(function_MathLib_root_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_log_def, NULL, 0, sizeof(function_MathLib_log_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_natlog_def, NULL, 0, sizeof(function_MathLib_natlog_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_natexp_def, NULL, 0, sizeof(function_MathLib_natexp_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_cos_def, NULL, 0, sizeof(function_MathLib_cos_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_sin_def, NULL, 0, sizeof(function_MathLib_sin_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_tan_def, NULL, 0, sizeof(function_MathLib_tan_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_acos_def, NULL, 0, sizeof(function_MathLib_acos_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_asin_def, NULL, 0, sizeof(function_MathLib_asin_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_atan_def, NULL, 0, sizeof(function_MathLib_atan_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_cosh_def, NULL, 0, sizeof(function_MathLib_cosh_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_sinh_def, NULL, 0, sizeof(function_MathLib_sinh_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_tanh_def, NULL, 0, sizeof(function_MathLib_tanh_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_acosh_def, NULL, 0, sizeof(function_MathLib_acosh_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_asinh_def, NULL, 0, sizeof(function_MathLib_asinh_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_MathLib_atanh_def, NULL, 0, sizeof(function_MathLib_atanh_def)}, 0}};
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
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[18]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[19]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[20]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[21]}}};
static StructuredInterfaceType ILib = {{(unsigned char*) "MathLib", NULL, 0, 7}, {(unsigned char*) intf_def, NULL, 0, sizeof(intf_def)}, 0};
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
static DanaType sqrtLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType sqrtLocalsDef = {{}, {(unsigned char*) sqrtLocalsSpec, NULL, 0, sizeof(sqrtLocalsSpec)}, 0};
static DanaType powLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType powLocalsDef = {{}, {(unsigned char*) powLocalsSpec, NULL, 0, sizeof(powLocalsSpec)}, 0};
static DanaType rootLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType rootLocalsDef = {{}, {(unsigned char*) rootLocalsSpec, NULL, 0, sizeof(rootLocalsSpec)}, 0};
static DanaType logLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType logLocalsDef = {{}, {(unsigned char*) logLocalsSpec, NULL, 0, sizeof(logLocalsSpec)}, 0};
static DanaType natlogLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType natlogLocalsDef = {{}, {(unsigned char*) natlogLocalsSpec, NULL, 0, sizeof(natlogLocalsSpec)}, 0};
static DanaType natexpLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType natexpLocalsDef = {{}, {(unsigned char*) natexpLocalsSpec, NULL, 0, sizeof(natexpLocalsSpec)}, 0};
static DanaType cosLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType cosLocalsDef = {{}, {(unsigned char*) cosLocalsSpec, NULL, 0, sizeof(cosLocalsSpec)}, 0};
static DanaType sinLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType sinLocalsDef = {{}, {(unsigned char*) sinLocalsSpec, NULL, 0, sizeof(sinLocalsSpec)}, 0};
static DanaType tanLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType tanLocalsDef = {{}, {(unsigned char*) tanLocalsSpec, NULL, 0, sizeof(tanLocalsSpec)}, 0};
static DanaType acosLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType acosLocalsDef = {{}, {(unsigned char*) acosLocalsSpec, NULL, 0, sizeof(acosLocalsSpec)}, 0};
static DanaType asinLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType asinLocalsDef = {{}, {(unsigned char*) asinLocalsSpec, NULL, 0, sizeof(asinLocalsSpec)}, 0};
static DanaType atanLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType atanLocalsDef = {{}, {(unsigned char*) atanLocalsSpec, NULL, 0, sizeof(atanLocalsSpec)}, 0};
static DanaType coshLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType coshLocalsDef = {{}, {(unsigned char*) coshLocalsSpec, NULL, 0, sizeof(coshLocalsSpec)}, 0};
static DanaType sinhLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType sinhLocalsDef = {{}, {(unsigned char*) sinhLocalsSpec, NULL, 0, sizeof(sinhLocalsSpec)}, 0};
static DanaType tanhLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType tanhLocalsDef = {{}, {(unsigned char*) tanhLocalsSpec, NULL, 0, sizeof(tanhLocalsSpec)}, 0};
static DanaType acoshLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType acoshLocalsDef = {{}, {(unsigned char*) acoshLocalsSpec, NULL, 0, sizeof(acoshLocalsSpec)}, 0};
static DanaType asinhLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType asinhLocalsDef = {{}, {(unsigned char*) asinhLocalsSpec, NULL, 0, sizeof(asinhLocalsSpec)}, 0};
static DanaType atanhLocalsSpec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType atanhLocalsDef = {{}, {(unsigned char*) atanhLocalsSpec, NULL, 0, sizeof(atanhLocalsSpec)}, 0};
static unsigned char op_clone_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_equals_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_toString_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getID_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_sqrt_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_pow_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_root_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_log_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_natlog_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_natexp_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_cos_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_sin_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_tan_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_acos_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_asin_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_atan_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_cosh_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_sinh_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_tanh_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_acosh_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_asinh_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_atanh_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static SourceHeader header;
static Component self;
static size_t interfaceFunctions[] = {
(size_t) op_clone_thread_spec,
(size_t) op_equals_thread_spec,
(size_t) op_toString_thread_spec,
(size_t) op_getID_thread_spec,
(size_t) op_sqrt_thread_spec,
(size_t) op_pow_thread_spec,
(size_t) op_root_thread_spec,
(size_t) op_log_thread_spec,
(size_t) op_natlog_thread_spec,
(size_t) op_natexp_thread_spec,
(size_t) op_cos_thread_spec,
(size_t) op_sin_thread_spec,
(size_t) op_tan_thread_spec,
(size_t) op_acos_thread_spec,
(size_t) op_asin_thread_spec,
(size_t) op_atan_thread_spec,
(size_t) op_cosh_thread_spec,
(size_t) op_sinh_thread_spec,
(size_t) op_tanh_thread_spec,
(size_t) op_acosh_thread_spec,
(size_t) op_asinh_thread_spec,
(size_t) op_atanh_thread_spec};
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
populateOffsets(sqrtLocalsSpec, sizeof(sqrtLocalsSpec) / sizeof(DanaType), &sqrtLocalsDef);
populateOffsets(powLocalsSpec, sizeof(powLocalsSpec) / sizeof(DanaType), &powLocalsDef);
populateOffsets(rootLocalsSpec, sizeof(rootLocalsSpec) / sizeof(DanaType), &rootLocalsDef);
populateOffsets(logLocalsSpec, sizeof(logLocalsSpec) / sizeof(DanaType), &logLocalsDef);
populateOffsets(natlogLocalsSpec, sizeof(natlogLocalsSpec) / sizeof(DanaType), &natlogLocalsDef);
populateOffsets(natexpLocalsSpec, sizeof(natexpLocalsSpec) / sizeof(DanaType), &natexpLocalsDef);
populateOffsets(cosLocalsSpec, sizeof(cosLocalsSpec) / sizeof(DanaType), &cosLocalsDef);
populateOffsets(sinLocalsSpec, sizeof(sinLocalsSpec) / sizeof(DanaType), &sinLocalsDef);
populateOffsets(tanLocalsSpec, sizeof(tanLocalsSpec) / sizeof(DanaType), &tanLocalsDef);
populateOffsets(acosLocalsSpec, sizeof(acosLocalsSpec) / sizeof(DanaType), &acosLocalsDef);
populateOffsets(asinLocalsSpec, sizeof(asinLocalsSpec) / sizeof(DanaType), &asinLocalsDef);
populateOffsets(atanLocalsSpec, sizeof(atanLocalsSpec) / sizeof(DanaType), &atanLocalsDef);
populateOffsets(coshLocalsSpec, sizeof(coshLocalsSpec) / sizeof(DanaType), &coshLocalsDef);
populateOffsets(sinhLocalsSpec, sizeof(sinhLocalsSpec) / sizeof(DanaType), &sinhLocalsDef);
populateOffsets(tanhLocalsSpec, sizeof(tanhLocalsSpec) / sizeof(DanaType), &tanhLocalsDef);
populateOffsets(acoshLocalsSpec, sizeof(acoshLocalsSpec) / sizeof(DanaType), &acoshLocalsDef);
populateOffsets(asinhLocalsSpec, sizeof(asinhLocalsSpec) / sizeof(DanaType), &asinhLocalsDef);
populateOffsets(atanhLocalsSpec, sizeof(atanhLocalsSpec) / sizeof(DanaType), &atanhLocalsDef);
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
((VFrameHeader*) op_sqrt_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + sqrtLocalsDef.size;
((VFrameHeader*) op_sqrt_thread_spec) -> formalParamsCount = (sqrtLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_sqrt_thread_spec) -> localsDef = (size_t) &sqrtLocalsDef;
((VFrameHeader*) op_sqrt_thread_spec) -> functionName = "sqrt";
((VFrameHeader*) op_pow_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + powLocalsDef.size;
((VFrameHeader*) op_pow_thread_spec) -> formalParamsCount = (powLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_pow_thread_spec) -> localsDef = (size_t) &powLocalsDef;
((VFrameHeader*) op_pow_thread_spec) -> functionName = "pow";
((VFrameHeader*) op_root_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + rootLocalsDef.size;
((VFrameHeader*) op_root_thread_spec) -> formalParamsCount = (rootLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_root_thread_spec) -> localsDef = (size_t) &rootLocalsDef;
((VFrameHeader*) op_root_thread_spec) -> functionName = "root";
((VFrameHeader*) op_log_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + logLocalsDef.size;
((VFrameHeader*) op_log_thread_spec) -> formalParamsCount = (logLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_log_thread_spec) -> localsDef = (size_t) &logLocalsDef;
((VFrameHeader*) op_log_thread_spec) -> functionName = "log";
((VFrameHeader*) op_natlog_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + natlogLocalsDef.size;
((VFrameHeader*) op_natlog_thread_spec) -> formalParamsCount = (natlogLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_natlog_thread_spec) -> localsDef = (size_t) &natlogLocalsDef;
((VFrameHeader*) op_natlog_thread_spec) -> functionName = "natlog";
((VFrameHeader*) op_natexp_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + natexpLocalsDef.size;
((VFrameHeader*) op_natexp_thread_spec) -> formalParamsCount = (natexpLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_natexp_thread_spec) -> localsDef = (size_t) &natexpLocalsDef;
((VFrameHeader*) op_natexp_thread_spec) -> functionName = "natexp";
((VFrameHeader*) op_cos_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + cosLocalsDef.size;
((VFrameHeader*) op_cos_thread_spec) -> formalParamsCount = (cosLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_cos_thread_spec) -> localsDef = (size_t) &cosLocalsDef;
((VFrameHeader*) op_cos_thread_spec) -> functionName = "cos";
((VFrameHeader*) op_sin_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + sinLocalsDef.size;
((VFrameHeader*) op_sin_thread_spec) -> formalParamsCount = (sinLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_sin_thread_spec) -> localsDef = (size_t) &sinLocalsDef;
((VFrameHeader*) op_sin_thread_spec) -> functionName = "sin";
((VFrameHeader*) op_tan_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + tanLocalsDef.size;
((VFrameHeader*) op_tan_thread_spec) -> formalParamsCount = (tanLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_tan_thread_spec) -> localsDef = (size_t) &tanLocalsDef;
((VFrameHeader*) op_tan_thread_spec) -> functionName = "tan";
((VFrameHeader*) op_acos_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + acosLocalsDef.size;
((VFrameHeader*) op_acos_thread_spec) -> formalParamsCount = (acosLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_acos_thread_spec) -> localsDef = (size_t) &acosLocalsDef;
((VFrameHeader*) op_acos_thread_spec) -> functionName = "acos";
((VFrameHeader*) op_asin_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + asinLocalsDef.size;
((VFrameHeader*) op_asin_thread_spec) -> formalParamsCount = (asinLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_asin_thread_spec) -> localsDef = (size_t) &asinLocalsDef;
((VFrameHeader*) op_asin_thread_spec) -> functionName = "asin";
((VFrameHeader*) op_atan_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + atanLocalsDef.size;
((VFrameHeader*) op_atan_thread_spec) -> formalParamsCount = (atanLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_atan_thread_spec) -> localsDef = (size_t) &atanLocalsDef;
((VFrameHeader*) op_atan_thread_spec) -> functionName = "atan";
((VFrameHeader*) op_cosh_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + coshLocalsDef.size;
((VFrameHeader*) op_cosh_thread_spec) -> formalParamsCount = (coshLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_cosh_thread_spec) -> localsDef = (size_t) &coshLocalsDef;
((VFrameHeader*) op_cosh_thread_spec) -> functionName = "cosh";
((VFrameHeader*) op_sinh_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + sinhLocalsDef.size;
((VFrameHeader*) op_sinh_thread_spec) -> formalParamsCount = (sinhLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_sinh_thread_spec) -> localsDef = (size_t) &sinhLocalsDef;
((VFrameHeader*) op_sinh_thread_spec) -> functionName = "sinh";
((VFrameHeader*) op_tanh_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + tanhLocalsDef.size;
((VFrameHeader*) op_tanh_thread_spec) -> formalParamsCount = (tanhLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_tanh_thread_spec) -> localsDef = (size_t) &tanhLocalsDef;
((VFrameHeader*) op_tanh_thread_spec) -> functionName = "tanh";
((VFrameHeader*) op_acosh_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + acoshLocalsDef.size;
((VFrameHeader*) op_acosh_thread_spec) -> formalParamsCount = (acoshLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_acosh_thread_spec) -> localsDef = (size_t) &acoshLocalsDef;
((VFrameHeader*) op_acosh_thread_spec) -> functionName = "acosh";
((VFrameHeader*) op_asinh_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + asinhLocalsDef.size;
((VFrameHeader*) op_asinh_thread_spec) -> formalParamsCount = (asinhLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_asinh_thread_spec) -> localsDef = (size_t) &asinhLocalsDef;
((VFrameHeader*) op_asinh_thread_spec) -> functionName = "asinh";
((VFrameHeader*) op_atanh_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(VVarR) + atanhLocalsDef.size;
((VFrameHeader*) op_atanh_thread_spec) -> formalParamsCount = (atanhLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((VFrameHeader*) op_atanh_thread_spec) -> localsDef = (size_t) &atanhLocalsDef;
((VFrameHeader*) op_atanh_thread_spec) -> functionName = "atanh";
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
{"sqrt", (VFrameHeader*) op_sqrt_thread_spec},
{"pow", (VFrameHeader*) op_pow_thread_spec},
{"root", (VFrameHeader*) op_root_thread_spec},
{"log", (VFrameHeader*) op_log_thread_spec},
{"natlog", (VFrameHeader*) op_natlog_thread_spec},
{"natexp", (VFrameHeader*) op_natexp_thread_spec},
{"cos", (VFrameHeader*) op_cos_thread_spec},
{"sin", (VFrameHeader*) op_sin_thread_spec},
{"tan", (VFrameHeader*) op_tan_thread_spec},
{"acos", (VFrameHeader*) op_acos_thread_spec},
{"asin", (VFrameHeader*) op_asin_thread_spec},
{"atan", (VFrameHeader*) op_atan_thread_spec},
{"cosh", (VFrameHeader*) op_cosh_thread_spec},
{"sinh", (VFrameHeader*) op_sinh_thread_spec},
{"tanh", (VFrameHeader*) op_tanh_thread_spec},
{"acosh", (VFrameHeader*) op_acosh_thread_spec},
{"asinh", (VFrameHeader*) op_asinh_thread_spec},
{"atanh", (VFrameHeader*) op_atanh_thread_spec}};
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

