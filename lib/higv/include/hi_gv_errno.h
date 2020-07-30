/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: errno API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_ERRNO_H
#define HI_GV_ERRNO_H

#include "hi_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    /* unknown error ; CNcomment:����ԭ��δ֪��ȷ���Ѿ������ǲ����ж������ԭ�� */
    HI_ERR_COMM_UNKNOWN = 1,
    /* other error ; CNcomment:��������֪������ԭ�������Թ��� */
    HI_ERR_COMM_OTHER,
    /* inner error */
    /* CNcomment:�ڲ����������ڲ��������Դ���ĳЩ�ڴ������
    CPU�Բ��I/O����ѧ����������� */
    HI_ERR_COMM_INTER,
    /* version error ; CNcomment:�汾���� */
    HI_ERR_COMM_VERSION,
    /* unsupport function, operation, feature */
    /* CNcomment:��֧�ֵĲ���/����/���ԣ����������汾����
    δ���İ汾����������Ʒ����֧�� */
    HI_ERR_COMM_PAERM = 5,
    /* invalid paramater */
    /* CNcomment:�������󣬰������������������ò����������ò�����һ�»��г�ͻ��
    ���ʵ��ı�š�ͨ���š��豸�š���ָ�롢��ַ��������ȵ� */
    HI_ERR_COMM_INVAL,
    /* not init */
    /* CNcomment:û�г�ʼ����ĳЩ�����������Ƚ��г�ʼ������ܽ��У�����δ���� */
    HI_ERR_COMM_NOTINIT,
    /* not ready */
    /* CNcomment:û��׼���ã�ĳЩ���������ھ߱�һ����������ܽ��У�������Ҫ�Ļ�������ȷ
     ������ȱ���������Դ */
    HI_ERR_COMM_NOTREADY,
    /* no resource ; CNcomment:û����Դ�����������ڴ�ʧ�ܡ�û�п��л�������û�п��ж˿ڡ�û�п���ͨ���� */
    HI_ERR_COMM_NORES,
    /* resouce is  exist ; CNcomment:��Դ�Ѵ��ڣ���������½�����Դ�Ѿ����ڣ������������� */
    HI_ERR_COMM_EXIST = 10,
    /* resouce is not exist ; CNcomment:��Դ�����ڣ�������ĳ����Դ����ַ���Ự������ */
    HI_ERR_COMM_LOST,
    /* no operation ; CNcomment:��Դ���ɲ������������𻵲���ʹ�á�У�����δ����Ԥ�ڵ����á��豸�����ݵȵ� */
    HI_ERR_COMM_NOOP,
    /* busy ; CNcomment:��Դ��æµ�����类���� */
    HI_ERR_COMM_BUSY,
    /* idle ; CNcomment:��Դ������ */
    HI_ERR_COMM_IDLE,
    /* full ; CNcomment:����ĳ���������Ѿ������� */
    HI_ERR_COMM_FULL = 15,
    /* empty ; CNcomment:�գ�ĳ���������ǿյ� */
    HI_ERR_COMM_EMPTY,
    /* underflow ; CNcomment:���磬ĳ�������е������Ѿ��½�������ˮ��֮�� */
    HI_ERR_COMM_UNDERFLOW,
    /* Overflow ; CNcomment:���磬ĳ�������е���������������ˮ��֮�� */
    HI_ERR_COMM_OVERFLOW,
    /* Couldn't access ; CNcomment:Ȩ�޴�������û��Ȩ�ޡ��������ȵ� */
    HI_ERR_COMM_ACCES,
    /* operation is not finish when get interupt ; CNcomment:����δ��ɣ��Ѿ��ж� */
    HI_ERR_COMM_INTR = 20,
    /* Operation is not finish, it will continue ; CNcomment:����δ��ɣ����ڼ��� */
    HI_ERR_COMM_CONTINUE,
    /* Operation is over, there is no any object to opreate ; CNcomment:������ɣ���û�к����Ĳ������� */
    HI_ERR_COMM_OVER,
    /* Operation is not support ; CNcomment:��֧�ֵĲ��� */
    HI_ERR_COMM_UNSUPPORT,
    /* out of bound ; CNcomment:�����߽� */
    HI_ERR_COMM_OUTOFBOUND,
    /* File opreation error ; CNcomment:�ļ��������� */
    HI_ERR_COMM_FILEOP,
    /* Secure function error ; CNcomment:��ȫ��������ֵ���� */
    HI_ERR_COMM_SECURE,
    /* No effect error ; CNcomment:��ҵ������Ӱ��ķ���ֵ ���б���HI_SUCCESS */
    HI_ERR_COMM_NOEFFECT,

    HI_ERR_COMM_END = 28,

    /* Messsage module */
    /* Send message failuer; CNcomment:����ͬ��VTOP��Ϣ���� */
    HI_ERR_MSGM_VTOPMSGSEND = 500,
    /* Create message queue failure ; CNcomment:����VTOP��Ϣ����ʧ�� */
    HI_ERR_MSGM_VTOPMSGCREATE,
    /* Create message server failure ; CNcomment:����VTOP��Ϣ������ʧ�� */
    HI_ERR_MSGM_VTOPMSGSERVER,

    /* APP */
    /* The base of task manager ; CNcomment:�������ģ�������Ļ�׼ֵ */
    /* Tase not stop ; CNcomment:����δֹͣ */
    HI_ERR_TASK_TASKNOTSTOP,

    /* resouce manager */
    /* no memory ; CNcomment:�ڴ治�� */
    HI_ERR_RES_NOMEN,
    /* unknown resource type ; CNcomment:δ֪����Դ���� */
    HI_ERR_RES_UNKNOWRES = 505,
    /* resource is using ; CNcomment:��Դ����ʹ�� */
    HI_ERR_RES_USED,
    /* invalid resouce type ; CNcomment:��Ч����Դ���� */
    HI_ERR_RES_INVRESTYPE,
    /* The pointer is null when save resouce infoamtion ; CNcomment:������Դ��Ϣ��ָ��Ϊ�� */
    HI_ERR_RES_NULL,
    /* Load resouce is failure ; CNcomment:��Դ����ʧ�� */
    HI_ERR_RES_LOAD,
    /* The rource is not loaded ; CNcomment:��Դδ���� */
    HI_ERR_RES_NOLOAD = 510,
    /* Create resource failure ; CNcomment:��Դ����ʧ�ܣ�һ��ֻ����HIGO�ӿ�ʧ�� */
    HI_ERR_RES_CREATE,

    /* Window manager ; CNcomment: ���ڹ��� */
    /* The base of window manager ; CNcomment: ���ڹ���ģ�������Ļ�׼ֵ */
    HI_ERR_WM_CREATE,

    /* widget framework ; CNcomment: �ؼ���� */
    /* Widget type is no exisit ; CNcomment:ָ��widget���Ͳ����� */
    HI_ERR_TYPE_NOEXISIT,
    /* Unsupport multi thread to call ; CNcomment:��֧���������߳��е��� */
    HI_ERR_MULTIPLE_THREAD_CALL,
    /* binded db is not used ; CNcomment:�󶨵�DB������ */
    HI_ERR_WIDGET_INVALDB = 515,
    /* The widget is shown ; CNcomment:Widget����ʾ */
    HI_ERR_WIDGET_SHOW,
    /* the widget is hided ; CNcomment:Widget��hide */
    HI_ERR_WIDGET_HIDE,
    /* the rect is null ; CNcomment:���о���Ϊ�գ����²��ܻ� */
    HI_ERR_INVSIBLE,

    /* DDB */
    /* no field ; CNcomment:û���ֶ����� */
    HI_ERR_DDB_ZEROFIELD,
    /* out of range ; CNcomment: �����߽� */
    HI_ERR_DDB_OUTOFRANGE = 520,
    /* null pointer ; CNcomment:��ָ�� */
    HI_ERR_DDB_NULLPTR,
    /* invalid paramater ; CNcomment:�Ƿ����� */
    HI_ERR_DDB_INVAIDPARA,
    /* Bufffer is too small ; CNcomment:BUFFER̫С */
    HI_ERR_DDB_BUFFSMALL,

    /* ADM */
    /* no filed ; CNcomment:û���ֶ����� */
    HI_ERR_ADM_ZEROFIELD,
    /* Out of range ; CNcomment:�����߽� */
    HI_ERR_ADM_OUTOFRANGE = 525,
    /* Null pointer ; CNcomment:��ָ�� */
    HI_ERR_ADM_NULLPTR,
    /* Invalid paramater ; CNcomment:�Ƿ����� */
    HI_ERR_ADM_INVAIDPARA,
    /* The ADM buffer is too small ; CNcomment:BUFFER̫С */
    HI_ERR_ADM_BUFFSMALL,
    /* Get data failure ; CNcomment:��ȡ����ʧ�� */
    HI_ERR_ADM_GETDATA,
    /* Unknown operation ; CNcomment:���ݿ�δ֪���� */
    HI_ERR_ADM_UNKNOWNOPT = 530,

    /* LANGUAGE */
    /* *Not set locale ; CNcomment:û�����ö����Ե�LOCALE */
    HI_ERR_LANG_INVALID_LOCALE,

    /* �����豸 */
    /* ��IR�豸ʧ�� */
    HI_ERR_IM_OPENIRDEVICE,
    /* ��ȡIRֵʧ�� */
    HI_ERR_IM_GETIRVALUE,
    /* û�ж�Ӧ������� */
    HI_ERR_IM_NOVIRKEY,
    /* �ַ��� */
    /* ��֧�ֵ��ַ��� */
    HI_ERR_CHARSET_UNSUPPORT = 535,
    /* ��Ч���ַ���ת�� */
    HI_ERR_CHARSET_CONVERT,

    /* CNcomment: Parserģ��������׼ֵ  ; CNcomment: Parserģ��������׼ֵ  */
    /* Not init ; CNcomment:δ��ʼ�� */
    HI_ERR_PARSER_NOINIT,
    /* it is inited ; CNcomment: �ѳ�ʼ�� */
    HI_ERR_PARSER_INITED,
    /* Check code is error ; CNcomment: У������� */
    HI_ERR_PARSER_VERIFY = 540,
    /* The identifier is error ; CNcomment: �ļ���ʶ���� */
    HI_ERR_PARSER_MARK,
    /* The file type is error ; CNcomment: �ļ����ʹ��� */
    HI_ERR_PARSER_TYPE,
    /* The length is error ; CNcomment: ���ݳ��ȴ��� */
    HI_ERR_PARSER_DATALEN,
    /* Unsupport ;  CNcomment:��֧�� */
    HI_ERR_PARSER_UNSUPPORT,
    /* The data of higv bin is error ;  CNcomment:HIGVBin�ļ����ݴ��� */
    HI_ERR_PARSER_DATAERR = 545,
    /* The view is not loaded fullly ;  CNcomment:��ͼδȫ������ */
    HI_ERR_PARSER_VIEWNOLOAD,
    /* File is loaded ;  CNcomment:�ļ��Ѽ��� */
    HI_ERR_PARSER_FILELOADED,
    /* File is not loaded ; CNcomment: �ļ�δ���� */
    HI_ERR_PARSER_FILENOTLOAD,
} VResult;

#ifdef __cplusplus
}
#endif
#endif /* HI_GV_ERRNO_H */
