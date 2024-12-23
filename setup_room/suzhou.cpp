#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"

//     ���ݳ�
#include "../d/suzhou/suzhoucity.h" 
#include "../d/suzhou/suzhou_baodaiqiao.h" 
#include "../d/suzhou/suzhou_bingying.h" 
#include "../d/suzhou/suzhou_canlangting.h" 
#include "../d/suzhou/suzhou_chaguan.h" 
#include "../d/suzhou/suzhou_dangpu.h" 
#include "../d/suzhou/suzhou_datiepu.h" 
#include "../d/suzhou/suzhou_jiudai.h" 
#include "../d/suzhou/suzhou_jubaozhai.h" 
#include "../d/suzhou/suzhou_kedian.h" 
#include "../d/suzhou/suzhou_leitai.h" 
#include "../d/suzhou/suzhou_liuyuan.h" 
#include "../d/suzhou/suzhou_majiu.h" 
#include "../d/suzhou/suzhou_shizilin.h" 
#include "../d/suzhou/suzhou_shuchang.h" 
#include "../d/suzhou/suzhou_shuyuan.h" 
#include "../d/suzhou/suzhou_tingyu.h" 
#include "../d/suzhou/suzhou_wanjing.h" 
#include "../d/suzhou/suzhou_xiyuan.h" 
#include "../d/suzhou/suzhou_xuanmiao.h" 
#include "../d/suzhou/suzhou_yamen.h" 
#include "../d/suzhou/suzhou_yaopu.h" 
#include "../d/suzhou/suzhou_yunhematou.h" 
#include "../d/suzhou/suzhou_zijinan.h"
#include "../d/suzhou/suzhou_dongmen.h"
//���
#include "../d/suzhou/suzhou_bailianchi.h"
#include "../d/suzhou/suzhou_yanyutang.h"
#include "../d/suzhou/suzhou_fengqiao.h"
#include "../d/suzhou/suzhou_zhenshi.h"
#include "../d/suzhou/suzhou_zhishuang.h"
#include "../d/suzhou/suzhou_zhipoxuan.h"
#include "../d/suzhou/suzhou_zhenquting.h"
#include "../d/suzhou/suzhou_zhenniang.h"
#include "../d/suzhou/suzhou_wenmeige.h"
#include "../d/suzhou/suzhou_toumenshan.h"
#include "../d/suzhou/suzhou_tielingguan.h"
#include "../d/suzhou/suzhou_sunwuting.h"
#include "../d/suzhou/suzhou_shijianshi.h"
#include "../d/suzhou/suzhou_road2.h"
#include "../d/suzhou/suzhou_road1.h"
#include "../d/suzhou/suzhou_qianrenshi.h"
#include "../d/suzhou/suzhou_lixuetang.h"
#include "../d/suzhou/suzhou_huqiu.h"
#include "../d/suzhou/suzhou_hehuating.h"
#include "../d/suzhou/suzhou_hanshansi.h"
#include "../d/suzhou/suzhou_hanhanquan.h"
#include "../d/suzhou/suzhou_erxianting.h"
#include "../d/suzhou/suzhou_gumujiaohe.h"
#include "../d/suzhou/suzhou_nanmen.h"

#include "../d/suzhou/suzhounan.h"
#include "../d/suzhou/suzhouzhong.h"
#include "../d/suzhou/suzhoubei.h"

