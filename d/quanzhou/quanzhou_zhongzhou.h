//zhongzhou.h

//Sample for room: 泉州中洲桥
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_zhongzhou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泉州中洲桥");

	set("resident", "泉州");
	
	add_npc("pub_yinjiuyou");
	add_npc("pub_cunfu");
	add_npc("pub_daoke");         //add by zdn 2001-07-14


	add_door("泉州莆仙平原", "泉州莆仙平原", "泉州中洲桥");
	add_door("福州南门", "福州南门", "泉州中洲桥");


	
	
/*****************************************************
	set("exits", ([
		"north" : __DIR__"nanmen",
                "south" : __DIR__"puxian",
	]));
********************************************/
};


RESIDENT_END;
