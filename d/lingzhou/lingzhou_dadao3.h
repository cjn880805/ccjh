//dadao3.h

//Sample for room: �ʹ����3
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_dadao3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ʹ����3");

	//add npcs into the room
	add_npc("lingzhou_gongweishi");
	add_npc("lingzhou_gongweishi");     

	add_door("���ݻʹ����2", "���ݻʹ����2", "���ݻʹ����3");
	add_door("���ݻʹ��㳡", "���ݻʹ��㳡", "���ݻʹ����3");

	set("no_fight",1);
	set("no_cast",1);

};

ROOM_END;
