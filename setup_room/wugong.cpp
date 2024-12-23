#include "stdafx.h"
#include "../server/Room.h"

//   武功
#include "../d/wugong_room.h"
#include "../d/wugong/wugongcity.h"
#include "../d/wugong/wugong_xiaomiao.h"
#include "../d/wugong/wugong_minju2.h"
#include "../d/wugong/wugong_minju1.h"
#include "../d/wugong/wugong_kedian1.h"
#include "../d/wugong/wugong_kedian2.h"
#include "../d/wugong/wugong_fu_cemen.h"
#include "../d/wugong/wugong_jiulou1.h"
#include "../d/wugong/wugong_jiulou2.h"
#include "../d/wugong/wugong_fu_damen.h"
#include "../d/wugong/wugong_fu_xiaoyuan.h"
#include "../d/wugong/wugong_fu_datang.h"

CRoom * Load_WuGong(string room_name)
{
	CRoom * r = NULL;

	//武功
	if(room_name == "武功")
		r = new CRWuGongcity();
	else if(room_name == "武功土地庙")
		r = new CRWuGong_xiaomiao();
	else if(room_name == "武功民居1")
		r = new CRWuGong_minju1();
	else if(room_name == "武功民居2")
		r = new CRWuGong_minju2();
	else if(room_name == "武功富家侧门")
		r = new CRWuGong_fu_cemen();
	else if(room_name == "武功客店")
		r = new CRWuGong_kedian1();
	else if(room_name == "武功客店二楼")
		r = new CRWuGong_kedian2();
	else if(room_name == "武功酒楼")
		r = new CRWuGong_jiulou1();
	else if(room_name == "武功酒楼二楼")
		r = new CRWuGong_jiulou2();
	else if(room_name == "武功富家小院")
		r = new CRWuGong_fu_xiaoyuan();
	else if(room_name == "武功富家大门")
		r = new CRWuGong_fu_damen();
	else if(room_name == "武功富家大堂")
		r = new CRWuGong_fu_datang();

	return r;
}