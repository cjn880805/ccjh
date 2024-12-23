#include "stdafx.h"
#include "../server/Room.h"


//万劫谷
#include "../d/wanjie/wanjiecity.h"
#include "../d/wanjie/wanjie_bed_room.h"
#include "../d/wanjie/wanjie_bridge.h"
#include "../d/wanjie/wanjie_entrance.h"
#include "../d/wanjie/wanjie_grassland.h"
#include "../d/wanjie/wanjie_port.h"
#include "../d/wanjie/wanjie_port2.h"
#include "../d/wanjie/wanjie_riverside1.h"
#include "../d/wanjie/wanjie_riverside2.h"
#include "../d/wanjie/wanjie_riverside3.h"
#include "../d/wanjie/wanjie_shan_road1.h"
#include "../d/wanjie/wanjie_shan_road2.h"
#include "../d/wanjie/wanjie_shan_road3.h"
#include "../d/wanjie/wanjie_shan_road4.h"
#include "../d/wanjie/wanjie_slide.h"
#include "../d/wanjie/wanjie_stone_room.h"
#include "../d/wanjie/wanjie_xiaoting.h"
#include "../d/wanjie/wanjie_yaofang.h"

CRoom * Load_WanJie(string room_name)
{
	CRoom * r = NULL;

	//万劫谷
    if(room_name == "万劫谷")
		r = new CRWanJiecity();
    else if(room_name == "万劫谷小厅")
		r = new CRWanJie_xiaoting();
    else if(room_name == "万劫谷山坡")
		r = new CRWanJie_slide();
    else if(room_name == "万劫谷山路4")
		r = new CRWanJie_shan_road4();
    else if(room_name == "万劫谷山路3")
		r = new CRWanJie_shan_road3();
    else if(room_name == "万劫谷山路2")
		r = new CRWanJie_shan_road2();
    else if(room_name == "万劫谷山路1")
		r = new CRWanJie_shan_road1();
    else if(room_name == "万劫谷江边小路3")
		r = new CRWanJie_riverside3();
    else if(room_name == "万劫谷江边小路2")
		r = new CRWanJie_riverside2();
    else if(room_name == "万劫谷江边小路1")
		r = new CRWanJie_riverside1();
    else if(room_name == "万劫谷澜沧江畔")
		r = new CRWanJie_port2();
    else if(room_name == "万劫谷善人渡")
		r = new CRWanJie_port();
    else if(room_name == "万劫谷草地")
		r = new CRWanJie_grassland();
    else if(room_name == "万劫谷大森林")
		r = new CRWanJie_entrance();
    else if(room_name == "万劫谷卧室")
		r = new CRWanJie_bed_room();
    else if(room_name == "万劫谷药房")
		r = new CRWanJie_yaofang();
    else if(room_name == "万劫谷石屋")
		r = new CRWanJie_stone_room();
    else if(room_name == "万劫谷铁索桥")
		r = new CRWanJie_bridge();

	return r;
}