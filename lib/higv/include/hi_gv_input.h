/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: input API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HIGV_INPUT_H
#define HIGV_INPUT_H

#include "hi_type.h"
#include "hi_go.h"
#include <sys/time.h>
#include "hi_gv_gesture.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    HI_U32 msg;  /* Mouse/keyboard action(up, down, move, double click)
    CNcomment:��갴�£��ɿ���������˫�����¼�,���߼��̰��£��ɿ��� */
    HI_U32 value; /* Mouse button  (left, middle, right) or keyboard , CNcomment:��ֵ����������У��Ҽ� */
    HI_S32 dx; /*  Mouse move x offset which is relative last value  , CNcomment:����ƶ�ƫ����X������ϴε�ֵ */
    HI_S32 dy; /*  Mouse move y offset which is relative last value , CNcomment:����ƶ�ƫ����X������ϴε�ֵ */
    HI_S32 step; /* Mouse move step offset which is relative last value  ,CNcomment: ������ƫ����������ϴε�ֵ */
} HIGV_INPUTEVENT_S;

/* add some data struct refers to the implementation of DFB , CNcomment:�ο�DFB��ʵ�����ӱ�Ҫ�����ݽṹ */
#define HIGV_D_ARRAY_SIZE(array)                         \
    (static_cast<int>(sizeof(array) / sizeof((array)[0])))

#define HIGV_DFB_KEY(type, index) ((HIGV_DIKT_##type) | (index))
#define HIGV_DFB_FUNCTION_KEY(n)  (HIGV_DFB_KEY(FUNCTION, n))
#define HIGV_DFB_MODIFIER_KEY(i)  (HIGV_DFB_KEY(MODIFIER, (1 << i)))
#define HIGV_DFB_CUSTOM_KEY(n)    (HIGV_DFB_KEY(CUSTOM, n))
/*
 * KeyBoard key types (for advanced mapping)
 */
typedef enum {
    HIGV_DIKT_UNICODE = 0x0000,   /* Unicode 3.x character
                                (compatible to Latin-1) */
    HIGV_DIKT_SPECIAL = 0xF000,   /* Special key (e.g. Cursor Up or Menu) */
    HIGV_DIKT_FUNCTION = 0xF100,  /* Function key (F1 - Fn) */
    HIGV_DIKT_MODIFIER = 0xF200,  /* Modifier key */
    HIGV_DIKT_LOCK = 0xF300,      /* Lock key (e.g. CapsLock) */
    HIGV_DIKT_DEAD = 0xF400,      /* Dead key (e.g. dead grave) */
    HIGV_DIKT_CUSTOM = 0xF500,    /* Custom key (vendor specific) */
    HIGV_DIKT_IDENTIFIER = 0xF600 /* DirectFB key identifier */
} HIGV_KBDInputDeviceKeyType;

/*
* KeyBoard modifier key identifiers (for advanced mapping)
*/
typedef enum {
    HIGV_DIMKI_SHIFT,   /* Shift modifier key */
    HIGV_DIMKI_CONTROL, /* Control modifier key */
    HIGV_DIMKI_ALT,     /* Alt modifier key */
    HIGV_DIMKI_ALTGR,   /* AltGr modifier key */
    HIGV_DIMKI_META,    /* Meta modifier key */
    HIGV_DIMKI_SUPER,   /* Super modifier key */
    HIGV_DIMKI_HYPER,   /* Hyper modifier key */

    HIGV_DIMKI_FIRST = HIGV_DIMKI_SHIFT,
    HIGV_DIMKI_LAST = HIGV_DIMKI_HYPER
} HIGV_KBDInputDeviceModifierKeyIdentifier;

/*
 * The type of an input event.
 */
typedef enum {
    HIGV_DIET_UNKNOWN = 0, /* unknown event */
    HIGV_DIET_KEYPRESS,    /* a key is been pressed */
    HIGV_DIET_KEYRELEASE,  /* a key is been released */
} HIGV_KBDInputEventType;

/*
 * Flags defining which additional (optional) event fields are valid.
 */
typedef enum {
    HIGV_DIEF_NONE = 0x0000,      /* no additional fields */
    HIGV_DIEF_TIMESTAMP = 0x0001, /* timestamp is valid */
    HIGV_DIEF_AXISABS = 0x0002,   /* axis and axisabs are valid */
    HIGV_DIEF_AXISREL = 0x0004,   /* axis and axisrel are valid */

    HIGV_DIEF_KEYCODE = 0x0008,   /* used internally by the input core,
                               always set at application level */
    HIGV_DIEF_KEYID = 0x0010,     /* used internally by the input core,
                             always set at application level */
    HIGV_DIEF_KEYSYMBOL = 0x0020, /* used internally by the input core,
                                 always set at application level */
    HIGV_DIEF_MODIFIERS = 0x0040, /* used internally by the input core,
                                 always set at application level */
    HIGV_DIEF_LOCKS = 0x0080,     /* used internally by the input core,
                             always set at application level */
    HIGV_DIEF_BUTTONS = 0x0100,   /* used internally by the input core,
                               always set at application level */
    HIGV_DIEF_GLOBAL = 0x0200,    /* Only for event buffers creates by IDirectFB::CreateInputEventBuffer()
    with global events enabled.Indicates that the event would have been filtered if the buffer hadn't been global. */
    HIGV_DIEF_REPEAT = 0x0400,    /* repeated event, e.g. key or button press */
    HIGV_DIEF_FOLLOW = 0x0800,    /* another event will follow immediately, e.g. x/y axis */

    HIGV_DIEF_MIN = 0x1000, /* minimum value is set, e.g. for absolute axis motion */
    HIGV_DIEF_MAX = 0x2000, /* maximum value is set, e.g. for absolute axis motion */
} HIGV_KBDInputEventFlags;

/* KeyBoard input event */
typedef struct {
    HIGV_KBDInputEventType type; /* type of event */

    HIGV_KBDInputEventFlags flags; /* which optional fields are valid? */

    /* additionally (check flags) */
    struct timeval timestamp; /* time of event creation */

    /* HIGV_DIET_KEYPRESS, HIGV_DIET_KEYRELEASE */
    HI_U32 key_code; /* hardware keycode, no mapping, -1 if device doesn't differentiate between several keys */
} HIGV_KEYBOARD_EVENT_S;

typedef struct hiHIGV_TOUCH_GESTURE_EVENT_S {
    HIGV_TOUCH_E touchtype;
    HIGV_TOUCH_EVENT_S touchevent;
    HI_BOOL isgesture;
    HIGV_GESTURE_E gesturetype;
    HIGV_GESTURE_EVENT_S gestureevent;
} HIGV_TOUCH_GESTURE_EVENT_S;

/*
 * KeyBoard key identifiers (for basic mapping)
 */
