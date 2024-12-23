#include "stdafx.h"
#include "../server/Room.h"
#include "../server/Char.h"

//血刀门
#include "../d/xuedao/xuedao_beilu.h"
#include "../d/xuedao/xuedao_nroad1.h"
#include "../d/xuedao/xuedao_nroad2.h"
#include "../d/xuedao/xuedao_nroad3.h"
#include "../d/xuedao/xuedao_nroad4.h"
#include "../d/xuedao/xuedao_nroad5.h"
#include "../d/xuedao/xuedao_nroad6.h"
#include "../d/xuedao/xuedao_nroad7.h"
#include "../d/xuedao/xuedao_shandong1.h"
#include "../d/xuedao/xuedao_shandong2.h"
#include "../d/xuedao/xuedao_sroad1.h"
#include "../d/xuedao/xuedao_sroad2.h"
#include "../d/xuedao/xuedao_sroad3.h"
#include "../d/xuedao/xuedao_sroad4.h"
#include "../d/xuedao/xuedao_sroad5.h"
#include "../d/xuedao/xuedao_sroad6.h"
#include "../d/xuedao/xuedao_sroad7.h"
#include "../d/xuedao/xuedao_sroad8.h"
#include "../d/xuedao/xuedao_sroad9.h"
#include "../d/xuedao/xuedao_wangyougu.h"
#include "../d/xuedao/xuedaomen.h"

#include "../d/xuedao/xuedao_guenchao.h"
#include "../d/xuedao/xuedao_kedian.h"
#include "../d/xuedao/xuedao_shanjiao.h"
#include "../d/xuedao/xuedao_shenghu.h"
#include "../d/xuedao/xuedao_tulu1.h"
#include "../d/xuedao/xuedao_tulu2.h"
#include "../d/xuedao/xuedao_tulu3.h"
#include "../d/xuedao/xuedao_xiaolu1.h"
#include "../d/xuedao/xuedao_xiaolu2.h"
#include "../d/xuedao/xuedao_xiaolu3.h"
#include "../d/xuedao/xuedao_xiaolu4.h"

CRoom * Load_XueDao(string room_name)
{
	CRoom * r = NULL;

	//血刀门
	if(room_name == "血刀门忘忧谷")
		r = new CRXueDao_wangyougu();
	else if(room_name == "血刀门大雪山山谷9")
		r = new CRXueDao_sroad9();
	else if(room_name == "血刀门大雪山山谷8")
		r = new CRXueDao_sroad8();
	else if(room_name == "血刀门大雪山口7")
		r = new CRXueDao_sroad7();
	else if(room_name == "血刀门大雪山口6")
		r = new CRXueDao_sroad6();
	else if(room_name == "血刀门大雪山")
		r = new CRXueDao_sroad5();
	else if(room_name == "血刀门大雪山口4")
		r = new CRXueDao_sroad4();
	else if(room_name == "血刀门雪山路3")
		r = new CRXueDao_sroad3();
	else if(room_name == "血刀门雪山路2")
		r = new CRXueDao_sroad2();
	else if(room_name == "血刀门雪山路1")
		r = new CRXueDao_sroad1();
	else if(room_name == "血刀门山洞2")
		r = new CRXueDao_shandong2();
	else if(room_name == "血刀门山洞1")
		r = new CRXueDao_shandong1();
	else if(room_name == "血刀门山路7")
		r = new CRXueDao_nroad7();
	else if(room_name == "血刀门山路6")
		r = new CRXueDao_nroad6();
	else if(room_name == "血刀门山路5")
		r = new CRXueDao_nroad5();
	else if(room_name == "血刀门山路4")
		r = new CRXueDao_nroad4();
	else if(room_name == "血刀门雪山北麓")
		r = new CRXueDao_beilu();
	else if(room_name == "血刀门山路2")
		r = new CRXueDao_nroad2();
	else if(room_name == "血刀门山路1")
		r = new CRXueDao_nroad1();
	else if(room_name == "血刀门山路3")
		r = new CRXueDao_nroad3();
	else if(room_name == "血刀门")
		r = new CRXueDao();
	else if(room_name == "血刀门小路4")
		r = new CRXueDao_xiaolu4();
	else if(room_name == "血刀门小路3")
		r = new CRXueDao_xiaolu3();
	else if(room_name == "血刀门小路2")
		r = new CRXueDao_xiaolu2();
	else if(room_name == "血刀门棍巢")
		r = new CRXueDao_guenchao();
	else if(room_name == "血刀门土路3")
		r = new CRXueDao_tulu3();
	else if(room_name == "血刀门土路2")
		r = new CRXueDao_tulu2();
	else if(room_name == "血刀门土路1")
		r = new CRXueDao_tulu1();
	else if(room_name == "血刀门圣湖")
		r = new CRXueDao_shenghu();
	else if(room_name == "血刀门山脚")
		r = new CRXueDao_shanjiao();
	else if(room_name == "血刀门客店")
		r = new CRXueDao_kedian();
	else if(room_name == "血刀门小路1")
		r = new CRXueDao_xiaolu1();

	return r;
}