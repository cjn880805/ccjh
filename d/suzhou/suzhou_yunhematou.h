//yunhematou.h

//Sample for room: 运河码头
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_yunhematou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "运河码头");
	
	add_npc("pub_qiaofu");        //add by zdn 2001-07-16


	add_door("苏州", "苏州", "苏州运河码头");

	set("outdoors", "suzhou");
	
/*****************************************************
	set("exits", ([
		"southeast" : __DIR__"xidajie1",
	]));

********************************************/
};


ROOM_END;
