//shanjiao.h

//Sample for room:  Ѫ����ɽ��
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_shanjiao);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ����ɽ��");

	add_door("Ѫ����С·4", "Ѫ����С·4", "Ѫ����ɽ��");
	add_door("Ѫ����ɽ·7", "Ѫ����ɽ·7", "Ѫ����ɽ��");


/******************************************************************************
******************************************************************************/
};


ROOM_END;