#include "stdafx.h"
#include "../std/RField.h"
#include "../std/resident.h"
#include "../std/FightRoom.h"

//   ������
#include "../d/beijing/beijing_aobai.h" 
#include "../d/beijing/beijing_dangpu.h" 
#include "../d/beijing/beijing_datiepu.h" 
#include "../d/beijing/beijing_dongchangdamen.h" 
#include "../d/beijing/beijing_duchang.h" 
#include "../d/beijing/beijing_gaoshengchaguan.h" 
#include "../d/beijing/beijing_guancaidian.h" 
#include "../d/beijing/beijing_huanggongzhengmen.h" 
#include "../d/beijing/beijing_huichuntang.h" 
#include "../d/beijing/beijing_kangfu.h" 
#include "../d/beijing/beijing_kedian1.h"
#include "../d/beijing/beijing_kedian2.h"
#include "../d/beijing/beijing_mianguan.h" 
#include "../d/beijing/beijing_qianzhuang.h" 
#include "../d/beijing/beijing_quanjudejiulou.h" 
#include "../d/beijing/beijing_shuyuan.h" 
#include "../d/beijing/beijing_tuzai.h" 
#include "../d/beijing/beijing_wenmiao.h" 
#include "../d/beijing/beijing_xichangdamen.h" 
#include "../d/beijing/beijing_xiyuan.h"
#include "../d/beijing/beijing_yihongyuan.h" 
#include "../d/beijing/beijing_yihongyuan2.h" 
#include "../d/beijing/beijing_zahuopu.h" 
#include "../d/beijing/beijingcity.h"
#include "../d/beijing/beijing_haigang.h"
#include "../d/beijing/beijing_road1.h"
#include "../d/beijing/beijing_road10.h"
#include "../d/beijing/beijing_road2.h"
#include "../d/beijing/beijing_road3.h"
#include "../d/beijing/beijing_road4.h"
#include "../d/beijing/beijing_road5.h"
#include "../d/beijing/beijing_road6.h"
#include "../d/beijing/beijing_road7.h"
#include "../d/beijing/beijing_road8.h"
#include "../d/beijing/beijing_road9.h"
#include "../d/beijing/beijing_ruzhou.h"

#include "../d/beijing/beijing_dongbei.h"
#include "../d/beijing/beijing_dongnan.h"
#include "../d/beijing/beijing_xibei.h"
#include "../d/beijing/beijing_xinan.h"

#include "../d/beijing/beijing_zhangfu.h"
#include "../d/beijing/beijing_zhangfudating.h"
#include "../d/beijing/beijing_zhangfuhouyuan.h"
#include "../d/beijing/beijing_zhangfuneitang.h"
#include "../d/beijing/beijing_zhangfushufang.h"
#include "../d/beijing/beijing_maofu.h"
#include "../d/beijing/beijing_maofudating.h"
#include "../d/beijing/beijing_maofuhouyuan.h"
#include "../d/beijing/beijing_maofuneitang.h"
#include "../d/beijing/beijing_maofushufang.h"
#include "../d/beijing/beijing_wanbaolou.h"
#include "../d/beijing/beijing_shueilao.h"

//�����������񳡾�
#include "../d/beijing/was/beijing_waswai.h"
#include "../d/beijing/was/beijing_was.h"
#include "../d/beijing/was/beijing_was1.h"
#include "../d/beijing/was/beijing_was2.h"
#include "../d/beijing/was/beijing_was3.h"
#include "../d/beijing/was/beijing_was4.h"
#include "../d/beijing/was/beijing_was5.h"
#include "../d/beijing/was/beijing_was6.h"

