//chema.h

//Sample for room: �����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_chema);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����");

	//add npcs into the room
	add_npc("pub_xiaoer2");/////////////////////////

	add_door("������", "������", "���ݳ����");
	add_door("�������", "�������", "���ݳ����");

	set("no_fight", 1);
    set("sleep_room",1);

};


ROOM_END;
