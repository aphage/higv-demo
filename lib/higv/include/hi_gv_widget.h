/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020 All rights reserved.
 * Description: Widget moudle API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_WIDGET_H
#define HI_GV_WIDGET_H

#include "hi_gv_conf.h"
#include "hi_go.h"
#include "hi_gv_errno.h"
#include "hi_gv_resm.h"

#ifdef HIGV_USE_WIDGET_BUTTON
#include "hi_gv_button.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* *Widget type */
/* *CNcomment: �ؼ����Ͷ��� */
typedef enum HI_WIDGET {
    /* <window CNcomment: ���ڿؼ� */
    HIGV_WIDGET_WINDOW = 0,
    /* <containder  <CNcomment: �����ؼ� */
    HIGV_WIDGET_CONTAINER = 1,
    /* <button <CNcomment: Button�ؼ� */
    HIGV_WIDGET_BUTTON = 2,
    /* <label <CNcomment: Label�ؼ� */
    HIGV_WIDGET_LABEL = 3,
    /* <image CNcomment: Image�ؼ� */
    HIGV_WIDGET_IMAGE = 4,
    /* <extend image <CNcomment: ��չImage�ؼ� */
    HIGV_WIDGET_IMAGEEX = 5,
    /* <grid <CNcomment: Grid�ؼ� */
    HIGV_WIDGET_GRID = 6,
    /* <groupbox <CNcomment: Groupbox�ؼ� */
    HIGV_WIDGET_GROUPBOX = 7,
    /* <scrollbar <CNcomment: Scrollbar�ؼ� */
    HIGV_WIDGET_SCROLLBAR = 8,
    /* <edit <CNcomment: Edit�ؼ� */
    HIGV_WIDGET_EDIT = 9,
    /* <spin box *<CNcomment: Spinbox�ؼ� */
    HIGV_WIDGET_SPINBOX = 10,
    /* <progressbar <CNcomment: Progressbar�ؼ� */
    HIGV_WIDGET_PROGRESS = 11,
    /* <scrollbox <CNcomment: Scrollbox�ؼ� */
    HIGV_WIDGET_SCROLLBOX = 12,
    /* <scrolltext <CNcomment: Scrolltext�ؼ� */
    HIGV_WIDGET_SCROLLTEXT = 13,
    /* <image cipher <CNcomment: Imagecipher�ؼ� */
    HIGV_WIDGET_IMAGECIPHER = 14,
    /* <clock <CNcomment: Clock�ؼ� */
    HIGV_WIDGET_CLOCK = 15,
    /* <listbox <CNcomment: Listbox�ؼ� */
    HIGV_WIDGET_LISTBOX = 16,
    /* <timetrack <CNcomment: ʱ����ؼ� */
    HIGV_WIDGET_TIMETRACK = 17,
    /* <scrollgrid <CNcomment: ScrollGrid�ؼ� */
    HIGV_WIDGET_SCROLLGRID = 18,
    /* <trackbar <CNcomment:TrackBar�ؼ� */
    HIGV_WIDGET_TRACKBAR = 19,
    /* <ipedit <CNcomment:IpEdit�ؼ� */
    HIGV_WIDGET_IPEDIT = 20,
    /* <calendar <CNcomment: �����ؼ� */
    HIGV_WIDGET_CALENDAR = 21,
    /* <videoshelter<CNcomment: ��Ƶ�ڵ��ؼ� */
    HIGV_WIDGET_VIDEOSHELTER = 22,
    /* <movemonito <CNcomment: �ƶ���ؿؼ� */
    HIGV_WIDGET_MOVEMONITOR = 23,
    /* <combobox <CNcomment:��Ͽ�ؼ� */
    HIGV_WIDGET_COMBOBOX = 24,
    /* <pop window of combobox <CNcomment: �๦�ܴ��� */
    HIGV_WIDGET_CPOPBOX = 25,
    /* <input method window  <CNcomment: ���뷨���� */
    HIGV_WIDGET_IMEWINDOW = 26,
    /* <timebar  <CNcomment: ʱ����ؼ� */
    HIGV_WIDGET_TIMEBAR = 27,
    /* <dialog box  CNcomment: �Ի���ؼ� */
    HIGV_WIDGET_MSGBOX = 28,
    /* <multi edit <CNcomment: ���б༭��ؼ� */
    HIGV_WIDGET_MULTIEDIT = 29,
    /* <scroll view  <CNcomment: ������ͼ */
    HIGV_WIDGET_SCROLLVIEW = 30,
    /* <content box  <CNcomment: ���ݺ��� */
    HIGV_WIDGET_CONTENTBOX = 31,
    /* <slide unlock  CNcomment: �������� */
    HIGV_WIDGET_SLIDEUNLOCK = 32,
    /* <wheel view <CNcomment: ����ѡ���� */
    HIGV_WIDGET_WHEELVIEW = 33,
    /* <image view <CNcomment: ��ͼƬ��ʾ  */
    HIGV_WIDGET_IMAGEVIEW = 34,
    /* <image view <CNcomment:����Ŵ�ؼ� */
    HIGV_WIDGET_SCALEVIEW = 35,
   /* <charts view <CNcomment:ͼ��ؼ� */
    HIGV_WIDGET_CHARTS  = 36,
    HIGV_WIDGET_BUTT
} HIGV_WIDGET_E;

typedef struct {
    HI_U32 style;
    const HI_RECT *rect;
    HIGV_HANDLE parentHandle;
    HI_U32 level;
} WidgetBasicParam;

/* The sequence of user defined widget */ /* CNcomment:�û��Զ���ؼ���ID��ʼ */
#define HIGV_EXTWIDGET_START HIGV_WIDGET_BUTT
/* The callback of user defined widget; CNcomment:�û��Զ���ؼ������ص����� */
typedef HI_VOID *(*HIGV_WIDGET_INIT_FUNC)(const WidgetBasicParam *widgetBasicParam);

typedef HI_S32 (*HIGV_WIDGET_HDL2ADDR_PFN)(HI_U32 u32Idx, HI_U8 u8MemType, HI_PARAM *pAddr);

typedef struct hiHIGV_WIDGET_TYPEINFO_S {
    /* Widget name; CNcomment:  �ؼ��� */
    HI_CHAR Name[33];  // 33 represents this array can save 33 HI_CHAR type datas
    /* The sequence of user defined widget; CNcomment:  TypeIDӦ��HIGV_EXTWIDGET_START��ʼ��� */
    HI_U32 TypeID;
    HIGV_WIDGET_INIT_FUNC WidgetInitFunc;
    /* The callback of user defined widget; CNcomment:  �û��Զ���ؼ������ص����� */
    /* The size of widget that pasered by parser mode, it is should seted
    if the widget is defined in xml, otherwise it can be set 0 */
    /* CNcomment:  �ؼ�����ģ��������ṹ�Ĵ�С������ÿؼ�����XML�н�����������Ҫ���ã��������Ϊ0 */
    HI_U32 WidgetPaserSize;
} HIGV_WIDGET_TYPEINFO_S;

/* coordinate type  CNcomment:  HIGV �������� */
typedef HI_S32 HIGV_CORD;

/* The button of mouse which pressed; CNcomment:  ��갴ť����״̬���� */
typedef enum {
    /* CNcomment:  ���δ���� */
    HIGV_MOUSEBUTTON_NONE = 0x00,
    /* CNcomment:  ���������� */
    HIGV_MOUSEBUTTON_L = 0x01,
    /* CNcomment:  ����м����� */
    HIGV_MOUSEBUTTON_M = 0x02,
    /* CNcomment:  ����Ҽ����� */
    HIGV_MOUSEBUTTON_R = 0x04,
    HIGV_MOUSEBUTTON_BUTT
} HIGV_MOUSEBUTTON_E;

/* The status of timer running  CNcomment: �ؼ���ʱ����Ϣ����״̬ */
typedef enum {
    HIGV_TIMERMSG_STATUS_UNEXIST = 0,
    /* unexit status <CNcomment: ��ʱ�������� */
    HIGV_TIMERMSG_STATUS_IDLE,
    /* idle status <CNcomment: ��ʱ������״̬ */
    HIGV_TIMERMSG_STATUS_FRYING,
    /* frying status <CNcomment: ��ʱ�����ڴ��� */
    HIGV_TIMERMSG_STATUS_RESET,
    /* reset status <CNcomment: ��ʱ����λ״̬ */
    HIGV_TIMERMSG_STATUS_BUTT
} HIGV_TIMERMSG_STATUS_E;
/* The language direction of widget  CNcomment: ǿ�ƿؼ����Է��� */
typedef enum {
    HIGV_TEXTDIR_NEUTRAL = 0,
    HIGV_TEXTDIR_LTR,
    HIGV_TEXTDIR_RTL,
    HIGV_TEXTDIR_BUTT
} HIGV_TEXTDIR_E;

/* Set widget foucs switch mode  CNcomment: �����л�ģʽ */
typedef enum {
    HIGV_FOCUS_SWITCH_AUTO = 0,
    /* auto CNcomment:�����Զ��л�ģʽ������Ҫ��ENTER���Ϳ����л����㣬һ�㰴���·�����н��� */
    HIGV_FOCUS_SWITCH_MANUAL,
    /* manual CNcomment:�����ֶ��л�ģʽ����Ҫ��ENTER������˳��ؼ��Ĳ����༭״̬ */
    HIGV_FOCUS_SWITCH_BUTT
} HIGV_FOCUS_SWITCH_E;

/* Focus switch state at manual focus mode  CNcomment: �ֶ������л�״̬ */
typedef enum {
    HIGV_FOCUS_STATE_SWITCH = 0,
    /* Focus switch state CNcomment:�����л�״̬ */
    HIGV_FOCUS_STATE_EDIT,
    /* Widget can operate CNcomment:�ؼ�������༭״̬ */
    HIGV_FOCUS_STATE_BUTT
} HIGV_FOCUS_STATE_E;

/* The type of widget paint  CNcomment: ���ػ���ʾ */
typedef enum {
    HIGV_PAINT_TYPE_HIDE = 0,
    /* hide widget  CNcomment:���ؿؼ� */
    HIGV_PAINT_TYPE_SHOW,
    /* show widget  CNcomment:��ʾ�ؼ� */
    HIGV_PAINT_TYPE_BUTT
} HIGV_PAINT_TYPE_E;

