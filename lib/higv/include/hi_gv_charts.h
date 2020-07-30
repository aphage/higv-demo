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

/* Chart type [CN]:ͼ��ؼ������� */
typedef enum {
    HIGV_CHARTS_TYPE_INVAILD = 0,
    HIGV_CHARTS_TYPE_LINE = 1,   /* line chart.[CN]:����ͼ */
    HIGV_CHARTS_TYPE_BAR = 2,   /* histogram. [CN]:��״ͼ */
    HIGV_CHARTS_TYPE_CLUSTER = 3,  /* histogram(cluster). [CN]:��״��Ŀ��ͼ */
    HIGV_CHARTS_TYPE_BUFFER
} HigvChartsTypes;

/* Charts control public property structure[CN]:Charts�ؼ��������Խṹ�� */
typedef struct {
    HI_U32 chartType;  // Control type, [CN]:ͼ�������
    HI_U32 barWidth;  // Histogram width in single histogram mode.[CN]:����״ͼģʽ�µ���״ͼ���
    HI_U32 subBarWidth;  // Sub-item width in item cluster mode.[CN]:��Ŀ��ģʽ�£�����Ŀ�Ŀ��
    HI_U32 subBarDist;  // Spacing of sub-items in item cluster mode.[CN]:��Ŀ���£�����Ŀ��ľ���
    HI_U32 subBarCnt;  //  Number of sub-items in item cluster mode.[CN]:������ͼ����
    HI_U32 lineCnt;  // Number of polylines.[CN]:���߸���
    HI_U32 lineWidth;  // Polyline width, [CN]���߿��
    HI_COLOR borderColor;  // Border color.[CN]:�߿���ɫ
    HI_U32 borderWidth;  // Border width.[CN]:�߿���
    HIGV_HANDLE titleFont;  // Title font.[CN]:��������
    HI_COLOR titleColor;  // Title color,[CN]:������ɫ
    HIGV_HANDLE legendFont;  // Legend font,[CN]:ͼ������
    HI_COLOR legendColor;  // Legend color, [CN]:ͼ����ɫ
    HI_BOOL drawBorder;  // Whether to draw a border.[CN]�Ƿ񻭱߿�
    HI_CHAR  titleContent[MAX_LINE_LABEL_TEXT];  // title content.[CN]:��������
} HIGV_CHARTS_COMM_S;

/* Charts control axis property structure.[CN]:Charts�ؼ����������Խṹ�� */
typedef struct {
    HI_U32 axisLeftSpace;  // Left margin of the axis and border, [CN]:��������߿�ľ���
    HI_U32 axisRightSpace;  // Right margin of the axis and border,[CN]:��������߿���ұ߾�
    HI_U32 axisTopSpace;  // Top margin of the axis and border, [CN]:������߿�Ķ��߾�
    HI_U32 axisBottonSpace;  // Botton margin of the axis and border. [CN]:������߿�ĵױ߾�
    HI_U32 axisWidth;  // Axis width: [CN]:��������
    HI_COLOR axisColor;  // Axis color: [CN]:��������ɫ
    HI_U32 axisArrowLength;  // Axis arrow length, [CN]: �������ͷ����
    HIGV_HANDLE axisLabelFont;  // Axis font labels, [CN]:�������ǩ����
    HI_COLOR axisLabelColor;  // Axis font labels color, [CN]:�������ǩ��ɫ
    HI_U32 axisXMinValue;  // X coordinate axis minimum, [CN]: X ��������Сֵ
    HI_U32 axisXMaxValue;  // X coordinate axis maximum, [CN]: X ���������ֵ
    HI_U32 axisYMinValue;  // Y coordinate axis minimum, [CN]: Y ��������Сֵ
    HI_U32 axisYMaxValue;  // Y coordinate axis maximum, [CN]: Y ���������ֵ
    HI_U32 axisXTickNum;  // X-axis axis division factor�� [CN]: X ������ȷ�ϵ��
    HI_U32 axisYTickNum;  // Y-axis axis division factor�� [CN]: Y ������ȷ�ϵ��
    HI_U32 axisTickLength;  // Axis scale height�� [CN]:������̶ȸ߶�
    HI_CHAR axisXLabelContent[MAX_LINE_LABEL_TEXT];  // X axis label content, [CN]:X�������ǩ����
    HI_CHAR axisYLabelContent[MAX_LINE_LABEL_TEXT];  // Y axis label content, [CN]:Y �������ǩ����
} HIGV_CHARTS_AXIS_S;

