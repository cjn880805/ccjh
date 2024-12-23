//----------Room-------------------------
#include "stdafx.h"
#include "../server/Room.h"
#include "../std/house.h"
#include "../std/void_room.h"
#include "../std/corps.h"
#include "../std/FightRoom.h"
#include "../std/Vendor.h"
#include "../std/Corpse.h"
#include "../server/User.h"
#include "../server/Channel.h"
#include "../combat/Combatd.h"


#include "../d/wiz/jy.h"
#include "../d/wiz/pk.h"
#include "../d/wiz/bw2.h"
#include "../d/wiz/bw3.h"
#include "../d/wiz/bw4.h"
#include "../d/wiz/bw5.h"
#include "../d/wiz/bw6.h"
#include "../d/guanwai/guanwai_juqinggu.h"
#include "../d/guanwai/juqinggusandao.h"
#include "../d/guanwai/juqinggusandao1.h"
#include "../d/guanwai/juqinggusandao2.h"
#include "../d/guanwai/juqinggusandao3.h"
#include "../d/guanwai/juqinggusandao4.h"
#include "../d/guanwai/juqinggusandao5.h"
#include "../d/guanwai/juqinggusandao6.h"
#include "../d/guanwai/juqinggusandao7.h"
#include "../d/guanwai/juqinggusandao8.h"
#include "../d/guanwai/juqinggudating.h"

#include "../std/corps_1.h"
#include "../d/corps/gong/xinyuedian.h"
#include "../d/corps/gong/yuxumen.h"

#define DEFINEROOMLOADER(func) CRoom * func(string room_name)

//ScriptEitor-DeclareAreaBegin
DEFINEROOMLOADER(Load_BaiTuo);
DEFINEROOMLOADER(Load_BeiJing);
DEFINEROOMLOADER(Load_ChangAn);
DEFINEROOMLOADER(Load_ChengDu);
DEFINEROOMLOADER(Load_DaLi);
DEFINEROOMLOADER(Load_EMei);
DEFINEROOMLOADER(Load_FoShan);
DEFINEROOMLOADER(Load_FuZhou);
DEFINEROOMLOADER(Load_GuanWai);
DEFINEROOMLOADER(Load_GuiYun);
DEFINEROOMLOADER(Load_GuMu);
DEFINEROOMLOADER(Load_HangZhou);
DEFINEROOMLOADER(Load_HeiMuYa);
DEFINEROOMLOADER(Load_HengShan);
DEFINEROOMLOADER(Load_HengShan2);
DEFINEROOMLOADER(Load_HengYang);
DEFINEROOMLOADER(Load_HuangHe);
DEFINEROOMLOADER(Load_HuaShan);
DEFINEROOMLOADER(Load_JiaXing);
DEFINEROOMLOADER(Load_LingJiu);
DEFINEROOMLOADER(Load_LingZhou);
DEFINEROOMLOADER(Load_MeiZhuang);
DEFINEROOMLOADER(Load_MingJiao);
DEFINEROOMLOADER(Load_NanYang);
DEFINEROOMLOADER(Load_QingCheng);
DEFINEROOMLOADER(Load_QuanZhou);
DEFINEROOMLOADER(Load_ShaoLin);
DEFINEROOMLOADER(Load_SheShenYa);
DEFINEROOMLOADER(Load_SongShan);
DEFINEROOMLOADER(Load_SuZhou);
DEFINEROOMLOADER(Load_TaiShan);
DEFINEROOMLOADER(Load_TaiWan);
DEFINEROOMLOADER(Load_TaoHuaDao);
DEFINEROOMLOADER(Load_TianLong);
DEFINEROOMLOADER(Load_WanJie);
DEFINEROOMLOADER(Load_WuDang);
DEFINEROOMLOADER(Load_WuGong);
DEFINEROOMLOADER(Load_XiaKeDao);
DEFINEROOMLOADER(Load_XiangYang);
DEFINEROOMLOADER(Load_XiaoYao);
DEFINEROOMLOADER(Load_XingXiu);
DEFINEROOMLOADER(Load_XiYu);
DEFINEROOMLOADER(Load_XueDao);
DEFINEROOMLOADER(Load_XueShan);
DEFINEROOMLOADER(Load_YangZhou);
DEFINEROOMLOADER(Load_YanZiWu);
DEFINEROOMLOADER(Load_ZhongNan);
DEFINEROOMLOADER(Load_ChongYang);
DEFINEROOMLOADER(Load_ShenLong);
//DEFINEROOMLOADER(Load_18hell);
DEFINEROOMLOADER(Load_Yewai);
DEFINEROOMLOADER(Load_CangBao);
DEFINEROOMLOADER(Load_WuLin);
DEFINEROOMLOADER(Load_GaoChang);
//ScriptEditor-DeclareAreaEnd

typedef CRoom * (* LOADROOMFUNC)(string room_name);
typedef map<string, LOADROOMFUNC, less<string> >AREAMAP;
AREAMAP room_loader;