/* Window style   CNcomment: ���ڷ���� */
/* Default style, it is used 2bytes  CNcomment: Ĭ�Ϸ��,ռ�÷����������ֽ� */
#define HIGV_STYLE_DEFAULT 0x00
/* Don't draw the backgroud  CNcomment: �Կؼ���Ч���ÿؼ������Ʊ��� */
#define HIGV_STYLE_TRANSPARENT 0x02
/* Couldn't get foucs��such Label  CNcomment:  ���ܻ�ȡ���㣬����Label */
#define HIGV_STYLE_NOFOCUS 0x04
/* Release the resouce when hided  CNcomment: ������ʱ���ͷŸÿؼ��򴰿�ռ����Դ */
#define HIGV_STYLE_HIDE_UNLODRES 0x10
/* It is indicated that the widget can change language, it can triger the langugage msg to user */
/* CNcomment:��ʾ�ÿؼ����Ըı�����,��Ҫ�ǿ��Ʒ��������л���Ϣ���û� */
#define HIGV_STYLE_LANCHNG 0x20
/* Modal windwo */
/* CNcomment: ��ʾ�ô�����ģ̬�ģ�ģ̬���ڲ����ܱ���ȥ���㣬���Ǹô��ڹرջ����� */
#define HIGV_STYLE_MODAL 0x40
/* Foce draw backgroud of parent */
/* CNcomment: ǿ�ƻ��Ƹ����� */
#define HIGV_STYLE_FORCE_PAINT_PARENT 0x80
/* if container is seted this flag, it's child also hightlighted,
and lost the focus, the child will not be hightlight */
/* CNcomment: ����������ؼ������������־ʱ����������ʱ�������ӿؼ�Ҳͬʱ����������
 * ʧȥ����ʱ������ʧȥ����״̬ */
#define HIGV_STYLE_HILIGHT_CHILD 0x100

/* The extend style of widget which only support 8 */
/* CNcomment: ���ڿؼ���չstyle ������֧��8��,ռ�÷���ֶ����2��byte */
#define HIGV_STYLE_DEFINE(WidgetType, style) ((((HI_U32)WidgetType) << (24)) | ((1) << ((16) + (HI_U32)((style) & (0x7)))))

/* Common style mask of widget */
/* CNcomment: �ؼ�ͨ�÷������ */
#define HIGV_STYLE_MASK 0xffffff

/* Skin index, it is only used to skin */
/* CNcomment:  Ƥ��IDX���壬��Ҫ����Ƥ�� */
/* No focus */ /* *CNcomment:  �޽��� */
#define HIGV_SKIN_NORMAL 0x01
/* Disable state */
/* CNcomment:  δʹ��״̬ */
#define HIGV_SKIN_DISABLE 0x02
/* Hightlight state */
/* CNcomment:  ����״̬ */
#define HIGV_SKIN_HIGHLIGHT 0x03
/* Active state */
/* CNcomment:  �н��㣬���� */
#define HIGV_SKIN_ACITVE 0x04
/* Mouse down state */
/* CNcomment: ��갴�£��ؼ���ʾƤ�� */
#define HIGV_SKIN_MOUSEDOWN 0x05
/* Checked state */
/* CNcomment:  ����check״̬��button������״̬�µ�Ƥ�� */
#define HIGV_SKIN_BUTTON_CHECKED_NORMAL 0x06
/* Disable at check state */
/* CNcomment:  ����check״̬��button��δʹ��״̬�µ�Ƥ�� */
#define HIGV_SKIN_BUTTON_CHECKED_DISABLE 0x07
/* Hightlight at check state */
/* CNcomment:  ����check״̬��button�ڸ���״̬�µ�Ƥ�� */
#define HIGV_SKIN_BUTTON_CHECKED_HIGHLIGHT 0x08
/* Focus at check state */
/* CNcomment:  ����check״̬��button�ڽ���״̬�µ�Ƥ�� */
#define HIGV_SKIN_BUTTON_CHECKED_ACITVE 0x09
/* Pressed at check state */
/* CNcomment:  ����check״̬��button����갴��״̬�µ�Ƥ�� */
#define HIGV_SKIN_BUTTON_CHECKED_MOUSEDOWN 0xa

/* Window manager handle */
/* CNcomment:  ���ڹ����������¼�����ģ���յ���Ϣ���������ڹ���ģ�� */
#define HIGV_WND_MANAGER_HANDLE ((HI_U32)(-1))

/* It is used to HIGV_MSG_STATE_CHANGE message */
/* CNcomment:  �������HIGV_MSG_STATE_CHANGE��Ϣ, wParam���� */
typedef enum {
    HIGV_STATENAME_ENABLE,
    /* enable <CNcomment:  ʹ�� */
    HIGV_STATENAME_HIGHLIGHT,
    /* highlight <CNcomment:  ���� */
    HIGV_STATENAME_BUTT
} HIGV_STATENAME_E;
/* The order of the message which user register to higv */
/* CNcomment:��ʶͬһ���¼���Ϣ�û�ע����¼�������
* �ؼ�ԭʼ���¼������Ĵ����Ⱥ�˳��
*/
typedef enum {
    HIGV_PROCORDER_BEFORE,
    /* It is first order to call user function */
    /* CNcomment:  �û�ע����¼������ȵ��� */
    HIGV_PROCORDER_AFTER,
    /* It is after order to call user function */
    /* CNcomment:  �û�ע����¼���������� */
    HIGV_PROCORDER_BUTT
} HIGV_PROCORDER_E;

/* ���������ת������ */
#define HIGV_RECT_TOU32PARAM(rc, param1, param2)                                  \
    do {                                                                          \
        param1 = ((((HI_U32)(rc).x & 0xFFFF) << 16) | ((HI_U32)(rc).y & 0xFFFF)); \
        param2 = ((((HI_U32)(rc).w & 0xFFFF) << 16) | ((HI_U32)(rc).h & 0xFFFF)); \
    } while (0)

#define HIGV_U32PARAM_TORECT(param1, param2, rc)      \
    do {                                              \
        (rc).x = (HI_S32)(((param1) >> 16) & 0xFFFF); \
        (rc).y = (HI_S32)((param1)&0xFFFF);           \
        (rc).w = (HI_S32)(((param2) >> 16) & 0xFFFF); \
        (rc).h = (HI_S32)((param2)&0xFFFF);           \
    } while (0)

/* Message of window CNcomment: ������Ϣ���� */
/* Paint messsage [wparam, lparam] = [PaintRect<x,y>, PaintRect<w,h>] =
[((((rc).x & 0xFFFF)<<16) | ((rc).y & 0xFFFF)),
 *  ((((rc).w & 0xFFFF)<<16) | ((rc).h & 0xFFFF))] */
/* CNcomment:CNcomment:  ������Ϣ[wparam, lparam] = [PaintRect<x,y>, PaintRect<w,h>] =
[((((rc).x & 0xFFFF)<<16) | ((rc).y & 0xFFFF)), ((((rc).w & 0xFFFF)<<16) | ((rc).h & 0xFFFF))] */
#define HIGV_MSG_PAINT 0x03
/* Key down message [wparam, lparam]= [HIGV_KEYCODE_E, nil] */
/* CNcomment:  ��������Ϣ [wparam, lparam]=   [HIGV_KEYCODE_E, nil] */
#define HIGV_MSG_KEYDOWN 0x04
/* Key up message [wparam, lparam]  = [HIGV_KEYCODE_E, nil]* */
/* CNcomment:  ��������Ϣ [wparam, lparam]  = [HIGV_KEYCODE_E, nil] */
#define HIGV_MSG_KEYUP 0x05
/* Get focus message [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ��ý�����Ϣ [wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_GET_FOCUS 0x06
/* Lost focus message [wparam, lparam]  = [nil, nil] */
/* *CNcomment:  ʧȥ������Ϣ [wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_LOST_FOCUS 0x07
/* Show message [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ��ʾ��Ϣ [wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_SHOW 0x08
/* Hide message [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ������Ϣ[wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_HIDE 0x09
/* Data change message [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ���ݸı���Ϣ[wparam, lparam]  = [nil, nil]  */
#define HIGV_MSG_DATA_CHANGE 0x10
/* Timer message [wparam, lparam]  = [TimerID, nil]  */
/* CNcomment:  ��ʱ��Ϣ [wparam, lparam]  = [TimerID, nil]  */
#define HIGV_MSG_TIMER 0x11
/* button down message  [wparam, lparam]  = [nil, nil] */
/* CNcomment:  button������Ϣ [wparam, lparam]  = [nil, nil]
                                                           */
#define HIGV_MSG_CLICK 0x12
/* State change message */
/* CNcomment:  ״̬�ı���Ϣ [wparam, lparam]  = [HIGV_STATENAME_E, HI_TRUE | HI_FALSE]  */
#define HIGV_MSG_STATE_CHANGE 0x13
/* Item selected message */
/* CNcomment:  ��Ŀѡ����Ϣ [wparam, lparam]  = [SelCell.Item, SelCell.Col]  */
#define HIGV_MSG_ITEM_SELECT 0x14
/* Scroll text message */ /* *CNcomment:  ������Ļ [wparam, lparam]  = [nil, nil]  */
#define HIGV_MSG_ST_UPDATE 0x15
/* Update time message [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ʱ�ӿؼ���Ҫ����ʱ�� [wparam, lparam]  = [nil,nil]  */
#define HIGV_MSG_CLOCK_UPDATE 0x16
/* Input over for imagecipher [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ͼƬ������������[wparam, lparam]  =  [nil, nil]  */
#define HIGV_MSG_IC_INPUTEND 0x17
/* Input over for edit [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ������������� [wparam, lparam]  = [nil, nil]  */
#define HIGV_MSG_EDIT_INPUTEND 0x18
/* Scroll over in one cycle for scrolltext  [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ������Ļ����һ�ֽ���[wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_ST_SCROLLONETIME 0x19
/* The value changed when mouse opreate [wparam, lparam]  = [SlidePos, ContentLength] */
/* CNcomment:        ������ֵ��Ϊ�����������ı�[wparam,  lparam]  = [SlidePos,ContentLength] */
#define HIGV_MSG_SCROLLBAR_CHANGE 0x1a
/* State change of checkbox or radio button [wparam, lparam]  = [HIGV_BUTTON_STATUS_E, nil] */
/* CNcomment:  CheckBox����Radio Button��״̬�ı�
 * [wparam, lparam]  =[HIGV_BUTTON_STATUS_E,nil] */
#define HIGV_MSG_BUTTON_STATUSCHANGE 0x1b
/* Cell is selected [m_SelCell.Item,m_SelCell.Col] */
/* CNcomment:  ĳһ��cell��ѡ�� [wparam, lparam]  =[m_SelCell.Item,m_SelCell.Col] */
#define HIGV_MSG_LISTBOX_CELLSEL 0x1c
/* Item is selected [wparam, lparam]  =  [Item, nil] */
/* CNcomment:  ��Ŀѡ����Ϣ [wparam, lparam]  =  [Item, nil] */
#define HIGV_MSG_COMBOBOX_ITEMSEL 0x1d
/* Container widget change active child [wparam, lparam] = [Last active child handle, new active child handle] */
/* CNcomment: �����ؼ��ı佹�㺢���¼� [wparam, lparam] = [��һ�����㺢�Ӿ��, �½��㺢�Ӿ��] */
#define HIGV_MSG_CONTAINER_CHANGE_FOCUSE 0x1e

