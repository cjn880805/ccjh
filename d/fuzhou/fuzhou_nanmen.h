//nanmen.h

//Sample for room: 福州南门
//coded by zouwenbin
//data: 2000-11-13

RESIDENT_BEGIN(CRfuzhou_nanmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "福州南门");

	set("resident", "福州");

	add_npc("pub_bing");   // add by zdn 2001-07-13

	add_door("福州南", "福州南", "福州南门");
	add_door("泉州中洲桥", "泉州中洲桥", "福州南门");

	set("long", "这里是福州南门。" );
    
};

RESIDENT_END;
