//dadao1.h

//Sample for room: �ʹ����1
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_dadao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ʹ����");

	//add npcs into the room
	add_npc("lingzhou_gongweishi");
	add_npc("lingzhou_gongweishi");     

	add_door("���ݻʹ�����", "���ݻʹ�����", "���ݻʹ����");
	add_door("���ݻʹ����2", "���ݻʹ����2", "���ݻʹ����");

	set("no_fight",1);
	set("no_cast",1);

};

ROOM_END;
