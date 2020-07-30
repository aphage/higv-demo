/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2014-2020. All rights reserved.
 * Description: graphiccontext moudle API
 * Author: HiMobileCam middleware develop team
 * Create: 2014-12-23
*/

#ifndef HI_GV_GRAPHICCONTEXT_H
#define HI_GV_GRAPHICCONTEXT_H
#include "hi_type.h"
#include "hi_go.h"
#include "hi_gv_conf.h"


#ifdef __cplusplus
extern "C" {
#endif

HI_S32 HI_GV_GraphicContext_Create(HIGV_HANDLE widgetHandle, HIGV_HANDLE *graphicContextHandle);

/*
* brief Destroy GraphicContext.CNcomment:销毁绘制环境
* attention
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* HI_GV_GraphicContext_Destroy
*/
HI_S32 HI_GV_GraphicContext_Destroy(HIGV_HANDLE graphicContextHandle);

/*
* brief Begin draw,add the default clip rect .CNcomment:开始绘制，添加默认的剪切矩形
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_LOST
* see
* HI_GV_GraphicContext_End
*/
HI_S32 HI_GV_GraphicContext_Begin(HIGV_HANDLE graphicContextHandle);

/*
* brief End draw,empty clip rect.CNcomment:结束绘制，删除剪切矩形
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* see : HI_GV_GraphicContext_Begin
*/
HI_S32 HI_GV_GraphicContext_End(HIGV_HANDLE graphicContextHandle);

/*
* brief Add clip rect.CNcomment:添加剪切矩形
* Keep old clip rect,add new clip rect.CNcomment:保持原有剪切矩形添加矩形
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC句柄
* param[in] rect Clip rect.CNcomment:传入矩形
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_GraphicContext_AddClipRect(HIGV_HANDLE graphicContextHandle, const HI_RECT *rect);

/*
* brief Reset clip rect.CNcomment:重设剪切矩形
* Clean old clip rect,reset new clip rect.CNcomment:删除原有剪切矩形添加新矩形
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC句柄
* param[in] rect Clip rect.CNcomment:传入矩形
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_GraphicContext_SetClipRect(HIGV_HANDLE graphicContextHandle, const HI_RECT *rect);

/*
* brief Decode a locale picture.CNcomment:解码本地图片
* If imgWidth or imgHeight is 0,it indicates that the original picture attributes are retained.
* CNcomment:如果带入宽高为零，图片大小为默认大小
* param[in] fileName Picture path.CNcomment:图片路径
* param[in] imgWidth Image surface width.CNcomment:解码后surface宽度
* param[in] imgHeight Image surface height.CNcomment:解码后surface高度
* param[out] imgSurfaceHandle Image surface handle.CNcomment:解码获得的surface句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_LOST
* retval ::HIGO_ERR_NULLPTR
* retval ::HI_FAILURE
* retval ::HI_NULL
* retval ::HIGO_ERR_INVIMGDATA
* see::
* hi_go_decoder.h
* HI_GV_GraphicContext_FreeImageSurface
*/
HI_S32 HI_GV_GraphicContext_DecodeImg(const HI_CHAR *fileName, HI_U32 imgWidth, HI_U32 imgHeight,
    HIGV_HANDLE *imgSurfaceHandle);

/*
* brief Decode memory picture.CNcomment:解码内存图片
* If imgWidth or imgHeight is 0,it indicates that the original picture attributes are retained.
* CNcomment:如果带入宽高为零，图片大小为默认大小
* param[in] addr The memory picture address.CNcomment:内存图片地址
* param[in] Lenth The memory lenth.CNcomment:内存长度
* param[in] imgWidth Image surface width.CNcomment:解码后surface宽度
* param[in] imgHeight Image surface height.CNcomment:解码后surface高度
* param[out] imgSurfaceHandle Image surface handle.CNcomment:解码获得的surface句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_LOST
* retval ::HIGO_ERR_NULLPTR
* retval ::HI_FAILURE
* retval ::HI_NULL
* retval ::HIGO_ERR_INVIMGDATA
* see::
* hi_go_decoder.h
* HI_GV_GraphicContext_FreeImageSurface
*/
HI_S32 HI_GV_GraphicContext_DecodeMemImg(HI_CHAR *addr, HI_U32 Length, HI_U32 imgWidth, HI_U32 imgHeight,
    HIGV_HANDLE *imgSurfaceHandle);

/*
* brief Destroy image surface.CNcomment:释放解码图片surface
* param[in] imgSurface Image surface handle.CNcomment:图片surface句柄
* retval ::HI_SUCCESS
* retval ::HIGO_ERR_NOTINIT
* retval ::HIGO_ERR_INVHANDLE
* retval ::HIGO_ERR_INUSE
* see ::
* HI_GV_GraphicContext_DecodeImg
* HI_GV_GraphicContext_DecodeMemImg
*/
HI_S32 HI_GV_GraphicContext_FreeImageSurface(HIGV_HANDLE imgSurface);

/*
* brief Set foreground color. CNcomment:设置前景色
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC句柄
* param[in] foregroundColor Foreground color.CNcomment:前景色
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_GraphicContext_SetFgColor(HIGV_HANDLE graphicContextHandle, HI_COLOR foregroundColor);

/*
* brief Set background color. CNcomment:设置背景色
* Set text background colorN/A.CNcomment:设置文字的背景色
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC句柄
* param[in] backgroundColor text background color.CNcomment:文字背景色
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_GraphicContext_SetBgColor(HIGV_HANDLE graphicContextHandle, HI_COLOR backgroundColor);

/*
* brief Draw line .CNcomment:画线
* The (startX,startY,endX,endY) >= 0 && < Widget width.
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC句柄
* param[in] startX,startY Start point.CNcomment:起点
* param[in] endX,endY End point.CNcomment:终点
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_INVSIBLE
* retval ::HIGO_ERR_UNSUPPORTED
* retval ::HIGO_ERR_INVPIXELFMT
* retval ::HIGO_ERR_DEPEND_TDE
*/
HI_S32 HI_GV_GraphicContext_DrawLine(HIGV_HANDLE graphicContextHandle, HI_U32 startX, HI_U32 startY,
    HI_U32 endX, HI_U32 endY, HI_U32 width);

/*
* brief Draw surface picture. CNcomment:绘制surface图片
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC句柄
* param[in] dstRect Destination rect(null indicate full surface).CNcomment:绘制到image控件的矩形区域,为NULL时从控件坐标
* 0,0开始绘制 \param[in] imageHandle Image surface handle.CNcomment:句柄 \param[in] srcRect Source rect(null indicate full
* surface).CNcomment:surface的源矩形区域,为NULL时绘制整个surface \param[in] blitOpt Bit block transfer
* operation.CNcomment:搬移混合操作运算属性
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_INVSIBLE
*/
HI_S32 HI_GV_GraphicContext_DrawImage(HIGV_HANDLE graphicContextHandle, HI_RECT *dstRect,
    HIGV_HANDLE imageHandle, HI_RECT *srcRect, HIGO_BLTOPT_S *blitOpt);

/*
* brief Draw string. CNcomment:绘制文本
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC句柄
* param[in] text String.CNcomment:绘制文本内容
* param[in] rect Paint rect on the bind widget surface.CNcomment:绑定控件surface的绘制矩形
* param[in] align Alignment of text.CNcomment:文本对齐方式
* HIGV_ALIGN_RIGHT
* HIGV_ALIGN_HCENTER
* HIGV_ALIGN_TOP
* HIGV_ALIGN_BOTTOM
* HIGV_ALIGN_VCENTER
* HIGV_ALIGN_WRAP
* HIGV_ALIGN_WORDELLIPSIS
* HIGV_ALIGN_FORCE_LEFT
* HIGV_ALIGN_FORCE_RIGHT
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_INVSIBLE
* retval ::HIGO_ERR_NULLPTR
*/
HI_S32 HI_GV_GraphicContext_DrawText(HIGV_HANDLE graphicContextHandle, const HI_CHAR *text,
    const HI_RECT *rect, HI_U32 align);

/*
* brief Draw text by string ID. CNcomment:绘制多语言字串
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC句柄
* param[in] strID String ID.CNcomment:多语言字串ID
* param[in] rect Paint rect on the bind widget surface.CNcomment:绑定控件surface的绘制矩形
* param[in] align Alignment of text.CNcomment:文本对齐方式
* HIGV_ALIGN_RIGHT
* HIGV_ALIGN_HCENTER
* HIGV_ALIGN_TOP
* HIGV_ALIGN_BOTTOM
* HIGV_ALIGN_VCENTER
* HIGV_ALIGN_WRAP
* HIGV_ALIGN_WORDELLIPSIS
* HIGV_ALIGN_FORCE_LEFT
* HIGV_ALIGN_FORCE_RIGHT
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_INVSIBLE
* retval ::HIGO_ERR_NULLPTR
*/
HI_S32 HI_GV_GraphicContext_DrawTextByID(HIGV_HANDLE graphicContextHandle, const HI_U32 strID,
    const HI_RECT *rect, HI_U32 align);

/*
* brief Set text font. CNcomment:设置文本字体
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC句柄
* param[in] fontHandle Font handle.CNcomment:字体句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_GraphicContext_SetFont(HIGV_HANDLE graphicContextHandle, HIGV_HANDLE fontHandle);

/*
* brief Fill rect. CNcomment:填充区域
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC句柄
* param[in] rect Fill rect on the bind widget surface.CNcomment:在绑定surface上填充的区域
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_INVSIBLE
* see :: HI_GV_GraphicContext_SetBgColor
*/
HI_S32 HI_GV_GraphicContext_FillRect(HIGV_HANDLE graphicContextHandle, const HI_RECT *rect);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* HI_GV_GRAPHICCONTEXT_H */
