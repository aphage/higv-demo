/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: ScrollText API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_SCROLLTEXT_H
#define HI_GV_SCROLLTEXT_H

/* add include here */
#include "hi_type.h"
#include "hi_go.h"
#include "hi_gv_resm.h"
#include "hi_gv_conf.h"

#ifdef HIGV_USE_WIDGET_SCROLLTEXT

#ifdef __cplusplus
extern "C" {
#endif

#define ST_STYLE_ALWAYSSCROLL 0x4

#define HIGV_ST_STYLE_ALWAYSSCROLL HIGV_STYLE_DEFINE(HIGV_WIDGET_SCROLLTEXT, ST_STYLE_ALWAYSSCROLL)

/* scroll direction ; CNcomment: 滚动方向 */
typedef enum {
    /* left scroll ; CNcomment: 自右向左滚动 */
    HIGV_DIRECTION_LEFT = 0,
    /* right scroll ; CNcomment: 自左向右滚动 */
    HIGV_DIRECTION_RIGHT,
    HIGV_DIRECTION_BUTT
} HIGV_DIRECTION_E;

/*
* brief Set content of scrolltext. CNcomment:设置滚动字幕控件中的内容
* param[in] scrollTextHandle Scrolltext handle.CNcomment:控件句柄
* param[in] image Picture resouce ID.CNcomment:图片资源ID，INVALID_RESID为无图片
* param[in] string String.CNcomment:文本字符串
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_ScrollText_GetContent
*/
HI_S32 HI_GV_ScrollText_SetContent(HIGV_HANDLE scrollTextHandle, HI_RESID image, HI_CHAR *string);

/*
* brief Set content of scrolltext.CNcomment:设置滚动字幕控件中的内容
* param[in] scrollTextHandle Scrolltext handle.CNcomment:控件句柄
* param[in] image Picture resouce ID.CNcomment:图片资源ID，INVALID_RESID为无图片
* param[in] string String.CNcomment:文本字符串
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_ScrollText_GetContent
*/
HI_S32 HI_GV_ScrollText_SetContentByID(HIGV_HANDLE scrollTextHandle, HI_RESID image, HI_U32 strID);

/*
* brief Get content of scrolltext.CNcomment:获取滚动字幕控件的内容
* param[in] scrollTextHandle Scrolltext handle.CNcomment:控件句柄
* param[out] image Picture resouce ID.CNcomment:图片资源ID
* param[out] string String.CNcomment:文本
* param[in] textBufLen String length.CNcomment:文本长度
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL  CNcomment:指针为空或文本长度超出最大文本长度
* see ::HI_GV_ScrollText_SetContent
*/
HI_S32 HI_GV_ScrollText_GetContent(HIGV_HANDLE scrollTextHandle, HI_RESID *image, HI_CHAR *string, HI_U32 textBufLen);

/*
* brief Set start position of scrolltext.CNcomment:设置图片的起始位置
* param[in] scrollTextHandle  Scrolltext handle.CNcomment:控件句柄
* param[in] x the x coordiate of picture.CNcomment:图片在控件中的x坐标(相对于控件原点，默认相对控件居中)
* param[in] y the y coordiate of picture.CNcomment:图片在控件中的y坐标(相对于控件原点，默认相对控件居中)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ScrollText_SetImagePos(HIGV_HANDLE scrollTextHandle, HI_S32 x, HI_S32 y);

/*
* brief Set start position of scrolltext.CNcomment:设置文本的起始位置
* param[in] scrollTextHandle   Scrolltext handle.CNcomment:控件句柄
* param[in] x the x coordiate of text.CNcomment:文本在控件中的x坐标(相对于控件原点，默认相对控件居中)
* param[in] y the y coordiate of text.CNcomment:文本在控件中的y坐标(相对于控件原点，默认相对控件居中)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ScrollText_SetTextPos(HIGV_HANDLE scrollTextHandle, HI_S32 x, HI_S32 y);

/*
* brief Set interval of scrolltext.CNcomment:设置控件滚动的时间间隔
* param[in] scrollTextHandle Scrolltext handle.CNcomment:控件句柄
* param[in] timeInterval Time interval.CNcomment:时间间隔(以ms为单位，默认为30ms)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ScrollText_SetTimeInterval(HIGV_HANDLE scrollTextHandle, HI_U32 timeInterval);

/*
* brief Set step of scrolltext.CNcomment:设置控件滚动步长
* param[in] scrollTextHandle CNcomment:控件句柄
* param[in] step Scroll step.CNcomment:滚动步长(以pixel为单位，默认为5pixel)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ScrollText_SetStep(HIGV_HANDLE scrollTextHandle, HI_U32 step);

/*
* brief Set direction of scrolltext.CNcomment:设置滚动方向
* param[in] scrollTextHandle Scrolltext handle.CNcomment:控件句柄
* param[in] direction Scroll direction.CNcomment:滚动方向(默认自右向左)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ScrollText_SetDirection(HIGV_HANDLE scrollTextHandle, HIGV_DIRECTION_E direction);

/*
* brief Set widget content.CNcomment:设置控件状态
* param[in] scrollTextHandle Scrolltext handle.CNcomment:控件句柄
* param[in] status The satus of scrolltext.CNcomment:控件状态(TRUE为滚动，FALSE为停止滚动，默认为TRUE)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ScrollText_SetStatus(HIGV_HANDLE scrollTextHandle, HI_BOOL status);

/*
* brief Get the position of the content.CNcomment:获取控件内容当前所在的位置
* param[in] scrollTextHandle Scrolltext handle.CNcomment:控件句柄
* param[out] x         x coordinate. CNcomment:x坐标
* param[out] y        y coordinate.  CNcomment:y坐标
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ScrollText_GetCurPos(HIGV_HANDLE scrollTextHandle, HI_S32 *x, HI_S32 *y);

/*
* brief Reset  the position of the content.CNcomment:复位控件内容的位置
* param[in] scrollTextHandle Scrolltext handle.CNcomment:控件句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ScrollText_ResetPos(HIGV_HANDLE scrollTextHandle);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_SCROLLTEXT_H */
