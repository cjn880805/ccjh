//cuixia.h

//Sample for room: �������ϼ��
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_cuixia);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������ϼ��");

	add_npc("yanziwu_azhu");
	
	add_door("�����봩��", "�����봩��", "�������ϼ��");
	add_door("������������", "������������", "�������ϼ��");
	add_door("����������", "����������", "�������ϼ��");

};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp