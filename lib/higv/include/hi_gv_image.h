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
    HI_CHAR *pAddr; /*  Memory pointer address ; CNcomment: �ڴ�ָ���ַ  */
    HI_U32 Length; /*  Length ; CNcomment: ����  */
} HI_GV_MemInfo;

/*
* brief Set image resource.CNcomment:����ͼƬ��Դ
* param[in] imageHandle Image handle.CNcomment:�ؼ����
* param[in] image The resource ID of image.CNcomment:ͼƬ��ԴID
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Image_SetImage(HIGV_HANDLE imageHandle, HI_RESID image);

/*
* brief Draw surface image.CNcomment:�����ڴ�ͼƬ
* attention :
* User should call HI_GV_Image_FreeMemSurface to release before call this api.
* CNcomment:�ظ����ô˺���ǰ�����ȵ���HI_GV_Image_FreeMemSurface�ͷ���һ��ͼƬsurface
* �Զ��ػ�ؼ�
* param[in] imageHandle Image handle.CNcomment:�ؼ����
* param[in] memInfo Memory infomation.CNcomment:�ڴ�����
* param[in] imageHeight Image hegiht.CNcomment:���ý���ͼƬ�߶�
* param[in] imageWidth Image width.CNcomment:���ý���ͼƬ���
* param[in] srcRect Source rect.CNcomment:Image��Դsurface��������,ΪNULLʱ��������ͼƬ
* param[in] dstRect Destination rect.CNcomment:���Ƶ�Ŀ��surface�ľ�������,ΪNULLʱ�ӿؼ����� 0,0��ʼ����
* param[in] blitOpt Bit block transfer operation.CNcomment:���ƻ�ϲ�����������
* param[in] transparent Transparent.CNcomment:�Ƿ�͸��Ƥ��,HI_TRUE ͸��,HI_FALSE ��͸��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see :: HI_GV_Image_FreeMemSurface
*/
HI_S32 HI_GV_Image_DrawMemImage(HIGV_HANDLE imageHandle, HI_GV_MemInfo *memInfo, HI_U32 imageHeight, HI_U32 imageWidth,
                                HI_RECT *srcRect, HI_RECT *dstRect, HIGO_BLTOPT_S *blitOpt, HI_BOOL transparent);


/*
* brief Draw surface picture. CNcomment:����surfaceͼƬ
* param[in] imageHandle Image handle.CNcomment:�ؼ����
* param[in] handleSrcSurface Higo surface handle.CNcomment:HIGO surface���
* param[in] srcRect Source rect(null indicate full surface).CNcomment:surface��Դ��������,
* ΪNULLʱ��������surface
* param[in] dstRect Destination rect(null indicate full surface).CNcomment:
* ���Ƶ�image�ؼ��ľ�������,ΪNULLʱ�ӿؼ�����
* 0,0��ʼ���� \param[in] blitOpt Bit block transfer operation.CNcomment:���ƻ�ϲ�����������
* \param[in] transparent
* transparent.CNcomment:�Ƿ�͸��Ƥ��,HI_TRUE ͸��,HI_FALSE ��͸��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Image_DrawSurface(HIGV_HANDLE imageHandle, HIGV_HANDLE handleSrcSurface,
    HI_RECT *srcRect, HI_RECT *dstRect, HIGO_BLTOPT_S *blitOpt, HI_BOOL transparent);

/*
* brief Release the picture surface.CNcomment:�ͷ��ڴ�ͼƬ��surface
* attention ::
* Release the surface when unload the resouce, and the widget
* will not redraw, so you should send repaint message to higv.
* CNcomment:ж����Դʱ�ؼ��ڲ�ͬ���ͷ�surface
* �ؼ����ػ棬�����ػ��뷢�ͻ�����Ϣ
* param[in] imageHandle Image handle.CNcomment:�ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* see :: HI_GV_Image_DrawMemImage
*/
HI_S32 HI_GV_Image_FreeMemSurface(HIGV_HANDLE imageHandle);

/*
* brief Set bit block transfer operation.CNcomment:����ͼƬ�İ��ƻ�ϲ�������
* param[in] imageHandle Image handle.CNcomment:�ؼ����
* param[in] blitOpt Bit block transfer operation.CNcomment:���ƻ�ϲ�����������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Image_SetBlitOpt(HIGV_HANDLE imageHandle, HIGO_BLTOPT_S *blitOpt);

/*
* brief Get bit block transfer operation.CNcomment:��ȡͼƬ�İ��ƻ�ϲ�������
* param[in] imageHandle Image handle.CNcomment:�ؼ����
* param[out] blitOpt Bit block transfer operation.CNcomment:���ƻ�ϲ�����������
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
