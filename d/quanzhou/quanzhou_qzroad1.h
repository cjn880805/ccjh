//qzroad1.h

//Sample for room: 泉州山路1
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_qzroad1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泉州山路1");

	set("resident", "泉州");
	
	add_npc("pub_flowerg");     //add by zdn 2001-07-14


	add_door("泉州山路2", "泉州山路2", "泉州山路1");
	add_door("泰山大驿道", "泰山大驿道", "泉州山路1");

	
	
/*****************************************************
	set("exits", ([
		"northwest" : "/d/taishan/yidao1",
                "south" : __DIR__"qzroad2",
	]));
********************************************/
};


RESIDENT_END;
