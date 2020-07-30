/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: Window API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_WIN_H
#define HI_GV_WIN_H

/* add include here */
#include "hi_type.h"
#include "hi_gv_conf.h"
#ifdef __cplusplus
extern "C" {
#endif

/*
* brief Set window opacity.CNcomment:���ô��ڿɼ���
* param[in] windowHandle Window handle.CNcomment:���ھ��
* param[in] opacity Window opacity.CNcomment:���ڿɼ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Win_SetOpacity(HIGV_HANDLE windowHandle, HI_U8 opacity);

/*
* brief Get first highlight child widget of widnow CNcomment:��ȡ���ڵ�һ�������ĺ��Ӿ��
* attention :This api is uded to get the hightlight widget for softkeyboard.
* CNcomment:��Ҫ��Ӧ����������ϻ�ȡ��ǰ�����ؼ�
* param[in] windowHandle Window handle.CNcomment:���ھ��
* param[out] handleHilghtChild Hightlight child.CNcomment:��������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Win_GetHilightChild(HIGV_HANDLE windowHandle, HIGV_HANDLE *handleHilghtChild);

/*
* brief Reset all hightlight child and hightlight the first child.CNcomment:��λ�����еĸ������ӣ������ڵ�һ���ӿؼ�����
* attention:This API is used to redisplay the softkeyboard.
* CNcomment:��Ҫ��Ӧ��������ʾ�����ʱ��λ�����
* param[in] windowHandle Window handle.CNcomment:���ھ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Win_ResetHilightChild(HIGV_HANDLE windowHandle);

/*
* brief Sync show win and get widget handle of done this show.CNcomment:ͬ����ʾwindow����ȡ������ʾ�Ŀؼ����
* attention:Return the second arg of HI_GV_Win_EndSyncShow.CNcomment:����HI_GV_Win_EndSyncShow�ӿڵĵڶ�������
* param[in] windowHandle Window handle.CNcomment:���ھ��
* retval ::HIGV_HANDLE
* retval ::HI_FAILURE
* see : HI_GV_Win_EndSyncShow
*/
HI_S32 HI_GV_Win_SyncShow(HIGV_HANDLE windowHandle);

/*
* brief Done the sync show.CNcomment:��������ͬ����ʾ
* param[in] windowHandle Window handle.CNcomment:���ھ��
* param[in] handleWidget Widget handle of end window sync show .CNcomment:����ͬ����ʾʱ���صĿؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_NOOP
* see : HI_GV_Win_SyncShow
*/
HI_S32 HI_GV_Win_EndSyncShow(HIGV_HANDLE windowHandle, HIGV_HANDLE handleWidget);

/*
* brief Get window level.CNcomment:��ȡ���ڵȼ�
* param[in] windowHandle Window handle.CNcomment:���ھ��
* param[out] level Window level.CNcomment:�����Ĵ��ڵȼ�
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Win_GetWinLevel(HIGV_HANDLE windowHandle, HI_U32 *level);

/*
* brief Advance window and child to load skin.CNcomment:���ش��ڼ����ӿؼ��ĵ�Ƥ��
* attention : HIGV_STYLE_HIDE_UNLODRES style .CNcomment:�������ͷ���Դ���ʱ��Ч
* param[in] windowHandle Window handle.CNcomment:���ھ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Win_LoadSkin(HIGV_HANDLE windowHandle);

#ifdef __cplusplus
}
#endif
#endif /* HI_GV_WIN_H */
