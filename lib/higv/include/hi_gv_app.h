/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: app API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_APP_H
#define HI_GV_APP_H

/* add include here */
#include "hi_type.h"
#include "hi_gv_conf.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Key hook go on ; CNcomment:按键继续往下传递 */
#define HI_GV_KEYHOOK_GOON 0x1000
/* Key hook stop ; CNcomment:按键停止往下传递 */
#define HI_GV_KEYHOOK_STOP 0x1001

/* The max static handle number for app ; CNcomment: 提供应用使用的静态句柄个数 */
#define HIGV_RESERVE_STATIC_HANDLE_NUM 1000

typedef enum {
    COMM_LEVEL_EMERGENCY = 0, /*  emergency event */
    COMM_LEVEL_NOTIFY,        /*  notify event */
    COMM_LEVEL_BUTT
} COMM_LEVEL_E;

typedef struct {
    HI_U32 id;          /*  message sequence id */
    HI_U32 msg;         /*  message type */
    COMM_LEVEL_E level; /*  message level */
} COMM_MSG_S;

typedef void (*COMM_MSG_HANDLER)(COMM_MSG_S *pmsg);
typedef void (*COMM_ERR_HANDLER)(void);

typedef enum {
    HIGV_VSYNC_HW = 0, /*  hardware vsync signal */
    HIGV_VSYNC_SW,     /*  software vsync signal */
    HIGV_VSYNC_BUTT
} HIGV_VSYNC_E;

/*
* brief Callback of key hook.CNcomment:按键钩子回调函数
* param[in] MsgId  Message ID.CNcomment:消息ID，MSG_KEYDOWN或MSG_KEYUP
* param[in] Param1 Paramater 1, key value.CNcomment:消息参数1，按键值
* param[in] Param2 Paramater 2, key status.CNcomment:消息参数2，特殊键状态(预留)
* retval ::HI_SUCCESS
* retval ::HI_GV_KEYHOOK_GOON
* retval ::HI_GV_KEYHOOK_STOP
*/
typedef HI_S32 (*PTR_KEYHOOK_CallBack)(HI_U32 MsgId, HI_PARAM Param1, HI_PARAM Param2);

/*
* brief Create application.CNcomment:创建HiGV应用程序实例
* attention : A application correspoding a message.
* CNcomment:一个应用程序实例对应一个消息循环
* param[in] name  Application name.CNcomment:无应用程序名，不可为空
* param[in] appHandle Application handle. CNcomment:无应用程序实例句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_MSGM_VTOPMSGCREATE
* retval ::HI_ERR_COMM_NORES
* see :: HI_GV_App_Destroy
*/
HI_S32 HI_GV_App_Create(const HI_CHAR *name, HIGV_HANDLE *appHandle);

/*
* brief Start application.CNcomment:启动应用程序
* attention : The app will not accept any message if you not start the app.
* CNcomment:未启动之前无法收到任何消息
* param[in] appHandle Application handle.CNcomment:应用程序实例句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_NORES
* see :: HI_GV_App_Stop
*/
HI_S32 HI_GV_App_Start(HIGV_HANDLE appHandle);

/*
* brief Stop the application.CNcomment:停止应用程序消息循环
* param[in] appHandle Application instance.CNcomment:应用程序实例句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* see :: HI_GV_App_Start
*/
HI_S32 HI_GV_App_Stop(HIGV_HANDLE appHandle);

/*
* brief Destroy the application.CNcomment:销毁应用程序实例
* param[in] appHandle CNcomment:应用程序实例句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_TASK_TASKNOTSTOP
* see:: HI_GV_App_Create
*/
HI_S32 HI_GV_App_Destroy(HIGV_HANDLE appHandle);

/*
* brief Acitve higv app to display on screen.CNcomment: 激活APP，使得该APP可以显示到屏幕上
* When Mutile higv app start up on the same time, This only suport one active app display on the sceen.
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
* see:: HI_GV_App_DeActive
*/
HI_S32 HI_GV_App_Active(HI_VOID);

/*
* brief Enabel app run in background.CNcomment:激活 应用后台运行
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
* see :: HI_GV_App_DeActive
*/
HI_S32 HI_GV_App_DeActive(HI_VOID);

/*
* brief Get the app wether active CNcomment:获取应用是否处于前台运行状态
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
* see:
* HI_GV_App_Active
* HI_GV_App_DeActive
*/
HI_BOOL HI_GV_App_IsActive(HI_VOID);

/*
* brief Init HIGV.CNcomment:初始化HiGV
* retval ::HI_SUCCESS
* retval ::HI_ERR_MSGM_VTOPMSGSERVER
* retval ::HI_ERR_COMM_OTHER
* see :: HI_GV_Deinit
*/
HI_S32 HI_GV_Init(HI_VOID);

