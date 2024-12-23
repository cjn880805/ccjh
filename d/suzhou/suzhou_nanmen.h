//nanmen.h

//Sample for room: 南门
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_nanmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "南门");
	
	add_npc("pub_bing");        //add by zdn 2001-07-16

	add_door("苏州南", "苏州南", "苏州南门");
	add_door("燕子坞太湖", "燕子坞太湖", "苏州南门");

};


ROOM_END;
