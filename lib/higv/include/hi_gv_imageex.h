/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: ImageEx wdiget
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_IMAGEEX_H
#define HI_GV_IMAGEEX_H

/* add include here */
#include "hi_type.h"
#include "hi_gv_conf.h"

#ifdef HIGV_USE_WIDGET_IMAGEEX
#ifdef __cplusplus
extern "C" {
#endif

/*  Alignment of image , CNcomment:图片的对齐方式 */
typedef enum {
    /* Center ; CNcomment:居中 */
    HIGV_IMGPOS_CENTER,
    /* Stretch ; CNcomment:拉伸 */
    HIGV_IMGPOS_STRETCH,
    /* Autostrech ; CNcomment:自动拉伸 */
    HIGV_IMGPOS_AUTOSTRETCH,

    HIGV_IMGPOS_BUTT
} HIGV_IMGPOS_E;

/*
* brief Set the content.CNcomment:设置图片内容
* param[in] imageExHandle Imagex handle. CNcomment:图片控件句柄
* param[in] imgFile  The path file of image.CNcomment:图片文件路径
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_EXIST Timer is exist.CNcomment:定时器资源已经存在
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_ImageEx_SetImage(HIGV_HANDLE imageExHandle, const HI_CHAR *imgFile);

/*
* brief Set the count of playback cycles.CNcomment:设置动画图片播放次数
* param[in] imageExHandle Imagex handle. CNcomment:图片控件句柄
* param[in] repeatCount The count of playback cycles .CNcomment:动画图片播放次数
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_ImageEx_SetRepeatCount(HIGV_HANDLE imageExHandle, HI_S32 repeatCount);

/*
* brief Set the position of picture to the widget.CNcomment:设置图片在控件中的显示位置
* param[in] imageExHandle Imagex handle.CNcomment:图片控件句柄
* param[in] posType  Position type of picture.CNcomment:图片位置类型
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ImageEx_SetPos(HIGV_HANDLE imageExHandle, HIGV_IMGPOS_E posType);

/*
* brief Set the interval of image display.CNcomment:设置图片显示的时间间隔
* attention ::
* it is only valid to dynamic gif format.
* CNcomment:对动态GIF图片有效
* param[in] imageExHandle Imagex handle.CNcomment:图片控件句柄
* param[in] interval Interval of picture display.CNcomment:图片显示的时间间隔，以ms为单位
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ImageEx_SetInterval(HIGV_HANDLE imageExHandle, HI_U32 interval);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_IMAGEEX_H */
