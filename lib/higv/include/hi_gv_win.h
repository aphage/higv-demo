/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: Window API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_WIN_H
#define HI_GV_WIN_H

/* add include here */
#include "hi_type.h"
#include "hi_gv_conf.h"
#ifdef __cplusplus
extern "C" {
#endif

/*
* brief Set window opacity.CNcomment:设置窗口可见度
* param[in] windowHandle Window handle.CNcomment:窗口句柄
* param[in] opacity Window opacity.CNcomment:窗口可见度
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Win_SetOpacity(HIGV_HANDLE windowHandle, HI_U8 opacity);

/*
* brief Get first highlight child widget of widnow CNcomment:获取窗口第一个高亮的孩子句柄
* attention :This api is uded to get the hightlight widget for softkeyboard.
* CNcomment:主要是应用在软键盘上获取当前高亮控件
* param[in] windowHandle Window handle.CNcomment:窗口句柄
* param[out] handleHilghtChild Hightlight child.CNcomment:高亮孩子
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Win_GetHilightChild(HIGV_HANDLE windowHandle, HIGV_HANDLE *handleHilghtChild);

/*
* brief Reset all hightlight child and hightlight the first child.CNcomment:复位窗口中的高亮孩子，将窗口第一个子控件高亮
* attention:This API is used to redisplay the softkeyboard.
* CNcomment:主要是应用重新显示软键盘时复位软键盘
* param[in] windowHandle Window handle.CNcomment:窗口句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Win_ResetHilightChild(HIGV_HANDLE windowHandle);

/*
* brief Sync show win and get widget handle of done this show.CNcomment:同步显示window并获取结束显示的控件句柄
* attention:Return the second arg of HI_GV_Win_EndSyncShow.CNcomment:返回HI_GV_Win_EndSyncShow接口的第二个参数
* param[in] windowHandle Window handle.CNcomment:窗口句柄
* retval ::HIGV_HANDLE
* retval ::HI_FAILURE
* see : HI_GV_Win_EndSyncShow
*/
HI_S32 HI_GV_Win_SyncShow(HIGV_HANDLE windowHandle);

/*
* brief Done the sync show.CNcomment:结束窗口同步显示
* param[in] windowHandle Window handle.CNcomment:窗口句柄
* param[in] handleWidget Widget handle of end window sync show .CNcomment:结束同步显示时返回的控件句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_NOOP
* see : HI_GV_Win_SyncShow
*/
HI_S32 HI_GV_Win_EndSyncShow(HIGV_HANDLE windowHandle, HIGV_HANDLE handleWidget);

/*
* brief Get window level.CNcomment:获取窗口等级
* param[in] windowHandle Window handle.CNcomment:窗口句柄
* param[out] level Window level.CNcomment:传出的窗口等级
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Win_GetWinLevel(HIGV_HANDLE windowHandle, HI_U32 *level);

/*
* brief Advance window and child to load skin.CNcomment:加载窗口及其子控件的的皮肤
* attention : HIGV_STYLE_HIDE_UNLODRES style .CNcomment:当隐藏释放资源风格时有效
* param[in] windowHandle Window handle.CNcomment:窗口句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Win_LoadSkin(HIGV_HANDLE windowHandle);

#ifdef __cplusplus
}
#endif
#endif /* HI_GV_WIN_H */
