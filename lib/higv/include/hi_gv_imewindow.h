/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: Input method window API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_IMEWINDOW_H
#define HI_GV_IMEWINDOW_H

/* add include here */
#include "hi_gv_widget.h"
#ifdef HIGV_USE_MODULE_IME
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    HI_GV_IMEWindow_ENGLISH = 0,
    HI_GV_IMEWindow_CAPENGLISH,
    HI_GV_IMEWindow_NUMBER,
    HI_GV_IMEWindow_PINYIN,
    HI_GV_IMEWindow_SYBMOL,
    HI_GV_IMEWindow_STANDARD_A,
    HI_GV_IMEWindow_STANDARD_B,
    HI_GV_IMEWindow_BUTT
} HigvIMEWindowType;

typedef struct {
    HI_U32 pinyinCharRectLeftMargin; /* Left margin of pingyin input rect */
    HI_U32 pinyinCharRectUpMargin; /* Up margin of pingyin input rect */
    HI_U32 pinyinCharRectDownMargin; /* Down margin of pingyin input rect */

    HI_U32 logPicRectRightMargin; /* Right margin of logo */
    HI_U32 logPicRectUpMargin; /* Up margin of logo */
    HI_U32 logPicRectDownMargin; /* Down margin of logo */
    HI_U32 logPicRectWidth; /* The width of logo */
    HI_U32 logPicRectHeight; /* The height of logo */

    HI_U32 logPicAndCharRectSpace; /* The space between logo and input char rect */

    HI_U32 lArrowPicRectLeftMargin; /* The space margin of left arrow rect */
    HI_U32 lArrowPicRectUpMargin; /* The up margin of bottom arrow rect */
    HI_U32 lArrowPicRectDownMargin; /* The down margin of bottom arrow rect */
    HI_U32 lArrowPicRectWidth; /* The height of left arrow rect */
    HI_U32 lArrowPicRectHeight; /* The width of left arrow rect */

    HI_U32 rArrowPicRectRightMargin; /* Right margin of right arrow rect */
    HI_U32 rArrowPicRectUpMargin; /* Up margin of right arrow rect */
    HI_U32 rArrowPicRectDownMargin; /* Bottom margin of right arrow rect */
    HI_U32 rArrowPicRectWidth; /* The height of right arrow rect */
    HI_U32 rArrowPicRectHeight; /* The height of left arrow rect */

    HI_U32 twoArrowSpace; /* The space between left and right margin */

    HI_U32 candidataWordUpMargin; /* Top margin of first level candiate */
    HI_U32 candidataWordDownMargin; /* Down margin of first level candidate */
    HI_U32 candidataWordLeftMargin; /* Left margin of first level candidate */
} HigvIMEWindowInitEx;

typedef struct {
    HIGO_PF_E pixelFormat; /* Input method pixel format */
    HI_PARAM englishLogoIndex; /* english input method logo */
    HI_PARAM capEnglishLogoIndex; /* Caps english input method logo */
    HI_PARAM symbolLogoIndex; /* Symbol input method logo */
    HI_PARAM numberLogoIndex; /* Number input method LOGO */
    HI_PARAM pinyinLogoIndex; /* Pinyin input method LOGO */
    HI_PARAM standardALogoIndex; /* Standard input method A logo */
    HI_PARAM standardBLogoIndex; /* Standard input method B logo */
    HI_PARAM leftArrowPicIndex; /* Left arrow picture */
    HI_PARAM rightArrowPicIndex; /* Right arrow picture */
    HI_PARAM unActiveLeftArrowPicIndex; /* Unactive status of left arrow */
    HI_PARAM unActiveRightArrowPicIndex; /* Unactive status of right arrow */
    HI_PARAM pinYinTablePath; /* path of pinyin code table */
    HI_PARAM pinYinTablePathLen; /* path length of pinyin code table */
    HigvIMEWindowInitEx *exData; /* Change input method size */
} HigvIMEWindowInit;

