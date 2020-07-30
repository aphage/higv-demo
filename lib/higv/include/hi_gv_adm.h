/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: adm API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_ADM_H
#define HI_GV_ADM_H

#include "hi_type.h"
#include "hi_gv_widget.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ADM and DDB support  MAX filed number ; CNconmment: ���ݿ��Ĭ�ϻ���֧�ֵ�����ֶθ��� */
#define HIGV_DB_MAX_FIELDNUM      (64)
#define HIGV_DB_MAX_FIELD_STR_LEN (4096)

/* The type of data are supported.; CNcomment:֧�ֵ��������Ͷ��� */
typedef enum {
    HIGV_DT_S8 = 0, /* char */
    HIGV_DT_U8,     /* unsigned char */
    HIGV_DT_S16,    /* short */
    HIGV_DT_U16,    /* unsigned short */
    HIGV_DT_S32,    /* int */
    HIGV_DT_U32,    /* unsigned int */
    HIGV_DT_S64,    /* long long */
    HIGV_DT_U64,    /* unsigned long long */
    HIGV_DT_F32,    /* float */
    HIGV_DT_D64,    /* double */
    HIGV_DT_STRING, /* char * */
    HIGV_DT_HIMAGE, /* image handle */
    HIGV_DT_STRID,  /* multi-langugae  string ID */
    HIGV_DT_BUTT
} HIGV_DT_E;

/* The type of data change. ; CNconmment:���ݱ仯������ */
typedef enum {
    HIGV_DC_INSERT = 0,
    /* insert data ; CNcomment:���� */
    HIGV_DC_MODIFY,
    /* modify data ; CNcomment:�޸� */
    HIGV_DC_DELETE,
    /*  delete data ; CNcomment:ɾ�� */
    HIGV_DC_UPDATE,
    /* updata data,sealed operations ; CNcomment:���ݱ仯������δ֪ */
    HIGV_DC_CLEAR,
    /* clear all the data ; CNcomment:����ȫ������ */
    HIGV_DC_DESTROY,
    /* destroy the data source ; CNcomment:����Դ���� */
    HIGV_DC_BUTT
} HIGV_DC_E;

/* The data change info.  ; CNconmment:���ݱ仯��Ϣ */
typedef struct {
    HIGV_DC_E Action; /* the type of data change */     /* CNcomment:�仯�������� */
    HI_U16 StartRow; /* the start row of data change */ /* CNcomment:�仯����ʼ�� */
    HI_U16 Rows; /* rows aggregate have data change */ /* CNcomment:�仯�������� */
} HIGV_DCINFO_S;

/* Cell attribute.CNconmment:�ֶ����� */
typedef struct hiHIGV_CELLATTR_S {
    HIGV_DT_E eDataType; /* *< data type ; CNcomment:�������� */
    /* max field str len, value must less than ::HIGV_DB_MAX_FIELD_STR_LEN */
    /* CNcomment:��󳤶ȣ���С����С��::HIGV_DB_MAX_FIELD_STR_LEN */
    HI_U32 MaxSize;
} HIGV_FIELDATTR_S;

/* Row deferable.CNcomment: �����ݴ洢 */
typedef struct hiHIGV_DBROW_S {
    HI_U32 Size; /* data size  , CNcomment:���ݳ��� */
    HI_VOID *pData; /* data pointer , CNcomment:���� */
} HIGV_DBROW_S;

typedef HI_S32 (*GetCountFunc)(HIGV_HANDLE DBSource, HI_U32 *RowCnt);
typedef HI_S32 (*GetRowValueFunc)(HIGV_HANDLE DBSource, HI_U32 Row, HI_U32 Num, HI_VOID *pData, HI_U32 *pRowNum);
typedef HI_S32 (*RegisterDataChangeFunc)(HIGV_HANDLE DBSource, HIGV_HANDLE hADM);
typedef HI_S32 (*UnregisterDataChangeFunc)(HIGV_HANDLE DBSource, HIGV_HANDLE hADM);

typedef struct hiADM_OPT_S {
    HI_U32 DBSource; /* *< data source ; CNcomment:����Դ��ʶ */
    HI_U32 FieldCount; /* *< data source field count ; CNcomment:����Դ���ֶ����� */
    HIGV_FIELDATTR_S *pFieldAttr; /* *< field attribute ; CNcomment:����Դ��ÿ���ֶ����� */
    HI_U32 BufferRows; /* *< rows at buffer ; CNcomment:ϣ���Ļ������� */
    GetCountFunc GetCount; /* * get rows count function. ; CNcomment:��ȡ�����ӿ� */
    GetRowValueFunc GetRowValue;
    /* * get rows value from  appoint rows function. ; CNcomment:��ָ���д���ȡn������ */
    RegisterDataChangeFunc RegisterDataChange;
    /* * Register the function when data change ; CNcomment:ע�����ݱ仯֪ͨ�ӿ� */
    UnregisterDataChangeFunc UnregisterDataChange;
    /* * Unregister the function when data change. ; CNcomment:ȡ�����ݱ仯֪ͨ�ӿ� */
} HIGV_ADMOPT_S;

