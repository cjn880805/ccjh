//tulu1.h
//Sample for room:  血刀门土路1
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_tulu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room

	set_name( "血刀门土路1");

	add_door("血刀门土路2", "血刀门土路2", "血刀门土路1");

	add_door("西域草原", "西域草原", "血刀门土路1");
/******************************************************************************

******************************************************************************/

};

ROOM_END;
