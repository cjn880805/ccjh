//huanghe.h

//Sample for room  黄河
//coded by zwb
//data: 2000-11-18

//Note: these two headers must be include
//use macro CHANGAN_BEGIN(room_name) to declare room
//and use macro CHANGAN_END end declare
CHANGAN_BEGIN(CRHuangHe);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河");
	
	add_npc("huanghe_peng");         // add by zdn 2001-07-14
	add_npc("helpnpc017");

	add_door("灵州宣和堡", "灵州宣和堡", "黄河");
	add_door("黄河古长城", "黄河古长城", "黄河");

};


CHANGAN_END;
