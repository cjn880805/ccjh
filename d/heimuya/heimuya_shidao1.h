//shidao1.h

//Sample for room: ºÚÄ¾ÑÂÊ¯µÀ1
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_shidao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ºÚÄ¾ÑÂÊ¯µÀ1");
	
	add_npc("heimuya_zishan");     // add by zdn 2001-07-20


	add_door("ºÚÄ¾ÑÂÊ¯µÀ2", "ºÚÄ¾ÑÂÊ¯µÀ2", "ºÚÄ¾ÑÂÊ¯µÀ1");
	add_door("ºÚÄ¾ÑÂÉ½¹È", "ºÚÄ¾ÑÂÉ½¹È", "ºÚÄ¾ÑÂÊ¯µÀ1");

};


ROOM_END;
