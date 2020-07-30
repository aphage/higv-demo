/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: Listbox API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_LIST_H
#define HI_GV_LIST_H
#include "hi_gv_conf.h"
#ifdef HIGV_USE_WIDGET_LISTBOX
/* add include here */
#include "hi_gv_resm.h"

#ifdef __cplusplus
extern "C" {
#endif

/*  Max col number */
#define HIGV_LISTBOX_COL_MAX 20

typedef enum {
    LIST_COLTYPE_TXT = 0,
    /* Text ; CNcomment:  �ı� */
    LIST_COLTYPE_IMG,
    /* Picture ; CNcomment:  ͼƬ */
    LIST_COLTYPE_TXTICONLEFT,
    /* Text and icon,icon on left ; CNcomment:  �ı���ͼ�꣬ͼ������ */
    LIST_COLTYPE_TXTICONRIGHT,
    /* Text and icon,icon on right ; CNcomment:  �ı���ͼ�꣬ͼ������ */
    LIST_COLTYPE_BUTT
} HIGV_LIST_COLTYPE_E;

typedef HI_S32 (*HIGV_LIST_CONV_CB)(HIGV_HANDLE listHandle, HI_U32 col, HI_U32 item, const HI_CHAR *srcStr,
                                    HI_CHAR *dstStr, HI_U32 length);

/* At cell foucs mode, the callback function is used to get the cell width */
/* CNcomment:
* ��Ԫ�񽹵�ģʽ�£��ؼ�������ȡ��Ԫ���ȵĻص�������HIGV�Ὣ������
* Ҫ��ʾ�ĵ�Ԫ����к������δ��룬���ݷ���ֵ0-100�����õ�Ԫ���ȡ�0��
* ʾ���ص�Ԫ��100��ʾ�˵�Ԫ��ռ��һ�С�����ֵ����0-100�ڵĲ��Կ����
* ������
*/
typedef HI_S32 (*HIGV_GET_WIDTH_CB)(HIGV_HANDLE listHandle, HI_U32 item, HI_U32 col);

typedef struct {
    HIGV_LIST_COLTYPE_E Type; /*  Column type ; CNcomment: ������ */
    HI_U32 Width; /*  Column width ; CNcomment: �п� */
    HI_U32 Align; /*  Alignment text ; CNcomment: �ı����뷽ʽ */
    HI_COLOR Fgidx; /*  Font color of column text; CNcomment: ���ı�������ɫ */
    HIGV_HANDLE hImage;  /* Picture surface handle (only support type is LIST_COLTYPE_IMG)
                            CNcomment:  ��Type=LIST_COLTYPE_IMGʱ��Ч����Ҫ��ʾ��ͼƬsurface��� */
    HI_U32 FieldColIdxInDb; /* Column index in db ; CNcomment:  ���������ݿ��е��к� */
    HIGV_LIST_CONV_CB ConvString;  /* function which convert string (only support type is LIST_COLTYPE_TXT)
                                    CNcomment:  �ַ���ת��������ֻ��LIST_COLTYPE_TXT��Ч */
} HIGV_LIST_COLATTR_S;

typedef struct {
    HI_U32 RowNum; /* Row number ; CNcomment:  ����Ŀ */
    HI_U32 ColNum; /* Column number ; CNcomment:  ����Ŀ */
    HI_BOOL NoFrame; /* Is no frame Draw ; CNcomment:  �Ƿ��ޱ߿� */
    HI_BOOL Cyc; /* Is cycle ; CNcomment:  �Ƿ�ѭ������ */
    HI_BOOL IsCellActive; /* Is cell active ; CNcomment:  �Ƿ�Ԫ�񽹵� */
    HI_BOOL AutoSwitchCell; /* If cell active auto suwich active cell ; CNcomment:  ��Ԫ�񽹵��Ƿ��Զ��л����� */
    HI_BOOL Scroll; /* Is scroll ; CNcomment:  �Ƿ������Ԫ����ʾ */
    HI_BOOL Fromleft; /* Is Scroll from left ; CNcomment:  �Ƿ����߿�ʼ���� */
    HI_U32 Timeinterval; /* Time interval ; CNcomment:  ����ʱ���� */
    HI_U32 Step; /* Scroll step ; CNcomment:  ������Ԫ��Ĺ������� */
    HI_U32 ScrollCol; /* If item active,scroll col of item ; CNcomment:  ��Ŀ����ʱ�ɹ����� */
    HIGV_GET_WIDTH_CB GetWidthCb;  /*  Function get cell width from call back ;
                                    CNcomment:  �ؼ��ڲ��ص��û����õ�Ԫ���Ⱥ��� */
    HIGV_LIST_COLATTR_S *pColAttr;  /* List column attributes array ;
                                        CNcomment:  �б��ؼ������Խṹ���飬��ColNum��Ԫ�� */
} HIGV_LIST_ATTRIBUTE_S;

/*
* brief Init the listbox.CNcomment: ListBox�ؼ���ʼ��
* attention ::
* CNcomment: Set the head of listbox.CNcomment: ����listbox�ؼ��ı�ͷ(������������)������
* param[in] listHandle    CNcomment: ListBox�ؼ����
* param[in] rowNum  Row number of dispaly. CNcomment: ��ʾ����
* param[in] colNum   Column number.CNcomment: ����
* param[in] colAttr Column attribute array.CNcomment: ����������(����ColNum��Ԫ��)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_List_Init(HIGV_HANDLE listHandle, HI_U32 rowNum, HI_U32 colNum, const HIGV_LIST_COLATTR_S *colAttr);

/*
* brief Init the listbox.CNcomment: ListBox�ؼ���ʼ��
* attention ::
* CNcomment: Set the head of listbox.CNcomment: ����listbox�ؼ��ı�ͷ(������������)������
* param[in] listHandle    CNcomment: ListBox�ؼ����
* param[in] listAttr  Init listbox attributes. CNcomment: ��ʼ���б������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_List_InitEx(HIGV_HANDLE listHandle, const HIGV_LIST_ATTRIBUTE_S *listAttr);

/*
* brief Get the content of listbox.CNcomment: ��ȡListBox�ؼ����ݸ������
* param[in] listHandle   Listbox handle.CNcomment: ListBox�ؼ����
* param[in] item  Item index. CNcomment: ��
* param[in] col   Column index. CNcomment: ��
* param[out] value Cell's content.CNcomment: ��Ԫ������
* param[in] length Length of pValue.CNcomment: pValue�ַ�������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST CNcomment: �����Ч���߶Ծ��к���û������
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_List_GetCell(HIGV_HANDLE listHandle, HI_U32 item, HI_U32 col, HI_CHAR *value, HI_U32 length);

/*
* brief Set skin fo focus item.CNcomment: ���ý����е�Ƥ��
* param[in] listHandle    Listbox handle. CNcomment: �ؼ����
* param[in] selSkin   The skin of Selected status.CNcomment: �ؼ����ڽ���״̬��ѡ����Ƥ��
* param[in] normSkin  The skin of normal status.CNcomment: �ؼ����ڷǽ���״̬��ѡ����Ƥ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_List_SetRowSkin(HIGV_HANDLE listHandle, HIGV_HANDLE selSkin, HIGV_HANDLE normSkin);

/*
* brief Set selected item of listbox.CNcomment: ���� ListBox��ǰ��Ŀ
* attention ::The api is only support the selected item and apply this api at the init stage.
* CNcomment: �ýӿڽ����õ�ǰѡ����Ŀ����ˢ�¿ؼ�����Ҫ�ڳ�ʼ��Listbox�ؼ�ʱʹ��
* param[in] listHandle Listbox handle. CNcomment: �ؼ����
* param[in] item  Item index.CNcomment: ��Ŀ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_PAERM Foucs moe error.CNcomment: ����ģʽ����
* see :: HI_GV_List_GetSelItem
*/
HI_S32 HI_GV_List_SetSelItem(HIGV_HANDLE listHandle, HI_U32 item);

/*
* brief Get the item of listbox.CNcomment: ��ȡListBox��ǰ��Ŀ
* param[in] listHandle  Listbox handle.CNcomment: �ؼ����
* param[out] item Item index.CNcomment: ��Ŀ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see :: HI_GV_List_SetSelItem
*/
HI_S32 HI_GV_List_GetSelItem(HIGV_HANDLE listHandle, HI_U32 *item);

/*
* brief Get the total item number of listbox.CNcomment: ��ȡListBox��ǰ����������
* param[in]  listHandle  Listbox handle. CNcomment:  �ؼ����
* param[out] itemNum Toal item number.CNcomment: ����Ŀ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_List_GetItemNum(HIGV_HANDLE listHandle, HI_U32 *itemNum);

/*
* brief CNcomment: �Ƿ���ListBox�ؼ�����
* param[in]  listHandle  CNcomment: �ؼ����
* retval ::HI_TRUE
* retval ::HI_FALSE
*/
HI_BOOL HI_GV_List_IsListBoxType(HIGV_HANDLE listHandle);

/*
* brief Set the attribute of listbox.CNcomment: ������������
* param[in]  listHandle  Listbox handle.CNcomment: �ؼ����
* param[in]  horizontalLineHeight  The height of horizontal line.CNcomment: ˮƽ�߸߶�
* param[in]  horizontalLineColor  The color of horizontal line.CNcomment: ˮƽ����ɫ
* param[in]  verticalLineWidth The width of vertical line.CNcomment:  ��ֱ�߿��
* param[in]  verticalLineColor  The color of vertical line.CNcomment: ��ֱ����ɫ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_List_GetGridding
*/
HI_S32 HI_GV_List_SetGridding(HIGV_HANDLE listHandle, HI_U32 horizontalLineHeight,
    HI_COLOR horizontalLineColor, HI_U32 verticalLineWidth, HI_COLOR verticalLineColor);

/*
* brief Get the attribute of listbox.CNcomment: ��ȡ��������
* param[in]  listHandle  Listbox handle.�ؼ����
* param[out]  horizontalLineHeight The height of horizontal line. CNcomment: ˮƽ�߸߶�
* param[out]  horizontalLineColor  The color of horizontal line.CNcomment: ˮƽ����ɫ
* param[out]  verticalLineWidth  The width of vertical line.CNcomment: ��ֱ�߿��
* param[out]  verticalLineColor  The color of vertical line.CNcomment: ��ֱ����ɫ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_List_SetGridding
*/
HI_S32 HI_GV_List_GetGridding(HIGV_HANDLE listHandle, HI_U32 *horizontalLineHeight,
    HI_COLOR *horizontalLineColor, HI_U32 *verticalLineWidth, HI_COLOR *verticalLineColor);

/*
* brief Change the image of column.CNcomment: �ı���ʾ��ͼƬ
* param[in] listHandle Listbox handle.CNcomment: �ؼ����
* param[in] col    Column index.CNcomment: �к�
* param[in] imageHandle Picture handle.CNcomment: ͼƬ����������Ϊ��Ч����������֮ǰ���õ���Ч���
* retval N/A.CNcomment:��
*/
HI_S32 HI_GV_List_ChangeImage(HIGV_HANDLE listHandle, HI_U32 col, HIGV_HANDLE imageHandle);

/*
* brief Get the start index of current page. CNcomment: ��ȡ��ǰ��ʾҳ����������
* param[in] listHandle Listbox handle.CNcomment: �ؼ����
* param[out] item Item.CNcomment: ҳ����ʼ��Ŀ
* retval N/A.CNcomment:��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_List_GetStartItem(HIGV_HANDLE listHandle, HI_U32 *item);

/*
* brief Set the start index of current page. CNcomment: ���õ�ǰ��ʾҳ����������
* param[in] listHandle Listbox handle.CNcomment: �ؼ����
* param[in] item Item.CNcomment: ҳ����ʼ��Ŀ
* retval N/A.CNcomment:��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_List_SetStartItem(HIGV_HANDLE listHandle, HI_U32 item);

/*
* brief Get the index of the end item.CNcomment: ��ȡ��ǰ��ʾҳ��ĩ������
* param[in] listHandle Listbox handle.CNcomment: �ؼ����
* param[out] item Item.CNcomment: ҳ�������Ŀ
* retval N/A.CNcomment:��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_List_GetEndItem(HIGV_HANDLE listHandle, HI_U32 *item);

/*
* brief Set the foucus of listbox.CNcomment: ����ListBox��ǰ���㵥Ԫ��
* attention : The api is only support the selected cell.
* CNcomment: �ýӿڽ����õ�ǰѡ�е�Ԫ�񣬲�ˢ�¿ؼ�
* param[in] listHandle  Listbox handle. CNcomment: ListBox�ؼ����
* param[in] item   Row index.CNcomment: ��
* param[in] col    Column index.CNcomment: ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_PAERM Error at focus mode.CNcomment: ����ģʽ����
* see ::HI_GV_List_GetSelCell
*/
HI_S32 HI_GV_List_SetSelCell(HIGV_HANDLE listHandle, HI_U32 item, HI_U32 col);

/*
* brief Get the position of cell which selected.CNcomment: ��ȡListBox��ǰѡ�е�Ԫ��λ��
* param[in] listHandle  Listbox handle. CNcomment: ListBox�ؼ����
* param[out] item   row index.CNcomment: ��
* param[out] col   Column index. CNcomment: ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_List_SetSelCell
*/
HI_S32 HI_GV_List_GetSelCell(HIGV_HANDLE listHandle, HI_U32 *item, HI_U32 *col);

/*
* brief Get the width of cell at focus mode.CNcomment: ��Ԫ�񽹵�ģʽ�»�ȡ��Ԫ����
* attention : if the cell not display, it will return 0.
* CNcomment: δ��ʾ�ĵ�Ԫ�񷵻�0
* param[in] listHandle  Listbox handle. CNcomment: ListBox�ؼ����
* param[in] item   item index.CNcomment: ��
* param[in] col    Column index.CNcomment: ��
* param[out] pWidth  The pointer of width.CNcomment: ��ȡ��ȵ�ָ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_List_GetCellWidth(HIGV_HANDLE listHandle, HI_U32 item, HI_U32 col, HI_U32 *width);

/*
* brief Set scroll step of text.CNcomment: �����ı��Ĺ�������
* attention : it is only valid at foucs mode.
* CNcomment: ��Ԫ�񽹵�ģʽ����Ч
* param[in] listHandle Listbox handle.CNcomment: �ؼ����
* param[in] step Scroll step(unit:pixel, default:10piexl).CNcomment: ��������(��pixelΪ��λ��Ĭ��Ϊ10pixel)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_PAERM Error at focus mode.CNcomment: ����ģʽ����
*/
HI_S32 HI_GV_List_SetStep(HIGV_HANDLE listHandle, HI_U32 step);

/*
* brief Set the scroll direction of listbox.CNcomment: ���ù�������
* attention : it is only valid at foucs mode.
* CNcomment: ��Ԫ�񽹵�ģʽ����Ч
* param[in] listHandle Listbox handle.CNcomment: �ؼ����
* param[in] fromLeft Scroll direction.CNcomment: ��������Ĭ��HI_FALSE��������,����HI_TRUE��ʾ�������ҹ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_PAERM Error at focus mode.CNcomment: ����ģʽ����
*/
HI_S32 HI_GV_List_SetDirection(HIGV_HANDLE listHandle, HI_BOOL fromLeft);

/*
* brief  Set the status of widget.CNcomment: ���ÿؼ�״̬
* attention : it is only valid at foucs mode.
* CNcomment: ��Ԫ�񽹵�ģʽ����Ч
* param[in] listHandle Listbox handle.CNcomment: �ؼ����
* param[in] scroll Scroll status.CNcomment: ����״̬(TRUEΪ������FALSEΪֹͣ������Ĭ��ΪFALSE)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_PAERM Error at focus mode.CNcomment: ����ģʽ����
*/
HI_S32 HI_GV_List_SetScroll(HIGV_HANDLE listHandle, HI_BOOL scroll);

/*
* brief Set the foreground color of column.CNcomment: ������ǰ����ɫ
* attention :it is only support the column type is LIST_COLTYPE_TXT,
* if col is -1, it will effect the color of text to all column .
* CNcomment: �ı�����ΪLIST_COLTYPE_TXTʱ��Ч,ColΪ-1ʱ����������������ɫ
* param[in] listHandle Listbox handle.CNcomment: �ؼ����
* param[in] col   Column index.CNcomment: ��
* param[in] index Foreground color index.CNcomment: ��ɫֵ
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_PAERM Unsupport the column to set picture.CNcomment: ��֧������ͼƬ��
*/
HI_S32 HI_GV_List_SetColFgIdx(HIGV_HANDLE listHandle, HI_U32 col, HI_COLOR index);

/*
* brief Set the exterior line of listbox.CNcomment: �����Ƿ�����������
* param[in] listHandle Listbox handle.CNcomment: �ؼ����
* param[in] noFrame Is not draw.CNcomment: �Ƿ����(TRUE���棬FALSE�棬Ĭ��ΪFALSE)
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_List_SetNoFrame(HIGV_HANDLE listHandle, HI_BOOL noFrame);

/*
* brief Set the foucs whether cycle.CNcomment: �����Ƿ�ѭ������
* attention :It is only valid at focus mode.
* CNcomment: ��Ŀ����ģʽ����Ч
* param[in] listHandle Listbox handle.CNcomment: �ؼ����
* param[in] cycle Focus cycle.CNcomment: TRUEѭ����FALSE��ѭ����Ĭ��ΪFALSE
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
*/
HI_S32 HI_GV_List_SetCyc(HIGV_HANDLE listHandle, HI_BOOL cycle);

/*
* brief Set scroll param.CNcomment:���û���������ϵ��(Ĭ��Ϊ1.0�����ڵ���1.0)
\attention \n
N/A.CNcomment:��
* param[in] listHandle Listbox handle.    CNcomment:�ؼ����
* param[in] scrollParam scroll index.    CNcomment:����������ϵ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_List_SetScrollParam(HIGV_HANDLE listHandle, HI_FLOAT scrollParam);

/*
* brief Set fling param.CNcomment:������ɨ������ϵ��(Ĭ��Ϊ2�����ڵ���1)
* param[in] listHandle Listbox handle.    CNcomment:�ؼ����
* param[in] flingParam fling index.    CNcomment:��ɨ������ϵ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_List_SetFlingParam(HIGV_HANDLE listHandle, HI_S32 flingParam);

#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_LIST_H */
