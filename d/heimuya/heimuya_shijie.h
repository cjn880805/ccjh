//shijie.h

//Sample for room: ºÚÄ¾ÑÂÊ¯½×
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_shijie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ºÚÄ¾ÑÂÊ¯½×");

    add_npc("pub_boy");         // add by zdn 2001-07-14
	add_npc("helpnpc004");

	add_door("ºÚÄ¾ÑÂÉ½µÀ", "ºÚÄ¾ÑÂÉ½µÀ", "ºÚÄ¾ÑÂÊ¯½×");
	add_door("ºÚÄ¾ÑÂÊ¯ÃÅ", "ºÚÄ¾ÑÂÊ¯ÃÅ", "ºÚÄ¾ÑÂÊ¯½×");

};


ROOM_END;
