/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: Multi-layer module API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_MLAYER_H
#define HI_GV_MLAYER_H

#include "hi_go.h"
#include "hi_gv_conf.h"

#ifdef __cplusplus
extern "C" {
#endif

/* * The event of window move or size change */ /* * CNcomment: �����ƶ���ߴ��޸ĺ�����Ĵ����¼�ID */
#define HIGV_MSG_WINDOW_MOVE 0x502

typedef enum {
    HIGV_ROTATE_NONE = 0,
    HIGV_ROTATE_90,
    /* <Rotate 90 degrees clockwise  , CNcomment:  ˳ʱ����ת90�� */
    HIGV_ROTATE_180,
    /* <Rotate 180 degrees clockwise , CNcomment: ˳ʱ����ת�������� */
    HIGV_ROTATE_270,
    /* <Rotate 270 degrees clockwise , CNcomment: ˳ʱ����ת�������� */
    HIGV_ROTATE_BUTT
} HIGV_ROTATE_E;

/*
* brief Create layer.CNcomment: ����ͼ��
* param[in]  layerInfo Layer infomation.CNcomment: ͼ����Ϣ
* param[out] layerHandle The pointer of layer handle.CNcomment: ���ͼ������ָ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Layer_Create(const HIGO_LAYER_INFO_S *layerInfo, HIGV_HANDLE *layerHandle);

/*
* brief Create Layer, the handle is used by xml.CNcomment: ����ͼ�㣬������XML����ָ�����ʹ��
* param[in]  layerInfo Layer infomation.CNcomment: ͼ����Ϣ
* param[in]  layerHandle Layer handle.CNcomment: ͼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Layer_CreateEx(const HIGO_LAYER_INFO_S *layerInfo, HIGV_HANDLE layerHandle);

/*
* brief Destroy layer.CNcomment: ����ͼ��
* param[in] layerHandle Layer handle.CNcomment: ͼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Layer_Destroy(HIGV_HANDLE layerHandle);

/*
* brief show/hide the layer.CNcomment: ��ʾ/����ͼ��
* param[in] visible The flag indicat show or hide.CNcomment: HI_TRUE��ʾ��ʾ��HI_FALSE��ʾ����
* retval ::HI_SUCCESS
*/
HI_S32 HI_GV_Layer_Show(HIGV_HANDLE layerHandle, HI_BOOL visible);

/*
* brief Set default layer.CNcomment: ����ȱʡͼ�㣬����ȱʡͼ�������������ڲ��ƶ�ͼ�㣬��
*        Ĭ��Ϊ��ͼ��
* param[in] layerHandle Layer handle.CNcomment:  ͼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Layer_SetDefault(HIGV_HANDLE layerHandle);

/*
* brief Get default layer.CNcomment: ��ȡȱʡͼ��
* param[out] defaultLayer The pointer of default layer.CNcomment:  ��ȡĬ��ͼ��ָ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_EMPTY
*/
HI_S32 HI_GV_Layer_GetDefault(HIGV_HANDLE *defaultLayer);

/*
* brief Get the active window handle.CNcomment: ��ȡͼ�����ھ��
* param[in] layerHandle Layer handle.CNcomment: ͼ����
* param[out] window Active window handle.CNcomment: ����ھ��ָ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_EMPTY
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Layer_GetActiveWindow(HIGV_HANDLE layerHandle, HIGV_HANDLE *window);

/*
* brief Get the higo layer by higv layer handle.CNcomment: ͨ��HIGVͼ������ȡHIGOͼ��ͼ����
* param[in] layerHandle Layer handle.CNcomment: HIGVͼ����
* param[out] higoLayer  higo layer handle.CNcomment: HIGOͼ����ָ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_EMPTY
*/
HI_S32 HI_GV_Layer_GetHigoLayer(HIGV_HANDLE layerHandle, HIGV_HANDLE *higoLayer);

/*
* brief Set the layer the share source.CNcomment: ����������ͬԴ���
* param[in] ownerLayerHandle   Layer handle.CNcomment: �Ѿ�ӵ��������ݵ�layer
* param[in] cientLayerHandle  The share source between the layer.CNcomment: ��Ҫ��hOwnerLayer����Դ��layer
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_UNSUPPORT
*/
HI_S32 HI_GV_Layer_ShareSource(HIGV_HANDLE ownerLayerHandle, HIGV_HANDLE cientLayerHandle);

/*
* brief Get the active layer handle.CNcomment: ��ȡ�ͼ����
* param[out] layerHandle   Layer handle.CNcomment: �ͼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_EMPTY
*/
HI_S32 HI_GV_Layer_GetActiveLayer(HIGV_HANDLE *layerHandle);

/*
* brief Set active layer.CNcomment: ���ûͼ����
* param[in] layerHandle   Layer handle.CNcomment: �ͼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Layer_SetActiveLayer(HIGV_HANDLE layerHandle);

/*
* brief Move window zorder to top.CNcomment: ���ø�ͼ���z��Ϊ���
* attention:
* The layer has z order, The z order of is more bigger,
* the layer is displayed close to user, this interface is to set the
* layer show on top of screen.
* param[in] layerHandle   Layer handle.CNcomment: ͼ����
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
* see:HI_GV_Layer_MoveToBottom
*/
HI_S32 HI_GV_Layer_MoveToTop(HIGV_HANDLE layerHandle);

/*
* brief move window zorder to bottom.CNcomment: ���ø�ͼ���z��Ϊ��ײ�
* param[in] layerHandle   Layer handle.CNcomment: ͼ����
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
* see : HI_GV_Layer_MoveToTop
*/
HI_S32 HI_GV_Layer_MoveToBottom(HIGV_HANDLE layerHandle);

/*
* brief Move up window zorder.CNcomment: ��ߴ��ڵ�z��ȼ�
* attention
* The layer has z order, The z order of is more bigger,
* the layer is displayed close to user, this interface is to set the
* layer show on top of screen.
* param[in] layerHandle   Layer handle.CNcomment: ͼ����
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
* see : HI_GV_Layer_MoveDown
*/
HI_S32 HI_GV_Layer_MoveUp(HIGV_HANDLE layerHandle);

/*
* brief Move down window zorder.CNcomment: ���ʹ��ڵ�z��ȼ�
* param[in] layerHandle   Layer handle.CNcomment: ͼ����
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
* see : HI_GV_Layer_MoveUp
*/
HI_S32 HI_GV_Layer_MoveDown(HIGV_HANDLE layerHandle);

/*
* brief set rotate mode.CNcomment: ����ͼ����ת����
* attention depend on higo support\n
* attention only support HIGO_PF_4444 & HIGO_PF_1555 Pixel Format \n
* param[in] layerHandle   Layer handle.CNcomment: ͼ����
* param[in] rotate   rotate.CNcomment: ��ת����
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
* see : HI_GV_Layer_SetRotateMode
*/
HI_S32 HI_GV_Layer_SetRotateMode(HIGV_HANDLE layerHandle, HIGV_ROTATE_E rotate);

#ifdef __cplusplus
}
#endif
#endif /* HI_GV_MLAYER_H */
