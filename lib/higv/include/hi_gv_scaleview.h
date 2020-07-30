/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: scaleView API
 * Author: HiMobileCam middleware develop team
 * Create: 2019-8-9
 */

#ifndef HI_GV_SCALE_VIEW_H
#define HI_GV_SCALE_VIEW_H
#include "hi_gv_widget.h"
#include "hi_type.h"
#include "hi_gv_conf.h"

#ifdef HIGV_USE_WIDGET_SCALEVIEW
/* add include here */
#include "hi_gv_resm.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct HIGV_SCALEVIEW_STYLE_S {
    HIGV_HANDLE dataModel; /* Data Model Handle ; CNcomment:  ����ģ�;�� */
    HI_U32 rowNum; /* The count of display item ; CNcomment: ��Ļ����ʾ������ */
    HI_U32 leftMargin; /* Left margin ; CNcomment:  ��߾� */
    HI_U32 rightMargin; /* Right margin ; CNcomment:  �ұ߾� */
    HI_U32 topMargin; /* Up margin ; CNcomment:  �ϱ߾� */
    HI_U32 bottomMargin; /* Bottom margin ; CNcomment:  �±߾� */
    HI_U32 imgDecIndex; /* imgDecIndex ; CNcomment:  ͼƬ������ */
    HI_U32 lineHeight;                 /*  ˮƽ�����߸߶� */
    HI_U32 lineWidth;                 /*  ˮƽ�����߿�� */
    HI_U32 lineDistance;                 /* ˮƽ�����ߵ���Ŀ���ݵľ��� */
    HI_U32 hlineColor; /* hlineColor ; CNcomment:  �����ߵ���ɫ */
    HI_U32 type;	    /* type ; CNcomment:  ��Ŀ���ݵ����� */
    HIGV_HANDLE scaleFont;	 /* scaleFont ; CNcomment:  ������  */
    HI_COLOR tapTxtColor; /* tapTxtColor ; CNcomment: ������ý����������ɫ */
    HI_DOUBLE sizeGrain; /* �����С�仯���� */
    HI_BOOL isNeedTransform;  /* �������Ŀ���Ƿ���Ҫת�� */
    HI_BOOL tapAutoMove;  /* �������Ŀ���Ƿ���Ҫ�Զ����� */
    HI_U32 imageSize;                 /*  ��Ԫ��ͼƬ�߶� */
    HI_DOUBLE imageSizeGrain;                 /*  ͼƬ��С�仯���� */
} HIGV_SCALEVIEW_STYLE;

/*
* brief Initiatlize the scaleview. CNcomment:ScaleView �ؼ���ʼ��
* attention : Set the head of ScaleView and row num.
* CNcomment:���ÿؼ��ı�ͷ(������)������
* param[in] handleScaleView   ScaleView handle. CNcomment:ScaleView�ؼ����
* param[in] creatInfo: widget info of ScaleView.CNcomment:�ؼ�������Ϣ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_SCALEVIEW_Create(const HIGV_WCREATE_S *creatInfo, HIGV_HANDLE *handleScaleView);

/*
\brief Set selected item of  ScaleView. CNcomment: ���� ScaleView������Ŀ
\attention \n
CNcomment:
\param[in] handleScaleView ScaleView handle. CNcomment: �ؼ����
\param[in] item  Item index.CNcomment: ��Ŀ���
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
::HI_GV_SCALEVIEW_SetSelItem
*/
HI_S32 HI_GV_SCALEVIEW_SetSelItem(HIGV_HANDLE handleScaleView, HI_U32 item);

/*
\brief Get the item of ScaleView.CNcomment: ��ȡScaleView������Ŀ
\attention \n
N/A.CNcomment:��
\param[in] handleScaleView  ScaleView handle.CNcomment: �ؼ����
\param[out] selItem Item index.CNcomment: ��Ŀ���
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL

\see \n
::HI_GV_SCALEVIEW_GetSelItem
*/
HI_S32 HI_GV_SCALEVIEW_GetSelItem(HIGV_HANDLE handleScaleView, HI_U32 *selItem);

/*
\brief Get the total item number of ScaleView.CNcomment: ��ȡScaleView����Դ������
\attention \n
N/A.CNcomment:��
\param[in]  handleScaleView  ScaleView handle. CNcomment:  �ؼ����
\param[out] itemNum Toal item number.CNcomment: ����Ŀ��
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:��
*/
HI_S32 HI_GV_SCALEVIEW_GetItemNum(HIGV_HANDLE handleScaleView, HI_U32 *itemNum);

/*
brief Get the item of ScaleView.CNcomment: ��ȡScaleView����tap������Ŀ
\attention \n
N/A.CNcomment:��
\param[in] handleScaleView  ScaleView handle.CNcomment: �ؼ����
\param[out] tapItem Item index.CNcomment: ��Ŀ���
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
::HI_GV_SCALEVIEW_GetTapItem
*/
HI_S32 HI_GV_SCALEVIEW_GetTapItem(HIGV_HANDLE handleScaleView, HI_U32 *tapItem);

/*
brief Get the item of ScaleView.CNcomment: ��ȡScaleView������Ŀ�仯�Ľ�����Ŀ���
\attention \n
N/A.CNcomment:��
\param[in] handleScaleView  ScaleView handle.CNcomment: �ؼ����
\param[out] itemNum Item index.CNcomment: ��Ŀ���
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
::HI_GV_SCALEVIEW_GetFoucItem
*/
HI_S32 HI_GV_SCALEVIEW_GetFoucItem(HIGV_HANDLE handleScaleView, HI_U32 *itemNum);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_SCALEVIEW_H */
