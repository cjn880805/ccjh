#include "stdafx.h"
#include "../server/Room.h"

//   �书
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

	//�书
	if(room_name == "�书")
		r = new CRWuGongcity();
	else if(room_name == "�书������")
		r = new CRWuGong_xiaomiao();
	else if(room_name == "�书���1")
		r = new CRWuGong_minju1();
	else if(room_name == "�书���2")
		r = new CRWuGong_minju2();
	else if(room_name == "�书���Ҳ���")
		r = new CRWuGong_fu_cemen();
	else if(room_name == "�书�͵�")
		r = new CRWuGong_kedian1();
	else if(room_name == "�书�͵��¥")
		r = new CRWuGong_kedian2();
	else if(room_name == "�书��¥")
		r = new CRWuGong_jiulou1();
	else if(room_name == "�书��¥��¥")
		r = new CRWuGong_jiulou2();
	else if(room_name == "�书����СԺ")
		r = new CRWuGong_fu_xiaoyuan();
	else if(room_name == "�书���Ҵ���")
		r = new CRWuGong_fu_damen();
	else if(room_name == "�书���Ҵ���")
		r = new CRWuGong_fu_datang();

	return r;
}