CRoom * Load_BeiJing(string room_name)
{
	CRoom * r = NULL;

	//   ������
	if(room_name == "�����ʳ�")
		r = new CRbeijingcity();
	else if(room_name == "��������")
		r = new CRBeiJing_aobai();
	else if(room_name == "�����ӻ���")
		r = new CRBeiJing_zahuopu();
	else if(room_name == "��������Ժ")
		r = new CRBeiJing_yihongyuan();
	else if(room_name == "��������Ժ��¥")
		r = new CRBeiJing_yihongyuan2();
	else if(room_name == "��������ϷԺ")
		r = new CRBeiJing_xiyuan();
	else if(room_name == "������������")
		r = new CRBeiJing_xichangdamen();
	else if(room_name == "��������")
		r = new CRBeiJing_wenmiao();
	else if(room_name == "�������׳�")
		r = new CRBeiJing_tuzai();
	else if(room_name == "������Ժ")
		r = new CRBeiJing_shuyuan();
	else if(room_name == "����ȫ�۵¾�¥")
		r = new CRBeiJing_quanjudejiulou();
	else if(room_name == "����Ǯׯ")
		r = new CRBeiJing_qianzhuang();
	else if(room_name == "�������")
		r = new CRBeiJing_mianguan();
	else if(room_name == "�����͵�1")
		r = new CRBeiJing_kedian1();
	else if(room_name == "�����͵�2")
		r = new CRBeiJing_kedian2();
	else if(room_name == "��������")
		r = new CRBeiJing_kangfu();
	else if(room_name == "�����ش���ҩ��")
		r = new CRBeiJing_huichuntang();
	else if(room_name == "�����ʹ�����")
		r = new CRBeiJing_huanggongzhengmen();
	else if(room_name == "�����ײĵ�")
		r = new CRBeiJing_guancaidian();
	else if(room_name == "�����������")
		r = new CRBeiJing_gaoshengchaguan();
	else if(room_name == "�����ĳ�")
		r = new CRBeiJing_duchang();
	else if(room_name == "������������")
		r = new CRBeiJing_dongchangdamen();
	else if(room_name == "����������")
		r = new CRBeiJing_datiepu();
	else if(room_name == "��������")
		r = new CRBeiJing_dangpu();
	else if(room_name == "�������ݳ�")
		r = new CRBeiJing_ruzhou();
	else if(room_name == "���������9")
		r = new CRBeiJing_road9();
	else if(room_name == "���������8")
		r = new CRBeiJing_road8();
	else if(room_name == "���������7")
		r = new CRBeiJing_road7();
	else if(room_name == "���������6")
		r = new CRBeiJing_road6();
	else if(room_name == "���������5")
		r = new CRBeiJing_road5();
	else if(room_name == "���������4")
		r = new CRBeiJing_road4();
	else if(room_name == "���������3")
		r = new CRBeiJing_road3();
	else if(room_name == "����������")
		r = new CRBeiJing_haigang();
	else if(room_name == "����С��10")
		r = new CRBeiJing_road10();
	else if(room_name == "���������1")
		r = new CRBeiJing_road1();
	else if(room_name == "���������2")
		r = new CRBeiJing_road2();
		
	else if(room_name == "��������")
		r = new CRbeijing_dongbei();
	else if(room_name == "��������")
		r = new CRbeijing_dongnan();
	else if(room_name == "��������")
		r = new CRbeijing_xibei();
	else if(room_name == "��������")
		r = new CRbeijing_xinan();

	else if(room_name == "�����Ÿ�")
		r = new CRBeiJing_zhangfu();
	else if(room_name == "�����Ÿ�����")
		r = new CRBeiJing_zhangfudating();
	else if(room_name == "�����Ÿ���Ժ")
		r = new CRBeiJing_zhangfuhouyuan();
	else if(room_name == "�����Ÿ�����")
		r = new CRBeiJing_zhangfuneitang();
	else if(room_name == "�����Ÿ��鷿")
		r = new CRBeiJing_zhangfushufang();
		else if(room_name == "����ë��")
		r = new CRBeiJing_maofu();
	else if(room_name == "����ë������")
		r = new CRBeiJing_maofudating();
	else if(room_name == "����ë����Ժ")
		r = new CRBeiJing_maofuhouyuan();
	else if(room_name == "����ë������")
		r = new CRBeiJing_maofuneitang();
	else if(room_name == "����ë���鷿")
		r = new CRBeiJing_maofushufang();
	else if(room_name == "������¥")
		r = new CRBeiJing_wanbaolou();
	else if(room_name == "������¥ˮ��")
		r = new CRBeiJing_shueilao();

	//�����������񳡾�
	else if(room_name == "����������")
		r = new CRbeijing_waswai();
	else if(room_name == "��������")
		r = new CRbeijing_was();
	else if(room_name == "�������µ�һ��")
		r = new CRbeijing_was1();
	else if(room_name == "�������µڶ���")
		r = new CRbeijing_was2();
	else if(room_name == "�������µ�����")
		r = new CRbeijing_was3();
	else if(room_name == "�������µ��Ĳ�")
		r = new CRbeijing_was4();
	else if(room_name == "�������µ����")
		r = new CRbeijing_was5();
	else if(room_name == "�������µ�����")
		r = new CRbeijing_was6();


	return r;
}