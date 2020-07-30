/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: ScrollGrid API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_SCROLLGRID_H
#define HI_GV_SCROLLGRID_H
#include "hi_gv_conf.h"

#ifdef HIGV_USE_WIDGET_SCROLLGRID
/* add include here */
#include "hi_gv_resm.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HIGV_SCROLLGRID_COL_MAX 20

typedef enum {  /* ScrollGrid ; CNcomment: ScrollGrid */
    SCROLLGRID_COLTYPE_TXT = 0, /* text */
    SCROLLGRID_COLTYPE_IMG, /* picture */
    SCROLLGRID_COLTYPE_IMG_MEM,  /* memory picture */
    SCROLLGRID_COLTYPE_BUTT
} HIGV_SCROLLGRID_COLTYPE_E;

/*  The callback function is uded to convert string */
typedef HI_S32 (*HIGV_SCROLLGRID_CONV_CB)(HIGV_HANDLE scrollGridPara, HI_U32 cellCol, HI_U32 cell,
    const HI_CHAR *srcStr, HI_CHAR *dstStr, HI_U32 length);

typedef struct _HIGV_SCROLLGRID_COLATTR_S { /* the column attribute structure; CNcomment: ScrollGrid�ؼ������Խṹ */
    HIGV_SCROLLGRID_COLTYPE_E Type; /* The type of column ; CNcomment:CELL�� ������ */
    HI_U32 Top; /* The top position of cell; CNcomment: ���CELL������λ�� */
    HI_U32 Left; /* The top position of cell ; CNcomment: ���CELL�� ����λ�� */
    HI_U32 Width; /* The widht of cell ; CNcomment: CELL�� �п� */
    HI_U32 Height; /* The height of cell ; CNcomment: CELL�� �и� */
    HI_U32 Align; /* The aligment of text ; CNcomment: �ı����뷽ʽ */
    HIGV_HANDLE hImage;  /*  The picture handle(only support the cloumn type is LIST_COLTYPE_IMG)
                            CNcomment: ��Type=LIST_COLTYPE_IMGʱ��Ч����Ҫ��ʾ��ͼƬsurface��� */
    HI_U32 FieldColIdxInDb;  /* The index in database correspoding column in scrollgrid ;
                                CNcomment: ���������ݿ��е��к� */
    HIGV_SCROLLGRID_CONV_CB ConvString;  /* The convet string callback ;
                                        CNcomment: �ַ���ת��������ֻ��LIST_COLTYPE_TXT��Ч */
} HIGV_SCROLLGRID_COLATTR_S;

typedef enum _SCROLLGRID_DIRECTION_E {  /* Scroll direction ; CNcomment: ScrollGrid�ؼ��Ĺ���(����)����ö�� */
    SCROLLGRID_DIRECTION_HORI,      /* <Horizal direction ; CNcomment: ˮƽ�������� */
    SCROLLGRID_DIRECTION_VERT,  /* Vertial direction ; CNcomment:��ֱ�������� */
    SCROLLGRID_DIRECTION_BUTT
} HIGV_SCROLLGRID_DIRECTION_E;

