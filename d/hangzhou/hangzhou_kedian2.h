//kedian2.h

//Sample for room: ����������͵��¥
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRhangzhou_kedian2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������͵��¥");

	//add npcs into the room
	add_npc("pub_xiaoer2");
	set("sleep_room", 1);
	
	add_door("����������͵�","����������͵�", "����������͵��¥");

};


ROOM_END;