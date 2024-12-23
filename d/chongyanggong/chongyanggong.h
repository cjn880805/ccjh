//chongyanggong.h

//Sample for room:  ������
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	add_npc("quanzhen_cheng");
	add_npc("quanzhen_cui");
	add_npc("quanzhen_fang");
	add_npc("quanzhen_hao");
	add_npc("quanzhen_qiu");

	add_door("����������", "����������", "������");

	add_door("����������", "����������", "������");
	add_door("���������湬", "���������湬", "������");
	add_door("������������", "������������", "������");
	add_door("������������", "������������", "������");
	add_door("������������", "������������", "������");
	add_door("��������Ϣ��", "��������Ϣ��", "������");
	add_door("������С��԰1", "������С��԰1", "������");



/******************************************************************************
 ******************************************************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp