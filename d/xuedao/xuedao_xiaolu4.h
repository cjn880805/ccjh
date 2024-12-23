//xiaolu4.h

//Sample for room:  血刀门小路4
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_xiaolu4);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门小路4");
	
//	add_npc("xuedao_shuidai");        //add by zdn 2001-07-20
		
	add_door("血刀门小路3", "血刀门小路3", "血刀门小路4");
	add_door("血刀门山脚", "血刀门山脚", "血刀门小路4");
	
	
	/******************************************************************************
	******************************************************************************/
};


ROOM_END;