/*
* brief CNcomment:Creates a abstract data model example. CNcomment:����һ����������ģ��ʵ��
* param[in] dataSource CNcomment: ����Դ��������
* param[out] admHandle  ADM handle.CNcomment: ����ģ�;��
* retval ::HI_SUCCESS
* retval ::HI_ERR_ADM_NULLPTR
* retval ::HI_ERR_ADM_ZEROFIELD
* retval ::HI_ERR_ADM_OUTOFRANGE
* retval ::HI_ENORES
*/
HI_S32 HI_GV_ADM_Create(HIGV_ADMOPT_S *dataSource, HIGV_HANDLE *admHandle);

/*
* brief Create ADM by handle.CNcomment:����ָ����Handle����һ����������ģ��ʵ������XML2Binʹ��
* param[in] dataSource operation of datasouce.CNcomment:����Դ��������
* param[in] admHandle   ADM handle.CNcomment: ����ģ�;��
* retval ::HI_SUCCESS
* retval ::HI_ERR_ADM_NULLPTR
* retval ::HI_ERR_ADM_ZEROFIELD
* retval ::HI_ERR_ADM_OUTOFRANGE
* retval ::HI_ENORES
*/
HI_S32 HI_GV_ADM_CreateByHandle(HIGV_ADMOPT_S *dataSource, HIGV_HANDLE admHandle);

/*
* brief Create DDB by default.CNcomment:����Ĭ�ϵ����ݻ��崴������ģ��
* param[in] dbHandle DB handle.CNcomment:Ĭ�ϵ����ݻ�����
* param[in] fieldCount Field count.CNcomment:�ֶθ���
* param[in] fieldAttr  Field attribute.CNcomment:�ֶ�����
* param[out] admHandle ADM handle.CNcomment:����ģ�;��
* retval ::HI_SUCCESS
* retval ::HI_ERR_ADM_NULLPTR
* retval ::HI_ERR_ADM_ZEROFIELD
* retval ::HI_ERR_ADM_OUTOFRANGE
* retval ::HI_ENORES
*/
HI_S32 HI_GV_ADM_CreateDefault(HIGV_HANDLE dbHandle, HI_U32 fieldCount, HIGV_FIELDATTR_S *fieldAttr,
                               HIGV_HANDLE *admHandle);

/*
* brief Create default DDB by handle.CNcomment:ͨ��ָ����Handle������Ĭ�ϵ����ݻ��崴������ģ��
* param[in] dbHandle  DB handle.CNcomment:Ĭ�ϵ����ݻ�����
* param[in] fieldCount Field count.CNcomment:�ֶθ���
* param[in] fieldAttr  Field attribute.CNcomment:�ֶ�����
* param[in] admHandle ADM handle.CNcomment:����ģ�;��
* retval ::HI_SUCCESS
* retval ::HI_ERR_ADM_NULLPTR
* retval ::HI_ERR_ADM_OUTOFRANGE
* retval ::HI_ENORES
*/
HI_S32 HI_GV_ADM_CreateDefaultByHandle(HIGV_HANDLE dbHandle, HI_U32 fieldCount, HIGV_FIELDATTR_S *fieldAttr,
                                       HIGV_HANDLE admHandle);

/*
* brief Destroy ADM.CNcomment:ɾ��һ������ģ��ʵ��
* param[in] admHandle ADM handle.CNcomment:����ģ�;��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ADM_Destroy(HIGV_HANDLE admHandle);

/*
* brief Bind adm to widget.CNcomment:��һ���ؼ��󶨵�����ģ��
* param[in] widgetHandle Widget handle.CNcomment:�ؼ����
* param[in] admHandle ADM handle.CNcomment:����ģ�;��
* retval ::HI_SUCCESS
*/
HI_S32 HI_GV_ADM_Bind(HIGV_HANDLE widgetHandle, HIGV_HANDLE admHandle);

