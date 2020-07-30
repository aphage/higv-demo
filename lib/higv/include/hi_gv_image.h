/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: Image API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_IMAGE_H
#define HI_GV_IMAGE_H

#include "hi_type.h"
#include "hi_go.h"
#include "hi_gv_resm.h"

#ifdef HIGV_USE_WIDGET_IMAGE
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    HI_CHAR *pAddr; /*  Memory pointer address ; CNcomment: 内存指针地址  */
    HI_U32 Length; /*  Length ; CNcomment: 长度  */
} HI_GV_MemInfo;

/*
* brief Set image resource.CNcomment:设置图片资源
* param[in] imageHandle Image handle.CNcomment:控件句柄
* param[in] image The resource ID of image.CNcomment:图片资源ID
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Image_SetImage(HIGV_HANDLE imageHandle, HI_RESID image);

/*
* brief Draw surface image.CNcomment:绘制内存图片
* attention :
* User should call HI_GV_Image_FreeMemSurface to release before call this api.
* CNcomment:重复调用此函数前必须先调用HI_GV_Image_FreeMemSurface释放上一次图片surface
* 自动重绘控件
* param[in] imageHandle Image handle.CNcomment:控件句柄
* param[in] memInfo Memory infomation.CNcomment:内存数据
* param[in] imageHeight Image hegiht.CNcomment:设置解码图片高度
* param[in] imageWidth Image width.CNcomment:设置解码图片宽度
* param[in] srcRect Source rect.CNcomment:Image的源surface矩形区域,为NULL时绘制整张图片
* param[in] dstRect Destination rect.CNcomment:绘制到目标surface的矩形区域,为NULL时从控件坐标 0,0开始绘制
* param[in] blitOpt Bit block transfer operation.CNcomment:搬移混合操作运算属性
* param[in] transparent Transparent.CNcomment:是否透明皮肤,HI_TRUE 透明,HI_FALSE 不透明
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see :: HI_GV_Image_FreeMemSurface
*/
HI_S32 HI_GV_Image_DrawMemImage(HIGV_HANDLE imageHandle, HI_GV_MemInfo *memInfo, HI_U32 imageHeight, HI_U32 imageWidth,
                                HI_RECT *srcRect, HI_RECT *dstRect, HIGO_BLTOPT_S *blitOpt, HI_BOOL transparent);


/*
* brief Draw surface picture. CNcomment:绘制surface图片
* param[in] imageHandle Image handle.CNcomment:控件句柄
* param[in] handleSrcSurface Higo surface handle.CNcomment:HIGO surface句柄
* param[in] srcRect Source rect(null indicate full surface).CNcomment:surface的源矩形区域,
* 为NULL时绘制整个surface
* param[in] dstRect Destination rect(null indicate full surface).CNcomment:
* 绘制到image控件的矩形区域,为NULL时从控件坐标
* 0,0开始绘制 \param[in] blitOpt Bit block transfer operation.CNcomment:搬移混合操作运算属性
* \param[in] transparent
* transparent.CNcomment:是否透明皮肤,HI_TRUE 透明,HI_FALSE 不透明
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Image_DrawSurface(HIGV_HANDLE imageHandle, HIGV_HANDLE handleSrcSurface,
    HI_RECT *srcRect, HI_RECT *dstRect, HIGO_BLTOPT_S *blitOpt, HI_BOOL transparent);

/*
* brief Release the picture surface.CNcomment:释放内存图片的surface
* attention ::
* Release the surface when unload the resouce, and the widget
* will not redraw, so you should send repaint message to higv.
* CNcomment:卸载资源时控件内部同样释放surface
* 控件不重绘，如需重绘请发送绘制消息
* param[in] imageHandle Image handle.CNcomment:控件句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* see :: HI_GV_Image_DrawMemImage
*/
HI_S32 HI_GV_Image_FreeMemSurface(HIGV_HANDLE imageHandle);

/*
* brief Set bit block transfer operation.CNcomment:设置图片的搬移混合操作运算
* param[in] imageHandle Image handle.CNcomment:控件句柄
* param[in] blitOpt Bit block transfer operation.CNcomment:搬移混合操作运算属性
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Image_SetBlitOpt(HIGV_HANDLE imageHandle, HIGO_BLTOPT_S *blitOpt);

/*
* brief Get bit block transfer operation.CNcomment:获取图片的搬移混合操作运算
* param[in] imageHandle Image handle.CNcomment:控件句柄
* param[out] blitOpt Bit block transfer operation.CNcomment:搬移混合操作运算属性
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_NOTINIT
*/
HI_S32 HI_GV_Image_GetBlitOpt(HIGV_HANDLE imageHandle, HIGO_BLTOPT_S *blitOpt);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_IMAGE_H */
