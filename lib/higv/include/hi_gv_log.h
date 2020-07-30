/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: Log module API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_LOG_H
#define HI_GV_LOG_H

#include "hi_gv.h"
#include "hi_gv_errno.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DOMAIN_BUTTON       "Button"
#define DOMAIN_SPIN         "Spin"
#define DOMAIN_SCROLLBOX    "ScrollBox"
#define DOMAIN_EDIT         "Edit"
#define DOMAIN_LABEL        "Label"
#define DOMAIN_PROGRESSBAR  "ProgressBar"
#define DOMAIN_SCROLLTEXT   "ScrollText"
#define DOMAIN_IMAGECIPHER  "ImageCipher"
#define DEMAIN_IMAGE        "Image"
#define DEMAIN_SCROLLBAR    "ScrollBar"
#define DEMAIN_SCROLLGRID   "ScrollGrid"
#define DEMAIN_CLOCK        "Clock"
#define DEMAIN_LISTBOX      "ListBox"
#define DEMAIN_TIMETRACK    "TimeTrack"
#define DEMAIN_TRACKBAR     "TrackBar"
#define DEMAIN_SLIDEUNLOCK  "SlideUnlock"
#define DEMAIN_IPEDIT       "IpEdit"
#define DEMAIN_DAYLIST      "DayList"
#define DEMAIN_CALENDAR     "Calendar"
#define DEMAIN_COMBOBOX     "ComboBox"
#define DEMAIN_VIDEOSHELTER "VideoShelter"
#define DEMAIN_MOVEMONITOR  "MoveMonitor"
#define DEMAIN_TIMERBAR     "TimerBar"
#define DEMAIN_MSGBOX       "MessageBox"
#define DEMAIN_SCROLLVIEW   "ScrollView"
#define DEMAIN_CONTENTBOX   "ContentBox"
#define DEMAIN_IMAGEVIEW    "IMAGEVIEW"
#define DEMAIN_SCALEVIEW    "ScaleView"
#define DEMAIN_CHARTS       "Charts"

#define DOMAIN_WIDGET       "Widget"
#define DOMAIN_MSGM         "Msgm"
#define DOMAIN_MTASK        "MultiTask"
#define DOMAIN_IM           "InputManager"
#define DOMAIN_RESM         "ResManager"
#define DOMAIN_WM           "WndManager"
#define DOMAIN_TIMER        "Timer"
#define DOMAIN_DDB          "DDatabase"
#define DOMAIN_ADM          "Datamodel"
#define DOMAIN_MLAYER       "MultiLayer"
#define DOMAIN_ANIM         "Animation"
#define DOMAIN_VSYNC        "Vsync"
#define DOMAIN_CURSOR       "Cursor"
#define DOMIAN_GESTURE      "Gesture"
#define DOMIAN_KEY          "Key"
#define DOMIAN_PERFORMANCE  "Performance"

typedef enum {
    HIGV_LOG_UNKNOWN = 0,
    HIGV_LOG_DEFAULT, /* only for SetMinPriority() */
    HIGV_LOG_VERBOSE, /* lowest priority */
    HIGV_LOG_DEBUG,   /*  Print debug, info, warring and error log info */
    HIGV_LOG_INFO,    /*  Print info, warring and error log info */
    HIGV_LOG_WARNING, /*  Print warring and error log info */
    HIGV_LOG_ERROR,   /*  Only print error log info */
    HIGV_LOG_FATAL,   /*  Only print fatal log info */
    HIGV_LOG_SILENT,  /* only for SetMinPriority(); must be last */
    HIGV_LOG_BUTT
} HIGV_LOG_LEVEL_E;

