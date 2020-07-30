/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: MultiEdit API
 * Author: NULL
 * Create: 2009-2-9
 */
#ifndef HI_GV_MULTIEDIT_H
#define HI_GV_MULTIEDIT_H
/* add include here */
#include "hi_gv_widget.h"
#ifdef HIGV_USE_WIDGET_MULTIEDIT
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    HI_U32 charNum; /*  Limit the number of char */          /*  CNcomment: �ַ����ƣ�Ϊ�㲻������ */
    HI_U32 lineNum; /*  Limit the number of line */          /*  CNcomment: �������ƣ�Ϊ�㲻������ */
    HI_BOOL isReadOnly; /*  Only read flag */                /*  CNcomment:�Ƿ�ֻ�� */
    HI_BOOL isSingleLine; /*  Single line flag */            /*  CNcomment:�Ƿ��� */
    HIGV_HANDLE font; /*  Font handle */                    /*  CNcomment:������ */
    HI_COLOR selectBgColor; /*  Selected background color */ /*  CNcomment:��ѡ������ɫ */
    HI_COLOR selectFgColor; /*  Selected foreground color */ /*  CNcomment:��ѡǰ����ɫ */
    HI_COLOR cursorColor; /*  Cursor color */                /*  CNcomment:�����ɫ */
    HI_U32 lineSpace; /*  Space between line */              /*  CNcomment:�м�� */
    HI_U32 charSpace; /*  Space between char */              /*  CNcomment:�ַ���� */
} HigvMultiEditStyle;

typedef enum {
    /*  Left side */ /*  CNcomment:��߽� */
    HIGV_MULTIEDIT_SIDE_LEFT = 0,
    /*  Right side */ /*  CNcomment:�ұ߽� */
    HIGV_MULTIEDIT_SIDE_RIGHT = 1,
    /*  Top side */ /*  CNcomment:�ϱ߽� */
    HIGV_MULTIEDIT_SIDE_TOP = 2,
    /*  Down side */ /*  CNcomment:�±߽� */
    HIGV_MULTIEDIT_SIDE_BOTTOM = 3,
} HigvMultiEditSlide;

/*
\brief Init the multiedit.CNcomment:��ʼ��multiedit�ؼ�
\attention \n
N/A.CNcomment:��
\param[in]  editHandle multiedit handle. CNcomment:�ؼ����
\param[in]  style The info of multiedit when created. CNcomment:�ؼ�������Ϣ
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\retval ::HI_ERR_COMM_NORES
\see \n
N/A.CNcomment:��
*/
HI_S32 HI_GV_MULTIEDIT_Init(HIGV_HANDLE editHandle, HigvMultiEditStyle *style);

/*
\brief Set the content of edit.CNcomment:����Edit�ؼ���ǰ��ʾ����
\attention \n
��
\param[in] editHandle  multiedit handle.CNcomment:�ؼ����
\param[in] content  Current content.CNcomment:��ǰ��ʾ����
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
::HI_GV_MULTIEDIT_GetContent
*/
HI_S32 HI_GV_MULTIEDIT_SetContent(HIGV_HANDLE editHandle, const HI_CHAR *content);

/*
\brief Get the display content of edit.CNcomment:��ȡEdit�ؼ���ǰ��ʾ����
\attention \n
N/A.CNcomment:��
\param[in]  editHandle multiedit handle.CNcomment:�ؼ����
\param[out] content The dipslay content.CNcomment:��ǰ��ʾ����
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
::HI_GV_MULTIEDIT_SetContent
::HI_GO_LayoutGetText
*/
HI_S32 HI_GV_MULTIEDIT_GetContent(HIGV_HANDLE editHandle, HI_CHAR *content);

/*
\brief Clear the display content of edit.CNcomment:���Edit�ؼ���ǰ��ʾ����
\attention \n
N/A.CNcomment:��
\param[in]  editHandle multiedit handle.CNcomment:�ؼ����
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
::HI_GV_MULTIEDIT_SetContent
*/
HI_S32 HI_GV_MULTIEDIT_ClearContent(HIGV_HANDLE editHandle);

/*
\brief Get select string.CNcomment:��ȡѡ�е��ִ�
\attention \n
N/A.CNcomment:��
\param[in]  editHandle multiedit handle.CNcomment:�ؼ����
\param[out] str UTF8 string to output.CNcomment:�����UTF-8�ַ���
\param[out] len Lenth of output string.CNcomment:������ַ���
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\retval ::HI_ERR_COMM_EMPTY
\see \n
N/A.CNcomment:��
*/
HI_S32 HI_GV_MULTIEDIT_GetSelectString(HIGV_HANDLE editHandle, HI_CHAR *str, HI_U32 *len);
/*
\brief Page up.CNcomment:���Ϸ�ҳ
\attention \n
N/A.CNcomment:��
\param[in]  editHandle multiedit handle.CNcomment:�ؼ����
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\see \n
HI_GV_MULTIEDIT_PageDown
*/
HI_S32 HI_GV_MULTIEDIT_PageUp(HIGV_HANDLE editHandle);

/*
\brief Page down.CNcomment:���·�ҳ
\attention \n
N/A.CNcomment:��
\param[in]  editHandle multiedit handle.CNcomment:�ؼ����
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\see \n
HI_GV_MULTIEDIT_PageUp
*/
HI_S32 HI_GV_MULTIEDIT_PageDown(HIGV_HANDLE editHandle);

/*
\brief Set cursor color.CNcomment:���ù����ɫ
\attention \n
N/A.CNcomment:��
\param[in]  editHandle multiedit handle.CNcomment:�ؼ����
\param[in]  color cursor color.CNcomment:�����ɫֵ
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\see \n
N/A.CNcomment:��
*/
HI_S32 HI_GV_MULTIEDIT_SetCursorColor(HIGV_HANDLE editHandle, HI_COLOR color);

/*
\brief Enable widget get focuse with show soft keyboard.CNcomment:ʹ�ܿؼ���ʱ��ʾ�����
\attention \n
N/A.CNcomment:��
\param[in]  editHandle multiedit handle.CNcomment:�ؼ����
\param[in]  isEnable enable switch color.CNcomment:ʹ�ܿ���
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\see \n
N/A.CNcomment:��
*/
HI_S32 HI_GV_MULTIEDIT_ActiveWithIME(HIGV_HANDLE editHandle, HI_BOOL isEnable);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_MULTIEDIT_H */