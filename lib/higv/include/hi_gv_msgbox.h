/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: MSGBOX API
 * Author: HiMobileCam middleware develop team
 * Create: 2020-02-11
 */

#ifndef HI_GV_MSGBOX_H
#define HI_GV_MSGBOX_H

/* add include here */
#include "hi_gv_conf.h"
#include "hi_type.h"
#include "hi_gv_widget.h"

#ifdef HIGV_USE_WIDGET_MSGBOX

#ifdef __cplusplus
extern "C" {
#endif

#define MAXBUTTONNUM   4

/* Standard Message button ID */
#define MSG_BUTTONID_INVALID    0
#define MSG_BUTTONID_OK         1
#define MSG_BUTTONID_CANCEL     2
#define MSG_BUTTONID_ABORT      3
#define MSG_BUTTONID_RETRY      4
#define MSG_BUTTONID_IGNORE     5
#define MSG_BUTTONID_YES        6
#define MSG_BUTTONID_NO         7

/* customized style */
typedef enum {
    MSGBOX_STYLE_NONE = 0,               /* None button */
    MSGBOX_STYLE_OK = 1,                 /* Only OK */
    MSGBOX_STYLE_OKCANCEL = 2,           /* OK+cancel */
    MSGBOX_STYLE_RETRYCANCEL = 3,        /* Retry+cancel */
    MSGBOX_STYLE_ABORTRETRYIGNORE = 4,   /* Abort+retry+ignore */
    MSGBOX_STYLE_YESNOCANCEL = 5,        /* Yes+no+cancel */
    MSGBOX_STYLE_USERDEF = 6             /* User-Defined */
} HigvMsgBoxStyle;


/* MessageBox title info struction */
typedef struct {
    HI_U32  titleHeight;                /* Title height */
    HI_U32  titleAlignment;             /* Title alignment */
    HI_RESID titleSkin;                 /* Title skin style */
    HIGV_HANDLE titleFont;                /* Text font of title */
} HigvMsgBoxTitle;


/* MessageBox button info struction */
typedef struct {
    HI_U32  buttonAreaHeight;       /* Button area height */
    HI_U32  buttonCount;            /* Button count */
    HI_U32  buttonHeight;           /* Button widget height */
    HI_U32  buttonWidth;            /* Button widget width */
    HI_RESID buttonNormalSkin;      /* Button widget normal skin style */
    HI_RESID buttonActiveSkin;      /* Button widget active skin style */
    HI_RESID buttonHighlightSkin;   /* Button widget hightlight skin style */
    HI_RESID buttonMouseDownSkin;   /* Button widget mouse down skin style */
    HI_RESID buttonAreaSkin;        /* Button area skin style */
    HIGV_HANDLE buttonFont;           /* Text font of button widget */
} HigvMsgBoxButton;


/* MessageBox info struction for create */
typedef struct {
    HigvMsgBoxStyle msgBoxStyle;    /* Message box style */
    HigvMsgBoxTitle titleInfo;      /* Title info */
    HigvMsgBoxButton buttonInfo;    /* Button info */
    HI_U32 showTimes;               /* Show times */
    HI_RESID icon;                  /* Icon res ID */
} HigvMsgBoxCreateInfo;

/*
\brief Init Message box.CNcomment:初始化消息框
\attention \n
N/A.CNcomment:无
\param[in]  handle  Message box handle.CNcomment:控件句柄
\param[in]  createInfo  Create information.CNcomment:初始化信息

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL

\see \
N/A.CNcomment:无
*/
HI_S32 HI_GV_MSGBOX_Init(HIGV_HANDLE handle, HigvMsgBoxCreateInfo* createInfo);

/*
\brief Set title text.CNcomment:设置title显示文本
\attention \n
N/A.CNcomment:无
\param[in]  handle  Msg box handle.CNcomment:控件句柄
\param[in]  text    Text of Message box title.Cncomment:文本

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\retval ::HI_ERR_COMM_NOTREADY

\see \
:: HI_GV_MSGBOX_GetTitleText
*/
HI_S32 HI_GV_MSGBOX_SetTitleText(HIGV_HANDLE handle, const HI_CHAR* text);

/*
\brief Get title text.CNcomment: 获取title文本
\attention \n
N/A.CNcomment:无
\param[in] handle   Widget handle.CNcomment: 控件句柄
\param[out] buf     Text content.CNcomment: 控件文本内容
\param[in] bufLen    Buffer length.CNcomment: 输出buf长度

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\retval ::HI_ERR_COMM_NOTREADY
\see \n
:: HI_GV_MSGBOX_SetTitleText
*/
HI_S32  HI_GV_MSGBOX_GetTitleText(HIGV_HANDLE handle, HI_CHAR* buf, HI_U32 bufLen);

/*
\brief Set title text by ID.CNcomment: 通过字符串ID设置title文本
\attention \n
N/A.CNcomment:无
\param[in] handle  Widget handle.CNcomment: 控件句柄
\param[in] strID    String ID.CNcomment: 控件文本ID

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_NOTREADY
\see \n
::HI_GV_MSGBOX_GetTitleTextID
*/
HI_S32 HI_GV_MSGBOX_SetTitleTextByID(HIGV_HANDLE handle, const HI_U32 strID);

/*
\brief Get title text by ID.CNcomment: 获取title文本ID
\attention \n
N/A.CNcomment:无
\param[in] handle  Widget handle.CNcomment:  控件句柄
\param[out] strID   String ID.CNcomment:  输出文本ID

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\retval ::HI_ERR_COMM_NOTREADY
\see \n
:: HI_GV_ MSGBOX_SetTitleTextByID
*/
HI_S32  HI_GV_MSGBOX_GetTitleTextID(HIGV_HANDLE handle, HI_U32* strID);

/*
\brief Set icon res.CNcomment: 设置图片资源
\attention \n
N/A.CNcomment:无
\param[in] handle  Widget handle.CNcomment: 控件句柄
\param[in] icon     Icon res ID.CNcomment:Icon的资源ID

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval:: HI_ERR_COMM_NOTREADY

\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_MSGBOX_SetIcon(HIGV_HANDLE handle, HI_RESID icon);

/*
\brief Set button layout.CNcomment: 设置button布局
\attention \n
Only User-Defined style can availability.CNcomment:  只有用户自定义风格时有效
The button index from left to right.CNcomment: 从左到右按钮的索引
\param[in] handle  Widget handle. CNcomment: 控件句柄
\param[in] Button[] The button ID array.CNcomment: 按钮ID数组
\param[in] length The length of button ID array.CNcomment: 按钮ID数组长度

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_NOTREADY

\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_MSGBOX_ButtonLayout(HIGV_HANDLE handle,  HI_S32 buttonID[MAXBUTTONNUM], HI_S32 length);

/*
\brief Set inchoative button index.CNcomment: 设置初始焦点
\attention \n
N/A.CNcomment:无
\param[in] handle   Widget handle.CNcomment: 控件句柄
\param[in] buttonID  Button ID.CNcomment: 初始焦点button

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\retval ::HI_ERR_COMM_NOTREADY

\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_MSGBOX_SetInitFocusButton(HIGV_HANDLE handle,  HI_S32 buttonID);

/*
\brief Get child button handle.CNcomment: 获取子按钮句柄
\attention \n
N/A.CNcomment:无
\param[in] handle   Widget handle.CNcomment: 控件句柄
\param[out] buttonArray  Button Handle Array.CNcomment: 按钮句柄获取参数数组
\param[in] length  The length of Button Handle Array.CNcomment: 按钮句柄获取参数数组长度

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\retval ::HI_ERR_COMM_NOTREADY

\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_MSGBOX_GetButtonHandle(HIGV_HANDLE handle,  HIGV_HANDLE buttonArray[MAXBUTTONNUM], HI_S32 length);

/*
\brief Sync get key down button index.CNcomment:同步获取按下按钮的索引
\attention \n
N/A.CNcomment:无
\param[in] handle  Msg box handle.CNcomment:控件句柄

\retval :: MSG_BUTTONID
\retval :: HI_FAILURE

\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_MSGBOX_Show(HIGV_HANDLE handle);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_MSGBOX_H */
