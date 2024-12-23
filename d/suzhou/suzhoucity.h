//suzhoucity.h

//Sample for room:  苏州
//coded by Fisho
//data: 2000-11-3

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRsuzhoucity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "苏州");
	
	add_npc("pub_lady1");
	add_npc("pub_playboy");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_bing");                  //add by zdn 2001-07-15
	add_npc("helpnpc009");			//add by qzj 2001-08-13


	add_door("苏州青石官道2", "苏州青石官道2", "苏州");
	add_door("苏州寒山寺", "苏州寒山寺", "苏州");
	add_door("苏州东门", "苏州东门", "苏州");
	add_door("苏州南门", "苏州南门", "苏州");

	add_door("苏州府衙", "苏州府衙", "苏州");
	add_door("苏州书院", "苏州书院", "苏州");
	add_door("苏州书场", "苏州书场", "苏州");
	add_door("苏州客店", "苏州客店", "苏州");
	add_door("苏州茶馆", "苏州茶馆", "苏州");
	add_door("苏州兵营", "苏州兵营", "苏州");
//	add_door("苏州留园", "苏州留园", "苏州");
	add_door("苏州紫金庵", "苏州紫金庵", "苏州");
	add_door("苏州立春堂", "苏州立春堂", "苏州");
	add_door("苏州玄妙观", "苏州玄妙观", "苏州");
	add_door("苏州戏园子", "苏州戏园子", "苏州");
	add_door("苏州听雨轩", "苏州听雨轩", "苏州");
//	add_door("苏州狮子林", "苏州狮子林", "苏州");
	add_door("苏州宝带桥", "苏州宝带桥", "苏州");
	add_door("苏州聚宝斋", "苏州聚宝斋", "苏州");
	add_door("苏州春在楼", "苏州春在楼", "苏州");
	add_door("苏州打铁铺", "苏州打铁铺", "苏州");
	add_door("苏州宝和记", "苏州宝和记", "苏州");
	add_door("苏州沧浪亭", "苏州沧浪亭", "苏州");
	add_door("苏州运河码头", "苏州运河码头", "苏州");
	add_door("苏州擂台前广场", "苏州擂台前广场", "苏州");
};


ROOM_END;
