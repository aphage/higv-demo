/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: higv module header file
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_GESTURE_H
#define HI_GV_GESTURE_H

#include "hi_type.h"
#include "hi_gv_conf.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

typedef enum hiHIGV_TOUCH_E {
    HIGV_TOUCH_START = 1,     /* touch start event, the user touch screen */
    HIGV_TOUCH_END,           /* touch end event, the user release after touch screen */
    HIGV_TOUCH_MOVE,          /* touch move event, move on the touch screen */
    HIGV_TOUCH_CANCEL,        /* touch cancel event, the current gesture is interrupted. */
    HIGV_TOUCH_POINTER_START,  /* touch pointer start event, when a finger is already on the screen,
                                  the other finger is touching the screen */
    HIGV_TOUCH_POINTER_END,   /* touch pointer end event, trigger when a finger moves from the screen. */
    HIGV_TOUCH_BUTT
} HIGV_TOUCH_E;

/* *touch single point param */
typedef struct hiHIGV_TOUCH_POINT_S {
    HI_U32 id;         /* touch event serial number */
    HI_S32 x;          /* x coordinates relative to the screen */
    HI_S32 y;          /* y coordinates relative to the screen */
    HI_S32 pressure;   /* screen pressure */
    HI_U32 timeStamp;  /* event timestamp */
    HIGV_TOUCH_E type; /* event type */
} HIGV_TOUCH_POINT_S;

/* touch event param */
typedef struct hiHIGV_TOUCH_EVENT_S {
    HIGV_TOUCH_POINT_S last; /* the last event */
} HIGV_TOUCH_EVENT_S;

/* *gesture event enum */
typedef enum hiHIGV_GESTURE_E {
    HIGV_GESTURE_TAP = 1, /* gesture tap event, touch screen and up */
    HIGV_GESTURE_LONGTAP, /* gesture longpress event, long press screen */
    HIGV_GESTURE_FLING,   /* gesture fling event, user swipe screen */
    HIGV_GESTURE_SCROLL,  /* gesture scroll event, user sliding screen */
    HIGV_GESTURE_PINCH,   /*  gesture pinch event, zoom on the screen */
    HIGV_GESTURE_BUTT
} HIGV_GESTURE_E;

typedef struct hiHIGV_GESTURE_TAP_S {
    HIGV_TOUCH_POINT_S pointer; /* tap pointer infomation */
} HIGV_GESTURE_TAP_S;

typedef struct hiHIGV_GESTURE_LONGTAP_S {
    HIGV_TOUCH_POINT_S pointer; /* longtap pointer infomation */
} HIGV_GESTURE_LONGTAP_S;

typedef struct hiHIGV_GESTURE_FLING_S {
    HIGV_TOUCH_POINT_S start; /* start pointer infomation */
    HIGV_TOUCH_POINT_S end;   /* end pointer infomation */
    HI_S32 velocityX;         /* X axis speed per second */
    HI_S32 velocityY;         /*  Y axis speed per second */
} HIGV_GESTURE_FLING_S;

typedef struct hiHIGV_GESTURE_SCROLL_S {
    HIGV_TOUCH_POINT_S start; /* start pointer infomation */
    HIGV_TOUCH_POINT_S end;   /* end pointer infomation */
    HI_S32 distanceX;         /* moving distance between two points on X axis unit time */
    HI_S32 distanceY;         /* moving distance between two points on Y axis unit time */
} HIGV_GESTURE_SCROLL_S;

typedef struct hiHIGV_GESTURE_PINCH_S {
    HIGV_TOUCH_POINT_S pointer1; /* one flinger pointer infomation */
    HIGV_TOUCH_POINT_S pointer2; /* another flinger pointer infomation */
    HI_S32 intervalX;            /* distance of X axis at two points */
    HI_S32 intervalY;            /* distance of Y axis at two points */
} HIGV_GESTURE_PINCH_S;

typedef union hiHIGV_GESTURE_U {
    HIGV_GESTURE_TAP_S tap;         /* tap param */
    HIGV_GESTURE_LONGTAP_S longtap; /* longtap param */
    HIGV_GESTURE_FLING_S fling;     /* fling param */
    HIGV_GESTURE_SCROLL_S scroll;   /* scroll param */
    HIGV_GESTURE_PINCH_S pinch;     /* pinch param */
} HIGV_GESTURE_U;

