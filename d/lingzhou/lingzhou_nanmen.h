//nanmen.h

//Sample for room: ��������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_nanmen);

virtual void create()			//Call it when Room Create
{

	set_name( "��������");

	//add npcs into the room
	add_npc("pub_xiaowei");/////////////////////////
	add_npc("pub_xixiabing");

	add_door("������", "������", "��������");
	add_door("���ݻ���̲", "���ݻ���̲", "��������");

};


ROOM_END;