/* The event of scrollgrid */ /* *CNcomment:  ScrollGrid�¼����� */
/* The cell selected event  [wparam, lparam]  = [SelCell.Item, SelCell.Col] */
/* CNcomment:  ScrollGridĳһ��cell��ѡ�� [wparam, lparam]  = [SelCell.Item, SelCell.Col] */
#define HIGV_MSG_SCROLLGRID_CELL_COLSEL 0x23
/* The focus move the top margin will genterate the event [wparam, lparam]  = [SelCell, nil] */
/* CNcomment:  ScrollGrid�Ľ����ƶ������ϱ�Ե����¼� [wparam, lparam]  =SelCell, nil] */
#define HIGV_MSG_SCROLLGRID_REACH_TOP 0x24
/* The focus move the bottom margin will genterate the event  [wparam, lparam]  = [SelCell, nil] */
/* CNcomment:ScrollGrid �Ľ����ƶ������±�Ե����¼� [wparam, lparam] = [SelCell, nil] */
#define HIGV_MSG_SCROLLGRID_REACH_BTM 0x25
/* The focus move the left margin will genterate the event  [wparam, lparam]  = [SelCell, nil]  */
/* CNcomment:ScrollGrid �Ľ����ƶ��������Ե����¼� [wparam, lparam]= [SelCell, nil] */
#define HIGV_MSG_SCROLLGRID_REACH_LEFT 0x26
/* The focus move the right margin will genterate the event  [wparam, lparam]  = [SelCell, nil] */
/* CNcomment:ScrollGrid    �Ľ����ƶ������ұ�Ե����¼�    [wparam, lparam]   */
#define HIGV_MSG_SCROLLGRID_REACH_RIGHT 0x27
/* The update event of item for scrollgrid [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ScrollGrid ������Ŀ�����¼� [wparam, lparam]  = [nil, nil]  */
#define HIGV_MSG_SCROLLGRID_ITEM_UPDATE 0x28
/* The uddate event of scrollgrid [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ScrollGrid ���ƽ��������¼� [wparam, lparam]  = [nil, nil]  */
#define HIGV_MSG_SCROLLGRID_FOCUS_UPDATE 0x29
/* The begin event of decode image for scrollgrid [wparam, lparam]  = [nil, nil] */
/* CNcomment: ScrollGrid���뿪ʼ�¼�[wparam, lparam]  = [nil, nil]   */
#define HIGV_MSG_SCROLLGRID_DECIMG_BEGIN 0x2a
/* The finish event of decode image for scrollgrid [wparam, lparam]  = [nil, nil] */
/* CNcomment:ScrollGrid��������¼� [wparam,lparam]  = [nil, nil]  */
#define HIGV_MSG_SCROLLGRID_DECIMG_FINISH 0x2b
/* The finish event of fling for scrollgrid [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ScrollGrid��ɨ���ƽ����¼�[wparam, lparam]  = [nil, nil]  */
#define HIGV_MSG_SCROLLGRID_FLING_FINISH 0x2c

/* The event of timetrack */ /* *CNcomment:  ʱ�����¼����� */
/* The drag event of mouse for timetrack [wparam, lparam]  = [m_CurGraduation, nil]  */
/* CNcomment:  TimeTrackͨ����꿪ʼ�϶������¼�[wparam, lparam]  =  [m_CurGraduation, nil]  */
#define HIGV_MSG_TIMETRACK_DRAGBEGIN 0x30
/* The position change of timetrack  [wparam, lparam]  = [m_CurGraduation, nil]   */
/* CNcomment:  TimeTrack����λ�øı��¼�[wparam, lparam]  =[m_CurGraduation, nil]   */
#define HIGV_MSG_TIMETRACK_CHANGE 0x31
/* The end event when mouse move through timetrack [wparam, lparam]  = [m_CurGraduation, nil] */
/* CNcomment:  TimeTrackͨ������϶���������¼� [wparam, lparam]  = [m_CurGraduation,  nil]   */
#define HIGV_MSG_TIMETRACK_DRAGEND 0x32
/* The graduation value change event when drag trackbar [wparam, lparam]  = [m_CurValue, nil]   */
/* CNcomment: TrackBar�϶��ı�̶Ȳ�����Ϣ [wparam, lparam] = [m_CurValue,nil]   */
#define HIGV_MSG_VALUEONCHANGE 0x33

/* The update event of scrollbox  [wparam, lparam]  = [nil, nil] */
/* CNcomment:  SCROLLBOX���Ƹ����¼� [wparam,lparam]  = [nil, nil]  */
#define HIGV_MSG_SCROLLBOX_UPDATE 0x34

/* The switch event of input method[wparam, lparam]  = [nil, nil] */
/* CNcomment:  ���뷨�л��¼� [wparam, lparam]  = [nil, nil]  */
#define HIGV_MSG_IME_SWITCH 0x35
/* The show event of input method [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ���뷨��ش�����ʾ [wparam, lparam]  = [nil, nil]  */
#define HIGV_MSG_IME_SHOW 0x36
/* *The hide event of input method [wparam, lparam]  = [nil, nil] */
/* *CNcomment:  ���뷨��ش�������[wparam, lparam]  = [nil, nil]   */
#define HIGV_MSG_IME_HIDE 0x37

/* The event of timebar */
/* CNcomment:  ʱ�����¼����� */
/* The drag start event of mouse for timebar  [wparam, lparam]  = [nil, nil] */
/* CNcomment: Timebarͨ����꿪ʼ�϶������¼� [wparam, lparam]  = [nil, nil]  */
#define HIGV_MSG_TIMEBAR_DRAGBEGIN 0x40
/* The change event of timebar  [wparam, lparam]  = [GraduationIndex, nil] */
/* CNcomment:  timebar����λ�øı��¼� [wparam, lparam]  = [GraduationIndex, nil]  */
#define HIGV_MSG_TIMEBAR_CHANGE 0x41
/* The drag end event of mouse for timebar  [wparam, lparam]  = [nil, nil] */
/* CNcomment: timebarͨ������϶���������¼� [wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_TIMEBAR_DRAGEND 0x42

/* Change the foucs of clock [wparam, lparam]  =[m_FocusSeg, 0] */
/* CNcomment:  clock�����޸� [wparam, lparam]  = [m_FocusSeg, 0] */
#define HIGV_MSG_CLOCK_FOCUS_MOVE 0x50
/* Set clock. [wparam, lparam]  =  [nil, nil] */
/* CNcomment:  �޸� clockʱ��[wparam, lparam]  =  [Item, nil] */
#define HIGV_MSG_CLOCK_TIME_ADJUST 0x51
/* Set widget sate. [wparam, lparam]  =  [nil, nil] */
/* CNcomment:  �ؼ��ֶ�����ģʽ״̬�ı�[wparam, lparam]  = [HIGV_FOCUS_STATE_E, nil] */
#define HIGV_MSG_MANUAL_FOCUS_STATE_CHANGE 0x52

/* The event of message box */ /* *CNcomment:  ��Ϣ���¼����� */
/* The timeout event of MessageBox show  [wparam, lparam]  = [ButtonID, show times] */
/* CNcomment:   MessageBox��ʾʱ������Զ������¼� [wparam, lparam]  = [ButtonID, show times]  */
#define HIGV_MSG_MSGBOX_TIMEOUT 0x60
/* The message box click button message [wparam, lparam]  = [ButtonID, nil] */
/* CNcomment:  MessageBoxѡ����ť��Ϣ [wparam, lparam]  = [ButtonID, nil] */
#define HIGV_MSG_MSGBOX_SELECT 0x61
/* The message box hide message. attention:Don't use it */
/* CNcomment:  MessageBoxѡ��������Ϣ��ע������ʹ�� */
#define HIGV_MSG_MSGBOX_HIDE 0x62

/* The event of multi edit */
/* CNcomment:  ���б༭���¼����� */
/* Input over for multi edit [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ���б༭�������¼� [wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_MULTIEDIT_INPUT 0x70
/* Begin select string from text [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ����ڿؼ���ѡȡ�ִ��¼� [wparam,  lparam]  = [nil, nil] */
#define HIGV_MSG_MULTIEDIT_SELECT_OUT 0x71
/* End select string from text [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ������ѡȡ�ִ������¼� [wparam, lparam] = [nil, nil] */
#define HIGV_MSG_MULTIEDIT_SELECT_END 0x72
/* Move reach side [wparam, lparam]  = [HigvMultiEditSlide, nil] */
/* CNcomment:  �ƶ�����߽� [wparam, lparam]  = [HigvMultiEditSlide, nil] */
#define HIGV_MSG_MULTIEDIT_REACH_SIDE 0x73
/* Draw cursor [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ���ƹ����Ϣ [wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_MULTIEDIT_DRAW_CURSOR 0x74

/* The event of scroll view */ /* *CNcomment: ������ͼ�¼����� */
/* Scroll view scroll event [wparam, lparam] =
[(((content rect).x & 0xFFFF)<<16) | (y & 0xFFFF), ((w & 0xFFFF)<<16) |
 *  (h & 0xFFFF)] */
/* CNcomment: �ӿ��ƶ��¼� [wparam, lparam]  =
[(((content rect).x & 0xFFFF)<<16) | (y & 0xFFFF), ((w & 0xFFFF)<<16) | (h & 0xFFFF)] */
#define HIGV_MSG_SCROLLVIEW_SCROLL 0x80
/* The event of finish fling event */ /* *CNcomment: ������ɨ�¼����� */
/* finish fling event [wparam, lparam] = [(((content rect).x & 0xFFFF)<<16) | (y & 0xFFFF), ((w & 0xFFFF)<<16) | (h &
 * 0xFFFF)] */
/* CNcomment: ��ɨ�����¼� [wparam, lparam]  =
[(((content rect).x & 0xFFFF)<<16) | (y & 0xFFFF), ((w & 0xFFFF)<<16) | (h & 0xFFFF)] */
#define HIGV_MSG_SCROLLVIEW_FINISHFLING 0x81

