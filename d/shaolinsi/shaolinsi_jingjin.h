//jingjin.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_jingjin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����¾�����");

	add_npc("shaolin_hui_kong");

	add_door("���������޳�", "���������޳�", "�����¾�����");
	add_door("������������", "������������", "�����¾�����");
	add_door("�����¹�¥СԺ", "�����¹�¥СԺ", "�����¾�����");
	add_door("��������¥һ��", "��������¥һ��", "�����¾�����");

};

ROOM_END;
