//bailianchi.h

//Sample for room: ������
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_bailianchi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room
	add_npc("pub_lady1");/////////////////////////

	add_door("���ݶ���ͤ", "���ݶ���ͤ", "���ݰ�����");


};


ROOM_END;
