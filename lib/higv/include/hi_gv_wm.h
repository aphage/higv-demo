/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: APIWindow manageer moudle API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_WM_H
#define HI_GV_WM_H

#include "hi_type.h"
#include "hi_gv_conf.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Stack capacity ; CNcomment:����ջ���� */
#define HIGV_MAX_WINNUM 50

/*
* brief Push window to statck.CNcomment:��������ջ
* param[in] layerHandle  Layer handle. CNcomment:ͼ����
* param[in] windowHandle Window handle. CNcomment:���ھ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_FULL Stack full.CNcomment:ջ��
* see ::HI_GV_WM_PopWindow
*/
HI_S32 HI_GV_WM_PushWindow(HIGV_HANDLE layerHandle, HIGV_HANDLE windowHandle);

/*
* brief Pop up window from stack.CNcomment:�����ڳ�ջ
* param[in] layerHandle  Layer handle. CNcomment:ͼ����
* param[in] windowHandle Window handle.CNcomment:���ھ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_EMPTY Stack empty.CNcomment:ջ��
* see ::HI_GV_WM_PushWindow
*/
HI_S32 HI_GV_WM_PopWindow(HIGV_HANDLE layerHandle, HIGV_HANDLE windowHandle);

/*
* brief Get top window of stack. CNcomment:��ȡջ������
* param[in] layerHandle  Layer handle. CNcomment:ͼ����
* param[out] windowHandle Window handle. CNcomment: ���ھ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_EMPTY Stack empty.CNcomment:ջ��
*/
HI_S32 HI_GV_WM_GetTopWindow(HIGV_HANDLE layerHandle, HIGV_HANDLE *windowHandle);

/*
* brief Clear window of the stack.CNcomment:���ջ�д���
* param[in] layerHandle  Layer handle. CNcomment:ͼ����
* retval ::HI_SUCCESS
*/
HI_S32 HI_GV_WM_ClearAllWindow(HIGV_HANDLE layerHandle);

/**
* brief Get capture mouse window. CNcomment:�����겶�񴰿�
* param[in]  layerHandle    Layer handle. CNcomment:ͼ����
* param[out] widgetHandle  The window which capture mouse. CNcomment:�������Ĵ���
* retval ::HI_SUCCESS
*/
HI_S32 HI_GV_WM_GetMouseCapture(HIGV_HANDLE layerHandle, HIGV_HANDLE *widgetHandle);

/*
* brief Set the capture mouse window.CNcomment:������겶�񴰿�
* param[in] layerHandle  Layer handle.CNcomment:ͼ����
* param[in] widgetHandle Set the window which capture mouse.CNcomment:������겶�񴰿�
* retval ::HI_SUCCESS
N/A.CNcomment:��
*/
HI_S32 HI_GV_WM_SetMouseCapture(HIGV_HANDLE layerHandle, HIGV_HANDLE widgetHandle);

/*
* brief Get the higo layer handle correspoding layer.CNcomment:��ȡͼ���Ӧ��HIGOͼ����
* attention : CNcomment:���ֶ�ͼ��Ĳ�����Ҫ�õײ��higoͼ��ӿ�
* param[in] layerHandle     Layer handle.CNcomment:ͼ����
* param[out] higoLayer Higo layer handle. CNcomment:HIGOͼ����
* retval ::HI_SUCCESS
*/
HI_S32 HI_GV_WM_GetHigoLayer(HIGV_HANDLE layerHandle, HIGV_HANDLE *higoLayer);

/*
* brief Touch msg bind with widget. CNcomment:������Ϣ�Ϳؼ���
* param[in] layerHandle  Layer handle.CNcomment:ͼ����
* param[in] isBind Bind tag, HI_TRUE or HI_FALSE.CNcomment:�Ƿ�󶨿ؼ�
* retval ::HI_SUCCESS
*/
HI_S32 HI_GV_WM_BindTouchMsg(HIGV_HANDLE layerHandle, HI_BOOL isBind);

/*
* brief Get bind status.CNcomment:��ȡ��״̬
* param[in] layerHandle  Layer handle.CNcomment:ͼ����
* param[in] isBind Bind status .CNcomment:��״̬��HI_TRUE��ʾ�Ѱ󶨣�HI_FALSE��ʾδ��
* retval ::HI_SUCCESS
*/
HI_S32 HI_GV_WM_GetBindTouchStatus(HIGV_HANDLE layerHandle, HI_U32 *isBind);

#ifdef __cplusplus
}
#endif
#endif /* HI_GV_WM_H */
