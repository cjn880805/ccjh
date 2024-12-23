//beijing_dongbei.h

//Sample for room:  北京东北
//coded by Fisho
//data: 2000-11-2


RESIDENT_BEGIN(CRbeijing_dongbei);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "北京东北");

	set("resident", "北京");
	//add npcs into the room

	add_npc("pub_boy");
	add_npc("pub_lady1");
	add_npc("pub_playboy");


	add_door("北京全聚德酒楼", "北京全聚德酒楼", "北京东北");
	add_door("北京东厂大门", "北京东厂大门", "北京东北");
	add_door("北京康府", "北京康府", "北京东北");
	add_door("北京万宝楼", "北京万宝楼", "北京东北");
	
	add_door("北京西北", "北京西北", "北京东北");
	add_door("北京东南", "北京东南", "北京东北");
	add_door("北京张府", "北京张府", "北京东北");


};


RESIDENT_END;