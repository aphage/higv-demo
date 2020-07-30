/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: Clock API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_CLOCK_H
#define HI_GV_CLOCK_H

/* add include here */
#include <time.h>
#include "hi_gv_widget.h"
#ifdef HIGV_USE_WIDGET_CLOCK
#ifdef __cplusplus
extern "C" {
#endif

typedef struct hiHIG_TIME_S {
    HI_U32 year; /* Year , CNcomment: 年 */
    HI_U32 month; /* Month , CNcomment: 月 */
    HI_U32 day; /* Day , CNcomment: 日 */
    HI_U32 week; /* Week , CNcomment: 周 */
    HI_U32 hour; /* Hour , CNcomment: 时 */
    HI_U32 minute; /* Minute, CNcomment: 分 */
    HI_U32 second; /* Second , CNcomment: 秒 */
} HIGV_TIME_S;

typedef enum {
    HIGV_CURSORRES_TYPE_COLOR = 0,
    HIGV_CURSORRES_TYPE_IMAGE = 1,
    HIGV_CURSORRES_TYPE_BUTT,
} HIGV_CURSORRES_TYPE_E;

typedef enum {
    HIGV_CLOCK_MODE_TEXT = 0,
    /* User set time infomation by text , CNcomment: 用户直接通过文本设置时间 */
    HIGV_CLOCK_MODE_FORMAT,
    /* User set time infomation by time format , CNcomment: 用户通过时间格式方式来显示时间 */
    HIGV_CLOCK_MODE_BUTT,
} HIGV_CLOCK_MODE_E;

typedef struct {
    HIGV_CLOCK_MODE_E
    DispMode; /* display mode ; CNcomment:clock控件是否具有显示和编辑功能 */
    HIGV_CURSORRES_TYPE_E
    CursorResType; /* The  cursor resource type ; CNcomment:编辑焦点的资源类型 */
    /* The resource ID of cursor ; CNcomment:clock可编辑窗口的资源ID ，图片或颜色 */
    HI_U32 CursorRes;
} HIGV_CLOCK_STYLE_S;

/*
* brief Init the clock.CNcomment:初始化clock控件
* param[in]  clockHandle Clock handle. CNcomment:控件句柄
* param[in]  style The style of clock when created. CNcomment:控件创建信息
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_EMPTY
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_Clock_Init(HIGV_HANDLE clockHandle, HIGV_CLOCK_STYLE_S *style);

/*
* brief Set the colon whether blink.CNcomment:设置时间控件低位的冒号是否闪烁
* param[in]  clockHandle Clock handle.CNcomment:控件句柄
* param[out] flash Whether blink.CNcomment:是否闪烁，HI_TRUE表示闪烁，HI_FALSE表示不闪烁
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Clock_SetFlash(HIGV_HANDLE clockHandle, HI_BOOL flash);

/*
* brief Set time unit of clock widget.CNcomment:设置时间控件的最小单位
* attention ::
* CNcomment:
* (1)"second"-秒，"minute"-分，"hour"-时，"day"-日，"week"-周，"month"-月，"year"-年
* (2)调用该接口会自动开启clock控件
* param[in]  clockHandle Clock handle. CNcomment:控件句柄
* param[out] unit  Time unit. CNcomment:已字符串表示的最小时间单位
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_EMPTY
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_Clock_SetTimeUnit(HIGV_HANDLE clockHandle, const HI_CHAR *unit);

/*
* brief Control the clock run state.CNcomment:控制时间控件开始或结束计时
* param[in]  clockHandle Clock handle. CNcomment:控件句柄
* param[out] run  Start or stop. CNcomment:时钟控件运行或停止
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_EMPTY  CNcomment:用户没有设置最小更新时间单位
*/
HI_S32 HI_GV_Clock_Run(HIGV_HANDLE clockHandle, HI_BOOL run);

/*
* brief Clear the content of clock.CNcomment:清除时钟控件的内容
* param[in]  clockHandle Clock handle.控件句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_EMPTY
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_Clock_ClearContent(HIGV_HANDLE clockHandle);

/*
* brief Set UTC time.CNcomment:设置Clock控件UTC时间
* param[in]  clockHandle Clock handle. CNcomment:控件句柄
* param[in]  t UTC. CNcomment:设置的UTC时间
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_EMPTY
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_Clock_SetUTC(HIGV_HANDLE clockHandle, time_t t);

/*
* brief Get UTC time.CNcomment:获取Clock控件UTC时间
* param[in]  clockHandle Clock handle. CNcomment:控件句柄
* param[out]  t The pointer of UTC. CNcomment:获取的UTC时间
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_EMPTY
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_Clock_GetUTC(HIGV_HANDLE clockHandle, time_t *t);

/*
* brief Set the item switch step.CNcomment:设置条目切换步长
* attention : Only support the year item.CNcomment:只对YEAR条目有效
* param[in]  clockHandle Clock handle. CNcomment:控件句柄
* param[in]  step The step of switch item. CNcomment:切换步长
* param[in]  interval The interval time of switch item CNcomment:间隔时间(Interval = 0, default:100ms)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_EMPTY
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_Clock_SetSwitchItemStep(HIGV_HANDLE clockHandle, HI_U32 step, HI_U32 interval);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_SPIN_H */
