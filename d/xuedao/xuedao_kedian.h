//kedian.h

//Sample for room:  血刀门客店
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_kedian);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门客店");
	
	add_npc("pub_xiaoer2");          //add by zdn 2001-07-16

	add_door("血刀门土路2", "血刀门土路2", "血刀门客店");


/******************************************************************************
******************************************************************************/
};


ROOM_END;
