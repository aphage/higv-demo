/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: Input method window API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_IMEWINDOW_H
#define HI_GV_IMEWINDOW_H

/* add include here */
#include "hi_gv_widget.h"
#ifdef HIGV_USE_MODULE_IME
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    HI_GV_IMEWindow_ENGLISH = 0,
    HI_GV_IMEWindow_CAPENGLISH,
    HI_GV_IMEWindow_NUMBER,
    HI_GV_IMEWindow_PINYIN,
    HI_GV_IMEWindow_SYBMOL,
    HI_GV_IMEWindow_STANDARD_A,
    HI_GV_IMEWindow_STANDARD_B,
    HI_GV_IMEWindow_BUTT
} HigvIMEWindowType;

typedef struct {
    HI_U32 pinyinCharRectLeftMargin; /* Left margin of pingyin input rect */
    HI_U32 pinyinCharRectUpMargin; /* Up margin of pingyin input rect */
    HI_U32 pinyinCharRectDownMargin; /* Down margin of pingyin input rect */

    HI_U32 logPicRectRightMargin; /* Right margin of logo */
    HI_U32 logPicRectUpMargin; /* Up margin of logo */
    HI_U32 logPicRectDownMargin; /* Down margin of logo */
    HI_U32 logPicRectWidth; /* The width of logo */
    HI_U32 logPicRectHeight; /* The height of logo */

    HI_U32 logPicAndCharRectSpace; /* The space between logo and input char rect */

    HI_U32 lArrowPicRectLeftMargin; /* The space margin of left arrow rect */
    HI_U32 lArrowPicRectUpMargin; /* The up margin of bottom arrow rect */
    HI_U32 lArrowPicRectDownMargin; /* The down margin of bottom arrow rect */
    HI_U32 lArrowPicRectWidth; /* The height of left arrow rect */
    HI_U32 lArrowPicRectHeight; /* The width of left arrow rect */

    HI_U32 rArrowPicRectRightMargin; /* Right margin of right arrow rect */
    HI_U32 rArrowPicRectUpMargin; /* Up margin of right arrow rect */
    HI_U32 rArrowPicRectDownMargin; /* Bottom margin of right arrow rect */
    HI_U32 rArrowPicRectWidth; /* The height of right arrow rect */
    HI_U32 rArrowPicRectHeight; /* The height of left arrow rect */

    HI_U32 twoArrowSpace; /* The space between left and right margin */

    HI_U32 candidataWordUpMargin; /* Top margin of first level candiate */
    HI_U32 candidataWordDownMargin; /* Down margin of first level candidate */
    HI_U32 candidataWordLeftMargin; /* Left margin of first level candidate */
} HigvIMEWindowInitEx;

typedef struct {
    HIGO_PF_E pixelFormat; /* Input method pixel format */
    HI_PARAM englishLogoIndex; /* english input method logo */
    HI_PARAM capEnglishLogoIndex; /* Caps english input method logo */
    HI_PARAM symbolLogoIndex; /* Symbol input method logo */
    HI_PARAM numberLogoIndex; /* Number input method LOGO */
    HI_PARAM pinyinLogoIndex; /* Pinyin input method LOGO */
    HI_PARAM standardALogoIndex; /* Standard input method A logo */
    HI_PARAM standardBLogoIndex; /* Standard input method B logo */
    HI_PARAM leftArrowPicIndex; /* Left arrow picture */
    HI_PARAM rightArrowPicIndex; /* Right arrow picture */
    HI_PARAM unActiveLeftArrowPicIndex; /* Unactive status of left arrow */
    HI_PARAM unActiveRightArrowPicIndex; /* Unactive status of right arrow */
    HI_PARAM pinYinTablePath; /* path of pinyin code table */
    HI_PARAM pinYinTablePathLen; /* path length of pinyin code table */
    HigvIMEWindowInitEx *exData; /* Change input method size */
} HigvIMEWindowInit;

typedef struct {
    HIGV_HANDLE keyWidget;
    HI_U32 keyValue;
} HigvIMEWindowKeyValuePair;

typedef struct {
    HI_BOOL isNoDispIMW; /* Whether display input method window, default show. */
    HIGV_HANDLE softKB; /* Soft keyboard handle */
    HI_BOOL isDispSoftKB; /* Whether show softkeyboard */
    HigvIMEWindowKeyValuePair *keyValueMap; /* key map */
    HI_U32 keyNum; /* Key number */
} HigvIMEWindowSoftKB;