typedef struct _HIGV_SCROLLGRID_STYLE_S {   /*  Layout structure ; CNcomment: scrollgrid�ؼ���񲼾����� */
    HI_U32 RowNum; /* Row number in a page ; CNcomment: ҳ��ʾ���� */
    HI_U32 ColNum; /*  Colum number in a page ; CNcomment: ҳ��ʾ���� */
    HI_U32 LeftMargin; /* left margin of the page ; CNcomment: ҳ��߾� */
    HI_U32 RightMargin; /* Right margin of the page ; CNcomment: ҳ�ұ߾� */
    HI_U32 TopMargin; /* Up margin of the page ; CNcomment: ҳ�ϱ߾� */
    HI_U32 BtmMargin; /* Bottom margin of the page ; CNcomment: ҳ�±߾� */
    HI_U32 RowSpace; /* The space of row ; CNcomment: ҳ�м�� */
    HI_U32 ColSpace; /* The space of column ; CNcomment: ҳ�м�� */
    HI_U32 HLHeight; /* The height of horizontal line ; CNcomment: ˮƽ�����߿�� */
    HI_COLOR HLColor; /* The color of horizontal line ;  CNcomment: ˮƽ��������ɫ */
    HI_U32 VLWidth; /* The width of vertical line ; CNcomment:  ��ֱ�����߿�� */
    HI_COLOR VLColor; /* The color of vertical line ;  CNcomment: ��ֱ��������ɫ */
    HI_U32 FocusRectAnchor; /* The anchor position of focus item ; CNcomment: ������Ŀ����ʱ�����êλ�� */
    HI_U32 IsFocusAtBg; /* The focus is drawn at the background ; CNcomment:���������ڱ���֮�� */
    HI_U32 ImgDecIndex; /* The index of decode picture ; CNcomment:ͼƬ�������� */
    HI_U32 IsDynamicDecImg; /* Is Dynamic decode image ; CNcomment:����Ƿ�̬ͼƬ���� */
    HIGV_SCROLLGRID_DIRECTION_E Direction; /* Scroll direction ; CNcomment: ���췽�� */
    HI_RESID FocusRectSkin;
    HI_RESID FocusRectNormSkin;
} HIGV_SCROLLGRID_STYLE_S;

/*
* brief Initiatlize the scrollgird. CNcomment:ScrollGrid �ؼ���ʼ��
* attention : Set the head of scrollgrid and row num.
* CNcomment:����Grid�ؼ��ı�ͷ(������������)������
* param[in] scrollGridPara    Scrollgrid handle. CNcomment:ScrollGrid�ؼ����
* param[in] style   Scrollgrid handle.CNcomment:�ؼ���񲼾�����
* param[in] colAttr Scrollgrid handle.CNcomment:����������
* param[in] cellColNum Scrollgrid handle.CNcomment:�������������Ԫ�ظ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_ScrollGrid_Init(HIGV_HANDLE scrollGridPara, HIGV_SCROLLGRID_STYLE_S *style,
    const HIGV_SCROLLGRID_COLATTR_S *colAttr, HI_U32 cellColNum);

/*
* brief Get the content of scrollgrid.CNcomment:��ȡScrollGrid�ؼ����ݸ������
* param[in] scrollGridPara   Scrollgrid handle.CNcomment:ScrollGrid�ؼ����
* param[in] cell   Cell. CNcomment:��Ԫ��
* param[in] cellCol The column attribute of cell. CNcomment:��Ԫ���������
* param[out] value the conten of cell. CNcomment:��Ԫ�������е�����
* param[in] length String length. CNcomment:pValue�ַ�������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST Maybe the handle is invaldi or no data.CNcomment:�����Ч���߶Ծ��к���û������
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_GetCellValue(HIGV_HANDLE scrollGridPara, HI_U32 cell,
    HI_U32 cellCol, HI_CHAR *value, HI_U32 length);

/*
* brief Set the selected cell of the scrollgrid.CNcomment:���� ScrollGrid��ǰ��Ԫ
* attention : This api only support the current selected item.
* CNcomment:�ýӿڽ����õ�ǰѡ����Ŀ
* param[in] scrollGrid CNcomment:�ؼ����
* param[in] cell  Cell index.CNcomment:��Ŀ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_ScrollGrid_GetSelCell
*/
HI_S32 HI_GV_ScrollGrid_SetSelCell(HIGV_HANDLE scrollGridPara, HI_U32 cell);

/*
* brief Get the selected of cell.CNcomment:��ȡScrollGrid��ǰ��Ԫ
* param[in] scrollGridPara  Scrollgrid handle.CNcomment:�ؼ����
* param[out] cell Cell index. CNcomment:��Ŀ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_ScrollGrid_SetSelCell
*/
HI_S32 HI_GV_ScrollGrid_GetSelCell(HIGV_HANDLE scrollGridPara, HI_U32 *cell);

