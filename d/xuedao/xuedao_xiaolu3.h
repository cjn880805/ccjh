//xiaolu3.h

//Sample for room:  Ѫ����С·3
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_xiaolu3);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ����С·3");

	add_door("Ѫ����С·2", "Ѫ����С·2", "Ѫ����С·3");
	add_door("Ѫ����С·4", "Ѫ����С·4", "Ѫ����С·3");


/******************************************************************************
******************************************************************************/
};


ROOM_END;