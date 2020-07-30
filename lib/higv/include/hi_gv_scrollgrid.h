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

typedef struct _HIGV_SCROLLGRID_COLATTR_S { /* the column attribute structure; CNcomment: ScrollGrid控件列属性结构 */
    HIGV_SCROLLGRID_COLTYPE_E Type; /* The type of column ; CNcomment:CELL的 列类型 */
    HI_U32 Top; /* The top position of cell; CNcomment: 相对CELL的最上位置 */
    HI_U32 Left; /* The top position of cell ; CNcomment: 相对CELL的 最左位置 */
    HI_U32 Width; /* The widht of cell ; CNcomment: CELL的 列宽 */
    HI_U32 Height; /* The height of cell ; CNcomment: CELL的 列高 */
    HI_U32 Align; /* The aligment of text ; CNcomment: 文本对齐方式 */
    HIGV_HANDLE hImage;  /*  The picture handle(only support the cloumn type is LIST_COLTYPE_IMG)
                            CNcomment: 当Type=LIST_COLTYPE_IMG时有效，需要显示的图片surface句柄 */
    HI_U32 FieldColIdxInDb;  /* The index in database correspoding column in scrollgrid ;
                                CNcomment: 该列在数据库中的列号 */
    HIGV_SCROLLGRID_CONV_CB ConvString;  /* The convet string callback ;
                                        CNcomment: 字符串转换函数，只对LIST_COLTYPE_TXT有效 */
} HIGV_SCROLLGRID_COLATTR_S;

typedef enum _SCROLLGRID_DIRECTION_E {  /* Scroll direction ; CNcomment: ScrollGrid控件的滚动(延伸)方向枚举 */
    SCROLLGRID_DIRECTION_HORI,      /* <Horizal direction ; CNcomment: 水平方向延伸 */
    SCROLLGRID_DIRECTION_VERT,  /* Vertial direction ; CNcomment:垂直方向延伸 */
    SCROLLGRID_DIRECTION_BUTT
} HIGV_SCROLLGRID_DIRECTION_E;

typedef struct _HIGV_SCROLLGRID_STYLE_S {   /*  Layout structure ; CNcomment: scrollgrid控件风格布局属性 */
    HI_U32 RowNum; /* Row number in a page ; CNcomment: 页显示行数 */
    HI_U32 ColNum; /*  Colum number in a page ; CNcomment: 页显示列数 */
    HI_U32 LeftMargin; /* left margin of the page ; CNcomment: 页左边距 */
    HI_U32 RightMargin; /* Right margin of the page ; CNcomment: 页右边距 */
    HI_U32 TopMargin; /* Up margin of the page ; CNcomment: 页上边距 */
    HI_U32 BtmMargin; /* Bottom margin of the page ; CNcomment: 页下边距 */
    HI_U32 RowSpace; /* The space of row ; CNcomment: 页行间距 */
    HI_U32 ColSpace; /* The space of column ; CNcomment: 页列间距 */
    HI_U32 HLHeight; /* The height of horizontal line ; CNcomment: 水平网格线宽度 */
    HI_COLOR HLColor; /* The color of horizontal line ;  CNcomment: 水平网格线颜色 */
    HI_U32 VLWidth; /* The width of vertical line ; CNcomment:  垂直网格线宽度 */
    HI_COLOR VLColor; /* The color of vertical line ;  CNcomment: 垂直网格线颜色 */
    HI_U32 FocusRectAnchor; /* The anchor position of focus item ; CNcomment: 触发条目滚动时焦点框锚位置 */
    HI_U32 IsFocusAtBg; /* The focus is drawn at the background ; CNcomment:焦点框绘制在背景之上 */
    HI_U32 ImgDecIndex; /* The index of decode picture ; CNcomment:图片解码索引 */
    HI_U32 IsDynamicDecImg; /* Is Dynamic decode image ; CNcomment:标记是否动态图片解码 */
    HIGV_SCROLLGRID_DIRECTION_E Direction; /* Scroll direction ; CNcomment: 延伸方向 */
    HI_RESID FocusRectSkin;
    HI_RESID FocusRectNormSkin;
} HIGV_SCROLLGRID_STYLE_S;

/*
* brief Initiatlize the scrollgird. CNcomment:ScrollGrid 控件初始化
* attention : Set the head of scrollgrid and row num.
* CNcomment:设置Grid控件的表头(列数及列属性)和行数
* param[in] scrollGridPara    Scrollgrid handle. CNcomment:ScrollGrid控件句柄
* param[in] style   Scrollgrid handle.CNcomment:控件风格布局属性
* param[in] colAttr Scrollgrid handle.CNcomment:列属性数组
* param[in] cellColNum Scrollgrid handle.CNcomment:列属性数组包含元素个数
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_ScrollGrid_Init(HIGV_HANDLE scrollGridPara, HIGV_SCROLLGRID_STYLE_S *style,
    const HIGV_SCROLLGRID_COLATTR_S *colAttr, HI_U32 cellColNum);

/*
* brief Get the content of scrollgrid.CNcomment:获取ScrollGrid控件数据格的内容
* param[in] scrollGridPara   Scrollgrid handle.CNcomment:ScrollGrid控件句柄
* param[in] cell   Cell. CNcomment:单元格
* param[in] cellCol The column attribute of cell. CNcomment:单元格的属性列
* param[out] value the conten of cell. CNcomment:单元格属性列的内容
* param[in] length String length. CNcomment:pValue字符串长度
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST Maybe the handle is invaldi or no data.CNcomment:句柄无效或者对就行和列没有数据
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_GetCellValue(HIGV_HANDLE scrollGridPara, HI_U32 cell,
    HI_U32 cellCol, HI_CHAR *value, HI_U32 length);

/*
* brief Set the selected cell of the scrollgrid.CNcomment:设置 ScrollGrid当前单元
* attention : This api only support the current selected item.
* CNcomment:该接口仅设置当前选中条目
* param[in] scrollGrid CNcomment:控件句柄
* param[in] cell  Cell index.CNcomment:条目编号
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_ScrollGrid_GetSelCell
*/
HI_S32 HI_GV_ScrollGrid_SetSelCell(HIGV_HANDLE scrollGridPara, HI_U32 cell);