/* Language change event */
/* CNcomment:  ���Ըı��¼� [wparam, lparam]  = [LanguageID, LanguageDirection] */
#define HIGV_MSG_LAN_CHANGE 0x100
/* Exit edit status at auto manual focus mode [wparam, lparam]  = [nil, nil] */
/* CNcomment: �ֶ��л�����ģʽ���˳��༭״̬[wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_FOCUS_EDIT_EXIT 0x101
/* Mouse in event [wparam, lparam]  = [nil, nil] */
/* CNcomment: ��������¼�[wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_MOUSEIN 0x200
/* The first event of mouse */ /* *CNcomment: ��һ������¼� */
#define HIGV_MSG_FIRSTMOUSEMSG HIGV_MSG_MOUSEIN
/* Mouse down event [wparam, lparam]  = [HIGV_MOUSEBUTTON_L, (ScreenX << 16)|(ScreenY & 0xffff)] */
/* CNcomment: ��갴���¼�[wparam,   lparam]  =  [HIGV_MOUSEBUTTON_L, (ScreenX << 16)|(ScreenY & 0xffff)] */
#define HIGV_MSG_MOUSEDOWN 0x201
/* Mouse out event [wparam, lparam]  = [nil, nil] */
/* CNcomment: ����Ƴ��¼�[wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_MOUSEOUT 0x202
/* Mouse up event [wparam, lparam]  = [HigvMouseState, (ScreenX << 16)|(ScreenY & 0xffff)] */
/* CNcomment:  ���̧���¼�[wparam, lparam]  =  [HigvMouseState,(ScreenX << 16)|(ScreenY & 0xffff)] */
#define HIGV_MSG_MOUSEUP 0x203
/* Mouse move event [wparam, lparam]  = [nil, (ScreenX << 16)|(ScreenY & 0xffff)] */
/* CNcomment: ����ƶ��¼�[wparam, lparam]  = [nil, (ScreenX <<  16)|(ScreenY & 0xffff)] */
#define HIGV_MSG_MOUSEMOVE 0x204
/* Mouse wheel event [wparam, lparam]  = [nil, nil] */
/* CNcomment: �������¼�[wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_MOUSEWHEEL 0x205
/* The press down of left mouse [wparam, lparam]  = [nil, nil] */
/* �����������¼� [wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_MOUSELONGDOWN 0x206
/* The double click of  mouse [wparam, lparam]  = [nil, nil] */
/* ���˫���¼�[wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_MOUSEDBCLICK 0x207
/* The last message of  mouse */
/* CNcomment: ���һ������¼� */
#define HIGV_MSG_LASTMOUSEMSG HIGV_MSG_MOUSEDBCLICK
/* The virtual mouse up event [wparam, lparam]  = [nil, nil] */
/* CNcomment: ������굯���¼�[wparam, lparam]  = [nil,  nil] */
#define HIGV_MSG_VIRTUAL_MOUSEUP 0x208
/* The virtual mouse down event [wparam, lparam]  = [nil, nil] */
/* CNcomment: ������갴���¼�[wparam, lparam]  = [nil,  nil] */
#define HIGV_MSG_VIRTUAL_MOUSEDOWN 0x209

/* Refesh the window to screen [wparam, lparam]  =
[(((rc).x & 0xFFFF)<<16) | ((rc).y & 0xFFFF), (((rc).w & 0xFFFF)<<16)
 * | ((rc).h & 0xFFFF)] */
/* CNcomment:  ������ˢ�µ���Ļ��[wparam, lparam]  =
[(((rc).x & 0xFFFF)<<16) | ((rc).y & 0xFFFF), (((rc).w & 0xFFFF)<<16) | ((rc).h & 0xFFFF)] */
#define HIGV_MSG_REFRESH_WINDOW 0x500
/* After refesh the window to screen [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ������ˢ�µ���Ļ��[wparam, lparam] = [nil, nil] */
#define HIGV_MSG_AFTERREFRESH 0x501
/* The data change messag for adm */
/* CNcomment:  ADMģ�����е���Ϣ [wparam, lparam]  = [HIGV_DC_E, nil] */
#define HIGV_MSG_ADM_DATACHANGE 0x502
/* Force to update the window to the screen */
/* CNcomment:  ǿ�Ƹ��²�������ˢ�µ���Ļ��[wparam, lparam]  = [(((rc).x &
*  0xFFFF)<<16) | ((rc).y & 0xFFFF), (((rc).w & 0xFFFF)<<16) | ((rc).h &
* ��0xFFFF)] */
#define HIGV_MSG_FORCE_REFRESH_WINDOW 0x503

/* Refresh message which is used to avoid loss combined message [wparam, lparam]  = [nil, nil] */
/* CNcomment:ˢ����ϢΪ����ϲ���ʧˢ���¼�����������Ϣ[wparam,    nil] */
#define HIGV_MSG_FAKE_REFRESH_WINDOW 0x504

/* Bussiness event [wparam, lparam]  = [nil, nil] */
/* CNcomment: ҵ���¼�[wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_EVENT 0x900
/* The base value of user defined [wparam, lparam]  = [nil, nil] */
/* CNcomment: �û��Զ����¼���ʼֵ[wparam, lparam]  =  [nil, nil] */
#define HIGV_MSG_USER 0x1000
/* The mouse in for viedo shelter [wparam, lparam]  = [RectIndex, HIGV_VIDEOSHELTER_CURSOR_UNDER_E] */
/* CNcomment:  ��������¼�[wparam, lparam]  = [RectIndex,  HIGV_VIDEOSHELTER_CURSOR_UNDER_E] */
#define HIGV_MSG_VIDEOSHELTER_MOUSEIN 0x1001
/* The down event of mouse for video shelter  [wparam, lparam]  = [RectIndex, HIGV_VIDEOSHELTER_CURSOR_UNDER_E] */
/* CNcomment:  �������������¼� [wparam, lparam] = [RectIndex, HIGV_VIDEOSHELTER_CURSOR_UNDER_E]   */
#define HIGV_MSG_VIDEOSHELTER_MOUSEDOWN_L 0x1002
/* The up event of mouse for video shelter [wparam, lparam]  = [RectIndex, HIGV_VIDEOSHELTER_CURSOR_UNDER_E] */
/* CNcomment:  ��굯���¼�[wparam,  lparam] = [RectIndex, HIGV_VIDEOSHELTER_CURSOR_UNDER_E] */
#define HIGV_MSG_VIDEOSHELTER_MOUSEUP 0x1003
/* The move event of mouse for viedo shelter  [wparam, lparam]  = [RectIndex, HIGV_VIDEOSHELTER_CURSOR_UNDER_E] */
/* CNcomment:  ����ƶ��¼� [wparam,  lparam]  =  [RectIndex,  HIGV_VIDEOSHELTER_CURSOR_UNDER_E]  */
#define HIGV_MSG_VIDEOSHELTER_MOUSEMOVE 0x1004
/* The  click event of right mouse for viedo shelter [wparam, lparam]  = [RectIndex, nil] */
/* CNcomment:  ����Ҽ������¼�[wparam,lparam]  = [RectIndex,nil]  */
#define HIGV_MSG_VIDEOSHELTER_MOUSEDOWN_R 0x1005
/* The up event of mouse for move monitor [wparam, lparam]  = [HIGV_VIDEOSHELTER_CURSOR_UNDER_E, nil]  */
/* CNcomment:  �ƶ������굯���¼�[wparam, lparam]  = [HIGV_VIDEOSHELTER_CURSOR_UNDER_E, nil]  */
#define HIGV_MSG_MOVEMONITOR_MOUSEUP 0x1006
/* touch screen event [wparam, lparam]  = [nil, nil] */
/* CNcomment:  �����¼�[wparam, lparam]  = [nil, nil]   */
#define HIGV_MSG_TOUCH 0x2001
/* tap gesture event[wparam, lparam]  = [nil, nil] */
/* CNcomment:  ���ô����������¼�[wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_GESTURE_TAP 0x2002
/* long press gesture event [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ���������¼�[wparam, lparam]  = [nil, nil]  */
#define HIGV_MSG_GESTURE_LONGTAP 0x2003
/* fling gesture event [wparam, lparam]  = [nil, nil] */
/* CNcomment:  �ḧ�����������¼�[wparam, lparam]  = [nil, nil]
 */
#define HIGV_MSG_GESTURE_FLING 0x2004
/* scroll gesture event [wparam, lparam]  = [nil, nil] */
/* *CNcomment:  ���������¼�[wparam, lparam]  = [nil, nil]   */
#define HIGV_MSG_GESTURE_SCROLL 0x2005
/* pinch gesture event [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ��������¼�[wparam, lparam]  = [nil, nil]   */
#define HIGV_MSG_GESTURE_PINCH 0x2006
/* unlock done event [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ��������¼�[wparam, lparam]  = [nil, nil]   */
#define HIGV_MSG_UNLOCK 0x2007
/* finish seek trackbar [wparam, lparam]  = [m_CurValue, nil]   */
/* CNcomment:  TrackBar�϶������ϱ��¼� [wparam,  lparam]  = [m_CurValue, nil]   */
#define HIGV_MSG_FINISHSEEK 0x2008
/* move event [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ���������ؼ��ƶ��¼�[wparam, lparam]  = [nil, nil]   */
#define HIGV_MSG_MOVE 0x2009
/* kick back event [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ���������ص�����¼�[wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_KICKBACK 0x2010
/* clock position event [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ʱ��λ���ϱ��¼�[wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_POSITION 0x2011
/* Touch in event [wparam, lparam]  = [nil, nil] */
/* CNcomment: ���������¼�[wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_TOUCHIN 0x2012
/* Touch out event [wparam, lparam]  = [nil, nil] */
/* CNcomment: �����Ƴ��¼�[wparam, lparam]  = [nil, nil] */
#define HIGV_MSG_TOUCHOUT 0x2013
/* wheelview position event [wparam, lparam]  = [nil, nil] */
/* CNcomment:  ����ѡ��������λ���ϱ��¼�[wparam, lparam]  = [nil, nil]   */
#define HIGV_MSG_WHEELVIEW_ITEM 0x3001
/* imageview git finish repeat event [wparam, lparam]  = [nil, nil] */
/* CNcomment: gif����ѭ�����Ž����ϱ��¼�[wparam,   lparam]  = [nil, nil]   */
#define HIGV_MSG_IMAGEEX_ENDOF_REPEAT 0x3101

/* animation start event [wparam, lparam]   = [nil, nil] */
/* CNcomment:  ������ʼ�¼�[wparam, lparam]  = [nil, nil]wparam ������, lparam ������� */
#define HIGV_MSG_ANIM_START 0x5001
/* animation running event [wparam, lparam] = [nil, nil] */
/* CNcomment:  ���������¼�[wparam, lparam]  = [nil, nil]  wparam ������, lparam ������� */
#define HIGV_MSG_ANIM_UPDATE 0x5002
/* animation stop event [wparam, lparam]    = [nil, nil] */
/* CNcomment:  ���������¼�[wparam, lparam]  = [nil, nil]��wparam ������, lparam ������� */
#define HIGV_MSG_ANIM_STOP 0x5003