/*
\brief Create input method window(default height/width:100/42).CNcomment:创建输入法，输入法窗口宽度100,  高度42
\param[in]  creatInfo Create inforamtion.CNcomment:输入法窗口初始化信息
\param[out] handle Input method window handle.  CNcomment:创建的输入法窗口句柄指针
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\retval ::HI_EEXIST
\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_IMEWINDOW_Create(const HIGV_WCREATE_S *creatInfo, HigvIMEWindowInit *initData, HIGV_HANDLE *handle);

/*
\brief Destroy input method window.CNcomment:销毁输入法窗口
\param[in] handle
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_IMEWINDOW_Destroy(HIGV_HANDLE handle);

/*
\brief Switch input method.CNcomment:切换输入法
\param[in] handle
\param[in] imeType
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_IMEWINDOW_Change(HIGV_HANDLE handle, HigvIMEWindowType imeType);

/*
\brief Open/clos the input method.CNcomment:打开/关闭指定输入法
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_IMEWINDOW_Enable(HigvIMEWindowType imeType, HI_BOOL isEnable);

/*
\brief Set the switch window at init stage.CNcomment:初始化时设置输入法切换窗口句柄
\attention \n
N/A.CNcomment:无
\param[in]  handle   Input method window handle. CNcomment:输入法窗口
\param[in]  switchWindowHandle  switch window CNcomment:控制显示输入法
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_IMEWINDOW_SetSwitchIMWin(HIGV_HANDLE handle, HIGV_HANDLE switchWindowHandle);

/*
\brief Bind the softkeyboard to the input window at init stage.CNcomment:初始化时绑定软键盘到输入法 窗口
\attention \n
N/A.CNcomment:无
\param[in]  handle   Input method window handle.  CNcomment:输入法窗口
\param[in]  softKBArray Softkey board.CNcomment:需要绑定的软键盘
\param[in]  imeNum   Input method number.CNcomment: 绑定输入法数目
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_IMEWINDOW_SetSoftKB(HIGV_HANDLE handle, HigvIMEWindowSoftKB *softKBArray, HI_U32 imeNum);

/*
\brief Get the show status of input window.CNcomment:获取当前输入法相关 窗口(包括输入法窗口或软键盘)
或输入法切换窗口)的显示状态
\attention \n
N/A.CNcomment:无
\param[in]  handle Input method window handle.  CNcomment:输入法窗口
\retval ::HI_TRUE  Show.CNcomment:显示
\retval ::HI_FALSE Hide.CNcomment:隐藏
\see \n
N/A.CNcomment:无
*/
HI_BOOL HI_GV_IMEWINDOW_IsShowIM(HIGV_HANDLE handle);

/*
\brief Get the show status of softkeyboard.CNcomment:获取当前软键盘窗口软键盘的显示状态
\attention \n
N/A.CNcomment:无
\param[in]  handle Input mesthod window handle.CNcomment:输入法窗口
\retval ::HI_TRUE  Show. CNcomment:显示
\retval ::HI_FALSE Hdie.CNcomment:隐藏
\see \n
N/A.CNcomment:无
*/
HI_BOOL HI_GV_IMEWINDOW_IsShowSoftKB(HIGV_HANDLE handle);

/*
\brief Set the show status of soft keyboard.CNcomment:设置软键盘窗口软键盘的显示状态
\attention \n
N/A.CNcomment:无
\param[in]  handle   Input method window handle.  CNcomment:输入法窗口
\param[in]  softKBHandle  Softkeyboad winddow handle. CNcomment:软键盘窗口
\param[in]  isShow  show/hide. CNcomment:显示或隐藏
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_IMEWINDOW_SetDispSoftKB(HIGV_HANDLE handle, HIGV_HANDLE softKBHandle, HI_BOOL isShow);

/*
\brief Get the active widget which get the input focus.CNcomment:获取当前激活输入法的控件或输入法切换窗口
\attention \n
N/A.CNcomment:无
\param[in]  handle    Input method window handle. CNcomment:输入法窗口
\param[out]  activeWidget  The active widget handle.  CNcomment:当前激活控件句柄指针
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_IMEWINDOW_GetIMEActiveWidget(HIGV_HANDLE handle, HIGV_HANDLE *activeWidget);

/*
\brief Get the current input method.CNcomment:获取当前输入法
\attention \n
N/A.CNcomment:无
\param[in]  handle  Input method window handle.  CNcomment:输入法窗口
\param[out]  imeType  The pointer of inpute method. CNcomment: 当前输入法指针
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_IMEWINDOW_GetCurrentIME(HIGV_HANDLE handle, HigvIMEWindowType *imeType);

/*
\brief Reset the key map of softkeyboard.CNcomment:重设软键盘窗口的按钮按键映射
\attention \n
N/A.CNcomment:无
\param[in]  imeType  Input method.  CNcomment:重设的输入法
\param[in]  keyValue   The pointer of Key value.CNcomment:映射指针
\param[in]  num   Key value number.CNcomment:重设的数目
\param[out]
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:无
*/
HI_S32 HI_GV_IMEWINDOW_SetKeyValue(HigvIMEWindowType imeType, HI_U32 *keyValue, HI_U32 num);

/*
\brief 设置软键盘显示在屏幕的固定位置
\attention \n
无
\param[in]  handle    输入法窗口
\param[in]  x    屏幕坐标x
\param[in]  y    屏幕坐标y
\retval ::HI_SUCCESS 成功
\retval ::HI_ERR_LOST 句柄无效
\retval ::HI_ERR_INVAL 无效参数
\see \n
无
*/
HI_S32 HI_GV_IMEWINDOW_PinSoftKB(HIGV_HANDLE handle, HI_S32 x, HI_S32 y);

/*
\brief 不固定显示软键盘显示位置
\attention \n
无
\param[in]  handle    输入法窗口
\retval ::HI_SUCCESS 成功
\retval ::HI_ERR_LOST 句柄无效
\retval ::HI_ERR_INVAL 无效参数
\see \n
无
*/
HI_S32 HI_GV_IMEWINDOW_UnPinSoftKB(HIGV_HANDLE handle);

/*
\brief 灵活设置输入法窗口和软键盘窗口的位置
\attention \n
无
\param[in]  handle    输入法窗口
\param[in]  isFlexible    灵活设置输入法窗口和软键盘窗口的位置的开关
\retval ::HI_SUCCESS 设置成功
\retval ::HI_ERR_LOST 句柄无效
\retval ::HI_ERR_INVAL 无效参数
\see \n
无
*/
HI_S32 HI_GV_IMEWINDOW_FlexibleSoftKB(HIGV_HANDLE handle, HI_BOOL isFlexible);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_IMEWINDOW_H */