/*
* brief Get the selected of cell.CNcomment:获取ScrollGrid当前单元
* param[in] scrollGridPara  Scrollgrid handle.CNcomment:控件句柄
* param[out] cell Cell index. CNcomment:条目编号
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_ScrollGrid_SetSelCell
*/
HI_S32 HI_GV_ScrollGrid_GetSelCell(HIGV_HANDLE scrollGridPara, HI_U32 *cell);

/*
* brief Get the cell number of scrollgrid.CNcomment:获取ScrollGrid当前数据总单元数
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:控件句柄
* param[out] cellNum Cell number.CNcomment:总条目数
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_GetCellNum(HIGV_HANDLE scrollGridPara, HI_U32 *cellNum);

/*
* brief Page up or page right.CNcomment:向下或向右翻页
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:控件句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_PageForward(HIGV_HANDLE scrollGridPara);

/*
* brief Page up or page left.CNcomment:向上或向左翻页
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:控件句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_PageBackward(HIGV_HANDLE scrollGridPara);

/*
* brief Back to origin.CNcomment:设置背景移动到初始位置
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:控件句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_MoveToOrigin(HIGV_HANDLE scrollGridPara);

/*
* brief Move to last.CNcomment:设置背景移动到终点位置
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:控件句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_MoveToLast(HIGV_HANDLE scrollGridPara);

/*
* brief Set the attribute of scrollgird.CNcomment: 设置网格线属性
* param[in]  scrollGridPara  ScrollGrid handle.CNcomment: 控件句柄
* param[in]  horizontalLineHeight  The height of horizontal line.CNcomment: 水平线高度
* param[in]  horizontalLineColor  The color of horizontal line.CNcomment: 水平线颜色
* param[in]  verticalLineWidth The width of vertical line.CNcomment:  竖直线宽度
* param[in]  verticalLineColor  The color of vertical line.CNcomment: 竖直线颜色
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_ScrollGrid_GetGridding
*/
HI_S32 HI_GV_ScrollGrid_SetGridding(HIGV_HANDLE scrollGridPara, HI_U32 horizontalLineHeight,
    HI_COLOR horizontalLineColor, HI_U32 verticalLineWidth, HI_COLOR verticalLineColor);

/*
* brief Get the attribute of scrollgird.CNcomment: 获取网格线属性
* param[in]  scrollGridPara  ScrollGrid handle.控件句柄
* param[out]  horizontalLineHeight The height of horizontal line. CNcomment: 水平线高度
* param[out]  horizontalLineColor  The color of horizontal line.CNcomment: 水平线颜色
* param[out]  verticalLineWidth  The width of vertical line.CNcomment: 竖直线宽度
* param[out]  verticalLineColor  The color of vertical line.CNcomment: 竖直线颜色
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see::HI_GV_ScrollGrid_SetGridding
*/
HI_S32 HI_GV_ScrollGrid_GetGridding(HIGV_HANDLE scrollGridPara, HI_U32 *horizontalLineHeight,
    HI_COLOR *horizontalLineColor, HI_U32 *verticalLineWidth, HI_COLOR *verticalLineColor);

/*
* brief Get touch diff.CNcomment:获取网格相对偏移距离
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:控件句柄
* param[out]  diff  diff distance. CNcomment:偏移距离
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_GetTouchDiff(HIGV_HANDLE scrollGridPara, HI_S32 *diff);

/*
* brief Set content location.CNcomment:设置控件内容偏移
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:控件句柄
* param[in]  diff  diff distance. CNcomment:偏移距离
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_Adjust(HIGV_HANDLE scrollGridPara, HI_S32 diff);

/*
* brief Set gesture enable.CNcomment:设置控件是否支持触摸
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:控件句柄
* param[in]  enable   Is enable gesture. CNcomment:是否支持触摸( HI_TRUE表示支持，HI_FALSE表示禁止)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_EnableGesture(HIGV_HANDLE scrollGridPara, HI_BOOL enable);

/*
* brief Get gesture enable.CNcomment:获取控件是否支持触摸
* param[in]  scrollGridPara  Scrollgrid handle. CNcomment:控件句柄
* param[in]  enable   Is enable gesture. CNcomment:是否支持触摸( HI_TRUE表示支持，HI_FALSE表示禁止，系统默认为HI_TRUE)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_ScrollGrid_IsGestureEnable(HIGV_HANDLE scrollGridPara, HI_BOOL *enable);

/*
* brief Register scrollgrid widget.CNcomment:注册scrollgrid控件
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
