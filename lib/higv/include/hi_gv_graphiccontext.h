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
* brief Destroy GraphicContext.CNcomment:���ٻ��ƻ���
* attention
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* HI_GV_GraphicContext_Destroy
*/
HI_S32 HI_GV_GraphicContext_Destroy(HIGV_HANDLE graphicContextHandle);

/*
* brief Begin draw,add the default clip rect .CNcomment:��ʼ���ƣ����Ĭ�ϵļ��о���
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_LOST
* see
* HI_GV_GraphicContext_End
*/
HI_S32 HI_GV_GraphicContext_Begin(HIGV_HANDLE graphicContextHandle);

/*
* brief End draw,empty clip rect.CNcomment:�������ƣ�ɾ�����о���
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* see : HI_GV_GraphicContext_Begin
*/
HI_S32 HI_GV_GraphicContext_End(HIGV_HANDLE graphicContextHandle);

/*
* brief Add clip rect.CNcomment:��Ӽ��о���
* Keep old clip rect,add new clip rect.CNcomment:����ԭ�м��о�����Ӿ���
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC���
* param[in] rect Clip rect.CNcomment:�������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_GraphicContext_AddClipRect(HIGV_HANDLE graphicContextHandle, const HI_RECT *rect);

/*
* brief Reset clip rect.CNcomment:������о���
* Clean old clip rect,reset new clip rect.CNcomment:ɾ��ԭ�м��о�������¾���
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC���
* param[in] rect Clip rect.CNcomment:�������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_GraphicContext_SetClipRect(HIGV_HANDLE graphicContextHandle, const HI_RECT *rect);

/*
* brief Decode a locale picture.CNcomment:���뱾��ͼƬ
* If imgWidth or imgHeight is 0,it indicates that the original picture attributes are retained.
* CNcomment:���������Ϊ�㣬ͼƬ��СΪĬ�ϴ�С
* param[in] fileName Picture path.CNcomment:ͼƬ·��
* param[in] imgWidth Image surface width.CNcomment:�����surface���
* param[in] imgHeight Image surface height.CNcomment:�����surface�߶�
* param[out] imgSurfaceHandle Image surface handle.CNcomment:�����õ�surface���
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
* brief Decode memory picture.CNcomment:�����ڴ�ͼƬ
* If imgWidth or imgHeight is 0,it indicates that the original picture attributes are retained.
* CNcomment:���������Ϊ�㣬ͼƬ��СΪĬ�ϴ�С
* param[in] addr The memory picture address.CNcomment:�ڴ�ͼƬ��ַ
* param[in] Lenth The memory lenth.CNcomment:�ڴ泤��
* param[in] imgWidth Image surface width.CNcomment:�����surface���
* param[in] imgHeight Image surface height.CNcomment:�����surface�߶�
* param[out] imgSurfaceHandle Image surface handle.CNcomment:�����õ�surface���
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
* brief Destroy image surface.CNcomment:�ͷŽ���ͼƬsurface
* param[in] imgSurface Image surface handle.CNcomment:ͼƬsurface���
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
* brief Set foreground color. CNcomment:����ǰ��ɫ
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC���
* param[in] foregroundColor Foreground color.CNcomment:ǰ��ɫ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_GraphicContext_SetFgColor(HIGV_HANDLE graphicContextHandle, HI_COLOR foregroundColor);

/*
* brief Set background color. CNcomment:���ñ���ɫ
* Set text background colorN/A.CNcomment:�������ֵı���ɫ
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC���
* param[in] backgroundColor text background color.CNcomment:���ֱ���ɫ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_GraphicContext_SetBgColor(HIGV_HANDLE graphicContextHandle, HI_COLOR backgroundColor);

/*
* brief Draw line .CNcomment:����
* The (startX,startY,endX,endY) >= 0 && < Widget width.
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC���
* param[in] startX,startY Start point.CNcomment:���
* param[in] endX,endY End point.CNcomment:�յ�
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
* brief Draw surface picture. CNcomment:����surfaceͼƬ
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC���
* param[in] dstRect Destination rect(null indicate full surface).CNcomment:���Ƶ�image�ؼ��ľ�������,ΪNULLʱ�ӿؼ�����
* 0,0��ʼ���� \param[in] imageHandle Image surface handle.CNcomment:��� \param[in] srcRect Source rect(null indicate full
* surface).CNcomment:surface��Դ��������,ΪNULLʱ��������surface \param[in] blitOpt Bit block transfer
* operation.CNcomment:���ƻ�ϲ�����������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_INVSIBLE
*/
HI_S32 HI_GV_GraphicContext_DrawImage(HIGV_HANDLE graphicContextHandle, HI_RECT *dstRect,
    HIGV_HANDLE imageHandle, HI_RECT *srcRect, HIGO_BLTOPT_S *blitOpt);

/*
* brief Draw string. CNcomment:�����ı�
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC���
* param[in] text String.CNcomment:�����ı�����
* param[in] rect Paint rect on the bind widget surface.CNcomment:�󶨿ؼ�surface�Ļ��ƾ���
* param[in] align Alignment of text.CNcomment:�ı����뷽ʽ
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
* brief Draw text by string ID. CNcomment:���ƶ������ִ�
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC���
* param[in] strID String ID.CNcomment:�������ִ�ID
* param[in] rect Paint rect on the bind widget surface.CNcomment:�󶨿ؼ�surface�Ļ��ƾ���
* param[in] align Alignment of text.CNcomment:�ı����뷽ʽ
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
* brief Set text font. CNcomment:�����ı�����
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC���
* param[in] fontHandle Font handle.CNcomment:������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_GraphicContext_SetFont(HIGV_HANDLE graphicContextHandle, HIGV_HANDLE fontHandle);

/*
* brief Fill rect. CNcomment:�������
* param[in] graphicContextHandle GraphicContext handle.CNcomment:GC���
* param[in] rect Fill rect on the bind widget surface.CNcomment:�ڰ�surface����������
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