typedef enum {
    HIGV_DIKI_UNKNOWN = HIGV_DFB_KEY(IDENTIFIER, 0),

    HIGV_DIKI_A,
    HIGV_DIKI_B,
    HIGV_DIKI_C,
    HIGV_DIKI_D,
    HIGV_DIKI_E,
    HIGV_DIKI_F,
    HIGV_DIKI_G,
    HIGV_DIKI_H,
    HIGV_DIKI_I,
    HIGV_DIKI_J,
    HIGV_DIKI_K,
    HIGV_DIKI_L,
    HIGV_DIKI_M,
    HIGV_DIKI_N,
    HIGV_DIKI_O,
    HIGV_DIKI_P,
    HIGV_DIKI_Q,
    HIGV_DIKI_R,
    HIGV_DIKI_S,
    HIGV_DIKI_T,
    HIGV_DIKI_U,
    HIGV_DIKI_V,
    HIGV_DIKI_W,
    HIGV_DIKI_X,
    HIGV_DIKI_Y,
    HIGV_DIKI_Z,

    HIGV_DIKI_0,
    HIGV_DIKI_1,
    HIGV_DIKI_2,
    HIGV_DIKI_3,
    HIGV_DIKI_4,
    HIGV_DIKI_5,
    HIGV_DIKI_6,
    HIGV_DIKI_7,
    HIGV_DIKI_8,
    HIGV_DIKI_9,

    HIGV_DIKI_F1,
    HIGV_DIKI_F2,
    HIGV_DIKI_F3,
    HIGV_DIKI_F4,
    HIGV_DIKI_F5,
    HIGV_DIKI_F6,
    HIGV_DIKI_F7,
    HIGV_DIKI_F8,
    HIGV_DIKI_F9,
    HIGV_DIKI_F10,
    HIGV_DIKI_F11,
    HIGV_DIKI_F12,

    HIGV_DIKI_SHIFT_L,
    HIGV_DIKI_SHIFT_R,
    HIGV_DIKI_CONTROL_L,
    HIGV_DIKI_CONTROL_R,
    HIGV_DIKI_ALT_L,
    HIGV_DIKI_ALT_R,
    HIGV_DIKI_META_L,
    HIGV_DIKI_META_R,
    HIGV_DIKI_SUPER_L,
    HIGV_DIKI_SUPER_R,
    HIGV_DIKI_HYPER_L,
    HIGV_DIKI_HYPER_R,

    HIGV_DIKI_CAPS_LOCK,
    HIGV_DIKI_NUM_LOCK,
    HIGV_DIKI_SCROLL_LOCK,

    HIGV_DIKI_ESCAPE,
    HIGV_DIKI_LEFT,
    HIGV_DIKI_RIGHT,
    HIGV_DIKI_UP,
    HIGV_DIKI_DOWN,
    HIGV_DIKI_TAB,
    HIGV_DIKI_ENTER,
    HIGV_DIKI_SPACE,
    HIGV_DIKI_BACKSPACE,
    HIGV_DIKI_INSERT,
    HIGV_DIKI_DELETE,
    HIGV_DIKI_HOME,
    HIGV_DIKI_END,
    HIGV_DIKI_PAGE_UP,
    HIGV_DIKI_PAGE_DOWN,
    HIGV_DIKI_PRINT,
    HIGV_DIKI_PAUSE,

    /*  The labels on these keys depend on the type of keyboard.
    *  We've choosen the names from a US keyboard layout. The
    *  comments refer to the ISO 9995 terminology.
    */
    HIGV_DIKI_QUOTE_LEFT,    /*  TLDE  */
    HIGV_DIKI_MINUS_SIGN,    /*  AE11  */
    HIGV_DIKI_EQUALS_SIGN,   /*  AE12  */
    HIGV_DIKI_BRACKET_LEFT,  /*  AD11  */
    HIGV_DIKI_BRACKET_RIGHT, /*  AD12  */
    HIGV_DIKI_BACKSLASH,     /*  BKSL  */
    HIGV_DIKI_SEMICOLON,     /*  AC10  */
    HIGV_DIKI_QUOTE_RIGHT,   /*  AC11  */
    HIGV_DIKI_COMMA,         /*  AB08  */
    HIGV_DIKI_PERIOD,        /*  AB09  */
    HIGV_DIKI_SLASH,         /*  AB10  */

    HIGV_DIKI_LESS_SIGN, /*  103rd  */

    HIGV_DIKI_KP_DIV,
    HIGV_DIKI_KP_MULT,
    HIGV_DIKI_KP_MINUS,
    HIGV_DIKI_KP_PLUS,
    HIGV_DIKI_KP_ENTER,
    HIGV_DIKI_KP_SPACE,
    HIGV_DIKI_KP_TAB,
    HIGV_DIKI_KP_F1,
    HIGV_DIKI_KP_F2,
    HIGV_DIKI_KP_F3,
    HIGV_DIKI_KP_F4,
    HIGV_DIKI_KP_EQUAL,
    HIGV_DIKI_KP_SEPARATOR,

    HIGV_DIKI_KP_DECIMAL,
    HIGV_DIKI_KP_0,
    HIGV_DIKI_KP_1,
    HIGV_DIKI_KP_2,
    HIGV_DIKI_KP_3,
    HIGV_DIKI_KP_4,
    HIGV_DIKI_KP_5,
    HIGV_DIKI_KP_6,
    HIGV_DIKI_KP_7,
    HIGV_DIKI_KP_8,
    HIGV_DIKI_KP_9,

    HIGV_DIKI_KEYDEF_END,
    HIGV_DIKI_NUMBER_OF_KEYS = HIGV_DIKI_KEYDEF_END - HIGV_DFB_KEY(IDENTIFIER, 0)
} HIGV_DFBInputDeviceKeyIdentifier;

/*
 * KeyBoard key symbols (for advanced mapping)
 */
