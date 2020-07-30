/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: trackbar API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_TRACKBAR_H
#define HI_GV_TRACKBAR_H

#include "hi_gv_conf.h"
#ifdef HIGV_USE_WIDGET_TRACKBAR
/* add include here */
#include "hi_type.h"
#include "hi_go.h"
#include "hi_gv_resm.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum HI_TRACKBAR_STYLE {
    TRACKBAR_H = 0,
    TRACKBAR_V,
    TRACKBAR_BUT
} TRACKBAR_STYLE;

typedef enum hiHIGV_TRACKBAR_E {    /* Trackbar type ; CNcomment:  ����ؼ����� */
    HIGV_TRACKBAR_NORMAL = 0,
    HIGV_TRACKBAR_ACTIVE,
    HIGV_TRACKBAR_MOUSEDOWN,
    HIGV_TRACKBAR_BUTT
} HIGV_TRACKBAR_E;

#define HIGV_TRACKBAR_H HIGV_STYLE_DEFINE(HIGV_WIDGET_TRACKBAR, TRACKBAR_H)
#define HIGV_TRACKBAR_V HIGV_STYLE_DEFINE(HIGV_WIDGET_TRACKBAR, TRACKBAR_V)

/*
* brief Set skin of trackbar. CNcomment:����TrackBar���˵�Ƥ��
* param[in] trackBarHandle Trackbar handle.CNcomment:Track���
* param[in] handleSkinIndex  Skin index.CNcomment:TrackƤ��״̬
* param[in] handleRes    Picture resource ID.CNcomment:TrackͼƬ��ԴID
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Track_SetSliImage(HIGV_HANDLE trackBarHandle, HI_U32 handleSkinIndex, HI_RESID handleRes);

/*
* brief Set the skin of slideblock.CNcomment:����TrackBar�����Ƥ��
* param[in] trackBarHandle    Trackbar handle.CNcomment:Track���
* param[in] handleSkinIndex  Skin index.CNcomment:TrackƤ��״̬
* param[in] handleRes   Picture resource ID of track bar.CNcomment:TrackͼƬ��ԴID
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Track_SetTraImage(HIGV_HANDLE trackBarHandle, HI_U32 handleSkinIndex, HI_RESID handleRes);

/*
* brief Set the value of trackbar.CNcomment:����TrackBar��ǰֵ
* param[in] trackBarHandle    Trackbar handle.   CNcomment:TrackBar���
* param[in] value     Get current valude of cursor.  CNcomment:�õ��α�ĵ�ǰֵ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Track_SetCurVal(HIGV_HANDLE trackBarHandle, HI_U32 value);

/*
* brief Get current graduation of cursror.CNcomment:�õ��α굱ǰ�̶�
* param[in] trackBarHandle      Trackbar handle.CNcomment: TrackBar���
* param[out] value     Get value of current cursor. CNcomment:�õ��α�ĵ�ǰֵ
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Track_GetCurVal(HIGV_HANDLE trackBarHandle, HI_U32 *value);

/*
* brief Set the range of cursor. CNcomment:�趨�α�ķ�Χֵ
* param[in] trackBarHandle     Trackbar handle.CNcomment:Track���
* param[in] maxnValue Max value of cursor.CNcomment: �α����ֵ
* param[in] minValue  Min value of cursor.CNcomment: �α���Сֵ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Track_SetRange(HIGV_HANDLE trackBarHandle, HI_U32 minValue, HI_U32 maxValue);

/*
* brief Get the range of cursor.CNcomment:��ȡ�α�ķ�Χ
* param[in]  trackBarHandle     Trackbar handle.CNcomment:Track���
* param[out] maxValue  Max value of cursor.CNcomment:�õ��α����ֵ
* param[out] minValue  Min value of cursor.CNcomment:�õ��α���Сֵ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Track_GetRange(HIGV_HANDLE trackBarHandle, HI_U32 *minValue, HI_U32 *maxValue);

/*
* brief Set gesture enable.CNcomment:���ÿؼ��Ƿ�֧�ִ���
* param[in]  trackBarHandle  Scrollgrid handle. CNcomment:�ؼ����
* param[in]  isEnable   Is enable gesture. CNcomment:�Ƿ�֧�ִ���( HI_TRUE��ʾ֧�֣�HI_FALSE��ʾ��ֹ)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Track_EnableGesture(HIGV_HANDLE trackBarHandle, HI_BOOL isEnable);

/*
* brief Get gesture enable.CNcomment:��ȡ�ؼ��Ƿ�֧�ִ���
* param[in]  trackBarHandle  Scrollgrid handle. CNcomment:�ؼ����
* param[in]  isEnable   Is enable gesture. CNcomment:�Ƿ�֧�ִ���( HI_TRUE��ʾ֧�֣�HI_FALSE��ʾ��ֹ��ϵͳĬ��ΪHI_TRUE)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Track_IsGestureEnable(HIGV_HANDLE trackBarHandle, HI_BOOL *isEnable);

#ifdef __cplusplus
}
#endif
#endif /* HI_GV_TRACKBAR_H */
#endif
