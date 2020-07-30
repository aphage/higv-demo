/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2009-2020. All rights reserved.
 * Description: Muti-language API
 * Author: HiMobileCam middleware develop team
 * Create: 2009-2-9
 */

#ifndef HI_GV_LAN_H
#define HI_GV_LAN_H

#ifdef __cplusplus
extern "C" {
#endif

/* language country abbreviation */
/* *he format of languge is <language>_<territory>. The <language> should satisfy iso639-2 and <territory> should
 * satisfy iso3166-1
*/
/*  CNcomment: ���Ը�ʽΪ:    ����_��������:zh_CN��ʾ���Ĵ�½����
* ������������iso639-2,���ҵ��������д����iso3166-1��
* zh_TW��ʾ����̨�������HIGV�ڲ������»�����߲� *
* �����ж����ַ���Ԥ���ұߵ���Ϊ�����û��趨
* ͬ�����ԵĲ�ͬ�����ַ��� ���û�Ҳ�����Զ�������
* �Ѵ��ڵ������У���ͬ����������(����zh_CN�ĸ�ʽ)
*/
#define LAN_CN    "cn"    /* china <CNcomment:�������ģ�Ϊƥ����ǰ�汾��ͬ��LAN_ZN */
#define LAN_ZH    "zh"    /* china <CNcomment::�������ģ���ͬ��LAN_ZN_CN */
#define LAN_ZH_CN "zh_CN" /* china <CNcomment::�������ģ���ͬ��LAN_ZN */
#define LAN_ZH_TW "zh_TW" /* taiwan <CNcomment::��������(�й�̨��) */
#define LAN_ZH_HK "zh_HK" /* hongkong <CNcomment::��������(�й����) */
#define LAN_AR    "ar"    /* arabic <CNcomment::�������� */
#define LAN_CS    "cs"    /* arabic <CNcomment::�ݿ��� */
#define LAN_DA    "da"    /* arabic <CNcomment::������ */
#define LAN_DE    "de"    /* germary <CNcomment::����(�¹�) */
#define LAN_DE_AT "de_AT" /* germary(austria)  <CNcomment::����(�µ���) */
#define LAN_DE_CH "de_CH" /* germary(swiss) <CNcomment::����(��ʿ) */
#define LAN_EL    "el"    /* greece <CNcomment::ϣ���� */
#define LAN_EN    "en"    /* english <CNcomment::Ӣ�ģ���ͬ��en_US */
#define LAN_EN_US "en_US" /* english(america)  <CNcomment::Ӣ��(����)����ͬ��en */
#define LAN_EN_CA "en_CA" /* english(canada)   <CNcomment::Ӣ��(���ô�) */
#define LAN_EN_GB "en_GB" /* english(england)  <CNcomment::Ӣ��(Ӣ��) */
#define LAN_ES    "es"    /* espana  <CNcomment::�������� */
#define LAN_FA    "fa"    /* persia  <CNcomment::��˹��(����) */
#define LAN_FI    "fi"    /* finnish <CNcomment::������ */
#define LAN_FR    "fr"    /* french(france)  <CNcomment::����(����) */
#define LAN_FR_CA "fr_CA" /* french(canada)    <CNcomment: ����(���ô�) */
#define LAN_FR_CH "fr_CH" /* french(swizerland)    <CNcomment: ����(��ʿ) */
#define LAN_IT    "it"    /* italian <CNcomment: �������(�����) */
#define LAN_IT_CH "it_CH" /* italian   <CNcomment: �������(��ʿ) */
#define LAN_HE    "he"    /* hebrew  <CNcomment: ϣ������ */
#define LAN_JA    "ja"    /* japan   <CNcomment: ���� */
#define LAN_KO    "ko"    /* korea   <CNcomment: ������ */
#define LAN_KO_KR "ko_KR" /* corean    <CNcomment: ���� */
#define LAN_NL    "nl"    /* holand  <CNcomment: ������(����) */
#define LAN_NL_BE "nl_BE" /* holand    <CNcomment: ������(����ʱ) */
#define LAN_PT    "pt"    /* portuguese(portugal)    <CNcomment: ��������(������) */
#define LAN_PT_BR "pt_BR" /* portuguese(brazil)    <CNcomment: ��������(����) */
#define LAN_RU    "ru"    /* russain <CNcomment: ���� */
#define LAN_SV    "sv"    /* swedish <CNcomment: ��� */
#define LAN_TH    "th"    /* thai    <CNcomment: ̩�� */
#define LAN_TR    "tr"    /* turkish <CNcomment: �������� */
#define LAN_PO    "po"    /* polski  <CNcomment: ������ */
#define LAN_VN    "vn"    /* vietnam <CNcomment: Խ���� */
#define LAN_HU    "hu"    /* hungary <CNcomment: �������� */
#define LAN_UKR   "ukr"   /* ukraine <CNcomment: �ڿ����� */
#define LAN_RO    "ro"    /* romanian <CNcomment: ���������� */
#define LAN_HR    "hr"    /* croatian <CNcomment: ���޵����� */
#define LAN_SR    "sr"    /* serbian <CNcomment: ����ά���� */
#define LAN_BS    "bs"    /* bosnian <CNcomment: ������ */
#define LAN_MK    "mk"    /* macedonian <CNcomment: ������� */
#define LAN_BG    "bg"    /* bulgarian <CNcomment: ���������� */
#define LAN_ET    "et"    /* estonian <CNcomment: ��ɳ������ */
#define LAN_LV    "lv"    /* latvian <CNcomment: ����ά���� */
#define LAN_LT    "lt"    /* lithuanian <CNcomment: �������� */
#define LAN_IND   "ind"   /* indonesian <CNcomment: ӡ���� */

/* Direction of language   *CNcomment: ���Ե��ı���д���� */
typedef enum {
    HI_LAN_DIR_LTR = 0, /* Left to right   *<CNcomment:����������д������ */
    HI_LAN_DIR_RTL = 1,  /* Right to left   *<CNcomment:����������д������ */
    HI_LAN_DIR_BUTT
} HI_LAN_DIR;

/*
* brief Register the multi-language.CNcomment:ע����Ҫ�л���������Ϣ
* attention:This api should call after the BIN loaded.
* CNcomment:����ע�ắ���ŵ�����BIN�ļ�֮����ã��ڼ�����ͼǰ����
* param[in] resFile CNcomment:��������Ҫ�任ָ�������ַ���
* param[in] fontHandle ��CNcomment:Ӧ�õ�������
* param[in] langId Language ID.CNcomment:���Ա�ʶ
* retval ::HI_SUCCESS Success.CNcomment:�ɹ�
* retval ::HI_ERR_COMM_INVAL Invalid paramater.CNcomment:�������Ϸ�����������Ч����Դ�ļ���Ч���п��е�
* retval ::HI_ERR_COMM_EXIST This language has registered.CNcomment:�������Ѿ�ע��
* retval ::HI_ERR_LANG_INVALID_LOCALE  Locale is not setting.CNcomment:locale����δ����
* retval ::HI_ERR_COMM_FULL  the max language is 16 or The total string count is over
* 128*1024.CNcomment:ע������Գ���ϵͳ�������16����������Դ�ļ���������128*1024�� \retval ::HI_ERR_COMM_NORES
* CNcomment:û����Դ������ϵͳ�ڴ治��
* see: HI_GV_Lan_UnRegister
*/
HI_S32 HI_GV_Lan_Register(const HI_CHAR *resFile, HIGV_HANDLE fontHandle, const HI_CHAR *langId);

/*
* brief Unregister the language.CNcomment:��ע����ע���������Ϣ
* param[in] langId Language ID.CNcomment:langId ���Ա�ʶ
* retval ::HI_SUCCESS Success.CNcomment:�ɹ�
* retval ::HI_ERR_COMM_INVAL Invalid paramater.CNcomment:�������Ϸ����������Ի�δע���
* etval ::HI_ERR_COMM_PAERM Unsupport operation.CNcomment:��֧�ֵĲ�������ע���������Ի�ע����ǰ����
* see :HI_GV_Lan_Register
*/
HI_S32 HI_GV_Lan_UnRegister(const HI_CHAR *langId);

/*
* brief Register the multi-language.CNcomment:���ñ�������
* param[in] langId Language ID.CNcomment:langId ���Ա�ʶ
* retval ::HI_SUCCESS Success.CNcomment:�ɹ�
* retval ::HI_ERR_COMM_INVAL Invalid paramater.CNcomment:�������Ϸ����������Ի�δע���
* retval ::HI_ERR_COMM_PAERM Unsupport operation.CNcomment:��֧�ֵĲ�������ע���������Ի�ע����ǰ����
*/
HI_S32 HI_GV_Lan_SetLocale(const HI_CHAR *locale);

/*
* brief Reigster font info of the language. CNcomment:ע������Ե�������Ϣ
* param[in]  langId  Language ID.CNcomment:���Ա�ʶ
* param[in]  fontHandle Font handle.CNcomment:��Ӧ�õ�������
* retval ::HI_SUCCESS Success.CNcomment:�ɹ�
* retval ::HI_ERR_LOSTInvalid handle. CNcomment:�����Ч
* retval ::HI_ERR_COMM_INVAL Invalid paramater.CNcomment:��Ч����
*/
HI_S32 HI_GV_Lan_FontRegister(const HI_CHAR *langId, HIGV_HANDLE fontHandle);

/*
* brief Change the language.CNcomment:�л���ָ�����ԣ��ɸı����Եķ��ؼ����յ�HIGV_MSG_LANCHNGE��Ϣ
* param[in] langId Language ID.CNcomment:���Ա�ʶ��Ӧ�ó����Լ�ָ���Ͷ��壬����������ע������Լ���
* retval ::HI_SUCCESS Success.CNcomment:�ɹ�
* retval ::HI_ERR_COMM_EMPTY Invalid paramater.CNcomment:������ID��ϵͳ���Ҳ���������û��ע��
* see:::HI_GV_Lan_Register
*/
HI_S32 HI_GV_Lan_Change(const HI_CHAR *langId);

/*
* brief Find current language id.CNcomment:�ҵ���ǰ����ID
* param[in] langId Language ID.CNcomment:���뵱ǰ����ID
* retval ::HI_SUCCESS Success.CNcomment:�ɹ�
* retval ::HI_ERR_COMM_EMPTY The language is not registered.CNcomment:ϵͳû��ע�������
* retval ::HI_ERR_COMM_INVAL Invalid paramater.CNcomment:�������Ϸ�
* see : ::HI_GV_Lan_Register
*/
HI_S32 HI_GV_Lan_GetCurLangID(HI_CHAR **langId);

/*
* brief Get the text by string id.CNcomment:�����ַ���ID��ȡ�õ�ǰ�����ı�
* param[in]  strID  String ID.CNcomment:�ַ���ID
* param[in]  langId  Language ID.CNcomment:����ID
* param[out] str The pointer of string.CNcomment:�ַ���ָ��
* retval ::HI_SUCCESS Success.CNcomment:�ɹ�
* retval ::HI_ERR_COMM_LOST Invalid handle.CNcomment:�����Ч
* retval ::HI_ERR_COMM_INVAL Invalid paramater.CNcomment:��Ч����
*/
HI_S32 HI_GV_Lan_GetLangString(const HI_CHAR *langId, const HI_U32 strID, HI_CHAR **str);

/*
* brief Add string.CNcomment:��ӷ�xml������ַ���
* You should register langugae before adding strings.CNcomment:����ⲿ�ַ�����Ҫ����HI_GV_Lan_Register�ӿ�ע������
* param[in]  langId  Language ID.CNcomment:����ID
* param[in]  strID  String ID.CNcomment:�ַ���ID
* param[out] strId The pointer of string id.CNcomment:�ַ���IDָ��
* retval ::HI_SUCCESS Success.CNcomment:�ɹ�
* retval ::HI_EFULL String item is full.CNcomment:�ַ�������(ֻ֧��1024��)
* retval ::HI_EINVAL Invalid paramater.CNcomment:��Ч����
* see :HI_GV_Lan_Register(...)
*/
HI_S32 HI_GV_AddLanString(const HI_CHAR *langId, HI_CHAR *str, HI_U32 *strId);

/*
* brief Get the dirction of the language.CNcomment:��ȡָ�����Է���
* param[in] direction Direction.CNcomment:���뵱ǰ���Է���
* param[in] langId   Language ID.CNcomment:��ȡ���������
* retval ::HI_SUCCESS Success.CNcomment:�ɹ�
* see : HI_GV_Lan_Register
*/
HI_S32 HI_GV_Lan_GetLangIDDirection(const HI_CHAR *langId, HI_LAN_DIR *direction);

#ifdef __cplusplus
}
#endif
#endif /* HI_GV_LAN_H */
