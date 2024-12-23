//hiemuya.h

//Sample for room:  ºÚÄ¾ÑÂ
//coded by zouwenbin
//data: 2000-11-16

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRHeiMuYacity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ºÚÄ¾ÑÂ");
	
	add_npc("pub_laozhe");        //add by zdn 2001-07-14

	add_door("ºÚÄ¾ÑÂÂÒÊ¯ÆÂ", "ºÚÄ¾ÑÂÂÒÊ¯ÆÂ", "³ö¿Ú");

	add_door("ºÚÄ¾ÑÂ³ÉµÂµî", "ºÚÄ¾ÑÂ³ÉµÂµî", "³ö¿Ú");
	add_door("ºÚÄ¾ÑÂÇàÁúÌÃ", "ºÚÄ¾ÑÂÇàÁúÌÃ", "³ö¿Ú");
	add_door("ºÚÄ¾ÑÂ°×»¢ÌÃ´óÌü", "ºÚÄ¾ÑÂ°×»¢ÌÃ´óÌü", "³ö¿Ú");
	add_door("ºÚÄ¾ÑÂ·çÀ×ÌÃ´óÌü", "ºÚÄ¾ÑÂ·çÀ×ÌÃ´óÌü", "³ö¿Ú");

};


ROOM_END;
