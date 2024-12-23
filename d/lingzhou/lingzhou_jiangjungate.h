//jiangjungate.h

//Sample for room: 大将军府
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_jiangjungate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大将军府");

	//add npcs into the room
	add_npc("pub_xiaowei");/////////////////////////

	add_door("灵州东", "灵州东", "灵州大将军府");


	set("no_fight",1);

};


ROOM_END;
