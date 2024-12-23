//jiuguan.h

//Sample for room: 酒馆
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_jiuguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "酒馆");

	//add npcs into the room
	add_npc("pub_xiaoer2");/////////////////////////

	add_door("灵州西", "灵州西", "灵州酒馆");

};


ROOM_END;
