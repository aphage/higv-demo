/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: nimation API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */
#ifndef HI_GV_ANIMATION_H
#define HI_GV_ANIMATION_H

#include "hi_type.h"
#include "hi_gv_conf.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Listener notify function */
typedef struct _HIGV_LISTENER_S HIGV_LISTENER_S;
typedef HI_VOID (*higv_notify_func_t)(HIGV_LISTENER_S *listener, void *data);

#define HIGV_ANIMATION_TWEEN_NUM 16

/* Thansition type */
typedef enum {
    HIGV_TWEEN_TRANSITION_LINEAR,  /* Linear transition */
    HIGV_TWEEN_TRANSITION_SINE,    /* Sine transition */
    HIGV_TWEEN_TRANSITION_QUINT,   /* Quint transition */
    HIGV_TWEEN_TRANSITION_QUART,   /* Quart transition */
    HIGV_TWEEN_TRANSITION_EXPO,    /* Expo transition */
    HIGV_TWEEN_TRANSITION_ELASTIC, /* Elastic transition */
    HIGV_TWEEN_TRANSITION_CUBIC,   /* Cubic transition */
    HIGV_TWEEN_TRANSITION_BOUNCE,  /* Bounce transition */
    HIGV_TWEEN_TRANSITION_BACK,    /* Back transition */
    HIGV_TWEEN_TRANSITION_BUTT
} HIGV_TWEEN_TRANSITION_E;

/* Easing type */
typedef enum {
    HIGV_TWEEN_EASE_IN,     /* Acceleration */
    HIGV_TWEEN_EASE_OUT,    /* Deceleration */
    HIGV_TWEEN_EASE_IN_OUT, /* Accelerate after the deceleration */
    HIGV_TWEEN_EASE_BUTT
} HIGV_TWEEN_EASE_E;

/*
* brief Create Tween Animation instance.
* retval Animation instance handle
* see
* ::HI_GV_TweenAnimDestroy
*/
HIGV_HANDLE HI_GV_TweenAnimCreate(HI_VOID);

/*
* brief Set Tween Animation  duration time.
* param[in] animHandle The animation instance handle
* param[in] ms  the time of delay. (unit: ms)
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
* see :: HI_GV_TweenAnimGetDuration
*/
HI_S32 HI_GV_TweenAnimSetDuration(HIGV_HANDLE animHandle, HI_U32 ms);

/*
* brief Get Tween Animation duration.
* param[in] animHandle  The animation instance handle
* param[out] duration  Animation duration
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_LOST
* see :: HI_GV_TweenAnimSetDuration
*/
HI_S32 HI_GV_TweenAnimGetDuration(HIGV_HANDLE animHandle, HI_S32 *duration);

/*
* brief Get Tween Animation curretnt  running time.
* param[in] animHandle  The animation instance handle
* param[out] currentTime  Animation runnig time
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_LOST
* see:: HI_GV_TweenAnimDestroy
*/
HI_S32 HI_GV_TweenAnimGetCurrentTime(HIGV_HANDLE animHandle, HI_S32 *currentTime);

/*
* brief Set Tween Animation curretnt  running time.
* param[in] animHandle The animation instance handle
* param[in] ms  the time of delay. (unit: ms)
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_TweenAnimSetDelay(HIGV_HANDLE animHandle, HI_U32 ms);

/*
* brief Set Tween Animation repeat loops
* param[in] animHandle The animation instance handle
* param[in] loopCount  the count of loops.
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_TweenAnimSetLoops(HIGV_HANDLE animHandle, HI_U32 loopCount);

/*
* brief  Register the animation started listener
* param[in] animHandle The animation instance handle
* param[in] func  Listener function
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_TweenAnimSetStartedListener(HIGV_HANDLE animHandle, higv_notify_func_t func);

/*
* brief  Register the animation Finished listener
* param[in] animHandle The animation instance handle
* param[in] func  Listener function
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_TweenAnimSetFinishedListener(HIGV_HANDLE animHandle, higv_notify_func_t func);

/*
* brief  Register the animation exection listener
* param[in] animHandle The animation instance handle
* param[in] func  Listener function
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_TweenAnimSetExecListener(HIGV_HANDLE animHandle, higv_notify_func_t func);

/*
* brief  Register the animation running listener
* attention:User can register this listener when need get tween value and update animation.
* param[in] animHandle The animation instance handle
* param[in] func  Listener function
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_TweenAnimStart(HIGV_HANDLE animHandle);

/*
* brief  Stop animation
* param[in] animHandle The animation instance handle
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_TweenAnimStop(HIGV_HANDLE animHandle);

/*
* brief  Resume animation
* param[in] animHandle The animation instance handle
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_TweenAnimResume(HIGV_HANDLE animHandle);

/*
* brief  Pause animation
* param[in] animHandle The animation instance handle
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_TweenAnimPause(HIGV_HANDLE animHandle);

/*
* brief Add Tween to the animation.
* param[in] animHandle The animation instance handle
* param[in] transition The transition of tween
* param[in] easing The easing of tween
* param[in] initialValue The initial value of tween
* param[in] endValue The end value of tween
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_FULL  Tween number <= HIGV_ANIMATION_TWEEN_NUM
*/
HI_S32 HI_GV_TweenAnimAddTween(HIGV_HANDLE animHandle, HIGV_TWEEN_TRANSITION_E transition,
    HIGV_TWEEN_EASE_E easing, HI_FLOAT initialValue, HI_FLOAT endValue);

