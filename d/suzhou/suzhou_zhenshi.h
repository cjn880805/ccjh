//zhenshi.h

//Sample for room: 枕石
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_zhenshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "枕石");
	
	add_npc("pub_jianke");               //add by zdn 2001-07-16


	add_door("苏州试剑石", "苏州试剑石", "苏州枕石");

};

ROOM_END;
