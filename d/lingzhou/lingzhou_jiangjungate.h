//jiangjungate.h

//Sample for room: �󽫾���
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_jiangjungate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�󽫾���");

	//add npcs into the room
	add_npc("pub_xiaowei");/////////////////////////

	add_door("���ݶ�", "���ݶ�", "���ݴ󽫾���");


	set("no_fight",1);

};


ROOM_END;
