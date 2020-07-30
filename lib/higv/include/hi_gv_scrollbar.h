/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: Scrollbar API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_SCROOBAL_H
#define HI_GV_SCROOBAL_H

/* add include here */
#include "hi_gv_widget.h"

#ifdef HIGV_USE_WIDGET_SCROLLBAR

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    /* Vertical style ; CNcomment:  ��ֱ���ScrollBar */
    SCROLLBAR_STYLE_VERTICAL,
    /* Horizontal style ; CNcomment:  ˮƽ���ScrollBar */
    SCROLLBAR_STYLE_HORIZONTAL,
    SCROLLBAR_BUTT
} HIGV_SCROLLBAR_SYLE_E;

/*  Vertical  scrollbar ; CNcomment:��ֱ���ScrollBar */
#define HIGV_SCROLLBAR_STYLE_VERTICAL HIGV_STYLE_DEFINE(HIGV_WIDGET_SCROLLBAR, SCROLLBAR_STYLE_VERTICAL)
/*  Horizonal ScrollBar ; CNcomment: ˮƽ���ScrollBar */
#define HIGV_SCROLLBAR_STYLE_HORIZONTAL HIGV_STYLE_DEFINE(HIGV_WIDGET_SCROLLBAR, SCROLLBAR_STYLE_HORIZONTAL)

/*
* brief Set scrollbar infomation. CNcomment: ���û�����Ϣ
* attention :The offset of slide block is dicided by the height of left & top corner picture.
* CNcomment: ����ĳ�ʼƫ��λ������ScrollBar�ı���Ƥ�������Ͻ�ltopindexͼƬ�߶Ⱦ�����
* param[in] scrollBarHandle Scrollbar handle.CNcomment: ���������
* param[in] slideRes Resource information.CNcomment: ��Դ��Ϣ
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle.CNcomment: �����Ч
* retval ::HI_ERR_COMM_INVAL CNcomment: ��Ч����
*/
HI_S32 HI_GV_ScrollBar_SetSlideRes(HIGV_HANDLE scrollBarHandle, HI_RESID slideRes);

/*
* brief Set the position of slide block. CNcomment: ���û����λ��
* param[in] scrollBarHandle Scrollbar handle.CNcomment: ���������
* param[in] pos  Slide block position.CNcomment: �����λ�ã������Կ�����ʱ������Ч���ã�������0��ʼ��
* retval ::HI_SUCCESS SuccessCNcomment: �ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle.CNcomment: �����Ч
* retval ::HI_ERR_COMM_INVAL CNcomment: ��Ч����
* see ::HI_GV_ScrollBar_GetPos
*/
HI_S32 HI_GV_ScrollBar_SetPos(HIGV_HANDLE scrollBarHandle, HI_U32 pos);

/*
* brief Get the position of slide block. CNcomment: ��ȡ�����λ��
* param[in]  scrollBarHandle Scrollbar handle.CNcomment: ���������
* param[out] pos Position pointer. CNcomment: �����λ��ָ��
* retval ::HI_SUCCESS SuccessCNcomment: �ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle.CNcomment: �����Ч
* retval ::HI_ERR_COMM_INVAL Invalid paramater.CNcomment: ��Ч����
* see ::HI_GV_ScrollBar_SetPos
*/
HI_S32 HI_GV_ScrollBar_GetPos(HIGV_HANDLE scrollBarHandle, HI_U32 *pos);

/*
* brief Set the range of slide block. CNcomment: ���ù�����������Χ
* param[in] scrollBarHandle  Scrollbar handle.CNcomment: ���������
* param[in] scrollRange The range of slide block, CNcomment: ������������Χ
* retval ::HI_SUCCESS SuccessCNcomment: �ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle.CNcomment: �����Ч
*/
HI_S32 HI_GV_ScrollBar_SetScrollRange(HIGV_HANDLE scrollBarHandle, HI_U32 scrollRange);

/*
* brief Set the length of visual area. CNcomment: ���ÿɼ����򳤶�
* param[in] scrollBarHandle  Scrollbar handle.CNcomment: ���������
* param[in] len The length of visual area.CNcomment: �ؼ��ɼ�����ĳ���
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle.CNcomment: �����Ч
*/
HI_S32 HI_GV_ScrollBar_SetVisibleLen(HIGV_HANDLE scrollBarHandle, HI_U32 len);

/*
* brief Set the length of content.CNcomment: �������ݳ���
* param[in] scrollBarHandle  Scrollbar handle.CNcomment: ���������
* param[in] len CNcomment: �ؼ���Ч���ݳ��ȣ����������ú�ʱ��Ч
* retval ::HI_SUCCESS SuccessCNcomment: �ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle.CNcomment: �����Ч
*/
HI_S32 HI_GV_ScrollBar_SetContentLen(HIGV_HANDLE scrollBarHandle, HI_U32 len);

/*
* brief Set the picture resouce of the button which is pressed or normal state.CNcomment:
* ���ù��������°�ť�����Ͱ���״̬ͼƬ \attention \n This api is not support 9 pitchs style.
* The noraml state and pressed
* state will not effect at the same time. CNcomment:
* ����״̬�Ͱ���״̬�µ�ͼƬ������ͬʱ��Ч�����һ��״̬��Ч��
* ��һ��״̬��Ч������Ч��״̬����Ч��״̬ʹ��ͬһ��ͼƬ
* ͼƬ������һ���ţ���֧�־Ź�����ͼ��ʽ
* param[in] scrollBarHandle  Scrollbar handle.CNcomment: ���������
* param[in] upNormalImg Up arrow which is normal state.CNcomment: �ϰ�ť����״̬ͼƬ
* param[in] upPressImg Up arrow which is pressed picture..CNcomment: �ϰ�ť����״̬ͼƬ
* param[in] downNormalImg Down arrow which is normal picture.CNcomment: �°�ť����״̬ͼƬ
* param[in] downPressImg Down arrow which is pressed picture. CNcomment: �°�ť����״̬ͼƬ
* retval ::HI_SUCCESS SuccessCNcomment: �ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle.CNcomment: �����Ч
*/
HI_S32 HI_GV_ScrollBar_SetButtonImg(HIGV_HANDLE scrollBarHandle, HI_RESID upNormalImg, HI_RESID upPressImg,
                                    HI_RESID downNormalImg, HI_RESID downPressImg);

/*
* brief No paint  scrollbar when suspend on the container widget  and content length
* not above container widget length.
* CNcomment: ��ǰscrollbarΪ����״̬���Ұ󶨵Ŀؼ������ݵĳ���С�ڵ��ڿؼ��ĳ���ʱ��������scrollbar�ؼ�
* param[in] scrollBarHandle Scrollbar handle.CNcomment: ���������
* param[in] isSuspending  Is suspending status.CNcomment: ����״̬�Ƿ�����
* retval ::HI_SUCCESS SuccessCNcomment: �ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle.CNcomment: �����Ч
* retval ::HI_ERR_COMM_INVAL CNcomment: ��Ч����
*/
HI_S32 HI_GV_ScrollBar_SetStatus(HIGV_HANDLE scrollBarHandle, HI_BOOL isSuspending);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_SCROOBAL_H */
