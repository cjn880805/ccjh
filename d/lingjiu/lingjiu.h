//lingjiu.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	add_npc("helpnpc015");		//code by qzj 2001-08-13

	add_door("������", "������", "����");

	add_door("������翷�ɽ��", "������翷�ɽ��", "����");


/*****************************************************
 
********************************************/
};


ROOM_END;
