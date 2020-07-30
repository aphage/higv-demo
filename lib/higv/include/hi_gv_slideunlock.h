/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: slideunlock API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_SLIDEUNLOCK_H
#define HI_GV_SLIDEUNLOCK_H

#include "hi_gv_conf.h"
#ifdef HIGV_USE_WIDGET_SLIDEUNLOCK
/* add include here */
#include "hi_type.h"
#include "hi_go.h"
#include "hi_gv_resm.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SLIDEUNLOCK_LENGTH  40   /* <length of slideunlock ; CNcomment: 滑槽长度，相对值 */
#define SLIDEUNLOCK_DUATION 250 /* <kickback duation ; CNcomment: 回弹时间 */

typedef enum HI_SLIDEUNLOCK_STYLE {
    SLIDEUNLOCK_H = 0,  /* <Horizontal ; <CNcomment: 水平 */
    SLIDEUNLOCK_V,   /* <Vertical ; <CNcomment: 竖直 */
    SLIDEUNLOCK_BUT
} SLIDEUNLOCK_STYLE;

typedef enum hiHIGV_SLIDEUNLOCK_E { /*  SlideUnlock type ; CNcomment:  滑块控件种类 */
    HIGV_SLIDEUNLOCK_NORMAL = 0,
    HIGV_SLIDEUNLOCK_TOUCH,
    HIGV_SLIDEUNLOCK_DONE,
    HIGV_SLIDEUNLOCK_BUTT
} HIGV_SLIDEUNLOCK_E;

#define HIGV_SLIDEUNLOCK_H HIGV_STYLE_DEFINE(HIGV_WIDGET_SLIDEUNLOCK, SLIDEUNLOCK_H)
#define HIGV_SLIDEUNLOCK_V HIGV_STYLE_DEFINE(HIGV_WIDGET_SLIDEUNLOCK, SLIDEUNLOCK_V)

/*
* brief Set skin of trackbar. CNcomment:设置SlideUnlock滑杆的皮肤
* param[in] handleSlideUnlock SlideUnlock handle.CNcomment:handleSlideUnlock句柄
* param[in] handleRes    Picture resource ID.CNcomment:handleSlideUnlock图片资源ID
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_SlideUnlock_SetSliImage(HIGV_HANDLE handleSlideUnlock, HI_RESID handleRes);

/*
* brief Set the skin of slideblock.CNcomment:设置SlideUnlock滑块的皮肤
* param[in] handleSlideUnlock    SlideUnlock handle.CNcomment:handleSlideUnlock句柄
* param[in] handleSkinIndex  Skin index.CNcomment:handleSlideUnlock皮肤状态
* param[in] handleRes   Picture resource ID of handleSlideUnlock.CNcomment:handleSlideUnlock图片资源ID
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_SlideUnlock_SetTraImage(HIGV_HANDLE handleSlideUnlock, HI_U32 handleSkinIndex,
    HI_RESID handleRes);

/*
* brief Set status of slideunlock.CNcomment:设置SlideUnlock业务的使能状态
* param[in] handleSlideUnlock    SlideUnlock handle.CNcomment:handleSlideUnlock句柄
* param[in] isEnable    enable status.CNcomment:业务使能状态
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_SlideUnlock_SetStatus(HIGV_HANDLE handleSlideUnlock, HI_BOOL isEnable);

/*
* brief get status of slideunlock.CNcomment:获取SlideUnlock业务的使能状态
* param[in] handleSlideUnlock SlideUnlock handle.CNcomment:handleSlideUnlock句柄
* param[out] isEnable enable status pointer.CNcomment:业务使能指针
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_SlideUnlock_GetStatus(HIGV_HANDLE handleSlideUnlock, HI_U32 *isEnable);

/*
* brief back to init status.CNcomment:恢复到初始状态
* param[in] handleSlideUnlock SlideUnlock handle.CNcomment:handleSlideUnlock句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_SlideUnlock_ReSet(HIGV_HANDLE handleSlideUnlock);

#ifdef __cplusplus
}
#endif
#endif /* HI_GV_SLIDEUNLOCK_H */
#endif
