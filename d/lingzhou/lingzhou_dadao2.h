//dadao2.h

//Sample for room: 皇宫大道2
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_dadao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "皇宫大道2");

	//add npcs into the room
	add_npc("lingzhou_gongweishi");
	add_npc("lingzhou_gongweishi");     

	add_door("灵州皇宫大道3", "灵州皇宫大道3", "灵州皇宫大道2");
	add_door("灵州皇宫大道", "灵州皇宫大道", "灵州皇宫大道2");

	set("no_fight",1);
	set("no_cast",1);

};

ROOM_END;
