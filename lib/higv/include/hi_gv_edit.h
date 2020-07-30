/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: Edit API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_EDIT_H
#define HI_GV_EDIT_H

/* add include here */
#include "hi_gv_widget.h"
#ifdef HIGV_USE_WIDGET_EDIT
#ifdef __cplusplus
extern "C" {
#endif

/* Edit type */
typedef enum {
    EDIT_TYPE_DEFAULT   = 0x0,      /* Default style */
    EDIT_TYPE_REPLACE   = 0x4,      /* replace style */
    EDIT_TYPE_RDONLY    = 0x10,     /* Readonly style */
} HigvEditType;

/*  Edit type define */
#define HIGV_EDITTYPE_DEFINE(type) ((HIGV_WIDGET_EDIT << 24) | ((type & 0xff) << 16))
#define HIGV_EDITTYPE_REPLACE HIGV_EDITTYPE_DEFINE(EDIT_TYPE_REPLACE)
#define HIGV_EDITTYPE_RDONLY HIGV_EDITTYPE_DEFINE(EDIT_TYPE_RDONLY)
#define HIGV_EDIT_PARSERTYPE(editType) (((editType) >> 16) & 0xff)

/*
* brief Set the limit count of edit.CNcomment:设置可编辑字符个数
* param[in] handle Edit handle.CNcomment:控件句柄
* param[in] countLimit Count limit of edit.CNcomment:可编辑字符个数
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_NORES
* see
* HI_GV_Edit_SetCountLimit
*/
HI_S32 HI_GV_EDIT_SetCountLimit(HIGV_HANDLE handle, HI_U32 countLimit);

/*
* brief Get the limit count of edit.CNcomment:获取可编辑字符个数
* param[in]  handle Edit handle.CNcomment:控件句柄
* param[out] count Edit count.CNcomment:可编辑字符个数
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_LOST
* see
* HI_GV_EDIT_SetCountLimit
*/
HI_S32 HI_GV_EDIT_GetCountLimit(HIGV_HANDLE handle, HI_U32 *count);

/*
* brief Reset the index of cursor.CNcomment:设置光标在文本内容中的字节索引
* param[in] handle Edit handle.CNcomment:控件句柄
* param[in] cursorIndex Cursor Index.CNcomment:光标索引
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see
* HI_GV_EDIT_GetCursorIndex
*/
HI_S32 HI_GV_EDIT_SetCursorIndex(HIGV_HANDLE handle, HI_U32 cursorIndex);

/*
* brief Get index of cursor.CNcomment:获取光标在文本内容中的字节索引
* param[in]  handle  Edit handle.CNcomment:控件句柄
* param[out] cursorIndex  Cursor Index.CNcomment:光标索引
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see
* HI_GV_EDIT_SetCursorIndex
*/
HI_S32 HI_GV_EDIT_GetCursorIndex(HIGV_HANDLE handle, HI_U32 *cursorIndex);

/*
* brief Reset the position of cursor.CNcomment:设置光标位置
* param[in] handle Edit handle.CNcomment:控件句柄
* param[in] cursorPos Cursor position.CNcomment:光标位置
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see
* HI_GV_EDIT_GetCursorPos
*/
HI_S32 HI_GV_EDIT_SetCursorPos(HIGV_HANDLE handle, HI_U32 cursorPos);

/*
* brief Get position of cursor.CNcomment:获取光标位置
* param[in]  handle  Edit handle.CNcomment:控件句柄
* param[out] cursorPos  Cursor position.CNcomment:光标位置
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see
* HI_GV_EDIT_SetCursorPos
*/
HI_S32 HI_GV_EDIT_GetCursorPos(HIGV_HANDLE handle, HI_U32 *cursorPos);

/*
* brief Set the content of edit.CNcomment:设置Edit控件当前显示内容
* param[in] handle  Edit handle.CNcomment:控件句柄
* param[in] content  Current content.CNcomment:当前显示内容
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see
* HI_GV_EDIT_GetContent
*/
HI_S32 HI_GV_EDIT_SetContent(HIGV_HANDLE handle, const HI_CHAR *content);

/*
* brief Get the display content of edit.CNcomment:获取Edit控件当前显示内容
* param[in]  handle Edit handle.CNcomment:控件句柄
* param[out] content The dipslay content.CNcomment:当前显示内容
* param[in]  length The length of dipslay buffer pContent.CNcomment:pContent存放当前显示内容缓冲区的长度
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see
* HI_GV_EDIT_SetContent
*/
HI_S32 HI_GV_EDIT_GetContent(HIGV_HANDLE handle, HI_CHAR *content, HI_U32 length);

/*
* brief Set the syle of edit.CNcomment:设置控件的风格,只能设置一次
* param[in] handle Edit handle.CNcomment:控件句柄
* param[in] type Edit type. CNcomment:控件风格
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see
* HI_GV_EDIT_GetType
*/
HI_S32 HI_GV_EDIT_SetType(HIGV_HANDLE handle, HI_U32 type);

/*
* brief Get the type of edit.CNcomment:获取控件的风格
* param[in]  handle edit handle. CNcomment:控件句柄
* param[out] type edit type.CNcomment:控件风格
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see
* HI_GV_EDIT_SetType
*/
HI_S32 HI_GV_EDIT_GetType(HIGV_HANDLE handle, HI_U32 *type);

/*
* brief Get the type of edit.CNcomment:设置替换风格是否显示内容
* param[in]  handle edit handle. CNcomment:控件句柄
* param[out] isShow isshow content.CNcomment:显示内容标志位
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_EDIT_ShowReplace(HIGV_HANDLE handle, HI_BOOL isShow);

/*
* brief Clear content in edit box.CNcomment:清除编辑框里内容
* param[in]  handle edit handle. CNcomment:控件句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_EDIT_CleanContent(HIGV_HANDLE handle);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_EDIT_H */
