//dadao2.h

//Sample for room: �ʹ����2
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_dadao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ʹ����2");

	//add npcs into the room
	add_npc("lingzhou_gongweishi");
	add_npc("lingzhou_gongweishi");     

	add_door("���ݻʹ����3", "���ݻʹ����3", "���ݻʹ����2");
	add_door("���ݻʹ����", "���ݻʹ����", "���ݻʹ����2");

	set("no_fight",1);
	set("no_cast",1);

};

ROOM_END;
