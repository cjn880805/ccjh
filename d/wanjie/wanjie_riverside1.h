//riverside1.h

//Sample for room: ����С·1
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_riverside1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����С·1");

	//add npcs into the room
//	add_npc("animal_duck");/////////////////////////

	add_door("������ʯ��", "������ʯ��", "��ٹȽ���С·1");
	add_door("��ٹȽ���С·2", "��ٹȽ���С·2", "��ٹȽ���С·1");


};


ROOM_END;