/* animation start event [wparam, lparam]   = [nil, nil] */
/* CNcomment:  �ص���ʼ�¼�[wparam, lparam]  = [nil, nil] wparam ������, lparam Ϊ�� */
#define HIGV_MSG_REBOUND_START 0x5101
/* animation running event [wparam, lparam] = [nil, nil] */
/* CNcomment:  �ص������¼�[wparam, lparam]  = [nil, nil]   wparam ������, lparam �ƶ����� */
#define HIGV_MSG_REBOUND_UPDATE 0x5102
/* animation stop event [wparam, lparam]    = [nil, nil] */
/* CNcomment:  �ص������¼�[wparam, lparam]  = [nil, nil]  wparam ������, lparam Ϊ��  */
#define HIGV_MSG_REBOUND_STOP 0x5103
/* item scale event [wparam, lparam] = [nil, nil] */
/* CNcomment:  ��Ŀ�Ŵ��¼�[wparam, lparam]  = [nil, nil]   wparam ������, lparam �ƶ����� */
#define HIGV_MSG_SCALE 0x5104
/* selector focus position report event [wparam, lparam] = [nil, nil] */
/* CNcomment:  ѡ��������λ���ϱ��¼�[wparam, lparam]  = [nil, nil]   */
#define MSG_SCALEVIEW_ITEM 0x3002
/* TAP reported event [wparam, lparam] = [nil, nil] */
/* CNcomment:  TAP�ϱ��¼�[wparam, lparam]  = [nil, nil]   */
#define MSG_SCALEVIEW_TAPLISTENER 0x3003


/* it is defined the message whether process continue */
/* CNcomment:������Ϣ�Ƿ�̼��������� */
/* The message will go on */ /* CNcomment: ��Ϣ�������´��� */
#define HIGV_PROC_GOON 100
/* Stop process message, it is not continue */
/* CNcomment: ��Ϣֹͣ���������´��� */
#define HIGV_PROC_STOP 200
/* Get the x coordiate of mouse which is relative the x coordiate of widget */
/* CNcomment:  ȡ���������꣬������ϵͳ����ڿؼ���X����  */
#define HIGV_GET_MOUSE_X(lParam) ((HIGV_CORD)((HI_S16)(((HI_U32)lParam) >> (16))))
/* Get the y coordiate of mouse which is relative the y coordiate of widget */
/* CNcomment:    ȡ���������꣬������ϵͳ����ڿؼ���Y���� */
#define HIGV_GET_MOUSE_Y(lParam) ((HIGV_CORD)((HI_S16)(((HI_U32)lParam) & (0xFFFF))))
/* Get step of mouse moving */ /* CNcomment: ��ȡ��경��ֵ */
#define HIGV_GET_MOUSE_STEP(wParam) ((HI_S32)((HI_S16)(((HI_U32)wParam) >> (16))))
/* Get state of mouse button */ /* CNcomment: ��ȡ��갴��״̬ */
#define HIGV_GET_MOUSE_BUTTON(wParam) ((HI_U32)((HI_S16)(((HI_U32)wParam) & (0xFFFF))))

/* Mouse wheel direction */ /* CNcomment: �����ֹ������� */
typedef enum hiHIGV_WHEEL_DIRECTION {
    HIGV_WHEEL_DIRECTION_DOWN = 0,
    HIGV_WHEEL_DIRECTION_UP = 1,
    HIGV_WHEEL_DIRECTION_BUTT
} HIGV_WHEEL_DIRECTION;

/* Get step and diection of mouse wheel */
/* CNcomment: ��ȡ�����ֹ����ķ���Ͳ��� */
#define HIGV_GET_MOUSE_WHEEL(wParam, Step, Direction) \
    do {                                              \
        Step = HIGV_GET_MOUSE_STEP(wParam);           \
        if (Step >> 7) {                              \
            Step = 0xFF - Step + 1;                   \
            Direction = HIGV_WHEEL_DIRECTION_UP;      \
        } else {                                      \
            Direction = HIGV_WHEEL_DIRECTION_DOWN;    \
        }                                             \
    } while (0)

/* Message callback */ /* *CNcomment:  ��Ϣ����ص����� */
typedef HI_S32 (*HIGV_MSG_PROC)(HIGV_HANDLE hWidget, HI_PARAM wParam, HI_PARAM lParam);

/* The attribute of widget to use create �� CNcomment:�ؼ��������� */
typedef struct hiHIGV_WCREATE_S {
    HI_U32 type; /* Control class  CNcomment:  �ؼ����� */
    HI_RECT rect;                    /* The position and size of widget��<CNcomment:  �ؼ�λ�ü���С */
    HIGV_HANDLE hParent;             /* Parent widget handle��<CNcomment:  ���ؼ���� */
    HI_U32 style;                    /* Widget style��<CNcomment:  �ؼ���� */
    HI_U32 level;
    /* Window level, it is only effect to window, the range is [0,15]
    ��CNcomment:  ���ڲ�Σ�ֻ��Դ��ڿؼ���Ч����ΧΪ[0,15] */
    HI_VOID *pPrivate; /* <The private data of widget��<CNcomment:  ��Widget������Ҫ��˽������ */
} HIGV_WCREATE_S;

/* The private data of widnow *��CNcomment:  ���ڴ���˽�����ݽṹ */
typedef struct hiHIGV_WINCREATE_S {
    HIGV_HANDLE hLayer;    /* Layer of window��<CNcomment:  ��������ͼ�� */
    HIGO_PF_E PixelFormat; /* Pixel format of window��CNcomment:  ���ڵ����ظ�ʽ */
    HI_BOOL bVideoHole;    /* For video hole��<CNcomment: �Ƿ���Ϊ��Ƶ���� */
} HIGV_WINCREATE_S;

/* The build tree of widget��CNcomment:  �ؼ�������(����ʹ�ö�������ʾ)�Ľڵ� */
typedef struct hiHIGV_WIDGETNODE_S {
    struct hiHIGV_WIDGETNODE_S *pChildHead;  /* first child node�� CNcomment: ����ڵ㺢�ӵĽڵ� */
    struct hiHIGV_WIDGETNODE_S *pNextSibing; /* sibling node�� CNcomment: ����ڵ��ֵܽڵ� */
    HI_VOID *pWidgetInfo;
    /* The build parameter when create the widget
    ��CNcomment: �����ؼ��ؼ���Ҫ�Ĺ������,����ؼ��ṹ����Ϣ�ο�higv_widgetstruct.h */
    HI_BOOL bCreateHide;   /* Wether hide the widget when create��CNcomment: �ؼ�����ʱ�Ƿ����� */
    HI_VOID *pPrivateData; /* User private data��CNcomment: �û��Զ���˽������ */
} HIGV_WIDGETNODE_S;

/* The type of text alignment ��CNcomment: ���ֶ��뷽ʽ */
/* Horizontal left of text alignment ��CNcomment:  ˮƽ���� */
#define HIGV_ALIGN_LEFT LAYOUT_LEFT
/* Horizontal right of text alignment ��CNcomment:  ˮƽ���� */
#define HIGV_ALIGN_RIGHT LAYOUT_RIGHT
/* Horizontal center of text alignment ��CNcomment:  ˮƽ���� */
#define HIGV_ALIGN_HCENTER LAYOUT_HCENTER
/* Top style of text alignment ��CNcomment:  ��ֱ�Ӷ� */
#define HIGV_ALIGN_TOP LAYOUT_TOP
/* Vertical bottom style  of text alignment ��CNcomment:  ��ֱ�ӵ� */
#define HIGV_ALIGN_BOTTOM LAYOUT_BOTTOM
/* Vertical center style  of text alignment ��CNcomment:  ��ֱ���� */
#define HIGV_ALIGN_VCENTER LAYOUT_VCENTER
/* Wap style  of text alignment��CNcomment:  �Զ����� */
#define HIGV_ALIGN_WRAP LAYOUT_WRAP

/* Ellipsis style of text alignment  CNcomment:  �ı��������Ⱥ����ʡ�Ժ� */
#define HIGV_ALIGN_WORDELLIPSIS LAYOUT_WORDELLIPSIS
/* Force to left of Horizontal  CNcomment:  ǿ��ˮƽ���� */
#define HIGV_ALIGN_FORCE_LEFT LAYOUT_FORCE_LEFT
/* Force to right of Horizontal  CNcomment:  ǿ��ˮƽ���� */
#define HIGV_ALIGN_FORCE_RIGHT LAYOUT_FORCE_RIGHT
/* Support the type of input method  CNcomment:  ֧�ֵ����뷨���� */
/* Support all input method by default CNcomment:  Ĭ��֧������ */
#define HIGV_IMETYPE_ALLTYPE 0
/* Lowcase english input method  CNcomment:  СдӢ�� */
#define HIGV_IMETYPE_ENGLISH (1 << 0)
/* Caps english input method  CNcomment:   ��дӢ�� */
#define HIGV_IMETYPE_CAPENGLISH (1 << 1)
/* Number input method  CNcomment:  ���� */
#define HIGV_IMETYPE_NUMBER (1 << 2)
/* Pingyin input method  CNcomment:  ƴ�� */
#define HIGV_IMETYPE_PINYIN (1 << 3)
/* Symbol method   CNcomment: ���� */
#define HIGV_IMETYPE_SYMBOL (1 << 4)
/* Standard input metod A  CNcomment: ��׼���뷨A */
#define HIGV_IMETYPE_STANDARD_A (1 << 5)
/* Standard input method B CNcomment: ��׼���뷨B */
#define HIGV_IMETYPE_STANDARD_B (1 << 6)

/* * ��Widget moudle�� */
/* * ���ؼ���ܡ� */
/**
* brief Active widget.CNcomment: ���ÿؼ�����Ϊ���
* param[in] widgetHandle Widget handle.CNcomment: �ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_FAILURE CNcomment: �ؼ������ܲ��ǻ�ģ�����ʧ��
*/
extern HI_S32 HI_GV_Widget_Active(HIGV_HANDLE widgetHandle);

/**
* brief Create widget.CNcomment: �������ںͿؼ�
* param[in] creatInfo The information of widget.CNcomment:  �ؼ���Ϣ
* param[out] widgetHandle   Widget handle.CNcomment:  �ؼ����ָ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
* see :HI_GV_Widget_Destroy
*/
HI_S32 HI_GV_Widget_Create(const HIGV_WCREATE_S *creatInfo, HIGV_HANDLE *widgetHandle);

