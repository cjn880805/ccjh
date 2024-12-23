#include "stdafx.h"
#include "../server/Room.h"
#include "../server/Char.h"
#include "../std/FightRoom.h"

//��ľ��
#include "../d/heimuya/heimuyacity.h"
#include "../d/heimuya/heimuya_baihu.h"
#include "../d/heimuya/heimuya_baihudating.h"
#include "../d/heimuya/heimuya_chengdedian.h"
#include "../d/heimuya/heimuya_chufang.h"
#include "../d/heimuya/heimuya_chufang1.h"
#include "../d/heimuya/heimuya_fenglei.h"
#include "../d/heimuya/heimuya_fengleizheng.h"
#include "../d/heimuya/heimuya_lingpai.h"
#include "../d/heimuya/heimuya_neishi.h"
#include "../d/heimuya/heimuya_qingtang.h"
#include "../d/heimuya/heimuya_restroom.h"
#include "../d/heimuya/heimuya_shenggu.h"
#include "../d/heimuya/heimuya_xiaoneishi.h"
#include "../d/heimuya/heimuya_xiaoshe.h"
#include "../d/heimuya/heimuya_dukou.h"
#include "../d/heimuya/heimuya_pingdingzhou.h"
#include "../d/heimuya/heimuya_road1.h"
#include "../d/heimuya/heimuya_road2.h"
#include "../d/heimuya/heimuya_road3.h"
#include "../d/heimuya/heimuya_road4.h"

#include "../d/heimuya/heimuya_changlang.h"
#include "../d/heimuya/heimuya_changlang2.h"
#include "../d/heimuya/heimuya_grass.h"
#include "../d/heimuya/heimuya_house1.h"
#include "../d/heimuya/heimuya_houting.h"
#include "../d/heimuya/heimuya_qingdating.h"
#include "../d/heimuya/heimuya_xiaohuayuan.h"

#include "../d/heimuya/heimuya_changtan.h"
#include "../d/heimuya/heimuya_riyueping.h"
#include "../d/heimuya/heimuya_shandao.h"
#include "../d/heimuya/heimuya_shangu.h"
#include "../d/heimuya/heimuya_shidao1.h"
#include "../d/heimuya/heimuya_shidao2.h"
#include "../d/heimuya/heimuya_shijie.h"
#include "../d/heimuya/heimuya_shimen.h"
#include "../d/heimuya/heimuya_xingxingtan.h"
#include "../d/heimuya/heimuya_xiaodao.h"

#include "../d/heimuya/heimuya_tongdao1.h"
#include "../d/heimuya/heimuya_tongdao2.h"
#include "../d/heimuya/heimuya_tongdao3.h"
#include "../d/heimuya/heimuya_tongdao4.h"
#include "../d/heimuya/heimuya_tongdao5.h"
#include "../d/heimuya/heimuya_tongdao6.h"
#include "../d/heimuya/heimuya_huayuan.h"