/*
* brief Set the verbose level of a domain.CNcomment: ����ģ������LOG�ļ���
* attention:
* The paramater |pDomain| is a string which is module name, The higv system will use module id,
* such as |HIGV_MODID_PARSER_E|, |HIGV_MODID_CORE_E|, |HIGV_MODID_WIDGET_E|. So application
* should not use the module id which will conflict with the higv moudle.
* If |pDomain| is set to HI_NULL, |Level| will be applied to all known domains
* and used as the default verbose level for yet unknown domains.
* param[in] pDomain domain name.CNcomment: ģ������
* param[in] Level new verbose level.CNcomment: LOG�������
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_Log_SetLevel(const HI_CHAR *pDomain, HIGV_LOG_LEVEL_E Level);

/*
* brief Set the verbose level of a domain.CNcomment: ����ģ������LOG�ļ���
* param[in] Get the verbose level from a domain name.CNcomment: ����ģ����������ȡlog�������
* param[out] verbose level
* retval ::HI_SUCCESS
* retval ::HI_FAILUER
*/
HIGV_LOG_LEVEL_E HI_GV_Log_GetLevel(const HI_CHAR *pDomain);

/*
* brief Output the verbose text info of a domain.CNcomment: ���ģ�����־��Ϣ
* param[in] Domain name. CNcomment: ģ������
* param[in] The verbose level. CNcomment: log�������
* param[in] Get the verbose log info.CNcomment: �����־���ı���Ϣ
* retval ::HI_SUCCESS
* retval ::HI_FAILUER
*/
HI_S32 HI_GV_Log_Output(const HI_CHAR *pDomain, HIGV_LOG_LEVEL_E Level, HI_S32 enoError, const HI_CHAR *pFileName,
                        const HI_CHAR *pFunctionName, HI_U32 Line, const HI_CHAR *pText, ...)
__attribute__((format(printf, 7, 8)));

#define HIGV_DEBUG(pDomain, format...)                                                                           \
    HI_GV_Log_Output(pDomain, HIGV_LOG_DEBUG, HI_SUCCESS, (const HI_CHAR *)__FILE__, (const HI_CHAR *)__FUNCTION__, \
        __LINE__, format)
#define HIGV_INFO(pDomain, format...)                                                                           \
    HI_GV_Log_Output(pDomain, HIGV_LOG_INFO, HI_SUCCESS, (const HI_CHAR *)__FILE__, (const HI_CHAR *)__FUNCTION__, \
        __LINE__, format)
#define HIGV_WARNING(pDomain, format...)                                                                           \
    HI_GV_Log_Output(pDomain, HIGV_LOG_WARNING, HI_SUCCESS, (const HI_CHAR *)__FILE__, (const HI_CHAR *)__FUNCTION__, \
        __LINE__, format)
#define HIGV_ERROR(errorNum, pDomain, format...)                                                                 \
    HI_GV_Log_Output(pDomain, HIGV_LOG_ERROR, (errorNum), (const HI_CHAR *)__FILE__, (const HI_CHAR *)__FUNCTION__, \
        __LINE__, format)
#define HIGV_FATAL(errorNum, pDomain, format...)                                                                 \
    HI_GV_Log_Output(pDomain, HIGV_LOG_FATAL, (errorNum), (const HI_CHAR *)__FILE__, (const HI_CHAR *)__FUNCTION__, \
        __LINE__, format)

/*
* Start to record log in asynchronous :�����첽��ӡ��־
* attention:
* After call HI_GV_Mem_Log_Start function; the next info(HI_GV_Mem_Log_Prinf) will be save in memory ,
* the info will not been to printf out immediately until call HI_GV_Mem_Log_Show function.
*/
HI_VOID HI_GV_Mem_Log_Start(HI_VOID);

/* Stop to record log in asynchronous :ֹͣ�첽��ӡ��־ */
HI_VOID HI_GV_Mem_Log_Stop(HI_VOID);

/*
* brief Output the text info in memory.CNcomment: ��¼�첽��־��Ϣ
* param[in] fileName. CNcomment: �ļ�����
* param[in] functionName. CNcomment: ��������
* param[in] index current redording's index.CNcomment: ��ǰ��¼����
* param[in] text Get the verbose log info.CNcomment: �����־���ı���Ϣ
*/
HI_VOID HI_GV_Mem_Log_Prinf(const HI_CHAR *fileName, const HI_CHAR *functionName, HI_U32 index,
                            const HI_CHAR *text);

/* pinrt out the recorded's logs in memory:��ʾ�첽��ӡ��־ */
HI_VOID HI_GV_Mem_Log_Show(HI_VOID);

#ifdef __cplusplus
}
#endif
#endif /* HI_GV_LOG_H */
