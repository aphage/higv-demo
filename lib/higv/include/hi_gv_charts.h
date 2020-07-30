/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: HigvCharts API
 * Author: HiMobileCam middleware develop team
 * Create: 2020-02-12
 */

#ifndef HI_GV_CHARTS_H
#define HI_GV_CHARTS_H
#include "hi_gv_conf.h"
#include "hi_gv.h"

#ifdef HIGV_USE_WIDGET_CHARTS
#include "hi_gv_resm.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_SUB_BAR_CNT  28
#define MAX_LINE_CNT 28
#define MAX_BAR_CNT 28
#define MAX_LINE_LABEL_TEXT 128

/* Chart type [CN]:图表控件的类型 */
typedef enum {
    HIGV_CHARTS_TYPE_INVAILD = 0,
    HIGV_CHARTS_TYPE_LINE = 1,   /* line chart.[CN]:折线图 */
    HIGV_CHARTS_TYPE_BAR = 2,   /* histogram. [CN]:柱状图 */
    HIGV_CHARTS_TYPE_CLUSTER = 3,  /* histogram(cluster). [CN]:柱状条目簇图 */
    HIGV_CHARTS_TYPE_BUFFER
} HigvChartsTypes;

/* Charts control public property structure[CN]:Charts控件公有属性结构体 */
typedef struct {
    HI_U32 chartType;  // Control type, [CN]:图表的类型
    HI_U32 barWidth;  // Histogram width in single histogram mode.[CN]:单柱状图模式下的柱状图宽度
    HI_U32 subBarWidth;  // Sub-item width in item cluster mode.[CN]:条目簇模式下，子条目的宽度
    HI_U32 subBarDist;  // Spacing of sub-items in item cluster mode.[CN]:条目簇下，子条目间的距离
    HI_U32 subBarCnt;  //  Number of sub-items in item cluster mode.[CN]:子条形图个数
    HI_U32 lineCnt;  // Number of polylines.[CN]:折线个数
    HI_U32 lineWidth;  // Polyline width, [CN]折线宽度
    HI_COLOR borderColor;  // Border color.[CN]:边框颜色
    HI_U32 borderWidth;  // Border width.[CN]:边框宽度
    HIGV_HANDLE titleFont;  // Title font.[CN]:标题字体
    HI_COLOR titleColor;  // Title color,[CN]:标题颜色
    HIGV_HANDLE legendFont;  // Legend font,[CN]:图例字体
    HI_COLOR legendColor;  // Legend color, [CN]:图例颜色
    HI_BOOL drawBorder;  // Whether to draw a border.[CN]是否画边框
    HI_CHAR  titleContent[MAX_LINE_LABEL_TEXT];  // title content.[CN]:标题内容
} HIGV_CHARTS_COMM_S;

/* Charts control axis property structure.[CN]:Charts控件坐标轴属性结构体 */
typedef struct {
    HI_U32 axisLeftSpace;  // Left margin of the axis and border, [CN]:坐标轴与边框的距离
    HI_U32 axisRightSpace;  // Right margin of the axis and border,[CN]:坐标轴与边框的右边距
    HI_U32 axisTopSpace;  // Top margin of the axis and border, [CN]:坐标轴边框的顶边距
    HI_U32 axisBottonSpace;  // Botton margin of the axis and border. [CN]:坐标轴边框的底边距
    HI_U32 axisWidth;  // Axis width: [CN]:坐标轴宽度
    HI_COLOR axisColor;  // Axis color: [CN]:坐标轴颜色
    HI_U32 axisArrowLength;  // Axis arrow length, [CN]: 坐标轴箭头长度
    HIGV_HANDLE axisLabelFont;  // Axis font labels, [CN]:坐标轴标签字体
    HI_COLOR axisLabelColor;  // Axis font labels color, [CN]:坐标轴标签颜色
    HI_U32 axisXMinValue;  // X coordinate axis minimum, [CN]: X 坐标轴最小值
    HI_U32 axisXMaxValue;  // X coordinate axis maximum, [CN]: X 坐标轴最大值
    HI_U32 axisYMinValue;  // Y coordinate axis minimum, [CN]: Y 坐标轴最小值
    HI_U32 axisYMaxValue;  // Y coordinate axis maximum, [CN]: Y 坐标轴最大值
    HI_U32 axisXTickNum;  // X-axis axis division factor， [CN]: X 坐标轴等分系数
    HI_U32 axisYTickNum;  // Y-axis axis division factor， [CN]: Y 坐标轴等分系数
    HI_U32 axisTickLength;  // Axis scale height， [CN]:坐标轴刻度高度
    HI_CHAR axisXLabelContent[MAX_LINE_LABEL_TEXT];  // X axis label content, [CN]:X坐标轴标签内容
    HI_CHAR axisYLabelContent[MAX_LINE_LABEL_TEXT];  // Y axis label content, [CN]:Y 坐标轴标签内容
} HIGV_CHARTS_AXIS_S;

