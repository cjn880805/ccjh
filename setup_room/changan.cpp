#include "stdafx.h"
#include "../std/RField.h"
#include "../std/resident.h"

//    长安城 
#include "../d/changan_room.h" 
#include "../d/chang_an/chang_ancity.h" 
#include "../d/chang_an/chang_an_club.h"
#include "../d/chang_an/chang_an_club3.h" 
#include "../d/chang_an/chang_an_clubpoem.h" 
#include "../d/chang_an/chang_an_clubup.h" 
#include "../d/chang_an/chang_an_duchang1.h" 
#include "../d/chang_an/chang_an_duchang2.h" 
#include "../d/chang_an/chang_an_duchang3.h" 
#include "../d/chang_an/chang_an_duchang4.h" 
#include "../d/chang_an/chang_an_piggy.h" 
#include "../d/chang_an/chang_an_pukeroom.h" 
#include "../d/chang_an/chang_an_qianzhuang.h" 
#include "../d/chang_an/chang_an_qishi.h" 
#include "../d/chang_an/chang_an_shaiziroom.h" 
#include "../d/chang_an/chang_an_road1.h" 
#include "../d/chang_an/chang_an_road2.h" 
#include "../d/chang_an/chang_an_road4.h" 
#include "../d/chang_an/chang_an_hanguguan.h" 

CRoom * Load_ChangAn(string room_name)
{
	CRoom * r = NULL;

	//    长安城
	if(room_name == "长安")
		r = new CRchang_ancity();
	else if(room_name == "长安骰子房")
		r = new CRChangAn_shaiziroom();
	else if(room_name == "长安入神坐照室")
		r = new CRChangAn_qishi();
	else if(room_name == "长安相记钱庄")
		r = new CRChangAn_qianzhuang();
	else if(room_name == "长安拱猪房")
		r = new CRChangAn_pukeroom();
	else if(room_name == "长安三楼拱猪房")
		r = new CRChangAn_piggy();
	else if(room_name == "长安乐坊")
		r = new CRChangAn_club();
	else if(room_name == "长安赛龟房")
		r = new CRChangAn_duchang4();
	else if(room_name == "长安斗鸡房")
		r = new CRChangAn_duchang3();
	else if(room_name == "长安骨骰房")
		r = new CRChangAn_duchang2();
	else if(room_name == "长安押签房")
		r = new CRChangAn_duchang1();
	else if(room_name == "长安乐坊二楼大厅")
		r = new CRChangAn_clubup();
	else if(room_name == "长安乐府诗社")
		r = new CRChangAn_clubpoem();
	else if(room_name == "长安聚义厅")
		r = new CRChangAn_club3();
	else if(room_name == "长安大官道4")
		r = new CRChangAn_road4();
	else if(room_name == "长安大官道2")
		r = new CRChangAn_road2();
	else if(room_name == "长安关洛道")
		r = new CRChangAn_road1();
	else if(room_name == "长安函谷关")
		r = new CRChangAn_hanguguan();

	return r;
}