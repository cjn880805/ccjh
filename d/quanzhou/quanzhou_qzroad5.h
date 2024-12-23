//qzroad5.h

//Sample for room: 泉州山路5
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_qzroad5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泉州山路5");

	set("resident", "泉州");
	
	add_npc("pub_daoke");        //add by zdn 2001-07-14


	add_door("泉州北门", "泉州北门", "泉州山路5");
	add_door("泉州山路4", "泉州山路4", "泉州山路5");

	
	
	
/*****************************************************
	set("exits", ([
                "north"   : __DIR__"jxnanmen",
                "west"    : __DIR__"qzroad3",
//		"southup" : __DIR__"qzroad5",
		"southup" : "/d/fuzhou/fzroad1",
		"east"    : __DIR__"chating",
	]));
********************************************/
};


RESIDENT_END;
