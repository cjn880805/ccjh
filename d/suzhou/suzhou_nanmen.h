//nanmen.h

//Sample for room: ����
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_nanmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");
	
	add_npc("pub_bing");        //add by zdn 2001-07-16

	add_door("������", "������", "��������");
	add_door("������̫��", "������̫��", "��������");

};


ROOM_END;
