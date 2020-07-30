/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: wheelview API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_WHEELVIEW_H
#define HI_GV_WHEELVIEW_H
#include "hi_type.h"
#include "hi_gv_conf.h"
#include "hi_gv_widget.h"

#ifdef HIGV_USE_WIDGET_WHEELVIEW
/* add include here */
#include "hi_gv_resm.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    HI_U32 rowNum; /* The count of display item ; CNcomment: ��Ļ����ʾ������ */
    HIGV_HANDLE dataModel; /* Data Model Handle ; CNcomment:  ����ģ�;�� */
    HIGV_HANDLE upCoverSkin; /* Up Cover Skin ; CNcomment: �ϸ���Ƥ����� */
    HIGV_HANDLE downCoverSkin; /* Down Cover Skin; CNcomment: �¸���Ƥ����� */
    HI_BOOL isCircleScroll; /* Circle tag ; CNcomment: ѭ��������־ */
    HI_FLOAT scrollParam; /* Scroll Param ; CNcomment: ����������ϵ�� */
    HI_FLOAT flingParam; /* Fling Param ; CNcomment: ��ɨ������ϵ�� */
    HI_U32 leftMargin; /* Left margin ; CNcomment:  ��߾� */
    HI_U32 rightMargin; /* Right margin ; CNcomment:  �ұ߾� */
    HI_U32 topMargin; /* Up margin ; CNcomment:  �ϱ߾� */
    HI_U32 btmMargin; /* Bottom margin ; CNcomment:  �±߾� */
} HigvWheelViewStyle;

/*
* brief Create wheelview.CNcomment:WheelView�ؼ���ʼ��
* param[in] creatInfo    The Layout infomation of wheelview. CNcomment:�ؼ���񲼾�����ָ��
* param[out] wheelViewHandle   the pointer of wheelview handle. CNcomment:WheelView�ؼ����ָ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_INVA
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_WheelView_Create(const HIGV_WCREATE_S *creatInfo, HIGV_HANDLE *wheelViewHandle);

/*
* brief Set selected item of  wheelview. CNcomment: ���� WheelView��ǰ��Ŀ
* param[in] wheelViewHandle WheelView handle. CNcomment: �ؼ����
* param[in] item  Item index.CNcomment: ��Ŀ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_WheelView_GetSelItem
*/
HI_S32 HI_GV_WheelView_SetSelItem(HIGV_HANDLE wheelViewHandle, HI_U32 item);

/*
* brief Get the item of WheelView.CNcomment: ��ȡWheelView��ǰ��Ŀ
* param[in] wheelViewHandle  WheelView handle.CNcomment: �ؼ����
* param[out] item Item index.CNcomment: ��Ŀ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_WheelView_SetSelItem
*/
HI_S32 HI_GV_WheelView_GetSelItem(HIGV_HANDLE wheelViewHandle, HI_U32 *item);

/*
* brief Get the total item number of WheelView.CNcomment: ��ȡWheelView��ǰ����������
* param[in]  wheelViewHandle  WheelView handle. CNcomment:  �ؼ����
* param[out] itemNum Toal item number.CNcomment: ����Ŀ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_GetItemNum(HIGV_HANDLE wheelViewHandle, HI_U32 *itemNum);

/*
* brief Set up image resource.CNcomment:�������ڵ�Ƥ����Դ
* param[in] wheelViewHandle Image handle.CNcomment:�ؼ����
* param[in] handleRes The resource ID of image.CNcomment:ͼƬ��Դ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_SetUpImage(HIGV_HANDLE wheelViewHandle, HI_RESID handleRes);

/*
* brief Set up image resource.CNcomment:�������ڵ�Ƥ����Դ
* param[in] wheelViewHandle Image handle.CNcomment:�ؼ����
* param[in] handleRes The resource ID of image.CNcomment:ͼƬ��Դ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_SetDownImage(HIGV_HANDLE wheelViewHandle, HI_RESID handleRes);

/*
* brief Enable wheelview touch.CNcomment:��������������
* param[in] wheelViewHandle Image handle.CNcomment:�ؼ����
* param[in] enable  Enable flag.CNcomment: ʹ�ܱ�־��HI_TRUE��ʾʹ�ܣ�HI_FALSE��ʾȥʹ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_Enable(HIGV_HANDLE wheelViewHandle, HI_BOOL enable);

/*
* brief Is touch enable.CNcomment:��ȡ�Ƿ�������״̬
* param[in] wheelViewHandle Image handle.CNcomment:�ؼ����
* retval ::HI_TRUE  Touch is Enable.CNcomment: ��������
* retval ::HI_FALSE Touch is Disable.CNcomment: ��������
*/
HI_BOOL HI_GV_WheelView_IsEnable(HIGV_HANDLE wheelViewHandle);

/*
* rief Set scroll param.CNcomment:���û���������ϵ��(Ĭ��Ϊ1.0�����ڵ���1.0)
* param[in] wheelViewHandle wheelview handle.    CNcomment:�ؼ����
* param[in] scrollParam scroll index.    CNcomment:����������ϵ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_SetScrollParam(HIGV_HANDLE wheelViewHandle, HI_FLOAT scrollParam);

/*
* brief Set fling param.CNcomment:������ɨ������ϵ��(Ĭ��Ϊ1.0�����ڵ���1.0)
* param[in] wheelViewHandle wheelview handle.    CNcomment:�ؼ����
* param[in] flingParam fling index.    CNcomment:��ɨ������ϵ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_SetFlingParam(HIGV_HANDLE wheelViewHandle, HI_FLOAT flingParam);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_WHEELVIEW_H */