CRoom * Load_SuZhou(string room_name)
{
	CRoom * r = NULL;

	//     ���ݳ�
	if(room_name == "����")
		r = new CRsuzhoucity();
	else if(room_name == "����Ϸ԰��")
		r = new CRSuZhou_xiyuan();
	else if(room_name == "�������")
		r = new CRSuZhou_majiu();
	else if(room_name == "���ݸ���")
		r = new CRSuZhou_yamen();
	else if(room_name == "���ݱ�����")
		r = new CRSuZhou_baodaiqiao();
	else if(room_name == "���ݱ�Ӫ")
		r = new CRSuZhou_bingying();
	else if(room_name == "���ݲ���ͤ")
		r = new CRSuZhou_canlangting();
	else if(room_name == "���ݲ��")
		r = new CRSuZhou_chaguan();
	else if(room_name == "���ݱ��ͼ�")
		r = new CRSuZhou_dangpu();
	else if(room_name == "���ݴ�����")
		r = new CRSuZhou_datiepu();
	else if(room_name == "���ݴ���¥")
		r = new CRSuZhou_jiudain();
	else if(room_name == "���ݾ۱�ի")
		r = new CRSuZhou_jubaozhai();
	else if(room_name == "���ݿ͵�")
		r = new CRSuZhou_kedian();
	else if(room_name == "������̨ǰ�㳡")
		r = new CRSuZhou_leitai();
	else if(room_name == "������԰")
		r = new CRSuZhou_liuyuan();
	else if(room_name == "����ʨ����")
		r = new CRSuZhou_shizilin();
	else if(room_name == "�����鳡")
		r = new CRSuZhou_shuchang();
	else if(room_name == "������Ժ")
		r = new CRSuZhou_shuyuan();
	else if(room_name == "����������")
		r = new CRSuZhou_tingyu();
	else if(room_name == "������ɽׯ")
		r = new CRSuZhou_wanjing();
	else if(room_name == "���������")
		r = new CRSuZhou_xuanmiao();
	else if(room_name == "����������")
		r = new CRSuZhou_yaopu();
	else if(room_name == "�����˺���ͷ")
		r = new CRSuZhou_yunhematou();
	else if(room_name == "�����Ͻ���")
		r = new CRSuZhou_zijinan();
	else if(room_name == "���ݶ���")
		r = new CRSuZhou_dongmen();
	//���
	else if(room_name == "������ˬ��")
		r = new CRSuZhou_zhishuang();
	else if(room_name == "����Ҿ��ָ����")
		r = new CRSuZhou_zhipoxuan();
	else if(room_name == "������ʯ")
		r = new CRSuZhou_zhenshi();
	else if(room_name == "������Ȥͤ")
		r = new CRSuZhou_zhenquting();
	else if(room_name == "���ݰ�����")
		r = new CRSuZhou_bailianchi();
	else if(room_name == "������÷��")
		r = new CRSuZhou_wenmeige();
	else if(room_name == "����ͷ��ɽ")
		r = new CRSuZhou_toumenshan();
	else if(room_name == "���������")
		r = new CRSuZhou_tielingguan();
	else if(room_name == "��������ͤ")
		r = new CRSuZhou_sunwuting();
	else if(room_name == "�����Խ�ʯ")
		r = new CRSuZhou_shijianshi();
	else if(room_name == "������ʯ�ٵ�2")
		r = new CRSuZhou_road2();
	else if(room_name == "������ʯ�ٵ�1")
		r = new CRSuZhou_road1();
	else if(room_name == "����ǧ��ʯ")
		r = new CRSuZhou_qianrenshi();
	else if(room_name == "������ѩ��")
		r = new CRSuZhou_lixuetang();
	else if(room_name == "���ݻ���ɽ")
		r = new CRSuZhou_huqiu();
	else if(room_name == "���ݺɻ���")
		r = new CRSuZhou_hehuating();
	else if(room_name == "���ݺ�ɽ��")
		r = new CRSuZhou_hanshansi();
	else if(room_name == "���ݺ���Ȫ")
		r = new CRSuZhou_hanhanquan();
	else if(room_name == "���ݹ�ľ��ڭ")
		r = new CRSuZhou_gumujiaohe();
	else if(room_name == "���ݷ���")
		r = new CRSuZhou_fengqiao();
	else if(room_name == "���ݶ���ͤ")
		r = new CRSuZhou_erxianting();
	else if(room_name == "����������")
		r = new CRSuZhou_yanyutang();
	else if(room_name == "��������Ĺ")
		r = new CRSuZhou_zhenniang();
	else if(room_name == "��������")
		r = new CRSuZhou_nanmen();
	else if(room_name == "������")
		r = new CRsuzhounan();
	else if(room_name == "������")
		r = new CRsuzhouzhong();
	else if(room_name == "���ݱ�")
		r = new CRsuzhoubei();

	return r;
}