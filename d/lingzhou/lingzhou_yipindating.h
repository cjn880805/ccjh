//yipindating.h

//Sample for room: һƷ�ô���
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_yipindating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "һƷ�ô���");

	//add npcs into the room
	add_npc("pub_yipinwushi");
	add_npc("lingzhou_yunying");          //add by zdn 2001-07-20

	add_door("������", "������", "����һƷ�ô���");
	add_door("���ݽ�����", "���ݽ�����", "����һƷ�ô���");
	add_door("����һƷ���ʷ�", "����һƷ���ʷ�", "����һƷ�ô���");


	set("no_fight",1);

};


ROOM_END;
