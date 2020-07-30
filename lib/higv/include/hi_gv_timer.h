/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020 All rights reserved.
 * Description: Time moudle API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_TIMER_H
#define HI_GV_TIMER_H

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/* * The timer Max number */
#define TIMER_MAX_NUM 0x40

/*
* brief Create timer.CNcomment:创建定时器
* param[in] widgetHandle Widget handle.CNcomment:窗口或控件句柄
* param[in] timerId Timer ID. CNcomment:定时器ID
* param[in] speed  Timer interval. CNcomment:定时器间隔，以ms为单位
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_EXIST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
* see ::HI_GV_Timer_Destroy
*/
HI_S32 HI_GV_Timer_Create(HIGV_HANDLE widgetHandle, HI_U32 timerId, HI_U32 speed);

/*
* brief Destory timer.CNcomment:销毁定时器
* param[in] widgetHandle Widget handle.CNcomment:窗口或控件句柄
* param[in] timerId Timer ID.CNcomment:定时器ID
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_NOOP Couldn't stop timer.CNcomment:不能停止定时器
* see ::HI_GV_Timer_Create
*/
HI_S32 HI_GV_Timer_Destroy(HIGV_HANDLE widgetHandle, HI_U32 timerId);

/*
* brief Start timer.CNcomment:启动定时器
* param[in] widgetHandle Widget handle. CNcomment:窗口或控件句柄
* param[in] timerId  Timer ID.CNcomment:定时器ID
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_NOOP CNcomment:调用定时器模块启动定时器失败
* see ::HI_GV_Timer_Stop
*/
HI_S32 HI_GV_Timer_Start(HIGV_HANDLE widgetHandle, HI_U32 timerId);

/*
* brief Stop timer.CNcomment:停止定时器
* param[in] widgetHandle Widget handle. CNcomment:窗口或控件句柄
* param[in] timerId  Timer ID.CNcomment:定时器ID
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_NOOP Couldn't stop timer.CNcomment:不能停止定时器
* see::HI_GV_Timer_Start
*/
HI_S32 HI_GV_Timer_Stop(HIGV_HANDLE widgetHandle, HI_U32 timerId);

/*
* brief Reset timer.CNcomment:复位定时器，定时器重现开始计时
* param[in] widgetHandle  Widget handle.CNcomment:窗口或控件句柄
* param[in] timerId  Timer ID.CNcomment:定时器ID
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_NOOP Couldn't stop timer. CNcomment:不能停止定时器
*/
HI_S32 HI_GV_Timer_Reset(HIGV_HANDLE widgetHandle, HI_U32 timerId);

/*
* brief Set timer speed.CNcomment:设置定时器速度
* param[in] widgetHandle  Widget handle.CNcomment:窗口或控件句柄
* param[in] timerId  Timer ID.CNcomment:定时器ID
* param[in] speed  Timer speed(unit: ms).CNcomment:定时器Speed (ms)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Timer_SetSpeed(HIGV_HANDLE widgetHandle, HI_U32 timerId, HI_U32 speed);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif /* HI_GV_TIMER_H */