/*
* brief Destroy widget.CNcomment: ���ٴ���
* param[in] widgetHandle Widget handle.CNcomment: �ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_NORES
* see:HI_GV_Widget_Create
*/
HI_S32 HI_GV_Widget_Destroy(HIGV_HANDLE widgetHandle);

/*
* brief enable widget, but it is not effect to window.CNcomment: ʹ�ܿؼ������ڴ�����Ч
* param[in] widgetHandle Widget handle.CNcomment: �ؼ����
* param[in] enable  enable flag.CNcomment: ʹ�ܱ�־��HI_TRUE��ʾʹ�ܣ�HI_FALSE��ʾȥʹ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_NOOP Unsupport operation, such as the operation is to window.CNcomment:
* ��֧�ָô��ڣ�����Դ��ڽ��иò��� \retval ::HI_ERR_COMM_PAERM Not allow, such as,
* it is not allowed when the parent
* window is disabled. CNcomment: ���������縸�����ǽ�ֹ�ģ�ִ��enable
*
*/
HI_S32 HI_GV_Widget_Enable(HIGV_HANDLE widgetHandle, HI_BOOL enable);

/*
* brief Get the active child widget.CNcomment: ��ȡ��Ӵ���
* attention :You can get the active window if parentHandle = HIGV_WND_MANAGER_HANDLE.
* CNcomment:��hParent = HIGV_WND_MANAGER_HANDLEʱ���Ի�ȡactive����
* param[in] parentHandle  Parent widget handle.CNcomment: ���ؼ����
* param[out] activeWidgetHandle The pointer of active childe widget.CNcomment: ��ӿؼ�ָ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST Invalid parater, such as the parent
* doesn't has active child or widget is invalid.CNcomment:
* �ؼ������Ч���߸�����û�л���� \retval ::HI_ERR_COMM_PAERM No support operation, parent window is not a
* container.CNcomment: ��֧�ָò����������ڲ����Ǹ�����
* see:HI_GV_Widget_SetActiveWidget
*/
HI_S32 HI_GV_Widget_GetActiveWidget(HIGV_HANDLE parentHandle, HIGV_HANDLE *activeWidgetHandle);

/*
* brief Get font.CNcomment: ��ȡ����
* param[in] widgetHandle Widget handle.CNcomment: �ؼ����
* param[out] fontHandle Pointer of font.CNcomment: �������ָ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Widget_GetFont(HIGV_HANDLE widgetHandle, HIGV_HANDLE *fontHandle);

/*
* brief Get parent widget, if it is window ,it will return NULL.CNcomment: ��ȡ�ؼ����ؼ�������������ڣ���ΪNULL
* param[in] widgetHandle Widget handle.CNcomment: �ؼ����
* param[out] parentHandle Ponter of parent widget handle.CNcomment: ���ؼ����ָ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_FAILURE Failure, such as, no parent. CNcomment: û�и�
*/
HI_S32 HI_GV_Widget_GetParent(HIGV_HANDLE widgetHandle, HIGV_HANDLE *parentHandle);

/*
* brief Get sibings of widget, it is mainly used to change focus.CNcomment: ��ȡ�ÿؼ����������ֵܣ���Ҫ���ڽ����л�
* param[in] widgetHandle Widget handle.CNcomment: �ؼ����
* param[out] leftSibingHandle  Left sibing widget. CNcomment: ���ھӿؼ����ָ��
* param[out] rightSibingHandle Right sibing widget.CNcomment: ���ھӿؼ����ָ��
* param[out] upSibingHandle    Up sibing widget.CNcomment: ���ھӿؼ����ָ��
* param[out] downSibingHandle  Down sibing widget.CNcomment: ���ھӿؼ����ָ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Widget_GetSiblings(HIGV_HANDLE widgetHandle, HIGV_HANDLE *leftSibingHandle,
    HIGV_HANDLE *rightSibingHandle, HIGV_HANDLE *upSibingHandle, HIGV_HANDLE *downSibingHandle);

/*
* brief Hide widget.CNcomment: ���ؿؼ�
* param[in] widgetHandle Widget handle.CNcomment: �ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Widget_Hide(HIGV_HANDLE widgetHandle);

/*
* brief Get the widget active state.CNcomment: �жϿؼ��Ƿ�
* param[in] Widget handle.CNcomment: widgetHandle �ؼ����
* retval ::HI_TRUE  The widget is active.CNcomment: �ؼ��ǻ�ؼ�
* retval ::HI_FALSE The widget is inactive.CNcomment: �ؼ����ǻ�ؼ�
*/
HI_BOOL HI_GV_Widget_IsActive(HIGV_HANDLE widgetHandle);

/*
* brief Get the widget enabel state.CNcomment: �ؼ�ʹ��״̬�����ڴ�����Ч
* param[in] widgetHandle Widget handle.CNcomment: �ؼ����
* retval ::HI_TRUE  enable state.CNcomment: ʹ��״̬
* retval ::HI_FALSE Disable state. CNcomment: ����״̬
*/
HI_BOOL HI_GV_Widget_IsEnable(HIGV_HANDLE widgetHandle);

/*
* brief The widget whether show.CNcomment: �жϿؼ��Ƿ���ʾ
* param[in] widgetHandle  Widget handle.CNcomment: �ؼ����
* retval ::HI_TRUE  Show state.CNcomment: ��ʾ״̬
* retval ::HI_FALSE  Hide state.CNcomment: ����״̬
*/
HI_BOOL HI_GV_Widget_IsShow(HIGV_HANDLE widgetHandle);

/*
* brief Get widget surface.CNcomment: ȡ�ÿؼ���surface
* param[in] widgetHandle Widget handle.CNcomment: �ؼ����
* param[out] surfaceHandle Surface pointerCNcomment: ���ָ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_GetSurface(HIGV_HANDLE widgetHandle, HIGV_HANDLE *surfaceHandle);

/*
* brief Paint the widget, it will emmit a asynchronism message.CNcomment: �첽���Ƹÿؼ�������HIGV_MSG_PAINT��Ϣ
* param[in] widgetHandle Widget handle.CNcomment: �ؼ����
* param[in] rect The area of update . CNcomment: ���Ƹ��µ�����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_FAILURE Failure such as the widget is not show.CNcomment: ���ܿؼ�������show��״̬
*/
HI_S32 HI_GV_Widget_Paint(HIGV_HANDLE widgetHandle, const HI_RECT *rect);

/*
* brief Set font.CNcomment: ��������
* param[in] widgetHandle Widget handle.CNcomment: �ؼ����
* param[in] fontHandle The font of widget. CNcomment:  �ؼ��������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_SetFont(HIGV_HANDLE widgetHandle, HIGV_HANDLE fontHandle);

/*
* brief Register message processor.CNcomment: ע����Ϣ������
* param[in] widgetHandle   Widget handle. CNcomment: �ؼ����
* param[in] msg        Message. CNcomment: ��Ϣ
* param[in] customProc Message processor.CNcomment: ��Ϣ������
* param[in] procOrder  Message prioprity.CNcomment: ��Ϣ�������ȼ�
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_Widget_SetMsgProc(HIGV_HANDLE widgetHandle, HI_U32 msg, HIGV_MSG_PROC customProc,
    HIGV_PROCORDER_E procOrder);

/*
* brief Set skin of widget.CNcomment: ���ÿؼ�Ƥ��
* param[in] widgetHandle   Widget handle. CNcomment: �ؼ����
* param[in] skinIndexHandle Skin index. CNcomment: Ƥ��״̬����
* param[in] skinHandle     Skin handle. CNcomment: Ƥ����Դ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_NORES CNcomment: �ڴ治��
* see:HI_GV_Widget_SetCharset
*/
HI_S32 HI_GV_Widget_SetSkin(HIGV_HANDLE widgetHandle, HI_U32 skinIndexHandle, HI_RESID skinHandle);

/*
* brief Set siblings of widget.CNcomment: ���ÿؼ����ֵ�
* param[in] widgetHandle  Widget handle.  CNcomment: �ؼ����
* param[in] leftSiblingHandle      Left siblings widet. CNcomment: ���ھӿؼ����
* param[in] rightSiblingHandle    Right siblings widet.CNcomment:  ���ھӿؼ����
* param[in] upSiblingHandle        Up siblings widet.CNcomment: ���ھӿؼ����
* param[in] downSiblingHandle    Down siblings widet. CNcomment:  ���ھӿؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_LOST
* see : HI_GV_Widget_GetSiblings
*/
HI_S32 HI_GV_Widget_SetSiblings(HIGV_HANDLE widgetHandle, HIGV_HANDLE leftSiblingHandle,
    HIGV_HANDLE rightSiblingHandle, HIGV_HANDLE upSiblingHandle, HIGV_HANDLE downSiblingHandle);

/*
* brief Show widget. CNcomment: ��ʾ�ؼ�
* param[in] widgetHandle   Widget handle. CNcomment: �ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* see: HI_GV_Widget_Hide
*/
HI_S32 HI_GV_Widget_Show(HIGV_HANDLE widgetHandle);

/*
* brief Move widget.CNcomment: �ƶ��ؼ�����
* param[in] widgetHandle Widget handle.  CNcomment:  �ؼ����
* param[in] x       the x coordinate that moved after.   CNcomment: �ƶ����x����
* param[in] y       the y coordinate  that moved after.  CNcomment: �ƶ����y����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_Move(HIGV_HANDLE widgetHandle, HIGV_CORD x, HIGV_CORD y);

/*
* brief Move window to top.CNcomment: �Ѵ����ö����Կؼ���Ч
* param[in] widgetHandle  Widget handle.  CNcomment: ���ھ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_NOOP Unsupport operation, such as the widget except window not support the api.CNcomment:
* ��֧�ָò���������Կؼ����øýӿ�
*/
HI_S32 HI_GV_Widget_MoveToTop(HIGV_HANDLE widgetHandle);

/*
* brief Hightlight widget.CNcomment: �����ؼ�
* param[in] widgetHandle   Widget handle. CNcomment: �ؼ����
* param[in] highlight  CNcomment: ������־
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_NOOP Unsupport operation, such as the widget is disabed.CNcomment: ��֧�ָò���������ؼ�����
*/
HI_S32 HI_GV_Widget_Highlight(HIGV_HANDLE widgetHandle, HI_BOOL highlight);

/*
* brief Whether highligt the widget.CNcomment: �ؼ��Ƿ����
* param[in] widgetHandle   Widget handle. CNcomment: �ؼ����
* retval ::HI_TRUE Highlight. CNcomment:  ����
* retval ::HI_FALSE it is not hightlight.CNcomment: �Ǹ���
*/
HI_BOOL HI_GV_Widget_IsHighlight(HIGV_HANDLE widgetHandle);

