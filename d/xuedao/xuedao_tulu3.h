//tulu3.h

//Sample for room:  Ѫ������·3
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_tulu3);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ������·3");

	add_door("Ѫ������·2", "Ѫ������·2", "Ѫ������·3");
	add_door("Ѫ����ʥ��", "Ѫ����ʥ��", "Ѫ������·3");


/******************************************************************************
******************************************************************************/
};


ROOM_END;