/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2009-2019. All rights reserved.
 * Description: Parse moudle API
 * Author: NULL
 * Create: 2009-2-9
 */

#ifndef __HI_PARSE_H__
#define __HI_PARSE_H__

/* * add include here */
#include "hi_type.h"
#include "hi_go.h"
#include "hi_gv.h"

#ifdef __cplusplus
extern "C" {
#endif

#define LOADALLVIEW (-1)
/* ****************************** API declaration **************************** */
/* * addtogroup      Parser */
/* * ��Parser module�� ; ������ģ�顿  */
/* brief Parser init.CNcomment:ģ���ʼ�� */
HI_S32 HI_GV_PARSER_Init(HI_VOID);

/* brief Uninit parser.CNcomment:Parserģ��ȥ��ʼ�� */
HI_VOID HI_GV_PARSER_Deinit(HI_VOID);

/**
* brief  Load HIGVBin file and parse the basic information of
* higvbin.CNcomment:HIGVBin�ļ����أ�ͬʱ������HIGVBin�ļ�������Ϣ \attention \n N/A.CNcomment:��
* param[in] pFile  File name.CNcomment:HIGVBin�ļ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_PARSER_NOINIT  it is not inited.CNcomment:δ��ʼ��
* retval ::HI_ERR_PARSER_FILELOADED  File error.CNcomment:�ļ�����
* retval ::HI_ERR_COMM_FILEOP      File opreration is error.CNcomment:�ļ���������
* retval ::HI_ERR_COMM_NORES  No memory. CNcomment: �ڴ治��
* retval ::HI_ERR_PARSER_VERIFY   CRC ERROR.CNcomment:CRC����
*/
HI_S32 HI_GV_PARSER_LoadFile(const HI_CHAR *pFile);

/* brief Unload higvbin file, release resouce.CNcomment:ж��HIGVBin�ļ����ͷ���Դ */
HI_S32 HI_GV_PARSER_UnLoadFile(HI_VOID);

/*
* brief Release the resouce when load higvbin file, This api will be called at the end of
* load.CNcomment:�ͷ��ļ����ع������������Դ����������ͼ������ɺ���� \attention \n N/A.CNcomment:��
* param N/A.CNcomment:��
*/
HI_S32 HI_GV_PARSER_ReleaseLoadRes(HI_VOID);

/*
* brief Get view number.CNcomment:��ȡ��ͼ����
* param[out] pViewNum View number.CNcomment:��ͼ����
*/
HI_S32 HI_GV_PARSER_GetViewNum(HI_U32 *pViewNum);

/* brief Load the view by name of view.CNcomment:����ͼ��������ͼ������ʱ������������ͼ */
HI_S32 HI_GV_PARSER_LoadViewByName(const HI_CHAR *pViewName);

/**
* brief Load the view by ID of view.CNcomment:����ͼID������ͼ������ʱ������������ͼ
* attention \n
* if(ViewId = LOADALLVIEW),load all view.CNcomment:���ViewIdΪ LOADALLVIEW,�����������ͼ
* param[in] ViewId    View id.CNcomment:��ͼID
* retval ::HI_SUCCESS
* retval ::HI_ERR_PARSER_NOINIT
* retval ::HI_ERR_COMM_LOST   The view is not exit.CNcomment:ָ������ͼ������
* retval ::HI_ERR_PARSER_DATALEN
* retval ::HI_ERR_PARSER_DATAERR
* see:HI_GV_PARSER_LoadViewById
*/
HI_S32 HI_GV_PARSER_LoadViewById(HIGV_HANDLE ViewId);

/* brief Unload the view by ID of view.CNcomment:����ͼIDж����ͼ��������ͼ�ؼ� */
HI_S32 HI_GV_PARSER_UnloadViewByID(HIGV_HANDLE ViewId);

/*
* brief Load the view by index.CNcomment:����ͼ����������ͼ������ʱ������������ͼ����������̰߳�ȫ
* param[in] ViewIndex   View index.CNcomment:��ͼ����
* retval ::HI_SUCCESS
* retval ::HI_ERR_PARSER_NOINIT
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_PARSER_DATALEN
* retval ::HI_ERR_PARSER_DATAERR
*/
HI_S32 HI_GV_PARSER_LoadViewByIndex(HI_U32 ViewIndex);

/*
* brief Delete the view exclude view.CNcomment:ɾ����ָ������ͼ������������ͼ
* param[in] ExcludeViewId  Exclude view that is not deleted.CNcomment:����Ҫɾ����ͼID����
* param[in] ExcludeViewNum  The number of view that not need deleted.CNcomment:����Ҫɾ����ͼ��Ŀ
* retval ::HI_SUCCESS
* retval ::HI_ERR_PARSER_NOINIT
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_PARSER_UnLoadViewExclude(HIGV_HANDLE *ExcludeViewId, HI_U32 ExcludeViewNum);

/*
* brief Get windows handle by view id.CNcomment:ͨ����ͼID ��ȡ��ͼ�����д��ھ��
* param[out] ppWinArray  The window handle array .CNcomment:��ͼ�ڴ���handle ����
* param[out] pWinsNum  The number of view that not need deleted.CNcomment:��ͼ�ڴ�����Ŀ
* retval ::HI_SUCCESS
* retval ::HI_FAILURE
*/
HI_S32 HI_GV_PARSER_ViewGetWinsHandle(HIGV_HANDLE ViewId, HIGV_HANDLE **ppWinsArray, HI_U32 *pWinsNum);

/*
* brief Get the version number.CNcomment:��ȡ�汾��
* param[out] pMainVersion  Main verison.CNcomment:���汾��
* param[out] pSubVersion   Sub version.CNcomment:�Ӱ汾��
* retval ::HI_SUCCESS
* retval ::HI_ERR_PARSER_NOINIT
*/
HI_S32 HI_GV_PARSER_GetVersion(HI_U32 *pMainVersion, HI_U32 *pSubVersion);

/*
* brief Set the evnent function at the STC mode.CNcomment:����STCģʽ���¼������б�
* param[in] pEventProc Event functon.CNcomment: �¼���������ָ��
* param[in] Number      The number of event fucntion.CNcomment:�¼����������к�������
* retval HI_SUCCESS
* retval HI_ERR_PARSER_NOINIT
* retval HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_PARSER_SetWidgetEventFunc(HIGV_MSG_PROC *pEventProc, HI_U32 Number);

/* * ==== API declaration end ==== */
#ifdef __cplusplus
}
#endif
#endif /* __HI_PARSE_H__ */
