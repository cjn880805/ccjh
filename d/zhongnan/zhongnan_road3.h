//road3.h

//Sample for room: ��ٵ�
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_road3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ٵ�");

	//add npcs into the room  2001-07-10 zdn add
	add_npc("pub_jianke");
	add_npc("pub_youngwoman");
	add_npc("pub_baifangxiao");
	add_npc("pub_linhongyin");

	add_door("����ɽɽ·2", "����ɽɽ·2", "����ɽ��ٵ�");
	add_door("������ٵ�2", "������ٵ�2", "����ɽ��ٵ�");

};


ROOM_END;
