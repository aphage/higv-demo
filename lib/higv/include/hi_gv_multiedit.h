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
    HI_U32 charNum; /*  Limit the number of char */          /*  CNcomment: 字符限制，为零不做限制 */
    HI_U32 lineNum; /*  Limit the number of line */          /*  CNcomment: 行数限制，为零不做限制 */
    HI_BOOL isReadOnly; /*  Only read flag */                /*  CNcomment:是否只读 */
    HI_BOOL isSingleLine; /*  Single line flag */            /*  CNcomment:是否单行 */
    HIGV_HANDLE font; /*  Font handle */                    /*  CNcomment:字体句柄 */
    HI_COLOR selectBgColor; /*  Selected background color */ /*  CNcomment:反选背景颜色 */
    HI_COLOR selectFgColor; /*  Selected foreground color */ /*  CNcomment:反选前景颜色 */
    HI_COLOR cursorColor; /*  Cursor color */                /*  CNcomment:光标颜色 */
    HI_U32 lineSpace; /*  Space between line */              /*  CNcomment:行间距 */
    HI_U32 charSpace; /*  Space between char */              /*  CNcomment:字符间距 */
} HigvMultiEditStyle;

typedef enum {
    /*  Left side */ /*  CNcomment:左边界 */
    HIGV_MULTIEDIT_SIDE_LEFT = 0,
    /*  Right side */ /*  CNcomment:右边界 */
    HIGV_MULTIEDIT_SIDE_RIGHT = 1,
    /*  Top side */ /*  CNcomment:上边界 */
    HIGV_MULTIEDIT_SIDE_TOP = 2,
    /*  Down side */ /*  CNcomment:下边界 */
    HIGV_MULTIEDIT_SIDE_BOTTOM = 3,
} HigvMultiEditSlide;

/*
\brief Init the multiedit.CNcomment:初始化multiedit控件
\attention \n
N/A.CNcomment:无
\param[in]  editHandle multiedit handle. CNcomment:控件句柄
\param[in]  style The info of multiedit when created. CNcomment:控件创建信息
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\retval ::HI_ERR_COMM_NORES
\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_MULTIEDIT_Init(HIGV_HANDLE editHandle, HigvMultiEditStyle *style);

/*
\brief Set the content of edit.CNcomment:设置Edit控件当前显示内容
\attention \n
无
\param[in] editHandle  multiedit handle.CNcomment:控件句柄
\param[in] content  Current content.CNcomment:当前显示内容
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
::HI_GV_MULTIEDIT_GetContent
*/
HI_S32 HI_GV_MULTIEDIT_SetContent(HIGV_HANDLE editHandle, const HI_CHAR *content);

/*
\brief Get the display content of edit.CNcomment:获取Edit控件当前显示内容
\attention \n
N/A.CNcomment:无
\param[in]  editHandle multiedit handle.CNcomment:控件句柄
\param[out] content The dipslay content.CNcomment:当前显示内容
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
::HI_GV_MULTIEDIT_SetContent
::HI_GO_LayoutGetText
*/
HI_S32 HI_GV_MULTIEDIT_GetContent(HIGV_HANDLE editHandle, HI_CHAR *content);

/*
\brief Clear the display content of edit.CNcomment:清除Edit控件当前显示内容
\attention \n
N/A.CNcomment:无
\param[in]  editHandle multiedit handle.CNcomment:控件句柄
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
::HI_GV_MULTIEDIT_SetContent
*/
HI_S32 HI_GV_MULTIEDIT_ClearContent(HIGV_HANDLE editHandle);

/*
\brief Get select string.CNcomment:获取选中的字串
\attention \n
N/A.CNcomment:无
\param[in]  editHandle multiedit handle.CNcomment:控件句柄
\param[out] str UTF8 string to output.CNcomment:输出的UTF-8字符串
\param[out] len Lenth of output string.CNcomment:输出的字符串
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\retval ::HI_ERR_COMM_EMPTY
\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_MULTIEDIT_GetSelectString(HIGV_HANDLE editHandle, HI_CHAR *str, HI_U32 *len);
/*
\brief Page up.CNcomment:向上翻页
\attention \n
N/A.CNcomment:无
\param[in]  editHandle multiedit handle.CNcomment:控件句柄
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\see \n
HI_GV_MULTIEDIT_PageDown
*/
HI_S32 HI_GV_MULTIEDIT_PageUp(HIGV_HANDLE editHandle);

/*
\brief Page down.CNcomment:向下翻页
\attention \n
N/A.CNcomment:无
\param[in]  editHandle multiedit handle.CNcomment:控件句柄
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\see \n
HI_GV_MULTIEDIT_PageUp
*/
HI_S32 HI_GV_MULTIEDIT_PageDown(HIGV_HANDLE editHandle);

/*
\brief Set cursor color.CNcomment:设置光标颜色
\attention \n
N/A.CNcomment:无
\param[in]  editHandle multiedit handle.CNcomment:控件句柄
\param[in]  color cursor color.CNcomment:光标颜色值
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_MULTIEDIT_SetCursorColor(HIGV_HANDLE editHandle, HI_COLOR color);

/*
\brief Enable widget get focuse with show soft keyboard.CNcomment:使能控件获焦时显示软键盘
\attention \n
N/A.CNcomment:无
\param[in]  editHandle multiedit handle.CNcomment:控件句柄
\param[in]  isEnable enable switch color.CNcomment:使能开关
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_MULTIEDIT_ActiveWithIME(HIGV_HANDLE editHandle, HI_BOOL isEnable);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_MULTIEDIT_H */