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
static const DanaType data_WindowEventData_spec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType data_WindowEventData_def = {{NULL, NULL, 0, 0}, {(unsigned char*) data_WindowEventData_spec, NULL, 0, sizeof(data_WindowEventData_spec)}, 0};
static const DanaType data_WindowEventData_map_def = 
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_WindowEventData_def}};
static const DanaType data_WH_spec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType data_WH_def = {{NULL, NULL, 0, 0}, {(unsigned char*) data_WH_spec, NULL, 0, sizeof(data_WH_spec)}, 0};
static const DanaType data_WH_map_def = 
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_WH_def}};
static const DanaType record_Pixel_spec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static const StructuredType record_Pixel_def = {{NULL, NULL, 0, 0}, {(unsigned char*) record_Pixel_spec, NULL, 0, sizeof(record_Pixel_spec)}, 0};
static const DanaType data_Pixel_map_def = 
{TYPE_PATTERN, X_FLAT, 0, 4, 4, 0, {(unsigned char*) &record_Pixel_def}};
static const DanaType array_Pixel_spec[] = {
{TYPE_PATTERN, X_FLAT, 0, 4, 4, 0, {(unsigned char*) &record_Pixel_def}}};
static const StructuredType array_Pixel_def = {{NULL, NULL, 0, 0}, {(unsigned char*) array_Pixel_spec, NULL, 0, sizeof(array_Pixel_spec)}, sizeof(VVarLivePTR)};
static const DanaType data_Pixel_array_map_def = 
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_Pixel_def}};
static const DanaType data_Bitmap_spec[] = {
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_WH_def}},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_Pixel_def}}};
static const StructuredType data_Bitmap_def = {{NULL, NULL, 0, 0}, {(unsigned char*) data_Bitmap_spec, NULL, 0, sizeof(data_Bitmap_spec)}, 0};
static const DanaType data_Bitmap_map_def = 
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_Bitmap_def}};
static const DanaType data_Rect_spec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType data_Rect_def = {{NULL, NULL, 0, 0}, {(unsigned char*) data_Rect_spec, NULL, 0, sizeof(data_Rect_spec)}, 0};
static const DanaType data_Rect_map_def = 
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_Rect_def}};
static const DanaType data_FontMetrics_spec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType data_FontMetrics_def = {{NULL, NULL, 0, 0}, {(unsigned char*) data_FontMetrics_spec, NULL, 0, sizeof(data_FontMetrics_spec)}, 0};
static const DanaType data_FontMetrics_map_def = 
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_FontMetrics_def}};
static const DanaType data_VC_spec[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType data_VC_def = {{NULL, NULL, 0, 0}, {(unsigned char*) data_VC_spec, NULL, 0, sizeof(data_VC_spec)}, 0};
static const DanaType data_VC_map_def = 
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_VC_def}};
static const DanaType function_UIPlaneLib_clone_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 1, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const StructuredType function_UIPlaneLib_clone_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_clone_def, NULL, 0, sizeof(function_UIPlaneLib_clone_def)}, 0};
static const DanaType function_UIPlaneLib_equals_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_OBJECT, X_POINTER, 1, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &object_Object_def}}};
static const StructuredType function_UIPlaneLib_equals_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_equals_def, NULL, 0, sizeof(function_UIPlaneLib_equals_def)}, 0};
static const DanaType function_UIPlaneLib_toString_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_UIPlaneLib_toString_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_toString_def, NULL, 0, sizeof(function_UIPlaneLib_toString_def)}, 0};
static const DanaType function_UIPlaneLib_getID_def[] = {
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_UIPlaneLib_getID_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_getID_def, NULL, 0, sizeof(function_UIPlaneLib_getID_def)}, 0};
static const DanaType function_UIPlaneLib_makeWindow_def[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_UIPlaneLib_makeWindow_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_makeWindow_def, NULL, 0, sizeof(function_UIPlaneLib_makeWindow_def)}, 0};
static const DanaType function_UIPlaneLib_selectEvent_def[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_WindowEventData_def}}};
static const StructuredType function_UIPlaneLib_selectEvent_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_selectEvent_def, NULL, 0, sizeof(function_UIPlaneLib_selectEvent_def)}, 0};
static const DanaType function_UIPlaneLib_startPoly_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0}};
static const StructuredType function_UIPlaneLib_startPoly_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_startPoly_def, NULL, 0, sizeof(function_UIPlaneLib_startPoly_def)}, 0};
static const DanaType function_UIPlaneLib_addPolyPoint_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static const StructuredType function_UIPlaneLib_addPolyPoint_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_addPolyPoint_def, NULL, 0, sizeof(function_UIPlaneLib_addPolyPoint_def)}, 0};
static const DanaType function_UIPlaneLib_endPoly_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0}};
static const StructuredType function_UIPlaneLib_endPoly_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_endPoly_def, NULL, 0, sizeof(function_UIPlaneLib_endPoly_def)}, 0};
static const DanaType function_UIPlaneLib_addRect_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static const StructuredType function_UIPlaneLib_addRect_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_addRect_def, NULL, 0, sizeof(function_UIPlaneLib_addRect_def)}, 0};
static const DanaType function_UIPlaneLib_addLine_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static const StructuredType function_UIPlaneLib_addLine_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_addLine_def, NULL, 0, sizeof(function_UIPlaneLib_addLine_def)}, 0};
static const DanaType function_UIPlaneLib_addPoint_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static const StructuredType function_UIPlaneLib_addPoint_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_addPoint_def, NULL, 0, sizeof(function_UIPlaneLib_addPoint_def)}, 0};
static const DanaType function_UIPlaneLib_addBitmap_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_Bitmap_def}},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_UIPlaneLib_addBitmap_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_addBitmap_def, NULL, 0, sizeof(function_UIPlaneLib_addBitmap_def)}, 0};
static const DanaType function_UIPlaneLib_addText_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static const StructuredType function_UIPlaneLib_addText_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_addText_def, NULL, 0, sizeof(function_UIPlaneLib_addText_def)}, 0};
static const DanaType function_UIPlaneLib_addTextWith_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static const StructuredType function_UIPlaneLib_addTextWith_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_addTextWith_def, NULL, 0, sizeof(function_UIPlaneLib_addTextWith_def)}, 0};
static const DanaType function_UIPlaneLib_pushSurface_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_UIPlaneLib_pushSurface_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_pushSurface_def, NULL, 0, sizeof(function_UIPlaneLib_pushSurface_def)}, 0};
static const DanaType function_UIPlaneLib_popSurface_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_UIPlaneLib_popSurface_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_popSurface_def, NULL, 0, sizeof(function_UIPlaneLib_popSurface_def)}, 0};
static const DanaType function_UIPlaneLib_setSize_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_UIPlaneLib_setSize_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_setSize_def, NULL, 0, sizeof(function_UIPlaneLib_setSize_def)}, 0};
static const DanaType function_UIPlaneLib_setPosition_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_UIPlaneLib_setPosition_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_setPosition_def, NULL, 0, sizeof(function_UIPlaneLib_setPosition_def)}, 0};
static const DanaType function_UIPlaneLib_setVisible_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static const StructuredType function_UIPlaneLib_setVisible_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_setVisible_def, NULL, 0, sizeof(function_UIPlaneLib_setVisible_def)}, 0};
static const DanaType function_UIPlaneLib_setTitle_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_UIPlaneLib_setTitle_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_setTitle_def, NULL, 0, sizeof(function_UIPlaneLib_setTitle_def)}, 0};
static const DanaType function_UIPlaneLib_commitBuffer_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_UIPlaneLib_commitBuffer_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_commitBuffer_def, NULL, 0, sizeof(function_UIPlaneLib_commitBuffer_def)}, 0};
static const DanaType function_UIPlaneLib_registerClickListener_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_UIPlaneLib_registerClickListener_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_registerClickListener_def, NULL, 0, sizeof(function_UIPlaneLib_registerClickListener_def)}, 0};
static const DanaType function_UIPlaneLib_registerMouseListener_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_UIPlaneLib_registerMouseListener_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_registerMouseListener_def, NULL, 0, sizeof(function_UIPlaneLib_registerMouseListener_def)}, 0};
static const DanaType function_UIPlaneLib_setBackgroundColor_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static const StructuredType function_UIPlaneLib_setBackgroundColor_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_setBackgroundColor_def, NULL, 0, sizeof(function_UIPlaneLib_setBackgroundColor_def)}, 0};
static const DanaType function_UIPlaneLib_maximiseWindow_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_UIPlaneLib_maximiseWindow_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_maximiseWindow_def, NULL, 0, sizeof(function_UIPlaneLib_maximiseWindow_def)}, 0};
static const DanaType function_UIPlaneLib_minimiseWindow_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_UIPlaneLib_minimiseWindow_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_minimiseWindow_def, NULL, 0, sizeof(function_UIPlaneLib_minimiseWindow_def)}, 0};
static const DanaType function_UIPlaneLib_getMaximisedScreenRect_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_Rect_def}}};
static const StructuredType function_UIPlaneLib_getMaximisedScreenRect_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_getMaximisedScreenRect_def, NULL, 0, sizeof(function_UIPlaneLib_getMaximisedScreenRect_def)}, 0};
static const DanaType function_UIPlaneLib_closeWindow_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_UIPlaneLib_closeWindow_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_closeWindow_def, NULL, 0, sizeof(function_UIPlaneLib_closeWindow_def)}, 0};
static const DanaType function_UIPlaneLib_loadFont_def[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_UIPlaneLib_loadFont_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_loadFont_def, NULL, 0, sizeof(function_UIPlaneLib_loadFont_def)}, 0};
static const DanaType function_UIPlaneLib_getTextWidth_def[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static const StructuredType function_UIPlaneLib_getTextWidth_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_getTextWidth_def, NULL, 0, sizeof(function_UIPlaneLib_getTextWidth_def)}, 0};
static const DanaType function_UIPlaneLib_getFontMetrics_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_FontMetrics_def}}};
static const StructuredType function_UIPlaneLib_getFontMetrics_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_getFontMetrics_def, NULL, 0, sizeof(function_UIPlaneLib_getFontMetrics_def)}, 0};
static const DanaType function_UIPlaneLib_getFontName_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_VC_def}}};
static const StructuredType function_UIPlaneLib_getFontName_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_getFontName_def, NULL, 0, sizeof(function_UIPlaneLib_getFontName_def)}, 0};
static const DanaType function_UIPlaneLib_isFontFixedWidth_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_UIPlaneLib_isFontFixedWidth_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_isFontFixedWidth_def, NULL, 0, sizeof(function_UIPlaneLib_isFontFixedWidth_def)}, 0};
static const DanaType function_UIPlaneLib_getTextBitmapWith_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_Bitmap_def}},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static const StructuredType function_UIPlaneLib_getTextBitmapWith_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_getTextBitmapWith_def, NULL, 0, sizeof(function_UIPlaneLib_getTextBitmapWith_def)}, 0};
static const DanaType function_UIPlaneLib_unloadFont_def[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static const StructuredType function_UIPlaneLib_unloadFont_spec = {{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_unloadFont_def, NULL, 0, sizeof(function_UIPlaneLib_unloadFont_def)}, 0};
static const StructuredFunctionType intf_fnc[] = {
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_clone_def, NULL, 0, sizeof(function_UIPlaneLib_clone_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_equals_def, NULL, 0, sizeof(function_UIPlaneLib_equals_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_toString_def, NULL, 0, sizeof(function_UIPlaneLib_toString_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_getID_def, NULL, 0, sizeof(function_UIPlaneLib_getID_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_makeWindow_def, NULL, 0, sizeof(function_UIPlaneLib_makeWindow_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_selectEvent_def, NULL, 0, sizeof(function_UIPlaneLib_selectEvent_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_startPoly_def, NULL, 0, sizeof(function_UIPlaneLib_startPoly_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_addPolyPoint_def, NULL, 0, sizeof(function_UIPlaneLib_addPolyPoint_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_endPoly_def, NULL, 0, sizeof(function_UIPlaneLib_endPoly_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_addRect_def, NULL, 0, sizeof(function_UIPlaneLib_addRect_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_addLine_def, NULL, 0, sizeof(function_UIPlaneLib_addLine_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_addPoint_def, NULL, 0, sizeof(function_UIPlaneLib_addPoint_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_addBitmap_def, NULL, 0, sizeof(function_UIPlaneLib_addBitmap_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_addText_def, NULL, 0, sizeof(function_UIPlaneLib_addText_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_addTextWith_def, NULL, 0, sizeof(function_UIPlaneLib_addTextWith_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_pushSurface_def, NULL, 0, sizeof(function_UIPlaneLib_pushSurface_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_popSurface_def, NULL, 0, sizeof(function_UIPlaneLib_popSurface_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_setSize_def, NULL, 0, sizeof(function_UIPlaneLib_setSize_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_setPosition_def, NULL, 0, sizeof(function_UIPlaneLib_setPosition_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_setVisible_def, NULL, 0, sizeof(function_UIPlaneLib_setVisible_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_setTitle_def, NULL, 0, sizeof(function_UIPlaneLib_setTitle_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_commitBuffer_def, NULL, 0, sizeof(function_UIPlaneLib_commitBuffer_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_registerClickListener_def, NULL, 0, sizeof(function_UIPlaneLib_registerClickListener_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_registerMouseListener_def, NULL, 0, sizeof(function_UIPlaneLib_registerMouseListener_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_setBackgroundColor_def, NULL, 0, sizeof(function_UIPlaneLib_setBackgroundColor_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_maximiseWindow_def, NULL, 0, sizeof(function_UIPlaneLib_maximiseWindow_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_minimiseWindow_def, NULL, 0, sizeof(function_UIPlaneLib_minimiseWindow_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_getMaximisedScreenRect_def, NULL, 0, sizeof(function_UIPlaneLib_getMaximisedScreenRect_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_closeWindow_def, NULL, 0, sizeof(function_UIPlaneLib_closeWindow_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_loadFont_def, NULL, 0, sizeof(function_UIPlaneLib_loadFont_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_getTextWidth_def, NULL, 0, sizeof(function_UIPlaneLib_getTextWidth_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_getFontMetrics_def, NULL, 0, sizeof(function_UIPlaneLib_getFontMetrics_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_getFontName_def, NULL, 0, sizeof(function_UIPlaneLib_getFontName_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_isFontFixedWidth_def, NULL, 0, sizeof(function_UIPlaneLib_isFontFixedWidth_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_getTextBitmapWith_def, NULL, 0, sizeof(function_UIPlaneLib_getTextBitmapWith_def)}, 0},
{{NULL, NULL, 0, 0}, {(unsigned char*) function_UIPlaneLib_unloadFont_def, NULL, 0, sizeof(function_UIPlaneLib_unloadFont_def)}, 0}};
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
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[21]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[22]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[23]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[24]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[25]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[26]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[27]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[28]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[29]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[30]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[31]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[32]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[33]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[34]}},
{TYPE_FUNCTION, X_FLAT, 0, 0, 0, 0, {(unsigned char*) &intf_fnc[35]}}};
static StructuredInterfaceType ILib = {{(unsigned char*) "UIPlaneLib", NULL, 0, 10}, {(unsigned char*) intf_def, NULL, 0, sizeof(intf_def)}, 0};
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
static DanaType makeWindowLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType makeWindowLocalsDef = {{}, {(unsigned char*) makeWindowLocalsSpec, NULL, 0, sizeof(makeWindowLocalsSpec)}, 0};
static DanaType selectEventLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_WindowEventData_def}}};
static StructuredType selectEventLocalsDef = {{}, {(unsigned char*) selectEventLocalsSpec, NULL, 0, sizeof(selectEventLocalsSpec)}, 0};
static DanaType startPolyLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0}};
static StructuredType startPolyLocalsDef = {{}, {(unsigned char*) startPolyLocalsSpec, NULL, 0, sizeof(startPolyLocalsSpec)}, 0};
static DanaType addPolyPointLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static StructuredType addPolyPointLocalsDef = {{}, {(unsigned char*) addPolyPointLocalsSpec, NULL, 0, sizeof(addPolyPointLocalsSpec)}, 0};
static DanaType endPolyLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0}};
static StructuredType endPolyLocalsDef = {{}, {(unsigned char*) endPolyLocalsSpec, NULL, 0, sizeof(endPolyLocalsSpec)}, 0};
static DanaType addRectLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static StructuredType addRectLocalsDef = {{}, {(unsigned char*) addRectLocalsSpec, NULL, 0, sizeof(addRectLocalsSpec)}, 0};
static DanaType addLineLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static StructuredType addLineLocalsDef = {{}, {(unsigned char*) addLineLocalsSpec, NULL, 0, sizeof(addLineLocalsSpec)}, 0};
static DanaType addPointLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static StructuredType addPointLocalsDef = {{}, {(unsigned char*) addPointLocalsSpec, NULL, 0, sizeof(addPointLocalsSpec)}, 0};
static DanaType addBitmapLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_Bitmap_def}},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType addBitmapLocalsDef = {{}, {(unsigned char*) addBitmapLocalsSpec, NULL, 0, sizeof(addBitmapLocalsSpec)}, 0};
static DanaType addTextLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static StructuredType addTextLocalsDef = {{}, {(unsigned char*) addTextLocalsSpec, NULL, 0, sizeof(addTextLocalsSpec)}, 0};
static DanaType addTextWithLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static StructuredType addTextWithLocalsDef = {{}, {(unsigned char*) addTextWithLocalsSpec, NULL, 0, sizeof(addTextWithLocalsSpec)}, 0};
static DanaType pushSurfaceLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType pushSurfaceLocalsDef = {{}, {(unsigned char*) pushSurfaceLocalsSpec, NULL, 0, sizeof(pushSurfaceLocalsSpec)}, 0};
static DanaType popSurfaceLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType popSurfaceLocalsDef = {{}, {(unsigned char*) popSurfaceLocalsSpec, NULL, 0, sizeof(popSurfaceLocalsSpec)}, 0};
static DanaType setSizeLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType setSizeLocalsDef = {{}, {(unsigned char*) setSizeLocalsSpec, NULL, 0, sizeof(setSizeLocalsSpec)}, 0};
static DanaType setPositionLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType setPositionLocalsDef = {{}, {(unsigned char*) setPositionLocalsSpec, NULL, 0, sizeof(setPositionLocalsSpec)}, 0};
static DanaType setVisibleLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static StructuredType setVisibleLocalsDef = {{}, {(unsigned char*) setVisibleLocalsSpec, NULL, 0, sizeof(setVisibleLocalsSpec)}, 0};
static DanaType setTitleLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType setTitleLocalsDef = {{}, {(unsigned char*) setTitleLocalsSpec, NULL, 0, sizeof(setTitleLocalsSpec)}, 0};
static DanaType commitBufferLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType commitBufferLocalsDef = {{}, {(unsigned char*) commitBufferLocalsSpec, NULL, 0, sizeof(commitBufferLocalsSpec)}, 0};
static DanaType registerClickListenerLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType registerClickListenerLocalsDef = {{}, {(unsigned char*) registerClickListenerLocalsSpec, NULL, 0, sizeof(registerClickListenerLocalsSpec)}, 0};
static DanaType registerMouseListenerLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType registerMouseListenerLocalsDef = {{}, {(unsigned char*) registerMouseListenerLocalsSpec, NULL, 0, sizeof(registerMouseListenerLocalsSpec)}, 0};
static DanaType setBackgroundColorLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static StructuredType setBackgroundColorLocalsDef = {{}, {(unsigned char*) setBackgroundColorLocalsSpec, NULL, 0, sizeof(setBackgroundColorLocalsSpec)}, 0};
static DanaType maximiseWindowLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType maximiseWindowLocalsDef = {{}, {(unsigned char*) maximiseWindowLocalsSpec, NULL, 0, sizeof(maximiseWindowLocalsSpec)}, 0};
static DanaType minimiseWindowLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType minimiseWindowLocalsDef = {{}, {(unsigned char*) minimiseWindowLocalsSpec, NULL, 0, sizeof(minimiseWindowLocalsSpec)}, 0};
static DanaType getMaximisedScreenRectLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_Rect_def}}};
static StructuredType getMaximisedScreenRectLocalsDef = {{}, {(unsigned char*) getMaximisedScreenRectLocalsSpec, NULL, 0, sizeof(getMaximisedScreenRectLocalsSpec)}, 0};
static DanaType closeWindowLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType closeWindowLocalsDef = {{}, {(unsigned char*) closeWindowLocalsSpec, NULL, 0, sizeof(closeWindowLocalsSpec)}, 0};
static DanaType loadFontLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType loadFontLocalsDef = {{}, {(unsigned char*) loadFontLocalsSpec, NULL, 0, sizeof(loadFontLocalsSpec)}, 0};
static DanaType getTextWidthLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}}};
static StructuredType getTextWidthLocalsDef = {{}, {(unsigned char*) getTextWidthLocalsSpec, NULL, 0, sizeof(getTextWidthLocalsSpec)}, 0};
static DanaType getFontMetricsLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_FontMetrics_def}}};
static StructuredType getFontMetricsLocalsDef = {{}, {(unsigned char*) getFontMetricsLocalsSpec, NULL, 0, sizeof(getFontMetricsLocalsSpec)}, 0};
static DanaType getFontNameLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_VC_def}}};
static StructuredType getFontNameLocalsDef = {{}, {(unsigned char*) getFontNameLocalsSpec, NULL, 0, sizeof(getFontNameLocalsSpec)}, 0};
static DanaType isFontFixedWidthLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType isFontFixedWidthLocalsDef = {{}, {(unsigned char*) isFontFixedWidthLocalsSpec, NULL, 0, sizeof(isFontFixedWidthLocalsSpec)}, 0};
static DanaType getTextBitmapWithLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0},
{TYPE_ARRAY, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &array_char_def}},
{TYPE_DATA, X_POINTER, 0, sizeof(VVarLivePTR), sizeof(VVarLivePTR), 0, {(unsigned char*) &data_Bitmap_def}},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0},
{TYPE_LITERAL, X_FLAT, 0, 1, 1, 0}};
static StructuredType getTextBitmapWithLocalsDef = {{}, {(unsigned char*) getTextBitmapWithLocalsSpec, NULL, 0, sizeof(getTextBitmapWithLocalsSpec)}, 0};
static DanaType unloadFontLocalsSpec[] = {
{TYPE_LITERAL, X_FLAT, 0, 0, 0, 0},
{TYPE_LITERAL, X_FLAT, 0, sizeof(size_t), sizeof(size_t), 0}};
static StructuredType unloadFontLocalsDef = {{}, {(unsigned char*) unloadFontLocalsSpec, NULL, 0, sizeof(unloadFontLocalsSpec)}, 0};
static unsigned char op_clone_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_equals_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_toString_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getID_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_makeWindow_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_selectEvent_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_startPoly_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_addPolyPoint_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_endPoly_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_addRect_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_addLine_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_addPoint_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_addBitmap_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_addText_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_addTextWith_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_pushSurface_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_popSurface_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_setSize_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_setPosition_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_setVisible_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_setTitle_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_commitBuffer_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_registerClickListener_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_registerMouseListener_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_setBackgroundColor_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_maximiseWindow_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_minimiseWindow_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getMaximisedScreenRect_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_closeWindow_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_loadFont_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getTextWidth_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getFontMetrics_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getFontName_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_isFontFixedWidth_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_getTextBitmapWith_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static unsigned char op_unloadFont_thread_spec[sizeof(VFrameHeader)+sizeof(VFrame)];
static SourceHeader header;
static Component self;
static size_t interfaceFunctions[] = {
(size_t) op_clone_thread_spec,
(size_t) op_equals_thread_spec,
(size_t) op_toString_thread_spec,
(size_t) op_getID_thread_spec,
(size_t) op_makeWindow_thread_spec,
(size_t) op_selectEvent_thread_spec,
(size_t) op_startPoly_thread_spec,
(size_t) op_addPolyPoint_thread_spec,
(size_t) op_endPoly_thread_spec,
(size_t) op_addRect_thread_spec,
(size_t) op_addLine_thread_spec,
(size_t) op_addPoint_thread_spec,
(size_t) op_addBitmap_thread_spec,
(size_t) op_addText_thread_spec,
(size_t) op_addTextWith_thread_spec,
(size_t) op_pushSurface_thread_spec,
(size_t) op_popSurface_thread_spec,
(size_t) op_setSize_thread_spec,
(size_t) op_setPosition_thread_spec,
(size_t) op_setVisible_thread_spec,
(size_t) op_setTitle_thread_spec,
(size_t) op_commitBuffer_thread_spec,
(size_t) op_registerClickListener_thread_spec,
(size_t) op_registerMouseListener_thread_spec,
(size_t) op_setBackgroundColor_thread_spec,
(size_t) op_maximiseWindow_thread_spec,
(size_t) op_minimiseWindow_thread_spec,
(size_t) op_getMaximisedScreenRect_thread_spec,
(size_t) op_closeWindow_thread_spec,
(size_t) op_loadFont_thread_spec,
(size_t) op_getTextWidth_thread_spec,
(size_t) op_getFontMetrics_thread_spec,
(size_t) op_getFontName_thread_spec,
(size_t) op_isFontFixedWidth_thread_spec,
(size_t) op_getTextBitmapWith_thread_spec,
(size_t) op_unloadFont_thread_spec};
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
populateOffsets(makeWindowLocalsSpec, sizeof(makeWindowLocalsSpec) / sizeof(DanaType), &makeWindowLocalsDef);
populateOffsets(selectEventLocalsSpec, sizeof(selectEventLocalsSpec) / sizeof(DanaType), &selectEventLocalsDef);
populateOffsets(startPolyLocalsSpec, sizeof(startPolyLocalsSpec) / sizeof(DanaType), &startPolyLocalsDef);
populateOffsets(addPolyPointLocalsSpec, sizeof(addPolyPointLocalsSpec) / sizeof(DanaType), &addPolyPointLocalsDef);
populateOffsets(endPolyLocalsSpec, sizeof(endPolyLocalsSpec) / sizeof(DanaType), &endPolyLocalsDef);
populateOffsets(addRectLocalsSpec, sizeof(addRectLocalsSpec) / sizeof(DanaType), &addRectLocalsDef);
populateOffsets(addLineLocalsSpec, sizeof(addLineLocalsSpec) / sizeof(DanaType), &addLineLocalsDef);
populateOffsets(addPointLocalsSpec, sizeof(addPointLocalsSpec) / sizeof(DanaType), &addPointLocalsDef);
populateOffsets(addBitmapLocalsSpec, sizeof(addBitmapLocalsSpec) / sizeof(DanaType), &addBitmapLocalsDef);
populateOffsets(addTextLocalsSpec, sizeof(addTextLocalsSpec) / sizeof(DanaType), &addTextLocalsDef);
populateOffsets(addTextWithLocalsSpec, sizeof(addTextWithLocalsSpec) / sizeof(DanaType), &addTextWithLocalsDef);
populateOffsets(pushSurfaceLocalsSpec, sizeof(pushSurfaceLocalsSpec) / sizeof(DanaType), &pushSurfaceLocalsDef);
populateOffsets(popSurfaceLocalsSpec, sizeof(popSurfaceLocalsSpec) / sizeof(DanaType), &popSurfaceLocalsDef);
populateOffsets(setSizeLocalsSpec, sizeof(setSizeLocalsSpec) / sizeof(DanaType), &setSizeLocalsDef);
populateOffsets(setPositionLocalsSpec, sizeof(setPositionLocalsSpec) / sizeof(DanaType), &setPositionLocalsDef);
populateOffsets(setVisibleLocalsSpec, sizeof(setVisibleLocalsSpec) / sizeof(DanaType), &setVisibleLocalsDef);
populateOffsets(setTitleLocalsSpec, sizeof(setTitleLocalsSpec) / sizeof(DanaType), &setTitleLocalsDef);
populateOffsets(commitBufferLocalsSpec, sizeof(commitBufferLocalsSpec) / sizeof(DanaType), &commitBufferLocalsDef);
populateOffsets(registerClickListenerLocalsSpec, sizeof(registerClickListenerLocalsSpec) / sizeof(DanaType), &registerClickListenerLocalsDef);
populateOffsets(registerMouseListenerLocalsSpec, sizeof(registerMouseListenerLocalsSpec) / sizeof(DanaType), &registerMouseListenerLocalsDef);
populateOffsets(setBackgroundColorLocalsSpec, sizeof(setBackgroundColorLocalsSpec) / sizeof(DanaType), &setBackgroundColorLocalsDef);
populateOffsets(maximiseWindowLocalsSpec, sizeof(maximiseWindowLocalsSpec) / sizeof(DanaType), &maximiseWindowLocalsDef);
populateOffsets(minimiseWindowLocalsSpec, sizeof(minimiseWindowLocalsSpec) / sizeof(DanaType), &minimiseWindowLocalsDef);
populateOffsets(getMaximisedScreenRectLocalsSpec, sizeof(getMaximisedScreenRectLocalsSpec) / sizeof(DanaType), &getMaximisedScreenRectLocalsDef);
populateOffsets(closeWindowLocalsSpec, sizeof(closeWindowLocalsSpec) / sizeof(DanaType), &closeWindowLocalsDef);
populateOffsets(loadFontLocalsSpec, sizeof(loadFontLocalsSpec) / sizeof(DanaType), &loadFontLocalsDef);
populateOffsets(getTextWidthLocalsSpec, sizeof(getTextWidthLocalsSpec) / sizeof(DanaType), &getTextWidthLocalsDef);
populateOffsets(getFontMetricsLocalsSpec, sizeof(getFontMetricsLocalsSpec) / sizeof(DanaType), &getFontMetricsLocalsDef);
populateOffsets(getFontNameLocalsSpec, sizeof(getFontNameLocalsSpec) / sizeof(DanaType), &getFontNameLocalsDef);
populateOffsets(isFontFixedWidthLocalsSpec, sizeof(isFontFixedWidthLocalsSpec) / sizeof(DanaType), &isFontFixedWidthLocalsDef);
populateOffsets(getTextBitmapWithLocalsSpec, sizeof(getTextBitmapWithLocalsSpec) / sizeof(DanaType), &getTextBitmapWithLocalsDef);
populateOffsets(unloadFontLocalsSpec, sizeof(unloadFontLocalsSpec) / sizeof(DanaType), &unloadFontLocalsDef);
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
((VFrameHeader*) op_makeWindow_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + makeWindowLocalsDef.size;
((VFrameHeader*) op_makeWindow_thread_spec) -> formalParamsCount = (makeWindowLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_makeWindow_thread_spec)[1])[0] = (size_t) &makeWindowLocalsDef;
((VFrameHeader*) op_makeWindow_thread_spec) -> functionName = "makeWindow";
((VFrameHeader*) op_selectEvent_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + selectEventLocalsDef.size;
((VFrameHeader*) op_selectEvent_thread_spec) -> formalParamsCount = (selectEventLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_selectEvent_thread_spec)[1])[0] = (size_t) &selectEventLocalsDef;
((VFrameHeader*) op_selectEvent_thread_spec) -> functionName = "selectEvent";
((VFrameHeader*) op_startPoly_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + startPolyLocalsDef.size;
((VFrameHeader*) op_startPoly_thread_spec) -> formalParamsCount = (startPolyLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_startPoly_thread_spec)[1])[0] = (size_t) &startPolyLocalsDef;
((VFrameHeader*) op_startPoly_thread_spec) -> functionName = "startPoly";
((VFrameHeader*) op_addPolyPoint_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + addPolyPointLocalsDef.size;
((VFrameHeader*) op_addPolyPoint_thread_spec) -> formalParamsCount = (addPolyPointLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_addPolyPoint_thread_spec)[1])[0] = (size_t) &addPolyPointLocalsDef;
((VFrameHeader*) op_addPolyPoint_thread_spec) -> functionName = "addPolyPoint";
((VFrameHeader*) op_endPoly_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + endPolyLocalsDef.size;
((VFrameHeader*) op_endPoly_thread_spec) -> formalParamsCount = (endPolyLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_endPoly_thread_spec)[1])[0] = (size_t) &endPolyLocalsDef;
((VFrameHeader*) op_endPoly_thread_spec) -> functionName = "endPoly";
((VFrameHeader*) op_addRect_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + addRectLocalsDef.size;
((VFrameHeader*) op_addRect_thread_spec) -> formalParamsCount = (addRectLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_addRect_thread_spec)[1])[0] = (size_t) &addRectLocalsDef;
((VFrameHeader*) op_addRect_thread_spec) -> functionName = "addRect";
((VFrameHeader*) op_addLine_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + addLineLocalsDef.size;
((VFrameHeader*) op_addLine_thread_spec) -> formalParamsCount = (addLineLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_addLine_thread_spec)[1])[0] = (size_t) &addLineLocalsDef;
((VFrameHeader*) op_addLine_thread_spec) -> functionName = "addLine";
((VFrameHeader*) op_addPoint_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + addPointLocalsDef.size;
((VFrameHeader*) op_addPoint_thread_spec) -> formalParamsCount = (addPointLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_addPoint_thread_spec)[1])[0] = (size_t) &addPointLocalsDef;
((VFrameHeader*) op_addPoint_thread_spec) -> functionName = "addPoint";
((VFrameHeader*) op_addBitmap_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + addBitmapLocalsDef.size;
((VFrameHeader*) op_addBitmap_thread_spec) -> formalParamsCount = (addBitmapLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_addBitmap_thread_spec)[1])[0] = (size_t) &addBitmapLocalsDef;
((VFrameHeader*) op_addBitmap_thread_spec) -> functionName = "addBitmap";
((VFrameHeader*) op_addText_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + addTextLocalsDef.size;
((VFrameHeader*) op_addText_thread_spec) -> formalParamsCount = (addTextLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_addText_thread_spec)[1])[0] = (size_t) &addTextLocalsDef;
((VFrameHeader*) op_addText_thread_spec) -> functionName = "addText";
((VFrameHeader*) op_addTextWith_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + addTextWithLocalsDef.size;
((VFrameHeader*) op_addTextWith_thread_spec) -> formalParamsCount = (addTextWithLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_addTextWith_thread_spec)[1])[0] = (size_t) &addTextWithLocalsDef;
((VFrameHeader*) op_addTextWith_thread_spec) -> functionName = "addTextWith";
((VFrameHeader*) op_pushSurface_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + pushSurfaceLocalsDef.size;
((VFrameHeader*) op_pushSurface_thread_spec) -> formalParamsCount = (pushSurfaceLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_pushSurface_thread_spec)[1])[0] = (size_t) &pushSurfaceLocalsDef;
((VFrameHeader*) op_pushSurface_thread_spec) -> functionName = "pushSurface";
((VFrameHeader*) op_popSurface_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + popSurfaceLocalsDef.size;
((VFrameHeader*) op_popSurface_thread_spec) -> formalParamsCount = (popSurfaceLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_popSurface_thread_spec)[1])[0] = (size_t) &popSurfaceLocalsDef;
((VFrameHeader*) op_popSurface_thread_spec) -> functionName = "popSurface";
((VFrameHeader*) op_setSize_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + setSizeLocalsDef.size;
((VFrameHeader*) op_setSize_thread_spec) -> formalParamsCount = (setSizeLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_setSize_thread_spec)[1])[0] = (size_t) &setSizeLocalsDef;
((VFrameHeader*) op_setSize_thread_spec) -> functionName = "setSize";
((VFrameHeader*) op_setPosition_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + setPositionLocalsDef.size;
((VFrameHeader*) op_setPosition_thread_spec) -> formalParamsCount = (setPositionLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_setPosition_thread_spec)[1])[0] = (size_t) &setPositionLocalsDef;
((VFrameHeader*) op_setPosition_thread_spec) -> functionName = "setPosition";
((VFrameHeader*) op_setVisible_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + setVisibleLocalsDef.size;
((VFrameHeader*) op_setVisible_thread_spec) -> formalParamsCount = (setVisibleLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_setVisible_thread_spec)[1])[0] = (size_t) &setVisibleLocalsDef;
((VFrameHeader*) op_setVisible_thread_spec) -> functionName = "setVisible";
((VFrameHeader*) op_setTitle_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + setTitleLocalsDef.size;
((VFrameHeader*) op_setTitle_thread_spec) -> formalParamsCount = (setTitleLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_setTitle_thread_spec)[1])[0] = (size_t) &setTitleLocalsDef;
((VFrameHeader*) op_setTitle_thread_spec) -> functionName = "setTitle";
((VFrameHeader*) op_commitBuffer_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + commitBufferLocalsDef.size;
((VFrameHeader*) op_commitBuffer_thread_spec) -> formalParamsCount = (commitBufferLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_commitBuffer_thread_spec)[1])[0] = (size_t) &commitBufferLocalsDef;
((VFrameHeader*) op_commitBuffer_thread_spec) -> functionName = "commitBuffer";
((VFrameHeader*) op_registerClickListener_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + registerClickListenerLocalsDef.size;
((VFrameHeader*) op_registerClickListener_thread_spec) -> formalParamsCount = (registerClickListenerLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_registerClickListener_thread_spec)[1])[0] = (size_t) &registerClickListenerLocalsDef;
((VFrameHeader*) op_registerClickListener_thread_spec) -> functionName = "registerClickListener";
((VFrameHeader*) op_registerMouseListener_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + registerMouseListenerLocalsDef.size;
((VFrameHeader*) op_registerMouseListener_thread_spec) -> formalParamsCount = (registerMouseListenerLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_registerMouseListener_thread_spec)[1])[0] = (size_t) &registerMouseListenerLocalsDef;
((VFrameHeader*) op_registerMouseListener_thread_spec) -> functionName = "registerMouseListener";
((VFrameHeader*) op_setBackgroundColor_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + setBackgroundColorLocalsDef.size;
((VFrameHeader*) op_setBackgroundColor_thread_spec) -> formalParamsCount = (setBackgroundColorLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_setBackgroundColor_thread_spec)[1])[0] = (size_t) &setBackgroundColorLocalsDef;
((VFrameHeader*) op_setBackgroundColor_thread_spec) -> functionName = "setBackgroundColor";
((VFrameHeader*) op_maximiseWindow_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + maximiseWindowLocalsDef.size;
((VFrameHeader*) op_maximiseWindow_thread_spec) -> formalParamsCount = (maximiseWindowLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_maximiseWindow_thread_spec)[1])[0] = (size_t) &maximiseWindowLocalsDef;
((VFrameHeader*) op_maximiseWindow_thread_spec) -> functionName = "maximiseWindow";
((VFrameHeader*) op_minimiseWindow_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + minimiseWindowLocalsDef.size;
((VFrameHeader*) op_minimiseWindow_thread_spec) -> formalParamsCount = (minimiseWindowLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_minimiseWindow_thread_spec)[1])[0] = (size_t) &minimiseWindowLocalsDef;
((VFrameHeader*) op_minimiseWindow_thread_spec) -> functionName = "minimiseWindow";
((VFrameHeader*) op_getMaximisedScreenRect_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + getMaximisedScreenRectLocalsDef.size;
((VFrameHeader*) op_getMaximisedScreenRect_thread_spec) -> formalParamsCount = (getMaximisedScreenRectLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_getMaximisedScreenRect_thread_spec)[1])[0] = (size_t) &getMaximisedScreenRectLocalsDef;
((VFrameHeader*) op_getMaximisedScreenRect_thread_spec) -> functionName = "getMaximisedScreenRect";
((VFrameHeader*) op_closeWindow_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + closeWindowLocalsDef.size;
((VFrameHeader*) op_closeWindow_thread_spec) -> formalParamsCount = (closeWindowLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_closeWindow_thread_spec)[1])[0] = (size_t) &closeWindowLocalsDef;
((VFrameHeader*) op_closeWindow_thread_spec) -> functionName = "closeWindow";
((VFrameHeader*) op_loadFont_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + loadFontLocalsDef.size;
((VFrameHeader*) op_loadFont_thread_spec) -> formalParamsCount = (loadFontLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_loadFont_thread_spec)[1])[0] = (size_t) &loadFontLocalsDef;
((VFrameHeader*) op_loadFont_thread_spec) -> functionName = "loadFont";
((VFrameHeader*) op_getTextWidth_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + getTextWidthLocalsDef.size;
((VFrameHeader*) op_getTextWidth_thread_spec) -> formalParamsCount = (getTextWidthLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_getTextWidth_thread_spec)[1])[0] = (size_t) &getTextWidthLocalsDef;
((VFrameHeader*) op_getTextWidth_thread_spec) -> functionName = "getTextWidth";
((VFrameHeader*) op_getFontMetrics_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + getFontMetricsLocalsDef.size;
((VFrameHeader*) op_getFontMetrics_thread_spec) -> formalParamsCount = (getFontMetricsLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_getFontMetrics_thread_spec)[1])[0] = (size_t) &getFontMetricsLocalsDef;
((VFrameHeader*) op_getFontMetrics_thread_spec) -> functionName = "getFontMetrics";
((VFrameHeader*) op_getFontName_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + getFontNameLocalsDef.size;
((VFrameHeader*) op_getFontName_thread_spec) -> formalParamsCount = (getFontNameLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_getFontName_thread_spec)[1])[0] = (size_t) &getFontNameLocalsDef;
((VFrameHeader*) op_getFontName_thread_spec) -> functionName = "getFontName";
((VFrameHeader*) op_isFontFixedWidth_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + isFontFixedWidthLocalsDef.size;
((VFrameHeader*) op_isFontFixedWidth_thread_spec) -> formalParamsCount = (isFontFixedWidthLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_isFontFixedWidth_thread_spec)[1])[0] = (size_t) &isFontFixedWidthLocalsDef;
((VFrameHeader*) op_isFontFixedWidth_thread_spec) -> functionName = "isFontFixedWidth";
((VFrameHeader*) op_getTextBitmapWith_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + getTextBitmapWithLocalsDef.size;
((VFrameHeader*) op_getTextBitmapWith_thread_spec) -> formalParamsCount = (getTextBitmapWithLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_getTextBitmapWith_thread_spec)[1])[0] = (size_t) &getTextBitmapWithLocalsDef;
((VFrameHeader*) op_getTextBitmapWith_thread_spec) -> functionName = "getTextBitmapWith";
((VFrameHeader*) op_unloadFont_thread_spec) -> frameSize = sizeof(VFrame) + sizeof(ScopeContainer) + sizeof(VVarR) + unloadFontLocalsDef.size;
((VFrameHeader*) op_unloadFont_thread_spec) -> formalParamsCount = (unloadFontLocalsDef.structure.vsize / sizeof(DanaType)) - 1;
((size_t*) &((VFrameHeader*) op_unloadFont_thread_spec)[1])[0] = (size_t) &unloadFontLocalsDef;
((VFrameHeader*) op_unloadFont_thread_spec) -> functionName = "unloadFont";
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
{"makeWindow", (VFrameHeader*) op_makeWindow_thread_spec},
{"selectEvent", (VFrameHeader*) op_selectEvent_thread_spec},
{"startPoly", (VFrameHeader*) op_startPoly_thread_spec},
{"addPolyPoint", (VFrameHeader*) op_addPolyPoint_thread_spec},
{"endPoly", (VFrameHeader*) op_endPoly_thread_spec},
{"addRect", (VFrameHeader*) op_addRect_thread_spec},
{"addLine", (VFrameHeader*) op_addLine_thread_spec},
{"addPoint", (VFrameHeader*) op_addPoint_thread_spec},
{"addBitmap", (VFrameHeader*) op_addBitmap_thread_spec},
{"addText", (VFrameHeader*) op_addText_thread_spec},
{"addTextWith", (VFrameHeader*) op_addTextWith_thread_spec},
{"pushSurface", (VFrameHeader*) op_pushSurface_thread_spec},
{"popSurface", (VFrameHeader*) op_popSurface_thread_spec},
{"setSize", (VFrameHeader*) op_setSize_thread_spec},
{"setPosition", (VFrameHeader*) op_setPosition_thread_spec},
{"setVisible", (VFrameHeader*) op_setVisible_thread_spec},
{"setTitle", (VFrameHeader*) op_setTitle_thread_spec},
{"commitBuffer", (VFrameHeader*) op_commitBuffer_thread_spec},
{"registerClickListener", (VFrameHeader*) op_registerClickListener_thread_spec},
{"registerMouseListener", (VFrameHeader*) op_registerMouseListener_thread_spec},
{"setBackgroundColor", (VFrameHeader*) op_setBackgroundColor_thread_spec},
{"maximiseWindow", (VFrameHeader*) op_maximiseWindow_thread_spec},
{"minimiseWindow", (VFrameHeader*) op_minimiseWindow_thread_spec},
{"getMaximisedScreenRect", (VFrameHeader*) op_getMaximisedScreenRect_thread_spec},
{"closeWindow", (VFrameHeader*) op_closeWindow_thread_spec},
{"loadFont", (VFrameHeader*) op_loadFont_thread_spec},
{"getTextWidth", (VFrameHeader*) op_getTextWidth_thread_spec},
{"getFontMetrics", (VFrameHeader*) op_getFontMetrics_thread_spec},
{"getFontName", (VFrameHeader*) op_getFontName_thread_spec},
{"isFontFixedWidth", (VFrameHeader*) op_isFontFixedWidth_thread_spec},
{"getTextBitmapWith", (VFrameHeader*) op_getTextBitmapWith_thread_spec},
{"unloadFont", (VFrameHeader*) op_unloadFont_thread_spec}};
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
{"FontMetrics", &data_FontMetrics_map_def},
{"Rect", &data_Rect_map_def},
{"Bitmap", &data_Bitmap_map_def},
{"Pixel[]", &data_Pixel_array_map_def},
{"Pixel", &data_Pixel_map_def},
{"WH", &data_WH_map_def},
{"WindowEventData", &data_WindowEventData_map_def},
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

