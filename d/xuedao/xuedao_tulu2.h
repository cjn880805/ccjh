//tulu2.h

//Sample for room:  Ѫ������·2

//coded by zouwenbin

//data: 2000-11-28
ROOM_BEGIN(CRXueDao_tulu2);

virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "Ѫ������·2");



	add_door("Ѫ������·1", "Ѫ������·1", "Ѫ������·2");

	add_door("Ѫ������·3", "Ѫ������·3", "Ѫ������·2");

	add_door("Ѫ���ſ͵�", "Ѫ���ſ͵�", "Ѫ������·2");
};

ROOM_END;