typedef enum {
    /*
    * Unicode excerpt - Controls and Basic Latin
    *
    * Any Unicode 3.x character can be used as a DirectFB key symbol,
    * the values of this enum are compatible with Unicode.
    */
    HIGV_DIKS_NULL = HIGV_DFB_KEY(UNICODE, 0x00),
    HIGV_DIKS_BACKSPACE = HIGV_DFB_KEY(UNICODE, 0x08),
    HIGV_DIKS_TAB = HIGV_DFB_KEY(UNICODE, 0x09),
    HIGV_DIKS_RETURN = HIGV_DFB_KEY(UNICODE, 0x0D),
    HIGV_DIKS_CANCEL = HIGV_DFB_KEY(UNICODE, 0x18),
    HIGV_DIKS_ESCAPE = HIGV_DFB_KEY(UNICODE, 0x1B),
    HIGV_DIKS_SPACE = HIGV_DFB_KEY(UNICODE, 0x20),
    HIGV_DIKS_EXCLAMATION_MARK = HIGV_DFB_KEY(UNICODE, 0x21),
    HIGV_DIKS_QUOTATION = HIGV_DFB_KEY(UNICODE, 0x22),
    HIGV_DIKS_NUMBER_SIGN = HIGV_DFB_KEY(UNICODE, 0x23),
    HIGV_DIKS_DOLLAR_SIGN = HIGV_DFB_KEY(UNICODE, 0x24),
    HIGV_DIKS_PERCENT_SIGN = HIGV_DFB_KEY(UNICODE, 0x25),
    HIGV_DIKS_AMPERSAND = HIGV_DFB_KEY(UNICODE, 0x26),
    HIGV_DIKS_APOSTROPHE = HIGV_DFB_KEY(UNICODE, 0x27),
    HIGV_DIKS_PARENTHESIS_LEFT = HIGV_DFB_KEY(UNICODE, 0x28),
    HIGV_DIKS_PARENTHESIS_RIGHT = HIGV_DFB_KEY(UNICODE, 0x29),
    HIGV_DIKS_ASTERISK = HIGV_DFB_KEY(UNICODE, 0x2A),
    HIGV_DIKS_PLUS_SIGN = HIGV_DFB_KEY(UNICODE, 0x2B),
    HIGV_DIKS_COMMA = HIGV_DFB_KEY(UNICODE, 0x2C),
    HIGV_DIKS_MINUS_SIGN = HIGV_DFB_KEY(UNICODE, 0x2D),
    HIGV_DIKS_PERIOD = HIGV_DFB_KEY(UNICODE, 0x2E),
    HIGV_DIKS_SLASH = HIGV_DFB_KEY(UNICODE, 0x2F),
    HIGV_DIKS_0 = HIGV_DFB_KEY(UNICODE, 0x30),
    HIGV_DIKS_1 = HIGV_DFB_KEY(UNICODE, 0x31),
    HIGV_DIKS_2 = HIGV_DFB_KEY(UNICODE, 0x32),
    HIGV_DIKS_3 = HIGV_DFB_KEY(UNICODE, 0x33),
    HIGV_DIKS_4 = HIGV_DFB_KEY(UNICODE, 0x34),
    HIGV_DIKS_5 = HIGV_DFB_KEY(UNICODE, 0x35),
    HIGV_DIKS_6 = HIGV_DFB_KEY(UNICODE, 0x36),
    HIGV_DIKS_7 = HIGV_DFB_KEY(UNICODE, 0x37),
    HIGV_DIKS_8 = HIGV_DFB_KEY(UNICODE, 0x38),
    HIGV_DIKS_9 = HIGV_DFB_KEY(UNICODE, 0x39),
    HIGV_DIKS_COLON = HIGV_DFB_KEY(UNICODE, 0x3A),
    HIGV_DIKS_SEMICOLON = HIGV_DFB_KEY(UNICODE, 0x3B),
    HIGV_DIKS_LESS_THAN_SIGN = HIGV_DFB_KEY(UNICODE, 0x3C),
    HIGV_DIKS_EQUALS_SIGN = HIGV_DFB_KEY(UNICODE, 0x3D),
    HIGV_DIKS_GREATER_THAN_SIGN = HIGV_DFB_KEY(UNICODE, 0x3E),
    HIGV_DIKS_QUESTION_MARK = HIGV_DFB_KEY(UNICODE, 0x3F),
    HIGV_DIKS_AT = HIGV_DFB_KEY(UNICODE, 0x40),
    HIGV_DIKS_CAPITAL_A = HIGV_DFB_KEY(UNICODE, 0x41),
    HIGV_DIKS_CAPITAL_B = HIGV_DFB_KEY(UNICODE, 0x42),
    HIGV_DIKS_CAPITAL_C = HIGV_DFB_KEY(UNICODE, 0x43),
    HIGV_DIKS_CAPITAL_D = HIGV_DFB_KEY(UNICODE, 0x44),
    HIGV_DIKS_CAPITAL_E = HIGV_DFB_KEY(UNICODE, 0x45),
    HIGV_DIKS_CAPITAL_F = HIGV_DFB_KEY(UNICODE, 0x46),
    HIGV_DIKS_CAPITAL_G = HIGV_DFB_KEY(UNICODE, 0x47),
    HIGV_DIKS_CAPITAL_H = HIGV_DFB_KEY(UNICODE, 0x48),
    HIGV_DIKS_CAPITAL_I = HIGV_DFB_KEY(UNICODE, 0x49),
    HIGV_DIKS_CAPITAL_J = HIGV_DFB_KEY(UNICODE, 0x4A),
    HIGV_DIKS_CAPITAL_K = HIGV_DFB_KEY(UNICODE, 0x4B),
    HIGV_DIKS_CAPITAL_L = HIGV_DFB_KEY(UNICODE, 0x4C),
    HIGV_DIKS_CAPITAL_M = HIGV_DFB_KEY(UNICODE, 0x4D),
    HIGV_DIKS_CAPITAL_N = HIGV_DFB_KEY(UNICODE, 0x4E),
    HIGV_DIKS_CAPITAL_O = HIGV_DFB_KEY(UNICODE, 0x4F),
    HIGV_DIKS_CAPITAL_P = HIGV_DFB_KEY(UNICODE, 0x50),
    HIGV_DIKS_CAPITAL_Q = HIGV_DFB_KEY(UNICODE, 0x51),
    HIGV_DIKS_CAPITAL_R = HIGV_DFB_KEY(UNICODE, 0x52),
    HIGV_DIKS_CAPITAL_S = HIGV_DFB_KEY(UNICODE, 0x53),
    HIGV_DIKS_CAPITAL_T = HIGV_DFB_KEY(UNICODE, 0x54),
    HIGV_DIKS_CAPITAL_U = HIGV_DFB_KEY(UNICODE, 0x55),
    HIGV_DIKS_CAPITAL_V = HIGV_DFB_KEY(UNICODE, 0x56),
    HIGV_DIKS_CAPITAL_W = HIGV_DFB_KEY(UNICODE, 0x57),
    HIGV_DIKS_CAPITAL_X = HIGV_DFB_KEY(UNICODE, 0x58),
    HIGV_DIKS_CAPITAL_Y = HIGV_DFB_KEY(UNICODE, 0x59),
    HIGV_DIKS_CAPITAL_Z = HIGV_DFB_KEY(UNICODE, 0x5A),
    HIGV_DIKS_SQUARE_BRACKET_LEFT = HIGV_DFB_KEY(UNICODE, 0x5B),
    HIGV_DIKS_BACKSLASH = HIGV_DFB_KEY(UNICODE, 0x5C),
    HIGV_DIKS_SQUARE_BRACKET_RIGHT = HIGV_DFB_KEY(UNICODE, 0x5D),
    HIGV_DIKS_CIRCUMFLEX_ACCENT = HIGV_DFB_KEY(UNICODE, 0x5E),
    HIGV_DIKS_UNDERSCORE = HIGV_DFB_KEY(UNICODE, 0x5F),
    HIGV_DIKS_GRAVE_ACCENT = HIGV_DFB_KEY(UNICODE, 0x60),
    HIGV_DIKS_SMALL_A = HIGV_DFB_KEY(UNICODE, 0x61),
    HIGV_DIKS_SMALL_B = HIGV_DFB_KEY(UNICODE, 0x62),
    HIGV_DIKS_SMALL_C = HIGV_DFB_KEY(UNICODE, 0x63),
    HIGV_DIKS_SMALL_D = HIGV_DFB_KEY(UNICODE, 0x64),
    HIGV_DIKS_SMALL_E = HIGV_DFB_KEY(UNICODE, 0x65),
    HIGV_DIKS_SMALL_F = HIGV_DFB_KEY(UNICODE, 0x66),
    HIGV_DIKS_SMALL_G = HIGV_DFB_KEY(UNICODE, 0x67),
    HIGV_DIKS_SMALL_H = HIGV_DFB_KEY(UNICODE, 0x68),
    HIGV_DIKS_SMALL_I = HIGV_DFB_KEY(UNICODE, 0x69),
    HIGV_DIKS_SMALL_J = HIGV_DFB_KEY(UNICODE, 0x6A),
    HIGV_DIKS_SMALL_K = HIGV_DFB_KEY(UNICODE, 0x6B),
    HIGV_DIKS_SMALL_L = HIGV_DFB_KEY(UNICODE, 0x6C),
    HIGV_DIKS_SMALL_M = HIGV_DFB_KEY(UNICODE, 0x6D),
    HIGV_DIKS_SMALL_N = HIGV_DFB_KEY(UNICODE, 0x6E),
    HIGV_DIKS_SMALL_O = HIGV_DFB_KEY(UNICODE, 0x6F),
    HIGV_DIKS_SMALL_P = HIGV_DFB_KEY(UNICODE, 0x70),
    HIGV_DIKS_SMALL_Q = HIGV_DFB_KEY(UNICODE, 0x71),
    HIGV_DIKS_SMALL_R = HIGV_DFB_KEY(UNICODE, 0x72),
    HIGV_DIKS_SMALL_S = HIGV_DFB_KEY(UNICODE, 0x73),
    HIGV_DIKS_SMALL_T = HIGV_DFB_KEY(UNICODE, 0x74),
    HIGV_DIKS_SMALL_U = HIGV_DFB_KEY(UNICODE, 0x75),
    HIGV_DIKS_SMALL_V = HIGV_DFB_KEY(UNICODE, 0x76),
    HIGV_DIKS_SMALL_W = HIGV_DFB_KEY(UNICODE, 0x77),
    HIGV_DIKS_SMALL_X = HIGV_DFB_KEY(UNICODE, 0x78),
    HIGV_DIKS_SMALL_Y = HIGV_DFB_KEY(UNICODE, 0x79),
    HIGV_DIKS_SMALL_Z = HIGV_DFB_KEY(UNICODE, 0x7A),
    HIGV_DIKS_CURLY_BRACKET_LEFT = HIGV_DFB_KEY(UNICODE, 0x7B),
    HIGV_DIKS_VERTICAL_BAR = HIGV_DFB_KEY(UNICODE, 0x7C),
    HIGV_DIKS_CURLY_BRACKET_RIGHT = HIGV_DFB_KEY(UNICODE, 0x7D),
    HIGV_DIKS_TILDE = HIGV_DFB_KEY(UNICODE, 0x7E),
    HIGV_DIKS_DELETE = HIGV_DFB_KEY(UNICODE, 0x7F),

    HIGV_DIKS_ENTER = HIGV_DIKS_RETURN,

    /*
    * Unicode private area - DirectFB Special keys
    */
    HIGV_DIKS_CURSOR_LEFT = HIGV_DFB_KEY(SPECIAL, 0x00),
    HIGV_DIKS_CURSOR_RIGHT = HIGV_DFB_KEY(SPECIAL, 0x01),
    HIGV_DIKS_CURSOR_UP = HIGV_DFB_KEY(SPECIAL, 0x02),
    HIGV_DIKS_CURSOR_DOWN = HIGV_DFB_KEY(SPECIAL, 0x03),
    HIGV_DIKS_INSERT = HIGV_DFB_KEY(SPECIAL, 0x04),
    HIGV_DIKS_HOME = HIGV_DFB_KEY(SPECIAL, 0x05),
    HIGV_DIKS_END = HIGV_DFB_KEY(SPECIAL, 0x06),
    HIGV_DIKS_PAGE_UP = HIGV_DFB_KEY(SPECIAL, 0x07),
    HIGV_DIKS_PAGE_DOWN = HIGV_DFB_KEY(SPECIAL, 0x08),
    HIGV_DIKS_PRINT = HIGV_DFB_KEY(SPECIAL, 0x09),
    HIGV_DIKS_PAUSE = HIGV_DFB_KEY(SPECIAL, 0x0A),
    HIGV_DIKS_OK = HIGV_DFB_KEY(SPECIAL, 0x0B),
    HIGV_DIKS_SELECT = HIGV_DFB_KEY(SPECIAL, 0x0C),
    HIGV_DIKS_GOTO = HIGV_DFB_KEY(SPECIAL, 0x0D),
    HIGV_DIKS_CLEAR = HIGV_DFB_KEY(SPECIAL, 0x0E),
    HIGV_DIKS_POWER = HIGV_DFB_KEY(SPECIAL, 0x0F),
    HIGV_DIKS_POWER2 = HIGV_DFB_KEY(SPECIAL, 0x10),
    HIGV_DIKS_OPTION = HIGV_DFB_KEY(SPECIAL, 0x11),
    HIGV_DIKS_MENU = HIGV_DFB_KEY(SPECIAL, 0x12),
    HIGV_DIKS_HELP = HIGV_DFB_KEY(SPECIAL, 0x13),
    HIGV_DIKS_INFO = HIGV_DFB_KEY(SPECIAL, 0x14),
    HIGV_DIKS_TIME = HIGV_DFB_KEY(SPECIAL, 0x15),
    HIGV_DIKS_VENDOR = HIGV_DFB_KEY(SPECIAL, 0x16),

    HIGV_DIKS_ARCHIVE = HIGV_DFB_KEY(SPECIAL, 0x17),
    HIGV_DIKS_PROGRAM = HIGV_DFB_KEY(SPECIAL, 0x18),
    HIGV_DIKS_CHANNEL = HIGV_DFB_KEY(SPECIAL, 0x19),
    HIGV_DIKS_FAVORITES = HIGV_DFB_KEY(SPECIAL, 0x1A),
    HIGV_DIKS_EPG = HIGV_DFB_KEY(SPECIAL, 0x1B),
    HIGV_DIKS_PVR = HIGV_DFB_KEY(SPECIAL, 0x1C),
    HIGV_DIKS_MHP = HIGV_DFB_KEY(SPECIAL, 0x1D),
    HIGV_DIKS_LANGUAGE = HIGV_DFB_KEY(SPECIAL, 0x1E),
    HIGV_DIKS_TITLE = HIGV_DFB_KEY(SPECIAL, 0x1F),
    HIGV_DIKS_SUBTITLE = HIGV_DFB_KEY(SPECIAL, 0x20),
    HIGV_DIKS_ANGLE = HIGV_DFB_KEY(SPECIAL, 0x21),
    HIGV_DIKS_ZOOM = HIGV_DFB_KEY(SPECIAL, 0x22),
    HIGV_DIKS_MODE = HIGV_DFB_KEY(SPECIAL, 0x23),
    HIGV_DIKS_KEYBOARD = HIGV_DFB_KEY(SPECIAL, 0x24),
    HIGV_DIKS_PC = HIGV_DFB_KEY(SPECIAL, 0x25),
    HIGV_DIKS_SCREEN = HIGV_DFB_KEY(SPECIAL, 0x26),

    HIGV_DIKS_TV = HIGV_DFB_KEY(SPECIAL, 0x27),
    HIGV_DIKS_TV2 = HIGV_DFB_KEY(SPECIAL, 0x28),
    HIGV_DIKS_VCR = HIGV_DFB_KEY(SPECIAL, 0x29),
    HIGV_DIKS_VCR2 = HIGV_DFB_KEY(SPECIAL, 0x2A),
    HIGV_DIKS_SAT = HIGV_DFB_KEY(SPECIAL, 0x2B),
    HIGV_DIKS_SAT2 = HIGV_DFB_KEY(SPECIAL, 0x2C),
    HIGV_DIKS_CD = HIGV_DFB_KEY(SPECIAL, 0x2D),
    HIGV_DIKS_TAPE = HIGV_DFB_KEY(SPECIAL, 0x2E),
    HIGV_DIKS_RADIO = HIGV_DFB_KEY(SPECIAL, 0x2F),
    HIGV_DIKS_TUNER = HIGV_DFB_KEY(SPECIAL, 0x30),
    HIGV_DIKS_PLAYER = HIGV_DFB_KEY(SPECIAL, 0x31),
    HIGV_DIKS_TEXT = HIGV_DFB_KEY(SPECIAL, 0x32),
    HIGV_DIKS_DVD = HIGV_DFB_KEY(SPECIAL, 0x33),
    HIGV_DIKS_AUX = HIGV_DFB_KEY(SPECIAL, 0x34),
    HIGV_DIKS_MP3 = HIGV_DFB_KEY(SPECIAL, 0x35),
    HIGV_DIKS_PHONE = HIGV_DFB_KEY(SPECIAL, 0x36),
    HIGV_DIKS_AUDIO = HIGV_DFB_KEY(SPECIAL, 0x37),
    HIGV_DIKS_VIDEO = HIGV_DFB_KEY(SPECIAL, 0x38),

    HIGV_DIKS_INTERNET = HIGV_DFB_KEY(SPECIAL, 0x39),
    HIGV_DIKS_MAIL = HIGV_DFB_KEY(SPECIAL, 0x3A),
    HIGV_DIKS_NEWS = HIGV_DFB_KEY(SPECIAL, 0x3B),
    HIGV_DIKS_DIRECTORY = HIGV_DFB_KEY(SPECIAL, 0x3C),
    HIGV_DIKS_LIST = HIGV_DFB_KEY(SPECIAL, 0x3D),
    HIGV_DIKS_CALCULATOR = HIGV_DFB_KEY(SPECIAL, 0x3E),
    HIGV_DIKS_MEMO = HIGV_DFB_KEY(SPECIAL, 0x3F),
    HIGV_DIKS_CALENDAR = HIGV_DFB_KEY(SPECIAL, 0x40),
    HIGV_DIKS_EDITOR = HIGV_DFB_KEY(SPECIAL, 0x41),

    HIGV_DIKS_RED = HIGV_DFB_KEY(SPECIAL, 0x42),
    HIGV_DIKS_GREEN = HIGV_DFB_KEY(SPECIAL, 0x43),
    HIGV_DIKS_YELLOW = HIGV_DFB_KEY(SPECIAL, 0x44),
    HIGV_DIKS_BLUE = HIGV_DFB_KEY(SPECIAL, 0x45),

    HIGV_DIKS_CHANNEL_UP = HIGV_DFB_KEY(SPECIAL, 0x46),
    HIGV_DIKS_CHANNEL_DOWN = HIGV_DFB_KEY(SPECIAL, 0x47),
    HIGV_DIKS_BACK = HIGV_DFB_KEY(SPECIAL, 0x48),
    HIGV_DIKS_FORWARD = HIGV_DFB_KEY(SPECIAL, 0x49),
    HIGV_DIKS_FIRST = HIGV_DFB_KEY(SPECIAL, 0x4A),
    HIGV_DIKS_LAST = HIGV_DFB_KEY(SPECIAL, 0x4B),
    HIGV_DIKS_VOLUME_UP = HIGV_DFB_KEY(SPECIAL, 0x4C),
    HIGV_DIKS_VOLUME_DOWN = HIGV_DFB_KEY(SPECIAL, 0x4D),
    HIGV_DIKS_MUTE = HIGV_DFB_KEY(SPECIAL, 0x4E),
    HIGV_DIKS_AB = HIGV_DFB_KEY(SPECIAL, 0x4F),
    HIGV_DIKS_PLAYPAUSE = HIGV_DFB_KEY(SPECIAL, 0x50),
    HIGV_DIKS_PLAY = HIGV_DFB_KEY(SPECIAL, 0x51),
    HIGV_DIKS_STOP = HIGV_DFB_KEY(SPECIAL, 0x52),
    HIGV_DIKS_RESTART = HIGV_DFB_KEY(SPECIAL, 0x53),
    HIGV_DIKS_SLOW = HIGV_DFB_KEY(SPECIAL, 0x54),
    HIGV_DIKS_FAST = HIGV_DFB_KEY(SPECIAL, 0x55),
    HIGV_DIKS_RECORD = HIGV_DFB_KEY(SPECIAL, 0x56),
    HIGV_DIKS_EJECT = HIGV_DFB_KEY(SPECIAL, 0x57),
    HIGV_DIKS_SHUFFLE = HIGV_DFB_KEY(SPECIAL, 0x58),
    HIGV_DIKS_REWIND = HIGV_DFB_KEY(SPECIAL, 0x59),
    HIGV_DIKS_FASTFORWARD = HIGV_DFB_KEY(SPECIAL, 0x5A),
    HIGV_DIKS_PREVIOUS = HIGV_DFB_KEY(SPECIAL, 0x5B),
    HIGV_DIKS_NEXT = HIGV_DFB_KEY(SPECIAL, 0x5C),
    HIGV_DIKS_BEGIN = HIGV_DFB_KEY(SPECIAL, 0x5D),

    HIGV_DIKS_DIGITS = HIGV_DFB_KEY(SPECIAL, 0x5E),
    HIGV_DIKS_TEEN = HIGV_DFB_KEY(SPECIAL, 0x5F),
    HIGV_DIKS_TWEN = HIGV_DFB_KEY(SPECIAL, 0x60),

    HIGV_DIKS_BREAK = HIGV_DFB_KEY(SPECIAL, 0x61),
    HIGV_DIKS_EXIT = HIGV_DFB_KEY(SPECIAL, 0x62),
    HIGV_DIKS_SETUP = HIGV_DFB_KEY(SPECIAL, 0x63),

    HIGV_DIKS_CURSOR_LEFT_UP = HIGV_DFB_KEY(SPECIAL, 0x64),
    HIGV_DIKS_CURSOR_LEFT_DOWN = HIGV_DFB_KEY(SPECIAL, 0x65),
    HIGV_DIKS_CURSOR_UP_RIGHT = HIGV_DFB_KEY(SPECIAL, 0x66),
    HIGV_DIKS_CURSOR_DOWN_RIGHT = HIGV_DFB_KEY(SPECIAL, 0x67),

    /*
    * Unicode private area - DirectFB Function keys
    * More function keys are available via HIGV_DFB_FUNCTION_KEY(n).
    */
    HIGV_DIKS_F1 = HIGV_DFB_FUNCTION_KEY(1),
    HIGV_DIKS_F2 = HIGV_DFB_FUNCTION_KEY(2),
    HIGV_DIKS_F3 = HIGV_DFB_FUNCTION_KEY(3),
    HIGV_DIKS_F4 = HIGV_DFB_FUNCTION_KEY(4),
    HIGV_DIKS_F5 = HIGV_DFB_FUNCTION_KEY(5),
    HIGV_DIKS_F6 = HIGV_DFB_FUNCTION_KEY(6),
    HIGV_DIKS_F7 = HIGV_DFB_FUNCTION_KEY(7),
    HIGV_DIKS_F8 = HIGV_DFB_FUNCTION_KEY(8),
    HIGV_DIKS_F9 = HIGV_DFB_FUNCTION_KEY(9),
    HIGV_DIKS_F10 = HIGV_DFB_FUNCTION_KEY(10),
    HIGV_DIKS_F11 = HIGV_DFB_FUNCTION_KEY(11),
    HIGV_DIKS_F12 = HIGV_DFB_FUNCTION_KEY(12),

    /*
    * Unicode private area - DirectFB Modifier keys
    */
    HIGV_DIKS_SHIFT = HIGV_DFB_MODIFIER_KEY(HIGV_DIMKI_SHIFT),
    HIGV_DIKS_CONTROL = HIGV_DFB_MODIFIER_KEY(HIGV_DIMKI_CONTROL),
    HIGV_DIKS_ALT = HIGV_DFB_MODIFIER_KEY(HIGV_DIMKI_ALT),
    HIGV_DIKS_ALTGR = HIGV_DFB_MODIFIER_KEY(HIGV_DIMKI_ALTGR),
    HIGV_DIKS_META = HIGV_DFB_MODIFIER_KEY(HIGV_DIMKI_META),
    HIGV_DIKS_SUPER = HIGV_DFB_MODIFIER_KEY(HIGV_DIMKI_SUPER),
    HIGV_DIKS_HYPER = HIGV_DFB_MODIFIER_KEY(HIGV_DIMKI_HYPER),

    /*
    * Unicode private area - DirectFB Lock keys
    */
    HIGV_DIKS_CAPS_LOCK = HIGV_DFB_KEY(LOCK, 0x00),
    HIGV_DIKS_NUM_LOCK = HIGV_DFB_KEY(LOCK, 0x01),
    HIGV_DIKS_SCROLL_LOCK = HIGV_DFB_KEY(LOCK, 0x02),

    /*
    * Unicode private area - DirectFB Dead keys
    */
    HIGV_DIKS_DEAD_ABOVEDOT = HIGV_DFB_KEY(DEAD, 0x00),
    HIGV_DIKS_DEAD_ABOVERING = HIGV_DFB_KEY(DEAD, 0x01),
    HIGV_DIKS_DEAD_ACUTE = HIGV_DFB_KEY(DEAD, 0x02),
    HIGV_DIKS_DEAD_BREVE = HIGV_DFB_KEY(DEAD, 0x03),
    HIGV_DIKS_DEAD_CARON = HIGV_DFB_KEY(DEAD, 0x04),
    HIGV_DIKS_DEAD_CEDILLA = HIGV_DFB_KEY(DEAD, 0x05),
    HIGV_DIKS_DEAD_CIRCUMFLEX = HIGV_DFB_KEY(DEAD, 0x06),
    HIGV_DIKS_DEAD_DIAERESIS = HIGV_DFB_KEY(DEAD, 0x07),
    HIGV_DIKS_DEAD_DOUBLEACUTE = HIGV_DFB_KEY(DEAD, 0x08),
    HIGV_DIKS_DEAD_GRAVE = HIGV_DFB_KEY(DEAD, 0x09),
    HIGV_DIKS_DEAD_IOTA = HIGV_DFB_KEY(DEAD, 0x0A),
    HIGV_DIKS_DEAD_MACRON = HIGV_DFB_KEY(DEAD, 0x0B),
    HIGV_DIKS_DEAD_OGONEK = HIGV_DFB_KEY(DEAD, 0x0C),
    HIGV_DIKS_DEAD_SEMIVOICED_SOUND = HIGV_DFB_KEY(DEAD, 0x0D),
    HIGV_DIKS_DEAD_TILDE = HIGV_DFB_KEY(DEAD, 0x0E),
    HIGV_DIKS_DEAD_VOICED_SOUND = HIGV_DFB_KEY(DEAD, 0x0F),

    /*
    * Unicode private area - DirectFB Custom keys
    *
    * More custom keys are available via HIGV_DFB_CUSTOM_KEY(n).
    */
    HIGV_DIKS_CUSTOM0 = HIGV_DFB_CUSTOM_KEY(0),
    HIGV_DIKS_CUSTOM1 = HIGV_DFB_CUSTOM_KEY(1),
    HIGV_DIKS_CUSTOM2 = HIGV_DFB_CUSTOM_KEY(2),
    HIGV_DIKS_CUSTOM3 = HIGV_DFB_CUSTOM_KEY(3),
    HIGV_DIKS_CUSTOM4 = HIGV_DFB_CUSTOM_KEY(4),
    HIGV_DIKS_CUSTOM5 = HIGV_DFB_CUSTOM_KEY(5),
    HIGV_DIKS_CUSTOM6 = HIGV_DFB_CUSTOM_KEY(6),
    HIGV_DIKS_CUSTOM7 = HIGV_DFB_CUSTOM_KEY(7),
    HIGV_DIKS_CUSTOM8 = HIGV_DFB_CUSTOM_KEY(8),
    HIGV_DIKS_CUSTOM9 = HIGV_DFB_CUSTOM_KEY(9),
    HIGV_DIKS_CUSTOM10 = HIGV_DFB_CUSTOM_KEY(10),
    HIGV_DIKS_CUSTOM11 = HIGV_DFB_CUSTOM_KEY(11),
    HIGV_DIKS_CUSTOM12 = HIGV_DFB_CUSTOM_KEY(12),
    HIGV_DIKS_CUSTOM13 = HIGV_DFB_CUSTOM_KEY(13),
    HIGV_DIKS_CUSTOM14 = HIGV_DFB_CUSTOM_KEY(14),
    HIGV_DIKS_CUSTOM15 = HIGV_DFB_CUSTOM_KEY(15),
    HIGV_DIKS_CUSTOM16 = HIGV_DFB_CUSTOM_KEY(16),
    HIGV_DIKS_CUSTOM17 = HIGV_DFB_CUSTOM_KEY(17),
    HIGV_DIKS_CUSTOM18 = HIGV_DFB_CUSTOM_KEY(18),
    HIGV_DIKS_CUSTOM19 = HIGV_DFB_CUSTOM_KEY(19),
    HIGV_DIKS_CUSTOM20 = HIGV_DFB_CUSTOM_KEY(20),
    HIGV_DIKS_CUSTOM21 = HIGV_DFB_CUSTOM_KEY(21),
    HIGV_DIKS_CUSTOM22 = HIGV_DFB_CUSTOM_KEY(22),
    HIGV_DIKS_CUSTOM23 = HIGV_DFB_CUSTOM_KEY(23),
    HIGV_DIKS_CUSTOM24 = HIGV_DFB_CUSTOM_KEY(24),
    HIGV_DIKS_CUSTOM25 = HIGV_DFB_CUSTOM_KEY(25),
    HIGV_DIKS_CUSTOM26 = HIGV_DFB_CUSTOM_KEY(26),
    HIGV_DIKS_CUSTOM27 = HIGV_DFB_CUSTOM_KEY(27),
    HIGV_DIKS_CUSTOM28 = HIGV_DFB_CUSTOM_KEY(28),
    HIGV_DIKS_CUSTOM29 = HIGV_DFB_CUSTOM_KEY(29),
    HIGV_DIKS_CUSTOM30 = HIGV_DFB_CUSTOM_KEY(30),
    HIGV_DIKS_CUSTOM31 = HIGV_DFB_CUSTOM_KEY(31),
    HIGV_DIKS_CUSTOM32 = HIGV_DFB_CUSTOM_KEY(32),
    HIGV_DIKS_CUSTOM33 = HIGV_DFB_CUSTOM_KEY(33),
    HIGV_DIKS_CUSTOM34 = HIGV_DFB_CUSTOM_KEY(34),
    HIGV_DIKS_CUSTOM35 = HIGV_DFB_CUSTOM_KEY(35),
    HIGV_DIKS_CUSTOM36 = HIGV_DFB_CUSTOM_KEY(36),
    HIGV_DIKS_CUSTOM37 = HIGV_DFB_CUSTOM_KEY(37),
    HIGV_DIKS_CUSTOM38 = HIGV_DFB_CUSTOM_KEY(38),
    HIGV_DIKS_CUSTOM39 = HIGV_DFB_CUSTOM_KEY(39),
    HIGV_DIKS_CUSTOM40 = HIGV_DFB_CUSTOM_KEY(40),
    HIGV_DIKS_CUSTOM41 = HIGV_DFB_CUSTOM_KEY(41),
    HIGV_DIKS_CUSTOM42 = HIGV_DFB_CUSTOM_KEY(42),
    HIGV_DIKS_CUSTOM43 = HIGV_DFB_CUSTOM_KEY(43),
    HIGV_DIKS_CUSTOM44 = HIGV_DFB_CUSTOM_KEY(44),
    HIGV_DIKS_CUSTOM45 = HIGV_DFB_CUSTOM_KEY(45),
    HIGV_DIKS_CUSTOM46 = HIGV_DFB_CUSTOM_KEY(46),
    HIGV_DIKS_CUSTOM47 = HIGV_DFB_CUSTOM_KEY(47),
    HIGV_DIKS_CUSTOM48 = HIGV_DFB_CUSTOM_KEY(48),
    HIGV_DIKS_CUSTOM49 = HIGV_DFB_CUSTOM_KEY(49),
    HIGV_DIKS_CUSTOM50 = HIGV_DFB_CUSTOM_KEY(50),
    HIGV_DIKS_CUSTOM51 = HIGV_DFB_CUSTOM_KEY(51),
    HIGV_DIKS_CUSTOM52 = HIGV_DFB_CUSTOM_KEY(52),
    HIGV_DIKS_CUSTOM53 = HIGV_DFB_CUSTOM_KEY(53),
    HIGV_DIKS_CUSTOM54 = HIGV_DFB_CUSTOM_KEY(54),
    HIGV_DIKS_CUSTOM55 = HIGV_DFB_CUSTOM_KEY(55),
    HIGV_DIKS_CUSTOM56 = HIGV_DFB_CUSTOM_KEY(56),
    HIGV_DIKS_CUSTOM57 = HIGV_DFB_CUSTOM_KEY(57),
    HIGV_DIKS_CUSTOM58 = HIGV_DFB_CUSTOM_KEY(58),
    HIGV_DIKS_CUSTOM59 = HIGV_DFB_CUSTOM_KEY(59),
    HIGV_DIKS_CUSTOM60 = HIGV_DFB_CUSTOM_KEY(60),
    HIGV_DIKS_CUSTOM61 = HIGV_DFB_CUSTOM_KEY(61),
    HIGV_DIKS_CUSTOM62 = HIGV_DFB_CUSTOM_KEY(62),
    HIGV_DIKS_CUSTOM63 = HIGV_DFB_CUSTOM_KEY(63),
    HIGV_DIKS_CUSTOM64 = HIGV_DFB_CUSTOM_KEY(64),
    HIGV_DIKS_CUSTOM65 = HIGV_DFB_CUSTOM_KEY(65),
    HIGV_DIKS_CUSTOM66 = HIGV_DFB_CUSTOM_KEY(66),
    HIGV_DIKS_CUSTOM67 = HIGV_DFB_CUSTOM_KEY(67),
    HIGV_DIKS_CUSTOM68 = HIGV_DFB_CUSTOM_KEY(68),
    HIGV_DIKS_CUSTOM69 = HIGV_DFB_CUSTOM_KEY(69),
    HIGV_DIKS_CUSTOM70 = HIGV_DFB_CUSTOM_KEY(70),
    HIGV_DIKS_CUSTOM71 = HIGV_DFB_CUSTOM_KEY(71),
    HIGV_DIKS_CUSTOM72 = HIGV_DFB_CUSTOM_KEY(72),
    HIGV_DIKS_CUSTOM73 = HIGV_DFB_CUSTOM_KEY(73),
    HIGV_DIKS_CUSTOM74 = HIGV_DFB_CUSTOM_KEY(74),
    HIGV_DIKS_CUSTOM75 = HIGV_DFB_CUSTOM_KEY(75),
    HIGV_DIKS_CUSTOM76 = HIGV_DFB_CUSTOM_KEY(76),
    HIGV_DIKS_CUSTOM77 = HIGV_DFB_CUSTOM_KEY(77),
    HIGV_DIKS_CUSTOM78 = HIGV_DFB_CUSTOM_KEY(78),
    HIGV_DIKS_CUSTOM79 = HIGV_DFB_CUSTOM_KEY(79),
    HIGV_DIKS_CUSTOM80 = HIGV_DFB_CUSTOM_KEY(80),
    HIGV_DIKS_CUSTOM81 = HIGV_DFB_CUSTOM_KEY(81),
    HIGV_DIKS_CUSTOM82 = HIGV_DFB_CUSTOM_KEY(82),
    HIGV_DIKS_CUSTOM83 = HIGV_DFB_CUSTOM_KEY(83),
    HIGV_DIKS_CUSTOM84 = HIGV_DFB_CUSTOM_KEY(84),
    HIGV_DIKS_CUSTOM85 = HIGV_DFB_CUSTOM_KEY(85),
    HIGV_DIKS_CUSTOM86 = HIGV_DFB_CUSTOM_KEY(86),
    HIGV_DIKS_CUSTOM87 = HIGV_DFB_CUSTOM_KEY(87),
    HIGV_DIKS_CUSTOM88 = HIGV_DFB_CUSTOM_KEY(88),
    HIGV_DIKS_CUSTOM89 = HIGV_DFB_CUSTOM_KEY(89),
    HIGV_DIKS_CUSTOM90 = HIGV_DFB_CUSTOM_KEY(90),
    HIGV_DIKS_CUSTOM91 = HIGV_DFB_CUSTOM_KEY(91),
    HIGV_DIKS_CUSTOM92 = HIGV_DFB_CUSTOM_KEY(92),
    HIGV_DIKS_CUSTOM93 = HIGV_DFB_CUSTOM_KEY(93),
    HIGV_DIKS_CUSTOM94 = HIGV_DFB_CUSTOM_KEY(94),
    HIGV_DIKS_CUSTOM95 = HIGV_DFB_CUSTOM_KEY(95),
    HIGV_DIKS_CUSTOM96 = HIGV_DFB_CUSTOM_KEY(96),
    HIGV_DIKS_CUSTOM97 = HIGV_DFB_CUSTOM_KEY(97),
    HIGV_DIKS_CUSTOM98 = HIGV_DFB_CUSTOM_KEY(98),
    HIGV_DIKS_CUSTOM99 = HIGV_DFB_CUSTOM_KEY(99)
} HIGV_DFBInputDeviceKeySymbol;