/*
* brief Set transparent of widget.CNcomment: ���ÿؼ��Ƿ�͸��
* param[in] widgetHandle  Widget handle.  CNcomment: �ؼ����
* param[in] isTrans  Transparent flag.  CNcomment: ͸����־
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_SetTransparent(HIGV_HANDLE widgetHandle, HI_BOOL isTrans);

/*
* brief Set alignment of text.CNcomment: �����ı����뷽ʽ
* param[in] widgetHandle Widget handle.   CNcomment: �ؼ����
* param[in] align  Alignment of text. CNcomment:  �ı����뷽ʽ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_SetAlign(HIGV_HANDLE widgetHandle, HI_U32 align);

/*
* brief Set text.CNcomment: �����ı�
* param[in] widgetHandle  Widget handle.  CNcomment: �ؼ����
* param[in] text   Text of wiget.  CNcomment:  �ؼ��ı�����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES No enought memory.CNcomment: û���ڴ�
* see
* ::HI_GV_Widget_GetText
* ::HI_GV_Widget_SetTextByID
*/
HI_S32 HI_GV_Widget_SetText(HIGV_HANDLE widgetHandle, const HI_CHAR *text);

/*
* brief Set text by ID.CNcomment: ͨ���ַ���ID�����ı�
* param[in] widgetHandle  Widget handle.  CNcomment: �ؼ����
* param[in] strID      String ID.CNcomment: �ؼ��ı�ID
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* see:
* HI_GV_Widget_GetText
* HI_GV_Widget_GetTextID
* HI_GV_Widget_SetText
*/
HI_S32 HI_GV_Widget_SetTextByID(HIGV_HANDLE widgetHandle, const HI_U32 strID);

/*
* brief Get text.CNcomment: ��ȡ�ؼ��ı�
* param[in] widgetHandle Widget handle.   CNcomment: �ؼ����
* param[out] buf     Text content. CNcomment: �ؼ��ı�����
* param[in] bufLen     Buffer length. CNcomment: ���pBuf�ĳ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL Null pointer and the buffer length is 0.CNcomment: ��ָ���buffer����Ϊ0
* see
* HI_GV_Widget_SetText
*/
HI_S32 HI_GV_Widget_GetText(HIGV_HANDLE widgetHandle, HI_CHAR *buf, HI_U32 bufLen);

/*
* brief Get text by ID.CNcomment: ��ȡ�ؼ��ı�ID
* attention:
* CNcomment: ��ȡ���ı�IDΪlanguage.xml���ֶε�������������1��ʼ����
* param[in] widgetHandle Widget handle. CNcomment:  �ؼ����
* param[out] strID    String ID.CNcomment:  ����ı�ID
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see :HI_GV_Widget_SetTextByID
*/
HI_S32 HI_GV_Widget_GetTextID(HIGV_HANDLE widgetHandle, HI_U32 *strID);

/*
* brief Bind database to widget.CNcomment: �����ݿ�
* param[in] widgetHandle Widget handle. CNcomment: �ؼ����
* param[in] dataSource Data source object.CNcomment: ���ݿ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* see:HI_GV_Widget_UnbindDataSource
*/
HI_S32 HI_GV_Widget_BindDataSource(HIGV_HANDLE widgetHandle, HIGV_HANDLE dataSource);

/*
* brief Unbind database to widget.CNcomment: ������ݿ�
* param[in] widgetHandle  Widget handle. CNcomment: �ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see :HI_GV_Widget_BindDataSource
*/
HI_S32 HI_GV_Widget_UnbindDataSource(HIGV_HANDLE widgetHandle);

/*
* brief Get datasource handle.CNcomment: ��ȡ����Դ���
* param[in] widgetHandle  Widget handle. CNcomment:  �ؼ����
* param[out] dataSource The pointer of datasource.CNcomment: ����Դ���ָ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Widget_GetDataSource(HIGV_HANDLE widgetHandle, HIGV_HANDLE *dataSource);

/*
* brief Get window which the widget attach. CNcomment: ��ȡ�ؼ����������ھ��
* param[in] widgetHandle Widget handle. CNcomment: �ؼ����
* param[out] windowHandle  the pointer of parent widget handle. CNcomment:  �����ھ��ָ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Widget_GetWindow(HIGV_HANDLE widgetHandle, HIGV_HANDLE *windowHandle);

/*
* brief Immediate repaint control.CNcomment: ��ʱ�ػ�ؼ���������HIGV_MSG_PAINT��Ϣ
* param[in] widgetHandle  Widget handle.  CNcomment: �ؼ����
* param[in] rect    The area of update CNcomment: ˢ������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_Update(HIGV_HANDLE widgetHandle, const HI_RECT *rect);

/*
* brief Immediate update the area of screen.CNcomment: ���ؼ���ָ������������ʾ����Ļ��
* param[in] widgetHandle Widget handle.  CNcomment:  �ؼ����
* param[in] rect  The area of update. CNcomment:  ˢ������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_Refresh(HIGV_HANDLE widgetHandle, const HI_RECT *rect);

/*
* brief Get data from db and notify the widget to upate data.CNcomment: ������Դ��ȡ���ݣ�֪ͨ�ؼ���ʾ���µ�����
* param[in] widgetHandle  Widget handle.CNcomment: �ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Widget_SyncDB(HIGV_HANDLE widgetHandle);

/*
* brief Get area of widget, the widget coordate is refre to the parent, and window is refer to the screen.CNcomment:
* ��ȡ�ؼ��򴰿ڵ���������������丸���������������Ļ \attention \n N/A.CNcomment:�� \param[in] widgetHandle Widget handle.
* CNcomment: �ؼ���� \param[out] rect    The size of widget.CNcomment: �ؼ������С
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Widget_GetRect(HIGV_HANDLE widgetHandle, HI_RECT *rect);

/*
* brief Set colorkey of window.CNcomment: ���ô���colorkey
* param[in] windowHandle Window handle. CNcomment: �ؼ����
* param[in] colorKey colorekey value.CNcomment: colorkeyֵ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_SetWinColorKey(HIGV_HANDLE windowHandle, HI_COLOR colorKey);

/*
* brief is it a window.CNcomment: �ؼ��Ƿ�Ϊ����
* param[in] widgetHandle   Widget handle.CNcomment: �ؼ����
* retval ::HI_TRUE
* retval ::HI_FALSE
*/
HI_BOOL HI_GV_Widget_IsWindow(HIGV_HANDLE widgetHandle);

/*
* brief Cancel paint.CNcomment: ȡ������
* param[in] widgetHandle Widet handle.CNcomment: �ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_Depaint(HIGV_HANDLE widgetHandle);

/*
* brief Convert the screen coordaite to widget coordiate.CNcomment: ����Ļ����ת���ɿؼ�����
* param[in] widgetHandle Widget handle.CNcomment: �ؼ����
* param[in] screenX The x coordinate of screen.CNcomment: ��Ļ����X
* param[in] screenY The y coordinate of screen.CNcomment: ��Ļ����Y
* param[out] widgetX The x coordinate of widget.CNcomment: ��ſؼ�����X
* param[out] widgetY The y coordinate of widget.CNcomment: ��ſؼ�����Y
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_Screen2Widget(HIGV_HANDLE widgetHandle, HIGV_CORD screenX, HIGV_CORD screenY, HIGV_CORD *widgetX,
                                  HIGV_CORD *widgetY);

/*
* brief Convert thewidget coordaite to  screen coordiate.CNcomment: ���ؼ�����ת������Ļ����
* param[in] widgetHandle Widget handle.CNcomment: �ؼ����
* param[in] widgetX The x coordinate of widget.CNcomment: �ؼ�����X
* param[in] widgetY The y coordinate of widget.CNcomment: �ؼ�����Y
* param[out] screenX The x coordinate of screen.CNcomment: �����Ļ����X
* param[out] screenY The y coordinate of screen.CNcomment: �����Ļ����Y
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_Widget2Screen(HIGV_HANDLE widgetHandle, HIGV_CORD widgetX, HIGV_CORD widgetY, HIGV_CORD *screenX,
    HIGV_CORD *screenY);

/*
* brief Get widget correspoding coordate.CNcomment: ��ȡ�������ڶ���ؼ�
* param[in]  screenX The x coordinate of widget.CNcomment: �ؼ�����X
* param[in]  screenY The x coordinate of widget.CNcomment: �ؼ�����Y
* param[out] widgetHandle The x coordinate of screen.CNcomment: ��ȡ����Ļ����ؼ�
* retval ::HI_SUCCESS
* retval ::HI_EINVAL
* retval ::HI_ENOTINIT
* retval ::HI_FAILURE
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_GetWidgetByPos(HIGV_CORD screenX, HIGV_CORD screenY, HIGV_HANDLE *widgetHandle);

/*
* brief Get widget correspoding coordate.CNcomment: ��ȡ�������ڶ���ؼ�,�����ڴ������豸
* param[in]  screenX The x coordinate of widget.CNcomment: �ؼ�����X
* param[in]  screenY The x coordinate of widget.CNcomment: �ؼ�����Y
* param[out] widgetHandle The x coordinate of screen.CNcomment: ��ȡ����Ļ����ؼ�,����������ؼ�
* retval ::HI_SUCCESS
* retval ::HI_EINVAL
* retval ::HI_ENOTINIT
* retval ::HI_FAILURE
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_GetWidgetByPos_TouchDevice(HIGV_CORD screenX, HIGV_CORD screenY, HIGV_HANDLE *widgetHandle);

/*
* brief Bind the scrollbar to widget.CNcomment: �ؼ��󶨹�����
* param[in] widgetHandle  Widget handle. CNcomment: �ؼ����
* param[in] scrollBarHandle Scrollbar handle.CNcomment: �������ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Widget_BindScrollBar(HIGV_HANDLE widgetHandle, HIGV_HANDLE scrollBarHandle);

/*
* brief Get the scrollbar of widget.CNcomment: ��ȡ�ÿؼ��󶨵�scrollbar
* param[in] widgetHandle  widget handle. CNcomment: �ؼ����
* param[in] scrollBarHandle  Binding scrollbar CNcomment: �󶨵�scrollbar
* retval N/A.CNcomment:��
*/
HI_S32 HI_GV_Widget_GetScrollBar(HIGV_HANDLE widgetHandle, HIGV_HANDLE *scrollBarHandle);

#ifdef HIGV_USE_WIDGET_BUTTON
/*
* brief Get the sate of all checkbox.CNcomment: ���ÿؼ��µ�����Check Box����Ϊѡ��״̬��δѡ��״̬
* param[in] parentHandle Parent widget handle. CNcomment: ���ؼ����
* param[in] status  Status. CNcomment: ״̬
* retval N/A.CNcomment:��
*/
HI_S32 HI_GV_Widget_SetAllCheckStatus(HIGV_HANDLE parentHandle, HIGV_BUTTON_STATUS_E status);
#endif

