//keting.h

//Sample for room:  Ã·×¯Ó­¿ÍÍ¤
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRMeiZhuang_keting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ã·×¯Ó­¿ÍÍ¤");
	
	add_npc("pub_jianke");      //add by zdn 2001-07-14
	add_item("meishu");

	add_door("Ã·×¯ËÄÑÅÇå·ç", "Ã·×¯ËÄÑÅÇå·ç", "Ã·×¯Ó­¿ÍÍ¤");
	add_door("Ã·×¯°ÙÄ¾Ô°", "Ã·×¯°ÙÄ¾Ô°", "Ã·×¯Ó­¿ÍÍ¤");

};


ROOM_END;
