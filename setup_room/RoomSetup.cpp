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
	room_loader["白驼"] = Load_BaiTuo;
	room_loader["北京"] = Load_BeiJing;
	room_loader["长安"] = Load_ChangAn;
	room_loader["成都"] = Load_ChengDu;
	room_loader["大理"] = Load_DaLi;
	room_loader["峨嵋"] = Load_EMei;
	room_loader["佛山"] = Load_FoShan;
	room_loader["福州"] = Load_FuZhou;
	room_loader["关外"] = Load_GuanWai;
	room_loader["归云"] = Load_GuiYun;
	room_loader["古墓"] = Load_GuMu;
	room_loader["杭州"] = Load_HangZhou;
	room_loader["黑木"] = Load_HeiMuYa;
	room_loader["衡山"] = Load_HengShan;
	room_loader["恒山"] = Load_HengShan2;
	room_loader["衡阳"] = Load_HengYang;
	room_loader["黄河"] = Load_HuangHe;
	room_loader["华山"] = Load_HuaShan;
	room_loader["嘉兴"] = Load_JiaXing;
	room_loader["灵鹫"] = Load_LingJiu;
	room_loader["灵州"] = Load_LingZhou;
	room_loader["梅庄"] = Load_MeiZhuang;
	room_loader["明教"] = Load_MingJiao;
	room_loader["南阳"] = Load_NanYang;
	room_loader["青城"] = Load_QingCheng;
	room_loader["泉州"] = Load_QuanZhou;
	room_loader["少林"] = Load_ShaoLin;
	room_loader["舍身"] = Load_SheShenYa;
	room_loader["嵩山"] = Load_SongShan;
	room_loader["苏州"] = Load_SuZhou;
	room_loader["泰山"] = Load_TaiShan;
	room_loader["台湾"] = Load_TaiWan;
	room_loader["桃花"] = Load_TaoHuaDao;
	room_loader["天龙"] = Load_TianLong;
	room_loader["万劫"] = Load_WanJie;
	room_loader["武当"] = Load_WuDang;
	room_loader["武功"] = Load_WuGong;
	room_loader["侠客"] = Load_XiaKeDao;
	room_loader["襄阳"] = Load_XiangYang;
	room_loader["逍遥"] = Load_XiaoYao;
	room_loader["星宿"] = Load_XingXiu;
	room_loader["西域"] = Load_XiYu;
	room_loader["血刀"] = Load_XueDao;
	room_loader["雪山"] = Load_XueShan;
	room_loader["扬州"] = Load_YangZhou;
	room_loader["燕子"] = Load_YanZiWu;
	room_loader["终南"] = Load_ZhongNan;
	room_loader["重阳"] = Load_ChongYang;
	room_loader["神龙"] = Load_ShenLong;
//	room_loader["地狱"] = Load_18hell;
	room_loader["野外"] = Load_Yewai;
	room_loader["梦泽"] = Load_CangBao;
	room_loader["武陵"] = Load_WuLin;
	room_loader["高昌"] = Load_GaoChang;

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
	else if(room_name == "绝情谷")
		r = new CRGuanWai_jueqinggu();
	else if(room_name == "绝情谷山道")
		r = new CRjuqinggusandao();
	else if(room_name == "绝情谷山道1")
		r = new CRjuqinggusandao1();
	else if(room_name == "绝情谷山道2")
		r = new CRjuqinggusandao2();
	else if(room_name == "绝情谷山道3")
		r = new CRjuqinggusandao3();
	else if(room_name == "绝情谷山道4")
		r = new CRjuqinggusandao4();
	else if(room_name == "绝情谷山道5")
		r = new CRjuqinggusandao5();
	else if(room_name == "绝情谷山道6")
		r = new CRjuqinggusandao6();
	else if(room_name == "绝情谷山道7")
		r = new CRjuqinggusandao7();
	else if(room_name == "绝情谷山道8")
		r = new CRjuqinggusandao8();
	else if(room_name == "绝情谷大厅")
		r = new CRjuqinggudating();

	else if(room_name == "武道场第1广场")
		r = new CRwiz_bw2();
	else if(room_name == "武道场第2广场")
		r = new CRwiz_bw3();
	else if(room_name == "武道场第3广场")
		r = new CRwiz_bw4();
	else if(room_name == "武道场第4广场")
		r = new CRwiz_bw5();
	else if(room_name == "武道场第5广场")
		r = new CRwiz_bw6();

	else
	{
		string area_name;
		area_name = room_name.substr(0, 4);
	
		AREAMAP::iterator p;
		if((p = room_loader.find(area_name)) != room_loader.end())
		{
			r = ((*p).second)(room_name);
			if(r) r->set("area", area_name.c_str());	//区域名
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
			output_error("没有该房间%s，替换成标准房间。", room_name.c_str());

			string msg = "fail";
			msg+=room_name;
			r->set_name(msg.c_str());
			r->set("fail_ob", 1);
		}

		r->set("infinity", 1);
	}

	return r;
}