/* Charts control standard line attribute structure.[CN]:Charts�ؼ���׼�����Խṹ�� */
typedef struct {
    HI_U32 stLineMinValue;  // Standard line minimum, [CN]:��׼����Сֵ
    HI_COLOR stLineMinColor;  // Standard line minimum color, [CN]:��С ��׼����ɫ
    HI_U32 stLineMaxValue;  // Standard line maximum, [CN]:��׼�����ֵ
    HI_COLOR stLineMaxColor;  // Standard line maximum color, [CN]:����׼����ɫ
} HIGV_CHARTS_STLINE_S;

/* Chart Widget's structure, [CN]:Chart�ؼ��ṹ��   */
typedef struct {
    HIGV_CHARTS_COMM_S comAttr;  // Charts control public property structure[CN]:Charts�ؼ��������Խṹ��
    HIGV_CHARTS_AXIS_S axisAttr;  // Charts control axis property structure.[CN]:Charts�ؼ����������Խṹ��
    HIGV_CHARTS_STLINE_S stLineAttr;  // Charts control standard line attribute structure.[CN]:Charts�ؼ���׼�����Խṹ��
    HI_BOOL isDrawStLine;  // Whether to draw standard lines, [CN]:�Ƿ���Ʊ�׼��
    HI_BOOL gridLine;  // Whether to draw grid lines, [CN]:�Ƿ�������
    HI_COLOR gridColor;  //  draw grid lines color, [CN]:��������ɫ
    HI_BOOL textOnBar;  // Whether to draw the corresponding text on the bar chart, [CN]:�Ƿ��ڸ�����ͼ�Ϸ��Ļ�������
    HIGV_HANDLE textOnBarFont;  // Font for drawing corresponding text on bar chart, [CN]:����ͼ������
    HI_COLOR textOnBarColor;  // Font color of corresponding text drawn on bar chart, [CN]:����ͼ����ʾ������ɫ
    HI_U32 axisXIndentation;  // Indentation of scale X axis, [CN]:X �᷽���������С��������ʾ�����
    HI_U32 axisYIndentation;  // Indentation of scale Y axis,[CN]:Y �᷽���������С��������ʾ�����
    HI_BOOL isReplaceXLabel;  // Used to replace the scale value on the X axis, such as the date display;
                                                // [CN] :���ڴ���X���Ͽ̶�ֵ��������������ʾ��
} HIGV_CHARTS_STYLE;

/* Child item cluster structure in Charts control.[CN]: Charts�ؼ�������Ŀ�ؽṹ�� */
typedef struct  {
    HI_COLOR barColor; /*  Sub-histogram color, [CN]:��Ŀ��ɫ */
                                            /* [CN]:����ͼ��Ŀ�Ϸ�������ʾ������ɫ */
    HI_U32 subBarTitle;  /*  Sub-histogram title for display at legend */
                                     /*  [CN]:����״ͼ���⣬������ͼ������ʾ  */
    HI_U32 indexDB;        /* The number of the column in the data burst, [CN]: ������DB�е������ */
} HIGV_CHARTS_BAR_S;

/* Structures at points on polylines, [CN]:  �����ϵ�Ľṹ�� */
typedef struct {
    HI_U32 x;  /* X coordinate point, [CN]:X  ������ */
    HI_U32 y;  /* Y coordinate point,[CN]: Y ������ */
} HIGV_LINECHARTS_POINT_S;

/* Histogram private data structure,  ��״ͼ˽�����ݽṹ�� */
typedef struct {
    HI_U32 value;  /* Histogram data value corresponding to ordinate, [CN]:��Ӧ����������� */
    HI_COLOR color;  /* Color value corresponding to the above data, [CN]:��Ӧ����ɫֵ */
} HIGV_BARCHARTS_VALUE_S;

