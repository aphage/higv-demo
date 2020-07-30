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

/* *Insert position ; CNcomment:插入类型 */
typedef enum {
    DDB_INSERT_PRE = 0,
    /*  Insert before,   CNcomment: 插入该行之前 */
    DDB_INSERT_NEXT,
    /*  Insert after,   CNcomment: 插入该行之后 */
    DDB_INSERT_BUTT
} HIGV_DDBINSERT_E;

/*
* brief Create a DDB.CNcomment:创建一个数据缓存实例
* param[in] fieldCount Field count.CNcomment:字段个数
* param[in] fieldAttr Field attribute.CNcomment:字段属性
* param[out] ddbHandle    DDB handle. CNcomment:数据缓存句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_DDB_Create(HI_U32 fieldCount, const HIGV_FIELDATTR_S *fieldAttr, HIGV_HANDLE *ddbHandle);

/*
* brief Destroy a DDB.CNcomment:删除一个数据缓存实例
* param[in] ddbHandle DDB handle.CNcomment:数据缓存句柄
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_DDB_Destroy(HIGV_HANDLE ddbHandle);

/*
* brief Insert a recoder to the databuffer.CNcomment:向数据缓存中插入一个记录
* param[in] ddbHandle DDB handle.CNcomment:数据缓存句柄
* param[in] row row position.CNcomment:标识插入数据的位置
* param[in] data The pointer of recoder.CNcomment:记录的数据，注意pData->size不能小于各列数据长度之和
* param[in] insert The postion of insert.CNcomment:标识插入数据的位置
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_NULLPTR
* retval ::HI_ERR_DDB_INVAIDPARA
*/
HI_S32 HI_GV_DDB_Insert(HIGV_HANDLE ddbHandle, HI_U32 row, const HIGV_DBROW_S *data, HIGV_DDBINSERT_E insert);

/*
* brief Modify a recoder of data buffer.CNcomment:修改数据缓存中的一个记录
* param[in] ddbHandle DDB handle.CNcomment:数据缓存句柄
* param[in] row row index.CNcomment:要修改的行号
* param[in] pdata Recoder data.CNcomment:记录的数据，注意pData->size不能小于各列数据长度之和
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_NULLPTR
* retval ::HI_ERR_DDB_OUTOFRANGE
*/
HI_S32 HI_GV_DDB_Modify(HIGV_HANDLE ddbHandle, HI_U32 row, const HIGV_DBROW_S *data);

/*
* brief Add a recoder to the tail of data buffer.CNcomment:向数据缓存尾部添加一个记录
* param[in] DDB handle.CNcomment:ddbHandle 数据缓存句柄
* param[in] data Recoder data.CNcomment:记录的数据，注意pData->size不能小于各列数据长度之和
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_NULLPTR
* retval ::HI_ERR_DDB_BUFFSMALL
*/
HI_S32 HI_GV_DDB_Append(HIGV_HANDLE ddbHandle, const HIGV_DBROW_S *data);

/*
* brief Clear the recoder in the data buffer.CNcomment:清除数据缓存中的记录
* param[in] ddbHandle DDB handle.
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_DDB_Clear(HIGV_HANDLE ddbHandle);

/*
* brief Delete a recoder by key.CNcomment:根据key值删除一条记录
* param[in] ddbHandle DDB handle.CNcomment:数据缓存句柄
* param[in] row row index.CNcomment:要操作记录的行号
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_OUTOFRANGE
*/
HI_S32 HI_GV_DDB_Del(HIGV_HANDLE ddbHandle, HI_U32 row);

/*
* brief Get the recoder by row number.CNcomment:根据行号获取一条记录
* param[in] ddbHandle DDB handle.CNcomment:数据缓存句柄
* param[in] row The row of recoder.CNcomment:要操作记录的位置
* param[out] data Recoder data.CNcomment:记录的数据
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_NULLPTR
* retval ::HI_ERR_DDB_OUTOFRANGE
*/
HI_S32 HI_GV_DDB_GetRow(HIGV_HANDLE ddbHandle, HI_U32 row, HIGV_DBROW_S *data);

