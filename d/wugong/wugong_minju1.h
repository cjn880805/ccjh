//minju1.h

//Sample for room: 武功民居1
//coded by zouwenbin
//data: 2000-11-14

WUGONG_BEGIN(CRWuGong_minju1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武功民居1");
	
//	add_npc("pub_zhangma");     //add by zdn 2001-07-16

	add_door("武功", "武功", "武功民居1");

	

/*****************************************************
 
********************************************/
};


WUGONG_END;