/*
 * Flags specifying the key locks that are currently active.
 */
typedef enum {
    HIGV_DILS_SCROLL = 0x00000001, /* scroll-lock active? */
    HIGV_DILS_NUM = 0x00000002,    /* num-lock active? */
    HIGV_DILS_CAPS = 0x00000004    /* caps-lock active? */
} HIGV_DFBInputDeviceLockState;

/*
 * Groups and levels as an index to the symbol array.
 */
typedef enum {
    HIGV_DIKSI_BASE = 0x00,       /* base group, base level (no modifier pressed) */
    HIGV_DIKSI_BASE_SHIFT = 0x01, /* base group, shifted level (with Shift pressed) */
    HIGV_DIKSI_ALT = 0x02,  /* alternative group, base level (with AltGr pressed) */
    HIGV_DIKSI_ALT_SHIFT = 0x03,  /* alternative group, shifted level (with AltGr and Shift pressed) */
    HIGV_DIKSI_LAST = HIGV_DIKSI_ALT_SHIFT
} HIGV_DFBInputDeviceKeymapSymbolIndex;

/*
 * One entry in the keymap of an input device.
 */
typedef struct {
    HI_U32 code;                                               /* hardware key code */
    HIGV_DFBInputDeviceLockState locks;                        /* locks activating shifted level */
    HIGV_DFBInputDeviceKeyIdentifier identifier;               /* basic mapping */
    HIGV_DFBInputDeviceKeySymbol symbols[HIGV_DIKSI_LAST + 1];  // advanced key mapping
} HIGV_DFBInputDeviceKeymapEntry;

