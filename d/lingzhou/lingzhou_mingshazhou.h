//mingshazhou.h

//Sample for room: ������ɳ��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_mingshazhou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ɳ��");
	
	add_npc("monster_28k");   //add by zdn 2001-07-14


	add_door("������ͭϿ", "������ͭϿ", "������ɳ��");
	add_door("�������ͱ�", "�������ͱ�", "������ɳ��");

};


ROOM_END;
