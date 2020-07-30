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

/* 【Cursor】  CNcomment:【光标】    */
typedef struct {
    HIGV_HANDLE imageHandle; /*  The max size of cursor bitmap is 64x64, and small size is 16x16 */
    HI_U32 hotspotX; /*  The x of cursor hotspot,  CNcomment:光标热点X坐标，相对于图片 */
    HI_U32 hotspotY; /* The y of cursor hotspot ,  CNcomment:光标热点Y坐标，相对于图片 */
} HigvCursorInfo;

typedef enum {
    HIGV_CURSOR_HW = 0x1,
    HIGV_CURSOR_SW,
    HIGV_CURSOR_BUTT
} HigvCursorType;

/*
* brief Cursor init.CNcomment:鼠标初始化
* param[in] type type of cursor. CNcomment:鼠标类型
* retval ::HI_SUCCESS
* see
*/
HI_S32 HI_GV_CURSOR_Init(HigvCursorType cursorType);

/*
* brief Cursor init.CNcomment:鼠标去初始化
* param N/A.CNcomment:无
* retval ::HI_SUCCESS
* see
*/
HI_S32 HI_GV_CURSOR_DeInit(HI_VOID);

/**
* brief Show cursor.CNcomment:显示光标
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_Show(HI_VOID);

/*
* brief Hide cursor.CNcomment:隐藏光标
* attention:If you hide cursor, it will not respond the mouse event.
* CNcomment:如果光标隐藏，则将不响应mouse事件
* param N/A.CNcomment:无
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_Hide(HI_VOID);

/*
* brief Set  map scale of cursor.设置鼠标映射比例
* 例如映射图层1024*768 到720*576，则Scale_X = 720/1024, Scale_Y = 576/768
*/
HI_S32 HI_GV_CURSOR_SetMapScale(HI_FLOAT scaleX, HI_FLOAT scaleY);

/*
* brief Set the threshold of cursor. CNcomment:设置鼠标加速阀值参数CNend
* The threshold is should generate and equal 3, default is 4.
* CNcomment:加速阀值必须大于等于3，默认值4CNend
* param[in] threshold of cursor. CNcomment:鼠标加速阀值CNend
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
* see
*/
HI_S32 HI_GV_CURSOR_SetThreshold(HI_U16 threshold);

/*
* brief Set the aceleration of cursor. CNcomment:设置鼠标加速倍数CNend
* The accelation paramater is should generate 0, default is 4.
* CNcomment:加速倍数必须大于0，默认值4CNend
* param[in] acceleration Acceleration of cursor. CNcomment:鼠标加速倍数CNend
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
* see
*/
HI_S32 HI_GV_CURSOR_SetAcceleration(HI_U16 acceleration);

/*
* brief Move the cursor to the position of screen.CNcomment:移动光标到指定屏幕指定位置
* param[in] x  x coordiate of screen(unit:pixel).CNcomment:屏幕X坐标，以像素为单位
* param[in] y y coordiate of screen(unit:pixel).CNcomment:屏幕Y坐标，以像素为单位
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_SetScreenPos(HIGV_CORD screenPosX, HIGV_CORD screenPosY);

/*
* brief Get the coordiate of cursor.CNcomment:获取光标的屏幕坐标
* param[out] x x coordiate of screen(unit:pixel)CNcomment:光标的屏幕X坐标，以像素为单位
* param[out] y y coordiate of screen(unit:pixel)CNcomment:光标的屏幕Y坐标，以像素为单位
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_GetScreenPos(HIGV_CORD *screenPosX, HIGV_CORD *screenPosY);

/*
* brief Set hotspot of cursor.CNcomment:设置光标的显示图片的热点
* CNcomment:图片最小16x16，最大64x64像素，支持colorkey和alpha，其colorkey和alpha，实质是对光标所在图层操作，需要硬件支持层间colorkey和alpha
* param[in] pCursorInfo 光标图片，热点坐标信息
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_SetImage(const HigvCursorInfo *cursorInfo);

/*
* brief Get the picture infomation of cursor.CNcomment:获取光标的显示图片信息
* param[out] pCursorInfo Cursor picture information.CNcomment:光标图片，热点坐标信息
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_GetImage(HigvCursorInfo *cursorInfo);

/*
* brief Set the output of cursor.CNcomment:设置光标显示输出设备，如果存在多个输出设备，需要指定光标显示在哪个设备上
* attention:When change output device, you should hide the cursor.
* CNcomment:当改变到新输出设备时，前面的输出设备光标将隐藏，新输出设备的光标位置默认在屏幕中间
* param[in] DevID  Output device ID.CNcomment:输出设备ID
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_SetOutputDev(HI_U32 devID);

/*
* brief Set the range of cursor move.CNcomment:设置光标移动的范围
* param[in] x_pos x coordiate.CNcomment:X 坐标
* param[in] y_pos y coordiate. CNcomment:Y 坐标
* param[in] width  Width. CNcomment:宽度
* param[in] height Heigth. CNcomment:高度
* retval ::HI_SUCCESS
*/
HI_S32 HI_GV_CURSOR_SetCursorRegion(HI_S32 regionX, HI_S32 regionY, HI_S32 regionWidth, HI_S32 regionHeight);

