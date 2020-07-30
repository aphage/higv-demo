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

/* scroll direction ; CNcomment: �������� */
typedef enum {
    /* left scroll ; CNcomment: ����������� */
    HIGV_DIRECTION_LEFT = 0,
    /* right scroll ; CNcomment: �������ҹ��� */
    HIGV_DIRECTION_RIGHT,
    HIGV_DIRECTION_BUTT
} HIGV_DIRECTION_E;

/*
* brief Set content of scrolltext. CNcomment:���ù�����Ļ�ؼ��е�����
* param[in] scrollTextHandle Scrolltext handle.CNcomment:�ؼ����
* param[in] image Picture resouce ID.CNcomment:ͼƬ��ԴID��INVALID_RESIDΪ��ͼƬ
* param[in] string String.CNcomment:�ı��ַ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_ScrollText_GetContent
*/
HI_S32 HI_GV_ScrollText_SetContent(HIGV_HANDLE scrollTextHandle, HI_RESID image, HI_CHAR *string);

/*
* brief Set content of scrolltext.CNcomment:���ù�����Ļ�ؼ��е�����
* param[in] scrollTextHandle Scrolltext handle.CNcomment:�ؼ����
* param[in] image Picture resouce ID.CNcomment:ͼƬ��ԴID��INVALID_RESIDΪ��ͼƬ
* param[in] string String.CNcomment:�ı��ַ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_ScrollText_GetContent
*/
HI_S32 HI_GV_ScrollText_SetContentByID(HIGV_HANDLE scrollTextHandle, HI_RESID image, HI_U32 strID);

/*
* brief Get content of scrolltext.CNcomment:��ȡ������Ļ�ؼ�������
* param[in] scrollTextHandle Scrolltext handle.CNcomment:�ؼ����
* param[out] image Picture resouce ID.CNcomment:ͼƬ��ԴID
* param[out] string String.CNcomment:�ı�
* param[in] textBufLen String length.CNcomment:�ı�����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL  CNcomment:ָ��Ϊ�ջ��ı����ȳ�������ı�����
* see ::HI_GV_ScrollText_SetContent
*/
HI_S32 HI_GV_ScrollText_GetContent(HIGV_HANDLE scrollTextHandle, HI_RESID *image, HI_CHAR *string, HI_U32 textBufLen);

/*
* brief Set start position of scrolltext.CNcomment:����ͼƬ����ʼλ��
* param[in] scrollTextHandle  Scrolltext handle.CNcomment:�ؼ����
* param[in] x the x coordiate of picture.CNcomment:ͼƬ�ڿؼ��е�x����(����ڿؼ�ԭ�㣬Ĭ����Կؼ�����)
* param[in] y the y coordiate of picture.CNcomment:ͼƬ�ڿؼ��е�y����(����ڿؼ�ԭ�㣬Ĭ����Կؼ�����)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ScrollText_SetImagePos(HIGV_HANDLE scrollTextHandle, HI_S32 x, HI_S32 y);

/*
* brief Set start position of scrolltext.CNcomment:�����ı�����ʼλ��
* param[in] scrollTextHandle   Scrolltext handle.CNcomment:�ؼ����
* param[in] x the x coordiate of text.CNcomment:�ı��ڿؼ��е�x����(����ڿؼ�ԭ�㣬Ĭ����Կؼ�����)
* param[in] y the y coordiate of text.CNcomment:�ı��ڿؼ��е�y����(����ڿؼ�ԭ�㣬Ĭ����Կؼ�����)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ScrollText_SetTextPos(HIGV_HANDLE scrollTextHandle, HI_S32 x, HI_S32 y);

/*
* brief Set interval of scrolltext.CNcomment:���ÿؼ�������ʱ����
* param[in] scrollTextHandle Scrolltext handle.CNcomment:�ؼ����
* param[in] timeInterval Time interval.CNcomment:ʱ����(��msΪ��λ��Ĭ��Ϊ30ms)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ScrollText_SetTimeInterval(HIGV_HANDLE scrollTextHandle, HI_U32 timeInterval);

/*
* brief Set step of scrolltext.CNcomment:���ÿؼ���������
* param[in] scrollTextHandle CNcomment:�ؼ����
* param[in] step Scroll step.CNcomment:��������(��pixelΪ��λ��Ĭ��Ϊ5pixel)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ScrollText_SetStep(HIGV_HANDLE scrollTextHandle, HI_U32 step);

/*
* brief Set direction of scrolltext.CNcomment:���ù�������
* param[in] scrollTextHandle Scrolltext handle.CNcomment:�ؼ����
* param[in] direction Scroll direction.CNcomment:��������(Ĭ����������)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ScrollText_SetDirection(HIGV_HANDLE scrollTextHandle, HIGV_DIRECTION_E direction);

/*
* brief Set widget content.CNcomment:���ÿؼ�״̬
* param[in] scrollTextHandle Scrolltext handle.CNcomment:�ؼ����
* param[in] status The satus of scrolltext.CNcomment:�ؼ�״̬(TRUEΪ������FALSEΪֹͣ������Ĭ��ΪTRUE)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ScrollText_SetStatus(HIGV_HANDLE scrollTextHandle, HI_BOOL status);

/*
* brief Get the position of the content.CNcomment:��ȡ�ؼ����ݵ�ǰ���ڵ�λ��
* param[in] scrollTextHandle Scrolltext handle.CNcomment:�ؼ����
* param[out] x         x coordinate. CNcomment:x����
* param[out] y        y coordinate.  CNcomment:y����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ScrollText_GetCurPos(HIGV_HANDLE scrollTextHandle, HI_S32 *x, HI_S32 *y);

/*
* brief Reset  the position of the content.CNcomment:��λ�ؼ����ݵ�λ��
* param[in] scrollTextHandle Scrolltext handle.CNcomment:�ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ScrollText_ResetPos(HIGV_HANDLE scrollTextHandle);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_SCROLLTEXT_H */
