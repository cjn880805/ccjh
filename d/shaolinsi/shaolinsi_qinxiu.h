//qinxiu.h

//Sample for room: ���޳�
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_qinxiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���������޳�");
	
	add_npc("shaolin_sengbing2");   //add by zdn 2001-07-20

	add_door("�����º��", "�����º��", "���������޳�");
	add_door("������ի��", "������ի��", "���������޳�");
	add_door("�����½���Ժ", "�����½���Ժ", "���������޳�");
	add_door("�����¾�����", "�����¾�����", "���������޳�");

};

ROOM_END;
