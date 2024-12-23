//wugongcity.h

//Sample for room:  武功
//coded by Fisho
//data: 2000-11-4

//Note: these two headers must be include
//use macro WUGONG_BEGIN(room_name) to declare room
//and use macro WUGONG_END end declare
WUGONG_BEGIN(CRWuGongcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武功");

	add_npc("pub_playboy");

	add_door("长安大官道2", "长安大官道2", "武功");

	add_door("武功土地庙", "武功土地庙", "武功");
	add_door("武功民居2", "武功民居2", "武功");
	add_door("武功民居1", "武功民居1", "武功");
	add_door("武功酒楼", "武功酒楼", "武功");
	add_door("武功富家大门", "武功富家大门", "武功");
	add_door("武功客店", "武功客店", "武功");
/********************************************************
 
****************************************************************/
};


WUGONG_END;
