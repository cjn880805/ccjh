#include "stdafx.h"
#include "../server/Room.h"

//   侠客岛
#include "../d/xiakedao/xiakedao_dating.h"
#include "../d/xiakedao/xiakedao_dongmen.h"
#include "../d/xiakedao/xiakedao_haitan.h"
#include "../d/xiakedao/xiakedao_motianya.h"
#include "../d/xiakedao/xiakedao_mtroad.h"
#include "../d/xiakedao/xiakedao_mtroad1.h"
#include "../d/xiakedao/xiakedao_mtxiaowu.h"
#include "../d/xiakedao/xiakedao_mtyadi.h"
#include "../d/xiakedao/xiakedao_pubu.h"
#include "../d/xiakedao/xiakedao_road1.h"
#include "../d/xiakedao/xiakedao_road6.h"
#include "../d/xiakedao/xiakedao_road7.h"
#include "../d/xiakedao/xiakedao_road8.h"
#include "../d/xiakedao/xiakedao_shanmen.h"
#include "../d/xiakedao/xiakedao_shidong1.h"
#include "../d/xiakedao/xiakedao_shidong2.h"
#include "../d/xiakedao/xiakedao_shidong6.h"
#include "../d/xiakedao/xiakedao_shidong7.h"
#include "../d/xiakedao/xiakedao_shidong8.h"
#include "../d/xiakedao/xiakedao_shishi.h"
#include "../d/xiakedao/xiakedao_shufang.h"
#include "../d/xiakedao/xiakedao_wangyun.h"
#include "../d/xiakedao/xiakedao_wuqiku.h"
#include "../d/xiakedao/xiakedao_xiaodian.h"
#include "../d/xiakedao/xiakedao_xiuxis.h"
#include "../d/xiakedao/xiakedao_yingbin.h"
#include "../d/xiakedao/xiakedao_yongdao.h"

CRoom * Load_XiaKeDao(string room_name)
{
	CRoom * r = NULL;

	//侠客岛
	if(room_name == "侠客岛海滩")
		r = new CRXiaKeDao_haitan();
	else if(room_name == "侠客岛甬道")
		r = new CRXiaKeDao_yongdao();
	else if(room_name == "侠客岛迎宾馆")
		r = new CRXiaKeDao_yingbin();
	else if(room_name == "侠客岛休息室")
		r = new CRXiaKeDao_xiuxis();
	else if(room_name == "侠客岛小吃店")
		r = new CRXiaKeDao_xiaodian();
	else if(room_name == "侠客岛武器库")
		r = new CRXiaKeDao_wuqiku();
	else if(room_name == "侠客岛望云台")
		r = new CRXiaKeDao_wangyun();
	else if(room_name == "侠客岛书房")
		r = new CRXiaKeDao_shufang();
	else if(room_name == "侠客岛石室")
		r = new CRXiaKeDao_shishi();
	else if(room_name == "侠客岛石洞8")
		r = new CRXiaKeDao_shidong8();
	else if(room_name == "侠客岛石洞7")
		r = new CRXiaKeDao_shidong7();
	else if(room_name == "侠客岛石洞6")
		r = new CRXiaKeDao_shidong6();
	else if(room_name == "侠客岛石洞2")
		r = new CRXiaKeDao_shidong2();
	else if(room_name == "侠客岛石洞1")
		r = new CRXiaKeDao_shidong1();
	else if(room_name == "侠客岛山门")
		r = new CRXiaKeDao_shanmen();
	else if(room_name == "侠客岛一线天")
		r = new CRXiaKeDao_road8();
	else if(room_name == "侠客岛夹鳖石")
		r = new CRXiaKeDao_road7();
	else if(room_name == "侠客岛山路6")
		r = new CRXiaKeDao_road6();
	else if(room_name == "侠客岛山路1")
		r = new CRXiaKeDao_road1();
	else if(room_name == "侠客岛瀑布")
		r = new CRXiaKeDao_pubu();
	else if(room_name == "侠客岛大厅")
		r = new CRXiaKeDao_dating();
	else if(room_name == "侠客岛木屋")
		r = new CRXiaKeDao_mtxiaowu();
	else if(room_name == "侠客岛树林")
		r = new CRXiaKeDao_mtroad1();
	else if(room_name == "侠客岛山路")
		r = new CRXiaKeDao_mtroad();
	else if(room_name == "侠客岛摩天崖")
		r = new CRXiaKeDao_motianya();
	else if(room_name == "侠客岛洞门")
		r = new CRXiaKeDao_dongmen();
	else if(room_name == "侠客岛崖底")
		r = new CRXiaKeDao_mtyadi();

	return r;
}