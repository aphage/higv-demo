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
* brief Set the limit count of edit.CNcomment:���ÿɱ༭�ַ�����
* param[in] handle Edit handle.CNcomment:�ؼ����
* param[in] countLimit Count limit of edit.CNcomment:�ɱ༭�ַ�����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_NORES
* see
* HI_GV_Edit_SetCountLimit
*/
HI_S32 HI_GV_EDIT_SetCountLimit(HIGV_HANDLE handle, HI_U32 countLimit);

/*
* brief Get the limit count of edit.CNcomment:��ȡ�ɱ༭�ַ�����
* param[in]  handle Edit handle.CNcomment:�ؼ����
* param[out] count Edit count.CNcomment:�ɱ༭�ַ�����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_LOST
* see
* HI_GV_EDIT_SetCountLimit
*/
HI_S32 HI_GV_EDIT_GetCountLimit(HIGV_HANDLE handle, HI_U32 *count);

/*
* brief Reset the index of cursor.CNcomment:���ù�����ı������е��ֽ�����
* param[in] handle Edit handle.CNcomment:�ؼ����
* param[in] cursorIndex Cursor Index.CNcomment:�������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see
* HI_GV_EDIT_GetCursorIndex
*/
HI_S32 HI_GV_EDIT_SetCursorIndex(HIGV_HANDLE handle, HI_U32 cursorIndex);

/*
* brief Get index of cursor.CNcomment:��ȡ������ı������е��ֽ�����
* param[in]  handle  Edit handle.CNcomment:�ؼ����
* param[out] cursorIndex  Cursor Index.CNcomment:�������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see
* HI_GV_EDIT_SetCursorIndex
*/
HI_S32 HI_GV_EDIT_GetCursorIndex(HIGV_HANDLE handle, HI_U32 *cursorIndex);

/*
* brief Reset the position of cursor.CNcomment:���ù��λ��
* param[in] handle Edit handle.CNcomment:�ؼ����
* param[in] cursorPos Cursor position.CNcomment:���λ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see
* HI_GV_EDIT_GetCursorPos
*/
HI_S32 HI_GV_EDIT_SetCursorPos(HIGV_HANDLE handle, HI_U32 cursorPos);

/*
* brief Get position of cursor.CNcomment:��ȡ���λ��
* param[in]  handle  Edit handle.CNcomment:�ؼ����
* param[out] cursorPos  Cursor position.CNcomment:���λ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see
* HI_GV_EDIT_SetCursorPos
*/
HI_S32 HI_GV_EDIT_GetCursorPos(HIGV_HANDLE handle, HI_U32 *cursorPos);

/*
* brief Set the content of edit.CNcomment:����Edit�ؼ���ǰ��ʾ����
* param[in] handle  Edit handle.CNcomment:�ؼ����
* param[in] content  Current content.CNcomment:��ǰ��ʾ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see
* HI_GV_EDIT_GetContent
*/
HI_S32 HI_GV_EDIT_SetContent(HIGV_HANDLE handle, const HI_CHAR *content);

/*
* brief Get the display content of edit.CNcomment:��ȡEdit�ؼ���ǰ��ʾ����
* param[in]  handle Edit handle.CNcomment:�ؼ����
* param[out] content The dipslay content.CNcomment:��ǰ��ʾ����
* param[in]  length The length of dipslay buffer pContent.CNcomment:pContent��ŵ�ǰ��ʾ���ݻ������ĳ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see
* HI_GV_EDIT_SetContent
*/
HI_S32 HI_GV_EDIT_GetContent(HIGV_HANDLE handle, HI_CHAR *content, HI_U32 length);

/*
* brief Set the syle of edit.CNcomment:���ÿؼ��ķ��,ֻ������һ��
* param[in] handle Edit handle.CNcomment:�ؼ����
* param[in] type Edit type. CNcomment:�ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see
* HI_GV_EDIT_GetType
*/
HI_S32 HI_GV_EDIT_SetType(HIGV_HANDLE handle, HI_U32 type);

/*
* brief Get the type of edit.CNcomment:��ȡ�ؼ��ķ��
* param[in]  handle edit handle. CNcomment:�ؼ����
* param[out] type edit type.CNcomment:�ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see
* HI_GV_EDIT_SetType
*/
HI_S32 HI_GV_EDIT_GetType(HIGV_HANDLE handle, HI_U32 *type);

/*
* brief Get the type of edit.CNcomment:�����滻����Ƿ���ʾ����
* param[in]  handle edit handle. CNcomment:�ؼ����
* param[out] isShow isshow content.CNcomment:��ʾ���ݱ�־λ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_EDIT_ShowReplace(HIGV_HANDLE handle, HI_BOOL isShow);

/*
* brief Clear content in edit box.CNcomment:����༭��������
* param[in]  handle edit handle. CNcomment:�ؼ����
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
