/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: wheelview API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_WHEELVIEW_H
#define HI_GV_WHEELVIEW_H
#include "hi_type.h"
#include "hi_gv_conf.h"
#include "hi_gv_widget.h"

#ifdef HIGV_USE_WIDGET_WHEELVIEW
/* add include here */
#include "hi_gv_resm.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    HI_U32 rowNum; /* The count of display item ; CNcomment: 屏幕上显示的行数 */
    HIGV_HANDLE dataModel; /* Data Model Handle ; CNcomment:  数据模型句柄 */
    HIGV_HANDLE upCoverSkin; /* Up Cover Skin ; CNcomment: 上覆盖皮肤句柄 */
    HIGV_HANDLE downCoverSkin; /* Down Cover Skin; CNcomment: 下覆盖皮肤句柄 */
    HI_BOOL isCircleScroll; /* Circle tag ; CNcomment: 循环滚动标志 */
    HI_FLOAT scrollParam; /* Scroll Param ; CNcomment: 滑动灵敏度系数 */
    HI_FLOAT flingParam; /* Fling Param ; CNcomment: 轻扫灵敏度系数 */
    HI_U32 leftMargin; /* Left margin ; CNcomment:  左边距 */
    HI_U32 rightMargin; /* Right margin ; CNcomment:  右边距 */
    HI_U32 topMargin; /* Up margin ; CNcomment:  上边距 */
    HI_U32 btmMargin; /* Bottom margin ; CNcomment:  下边距 */
} HigvWheelViewStyle;

/*
* brief Create wheelview.CNcomment:WheelView控件初始化
* param[in] creatInfo    The Layout infomation of wheelview. CNcomment:控件风格布局属性指针
* param[out] wheelViewHandle   the pointer of wheelview handle. CNcomment:WheelView控件句柄指针
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_INVA
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_WheelView_Create(const HIGV_WCREATE_S *creatInfo, HIGV_HANDLE *wheelViewHandle);

/*
* brief Set selected item of  wheelview. CNcomment: 设置 WheelView当前条目
* param[in] wheelViewHandle WheelView handle. CNcomment: 控件句柄
* param[in] item  Item index.CNcomment: 条目编号
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_WheelView_GetSelItem
*/
HI_S32 HI_GV_WheelView_SetSelItem(HIGV_HANDLE wheelViewHandle, HI_U32 item);

/*
* brief Get the item of WheelView.CNcomment: 获取WheelView当前条目
* param[in] wheelViewHandle  WheelView handle.CNcomment: 控件句柄
* param[out] item Item index.CNcomment: 条目编号
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_WheelView_SetSelItem
*/
HI_S32 HI_GV_WheelView_GetSelItem(HIGV_HANDLE wheelViewHandle, HI_U32 *item);

/*
* brief Get the total item number of WheelView.CNcomment: 获取WheelView当前数据总条数
* param[in]  wheelViewHandle  WheelView handle. CNcomment:  控件句柄
* param[out] itemNum Toal item number.CNcomment: 总条目数
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_GetItemNum(HIGV_HANDLE wheelViewHandle, HI_U32 *itemNum);

/*
* brief Set up image resource.CNcomment:设置上遮挡皮肤资源
* param[in] wheelViewHandle Image handle.CNcomment:控件句柄
* param[in] handleRes The resource ID of image.CNcomment:图片资源句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_SetUpImage(HIGV_HANDLE wheelViewHandle, HI_RESID handleRes);

/*
* brief Set up image resource.CNcomment:设置下遮挡皮肤资源
* param[in] wheelViewHandle Image handle.CNcomment:控件句柄
* param[in] handleRes The resource ID of image.CNcomment:图片资源句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_SetDownImage(HIGV_HANDLE wheelViewHandle, HI_RESID handleRes);

/*
* brief Enable wheelview touch.CNcomment:设置允许触摸功能
* param[in] wheelViewHandle Image handle.CNcomment:控件句柄
* param[in] enable  Enable flag.CNcomment: 使能标志，HI_TRUE表示使能，HI_FALSE表示去使能
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_Enable(HIGV_HANDLE wheelViewHandle, HI_BOOL enable);

/*
* brief Is touch enable.CNcomment:获取是否允许触摸状态
* param[in] wheelViewHandle Image handle.CNcomment:控件句柄
* retval ::HI_TRUE  Touch is Enable.CNcomment: 触摸可用
* retval ::HI_FALSE Touch is Disable.CNcomment: 触摸禁用
*/
HI_BOOL HI_GV_WheelView_IsEnable(HIGV_HANDLE wheelViewHandle);

/*
* rief Set scroll param.CNcomment:设置滑动灵敏度系数(默认为1.0，大于等于1.0)
* param[in] wheelViewHandle wheelview handle.    CNcomment:控件句柄
* param[in] scrollParam scroll index.    CNcomment:滑动灵敏度系数
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_SetScrollParam(HIGV_HANDLE wheelViewHandle, HI_FLOAT scrollParam);

/*
* brief Set fling param.CNcomment:设置轻扫灵敏度系数(默认为1.0，大于等于1.0)
* param[in] wheelViewHandle wheelview handle.    CNcomment:控件句柄
* param[in] flingParam fling index.    CNcomment:轻扫灵敏度系数
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_SetFlingParam(HIGV_HANDLE wheelViewHandle, HI_FLOAT flingParam);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_WHEELVIEW_H */