/*
* brief Get the cell number of scrollgrid.CNcomment:��ȡScrollGrid��ǰ�����ܵ�Ԫ��
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:�ؼ����
* param[out] cellNum Cell number.CNcomment:����Ŀ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_GetCellNum(HIGV_HANDLE scrollGridPara, HI_U32 *cellNum);

/*
* brief Page up or page right.CNcomment:���»����ҷ�ҳ
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:�ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_PageForward(HIGV_HANDLE scrollGridPara);

/*
* brief Page up or page left.CNcomment:���ϻ�����ҳ
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:�ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_PageBackward(HIGV_HANDLE scrollGridPara);

/*
* brief Back to origin.CNcomment:���ñ����ƶ�����ʼλ��
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:�ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_MoveToOrigin(HIGV_HANDLE scrollGridPara);

/*
* brief Move to last.CNcomment:���ñ����ƶ����յ�λ��
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:�ؼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_MoveToLast(HIGV_HANDLE scrollGridPara);

/*
* brief Set the attribute of scrollgird.CNcomment: ��������������
* param[in]  scrollGridPara  ScrollGrid handle.CNcomment: �ؼ����
* param[in]  horizontalLineHeight  The height of horizontal line.CNcomment: ˮƽ�߸߶�
* param[in]  horizontalLineColor  The color of horizontal line.CNcomment: ˮƽ����ɫ
* param[in]  verticalLineWidth The width of vertical line.CNcomment:  ��ֱ�߿��
* param[in]  verticalLineColor  The color of vertical line.CNcomment: ��ֱ����ɫ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_ScrollGrid_GetGridding
*/
HI_S32 HI_GV_ScrollGrid_SetGridding(HIGV_HANDLE scrollGridPara, HI_U32 horizontalLineHeight,
    HI_COLOR horizontalLineColor, HI_U32 verticalLineWidth, HI_COLOR verticalLineColor);

/*
* brief Get the attribute of scrollgird.CNcomment: ��ȡ����������
* param[in]  scrollGridPara  ScrollGrid handle.�ؼ����
* param[out]  horizontalLineHeight The height of horizontal line. CNcomment: ˮƽ�߸߶�
* param[out]  horizontalLineColor  The color of horizontal line.CNcomment: ˮƽ����ɫ
* param[out]  verticalLineWidth  The width of vertical line.CNcomment: ��ֱ�߿��
* param[out]  verticalLineColor  The color of vertical line.CNcomment: ��ֱ����ɫ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see::HI_GV_ScrollGrid_SetGridding
*/
HI_S32 HI_GV_ScrollGrid_GetGridding(HIGV_HANDLE scrollGridPara, HI_U32 *horizontalLineHeight,
    HI_COLOR *horizontalLineColor, HI_U32 *verticalLineWidth, HI_COLOR *verticalLineColor);

/*
* brief Get touch diff.CNcomment:��ȡ�������ƫ�ƾ���
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:�ؼ����
* param[out]  diff  diff distance. CNcomment:ƫ�ƾ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_GetTouchDiff(HIGV_HANDLE scrollGridPara, HI_S32 *diff);

/*
* brief Set content location.CNcomment:���ÿؼ�����ƫ��
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:�ؼ����
* param[in]  diff  diff distance. CNcomment:ƫ�ƾ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_Adjust(HIGV_HANDLE scrollGridPara, HI_S32 diff);

/*
* brief Set gesture enable.CNcomment:���ÿؼ��Ƿ�֧�ִ���
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:�ؼ����
* param[in]  enable   Is enable gesture. CNcomment:�Ƿ�֧�ִ���( HI_TRUE��ʾ֧�֣�HI_FALSE��ʾ��ֹ)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_EnableGesture(HIGV_HANDLE scrollGridPara, HI_BOOL enable);

/*
* brief Get gesture enable.CNcomment:��ȡ�ؼ��Ƿ�֧�ִ���
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:�ؼ����
* param[in]  enable   Is enable gesture. CNcomment:�Ƿ�֧�ִ���( HI_TRUE��ʾ֧�֣�HI_FALSE��ʾ��ֹ��ϵͳĬ��ΪHI_TRUE)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_IsGestureEnable(HIGV_HANDLE scrollGridPara, HI_BOOL *enable);

/*
* brief Register scrollgrid widget.CNcomment:ע��scrollgrid�ؼ�
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_RegisterWidget(HI_VOID);

#ifdef __cplusplus
}
#endif
#endif /* HI_GV_LIST_H */
#endif
