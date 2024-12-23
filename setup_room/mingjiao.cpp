#include "stdafx.h"
#include "../server/Room.h"
#include "../server/Char.h"
#include "../std/Money.h"

//��������
#include "../d/mingjiao/mingjiao_dadian.h"
#include "../d/mingjiao/mingjiao_daoshe.h"
#include "../d/mingjiao/mingjiao_fangtang.h"
#include "../d/mingjiao/mingjiao_hsqdating.h"
#include "../d/mingjiao/mingjiao_hsqmen.h"
#include "../d/mingjiao/mingjiao_htqdating.h"
#include "../d/mingjiao/mingjiao_htqmen.h"
#include "../d/mingjiao/mingjiao_jmqdating.h"
#include "../d/mingjiao/mingjiao_jmqmen.h"
#include "../d/mingjiao/mingjiao_lhqdating.h"
#include "../d/mingjiao/mingjiao_lhqmen.h"
#include "../d/mingjiao/mingjiao_lhqpaifang.h"
#include "../d/mingjiao/mingjiao_mjdimen.h"
#include "../d/mingjiao/mingjiao_mjfengmen1.h"
#include "../d/mingjiao/mingjiao_mjleimen.h"
#include "../d/mingjiao/mingjiao_mjtianmen.h"
#include "../d/mingjiao/mingjiao_nanshe.h"
#include "../d/mingjiao/mingjiao_nushe.h"
#include "../d/mingjiao/mingjiao_qsdadao1.h"
#include "../d/mingjiao/mingjiao_qsdadao2.h"
#include "../d/mingjiao/mingjiao_qsdadao3.h"
#include "../d/mingjiao/mingjiao_qsdadao4.h"
#include "../d/mingjiao/mingjiao_qsdadao5.h"
#include "../d/mingjiao/mingjiao_qsdadao6.h"
#include "../d/mingjiao/mingjiao_qsdadao7.h"
#include "../d/mingjiao/mingjiao_qsdadao8.h"
#include "../d/mingjiao/mingjiao_qsdadao9.h"
#include "../d/mingjiao/mingjiao_rjqdating.h"
#include "../d/mingjiao/mingjiao_rjqmen.h"
#include "../d/mingjiao/mingjiao_rjyuan.h"
#include "../d/mingjiao/mingjiao_shanmen.h"
#include "../d/mingjiao/mingjiao_simenguangchang.h"
#include "../d/mingjiao/mingjiao_square.h"
#include "../d/mingjiao/mingjiao_sushe.h"
#include "../d/mingjiao/mingjiao_tianweitang.h"
#include "../d/mingjiao/mingjiao_xingtang.h"
#include "../d/mingjiao/mingjiao_xuantianya.h"
#include "../d/mingjiao/mingjiao_zhandao.h"
#include "../d/mingjiao/mingjiao.h"
//�ص�
#include "../d/mjmidao/mingjiao_md1.h"
#include "../d/mjmidao/mingjiao_md2.h"
#include "../d/mjmidao/mingjiao_md3.h"
#include "../d/mjmidao/mingjiao_md4.h"
#include "../d/mjmidao/mingjiao_md5.h"
#include "../d/mjmidao/mingjiao_md6.h"
#include "../d/mjmidao/mingjiao_md7.h"
#include "../d/mjmidao/mingjiao_md8.h"
#include "../d/mjmidao/mingjiao_mishi.h"
//#include "../d/mjmidao/mingjiao_midao.h"

CRoom * Load_MingJiao(string room_name)
{
	CRoom * r = NULL;

	//��������
	if(room_name == "����ջ��")
		r = new CRMingJiao_zhandao();
	else if(room_name == "����������")
		r = new CRMingJiao_xuantianya();
	else if(room_name == "��������")
		r = new CRMingJiao_xingtang();
	else if(room_name == "������΢��")
		r = new CRMingJiao_tianweitang();
	else if(room_name == "������������")
		r = new CRMingJiao_sushe();
	else if(room_name == "���̹㳡")
		r = new CRMingJiao_square();
	else if(room_name == "�������Ź㳡")
		r = new CRMingJiao_simenguangchang();
	else if(room_name == "����ɽ��")
		r = new CRMingJiao_shanmen();
	else if(room_name == "���̴�Ժ")
		r = new CRMingJiao_rjyuan();
	else if(room_name == "������������")
		r = new CRMingJiao_rjqdating();
	else if(room_name == "������ʯ���9")
		r = new CRMingJiao_qsdadao9();
	else if(room_name == "������ʯ���8")
		r = new CRMingJiao_qsdadao8();
	else if(room_name == "������ʯ���7")
		r = new CRMingJiao_qsdadao7();
	else if(room_name == "������ʯ���6")
		r = new CRMingJiao_qsdadao6();
	else if(room_name == "������ʯ���5")
		r = new CRMingJiao_qsdadao5();
	else if(room_name == "������ʯ���4")
		r = new CRMingJiao_qsdadao4();
	else if(room_name == "������ʯ���3")
		r = new CRMingJiao_qsdadao3();
	else if(room_name == "������ʯ���2")
		r = new CRMingJiao_qsdadao2();
	else if(room_name == "������ʯ���1")
		r = new CRMingJiao_qsdadao1();
	else if(room_name == "���̵���Ů��")
		r = new CRMingJiao_nushe();
	else if(room_name == "������������")
		r = new CRMingJiao_nanshe();
	else if(room_name == "�����һ����Ʒ�")
		r = new CRMingJiao_lhqpaifang();
	else if(room_name == "�����һ������")
		r = new CRMingJiao_lhqdating();
	else if(room_name == "���̾�ľ�����")
		r = new CRMingJiao_jmqdating();
	else if(room_name == "��������ɽ��")
		r = new CRMingJiaocity();
	else if(room_name == "���̺�ˮ�����")
		r = new CRMingJiao_hsqdating();
	else if(room_name == "���̷���")
		r = new CRMingJiao_fangtang();
	else if(room_name == "���̵�������")
		r = new CRMingJiao_daoshe();
	else if(room_name == "���̴��")
		r = new CRMingJiao_dadian();
	else if(room_name == "���̺��������")
		r = new CRMingJiao_htqdating();

	else if(room_name == "�����ص�1")
		r = new CRMingJiao_md1();
	else if(room_name == "�����ص�2")
		r = new CRMingJiao_md2();
	else if(room_name == "�����ص�3")
		r = new CRMingJiao_md3();
	else if(room_name == "�����ص�4")
		r = new CRMingJiao_md4();
	else if(room_name == "�����ص�5")
		r = new CRMingJiao_md5();
	else if(room_name == "�����ص�6")
		r = new CRMingJiao_md6();
	else if(room_name == "�����ص�7")
		r = new CRMingJiao_md7();
	else if(room_name == "�����ص�8")
		r = new CRMingJiao_md8();
	else if(room_name == "��������")
		r = new CRMingJiao_mishi();

	return r;
}