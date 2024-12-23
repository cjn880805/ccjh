#include "stdafx.h"
#include "../server/Room.h"


//桃花岛
#include "../d/taohua/taohuacity.h"
#include "../d/taohua/taohua_bingqi.h"
#include "../d/taohua/taohua_chufang.h"
#include "../d/taohua/taohua_daojufang.h"
#include "../d/taohua/taohua_mudao.h"
#include "../d/taohua/taohua_shandong.h"
#include "../d/taohua/taohua_xiaoyuan.h"
#include "../d/taohua/taohua_wofang.h"
#include "../d/taohua/taohua_xaiowu.h"
#include "../d/taohua/taohua_xiguoshi.h"
#include "../d/taohua/taohua_xiuxishi.h"
#include "../d/taohua/taohua_zhengting.h"
#include "../d/taohua/taohua_shufang.h"
#include "../d/taohua/taohua_damen.h"
#include "../d/taohua/taohua_dahai.h"

CRoom * Load_TaoHuaDao(string room_name)
{
	CRoom * r = NULL;

	//桃花岛
	if(room_name == "桃花岛")
		r = new CRTaoHuacity();
    else if(room_name == "桃花岛山庄正厅")
		r = new CRTaoHua_zhengting();
    else if(room_name == "桃花岛桃花轩")
		r = new CRTaoHua_xiuxishi();
    else if(room_name == "桃花岛思过室")
		r = new CRTaoHua_xiguoshi();
    else if(room_name == "桃花岛小屋")
		r = new CRTaoHua_xaiowu();
    else if(room_name == "桃花岛卧房")
		r = new CRTaoHua_wofang();
    else if(room_name == "桃花山庄小院")
		r = new CRTaoHua_xiaoyuan();
    else if(room_name == "桃花岛山洞")
		r = new CRTaoHua_shandong();
    else if(room_name == "桃花岛墓道")
		r = new CRTaoHua_mudao();
    else if(room_name == "桃花岛道具房")
		r = new CRTaoHua_daojufang();
    else if(room_name == "桃花岛厨房")
		r = new CRTaoHua_chufang();
    else if(room_name == "桃花岛兵器室")
		r = new CRTaoHua_bingqi();
    else if(room_name == "桃花山庄书房")
		r = new CRTaoHua_shufang();
    else if(room_name == "桃花山庄正门")
		r = new CRTaoHua_damen();
    else if(room_name == "桃花岛大海")
		r = new CRTaoHua_dahai();

	return r;
}