typedef struct {
    HIGV_HANDLE keyWidget;
    HI_U32 keyValue;
} HigvIMEWindowKeyValuePair;

typedef struct {
    HI_BOOL isNoDispIMW; /* Whether display input method window, default show. */
    HIGV_HANDLE softKB; /* Soft keyboard handle */
    HI_BOOL isDispSoftKB; /* Whether show softkeyboard */
    HigvIMEWindowKeyValuePair *keyValueMap; /* key map */
    HI_U32 keyNum; /* Key number */
} HigvIMEWindowSoftKB;

/*
\brief Create input method window(default height/width:100/42).CNcomment:�������뷨�����뷨���ڿ��100,  �߶�42
\param[in]  creatInfo Create inforamtion.CNcomment:���뷨���ڳ�ʼ����Ϣ
\param[out] handle Input method window handle.  CNcomment:���������뷨���ھ��ָ��
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\retval ::HI_EEXIST
\see \n
N/A.CNcomment:��
*/
HI_S32 HI_GV_IMEWINDOW_Create(const HIGV_WCREATE_S *creatInfo, HigvIMEWindowInit *initData, HIGV_HANDLE *handle);

/*
\brief Destroy input method window.CNcomment:�������뷨����
\param[in] handle
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:��
*/
HI_S32 HI_GV_IMEWINDOW_Destroy(HIGV_HANDLE handle);

/*
\brief Switch input method.CNcomment:�л����뷨
\param[in] handle
\param[in] imeType
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:��
*/
HI_S32 HI_GV_IMEWINDOW_Change(HIGV_HANDLE handle, HigvIMEWindowType imeType);

/*
\brief Open/clos the input method.CNcomment:��/�ر�ָ�����뷨
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:��
*/
HI_S32 HI_GV_IMEWINDOW_Enable(HigvIMEWindowType imeType, HI_BOOL isEnable);

/*
\brief Set the switch window at init stage.CNcomment:��ʼ��ʱ�������뷨�л����ھ��
\attention \n
N/A.CNcomment:��
\param[in]  handle   Input method window handle. CNcomment:���뷨����
\param[in]  switchWindowHandle  switch window CNcomment:������ʾ���뷨
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:��
*/
HI_S32 HI_GV_IMEWINDOW_SetSwitchIMWin(HIGV_HANDLE handle, HIGV_HANDLE switchWindowHandle);

/*
\brief Bind the softkeyboard to the input window at init stage.CNcomment:��ʼ��ʱ������̵����뷨 ����
\attention \n
N/A.CNcomment:��
\param[in]  handle   Input method window handle.  CNcomment:���뷨����
\param[in]  softKBArray Softkey board.CNcomment:��Ҫ�󶨵������
\param[in]  imeNum   Input method number.CNcomment: �����뷨��Ŀ
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:��
*/
HI_S32 HI_GV_IMEWINDOW_SetSoftKB(HIGV_HANDLE handle, HigvIMEWindowSoftKB *softKBArray, HI_U32 imeNum);

/*
\brief Get the show status of input window.CNcomment:��ȡ��ǰ���뷨��� ����(�������뷨���ڻ������)
�����뷨�л�����)����ʾ״̬
\attention \n
N/A.CNcomment:��
\param[in]  handle Input method window handle.  CNcomment:���뷨����
\retval ::HI_TRUE  Show.CNcomment:��ʾ
\retval ::HI_FALSE Hide.CNcomment:����
\see \n
N/A.CNcomment:��
*/
HI_BOOL HI_GV_IMEWINDOW_IsShowIM(HIGV_HANDLE handle);

/*
\brief Get the show status of softkeyboard.CNcomment:��ȡ��ǰ����̴�������̵���ʾ״̬
\attention \n
N/A.CNcomment:��
\param[in]  handle Input mesthod window handle.CNcomment:���뷨����
\retval ::HI_TRUE  Show. CNcomment:��ʾ
\retval ::HI_FALSE Hdie.CNcomment:����
\see \n
N/A.CNcomment:��
*/
HI_BOOL HI_GV_IMEWINDOW_IsShowSoftKB(HIGV_HANDLE handle);

