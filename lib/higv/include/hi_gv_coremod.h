/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: coremod API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_COREMOD_H
#define HI_GV_COREMOD_H

#include "hi_type.h"
#include "hi_gv_conf.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

typedef enum {
    /* * CNcomment: CORE (HIGV_COMMON_MODID_START)
        VSYNC (HIGV_MODID_VSYNC + 14) WIDGET (HIGV_COMMON_MODID_START
       + 15) */
    HIGV_MODID_NULL = HIGV_COMMON_MODID_START,
    HIGV_MODID_WIDGET,
    HIGV_MODID_CONTAINER,
    HIGV_MODID_GC,
    HIGV_MODID_MTASK,
    HIGV_MODID_MSGM,
    HIGV_MODID_TIMER,
    HIGV_MODID_RESM,
    HIGV_MODID_IM,
    HIGV_MODID_WM,
    HIGV_MODID_DDB,
    HIGV_MODID_ADM,
    HIGV_MODID_PARSER,
    HIGV_MODID_ANIM,
    HIGV_MODID_VSYNC,
    HIGV_MODID_CORE_BUTT
} HIGV_MODID_CORE_E;

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* __HI_GV_MOD_H__ */
