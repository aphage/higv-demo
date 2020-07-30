/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2019. All rights reserved.
 * Description: HiGV API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_H
#define HI_GV_H

#include <stdio.h>
#if HI_OS_TYPE == HI_OS_LINUX
#include <sys/time.h>
#endif
#include "hi_go.h"
#include "hi_gv_conf.h"
#include "hi_gv_errno.h"
#include "hi_gv_mlayer.h"
#include "hi_gv_app.h"
#include "hi_gv_msg.h"
#include "hi_gv_resm.h"
#include "hi_gv_timer.h"
#include "hi_gv_widget.h"
#include "hi_gv_gesture.h"
#include "hi_gv_animation.h"
#include "hi_gv_lan.h"
#include "hi_gv_ddb.h"

#ifdef HIGV_USE_WIDGET_PROGRESSBAR
#include "hi_gv_progressbar.h"
#endif

#ifdef HIGV_USE_WIDGET_EDIT
#include "hi_gv_edit.h"
#endif

#include "hi_gv_win.h"
#include "hi_gv_timer.h"
#include "hi_gv_wm.h"

#ifdef HIGV_USE_WIDGET_SCROLLTEXT
#include "hi_gv_scrolltext.h"
#endif

#ifdef HIGV_USE_WIDGET_IMAGE
#include "hi_gv_image.h"
#endif

#ifdef HIGV_USE_WIDGET_IMAGEEX
#include "hi_gv_imageex.h"
#endif

#ifdef HIGV_USE_WIDGET_CLOCK
#include "hi_gv_clock.h"
#endif

#ifdef HIGV_USE_WIDGET_LISTBOX
#include "hi_gv_listbox.h"
#endif

#if defined(HIGV_USE_WIDGET_IPEDIT) && defined(HIGV_USE_WIDGET_EDIT)
#include "hi_gv_ipedit.h"
#endif

#ifdef HIGV_USE_WIDGET_SCROLLBAR
#include "hi_gv_scrollbar.h"
#endif

#ifdef HIGV_USE_WIDGET_SCROLLBOX
#include "hi_gv_scrollbox.h"
#endif

#ifdef HIGV_USE_MODULE_CURSOR
#include "hi_gv_cursor.h"
#endif
#ifdef HIGV_USE_WIDGET_TRACKBAR
#include "hi_gv_trackbar.h"
#endif

#if defined(HIGV_USE_WIDGET_MSGBOX) && defined(HIGV_USE_WIDGET_BUTTON) && defined(HIGV_USE_WIDGET_IMAGE) && \
    defined(HIGV_USE_WIDGET_LABEL)
#include "hi_gv_msgbox.h"
#endif

#ifdef HIGV_USE_MODULE_IME
#include "hi_gv_imewindow.h"
#endif

#ifdef HIGV_USE_WIDGET_MULTIEDIT
#include "hi_gv_multiedit.h"
#endif

#ifdef HIGV_USE_WIDGET_SCROLLVIEW
#include "hi_gv_scrollview.h"
#endif

#ifdef HIGV_USE_WIDGET_SCROLLGRID
#include "hi_gv_scrollgrid.h"
#endif

#ifdef HIGV_USE_WIDGET_SLIDEUNLOCK
#include "hi_gv_slideunlock.h"
#endif

#ifdef HIGV_USE_WIDGET_WHEELVIEW
#include "hi_gv_wheelview.h"
#endif

#ifdef HIGV_USE_WIDGET_SCALEVIEW
#include "hi_gv_scaleview.h"
#endif

#ifdef HIGV_USE_WIDGET_IMAGEVIEW
#include "hi_gv_imageview.h"
#endif

#endif /* HI_GV_H */
