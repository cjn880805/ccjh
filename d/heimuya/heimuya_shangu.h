//shangu.h

//Sample for room: ºÚÄ¾ÑÂÉ½¹È
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_shangu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ºÚÄ¾ÑÂÉ½¹È");

	add_npc("pub_ruhua");
	add_door("ºÚÄ¾ÑÂÁÖ¼äÐ¡µÀ", "ºÚÄ¾ÑÂÁÖ¼äÐ¡µÀ", "ºÚÄ¾ÑÂÉ½¹È");
	add_door("ºÚÄ¾ÑÂÊ¯µÀ1", "ºÚÄ¾ÑÂÊ¯µÀ1", "ºÚÄ¾ÑÂÉ½¹È");
	add_door("ºÚÄ¾ÑÂÇàÁúÌÃ", "ºÚÄ¾ÑÂÇàÁúÌÃ", "ºÚÄ¾ÑÂÉ½¹È");

};


ROOM_END;
