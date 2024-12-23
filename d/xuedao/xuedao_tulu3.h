//tulu3.h

//Sample for room:  血刀门土路3
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_tulu3);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门土路3");

	add_door("血刀门土路2", "血刀门土路2", "血刀门土路3");
	add_door("血刀门圣湖", "血刀门圣湖", "血刀门土路3");


/******************************************************************************
******************************************************************************/
};


ROOM_END;