/* Input devece structure */
/* CNcomment:�����豸�ṹ */
typedef struct hiHIGV_INPUT_S {
    HI_S32 (*InitInputDevice)(HI_VOID);
    HI_S32 (*DeinitInputDevice)(HI_VOID);
    /* timeout is us */
    HI_S32 (*GetKeyEvent)(HIGV_INPUTEVENT_S *pInputEvent, HI_U32 TimeOut);
    /* timeout is us */
    HI_S32 (*GetKeyBoardEvent)(HIGV_INPUTEVENT_S *pInputEvent, HI_U32 TimeOut);
    /* timeout is us */
    HI_S32 (*GetMouseEvent)(HIGV_INPUTEVENT_S *pInputEvent, HI_U32 TimeOut);
    /* timeout is us */
    HI_S32 (*GetTouchEvent)(HIGV_TOUCH_GESTURE_EVENT_S *pInputEvent, HI_U32 TimeOut);
} HIGV_INPUT_S;

/*
* brief Send input event to higv.CNcomment:���������¼������û��ʵ��GetInputEvent����ʹ�ô˽ӿ����������¼�
* param[in] inputEvent Input event information.CNcomment:�����¼���Ϣ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_MSGM_VTOPMSGSEND Failure when send message.CNcomment:������Ϣģ�鷢����Ϣʧ��
*/
HI_S32 HI_GV_SendInputEvent(HIGV_INPUTEVENT_S *inputEvent);

#ifdef __cplusplus
}
#endif
#endif /* HIGV_INPUT_H */