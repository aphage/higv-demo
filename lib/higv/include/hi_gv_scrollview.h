/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: ScrollView API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_SCROLLVIEW_H
#define HI_GV_SCROLLVIEW_H

/* add include here */
#include "hi_gv_widget.h"
#ifdef HIGV_USE_WIDGET_SCROLLVIEW
#ifdef __cplusplus
extern "C" {
#endif

/* NOTE: It is only valid for touch operation or mouse wheel operation */
typedef enum {
    SCROLLVIEW_DIRECTION_HORI = 0,  /* Horizal direction ; CNcomment: ˮƽ�������� */
    SCROLLVIEW_DIRECTION_VERT,  /* Vertial direction ; CNcomment:��ֱ�������� */
    SCROLLVIEW_DIRECTION_BUTT
} HIGV_SCROLLVIEW_DIRECTION_E;

typedef enum {
    SCROLLVIEW_STYLE_DEFAULTE = 0x00,
    SCROLLVIEW_STYLE_ALWAY_CENTER = 0x01,
    SCROLLVIEW_STYLE_BUTT = 0x10000
} HIGV_SCROLLVIEW_STYLE_E;

typedef struct hiHIGV_SCROLLVIEW_Init_S {
    HIGV_HANDLE hVerticalScrollBar; /* Bind vertical scrollbar handle; CNcomment: �󶨵Ĵ�ֱ��������� */
    HIGV_HANDLE hHorizontalScrollbar; /* Bind horizontal scrollbar handle ; CNcomment: �󶨵�ˮƽ��������� */
    HI_U32 LeftMargin; /* Invalid value ; CNcomment: ��ǰ�汾��Ч */
    HI_U32 RightMargin; /* Child widget right margin of background ; CNcomment: ���ӿؼ��ڱ������ұ߾� */
    HI_U32 TopMargin; /* Invalid value ; CNcomment: ��ǰ�汾��Ч */
    HI_U32 BottomMargin; /* Child widget bottom margin of background ; CNcomment: ���ӿؼ��ڱ����ĵױ߾� */
    HI_U32 Step; /* Scroll step ; CNcomment: �������� */
    HI_U32 Interval; /* Scroll interval ; CNcomment: ������� */
    HI_U32 ScrollContentWidth; /* The scroll content invariable width ; CNcomment: �������ݵĹ̶���� */
    HI_U32 ScrollContentHeight; /* The scroll content invariable height ; CNcomment: �������ݵĹ̶��߶� */
    HI_U32 ScrollViewStyle; /* Scroll view private style ; CNcomment: ˽�з�� */
    HIGV_SCROLLVIEW_DIRECTION_E Direction; /* Scroll direction ; CNcomment: �������� */
} HIGV_SCROLLVIEW_Init_S;

/*
* brief Init the scrollview.CNcomment:��ʼ��scrollview�ؼ�
* param[in]  scrollViewHandle Scroll view handle. CNcomment:�ؼ����
* param[in]  initAttr The info of scrollview when created. CNcomment:�ؼ�������Ϣ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_EXIST
*/
HI_S32 HI_GV_ScrollView_Init(HIGV_HANDLE scrollViewHandle, HIGV_SCROLLVIEW_Init_S *initAttr);

/*
* brief Set content invariable size.CNcomment:�������ݵĹ̶���С
* param[in]  scrollViewHandle Scroll view handle. CNcomment:�ؼ����
* param[in]  width The invariable width. CNcomment:�̶���ȣ���Χ����ڵ��ڿؼ��Ŀ��
* param[in]  height The invariable height. CNcomment:�̶��߶ȣ���Χ����ڵ��ڿؼ��ĸ߶�
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_PAERM
*/
HI_S32 HI_GV_ScrollView_SetContentSize(HIGV_HANDLE scrollViewHandle, HI_U32 width, HI_U32 height);

/*
* brief Move the view to center.CNcomment:���ӿ���������
* param[in]  scrollViewHandle scroll view handle. CNcomment:�ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_ScrollView_MoveToCenter(HIGV_HANDLE scrollViewHandle);

/*
* brief Get the content rectangle.CNcomment:��ȡ���ݵľ���
* param[in]  scrollViewHandle Scroll view handle. CNcomment:�ؼ����
* param[out] rect Rectangle. CNcomment:�����������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollView_GetContentRect(HIGV_HANDLE scrollViewHandle, HI_RECT *rect);

/*
* brief Get the view coordinate in the background content.CNcomment:��ȡ�ӿ�������ݵ�����
* attention \n
     _____________________
    |  background content |
    |        ____         |
    |       |view|        |
    |       |____|        |
    |_____________________|
* param[in]  scrollViewHandle Scroll view handle. CNcomment:�ؼ����
* param[out] cordX X abscissa. CNcomment:x����
* param[out] cordY Y abscissa. CNcomment:y����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollView_GetViewCoordinate(HIGV_HANDLE scrollViewHandle, HIGV_CORD *cordX, HIGV_CORD *cordY);

/*
* brief Set the view coordinate in the background content.CNcomment:�����ӿ�������ݵ�����
* param[in]  scrollViewHandle Scroll view handle. CNcomment:�ؼ����
* param[out] cordX X abscissa. CNcomment:x����
* param[out] cordY Y abscissa. CNcomment:y����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollView_SetViewCoordinate(HIGV_HANDLE scrollViewHandle, HIGV_CORD cordX, HIGV_CORD cordY);

/*
* brief Set scroll step.CNcomment:���ù�������
* param[in]  scrollViewHandle Scroll view handle. CNcomment:�ؼ����
* param[in]  step Scroll step.CNcomment:��������(��pixelΪ��λ��Ĭ��Ϊ20pixel)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollView_SetStep(HIGV_HANDLE scrollViewHandle, HI_U32 step);

/*
* brief Set scroll Interval.CNcomment:���ù������
* param[in]  scrollViewHandle Scroll view handle. CNcomment:�ؼ����
* param[in]  interval Interval. CNcomment:���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollView_SetInterval(HIGV_HANDLE scrollViewHandle, HI_U32 interval);

/*
* brief Bind the scrollbar to scrollbar.CNcomment:�󶨹�����
* param[in]  scrollViewHandle Scroll view handle. CNcomment:�ؼ����
* param[in]  handleVertical vertical scrollbar. CNcomment:��ֱ������
* param[in]  handleHorizontal horizontal scrollbar. CNcomment:ˮƽ������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollView_BindScrollBar(HIGV_HANDLE scrollViewHandle, HIGV_HANDLE handleVertical,
    HIGV_HANDLE handleHorizontal);

/*
* brief Check the focus widget in the view.CNcomment:���ȷ������ؼ����ӿ���
* param[in]  scrollViewHandle Scroll view handle. CNcomment:�ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollView_CheckFocusPos(HIGV_HANDLE scrollViewHandle);

/*
* brief Set scroll sensibility.CNcomment: ���û���������������ϵ����Ĭ����1.0
* param[in]  scrollViewHandle Scroll view handle. CNcomment:�ؼ����
* param[in]  scrollParam scroll sensibility param. CNcomment:����������ϵ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollView_SetScrollParam(HIGV_HANDLE scrollViewHandle, HI_FLOAT scrollParam);

/*
* brief Set fling sensibility.CNcomment:������ɨ������������ϵ����Ĭ����1.0
* param[in]  scrollViewHandle Scroll view handle. CNcomment:�ؼ����
* param[in]  flingParam fling sensibility param. CNcomment:��ɨ������ϵ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollView_SetFlingParam(HIGV_HANDLE scrollViewHandle, HI_FLOAT flingParam);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_SCROLLVIEW_H */
