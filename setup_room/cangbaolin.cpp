#include "stdafx.h"
#include "../std/FightRoom.h"
#include "../std/mf.h"


//�ر�-����ɽ
#include "../d/cangbaolin/CangBaoLin_choubiyi.h"
#include "../d/cangbaolin/CangBaoLin_dongmenchi.h"
#include "../d/cangbaolin/CangBaoLin_dulangu.h"
#include "../d/cangbaolin/CangBaoLin_elvxiaodao.h"
#include "../d/cangbaolin/CangBaoLin_fengyuedong.h"
#include "../d/cangbaolin/CangBaoLin_hengmen.h"
#include "../d/cangbaolin/CangBaoLin_huanshagu.h"
#include "../d/cangbaolin/CangBaoLin_jianxialin.h"
#include "../d/cangbaolin/CangBaoLin_jinsedong.h"
#include "../d/cangbaolin/CangBaoLin_liouyinxiaodao.h"
#include "../d/cangbaolin/CangBaoLin_longchi.h"
#include "../d/cangbaolin/CangBaoLin_mzeshanjiao.h"
#include "../d/cangbaolin/CangBaoLin_mzszhufeng.h"
#include "../d/cangbaolin/CangBaoLin_shuosudong.h"
#include "../d/cangbaolin/CangBaoLin_wanchougu.h"
#include "../d/cangbaolin/CangBaoLin_wanqinggu.h"
#include "../d/cangbaolin/CangBaoLin_wanqiou.h"
#include "../d/cangbaolin/CangBaoLin_weiyufeng.h"
#include "../d/cangbaolin/CangBaoLin_xiangfeilin.h"
#include "../d/cangbaolin/CangBaoLin_xiangsiting.h"
#include "../d/cangbaolin/CangBaoLin_xiyanglou.h"
#include "../d/cangbaolin/CangBaoLin_yaoci.h"
#include "../d/cangbaolin/CangBaoLin_yimeigu.h"
#include "../d/cangbaolin/CangBaoLin_yirenge.h"
#include "../d/cangbaolin/CangBaoLin_zenglioutai.h"


CRoom * Load_CangBao(string room_name)
{
	CRoom * r = NULL;

	// �ر���
	if(room_name == "����ɽɽ��")
		r = new CRCangBao_mzshanjiao();
	else if(room_name == "����ɽ����̨")
		r = new CRCangBao_zenglioutai();
	else if(room_name == "����ɽ����ˮ��")
		r = new CRCangBao_yirenge();
	else if(room_name == "����ɽ��÷��")
		r = new CRCangBao_yimeigu();
	else if(room_name == "����ɽ����")
		r = new CRCangBao_yaoci();
	else if(room_name == "����ɽϦ��¥")
		r = new CRCangBao_xiyanglou();
	else if(room_name == "����ɽ��˼ͤ")
		r = new CRCangBao_xiangsiting();
	else if(room_name == "����ɽ������")
		r = new CRCangBao_xiangfeilin();
	else if(room_name == "����ɽ΢���")
		r = new CRCangBao_weiyufeng();
	else if(room_name == "����ɽ����")
		r = new CRCangBao_wanqiou();
	else if(room_name == "����ɽ�����")
		r = new CRCangBao_wanqinggu();
	else if(room_name == "����ɽ����")
		r = new CRCangBao_wanchougu();
	else if(room_name == "����ɽ˶��")
		r = new CRCangBao_shuosudong();
	else if(room_name == "����ɽ����")
		r = new CRCangBao_mzszhufeng();
	else if(room_name == "����ɽ����")
		r = new CRCangBao_longchi();
	else if(room_name == "����ɽ��ݺС��")
		r = new CRCangBao_liouyinxiaodao();
	else if(room_name == "����ɽ��ɪ��")
		r = new CRCangBao_jinsedong();
	else if(room_name == "����ɽ������")
		r = new CRCangBao_jianxialin();
	else if(room_name == "����ɽ�ɴ��")
		r = new CRCangBao_huanshagu();
	else if(room_name == "����ɽ����")
		r = new CRCangBao_hengmen();
	else if(room_name == "����ɽ���¶�")
		r = new CRCangBao_fengyuedong();
	else if(room_name == "����ɽ����С��")
		r = new CRCangBao_elvxiaodao();
	else if(room_name == "����ɽ������")
		r = new CRCangBao_dulangu();		
	else if(room_name == "����ɽ����֮��")
		r = new CRCangBao_dongmenchi();
	else if(room_name == "����ɽ�����")
		r = new CRCangBao_choubiyi();	
	return r;
}