/*
* brief Change window size, it is not effect widget. CNcomment: �ı䴰�ڴ�С�����ڿؼ���Ч
* param[in] widgetHandle  Widget handle.  CNcomment: ���ھ��
* param[in] width   Window width.   CNcomment: �ı�󴰿ڿ��
* param[in] height    widnow height. CNcomment:  �ı�󴰿ڸ߶�
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_NOOP
*/
HI_S32 HI_GV_Widget_Resize(HIGV_HANDLE widgetHandle, HI_S32 width, HI_S32 height);

/*
* brief Query the widget whether support the input method window.CNcomment: ��ѰĿ��ؼ��Ƿ���Ҫ�������뷨����
* param[in] widgetHandle      Widget handle.  CNcomment: ���ھ��
* param[in] supportImeType  Input method type.CNcomment:  ֧�ֵ����뷨����
*          *    ȡֵΪ��������λ��
*         *    ֧�����У�  HIGV_IMETYPE_ALLTYPE
*             Ӣ�ģ�      HIGV_IMETYPE_ENGLISH
*             ��дӢ�ģ�  HIGV_IMETYPE_CAPENGLISH
*             ���֣�      HIGV_IMETYPE_NUMBER
*             ���ţ�      HIGV_IMETYPE_SYMBOL
*             ƴ����      HIGV_IMETYPE_PINYIN
* retval HI_TRUE          Is need input method window.   CNcomment: ��Ҫ���뷨����
* return HI_FALSE          it is not need. CNcomment:  ����Ҫ
*/
HI_BOOL HI_GV_Widget_IsNeedIMEWindow(HIGV_HANDLE widgetHandle, HI_U32 *supportImeType);

/*
* brief Get the layer correspoding widget.CNcomment: ��ȡWidget����ͼ��
* param[in]  widgetHandle       Widget handle.CNcomment: Widget���
* param[out] layerHandle       Layer.   CNcomment: ͼ��
* retval HI_SUCCESS
* return HI_ERR_COMM_LOST
* return HI_ERR_COMM_EMPTY
*/
HI_S32 HI_GV_Widget_GetLayer(HIGV_HANDLE widgetHandle, HIGV_HANDLE *layerHandle);

/*
* brief Set the private data of widget.CNcomment: ����Widget��˽������
* attention :The memory of private data should be released by user.
* CNcomment: ˽�������û������ͷ��ڴ�
* param[in]  widgetHandle      Widget handle.CNcomment: Widget���
* param[in] privateData    The pointer of private data.CNcomment: ˽������ָ��
* retval ::HI_SUCCESS
* return ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Widget_SetPrivate(HIGV_HANDLE widgetHandle, HI_VOID *privateData);

/*
* brief CNcomment: ��ȡWidget��˽������
* The memory of private data should be released by user.
* CNcomment: ˽�������û������ͷ��ڴ�
* aram[in]  widgetHandle    Widget handle.CNcomment:  Widget���
* param[out] privateData    The pointer of private data. CNcomment: ˽������ָ��
* retval ::HI_SUCCESS
* return ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Widget_GetPrivate(HIGV_HANDLE widgetHandle, HI_VOID **privateData);

/*
* brief Get the clone handle correspoding layer.CNcomment: ��ȡָ��ͼ��ؼ��Ŀ�¡���
* attention \n CNcomment: �ú�����ѯ�Ŀ�¡���δ����Ч����Ҫ����Ч�Լ��
* param[in]  widgetHandle  Widget handle.CNcomment: �ؼ����
* param[in]  layerHandle     Layer handle.CNcomment: ͼ����
* param[out] cloneHandle   Clone handle. CNcomment: ��¡�ľ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_INTER
* retval ::HI_ERR_COMM_OVERFLOW The layer number is over.CNcomment:  ͼ����������Χ
*/
HI_S32 HI_GV_Widget_GetCloneHandle(HIGV_HANDLE widgetHandle, HIGV_HANDLE layerHandle, HIGV_HANDLE *cloneHandle);

/*
* brief Whether errasing the bakground.CNcomment: ���ÿؼ��Ƿ��������
* attention  CNcomment: ���ڹ���ģʽĬ���ǲ���������\n
* param[in]  widgetHandle  Widget handle.CNcomment: �ؼ����
* param[in] isErasebg CNcomment: �Ƿ��������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_EraseBackground(HIGV_HANDLE widgetHandle, HI_BOOL isErasebg);

/*
* brief Register the infomation of widget type, user can apply this api to register their own widget.CNcomment:
* ע��ؼ�������Ϣ���û�����ͨ���ýӿ� ע���Զ���Ŀؼ�������Ϣ \attention \n N/A.CNcomment:�� \param[in] typeInfo The
* info of widget typeCNcomment: �ؼ�������Ϣ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_EXIST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_Widget_RgisterWidget(HIGV_WIDGET_TYPEINFO_S typeInfo);

/*
* brief Unregister the widget.CNcomment: ��ע��ؼ���Ϣ
* param[in] typeID The type ID of widget.CNcomment: �Զ���ؼ�����ID
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_UnRgisterWidget(HI_U32 typeID);

/*
* brief Whether active the widget, This api is added for pop window of combobox.CNcomment:
* Ϊ���������ӵĽӿڣ���ʹ��ģ̬���ڣ�ģ̬�����ϵĵ����� ����Ҳ���Լ��� \attention \n it is should attention to us this
* api, otherwise the modal window will loss the function. CNcomment: ����ʹ�ô˽ӿڣ�����ģ̬���ڽ�ʧȥ���� \param[in]
* widgetHandle   Widget handle. CNcomment: �ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_CanActive(HIGV_HANDLE widgetHandle);

/*
* brief enable/disable mirror the widget when change language.CNcomment:ʹ���Ƿ�������ؼ�
* param[in] widgetHandle Widget handle.CNcomment: �ؼ����
* param[in] posMirror   Whether mirror widget pos.CNcomment:�Ƿ������л�����ʱ�ڸ������о���
* param[in] interiorMirror  Whether mirror widget interior.CNcomment:�Ƿ������л�����ʱ���пؼ��ڲ�����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* see : HI_GV_Widget_GetMirrorAttr
*/
HI_S32 HI_GV_Widget_EnableMirror(HIGV_HANDLE widgetHandle, HI_BOOL posMirror, HI_BOOL interiorMirror);

/*
* brief Get the mirror attribute.CNcommment:��ȡ����ؼ�����
* param[in] widgetHandle  Widget handle.CNcomment: �ؼ����
* param[out] posMirror   Whether mirror widget pos.CNcomment:�Ƿ������л�����ʱ�ڸ������о���
* param[out] interiorMirror  Whether mirror widget interior.CNcomment:�Ƿ������л�����ʱ���пؼ��ڲ�����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_EMPTY
* see : HI_GV_Widget_EnableMirror
*/
HI_S32 HI_GV_Widget_GetMirrorAttr(HIGV_HANDLE widgetHandle, HI_BOOL *posMirror, HI_BOOL *interiorMirror);

/*
* brief Set text direction of the widget.CNcommment:ǿ�ƿؼ��ı��ķ���
* param[in] widgetHandle  Widget handle.CNcomment: �ؼ����
* param[in] direction  Text direction.CNcomment:�ı��ķ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_SetTextDir(HIGV_HANDLE widgetHandle, HIGV_TEXTDIR_E direction);

/*
* brief Set fouces switch mode of the widget.CNcommment:���ÿؼ������л�ģʽ
* param[in] widgetHandle  Widget handle.CNcomment: �ؼ����
* param[in] fousMode.CNcomment:�����л�ģʽ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_SetFoucsMode(HIGV_HANDLE widgetHandle, HIGV_FOCUS_SWITCH_E fousMode);

/*
* brief Set text or image margin. CNcomment:�������ֻ�ͼƬ��ʾ�ı�Ե���
* attention:
* For button,label,trackbar,listbox,msgbox,timerbar.
* CNcomment:������button label trackbar listbox msgbox timerbar�ؼ�
* param[in] widgetHandle  Widget handle.CNcomment: �ؼ����
* param[in] leftMargin  Left margin.CNcomment:���Ե���
* param[in] rightMargin  Right margin.CNcomment:�ұ�Ե���
* param[in] topMargin  Top margin.CNcomment:�ϱ�Ե���
* param[in] bottomMargin  Bottom margin.CNcomment:�±�Ե���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Widget_SetMargin(HIGV_HANDLE widgetHandle, HI_U32 leftMargin, HI_U32 rightMargin, HI_U32 topMargin,
    HI_U32 bottomMargin);

/*
* brief Get the margin.CNcomment:��ȡ��Ե���
* param[in] widgetHandle  Widget handle.CNcomment: �ؼ����
* param[out] leftMargin Left margin.CNcomment: ���Ե���
* param[out] rightMargin  Right margin.CNcomment:�ұ�Ե���
* param[out] topMargin  Top margin.CNcomment:�ϱ�Ե���
* param[out] bottomMargin Bottom margin.CNcomment:�±�Ե���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Widget_GetMargin(HIGV_HANDLE widgetHandle, HI_U32 *leftMargin, HI_U32 *rightMargin, HI_U32 *topMargin,
    HI_U32 *bottomMargin);

/*
* brief enable config image res path.CNcommment:ʹ������ͼƬ��Դ�����·��
* param[in] widgetHandle  Widget handle.CNcomment: �ؼ����
* param[in] enable enable or disable image res path.CNcomment:ʹ�ܿ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_EnableResPach(HIGV_HANDLE widgetHandle, HI_BOOL enable);

/*
* brief enable widget foget focus.CNcommment: show & active�ؼ�
* param[in] widgetHandle  Widget handle.CNcomment: �ؼ����
* param[in] activeShow. CNcomment:ʹ�ܻ��ʹ��
* retval ::HI_SUCCESS
*/
HI_S32 HI_GV_Widget_ActiveShow(HIGV_HANDLE widgetHandle, HI_BOOL activeShow);

/*
* brief Set bit block transfer operation of picture type skin.CNcommment: ���ÿؼ�ͼƬ��Ƥ���İ��ƻ�ϲ�������
* param[in] widgetHandle  Widget handle.CNcomment: �ؼ����
* param[in] blitOpt Bit block transfer operation.CNcomment:���ƻ�ϲ�����������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_Widget_SetSkinBlitOpt(HIGV_HANDLE widgetHandle, HIGO_BLTOPT_S *blitOpt);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* HI_GV_WIDGET_H */
