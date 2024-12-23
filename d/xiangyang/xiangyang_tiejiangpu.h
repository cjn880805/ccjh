//TieJiangPu.cpp

//Sample for room: Ìú½³ÆÌ
//coded by Lanwood
//data: 2000-10-25

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXiangYang_TieJiangPu);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ìú½³ÆÌ");

	//add npcs into the room
	add_npc("pub_tiejiang");
				

	add_door("ÏåÑô¶«ÄÏ", "ÏåÑô¶«ÄÏ", "ÏåÑôÌú½³ÆÌ");
	
/**********************************************
		set("exits", ([
		"west" : __DIR__"southjie3",
	]));
	set("objects", ([
		__DIR__"npc/tiejiang" : 1,
	]));
*****************************************/
};


ROOM_END;