/*
* brief Deinit HIGV.CNcomment:去初始化HiGV
* see::HI_GV_Init
*/
HI_VOID HI_GV_Deinit(HI_VOID);

/*
* brief Set key hook.CNcomment:设置键盘钩子回调函数
* param[in] callBackFunction Callback.CNcomment: 回调函数
* retval ::HI_SUCCESS
*/
HI_S32 HI_GV_SetKeyHook(PTR_KEYHOOK_CallBack callBackFunction);

/*
* brief Set the max value of handle.CNcomment:设置静态指定的Handle的最大值，只能指定一次
* param[in] maxHandle Handle CNcomment:最大值
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_SetMaxAssignHandle(HIGV_HANDLE maxHandle);

/* brief Get the reserved start static handle. CNcomment: 获取控件构造树保留的静态handle起始值 */
HIGV_HANDLE HI_GV_GetReserveStartStaticHandle(HI_VOID);

/*
* brief Get the version of HIGV. CNcomment:获取HIGV的版本号
* param[out] version HIGV Version.CNcomment:HIGV的版本号，由本地svn版本号 +  编译时间组成的浮点数
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_GetVersion(HI_DOUBLE *version);

/*
* brief Set the type of  vsync. CNcomment:设置VSYNC的信号源类型
* param[in] vsyncType  vsync type.CNcomment: vsync信号源类型
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_PAERM
*/
HI_S32 HI_GV_SetVsyncType(HIGV_VSYNC_E vsyncType);

/*
* brief Get the type of  vsync. CNcomment:获取VSYNC的信号源类型
* retval ::HIGV_VSYNC_HW
* retval ::HIGV_VSYNC_SW
*/
HIGV_VSYNC_E HI_GV_GetVsyncType(HI_VOID);

/*
* brief Set the period of software vsync. CNcomment:设置软件VSYNC的信号周期
* param[in] vsyncPeriod  Sw vsync period.CNcomment:VSYNC周期,单位us
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_SetSWVsyncPeriod(HI_S64 vsyncPeriod);

/*
* brief Get the period of software vsync. CNcomment:获取软件VSYNC的信号周期
* param[out] vsyncPeriod Sw vsync period.CNcomment:VSYNC周期指针,单位us
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_GetSWVsyncPeriod(HI_S64 *vsyncPeriod);

/*
* brief Set vsync lost frame policy. CNcomment:设置VSYNC丢帧策略
* param[in] isLostFrame Is lost frame.CNcomment:是否丢帧，HI_TRUE表示丢帧策略，HI_FALSE表示不丢帧策略
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_SetVsyncLostFrame(HI_BOOL isLostFrame);

/*
* brief Is vsync lost frame. CNcomment:获取VSYNC的丢帧策略
* retval ::HI_TRUE表示丢帧
* retval ::HI_FALSE表示不丢帧
*/
HI_BOOL HI_GV_IsVsyncLostFrame(HI_VOID);

/*
* brief Set the threshold of lost frame. CNcomment:设置VSYNC丢帧的阈值
* param[in] u32Threshold Lost frame threshold.CNcomment:丢帧的阈值,单位us
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_SetLostFrameThreshold(HI_U32 u32Threshold);

/*
* brief Get the threshold of lost frame. CNcomment:获取VSYNC丢帧的阈值
* param[out] u32Threshold Lost frame threshold.CNcomment:丢帧的阈值,单位us
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_GetLostFrameThreshold(HI_U32 *u32Threshold);

/*
* brief Sync the render cmd. CNcomment:Render命令同步接口，执行这个接口会阻塞，直到Render命令执行完成。
* retval ::HI_SUCCESS
*/
HI_S32 HI_GV_RenderCmdSync(HI_VOID);

/*
* brief Set render refresh cmd combine. CNcomment:设置Refresh命令是否合并
* param[in] isCombine Is combine.CNcomment:是否合并，HI_TRUE表示合并，HI_FALSE表示不合并
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_SetRefreshCombine(HI_BOOL isCombine);

/*
* brief Is refresh cmd combine. CNcomment:获取Refresh命令是否合并状态
* retval ::HI_TRUE表示合并
* retval ::HI_FALSE表示不合并
*/
HI_BOOL HI_GV_IsRefreshCombine(HI_VOID);

/*
* brief Set render refresh cmd combine. CNcomment:设置是否进行同步绘制，即绘制和刷新都使用UI线程，而不用单独的绘制线程，默认方式是异步绘制
* 此接口在HI_GV_Init初始化之前调用
* param[in] isSync Is sync.CNcomment:是否同步，HI_TRUE表示同步，HI_FALSE表示异步
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_SetSyncDraw(HI_BOOL isSync);

#ifdef __cplusplus
}
#endif
#endif /* HI_GV_APP_H */
