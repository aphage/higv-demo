#ifndef HI_GV_CONF_H
#define HI_GV_CONF_H

typedef unsigned int HIGV_HANDLE;

#ifdef __LP64__
typedef unsigned long long  HI_PARAM;
typedef struct
{
    long long  x;
    long long  y;
    long long  w;
    long long  h;
} HIGV_RECT_WRAPPER;
#else
typedef unsigned int HI_PARAM;
typedef struct
{
    int x;
    int y;
    int w;
    int h;
} HIGV_RECT_WRAPPER;
#endif

#ifndef HIGV_UNUSED
#define HIGV_UNUSED(expr) \
    do {                  \
        (void)expr;       \
    } while (0)
#endif

typedef HI_PARAM HIGV_COLOR_WRAPPER;

#define HIGV_COMMON_MODID_START 50
#define HIGV_PERFORMACE 1

#define HIGV_USE_TOUCHSCREEN_INPUT  1
#define HIGV_NOT_REGISTER_ALLWIDGET
#define HIGV_USE_WIDGET_BUTTON 1
#define HIGV_USE_WIDGET_SCROLLBAR 1
#define HIGV_USE_WIDGET_LABEL 1
#define HIGV_USE_WIDGET_IMAGE 1
#define HIGV_USE_WIDGET_IMAGEEX 1
#define HIGV_USE_WIDGET_PROGRESSBAR 1
#define HIGV_USE_WIDGET_SCROLLTEXT 1
#define HIGV_USE_WIDGET_SCROLLGRID 1
#define HIGV_USE_WIDGET_CLOCK 1
#define HIGV_USE_WIDGET_LISTBOX 1
#define HIGV_USE_WIDGET_TRACKBAR 1
#define HIGV_USE_WIDGET_SLIDEUNLOCK 1
#define HIGV_USE_WIDGET_WHEELVIEW 1
#define HIGV_USE_MODULE_TOUCH 1
#define HIGV_USE_WIDGET_SCROLLVIEW 1
#define HIGV_USE_MODULE_IME 1
#define HIGV_USE_MODULE_CURSOR 1
#define HIGV_USE_WIDGET_EDIT 1
#define HIGV_USE_WIDGET_SCALEVIEW 1
#define HIGV_USE_WIDGET_MSGBOX 1
#define HIGV_USE_WIDGET_CHARTS 1
#endif  // HI_GV_CONF_H
