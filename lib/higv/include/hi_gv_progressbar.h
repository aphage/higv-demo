/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: ProgressBar API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_PROGRESSBAR_H
#define HI_GV_PROGRESSBAR_H

/* add include here */
#include "hi_go_comm.h"
#include "hi_gv_conf.h"

#ifdef HIGV_USE_WIDGET_PROGRESSBAR
#ifdef __cplusplus
extern "C" {
#endif

/* the macro of horizontal style ; CNcomment: ��������� */
#define PROGRESSBAR_STYLE_HORIZON 0x1

/* the macro of vertical style ; CNcomment: ��������� */
#define PROGRESSBAR_STYLE_VERTICAL 0x2


/* Horizontal style ; CNcomment: ������������ */
#define HIGV_PROGRESSBAR_STYLE_HORIZON HIGV_STYLE_DEFINE(HIGV_WIDGET_PROGRESS, PROGRESSBAR_STYLE_HORIZON)

/* Vertical style ; CNcomment: ������������ */
#define HIGV_PROGRESSBAR_STYLE_VERTICAL HIGV_STYLE_DEFINE(HIGV_WIDGET_PROGRESS, PROGRESSBAR_STYLE_VERTICAL)

/*
* brief Set range of progressbar.CNcomment:���ý�������Χ
* param[in] progressBarHandle Progressbar handle.CNcomment:���������
* param[in] min    Min valude.CNcomment:��Сֵ
* param[in] max  Max value. CNcomment: ���ֵ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ProgressBar_SetRange(HIGV_HANDLE progressBarHandle, HI_U32 min, HI_U32 max);

/*
* brief Set step.CNcomment:���ò���
* param[in] progressBarHandle Progressbar handle.CNcomment:���������
* param[in] step   step.CNcomment:����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ProgressBar_SetStep(HIGV_HANDLE progressBarHandle, HI_U32 step);

/*
* brief Set the posithion of progressbar.CNcomment:���ý�������ǰλ��
* attention :If set pos out of the range, value will be min or max, return HI_SUCCESS.
* CNcomment:���ֵ������Χ����������Ϊ���ֵ����Сֵ�������سɹ�
* param[in] progressBarHandle Progressbar handle.CNcomment:���������
* param[in] pos    CNcomment:λ��
* retval ::HI_SUCCESS
* \retval ::HI_ERR_COMM_LOST
* see :: HI_GV_ProgressBar_GetPos
*/
HI_S32 HI_GV_ProgressBar_SetPos(HIGV_HANDLE progressBarHandle, HI_U32 pos);

/*
* brief Get the posithion of progressbar.CNcomment:��ȡ��������ǰλ��
* param[in] progressBarHandle Progressbar handle.CNcomment:���������
* param[out] pos  Position.CNcomment:λ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_ProgressBar_SetPos
*/
HI_S32 HI_GV_ProgressBar_GetPos(HIGV_HANDLE progressBarHandle, HI_U32 *pos);

/*
* brief Set the freground of progressbar.CNcomment:���ý�������ǰ�����
* param[in] progressBarHandle  Progressbar handle.CNcomment:���������
* param[in] fgRect The range of progress.CNcomment:������ǰ����ʾ�����Χ(��Խ�����λ��)
* Ϊ�ձ�ʾǰ����Χ��������������С��ͬ
* param[in] fgStyle   Fregroud style handle.CNcomment:�����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ProgressBar_SetFg(HIGV_HANDLE progressBarHandle, HI_RECT *fgRect, HI_RESID fgStyle);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_PROGRESSBAR_H */
