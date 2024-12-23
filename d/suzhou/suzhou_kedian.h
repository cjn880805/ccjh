//kedian.h

//Sample for room: 客店
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_kedian);

virtual void create()			//Call it when Room Create
{
	set_name( "客店");

	add_npc("pub_xiaoer2");

	add_door("苏州北", "苏州北", "苏州客店");

	set("no_fight", 1);
	set("valid_startroom", 1);
    set("sleep_room",1);
	

};


ROOM_END;
