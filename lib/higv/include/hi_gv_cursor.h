/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: Cursor API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_CURSOR_H
#define HI_GV_CURSOR_H

#include "hi_type.h"
#include "hi_gv_conf.h"
#include "hi_gv_widget.h"

#ifdef HIGV_USE_MODULE_CURSOR

#ifdef __cplusplus
extern "C" {
#endif

#define IMAGE_MAX_SIZE  64
#define IMAGE_MIN_SIZE  16

/* ��Cursor��  CNcomment:����꡿    */
typedef struct {
    HIGV_HANDLE imageHandle; /*  The max size of cursor bitmap is 64x64, and small size is 16x16 */
    HI_U32 hotspotX; /*  The x of cursor hotspot,  CNcomment:����ȵ�X���꣬�����ͼƬ */
    HI_U32 hotspotY; /* The y of cursor hotspot ,  CNcomment:����ȵ�Y���꣬�����ͼƬ */
} HigvCursorInfo;

typedef enum {
    HIGV_CURSOR_HW = 0x1,
    HIGV_CURSOR_SW,
    HIGV_CURSOR_BUTT
} HigvCursorType;

/*
* brief Cursor init.CNcomment:����ʼ��
* param[in] type type of cursor. CNcomment:�������
* retval ::HI_SUCCESS
* see
*/
HI_S32 HI_GV_CURSOR_Init(HigvCursorType cursorType);

/*
* brief Cursor init.CNcomment:���ȥ��ʼ��
* param N/A.CNcomment:��
* retval ::HI_SUCCESS
* see
*/
HI_S32 HI_GV_CURSOR_DeInit(HI_VOID);

/**
* brief Show cursor.CNcomment:��ʾ���
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_Show(HI_VOID);

/*
* brief Hide cursor.CNcomment:���ع��
* attention:If you hide cursor, it will not respond the mouse event.
* CNcomment:���������أ��򽫲���Ӧmouse�¼�
* param N/A.CNcomment:��
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_Hide(HI_VOID);

/*
* brief Set  map scale of cursor.�������ӳ�����
* ����ӳ��ͼ��1024*768 ��720*576����Scale_X = 720/1024, Scale_Y = 576/768
*/
HI_S32 HI_GV_CURSOR_SetMapScale(HI_FLOAT scaleX, HI_FLOAT scaleY);

/*
* brief Set the threshold of cursor. CNcomment:���������ٷ�ֵ����CNend
* The threshold is should generate and equal 3, default is 4.
* CNcomment:���ٷ�ֵ������ڵ���3��Ĭ��ֵ4CNend
* param[in] threshold of cursor. CNcomment:�����ٷ�ֵCNend
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
* see
*/
HI_S32 HI_GV_CURSOR_SetThreshold(HI_U16 threshold);

/*
* brief Set the aceleration of cursor. CNcomment:���������ٱ���CNend
* The accelation paramater is should generate 0, default is 4.
* CNcomment:���ٱ����������0��Ĭ��ֵ4CNend
* param[in] acceleration Acceleration of cursor. CNcomment:�����ٱ���CNend
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
* see
*/
HI_S32 HI_GV_CURSOR_SetAcceleration(HI_U16 acceleration);

/*
* brief Move the cursor to the position of screen.CNcomment:�ƶ���굽ָ����Ļָ��λ��
* param[in] x  x coordiate of screen(unit:pixel).CNcomment:��ĻX���꣬������Ϊ��λ
* param[in] y y coordiate of screen(unit:pixel).CNcomment:��ĻY���꣬������Ϊ��λ
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_SetScreenPos(HIGV_CORD screenPosX, HIGV_CORD screenPosY);

/*
* brief Get the coordiate of cursor.CNcomment:��ȡ������Ļ����
* param[out] x x coordiate of screen(unit:pixel)CNcomment:������ĻX���꣬������Ϊ��λ
* param[out] y y coordiate of screen(unit:pixel)CNcomment:������ĻY���꣬������Ϊ��λ
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_GetScreenPos(HIGV_CORD *screenPosX, HIGV_CORD *screenPosY);

/*
* brief Set hotspot of cursor.CNcomment:���ù�����ʾͼƬ���ȵ�
* CNcomment:ͼƬ��С16x16�����64x64���أ�֧��colorkey��alpha����colorkey��alpha��ʵ���ǶԹ������ͼ���������ҪӲ��֧�ֲ��colorkey��alpha
* param[in] pCursorInfo ���ͼƬ���ȵ�������Ϣ
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_SetImage(const HigvCursorInfo *cursorInfo);

/*
* brief Get the picture infomation of cursor.CNcomment:��ȡ������ʾͼƬ��Ϣ
* param[out] pCursorInfo Cursor picture information.CNcomment:���ͼƬ���ȵ�������Ϣ
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_GetImage(HigvCursorInfo *cursorInfo);

/*
* brief Set the output of cursor.CNcomment:���ù����ʾ����豸��������ڶ������豸����Ҫָ�������ʾ���ĸ��豸��
* attention:When change output device, you should hide the cursor.
* CNcomment:���ı䵽������豸ʱ��ǰ�������豸��꽫���أ�������豸�Ĺ��λ��Ĭ������Ļ�м�
* param[in] DevID  Output device ID.CNcomment:����豸ID
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_SetOutputDev(HI_U32 devID);

/*
* brief Set the range of cursor move.CNcomment:���ù���ƶ��ķ�Χ
* param[in] x_pos x coordiate.CNcomment:X ����
* param[in] y_pos y coordiate. CNcomment:Y ����
* param[in] width  Width. CNcomment:���
* param[in] height Heigth. CNcomment:�߶�
* retval ::HI_SUCCESS
*/
HI_S32 HI_GV_CURSOR_SetCursorRegion(HI_S32 regionX, HI_S32 regionY, HI_S32 regionWidth, HI_S32 regionHeight);

/*
* brief Get the ouput device.CNcomment:��ȡ�����ʾ����豸��������ڶ������豸����Ҫָ�������ʾ��ʾ���ĸ��豸��
* attention:When change output device, you should hide the cursor.
* CNcomment:���ı䵽������豸ʱ��ǰ�������豸��꽫���أ� ������豸�Ĺ��λ��Ĭ������Ļ�м�
* param[out] devID  The pointer of output device.CNcomment:����豸ID
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_GetOutputDev(HI_U32 *devID);

/*
* brief Set width and height of output screen. CNcomment:���ù�����������Ļ�Ŀ�͸�
* attention:it is different between the real display and the canvas surface size.
* CNcomment:GUI�ڲ����ڻ��Ƶ�ͼ��surface�Ŀ�Ⱥ͸߶�����Ļʵ�ʿɼ��߿���ܲ�����ͬ������:����PAL��NTSCLת��ʱ��
* GUI�ڲ�ͼ��surface��720x576�����ʱ��Ļʵ��Ҫ����720x480�������û�����������720x576ͨ�����Ŵ����720x480��ͼ��
* ����λ�ã�ҲҪ���ݱ���������Ӧ�Ĵ���
* param[in] devID  cursor device ID.CNcomment:����豸ID
* param[in] w     screen width of cursor output. CNcomment:���ʵ�������Ļ�Ŀ��û��ɼ�������
* param[in] h      screen height of cursor output. CNcomment:���ʵ�������Ļ�ĸߣ��û��ɼ�������
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_SetDisplayScreen(HI_U32 devID, HI_U32 screenWidth, HI_U32 screenHight);

/*
* brief Attach the cursro to the
* layer.CNcomment:�����󶨵�ͼ����,�������ʾ��ͼ��֮ǰ������Ҫ�Ȱ󶨣��ڰ�ͼ��ʱ�����Ļ��ʾ��Χ����
* ����Ǵΰ󶨵�ͼ�����buffer�ķ�Χ
* \attention \n
* you should set the bitmap and create layer first.
* CNcomment:�ɹ��󶨣�Ҫ��������: �����ù���λͼ��Ϣ����������Ҫ�İ�ͼ��
* param[in] layer Layer ID.CNcomment:ͼ��id
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_AttchLayer(HIGO_LAYER_E layerId);

/*
* brief Dettach cursor from layer.CNcomment:������ָ��ͼ���Ͻ��
* attention
* param[in] layer Layer ID.CNcomment:ͼ��id
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_DettchLayer(HIGO_LAYER_E layerId);

/*
* brief set whether the cursor allways show.CNcomment:�����Ƿ�һֱ��ʾ�����(��ʹ���δ����)
* attention if isCursorShow is HI_TRUE, the cursor will allways show, even if mouse is not disconnected;
* otherwise the cursor show only if the mouse conntected.
* CNcomment:�������isCursorShow��ֵΪHI_TRUE,����һֱ��ʾ(��ʹ���δ����);����,����������ʱ����ʾ���.\n
* param[in] isCursorShow is cursor allways show or not.CNcomment:����������Ƿ�һֱ��ʾ
* retval N/A.CNcomment:��
*/
HI_VOID HI_GV_CURSOR_SetAllwaysShow(const HI_BOOL isCursorShow);

#ifdef __cplusplus
}
#endif
#endif /* HI_GV_CURSOR_H */
#endif