/*
* brief Get the ouput device.CNcomment:获取光标显示输出设备，如果存在多个输出设备，需要指定光标显示显示在哪个设备上
* attention:When change output device, you should hide the cursor.
* CNcomment:当改变到新输出设备时，前面的输出设备光标将隐藏， 新输出设备的光标位置默认在屏幕中间
* param[out] devID  The pointer of output device.CNcomment:输出设备ID
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_GetOutputDev(HI_U32 *devID);

/*
* brief Set width and height of output screen. CNcomment:设置光标物理输出屏幕的宽和高
* attention:it is different between the real display and the canvas surface size.
* CNcomment:GUI内部用于绘制的图层surface的宽度和高度与屏幕实际可见高宽可能并不相同。例如:进行PAL和NTSCL转换时，
* GUI内部图层surface是720x576，输出时屏幕实际要求是720x480，最终用户看到的是由720x576通过缩放处理成720x480的图像，
* 光标的位置，也要根据比例进行相应的处理。
* param[in] devID  cursor device ID.CNcomment:光标设备ID
* param[in] w     screen width of cursor output. CNcomment:光标实际输出屏幕的宽，用户可见像素数
* param[in] h      screen height of cursor output. CNcomment:光标实际输出屏幕的高，用户可见像素数
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_SetDisplayScreen(HI_U32 devID, HI_U32 screenWidth, HI_U32 screenHight);

/*
* brief Attach the cursro to the
* layer.CNcomment:将光标绑定到图层上,光标在显示到图层之前，必须要先绑定，在绑定图层时，光标的活动显示范围基于
* 最后那次绑定的图层绘制buffer的范围
* \attention \n
* you should set the bitmap and create layer first.
* CNcomment:成功绑定，要满足条件: 先设置光标的位图信息，创建好需要的绑定图层
* param[in] layer Layer ID.CNcomment:图层id
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_AttchLayer(HIGO_LAYER_E layerId);

/*
* brief Dettach cursor from layer.CNcomment:将光标从指定图层上解绑定
* attention
* param[in] layer Layer ID.CNcomment:图层id
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_CURSOR_DettchLayer(HIGO_LAYER_E layerId);

/*
* brief set whether the cursor allways show.CNcomment:设置是否一直显示鼠标光标(即使鼠标未插入)
* attention if isCursorShow is HI_TRUE, the cursor will allways show, even if mouse is not disconnected;
* otherwise the cursor show only if the mouse conntected.
* CNcomment:如果参数isCursorShow的值为HI_TRUE,则光标一直显示(即使鼠标未插入);否则,仅当鼠标插入时才显示光标.\n
* param[in] isCursorShow is cursor allways show or not.CNcomment:设置鼠标光标是否一直显示
* retval N/A.CNcomment:无
*/
HI_VOID HI_GV_CURSOR_SetAllwaysShow(const HI_BOOL isCursorShow);

#ifdef __cplusplus
}
#endif
#endif /* HI_GV_CURSOR_H */
#endif