void Init_Room_Mapping()
{
	room_loader["����"] = Load_BaiTuo;
	room_loader["����"] = Load_BeiJing;
	room_loader["����"] = Load_ChangAn;
	room_loader["�ɶ�"] = Load_ChengDu;
	room_loader["����"] = Load_DaLi;
	room_loader["����"] = Load_EMei;
	room_loader["��ɽ"] = Load_FoShan;
	room_loader["����"] = Load_FuZhou;
	room_loader["����"] = Load_GuanWai;
	room_loader["����"] = Load_GuiYun;
	room_loader["��Ĺ"] = Load_GuMu;
	room_loader["����"] = Load_HangZhou;
	room_loader["��ľ"] = Load_HeiMuYa;
	room_loader["��ɽ"] = Load_HengShan;
	room_loader["��ɽ"] = Load_HengShan2;
	room_loader["����"] = Load_HengYang;
	room_loader["�ƺ�"] = Load_HuangHe;
	room_loader["��ɽ"] = Load_HuaShan;
	room_loader["����"] = Load_JiaXing;
	room_loader["����"] = Load_LingJiu;
	room_loader["����"] = Load_LingZhou;
	room_loader["÷ׯ"] = Load_MeiZhuang;
	room_loader["����"] = Load_MingJiao;
	room_loader["����"] = Load_NanYang;
	room_loader["���"] = Load_QingCheng;
	room_loader["Ȫ��"] = Load_QuanZhou;
	room_loader["����"] = Load_ShaoLin;
	room_loader["����"] = Load_SheShenYa;
	room_loader["��ɽ"] = Load_SongShan;
	room_loader["����"] = Load_SuZhou;
	room_loader["̩ɽ"] = Load_TaiShan;
	room_loader["̨��"] = Load_TaiWan;
	room_loader["�һ�"] = Load_TaoHuaDao;
	room_loader["����"] = Load_TianLong;
	room_loader["���"] = Load_WanJie;
	room_loader["�䵱"] = Load_WuDang;
	room_loader["�书"] = Load_WuGong;
	room_loader["����"] = Load_XiaKeDao;
	room_loader["����"] = Load_XiangYang;
	room_loader["��ң"] = Load_XiaoYao;
	room_loader["����"] = Load_XingXiu;
	room_loader["����"] = Load_XiYu;
	room_loader["Ѫ��"] = Load_XueDao;
	room_loader["ѩɽ"] = Load_XueShan;
	room_loader["����"] = Load_YangZhou;
	room_loader["����"] = Load_YanZiWu;
	room_loader["����"] = Load_ZhongNan;
	room_loader["����"] = Load_ChongYang;
	room_loader["����"] = Load_ShenLong;
//	room_loader["����"] = Load_18hell;
	room_loader["Ұ��"] = Load_Yewai;
	room_loader["����"] = Load_CangBao;
	room_loader["����"] = Load_WuLin;
	room_loader["�߲�"] = Load_GaoChang;

}

CRoom * Create_Room(string room_name)
{
	CRoom * r = NULL;
		
	if(room_name == "room_void")
		r = new CRvoid_room();
	else if(room_name == "jy")
		r = new CRwiz_jy();
	else if(room_name == "pk")
		r = new CRwiz_pk();
	else if(room_name == "�����")
		r = new CRGuanWai_jueqinggu();
	else if(room_name == "�����ɽ��")
		r = new CRjuqinggusandao();
	else if(room_name == "�����ɽ��1")
		r = new CRjuqinggusandao1();
	else if(room_name == "�����ɽ��2")
		r = new CRjuqinggusandao2();
	else if(room_name == "�����ɽ��3")
		r = new CRjuqinggusandao3();
	else if(room_name == "�����ɽ��4")
		r = new CRjuqinggusandao4();
	else if(room_name == "�����ɽ��5")
		r = new CRjuqinggusandao5();
	else if(room_name == "�����ɽ��6")
		r = new CRjuqinggusandao6();
	else if(room_name == "�����ɽ��7")
		r = new CRjuqinggusandao7();
	else if(room_name == "�����ɽ��8")
		r = new CRjuqinggusandao8();
	else if(room_name == "����ȴ���")
		r = new CRjuqinggudating();

	else if(room_name == "�������1�㳡")
		r = new CRwiz_bw2();
	else if(room_name == "�������2�㳡")
		r = new CRwiz_bw3();
	else if(room_name == "�������3�㳡")
		r = new CRwiz_bw4();
	else if(room_name == "�������4�㳡")
		r = new CRwiz_bw5();
	else if(room_name == "�������5�㳡")
		r = new CRwiz_bw6();

	else
	{
		string area_name;
		area_name = room_name.substr(0, 4);
	
		AREAMAP::iterator p;
		if((p = room_loader.find(area_name)) != room_loader.end())
		{
			r = ((*p).second)(room_name);
			if(r) r->set("area", area_name.c_str());	//������
		}
	}

	if(! r)
	{
		//from database
		if(room_name.substr(0, 6) == "house_")
		{
			r = new CRhouse();
		}
		else if(room_name.substr(0, 5) == "corp1" && sys_server_id==1)
		{
			r = new CRcorps_1();
		}
		else if(room_name.substr(0, 5) == "corps")
		{
			r = new CRcorps();
		}
		else if(room_name.substr(0, 3) == "g1_" && sys_server_id==1)
		{
			r = new CRxinyuedian();
		}
		else if(room_name.substr(0, 3) == "g2_" && sys_server_id==1)
		{
			r = new CRyuxumen();
		}
		else
		{
			r = new CRoom();
		}
		
		r->set("base_name", room_name.c_str());

		if(! r->Load())
		{
			output_error("û�и÷���%s���滻�ɱ�׼���䡣", room_name.c_str());

			string msg = "fail";
			msg+=room_name;
			r->set_name(msg.c_str());
			r->set("fail_ob", 1);
		}

		r->set("infinity", 1);
	}

	return r;
}



