#include "stdafx.h"
#include "../server/Room.h"


//������
#include "../d/tianlongsi/tianlongsi_banruotai.h"
#include "../d/tianlongsi/tianlongsi_baodian.h"
#include "../d/tianlongsi/tianlongsi_cibeiyuan.h"
#include "../d/tianlongsi/tianlongsi_damen.h"
#include "../d/tianlongsi/tianlongsi_doumugong.h"
#include "../d/tianlongsi/tianlongsi_doushuai.h"
#include "../d/tianlongsi/tianlongsi_huangtianmen.h"
#include "../d/tianlongsi/tianlongsi_munitang.h"
#include "../d/tianlongsi/tianlongsi_qingxinge.h"
#include "../d/tianlongsi/tianlongsi_ruihemen.h"
#include "../d/tianlongsi/tianlongsi_sangwugong.h"
#include "../d/tianlongsi/tianlongsi_ta1.h"
#include "../d/tianlongsi/tianlongsi_ta2.h"
#include "../d/tianlongsi/tianlongsi_talin.h"
#include "../d/tianlongsi/tianlongsi_ta3.h"
#include "../d/tianlongsi/tianlongsi_wujingge.h"
#include "../d/tianlongsi/tianlongsi_wulege.h"
#include "../d/tianlongsi/tianlongsi_wuwoge.h"
#include "../d/tianlongsi/tianlongsi_wuwujing.h"
#include "../d/tianlongsi/tianlongsi_xianghemen.h"
#include "../d/tianlongsi/tianlongsi_yaotai.h"
#include "../d/tianlongsi/tianlongsi_yuhuayuan.h"
#include "../d/tianlongsi/tianlongsi_wuchangge.h"
#include "../d/tianlongsi/tianlongsi_tading.h"

CRoom * Load_TianLong(string room_name)
{
	CRoom * r = NULL;

	//������
	if(room_name == "�������껨Ժ")
		r = new CRTianLongSi_yuhuayuan();
	else if(room_name == "�������嶼��̨")
		r = new CRTianLongSi_yaotai();
	else if(room_name == "�����������")
		r = new CRTianLongSi_xianghemen();
	else if(room_name == "���������޾�")
		r = new CRTianLongSi_wuwujing();
	else if(room_name == "���������Ҹ�")
		r = new CRTianLongSi_wuwoge();
	else if(room_name == "���������ָ�")
		r = new CRTianLongSi_wulege();
	else if(room_name == "�������޾���")
		r = new CRTianLongSi_wujingge();
	else if(room_name == "�������޳���")
		r = new CRTianLongSi_wuchangge();
	else if(room_name == "����������")
		r = new CRTianLongSi_talin();
	else if(room_name == "������������3")
		r = new CRTianLongSi_ta3();
	else if(room_name == "������������2")
		r = new CRTianLongSi_ta2();
	else if(room_name == "������������1")
		r = new CRTianLongSi_ta1();
	else if(room_name == "���������޹�")
		r = new CRTianLongSi_sangwugong();
	else if(room_name == "�����������")
		r = new CRTianLongSi_ruihemen();
	else if(room_name == "���������ĸ�")
		r = new CRTianLongSi_qingxinge();
	else if(room_name == "������Ĳ����")
		r = new CRTianLongSi_munitang();
	else if(room_name == "�����»�����")
		r = new CRTianLongSi_huangtianmen();
	else if(room_name == "�����°���̨")
		r = new CRTianLongSi_banruotai();
	else if(room_name == "�����¶�ĸ��")
		r = new CRTianLongSi_doumugong();
	else if(room_name == "�����´���")
		r = new CRTianLongSi_damen();
	else if(room_name == "�����´ȱ�Ժ")
		r = new CRTianLongSi_cibeiyuan();
	else if(room_name == "�����³�ʥ����")
		r = new CRTianLongSi_baodian();
	else if(room_name == "�����¶��ʴ�ʿԺ")
		r = new CRTianLongSi_doushuai();
	else if(room_name == "����������")
		r = new CRTianLongSi_tading();

	return r;
}