/*
\brief Set the show status of soft keyboard.CNcomment:��������̴�������̵���ʾ״̬
\attention \n
N/A.CNcomment:��
\param[in]  handle   Input method window handle.  CNcomment:���뷨����
\param[in]  softKBHandle  Softkeyboad winddow handle. CNcomment:����̴���
\param[in]  isShow  show/hide. CNcomment:��ʾ������
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:��
*/
HI_S32 HI_GV_IMEWINDOW_SetDispSoftKB(HIGV_HANDLE handle, HIGV_HANDLE softKBHandle, HI_BOOL isShow);

/*
\brief Get the active widget which get the input focus.CNcomment:��ȡ��ǰ�������뷨�Ŀؼ������뷨�л�����
\attention \n
N/A.CNcomment:��
\param[in]  handle    Input method window handle. CNcomment:���뷨����
\param[out]  activeWidget  The active widget handle.  CNcomment:��ǰ����ؼ����ָ��
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:��
*/
HI_S32 HI_GV_IMEWINDOW_GetIMEActiveWidget(HIGV_HANDLE handle, HIGV_HANDLE *activeWidget);

/*
\brief Get the current input method.CNcomment:��ȡ��ǰ���뷨
\attention \n
N/A.CNcomment:��
\param[in]  handle  Input method window handle.  CNcomment:���뷨����
\param[out]  imeType  The pointer of inpute method. CNcomment: ��ǰ���뷨ָ��
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:��
*/
HI_S32 HI_GV_IMEWINDOW_GetCurrentIME(HIGV_HANDLE handle, HigvIMEWindowType *imeType);

/*
\brief Reset the key map of softkeyboard.CNcomment:��������̴��ڵİ�ť����ӳ��
\attention \n
N/A.CNcomment:��
\param[in]  imeType  Input method.  CNcomment:��������뷨
\param[in]  keyValue   The pointer of Key value.CNcomment:ӳ��ָ��
\param[in]  num   Key value number.CNcomment:�������Ŀ
\param[out]
\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL
\see \n
N/A.CNcomment:��
*/
HI_S32 HI_GV_IMEWINDOW_SetKeyValue(HigvIMEWindowType imeType, HI_U32 *keyValue, HI_U32 num);

/*
\brief �����������ʾ����Ļ�Ĺ̶�λ��
\attention \n
��
\param[in]  handle    ���뷨����
\param[in]  x    ��Ļ����x
\param[in]  y    ��Ļ����y
\retval ::HI_SUCCESS �ɹ�
\retval ::HI_ERR_LOST �����Ч
\retval ::HI_ERR_INVAL ��Ч����
\see \n
��
*/
HI_S32 HI_GV_IMEWINDOW_PinSoftKB(HIGV_HANDLE handle, HI_S32 x, HI_S32 y);

/*
\brief ���̶���ʾ�������ʾλ��
\attention \n
��
\param[in]  handle    ���뷨����
\retval ::HI_SUCCESS �ɹ�
\retval ::HI_ERR_LOST �����Ч
\retval ::HI_ERR_INVAL ��Ч����
\see \n
��
*/
HI_S32 HI_GV_IMEWINDOW_UnPinSoftKB(HIGV_HANDLE handle);

/*
\brief ����������뷨���ں�����̴��ڵ�λ��
\attention \n
��
\param[in]  handle    ���뷨����
\param[in]  isFlexible    ����������뷨���ں�����̴��ڵ�λ�õĿ���
\retval ::HI_SUCCESS ���óɹ�
\retval ::HI_ERR_LOST �����Ч
\retval ::HI_ERR_INVAL ��Ч����
\see \n
��
*/
HI_S32 HI_GV_IMEWINDOW_FlexibleSoftKB(HIGV_HANDLE handle, HI_BOOL isFlexible);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_IMEWINDOW_H */
