/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020 All rights reserved.
 * Description: HIGV resouce manger API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_RESM_H
#define HI_GV_RESM_H

/* add include here */
#include "hi_type.h"
#include "hi_go.h"
#include "hi_gv_conf.h"

#ifdef __cplusplus
extern "C" {
#endif

#define UNLIMITED_REPEATE_COUNT (-1)
/* Invalid resource ID ; CNcomment: ��Ч����ԴID */
#define INVALID_RESID 0
/* The max length of resource file name */
/* CNcomment: ��Դ�ļ�������󳤶� */
#define HIGV_RESM_MAX_FILENAME_LEN 256

/* The max alpha value */
/* CNcomment: ����Alphaֵ */
#define HIGV_RESM_MAX_ALPHA 255

/* Resouce ID */
/* CNcomment: ��ԴID */
typedef HI_PARAM HI_RESID;

/* Resouce type */
/* CNcomment:  ��Դ��� */
typedef enum hiHIGV_RESTYPE_E {
    HIGV_RESTYPE_IMG,
    /* Picture resouce */
    /* CNcomment:  ͼƬ��Դ */
    HIGV_RESTYPE_FONT,
    /* Font resource */
    /* CNcomment:  ������Դ */
    HIGV_RESTYPE_BUTT
} HIGV_RESTYPE_E;

/* Skin type */
/* CNcomment:  Ƥ������ */
typedef enum hiHIGV_STYLE_TYPE_E {
    HIGV_STYLETYPE_COLOR = 0,
    /* Color type CNcomment:  ��ɫ */
    HIGV_STYLETYPE_PIC /* Picture type CNcomment:  ͼƬ */
} HIGV_STYLE_TYPE_E;

/*  Style union */
/*  CNcomment: style���� */
typedef union hiHIGV_STYLE_MEMBER_U {
    HI_COLOR Color; /* Color value  ; CNcomment:  ��ɫֵ */
    HI_RESID ResId; /* Resouce ID ; CNcomment:  ��ԴID */
} HIGV_STYLE_MEMBER_U;

/*  The style structure ; CNcomment: style�ṹ */
typedef struct hiHIGV_STYLE_S {
    HIGV_STYLE_TYPE_E StyleType; /* Style type ; CNcomment:  Style���� */
    HIGV_STYLE_MEMBER_U
    Top;     /* Top side (color or picture resource)  ; CNcomment:  �ϱ�Ե��ɫֵ����ͼƬ��ԴID */
    HIGV_STYLE_MEMBER_U Bottom;
    /* <Bottom side (color or picture resource) */
    /* <CNcomment:  �±�Ե��ɫֵ����ͼƬ��ԴID */
    HIGV_STYLE_MEMBER_U Left; /* Left side (color or picture resource ; CNcomment:  ���Ե��ɫֵ����ͼƬ��ԴID */
    HIGV_STYLE_MEMBER_U Right;    /* Right side (color or picture resource) */
                                 /* CNcomment:  �ұ�Ե��ɫֵ����ͼƬ��ԴID */
    HIGV_STYLE_MEMBER_U LeftTop;    /* Top left co (color or picture resource) */
                                     /* CNcomment:  ���Ͻ���ɫֵ����ͼƬ��ԴID */
    HIGV_STYLE_MEMBER_U LeftBottom;    /* Top side (color or picture resource) */
                                         /* CNcomment:  ���½���ɫֵ����ͼƬ��ԴID */
    HIGV_STYLE_MEMBER_U RightTop;    /* Right top side (color or picture resource) */
                                    /* CNcomment:  ���Ͻ���ɫֵ����ͼƬ��ԴID */
    HIGV_STYLE_MEMBER_U RightBottom;    /* Right bottom side (color or picture resource) */
                                         /* CNcomment:  ���½���ɫֵ����ͼƬ��ԴID */
    HIGV_STYLE_MEMBER_U BackGround;    /* Background (color or picture resource) */
                                          /* CNcomment:  ������ɫֵ��ͼƬ��ԴID */
    HI_COLOR FontColor; /* Font color CNcomment:  ������ɫֵ  */
    HI_U32 bNoDrawBg;   /* Is not draw background CNcomment:  �����Ƿ񻭱�����ɫֵ */
    HI_U32 LineWidth;   /* Line width CNcomment:  ���������ɫ��� */
    HI_U32 isRoundRect; /*  �����Ƿ����Բ�Ǿ��� */
    HI_U32 roundRadius; /*  ����Բ�ǰ뾶 */
} HIGV_STYLE_S;

typedef struct hiHIGV_FONT_S {
    HI_RESID SbFontID;
    HI_RESID MbFontID;
    HI_U32 Size;
    HI_BOOL bBold;
    HI_BOOL bItalic;
    HI_U32 lineSpace;
} HIGV_FONT_S;

typedef struct hiHIGV_DEC_SUFINFO_S {
    HIGO_PF_E PixFormat;    /* CNcomment: ������������ظ�ʽ��Ĭ��ΪHIGO_PF_8888 */
    HIGO_MEMTYPE_E MemType; /* CNcomment: ��������Ĵ洢���Ĭ��ΪMMZ */
    HI_BOOL IsPubPalette;   /* CNcomment: ����ͼƬ�Ƿ�ʹ�ù�����ɫ��,ֻ�������ʽ��Ч */
} HIGV_DEC_SUFINFO_S;

typedef struct {
    HI_CHAR *pTopName;         /* Resouce file name of top side CNcomment:  ��������Դ�ļ��� */
    HI_CHAR *pBottomName;      /* Resouce file name of bottom side <CNcomment:  �ײ�����Դ�ļ��� */
    HI_CHAR *pLeftName;        /* Resouce file name of left side CNcomment:  ��ߵ���Դ�ļ��� */
    HI_CHAR *pRightName;       /* Resouce file name of right side CNcomment:  �ұߵ���Դ�ļ��� */
    HI_CHAR *pLeftTopName;     /* Resouce file name of top and left side CNcomment:  ���ϵ���Դ�ļ��� */
    HI_CHAR *pLeftBottomName;  /* Resouce file name of bottom and left side CNcomment:  ���µ���Դ�ļ��� */
    HI_CHAR *pRightTopName;    /* Resouce file name of right and up side CNcomment:  ���ϵ���Դ�ļ��� */
    HI_CHAR *pRightBottomName; /* Resouce file name of right and bottom  side CNcomment:  ���µ���Դ�ļ��� */
    HI_CHAR *pBackGroundName;  /* Resouce file name of background CNcomment:  ��������Դ�ļ��� */
} HIGV_STYLEFILENAME_S;

/*  The Anim structure */
/*  CNcomment: Anim�ṹ */
/*  Anim��ID��Ӧ��ϵ�� */
/*  Anim type */ /* *CNcomment:  �������� */
typedef enum hiHIGV_ANIM_TYPE_E {
    /* Translate type */
    /* CNcomment: ƽ�� */
    HIGV_ANIMTYPE_TRANSLATE = 0,
    /* Alpha type */
    /* CNcomment:  Alpha */
    HIGV_ANIMTYPE_ALPHA,
    /* Roll type */
    /* CNcomment:  ���� */
    HIGV_ANIMTYPE_ROLL,
    /* Any type */
    /* CNcomment:  ���� */
    HIGV_ANIMTYPE_ANY,
    HIGV_ANIMTYPE_INVALIDATE
} HIGV_ANIM_TYPE_E;

/* Animation repeat type */
/* CNcomment:  �����ظ����� */
typedef enum hiHIGV_ANIM_REPEAT_TYPE_E {
    /* Repeate type restart */
    /* CNcomment: ��ͷ��ʼ */
    HIGV_REPEATE_TYPE_RESTART = 0,
    /* Repeate type reverse */
    /* <CNcomment: �ӽ�����λ�ü��� */
    HIGV_REPEATE_TYPE_REVERSE
} HIGV_ANIM_REPEAT_TYPE_E;

/* Animation roll type */
/* CNcomment:  Animation roll type�������� */
typedef enum {
    HIGV_ANIM_ROLL_UP = 0, /* Up */
    HIGV_ANIM_ROLL_DOWN,   /* Down */
    HIGV_ANIM_ROLL_LEFT,   /* Letf */
    HIGV_ANIM_ROLL_RIGHT   /* Right */
} HIGV_ANIM_ROLL_DIRECTION_E;

/* Translate info */
/* CNcomment:  Translate info ƽ����Ϣ */
typedef struct hiHIGV_ANIM_TRANSLATE_INFO_S {
    HI_S32 FromX; /* ��ʼ����X */
    HI_S32 FromY; /* ��ʼ����Y */
    HI_S32 ToX;   /* ��������X */
    HI_S32 ToY;   /* ��������Y */
} HIGV_ANIM_TRANSLATE_INFO_S;

/* Alpha info */
/* CNcomment:  Alpha info Alpha��Ϣ */
typedef struct hiHIGV_ANIM_ALPHA_INFO_S {
    HI_U32 FromApha; /*  ��ʼAlpha */
    HI_U32 ToAlpha;  /*  ����Alpha */
} HIGV_ANIM_ALPHA_INFO_S;

/* * Any info */
/* * CNcomment:  Any info ͨ����Ϣ */
typedef struct hiHIGV_ANIM_ANY_INFO_S {
    HI_S32 FromValue; /*  ��ʼ Value */
    HI_S32 ToValue;   /*  ���� Value */
} HIGV_ANIM_ANY_INFO_S;

/* Roll info */
/* CNcomment:  Roll info ������Ϣ */
typedef struct hiHIGV_ANIM_ROLL_INFO_S {
    HIGV_ANIM_ROLL_DIRECTION_E DirectionType; /* �������� */
    HI_S32 FromLoc;                           /* ��ʼλ�� */
    HI_S32 ToLoc;                             /* ����λ�� */
} HIGV_ANIM_ROLL_INFO_S;

/* Animation info */
/* CNcomment:  Animation info ������Ϣ */
typedef struct hiHIGV_ANIM_INFO_S {
    HI_U32 AnimHandle;                  /* Anim ID */
    HI_U32 DurationMs;                  /* ����ʱ�� */
    HI_S32 RepeatCount;                 /* ѭ������ */
    HIGV_ANIM_REPEAT_TYPE_E RepeatMode; /* ѭ��ģʽ */
    HI_U32 DelayStart;                  /* �ӳ�ִ��ʱ�� */
    HIGV_ANIM_TYPE_E AnimType;          /* �������� */
    union {
        HIGV_ANIM_TRANSLATE_INFO_S Translate;
        HIGV_ANIM_ALPHA_INFO_S Alpha;
        HIGV_ANIM_ROLL_INFO_S Roll;
        HIGV_ANIM_ANY_INFO_S Any;
    } AnimParam;
} HIGV_ANIM_INFO_S;

 /*
* brief Create resource ID. CNcomment: ������ԴID
* attention \n
* 1. The picture use ID in the system.
* 2. This function is effected by resouce envirnment var
* CNcomment:
* 1. ͼƬ��ϵͳ����ID��ʶ
* 2. �ýӿ��ܻ�������Ӱ�죬�����������Դ·��ǰ׺��������������Զ�����Դ·��ǰ�����Ӹ�ǰ׺
*     ������Դ���·��ǰ׺( HIGV_RES_FONT_PATH),
*     ͼƬ��Դ���·��ǰ׺(HIGV_RES_IMAGE_PATH)
* param[in]  fileName    Picture file name. CNcomment: ͼƬ�ļ���
* param[in]  resType Resouce type. CNcomment: ��Դ����
* param[out] resID   Resource ID. CNcomment: ��ԴID
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle. CNcomment: �����Ч
* retval ::HI_ERR_COMM_NORES No memory. CNcomment: ϵͳ��û���ڴ�
* see ::HI_GV_Res_DestroyID
*/
HI_S32 HI_GV_Res_CreateID(const HI_CHAR *fileName, HIGV_RESTYPE_E resType, HI_RESID *resID);

/*
* brief Create resource ID no res prefix path. CNcomment: ������ԴID����ȡ��Դǰ׺��������
* attention:
* The picture use ID in the system.
* CNcomment: ͼƬ��ϵͳ����ID��ʶ
* param[in]  fileName    Picture file name. CNcomment: ͼƬ�ļ���
* param[in]  resType Resouce type. CNcomment: ��Դ����
* param[out] resID   Resource ID. CNcomment: ��ԴID
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle. CNcomment: �����Ч
* retval ::HI_ERR_COMM_NORES No memory. CNcomment: ϵͳ��û���ڴ�
* see ::HI_GV_Res_DestroyID
*/
HI_S32 HI_GV_Res_CreateID_NoPrefixPath(const HI_CHAR *fileName, HIGV_RESTYPE_E resType, HI_RESID *resID);

/*
* brief Disable application use resource enviroment variables. CNcomment: ǿ��Ӧ�ò�ʹ����Դ·���Ļ�������
* If you set the reource enviroment variable, and don't want usnet the env variable, you can call this fuction disable.
* [HIGV_RES_FONT_PATH, HIGV_RES_IMAGE_PATH] \attention \n N/A.CNcomment:�� \param[in]  disable  boolean parameter.
* CNcomment: ʹ�ܲ���ֵ
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* see :: HI_GV_Res_CreateID_NoPrefixPath
*/
HI_S32 HI_GV_Res_DisablePrefixPath(HI_BOOL disable);

/*
* brief Destroy resource id. CNcomment: ������Դ���
* param[in] resID Rouce ID. CNcomment: ��ԴID
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_RES_UNKNOWRES Coun't find the resouce id .CNcomment: ��ɾ������ԴID��ϵͳ���Ҳ���
* retval ::HI_ERR_RES_USED The resouce is used.CNcomment: ��Դ����ʹ��
* see :: HI_GV_Res_CreateID
*/
HI_S32 HI_GV_Res_DestroyID(HI_RESID resID);

/*
* brief Generate style. CNcomment: ����Style
* param[in]  style   Generate the infomation of the skin. CNcomment: Ƥ����������ԴID��Ϣ
* param[out] residStyle  Skin handle.CNcomment: Ƥ�����
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle.CNcomment: �����Ч
* retval ::HI_ERR_COMM_NORES No memory.CNcomment: ϵͳ��û���ڴ�
* retval ::HI_ERR_COMM_INVAL Invalid paramater.CNcomment: ��Ч����
\* see :: HI_GV_Res_DestroyStyle
*/
HI_S32 HI_GV_Res_CreateStyle(const HIGV_STYLE_S *style, HI_RESID *residStyle);

/*
* brief Generate Style by the resource ID. CNcomment: ����ָ����RESID����Style
* param[in] style Style pointer.CNcomment: ��������
* param[in] styleHandle  Style handle.CNcomment: ���
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_COMM_NORES No memory.CNcomment: ϵͳ��û���ڴ�
* retval ::HI_ERR_COMM_INVAL Invalid parater.CNcomment: ��Ч����
*/
HI_S32 HI_GV_Res_CreateStyleByHandle(const HIGV_STYLE_S *style, HIGV_HANDLE styleHandle);

/*
* brief Destroy style. CNcomment: ����Style
* param[in] styleHandle  Style handle.CNcomment: Style���
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_RES_UNKNOWRES Coun't find the resouce id.CNcomment: ��ɾ������ԴID��ϵͳ���Ҳ���
* see ::HI_GV_Res_CreateStyle
*/
HI_S32 HI_GV_Res_DestroyStyle(HIGV_HANDLE styleHandle);

/*
* brief Set the resource to persistent memory. CNcomment: ������Դ��פ�ڴ�
* param[in] resID Resource handle.CNcomment: ��Դ���
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_RES_UNKNOWRES Coun't find the resouce id.CNcomment: ��ԴID��ϵͳ���Ҳ���
*/
HI_S32 HI_GV_Res_SetResident(HI_RESID resID);

/*
* brief Create font. CNcomment: ��������
* param[in]  fontInfo the point of Font information. CNcomment: ���崴����Ϣ
* param[out] fontHandle     Font handle. CNcomment: ������
* retval ::HI_SUCCESS Success. CNcomment: �ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle.CNcomment: �����Ч
* retval ::HI_ERR_COMM_NORES No memory. CNcomment: ϵͳ��û���ڴ�
* retval ::HI_ERR_RES_UNKNOWRES Coun't find the resouce id.CNcomment: ��ԴID��ϵͳ���Ҳ���
* see ::HI_GV_Font_Destroy
*/
HI_S32 HI_GV_Font_Create(const HIGV_FONT_S *fontInfo, HIGV_HANDLE *fontHandle);

/*
* brief Create font by the handle. CNcomment: ����ָ���ľ���������壬ΪXML2Bin�ṩ
* param[in] fontInfo CNcomment:  ���崴����Ϣ
* param[in] fontHandle     CNcomment: ������
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle.CNcomment: �����Ч
* retval ::HI_ERR_COMM_NORES No memory. CNcomment: ϵͳ��û���ڴ�
* retval ::HI_ERR_RES_UNKNOWRES CNcomment: ��ԴID��ϵͳ���Ҳ���
*/
HI_S32 HI_GV_Font_CreateByHandle(const HIGV_FONT_S *fontInfo, HIGV_HANDLE fontHandle);

/*
* brief Destroy font.CNcomment: ɾ������
* param[in] fontHandle  Font hanlde.CNcomment: ������
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_RES_UNKNOWRES Coun't find the font.CNcomment: ϵͳ��û���ҵ���Ӧ������
* see ::HI_GV_Font_Create
*/
HI_S32 HI_GV_Font_Destroy(HIGV_HANDLE fontHandle);

/*
* brief Set system default font. CNcomment: ����ϵͳĬ������
* param[in] fontHandle Font handle.CNcomment: ������Դ���
* retval ::HI_SUCCESS CNcomment: �ɹ�
* see ::HI_GV_Font_GetSystemDefault
*/
HI_S32 HI_GV_Font_SetSystemDefault(HIGV_HANDLE fontHandle);

/*
* brief Get system default font.CNcomment: ��ȡϵͳȱʡ����
* param[out] fontHandle Font handle.CNcomment: ������
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_COMM_INVAL Invalid handle.CNcomment: ��Ч����
* see ::HI_GV_Font_SetSystemDefault
*/
HI_S32 HI_GV_Font_GetSystemDefault(HIGV_HANDLE *fontHandle);

/*
* brief Get String width and height.CNcomment: ��ȡ�ַ����Ŀ��
* param[in] fontHandle Font handle.CNcomment: ������Դ���
* param[in] strHandle String handle.CNcomment: �ַ������
* param[out] width String width.CNcomment: �ַ������
* param[out] height String height.CNcomment: �ַ����߶�
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_COMM_INVAL Invalid handle.CNcomment: ��Ч����
*/
HI_S32 HI_GV_Font_GetTextExtent(HIGV_HANDLE fontHandle, HI_RESID strHandle, HI_S32 *width, HI_S32 *height);

/*
* brief Destroy all style. CNcomment: �ͷ�����Style
* attention \n
* Release the resource of style and don't rlease the picture resouce.
* CNcomment: �ͷ�Style������Դ�������ͷ�Style���õ�ͼƬ��Դ
* param N/A.CNcomment:��
* retval ::HI_SUCCESS      CNcomment: ɾ���ɹ�
* retval ::HI_ERR_RES_USED CNcomment: ��Դ����ʹ��
*/
HI_S32 HI_GV_Resm_DestroyAllStyle(HI_VOID);

/*
* brief Destroy all resource. CNcomment: �ͷ�����ͼƬ��������Դ
* param N/A.CNcomment:��
* retval ::HI_SUCCESS   Success.CNcomment: ɾ���ɹ�
*/
HI_S32 HI_GV_Resm_DestroyAllRes(HI_VOID);

/*
* brief Force to releaee all resouce.CNcomment: ǿ���ͷ�����ͼƬ��������Դ
* param N/A.CNcomment:��
* retval ::HI_SUCCESS   Success.CNcomment: ɾ���ɹ�
*/
HI_S32 HI_GV_Resm_ForceUnloadAllRes(HI_VOID);

/*
* brief Set the information of decode surface. CNcomment: ���ý���������Ϣ
* param[in] DecSufinfo The infomation of decode surface.CNcomment: ���������Ϣ
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_COMM_INVAL Invalid paramater.CNcomment: ��Ч����
*/
HI_S32 HI_GV_Resm_SetDecSurfInfo(HIGV_DEC_SUFINFO_S *decSufinfo);

/*
* brief Get the information of decode surface. CNcomment: ��ȡ����������Ϣ
* param[out] decSufinfo The surface infomation of decode surface.CNcomment: ���������Ϣ
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_COMM_INVAL Invalid paramater.CNcomment: ��Ч����
*/
HI_S32 HI_GV_Resm_GetDecSurfInfo(HIGV_DEC_SUFINFO_S *decSufinfo);

/*
* brief Get the information of the surface which is for picture reource ID.CNcomment: ��ȡͼƬ��ԴID��Ӧ��surface��Ϣ
* param[in]  resID Resouce ID.CNcomment: ��ԴID
* param[out] resHandle  the handle of resouce surface. CNcomment: ��Դsurface���
* retval ::HI_SUCCESS  Success.CNcomment: �ɹ�
* retval ::HI_ERR_RES_UNKNOWRES Coun't find the resouce id. CNcomment: ��ԴID������
* retval ::HI_ERR_RES_LOAD   Load failed.CNcomment: ����ʧ�ܣ����������崴����ͼƬ����ʧ��
*/
HI_S32 HI_GV_Res_GetResInfo(HI_RESID resID, HIGV_HANDLE *resHandle);

/*
* brief Free the information of the surface which is for picture reource ID.CNcomment: �ͷ�ͼƬ��ԴID��Ӧ��surface��Ϣ
* param[in]  resID Resouce ID.CNcomment: ��ԴID
* retval ::HI_SUCCESS  Success.CNcomment: �ɹ�
* retval ::HI_ERR_RES_UNKNOWRES Coun't find the resouce id. CNcomment: ��ԴID������
* retval ::HI_ERR_RES_NOLOAD   No Load.CNcomment: ��Դδ����
*/
HI_S32 HI_GV_Res_ReleaseResInfo(HI_RESID resID);

/*
* brief Create font set.CNcomment: �������弯
* attention
* CNcomment: ���弯�Ǿ�����ͬ�����ڲ�ͬ�����¿��滻�����弯��
* param[out] fontHandle   CNcomment:  ������
* retval ::HI_SUCCESS Success.CNcomment:  �ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle.CNcomment: �����Ч
* retval ::HI_ERR_RES_UNKNOWRES Coun't find the font. CNcomment: ��ԴID��ϵͳ���Ҳ���
* see::HI_GV_FontSet_Destroy
*/
HI_S32 HI_GV_FontSet_Create(HIGV_HANDLE *fontSet);

/*
* brief Add font to font set. CNcomment: ������嵽���弯��
* attention
* supportLan CNcomment: Ϊ�գ���ʾ֧�������������壻���岻�����ظ����
* param[in] fontHandle Font handle.CNcomment:  ������
* param[in]  supportLan The language which font support. CNcomment:  ����֧�ֵ����ԣ���������ʹ�÷ֺŸ�������"cn;en;" ��
* ��Դ?�뽨��ʹ��ISO-639 ��׼ \param[in]  fontSetHandle  The handle of font set.CNcomment: ���弯���
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle.CNcomment: �����Ч
* retval ::HI_ERR_COMM_NORES No memory.CNcomment: ϵͳ��û���ڴ�
* retval ::HI_ERR_RES_UNKNOWRES Coun't find the reouce id. CNcomment: ��ԴID��ϵͳ���Ҳ���
* see ::HI_GV_FontSet_Destroy
*/
HI_S32 HI_GV_FontSet_AddFont(HIGV_HANDLE fontHandle, const HI_CHAR *supportLan, HIGV_HANDLE fontSetHandle);

/*
* brief  Query the font style which is the same as fontHandle from font set.CNcomment: ��ѯ���弯�з����hFont��ͬ������
* param[in]  lan CNcomment:  ����֧�ֵ����ԣ����Դ��뽨��ʹ��ISO-639 ��׼
* param[in] fontHandle     Font handle. CNcomment: ������
* param[in]  supprotFontHandle  CNcomment: ���弯�з����hFont��ͬ������
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle.CNcomment: �����Ч
* retval ::HI_ERR_COMM_NORES No memory. CNcomment: ϵͳ��û���ڴ�
* retval ::HI_ERR_RES_UNKNOWRES Coun't find the resouce id. CNcomment: ��ԴID��ϵͳ���Ҳ���
* see ::HI_GV_FontSet_Destroy
*/
HI_S32 HI_GV_FontSet_Query(HI_CHAR *lan, HIGV_HANDLE fontHandle, HIGV_HANDLE *supprotFontHandle);

/*
* brief Destroy font set.CNcomment: ɾ�����弯
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* see :: HI_GV_Font_Create
*/
HI_S32 HI_GV_FontSet_Destroy(HI_VOID);

/*
* brief Get style file name.CNcomment: ��ȡStyle�ļ���
* param[in]  styleHandle     Style handle.CNcomment:  style���
* param[out] styleFileNameInfo  the file names of resouce.CNcomment: ��ȡ���style����Դ�ļ���
* retval ::HI_SUCCESS
*/
HI_S32 HI_GV_Res_GetStyleFileName(HI_RESID styleHandle, HIGV_STYLEFILENAME_S *styleFileNameInfo);

/*
* brief print resource information.CNcomment: ��ӡ��Դ��Ϣ
* param N/A.CNcomment:��
* retval ::HI_SUCCESS
*/
HI_S32 HI_GV_Res_PrintCurLoadResInfo(HI_VOID);

/*
* brief Create animtion information. CNcomment: ����������Ϣ
* param[in]  animInfo the point of animtion information. CNcomment: ����������Ϣ
* param[out] animHandle  animtion information handle.CNcomment: ������Ϣ���
* retval ::HI_SUCCESS Success. CNcomment: �ɹ�
* retval ::HI_ERR_COMM_NORES No memory. CNcomment: ϵͳ��û���ڴ�
* see ::HI_GV_AnimInfo_Destroy
*/
HI_S32 HI_GV_AnimInfo_Create(const HIGV_ANIM_INFO_S *animInfo, HIGV_HANDLE *animHandle);

/*
* brief Create animtion information by the handle. CNcomment: ����ָ���ľ������������Ϣ��ΪXML2Bin�ṩ
* param[in]  animInfo the point of animation information. CNcomment: ����������Ϣ
* param[in]  animHandle  Anim handle.CNcomment: ������Ϣ���
* retval ::HI_SUCCESS Success. CNcomment: �ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle.CNcomment: �����Ч
* reval ::HI_ERR_COMM_NORES No memory. CNcomment: ϵͳ��û���ڴ�
*/
HI_S32 HI_GV_AnimInfo_CreateByHandle(const HIGV_ANIM_INFO_S *animInfo, HIGV_HANDLE animHandle);

/*
* brief Destroy font.CNcomment: ɾ��������Ϣ
* param[in]  animHandle  Anim handle.CNcomment: ������Ϣ���
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_RES_UNKNOWRES Coun't find the anim.CNcomment: ϵͳ��û���ҵ���Ӧ�Ķ���
* see ::HI_GV_AnimInfo_Create
*/
HI_S32 HI_GV_AnimInfo_Destroy(HIGV_HANDLE animHandle);

/*
* brief Get system default font.CNcomment: ��ȡ������Ϣ
* param[in]  animHandle  Anim handle.CNcomment: ������Ϣ���
* param[out] animInfo   Anim info. CNcomment: ������Ϣ
* retval ::HI_SUCCESS Success.CNcomment: �ɹ�
* retval ::HI_ERR_COMM_INVAL Invalid handle.CNcomment: ��Ч����
* see ::HI_GV_AnimInfo_Create
*/
HI_S32 HI_GV_AnimInfo_Get(HIGV_HANDLE animHandle, HIGV_ANIM_INFO_S *animInfo);

#ifdef __cplusplus
}
#endif
#endif /* HI_GV_RESM_H */