/* Charts control standard line attribute structure.[CN]:Charts控件标准线属性结构体 */
typedef struct {
    HI_U32 stLineMinValue;  // Standard line minimum, [CN]:标准线最小值
    HI_COLOR stLineMinColor;  // Standard line minimum color, [CN]:最小 标准线颜色
    HI_U32 stLineMaxValue;  // Standard line maximum, [CN]:标准线最大值
    HI_COLOR stLineMaxColor;  // Standard line maximum color, [CN]:最大标准线颜色
} HIGV_CHARTS_STLINE_S;

/* Chart Widget's structure, [CN]:Chart控件结构体   */
typedef struct {
    HIGV_CHARTS_COMM_S comAttr;  // Charts control public property structure[CN]:Charts控件公有属性结构体
    HIGV_CHARTS_AXIS_S axisAttr;  // Charts control axis property structure.[CN]:Charts控件坐标轴属性结构体
    HIGV_CHARTS_STLINE_S stLineAttr;  // Charts control standard line attribute structure.[CN]:Charts控件标准线属性结构体
    HI_BOOL isDrawStLine;  // Whether to draw standard lines, [CN]:是否绘制标准线
    HI_BOOL gridLine;  // Whether to draw grid lines, [CN]:是否画网格线
    HI_COLOR gridColor;  //  draw grid lines color, [CN]:网格线颜色
    HI_BOOL textOnBar;  // Whether to draw the corresponding text on the bar chart, [CN]:是否在各条形图上方的绘制文字
    HIGV_HANDLE textOnBarFont;  // Font for drawing corresponding text on bar chart, [CN]:条形图上字体
    HI_COLOR textOnBarColor;  // Font color of corresponding text drawn on bar chart, [CN]:条形图上显示字体颜色
    HI_U32 axisXIndentation;  // Indentation of scale X axis, [CN]:X 轴方向的缩进大小，用于显示字体等
    HI_U32 axisYIndentation;  // Indentation of scale Y axis,[CN]:Y 轴方向的缩进大小，用于显示字体等
    HI_BOOL isReplaceXLabel;  // Used to replace the scale value on the X axis, such as the date display;
                                                // [CN] :用于代替X轴上刻度值，比如用日期显示等
} HIGV_CHARTS_STYLE;

/* Child item cluster structure in Charts control.[CN]: Charts控件中子条目簇结构体 */
typedef struct  {
    HI_COLOR barColor; /*  Sub-histogram color, [CN]:条目颜色 */
                                            /* [CN]:条形图条目上方数据提示字体颜色 */
    HI_U32 subBarTitle;  /*  Sub-histogram title for display at legend */
                                     /*  [CN]:子柱状图标题，用于在图例处显示  */
    HI_U32 indexDB;        /* The number of the column in the data burst, [CN]: 该列在DB中的列序号 */
} HIGV_CHARTS_BAR_S;

/* Structures at points on polylines, [CN]:  折线上点的结构体 */
typedef struct {
    HI_U32 x;  /* X coordinate point, [CN]:X  轴坐标 */
    HI_U32 y;  /* Y coordinate point,[CN]: Y 轴坐标 */
} HIGV_LINECHARTS_POINT_S;

/* Histogram private data structure,  柱状图私有数据结构体 */
typedef struct {
    HI_U32 value;  /* Histogram data value corresponding to ordinate, [CN]:对应纵坐标的数据 */
    HI_COLOR color;  /* Color value corresponding to the above data, [CN]:对应的颜色值 */
} HIGV_BARCHARTS_VALUE_S;

