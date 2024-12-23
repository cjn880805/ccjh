//tulu2.h

//Sample for room:  血刀门土路2

//coded by zouwenbin

//data: 2000-11-28
ROOM_BEGIN(CRXueDao_tulu2);

virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "血刀门土路2");



	add_door("血刀门土路1", "血刀门土路1", "血刀门土路2");

	add_door("血刀门土路3", "血刀门土路3", "血刀门土路2");

	add_door("血刀门客店", "血刀门客店", "血刀门土路2");
};

ROOM_END;