typedef struct hiHIGV_GESTURE_EVENT_S {
    HIGV_GESTURE_U gesture;
} HIGV_GESTURE_EVENT_S;

typedef struct hiHIGV_TOUCH_INPUTINFO_S {
    HI_S32 id;        /* input id info, one finger or two fingers */
    HI_S32 x;         /* x coordinate absolute */
    HI_S32 y;         /* y coordinate absolute */
    HI_U32 pressure;  /* is press on screen: 0, 1 */
    HI_U32 timeStamp; /* time stamp */
} HIGV_TOUCH_INPUTINFO_S;

typedef struct hiHIGV_TOUCH_DEVICE_INPUT_S {
    HI_S32 (*OpenDevice)(HI_S32 *fd);                 /* open touch device function */
    HI_S32 (*CloseDevie)(HI_VOID);                    /* close touch device function */
    HI_S32 (*ReadData)(HIGV_TOUCH_INPUTINFO_S *info); /* read touch data function */
} HIGV_TOUCH_DEVICE_INPUT_S;

/*
* brief Callback of touch hook.CNcomment:�������ӻص�����
* param[in] pTouchEvent  Touch Event.CNcomment:�����¼��ṹ��
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
typedef HI_S32 (*PTR_TOUCHHOOK_CallBack)(HIGV_TOUCH_POINT_S *touchEvent);

/*
* brief Touch device register.CNcomment:�����豸ע��ӿ�
* param[in] inputDevice  Input device function.CNcomment:�����豸ע��ṹ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_NOTINIT
*/
HI_S32 HI_GV_Gesture_RegisterDevice(HIGV_TOUCH_DEVICE_INPUT_S *inputDevice);

/*
* brief Set touch callback function.CNcomment:���ô����ص����Ӻ���
* param[in] touchCallBack  Touch callback function.CNcomment:���Ӻ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_NOTINIT
*/
HI_S32 HI_GV_Gesture_SetTouchHook(PTR_TOUCHHOOK_CallBack touchCallBack);

/*
* brief Set scroll event first trigger value.CNcomment:�����״δ��������¼�����ֵ
* param[in] scrollThreshold  First trigger value.CNcomment:�����¼�����ֵ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Gesture_SetScrollFTV(HI_U32 scrollThreshold);

/*
* brief Get scroll event first trigger value.CNcomment:��ȡ�״δ��������¼�����ֵ
* param[in] scrollThreshold  First trigger value.CNcomment:�����¼�����ֵ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_NOTINIT
*/
HI_S32 HI_GV_Gesture_GetScrollFTV(HI_U32 *scrollThreshold);

/*
* brief Set scroll event trigger value.CNcomment:���÷��״δ��������¼�����ֵ
* param[in] scrollThreshold  First trigger value.CNcomment:�����¼�����ֵ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Gesture_SetScrollTV(HI_U32 scrollThreshold);

/*
* brief Get scroll event  trigger value.CNcomment:��ȡ���״δ��������¼�����ֵ
* param[in] scrollThreshold First trigger value.CNcomment:�����¼�����ֵ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_NOTINIT
*/
HI_S32 HI_GV_Gesture_GetScrollTV(HI_U32 *scrollThreshold);

/*
* brief Set gesture enable. CNcomment: ���� ��������ʹ��
* param[in] isEnable enable tag. CNcomment: ʹ�ܱ�־��HI_TRUE��ʾʹ�ܣ�HI_FALSE��ʾ���á�
* retval ::0 success
* retval ::-1 failure
* see::HI_GV_Gesture_IsEnabled
*/
HI_S32 HI_GV_Gesture_Enable(HI_BOOL isEnable);

/*
* brief Check gesture status . CNcomment: �жϴ��������Ƿ����
* retval ::HI_TRUE
* retval ::HI_FLASE
* see::HI_GV_Gesture_Enable
*/
HI_BOOL HI_GV_Gesture_IsEnabled(HI_VOID);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */
#endif
