//tulu1.h
//Sample for room:  Ѫ������·1
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_tulu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room

	set_name( "Ѫ������·1");

	add_door("Ѫ������·2", "Ѫ������·2", "Ѫ������·1");

	add_door("�����ԭ", "�����ԭ", "Ѫ������·1");
/******************************************************************************

******************************************************************************/

};

ROOM_END;
