//fzroad.h

//Sample for room: 福州闽中大道
//coded by zouwenbin
//data: 2000-11-13

RESIDENT_BEGIN(CRfuzhou_fzroad);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "福州闽中大道");

	set("resident", "福州");

	add_npc("pub_xiaozei");   // add by zdn 2001-07-13
	add_npc("pub_hongzhoushushen"); 

	add_door("福州西", "福州西", "福州闽中大道");
	add_door("衡山黄土路", "衡山黄土路", "福州闽中大道");
 
};


RESIDENT_END;
