#include "stdafx.h"
#include "../server/Room.h"

//   ������
#include "../d/yanziwu/yanziwu_bozhou.h"
#include "../d/yanziwu/yanziwu_canheju.h"
#include "../d/yanziwu/yanziwu_chuantang.h"
#include "../d/yanziwu/yanziwu_chufang.h"
#include "../d/yanziwu/yanziwu_cuixia.h"
#include "../d/yanziwu/yanziwu_dannuo.h"
#include "../d/yanziwu/yanziwu_huanshi.h"
#include "../d/yanziwu/yanziwu_huizhen.h"
#include "../d/yanziwu/yanziwu_lanyue.h"
#include "../d/yanziwu/yanziwu_lixiang.h"
#include "../d/yanziwu/yanziwu_longfeng.h"
#include "../d/yanziwu/yanziwu_pindi.h"
#include "../d/yanziwu/yanziwu_qinfang.h"
#include "../d/yanziwu/yanziwu_qingzong.h"
#include "../d/yanziwu/yanziwu_qiushuan.h"
#include "../d/yanziwu/yanziwu_shijian.h"
#include "../d/yanziwu/yanziwu_shuiyun.h"
#include "../d/yanziwu/yanziwu_shuwu.h"
#include "../d/yanziwu/yanziwu_taihu.h"
#include "../d/yanziwu/yanziwu_tingxiang.h"
#include "../d/yanziwu/yanziwu_tingyu.h"
#include "../d/yanziwu/yanziwu_xiaojing.h"
#include "../d/yanziwu/yanziwu_xiaoting.h"
#include "../d/yanziwu/yanziwu_yimen.h"
#include "../d/yanziwu/yanziwu_zhulin.h"
#include "../d/yanziwu/yanziwu_zuijing.h"
#include "../d/yanziwu/yanziwucity.h"
#include "../d/yanziwu/yanziwu_taihudi1.h"
#include "../d/yanziwu/yanziwu_taihudi2.h"
#include "../d/yanziwu/yanziwu_taihudi3.h"
#include "../d/yanziwu/yanziwu_taihudi4.h"
#include "../d/yanziwu/yanziwu_taihudi5.h"
#include "../d/yanziwu/yanziwu_taihudi6.h"

CRoom * Load_YanZiWu(string room_name)
{
	CRoom * r = NULL;

	// ������
	if(room_name == "�����볤��")
		r = new CRyanziwucity();
	else if(room_name == "������׺��¥")
		r = new CRyanziwu_zuijing();
	else if(room_name == "����������")
		r = new CRyanziwu_zhulin();
	else if(room_name == "����������")
		r = new CRyanziwu_yimen();
	else if(room_name == "������������")
		r = new CRyanziwu_xiaoting();
	else if(room_name == "������С��")
		r = new CRyanziwu_xiaojing();
	else if(room_name == "�����������")
		r = new CRyanziwu_tingyu();
	else if(room_name == "����������ˮ�")
		r = new CRyanziwu_tingxiang();
	else if(room_name == "������̫��")
		r = new CRyanziwu_taihu();
	else if(room_name == "������ˮ����")
		r = new CRyanziwu_shuiyun();
	else if(room_name == "�������Խ�̨")
		r = new CRyanziwu_shijian();
	else if(room_name == "��������ˬի")
		r = new CRyanziwu_qiushuan();
	else if(room_name == "��������ڣ")
		r = new CRyanziwu_qingzong();
	else if(room_name == "�������߷���")
		r = new CRyanziwu_qinfang();
	else if(room_name == "������Ʒ��ͥ")
		r = new CRyanziwu_pindi();
	else if(room_name == "������������")
		r = new CRyanziwu_longfeng();
	else if(room_name == "���������¾�")
		r = new CRyanziwu_lanyue();
	else if(room_name == "�����뻹ʩˮ��")
		r = new CRyanziwu_huanshi();
	else if(room_name == "�������Ŵ��")
		r = new CRyanziwu_dannuo();
	else if(room_name == "���������")
		r = new CRyanziwu_chufang();
	else if(room_name == "�����봩��")
		r = new CRyanziwu_chuantang();
	else if(room_name == "������κϾ�")
		r = new CRyanziwu_canheju();
	else if(room_name == "���������԰")
		r = new CRyanziwu_huizhen();
	else if(room_name == "�����벴����")
		r = new CRyanziwu_bozhou();
	else if(room_name == "����������Է")
		r = new CRyanziwu_lixiang();
	else if(room_name == "�������ϼ��")
		r = new CRyanziwu_cuixia();
	else if(room_name == "�����뺲ī����")
		r = new CRyanziwu_shuwu();

	else if(room_name == "������̫������")
		r = new CRyanziwu_taihudi1();
	else if(room_name == "������̫������2")
		r = new CRyanziwu_taihudi2();
	else if(room_name == "������̫������3")
		r = new CRyanziwu_taihudi3();
	else if(room_name == "������̫������4")
		r = new CRyanziwu_taihudi4();
	else if(room_name == "������̫������5")
		r = new CRyanziwu_taihudi5();
	else if(room_name == "������̫������6")
		r = new CRyanziwu_taihudi6();
	return r;
}