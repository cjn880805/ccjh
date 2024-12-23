//xngxingtan.h

//Sample for room: ºÚÄ¾ÑÂÐÉÐÉÌ²
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_xngxingtan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ºÚÄ¾ÑÂÐÉÐÉÌ²");
	
	add_npc("pub_punk");               //add by zdn 2001-07-14


	add_door("ºÚÄ¾ÑÂÊ¯µÀ2", "ºÚÄ¾ÑÂÊ¯µÀ2", "ºÚÄ¾ÑÂÐÉÐÉÌ²");
	add_door("ºÚÄ¾ÑÂ³¤Ì²", "ºÚÄ¾ÑÂ³¤Ì²", "ºÚÄ¾ÑÂÐÉÐÉÌ²");

};


ROOM_END;
