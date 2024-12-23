//xuedaomen.h

//Sample for room:  血刀门
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门");
	
	add_npc("pub_zhuoma");        //add by zdn 2001-07-20




	add_door("襄阳城", "襄阳城", "血刀门");

	add_door("血刀门雪山路1", "血刀门雪山路1", "血刀门");


    

/******************************************************************************

******************************************************************************/
};


ROOM_END;
