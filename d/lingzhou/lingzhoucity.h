//lingzhoucity.h

//Sample for room:  ����
//coded by zwb
//data: 2000-11-16


ROOM_BEGIN(CRLingZhoucity);



virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");
	
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");             //add by zdn 2001-07-14
	add_npc("helpnpc018");		//add by qzj 2001-08-13

	add_door("��������", "��������", "����");

	add_door("���ݴ󽫾���", "���ݴ󽫾���", "����");

	add_door("����������1", "����������1", "����");


};


ROOM_END;