/*
* brief Get Tween value of animation
* param[in] animHandle The animation instance handle
* param[in] index The tween index
* retval  Tween value
* see :: HI_GV_TweenAnimSetTweenRange
*/
HI_FLOAT HI_GV_TweenAnimGetTweenValue(HIGV_HANDLE animHandle, HI_U32 index);

/*
* brief Reset Tween range value of animation
* param[in] animHandle The animation instance handle
* param[in] index The tween index
* param[in] initialValue The initial value of tween
* param[in] endValue The end value of tween
* retval  Tween value
* see :: HI_GV_TweenAnimGetTweenValue
*/
HI_S32 HI_GV_TweenAnimSetTweenRange(HIGV_HANDLE animHandle, HI_U32 index, HI_FLOAT initialValue,
    HI_FLOAT endValue);

/*
* brief Destroy Tween Animation instance.
* param[in] animHandle The animation instance handle
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
* see:: HI_GV_TweenAnimCreate
*/
HI_S32 HI_GV_TweenAnimDestroy(HIGV_HANDLE animHandle);

/*
* brief  Create animation instance
* attention:Use animation information and widget to create instance of animation.
    * Only one animation exists at a time,Not support two animation runs at a time
* param[in] animInfo The handle of animation information
* param[in] widgetHandle  The handle of Widget which is showing
* param[out] instanceHandle  The handle of animation instance
* retval :: HI_SUCCESS is OK, other is error
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_Anim_CreateInstance(HIGV_HANDLE animInfo, HIGV_HANDLE widgetHandle, HIGV_HANDLE *instanceHandle);

/*
* brief  Destory animation instance
* attention:Destory animation instance
* param[in] windowHandle  The handle of window instance
* param[in] hInstance The handle of animation information
* retval :: HI_SUCCESS is OK, other is error
* retval ::HI_FAILURE
* see :: HI_GV_Anim_CreateInstance
*/
HI_S32 HI_GV_Anim_DestroyInstance(HIGV_HANDLE windowHandle, HIGV_HANDLE animHandle);

/**
* brief  Get information by animation instance
* attention:Get information(widget/animation information) by instance
* param[in] windowHandle  The handle of window instance
* param[in] hInstance  The handle of animation instance
* param[out] animInfoHandle The handle of animation information
* param[out] widgetHandle  The handle of Widget which is showing
* retval :: HI_SUCCESS is OK, other is error
* retval ::HI_FAILURE
* see :: HI_GV_Anim_CreateInstance
*/
HI_S32 HI_GV_Anim_GetInfo(HIGV_HANDLE windowHandle, HIGV_HANDLE animHandle,
    HIGV_HANDLE *animInfoHandle, HIGV_HANDLE *widgetHandle);

/*
* brief  Start animation
* attention:Start animation
* param[in] windowHandle  The handle of window instance
* param[in] hInstance The handle of animation instance
* retval :: HI_SUCCESS is OK, other is error
* retval ::HI_FAILURE
* see ::  HI_GV_Anim_CreateInstance
*/
HI_S32 HI_GV_Anim_Start(HIGV_HANDLE windowHandle, HIGV_HANDLE animHandle);

/*
* brief  Stop animation
* attention: Stop animation
* param[in] windowHandle  The handle of window instance
* param[in] animHandle The handle of animation instance
* retval :: HI_SUCCESS is OK, other is error
* retval ::HI_FAILURE
* see :: HI_GV_Anim_CreateInstance
*/
HI_S32 HI_GV_Anim_Stop(HIGV_HANDLE windowHandle, HIGV_HANDLE animHandle);

#ifdef __cplusplus
}
#endif
#endif
