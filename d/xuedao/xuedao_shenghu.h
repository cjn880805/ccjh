//shenghu.h

//Sample for room:  血刀门圣湖
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_shenghu);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门圣湖");
	
	add_npc("xuedao_lutianshu");        //add by zdn 2001-07-20

	add_door("血刀门土路3", "血刀门土路3", "血刀门圣湖");
	add_door("血刀门小路1", "血刀门小路1", "血刀门圣湖");
	add_door("血刀门棍巢", "血刀门棍巢", "血刀门圣湖");


/******************************************************************************
******************************************************************************/
};


ROOM_END;
