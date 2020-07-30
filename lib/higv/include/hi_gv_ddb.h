/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: ddb API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_DDB_H
#define HI_GV_DDB_H

#include "hi_type.h"
#include "hi_gv_adm.h"

#ifdef __cplusplus
extern "C" {
#endif

/* *Insert position ; CNcomment:�������� */
typedef enum {
    DDB_INSERT_PRE = 0,
    /*  Insert before,   CNcomment: �������֮ǰ */
    DDB_INSERT_NEXT,
    /*  Insert after,   CNcomment: �������֮�� */
    DDB_INSERT_BUTT
} HIGV_DDBINSERT_E;

/*
* brief Create a DDB.CNcomment:����һ�����ݻ���ʵ��
* param[in] fieldCount Field count.CNcomment:�ֶθ���
* param[in] fieldAttr Field attribute.CNcomment:�ֶ�����
* param[out] ddbHandle    DDB handle. CNcomment:���ݻ�����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_DDB_Create(HI_U32 fieldCount, const HIGV_FIELDATTR_S *fieldAttr, HIGV_HANDLE *ddbHandle);

/*
* brief Destroy a DDB.CNcomment:ɾ��һ�����ݻ���ʵ��
* param[in] ddbHandle DDB handle.CNcomment:���ݻ�����
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_DDB_Destroy(HIGV_HANDLE ddbHandle);

/*
* brief Insert a recoder to the databuffer.CNcomment:�����ݻ����в���һ����¼
* param[in] ddbHandle DDB handle.CNcomment:���ݻ�����
* param[in] row row position.CNcomment:��ʶ�������ݵ�λ��
* param[in] data The pointer of recoder.CNcomment:��¼�����ݣ�ע��pData->size����С�ڸ������ݳ���֮��
* param[in] insert The postion of insert.CNcomment:��ʶ�������ݵ�λ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_NULLPTR
* retval ::HI_ERR_DDB_INVAIDPARA
*/
HI_S32 HI_GV_DDB_Insert(HIGV_HANDLE ddbHandle, HI_U32 row, const HIGV_DBROW_S *data, HIGV_DDBINSERT_E insert);

/*
* brief Modify a recoder of data buffer.CNcomment:�޸����ݻ����е�һ����¼
* param[in] ddbHandle DDB handle.CNcomment:���ݻ�����
* param[in] row row index.CNcomment:Ҫ�޸ĵ��к�
* param[in] pdata Recoder data.CNcomment:��¼�����ݣ�ע��pData->size����С�ڸ������ݳ���֮��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_NULLPTR
* retval ::HI_ERR_DDB_OUTOFRANGE
*/
HI_S32 HI_GV_DDB_Modify(HIGV_HANDLE ddbHandle, HI_U32 row, const HIGV_DBROW_S *data);

/*
* brief Add a recoder to the tail of data buffer.CNcomment:�����ݻ���β�����һ����¼
* param[in] DDB handle.CNcomment:ddbHandle ���ݻ�����
* param[in] data Recoder data.CNcomment:��¼�����ݣ�ע��pData->size����С�ڸ������ݳ���֮��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_NULLPTR
* retval ::HI_ERR_DDB_BUFFSMALL
*/
HI_S32 HI_GV_DDB_Append(HIGV_HANDLE ddbHandle, const HIGV_DBROW_S *data);

/*
* brief Clear the recoder in the data buffer.CNcomment:������ݻ����еļ�¼
* param[in] ddbHandle DDB handle.
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_DDB_Clear(HIGV_HANDLE ddbHandle);

/*
* brief Delete a recoder by key.CNcomment:����keyֵɾ��һ����¼
* param[in] ddbHandle DDB handle.CNcomment:���ݻ�����
* param[in] row row index.CNcomment:Ҫ������¼���к�
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_OUTOFRANGE
*/
HI_S32 HI_GV_DDB_Del(HIGV_HANDLE ddbHandle, HI_U32 row);

/*
* brief Get the recoder by row number.CNcomment:�����кŻ�ȡһ����¼
* param[in] ddbHandle DDB handle.CNcomment:���ݻ�����
* param[in] row The row of recoder.CNcomment:Ҫ������¼��λ��
* param[out] data Recoder data.CNcomment:��¼������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_NULLPTR
* retval ::HI_ERR_DDB_OUTOFRANGE
*/
HI_S32 HI_GV_DDB_GetRow(HIGV_HANDLE ddbHandle, HI_U32 row, HIGV_DBROW_S *data);

/*
* brief Get n rows form the DDB.CNcomment:��ָ���г���ȡn�е�����
* param[in] ddbHandle DDB handle.���ݻ�����
* param[in] row  row index.CNcomment:Ҫ��ȡ���ݵ���ʼ�к�
* param[in] num  row number.CNcomment:Ҫ��ȡ��������
* param[out] data    Data cache.CNcomment:���ݻ���
* param[out] rowNum  row number.CNcomment:ʵ�ʻ�ȡ������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_NULLPTR
* retval ::HI_ERR_DDB_OUTOFRANGE
* retval ::HI_ERR_DDB_INVAIDPARA
*/
HI_S32 HI_GV_DDB_GetRows(HIGV_HANDLE ddbHandle, HI_U32 row, HI_U32 num, HI_VOID *data, HI_U32 *rowNum);

/*
* brief Get the column index of data.CNcomment:���кŻ�ȡ����
* param[in]  ddbHandle DDB handle.CNcomment:���ݻ�����
* param[in]  row row index.CNcomment:�к�
* param[in]  col Column index.CNcomment:�к�
* param[out] fieldData CNcomment: �ֶ�buffer
* param[in]  len Buffer size.CNcomment:�ֶ�buffer��С
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_NULLPTR
* retval ::HI_ERR_DDB_OUTOFRANGE
* retval ::HI_ERR_DDB_BUFFSMALL
*/
HI_S32 HI_GV_DDB_GetCellData(HIGV_HANDLE ddbHandle, HI_U32 row, HI_U32 col, HI_VOID *fieldData, HI_U32 len);

/*
* brief Set the column index of data.CNcomment:���к���������
* param[in]  ddbHandle DDB handle.CNcomment:���ݻ�����
* param[in]  row row index.CNcomment:�к�
* param[in]  col Column index.CNcomment:�к�
* param[in]  fieldData CNcomment: �ֶ�buffer
* param[in]  len Buffer size.CNcomment:�ֶ�buffer��С
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_NULLPTR
* retval ::HI_ERR_DDB_OUTOFRANGE
* retval ::HI_ERR_DDB_OUTOFRANGE
*/
HI_S32 HI_GV_DDB_SetCellData(HIGV_HANDLE ddbHandle, HI_U32 row, HI_U32 col, const HI_VOID *fieldData, HI_U32 len);

/*
* brief Get the total row number.CNcomment:��ȡ������
* param[in] ddbHandle DDB handle.CNcomment:Ĭ�����ݻ�����
* param[out] rowCount row count.CNcomment:������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_NULLPTR
*/
HI_S32 HI_GV_DDB_GetRowCount(HIGV_HANDLE ddbHandle, HI_U32 *rowCount);

/*
* brief Register the function when the data change.CNcomment:ע�����ݱ仯֪ͨ����
* param[in] ddbHandle DDB handle.CNcomment:Ĭ�����ݻ�����
* param[in] admHandle The object which notify.CNcomment:��Ҫ֪ͨ�Ķ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_DDB_RegisterDataChange(HIGV_HANDLE ddbHandle, HIGV_HANDLE admHandle);

/*
* brief Unregister the function when data change.CNcomment:ȡ�����ݱ仯֪ͨ
* param[in] ddbHandle DDB handle.CNcomment:Ĭ�����ݻ�����
* param[in] admHandle The object which notify.CNcomment:��Ҫ֪ͨ�Ķ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_DDB_UnRegisterDataChange(HIGV_HANDLE ddbHandle, HIGV_HANDLE admHandle);

/*
* brief Register callback when data change.CNcomment:���ݱ仯֪ͨʹ�ܿ���
* param[in] ddbHandle  DDB handle. CNcomment: ���ݻ�����
* param[in] enable Enable flag. CNcomment:���ݱ仯֪ͨʹ�ܿ��أ�HI_TRUE��ʾʹ�ܣ�HI_FALSE��ʾȥʹ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_DDB_EnableDataChange(HIGV_HANDLE ddbHandle, HI_BOOL enable);

#ifdef __cplusplus
}
#endif
#endif /* HI_GV_DDB_H */
