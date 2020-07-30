/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: Clock API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_CLOCK_H
#define HI_GV_CLOCK_H

/* add include here */
#include <time.h>
#include "hi_gv_widget.h"
#ifdef HIGV_USE_WIDGET_CLOCK
#ifdef __cplusplus
extern "C" {
#endif

typedef struct hiHIG_TIME_S {
    HI_U32 year; /* Year , CNcomment: �� */
    HI_U32 month; /* Month , CNcomment: �� */
    HI_U32 day; /* Day , CNcomment: �� */
    HI_U32 week; /* Week , CNcomment: �� */
    HI_U32 hour; /* Hour , CNcomment: ʱ */
    HI_U32 minute; /* Minute, CNcomment: �� */
    HI_U32 second; /* Second , CNcomment: �� */
} HIGV_TIME_S;

typedef enum {
    HIGV_CURSORRES_TYPE_COLOR = 0,
    HIGV_CURSORRES_TYPE_IMAGE = 1,
    HIGV_CURSORRES_TYPE_BUTT,
} HIGV_CURSORRES_TYPE_E;

typedef enum {
    HIGV_CLOCK_MODE_TEXT = 0,
    /* User set time infomation by text , CNcomment: �û�ֱ��ͨ���ı�����ʱ�� */
    HIGV_CLOCK_MODE_FORMAT,
    /* User set time infomation by time format , CNcomment: �û�ͨ��ʱ���ʽ��ʽ����ʾʱ�� */
    HIGV_CLOCK_MODE_BUTT,
} HIGV_CLOCK_MODE_E;

typedef struct {
    HIGV_CLOCK_MODE_E
    DispMode; /* display mode ; CNcomment:clock�ؼ��Ƿ������ʾ�ͱ༭���� */
    HIGV_CURSORRES_TYPE_E
    CursorResType; /* The  cursor resource type ; CNcomment:�༭�������Դ���� */
    /* The resource ID of cursor ; CNcomment:clock�ɱ༭���ڵ���ԴID ��ͼƬ����ɫ */
    HI_U32 CursorRes;
} HIGV_CLOCK_STYLE_S;

/*
* brief Init the clock.CNcomment:��ʼ��clock�ؼ�
* param[in]  clockHandle Clock handle. CNcomment:�ؼ����
* param[in]  style The style of clock when created. CNcomment:�ؼ�������Ϣ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_EMPTY
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_Clock_Init(HIGV_HANDLE clockHandle, HIGV_CLOCK_STYLE_S *style);

/*
* brief Set the colon whether blink.CNcomment:����ʱ��ؼ���λ��ð���Ƿ���˸
* param[in]  clockHandle Clock handle.CNcomment:�ؼ����
* param[out] flash Whether blink.CNcomment:�Ƿ���˸��HI_TRUE��ʾ��˸��HI_FALSE��ʾ����˸
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Clock_SetFlash(HIGV_HANDLE clockHandle, HI_BOOL flash);

/*
* brief Set time unit of clock widget.CNcomment:����ʱ��ؼ�����С��λ
* attention ::
* CNcomment:
* (1)"second"-�룬"minute"-�֣�"hour"-ʱ��"day"-�գ�"week"-�ܣ�"month"-�£�"year"-��
* (2)���øýӿڻ��Զ�����clock�ؼ�
* param[in]  clockHandle Clock handle. CNcomment:�ؼ����
* param[out] unit  Time unit. CNcomment:���ַ�����ʾ����Сʱ�䵥λ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_EMPTY
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_Clock_SetTimeUnit(HIGV_HANDLE clockHandle, const HI_CHAR *unit);

/*
* brief Control the clock run state.CNcomment:����ʱ��ؼ���ʼ�������ʱ
* param[in]  clockHandle Clock handle. CNcomment:�ؼ����
* param[out] run  Start or stop. CNcomment:ʱ�ӿؼ����л�ֹͣ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_EMPTY  CNcomment:�û�û��������С����ʱ�䵥λ
*/
HI_S32 HI_GV_Clock_Run(HIGV_HANDLE clockHandle, HI_BOOL run);

/*
* brief Clear the content of clock.CNcomment:���ʱ�ӿؼ�������
* param[in]  clockHandle Clock handle.�ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_EMPTY
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_Clock_ClearContent(HIGV_HANDLE clockHandle);

/*
* brief Set UTC time.CNcomment:����Clock�ؼ�UTCʱ��
* param[in]  clockHandle Clock handle. CNcomment:�ؼ����
* param[in]  t UTC. CNcomment:���õ�UTCʱ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_EMPTY
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_Clock_SetUTC(HIGV_HANDLE clockHandle, time_t t);

/*
* brief Get UTC time.CNcomment:��ȡClock�ؼ�UTCʱ��
* param[in]  clockHandle Clock handle. CNcomment:�ؼ����
* param[out]  t The pointer of UTC. CNcomment:��ȡ��UTCʱ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_EMPTY
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_Clock_GetUTC(HIGV_HANDLE clockHandle, time_t *t);

/*
* brief Set the item switch step.CNcomment:������Ŀ�л�����
* attention : Only support the year item.CNcomment:ֻ��YEAR��Ŀ��Ч
* param[in]  clockHandle Clock handle. CNcomment:�ؼ����
* param[in]  step The step of switch item. CNcomment:�л�����
* param[in]  interval The interval time of switch item CNcomment:���ʱ��(Interval = 0, default:100ms)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_EMPTY
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_Clock_SetSwitchItemStep(HIGV_HANDLE clockHandle, HI_U32 step, HI_U32 interval);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_SPIN_H */
