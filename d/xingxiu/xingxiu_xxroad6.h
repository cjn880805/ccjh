//xxroad6.h

//Sample for room: 星宿海山间平地
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_xxroad6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "星宿海山间平地");


	add_door("星宿海小路", "星宿海小路", "星宿海山间平地");

    set("long","山间平地，地上是嫩绿的小草，周围布了几棵桦树，山边有一眼清泉。草地上树着几个毒僵尸，显是星宿弟子练功所用。" );


};


ROOM_END;