/*
* brief: Initiatlize the higvCharts. [CN]:Chart �ؼ���ʼ��
* param[in] handle:Chart control handle. [CN]:Chart�ؼ��ľ��
* param[in] style: Chart control's main property structure.[CN]:Chart�ؼ��������Խṹ��
* param[in] barAttr: Chart control's subsidiary child item cluster properties.[CN]:Chart�ؼ��ĸ�������Ŀ�����Խṹ��
* param[in] barCnt: Number of sub-items of Chart control.[CN]:Chart�ؼ��ĸ�������Ŀ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_CHARTS_Init(HIGV_HANDLE handle, HIGV_CHARTS_STYLE *style, HIGV_CHARTS_BAR_S *barAttr,
    HI_U32 barCnt);

/*
* brief: Binding Polyline Related Data. [CN]:�������������
* attition: Before drawing polyline data, you need to call this interface to bind the data with the polyline
* attition[CN]: �ڻ�����������ǰ������ô˽ӿڽ��������������
* param[in] handle:Chart control handle. [CN]:Chart�ؼ��ľ��
* param[in] pos: The number of the polyline to belong to, starting from 0.[CN]:������������ţ���0��ʼ
* param[in] color: The color of this polyline.[CN]:�������ߵ���ɫ
* param[in] lineChartPoint: Point data on polyline.[CN]:�����ϵĵ�����
* param[in] length:Number of point data on polyline, [CN]:�����ϵĵ���������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_CHARTS_BindLineData(HIGV_HANDLE handle, HI_U32 pos, HI_COLOR color,
    HIGV_LINECHARTS_POINT_S *lineChartPoint, HI_U32 length);

/*
* brief: Set polyline title for display on legend, [CN]:�������߱��⣬������ͼ������ʾ
* param[in] handle:Chart control handle. [CN]:Chart�ؼ��ľ��
* param[in] name:Polyline title. [CN]:���߱���
* param[in] length:Incoming name length, [CN]:�������Ƴ���
* param[in] pos: The number of the polyline to belong to, starting from 0.[CN]:������������ţ���0��ʼ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_CHARTS_SetLineTitle(HIGV_HANDLE handle, HI_CHAR *name, HI_U32 length, HI_U32 pos);

/*
* brief: Binding Histogram Data, [CN]:����״ͼ����
* attition: Before drawing Histogram data, you need to call this interface to bind the data with the Histogram
* attition: �ڻ�����״ͼʱ������ô˽ӿڽ���������״ͼ���
* param[in] handle:Chart control handle. [CN]:Chart�ؼ��ľ��
* param[in] name:Polyline title. [CN]:���߱���
* param[in] barChartValue:Histogram bound points, [CN]:��״ͼ�󶨵ĵ�
* param[in] length:Number of point data on polyline, [CN]:��״ͼ����������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_CHARTS_BindBarData(HIGV_HANDLE handle,
    HIGV_BARCHARTS_VALUE_S *barChartValue, HI_U32 length);

/*
* brief: Histogram labels in x-axis direction in histogram or item cluster mode
* brief[CN]:��״ͼ����Ŀ��ģʽ�£�x�᷽���ϸ���״ͼ��ǩ
* param[in] handle:Chart control handle. [CN]:Chart�ؼ��ľ��
* param[in] name:Polyline title. [CN]:����
* param[in] length:Incoming name length, [CN]:�������Ƴ���
* param[in] pos: The number of the Histogram to belong to, starting from 0.[CN]:��������״ͼ��ţ���0��ʼ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_CHARTS_SetAxisXBarTitle(HIGV_HANDLE handle, HI_CHAR *name, HI_U32 length, HI_U32 pos);

/*
* brief: In line chart mode, replace the X axis label name, such as time format
* brief[CN]:����ͼģʽ�£��滻X���������ǩ���������滻Ϊʱ��
* param[in] replace:enable this model. [CN]:���ܿ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_CHARTS_SetAxisXReplace(HIGV_HANDLE handle, HI_BOOL replace);

/*
* brief: Line replace labels in x-axis direction in line model
* brief[CN]:����ͼģʽ�£��滻X���������ǩ���������滻Ϊʱ��
* param[in] handle:Chart control handle. [CN]:Chart�ؼ��ľ��
* param[in] name:Replace x-axis tick label names. [CN]:�滻x��̶ȱ�ǩ����
* param[in] length:Incoming name length, [CN]:�������Ƴ���
* param[in] pos: The number of the x-axis tick labels belong to, starting from 0.[CN]:������x ���ǩλ����ţ���0��ʼ
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