/*
* brief Get n rows form the DDB.CNcomment:从指定行出获取n行的数据
* param[in] ddbHandle DDB handle.数据缓存句柄
* param[in] row  row index.CNcomment:要获取数据的起始行号
* param[in] num  row number.CNcomment:要获取的总行数
* param[out] data    Data cache.CNcomment:数据缓存
* param[out] rowNum  row number.CNcomment:实际获取的行数
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_NULLPTR
* retval ::HI_ERR_DDB_OUTOFRANGE
* retval ::HI_ERR_DDB_INVAIDPARA
*/
HI_S32 HI_GV_DDB_GetRows(HIGV_HANDLE ddbHandle, HI_U32 row, HI_U32 num, HI_VOID *data, HI_U32 *rowNum);

/*
* brief Get the column index of data.CNcomment:按列号获取数据
* param[in]  ddbHandle DDB handle.CNcomment:数据缓存句柄
* param[in]  row row index.CNcomment:行号
* param[in]  col Column index.CNcomment:列号
* param[out] fieldData CNcomment: 字段buffer
* param[in]  len Buffer size.CNcomment:字段buffer大小
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_NULLPTR
* retval ::HI_ERR_DDB_OUTOFRANGE
* retval ::HI_ERR_DDB_BUFFSMALL
*/
HI_S32 HI_GV_DDB_GetCellData(HIGV_HANDLE ddbHandle, HI_U32 row, HI_U32 col, HI_VOID *fieldData, HI_U32 len);

/*
* brief Set the column index of data.CNcomment:按列号设置数据
* param[in]  ddbHandle DDB handle.CNcomment:数据缓存句柄
* param[in]  row row index.CNcomment:行号
* param[in]  col Column index.CNcomment:列号
* param[in]  fieldData CNcomment: 字段buffer
* param[in]  len Buffer size.CNcomment:字段buffer大小
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_NULLPTR
* retval ::HI_ERR_DDB_OUTOFRANGE
* retval ::HI_ERR_DDB_OUTOFRANGE
*/
HI_S32 HI_GV_DDB_SetCellData(HIGV_HANDLE ddbHandle, HI_U32 row, HI_U32 col, const HI_VOID *fieldData, HI_U32 len);

/*
* brief Get the total row number.CNcomment:获取总行数
* param[in] ddbHandle DDB handle.CNcomment:默认数据缓存句柄
* param[out] rowCount row count.CNcomment:总行数
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_DDB_NULLPTR
*/
HI_S32 HI_GV_DDB_GetRowCount(HIGV_HANDLE ddbHandle, HI_U32 *rowCount);

/*
* brief Register the function when the data change.CNcomment:注册数据变化通知函数
* param[in] ddbHandle DDB handle.CNcomment:默认数据缓存句柄
* param[in] admHandle The object which notify.CNcomment:需要通知的对象
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_DDB_RegisterDataChange(HIGV_HANDLE ddbHandle, HIGV_HANDLE admHandle);

/*
* brief Unregister the function when data change.CNcomment:取消数据变化通知
* param[in] ddbHandle DDB handle.CNcomment:默认数据缓存句柄
* param[in] admHandle The object which notify.CNcomment:需要通知的对象
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_DDB_UnRegisterDataChange(HIGV_HANDLE ddbHandle, HIGV_HANDLE admHandle);

/*
* brief Register callback when data change.CNcomment:数据变化通知使能开关
* param[in] ddbHandle  DDB handle. CNcomment: 数据缓存句柄
* param[in] enable Enable flag. CNcomment:数据变化通知使能开关，HI_TRUE表示使能，HI_FALSE表示去使能
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_DDB_EnableDataChange(HIGV_HANDLE ddbHandle, HI_BOOL enable);

#ifdef __cplusplus
}
#endif
#endif /* HI_GV_DDB_H */
