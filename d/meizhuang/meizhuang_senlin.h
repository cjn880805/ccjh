//senlin.h

//Sample for room:  Ã·×¯°ÙÄ¾Ô°
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_senlin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ã·×¯°ÙÄ¾Ô°");
	
	add_npc("pub_shinu1");         //add by zdn 2001-07-14

	add_item("meishu");
	add_item("meishu");

	add_door("Ã·×¯Ó­¿ÍÍ¤", "Ã·×¯Ó­¿ÍÍ¤", "Ã·×¯°ÙÄ¾Ô°");
	add_door("Ã·×¯ÄÚÔº", "Ã·×¯ÄÚÔº", "Ã·×¯°ÙÄ¾Ô°");
	add_door("Ã·×¯Ææ»±ÆÂ", "Ã·×¯Ææ»±ÆÂ", "Ã·×¯°ÙÄ¾Ô°");
	add_door("Ã·×¯Æ«·¿", "Ã·×¯Æ«·¿", "Ã·×¯°ÙÄ¾Ô°");

};


ROOM_END;
