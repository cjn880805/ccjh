//dadao1.h

//Sample for room: 皇宫大道1
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_dadao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "皇宫大道");

	//add npcs into the room
	add_npc("lingzhou_gongweishi");
	add_npc("lingzhou_gongweishi");     

	add_door("灵州皇宫大门", "灵州皇宫大门", "灵州皇宫大道");
	add_door("灵州皇宫大道2", "灵州皇宫大道2", "灵州皇宫大道");

	set("no_fight",1);
	set("no_cast",1);

};

ROOM_END;
