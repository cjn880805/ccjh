#include "stdafx.h"
#include "../server/Room.h"
#include "../d/yewai_room.h"
#include "../d/cunluo_room.h"

//高昌迷宫

#include "../d/yewaidoor_room.h"
#include "../d/gaochang/GaoChang_mg.h"
#include "../d/gaochang/GaoChang_mg_2.h"
#include "../d/gaochang/GaoChang_mg_3.h"
#include "../d/gaochang/GaoChang_mg_4.h"
#include "../d/gaochang/GaoChang_mg_5.h"
#include "../d/gaochang/GaoChang_mg_6.h"
#include "../d/gaochang/GaoChang_mg_7.h"
#include "../d/gaochang/GaoChang_mg_8.h"
#include "../d/gaochang/GaoChang_mg_9.h"
#include "../d/gaochang/GaoChang_mg_10.h"
#include "../d/gaochang/GaoChang_mg_11.h"
#include "../d/gaochang/GaoChang_mg_12.h"
#include "../d/gaochang/GaoChang_mg_13.h"
#include "../d/gaochang/GaoChang_mg_14.h"
#include "../d/gaochang/GaoChang_mg_15.h"
#include "../d/gaochang/GaoChang_mg_16.h"
#include "../d/gaochang/GaoChang_mg_17.h"
#include "../d/gaochang/GaoChang_mg_18.h"
#include "../d/gaochang/GaoChang_mg_19.h"
#include "../d/gaochang/GaoChang_mg_20.h"
#include "../d/gaochang/GaoChang_mg_21.h"
#include "../d/gaochang/GaoChang_mg_22.h"

CRoom * Load_GaoChang(string room_name)
{
	CRoom * r = NULL;

	// 高昌迷宫
	if(room_name == "高昌迷宫")
		r = new CRGaoChang_mg();
	else if(room_name == "高昌黄泉之路")
		r = new CRGaoChang_mg_2();
	else if(room_name == "高昌奈何桥")
		r = new CRGaoChang_mg_3();
	else if(room_name == "高昌鬼门关")
		r = new CRGaoChang_mg_4();
	else if(room_name == "高昌泥犁地狱")
		r = new CRGaoChang_mg_5();
	else if(room_name == "高昌刀山地狱")
		r = new CRGaoChang_mg_6();
	else if(room_name == "高昌沸沙地狱")
		r = new CRGaoChang_mg_7();
	else if(room_name == "高昌沸屎地狱")
		r = new CRGaoChang_mg_8();
	else if(room_name == "高昌黑身地狱")
		r = new CRGaoChang_mg_9();
	else if(room_name == "高昌火海地狱")
		r = new CRGaoChang_mg_10();
	else if(room_name == "高昌镬汤地狱")
		r = new CRGaoChang_mg_11();
	else if(room_name == "高昌铁床地狱")
		r = new CRGaoChang_mg_12();
	else if(room_name == "高昌嵯山地狱")
		r = new CRGaoChang_mg_13();
	else if(room_name == "高昌寒冰地狱")
		r = new CRGaoChang_mg_14();
	else if(room_name == "高昌剥皮地狱")
		r = new CRGaoChang_mg_15();
	else if(room_name == "高昌畜性地狱")
		r = new CRGaoChang_mg_16();
	else if(room_name == "高昌刀兵地狱")
		r = new CRGaoChang_mg_17();
	else if(room_name == "高昌铁磨地狱")
		r = new CRGaoChang_mg_18();
	else if(room_name == "高昌冰地狱")
		r = new CRGaoChang_mg_19();
	else if(room_name == "高昌蛆虫地狱")
		r = new CRGaoChang_mg_20();
	else if(room_name == "高昌烊铜地狱")
		r = new CRGaoChang_mg_21();
	else if(room_name == "高昌阿鼻地狱")
		r = new CRGaoChang_mg_22();
	return r;
}

