#include "stdafx.h"
#include "../server/Room.h"
#include "../std/resident.h"

//   泉州
#include "../d/quanzhou/quanzhoucity.h" 
#include "../d/quanzhou/quanzhou_bamboo.h" 
#include "../d/quanzhou/quanzhou_beimen.h" 
#include "../d/quanzhou/quanzhou_dahai.h" 
#include "../d/quanzhou/quanzhou_haigang.h" 
#include "../d/quanzhou/quanzhou_nanmen.h" 
#include "../d/quanzhou/quanzhou_penghu.h" 
#include "../d/quanzhou/quanzhou_puxian.h" 
#include "../d/quanzhou/quanzhou_qinglong.h" 
#include "../d/quanzhou/quanzhou_qinglong1.h" 
#include "../d/quanzhou/quanzhou_qinglong2.h" 
#include "../d/quanzhou/quanzhou_qinglong3.h" 
#include "../d/quanzhou/quanzhou_qzroad1.h" 
#include "../d/quanzhou/quanzhou_qzroad2.h" 
#include "../d/quanzhou/quanzhou_qzroad3.h" 
#include "../d/quanzhou/quanzhou_qzroad4.h" 
#include "../d/quanzhou/quanzhou_qzroad5.h" 
#include "../d/quanzhou/quanzhou_westbridge.h" 
#include "../d/quanzhou/quanzhou_zhongxin.h" 
#include "../d/quanzhou/quanzhou_zhongzhou.h" 


CRoom * Load_QuanZhou(string room_name)
{
	CRoom * r = NULL;

	//     泉州
	if(room_name == "泉州")
		r = new CRQuanzhoucity();
	else if(room_name == "泉州中洲桥")
		r = new CRQuanZhou_zhongzhou();
	else if(room_name == "泉州城中心")
		r = new CRQuanZhou_zhongxin();
	else if(room_name == "泉州西门吊桥")
		r = new CRQuanzhou_westbridge();
	else if(room_name == "泉州山路5")
		r = new CRQuanZhou_qzroad5();
	else if(room_name == "泉州山路4")
		r = new CRQuanZhou_qzroad4();
	else if(room_name == "泉州山路3")
		r = new CRQuanZhou_qzroad3();
	else if(room_name == "泉州山路2")
		r = new CRQuanZhou_qzroad2();
	else if(room_name == "泉州山路1")
		r = new CRQuanZhou_qzroad1();
	else if(room_name == "泉州青龙会侧庭3")
		r = new CRQuanZhou_qinglong3();
	else if(room_name == "泉州青龙会侧庭2")
		r = new CRQuanZhou_qinglong2();
	else if(room_name == "泉州青龙会大庭")
		r = new CRQuanZhou_qinglong1();
	else if(room_name == "泉州青龙会前庭")
		r = new CRQuanZhou_qinglong();
	else if(room_name == "泉州竹林小道")
		r = new CRQuanZhou_bamboo();
	else if(room_name == "泉州莆仙平原")
		r = new CRQuanZhou_puxian();
	else if(room_name == "泉州澎湖岛")
		r = new CRQuanZhou_penghu();
	else if(room_name == "泉州南门")
		r = new CRQuanZhou_nanmen();
	else if(room_name == "泉州海港")
		r = new CRQuanZhou_haigang();
	else if(room_name == "泉州大海")
		r = new CRQuanZhou_dahai();
	else if(room_name == "泉州北门")
		r = new CRQuanZhou_beimen();

	return r;
}