/*
* brief: Initiatlize the higvCharts. [CN]:Chart 控件初始化
* param[in] handle:Chart control handle. [CN]:Chart控件的句柄
* param[in] style: Chart control's main property structure.[CN]:Chart控件的主属性结构体
* param[in] barAttr: Chart control's subsidiary child item cluster properties.[CN]:Chart控件的附属子条目簇属性结构体
* param[in] barCnt: Number of sub-items of Chart control.[CN]:Chart控件的附属子条目数量
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_CHARTS_Init(HIGV_HANDLE handle, HIGV_CHARTS_STYLE *style, HIGV_CHARTS_BAR_S *barAttr,
    HI_U32 barCnt);

/*
* brief: Binding Polyline Related Data. [CN]:绑定折线相关数据
* attition: Before drawing polyline data, you need to call this interface to bind the data with the polyline
* attition[CN]: 在绘制折线数据前，需调用此接口将数据与折线相绑定
* param[in] handle:Chart control handle. [CN]:Chart控件的句柄
* param[in] pos: The number of the polyline to belong to, starting from 0.[CN]:隶属的折线序号，从0开始
* param[in] color: The color of this polyline.[CN]:此条折线的颜色
* param[in] lineChartPoint: Point data on polyline.[CN]:折线上的点数据
* param[in] length:Number of point data on polyline, [CN]:折线上的点数据数量
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_CHARTS_BindLineData(HIGV_HANDLE handle, HI_U32 pos, HI_COLOR color,
    HIGV_LINECHARTS_POINT_S *lineChartPoint, HI_U32 length);

/*
* brief: Set polyline title for display on legend, [CN]:设置折线标题，用于在图例上显示
* param[in] handle:Chart control handle. [CN]:Chart控件的句柄
* param[in] name:Polyline title. [CN]:折线标题
* param[in] length:Incoming name length, [CN]:传入名称长度
* param[in] pos: The number of the polyline to belong to, starting from 0.[CN]:隶属的折线序号，从0开始
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_CHARTS_SetLineTitle(HIGV_HANDLE handle, HI_CHAR *name, HI_U32 length, HI_U32 pos);

/*
* brief: Binding Histogram Data, [CN]:绑定柱状图数据
* attition: Before drawing Histogram data, you need to call this interface to bind the data with the Histogram
* attition: 在绘制柱状图时，需调用此接口将数据与柱状图相绑定
* param[in] handle:Chart control handle. [CN]:Chart控件的句柄
* param[in] name:Polyline title. [CN]:折线标题
* param[in] barChartValue:Histogram bound points, [CN]:柱状图绑定的点
* param[in] length:Number of point data on polyline, [CN]:柱状图的数据数量
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_CHARTS_BindBarData(HIGV_HANDLE handle,
    HIGV_BARCHARTS_VALUE_S *barChartValue, HI_U32 length);

/*
* brief: Histogram labels in x-axis direction in histogram or item cluster mode
* brief[CN]:柱状图或条目簇模式下，x轴方向上各柱状图标签
* param[in] handle:Chart control handle. [CN]:Chart控件的句柄
* param[in] name:Polyline title. [CN]:标题
* param[in] length:Incoming name length, [CN]:传入名称长度
* param[in] pos: The number of the Histogram to belong to, starting from 0.[CN]:隶属的柱状图序号，从0开始
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_CHARTS_SetAxisXBarTitle(HIGV_HANDLE handle, HI_CHAR *name, HI_U32 length, HI_U32 pos);

/*
* brief: In line chart mode, replace the X axis label name, such as time format
* brief[CN]:折线图模式下，替换X轴坐标轴标签名，比如替换为时间
* param[in] replace:enable this model. [CN]:便能开关
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_CHARTS_SetAxisXReplace(HIGV_HANDLE handle, HI_BOOL replace);

/*
* brief: Line replace labels in x-axis direction in line model
* brief[CN]:折线图模式下，替换X轴坐标轴标签名，比如替换为时间
* param[in] handle:Chart control handle. [CN]:Chart控件的句柄
* param[in] name:Replace x-axis tick label names. [CN]:替换x轴刻度标签名称
* param[in] length:Incoming name length, [CN]:传入名称长度
* param[in] pos: The number of the x-axis tick labels belong to, starting from 0.[CN]:隶属的x 轴标签位置序号，从0开始
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_CHARTS_SetAxisXReplaceTitle(HIGV_HANDLE handle, HI_CHAR *name, HI_U32 length, HI_U32 pos);

#ifdef __cplusplus
}

#endif
#endif

#endif /* HI_GV_HIGVCHARTS_H */