CRoom * Load_HeiMuYa(string room_name)
{
	CRoom * r = NULL;

	//��ľ��
	if(room_name == "��ľ��")
		r = new CRHeiMuYacity();
	else if(room_name == "��ľ�·����ô���")
		r = new CRHeiMuYa_fenglei();
	else if(room_name == "��ľ�·����ó���")
		r = new CRHeiMuYa_chufang1();
	else if(room_name == "��ľ��С��")
		r = new CRHeiMuYa_xiaoshe();
	else if(room_name == "��ľ��С������")
		r = new CRHeiMuYa_xiaoneishi();
	else if(room_name == "��ľ��ʥ����")
		r = new CRHeiMuYa_shenggu();
	else if(room_name == "��ľ����Ϣ��")
		r = new CRHeiMuYa_restroom();
	else if(room_name == "��ľ��������")
		r = new CRHeiMuYa_qingtang();
	else if(room_name == "��ľ�°׻���")
		r = new CRHeiMuYa_baihu();
	else if(room_name == "��ľ��������")
		r = new CRHeiMuYa_lingpai();
	else if(room_name == "��ľ�·�����")
		r = new CRHeiMuYa_fengleizheng();
	else if(room_name == "��ľ�³���")
		r = new CRHeiMuYa_chufang();
	else if(room_name == "��ľ�³ɵµ�")
		r = new CRHeiMuYa_chengdedian();
	else if(room_name == "��ľ�°׻��ô���")
		r = new CRHeiMuYa_baihudating();
	else if(room_name == "��ľ������")
		r = new CRHeiMuYa_neishi();
	else if(room_name == "��ľ�»���·4")
		r = new CRHeiMuYa_road4();
	else if(room_name == "��ľ�»���·3")
		r = new CRHeiMuYa_road3();
	else if(room_name == "��ľ�»���·2")
		r = new CRHeiMuYa_road2();
	else if(room_name == "��ľ����ʯ��")
		r = new CRHeiMuYa_road1();
	else if(room_name == "��ľ�����Ŷɿ�")
		r = new CRHeiMuYa_dukou();
	else if(room_name == "��ľ��ƽ����")
		r = new CRHeiMuYa_pingdingzhou();

	else if(room_name == "��ľ�³���")
		r = new CRHeiMuYa_changlang();
	else if(room_name == "��ľ��������")
		r = new CRHeiMuYa_qingtang();
	else if(room_name == "��ľ�������ô���")
		r = new CRHeiMuYa_qingdating();
	else if(room_name == "��ľ�º���")
		r = new CRHeiMuYa_houting();
	else if(room_name == "��ľ������")
		r = new CRHeiMuYa_house();
	else if(room_name == "��ľ�²ݵ�")
		r = new CRHeiMuYa_grass();
	else if(room_name == "��ľ�³���2")
		r = new CRHeiMuYa_changlang2();
	else if(room_name == "��ľ��С��԰")
		r = new CRHeiMuYa_xiaohuayuan();

	else if(room_name == "��ľ���ּ�С��")
		r = new CRHeiMuYa_xiaodao();
	else if(room_name == "��ľ������̲")
		r = new CRHeiMuYa_xngxingtan();
	else if(room_name == "��ľ��ʯ��")
		r = new CRHeiMuYa_shimen();
	else if(room_name == "��ľ��ʯ��")
		r = new CRHeiMuYa_shijie();
	else if(room_name == "��ľ��ʯ��2")
		r = new CRHeiMuYa_shidao2();
	else if(room_name == "��ľ�³�̲")
		r = new CRHeiMuYa_changtan();
	else if(room_name == "��ľ��ɽ��")
		r = new CRHeiMuYa_shangu();
	else if(room_name == "��ľ��ɽ��")
		r = new CRHeiMuYa_shandao();
	else if(room_name == "��ľ������ƺ")
		r = new CRHeiMuYa_riyueping();
	else if(room_name == "��ľ��ʯ��1")
		r = new CRHeiMuYa_shidao1();

	else if(room_name == "��ľ�¶�ͨ��1��")
		r = new CRHeiMuYa_tongdao1();
	else if(room_name == "��ľ�¶�ͨ��2��")
		r = new CRHeiMuYa_tongdao2();
	else if(room_name == "��ľ�¶�ͨ��3��")
		r = new CRHeiMuYa_tongdao3();
	else if(room_name == "��ľ�¶�ͨ��4��")
		r = new CRHeiMuYa_tongdao4();
	else if(room_name == "��ľ�¶�ͨ��5��")
		r = new CRHeiMuYa_tongdao5();
	else if(room_name == "��ľ�¶�ͨ��6��")
		r = new CRHeiMuYa_tongdao6();
	else if(room_name == "��ľ�¶�С��԰")
		r = new CRHeiMuYa_huayuan();

	return r;
}