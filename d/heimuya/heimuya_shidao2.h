//shidao2.h

//Sample for room: ºÚÄ¾ÑÂÊ¯µÀ2
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_shidao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ºÚÄ¾ÑÂÊ¯µÀ2");
	
	add_npc("heimuya_zishan");       //add by zdn 2001-07-20


	add_door("ºÚÄ¾ÑÂÊ¯µÀ1", "ºÚÄ¾ÑÂÊ¯µÀ1", "ºÚÄ¾ÑÂÊ¯µÀ2");
	add_door("ºÚÄ¾ÑÂÐÉÐÉÌ²", "ºÚÄ¾ÑÂÐÉÐÉÌ²", "ºÚÄ¾ÑÂÊ¯µÀ2");

};


ROOM_END;
