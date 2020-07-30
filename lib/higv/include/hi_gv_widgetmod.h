/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2019. All rights reserved.
 * Description: HIGV LOG Moudle
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_WIDGETMOD_H
#define HI_GV_WIDGETMOD_H

#include "hi_type.h"
#include "hi_gv_coremod.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

typedef enum {  /*  CNcomment:  CORE (HIGV_COMMON_MODID_START)  VSYNC (HIGV_COMMON_MODID_START + 14) WIDGET
                        (HIGV_COMMON_MODID_START + 15) */
    HIGV_MODID_GROUPBOX = HIGV_COMMON_MODID_START + 15,
    HIGV_MODID_WIN,
    HIGV_MODID_MSGBOX,
    HIGV_MODID_BUTTON,
    HIGV_MODID_EDIT,
    HIGV_MODID_MULTIEDIT,
    HIGV_MODID_LABEL,
    HIGV_MODID_PROGRESSBAR,
    HIGV_MODID_LIST,
    HIGV_MODID_SCROLLBAR,
    HIGV_MODID_SCROLLGRID,
    HIGV_MODID_IMSY,
    HIGV_MODID_SCROLLTEXT,
    HIGV_MODID_IMAGE,
    HIGV_MODID_IMAGEEX,
    HIGV_MODID_GRID,
    HIGV_MODID_CLOCK,
    HIGV_MODID_IPEDIT,
    HIGV_MODID_COMBOBOX,
    HIGV_MODID_IMEWINDOW,
    HIGV_MODID_CONTAINERWIDGET,
    HIGV_MODID_SCROLLVIEW,
    HIGV_MODID_SLIDEUNLOCK,
    HIGV_MODID_WHEELVIEW,

    HIGV_MODID_WIDGET_BUTT
} HIGV_MODID_WIDGET_E;

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* HI_GV_MOD_H */
