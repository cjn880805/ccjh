//chema.h

//Sample for room: 车马店
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_chema);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "车马店");

	//add npcs into the room
	add_npc("pub_xiaoer2");/////////////////////////

	add_door("灵州西", "灵州西", "灵州车马店");
	add_door("灵州马厩", "灵州马厩", "灵州车马店");

	set("no_fight", 1);
    set("sleep_room",1);

};


ROOM_END;