/*
* brief Unbinde adm to widget.CNcomment:���һ���ؼ�������ģ�͵İ�
* param[in] widgetHandle Widget handle.CNcomment:�ؼ����
* param[in] admHandle ADM handle.CNcomment:����ģ�;��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ADM_UnBind(HIGV_HANDLE widgetHandle, HIGV_HANDLE admHandle);

/*
* brief Get the data type of field. CNcomment:��ȡָ���ֶε���������
* param[in] admHandle ADM handle.CNcomment:����ģ�;��
* param[in] col Column index.CNcomment:�к�
* param[out] fieldAttr Field attribute.CNcomment:�ֶ�����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_ADM_NULLPTR
* retval ::HI_ERR_ADM_OUTOFRANGE
*/
HI_S32 HI_GV_ADM_GetFieldAttr(HIGV_HANDLE admHandle, HI_U32 col, HIGV_FIELDATTR_S *fieldAttr);

/*
* brief Get total row number.CNcomment:��ȡ����������
* param[in] admHandle ADM handle.CNcomment:����ģ�;��
* param[out] count row count.CNcomment:��������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_ADM_NULLPTR
*/
HI_S32 HI_GV_ADM_GetRowCount(HIGV_HANDLE admHandle, HI_U32 *count);

/*
* brief Get the data by row and column index.CNcomment:��ȡָ����ָ���е�����
* param[in] admHandle ADM handle.CNcomment:����ģ�;��
* param[in] row row index.CNcomment:�к�
* param[in] col Column index.CNcomment:�к�
* param[out] data CNcomment:��������
* param[in] len data CNcomment:�������ɵ��ֽ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_ADM_NULLPTR
* retval ::HI_ERR_ADM_OUTOFRANGE
* retval ::HI_ERR_ADM_BUFFSMALL
* retval ::HI_ERR_ADM_GETDATA
*/
HI_S32 HI_GV_ADM_GetCellData(HIGV_HANDLE admHandle, HI_U32 row, HI_U32 col, HI_VOID *data, HI_U32 len);

/*
* brief Get the data of column.CNcomment:��ȡָ����ָ���е����ݣ����ַ�����ʾ
* param[in] admHandle ADM handle. CNcomment:����ģ�;��
* param[in] row row index.CNcomment:�к�
* param[in] col Column index.CNcomment:�к�
* param[out] dataString Data content.CNcomment:��������
* param[in] len dataString buffer size.CNcomment:pDataString�������ɵ��ֽ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_ADM_NULLPTR
* retval ::HI_ERR_ADM_OUTOFRANGE
* retval ::HI_ERR_ADM_BUFFSMALL data
* retval ::HI_ERR_ADM_GETDATA
*/
HI_S32 HI_GV_ADM_GetCellDataString(HIGV_HANDLE admHandle, HI_U32 row, HI_U32 col, HI_CHAR *dataString, HI_U32 len);

/*
* brief Set the callback function when data change.CNcomment:�������ݱ仯�Ļص�����
* param[in] admHandle ADM handle.CNcomment:����ģ�;��
* param[in] customProc notify callback of data change.CNcomment:���ݱ仯֪ͨ�ص�����
* param[in] procOrder callback of time choice.CNcomment:�ص���ʱ��ѡ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ADM_SetDCCallBack(HIGV_HANDLE admHandle, HIGV_MSG_PROC customProc, HIGV_PROCORDER_E procOrder);

/*
* brief Get the DDB handle by ADM handle.CNcomment:����ADM��ȡDDB
* param[in] ADM handle.CNcomment:admHandle  ����ģ�;��
* param[out] ddbHandle DDB handle.CNcomment:DDB���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_ADM_NULLPTR
*/
HI_S32 HI_GV_ADM_GetDDBHandle(HIGV_HANDLE admHandle, HIGV_HANDLE *ddbHandle);

/*
* brief Get column number.CNcomment:��ȡ������
* param[in] admHandle ADM handle.CNcomment:����ģ�;��
* param[out] colNum colunm count.CNcomment:������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_ADM_NULLPTR
*/
HI_S32 HI_GV_ADM_GetColNum(HIGV_HANDLE admHandle, HI_U32 *colNum);

/*
* brief Sync between  ADM and DB. CNcomment:ADM��DBͬ���ӿ�,���ô˽ӿں��Ժ��ȡ�����ݾ��������ݿ�ͬ����
* param[in] ADM handle.CNcomment:admHandle ����ģ�;��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ADM_Sync(HIGV_HANDLE admHandle);

/*
* brief Clear all cache data in the ADM.CNcomment:�������ADM�еĻ�������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_ADM_ClearAllData(HI_VOID);

/* ==== API declaration end ==== */
#ifdef __cplusplus
}
#endif
#endif /* HI_GV_ADM_H */
