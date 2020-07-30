/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: Button API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_BUTTON_H
#define HI_GV_BUTTON_H

/* add include here */
#include "hi_gv_resm.h"
#include "hi_gv_conf.h"

#ifdef HIGV_USE_WIDGET_BUTTON
#ifdef __cplusplus
extern "C" {
#endif

/* Normal button ; CNcomment:��ͨ��ť */
#define HIGV_BS_PUSH HIGV_STYLE_DEFINE(HIGV_WIDGET_BUTTON, BUTTON_STYLE_PUSH)

/*  Radio button ; CNcomment:��ѡ��ť */
#define HIGV_BS_RADIO HIGV_STYLE_DEFINE(HIGV_WIDGET_BUTTON, BUTTON_STYLE_RADIO)

/*  Check button ; CNcomment:��ѡ��ť */
#define HIGV_BS_CHECK HIGV_STYLE_DEFINE(HIGV_WIDGET_BUTTON, BUTTON_STYLE_CHECK)

/*  Softkey button ; CNcomment:����̰�ť */
#define HIGV_BS_SOFTKEY HIGV_STYLE_DEFINE(HIGV_WIDGET_BUTTON, BUTTON_STYLE_SOFTKEY)

/*  Switch button ; CNcomment:���ذ�ť */
#define HIGV_BS_SWITCH HIGV_STYLE_DEFINE(HIGV_WIDGET_BUTTON, BUTTON_STYLE_SWITCH)

/*  Toggle button ; CNcomment:Ŧ�ۿ��ذ�ť */
#define HIGV_BS_TOGGLE HIGV_STYLE_DEFINE(HIGV_WIDGET_BUTTON, BUTTON_STYLE_TOGGLE)

/*  Paint toggle min height ; CNcomment:����toggle�Ŀؼ���С�߶ȣ�С�ڴ˸߶ȵ�toggle��ť������Ŧ�� */
#define HIGV_BUTTON_TOGGLE_MIN_HEIGHT 5

/*  Paint toggle min width ; CNcomment:����toggle�Ŀؼ���С��ȣ�С�ڴ˿�ȵ�toggle��ť������Ŧ�� */
#define HIGV_BUTTON_TOGGLE_MIN_WIDTH 19

/* Button type ; CNcomment: button����ö�� */
typedef enum {
    BUTTON_STYLE_PUSH = 0,
    /* Push button , CNcomment: ��ͨ��ť */
    BUTTON_STYLE_RADIO,
    /* Radio button , CNcomment: ��ѡ��ť */
    BUTTON_STYLE_CHECK,
    /* Check button , CNcomment: ��ѡ��ť */
    BUTTON_STYLE_SOFTKEY,
    /* Softkey button , CNcomment: ����̰�ť������ͨ��ť���� */
    BUTTON_STYLE_SWITCH,
    /* Switch button , CNcomment: ���ذ�ť */
    BUTTON_STYLE_TOGGLE,
    /* Toggle button , CNcomment: Ŧ�ۿ��ذ�ť */
    BUTTON_STYLE_BUTT
} HIGV_BUTTON_SYLE_E;

/* Button status , CNcomment: button״̬ */
typedef enum {
    BUTTON_STATUS_UNCHECKED = 0,
    /* Unchecked status , CNcomment:δѡ��״̬ */
    BUTTON_STATUS_CHECKED,
    /* Checked status , CNcomment: ѡ��״̬ */
    BUTTON_STATUS_BUTT
} HIGV_BUTTON_STATUS_E;

/* Button switch status , CNcomment: button����״̬ */
typedef enum {
    BUTTON_SWITCH_OFF = 0,
    /* Switch off , CNcomment: �رտ��� */
    BUTTON_SWITCH_ON,
    /* Switch on , CNcomment: �򿪿��� */
    BUTTON_SWITCH_BUTT
} HIGV_BUTTON_SWITCH_E;

/* Switch button text layout , CNcomment: switch������ֲ��� */
typedef enum {
    BUTTON_SWITCHLAYOUT_OFF_ON = 0,
    /* "off:on" layout , CNcomment: off�����on���ұߵ��ı����� */
    BUTTON_SWITCHLAYOUT_ON_OFF,
    /* "on:off" layout , CNcomment: on�����off���ұߵ��ı����� */
    BUTTON_SWITCHLAYOUT_BUTT
} HIGV_BUTTON_SWITCHLAYOUT_E;

/*
* brief Set checked status.CNcomment:����Button��ѡ��״̬
* param[in] buttonHandle Button handle.CNcomment:Button���
* param[in] status  Checked status.CNcomment:Buttonѡ��״̬
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Button_SetCheck(HIGV_HANDLE buttonHandle, HIGV_BUTTON_STATUS_E status);

/*
* brief Get checked status.CNcomment:��ȡButton��ѡ��״̬
* param[in] buttonHandle Button handle.CNcomment:Button���
* param[out] status  Checked status.CNcomment:Buttonѡ��״̬
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Button_GetCheck(HIGV_HANDLE buttonHandle, HIGV_BUTTON_STATUS_E *status);

/*
* brief Set switch status of button.CNcomment:����Button�Ŀ���״̬
* param[in] buttonHandle Button handle.CNcomment:Button���
* param[in] switcbuttonHandle  CNcomment:Buttonѡ��״̬
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Button_SetSwitch(HIGV_HANDLE buttonHandle, HIGV_BUTTON_SWITCH_E switchButtonHandle);

/*
* brief Get the status of button.CNcomment:��ȡButton�Ŀ���״̬
* param[in] buttonHandle Button handle.CNcomment:Button���
* param[out] switcbuttonHandle CNcomment: Buttonѡ��״̬
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Button_GetSwitch(HIGV_HANDLE buttonHandle, HIGV_BUTTON_SWITCH_E *switchButtonHandle);

/*
* brief Set the color for toggle.CNcomment:����toggle��ɫ
* param[in] buttonHandle Button handle.CNcomment:Button���
* param[in] toggleOnColor BUTTON_SWITCH_ON status color.CNcomment:��״̬toggle��ɫֵ
* param[in] toggleOffColor BUTTON_SWITCH_OFF status color.CNcomment:�ر�״̬toggle��ɫֵ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Button_SetToggleColor(HIGV_HANDLE buttonHandle, HI_COLOR toggleOnColor, HI_COLOR toggleOffColor);

/*
* brief Set text by language ID for switch/toggle Button.CNcomment:����switch/toggle���ť����ʾ�������ı�ID
* param[in] buttonHandle Button handle.CNcomment:Button���
* param[in] onStrID BUTTON_SWITCH_ON status text ID.CNcomment:��״̬�������ִ�ID
* param[in] offStrID BUTTON_SWITCH_ON status textID.CNcomment:�ر�״̬�������ִ�ID
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Button_SetSwitchTextByID(HIGV_HANDLE buttonHandle, const HI_U32 onStrID, const HI_U32 offStrID);

/*
* brief Set switch button text layout.CNcomment:����switch���ť���ı�����
* param[in] buttonHandle Button handle.CNcomment:Button���
* param[in] textLayout text layout.CNcomment:���ַ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Button_SetSwitchLayout(HIGV_HANDLE buttonHandle, HIGV_BUTTON_SWITCHLAYOUT_E textLayout);

#ifdef __cplusplus
}
#endif
#endif
#endif /*  HI_GV_BUTTON_H */
