//beimen.h

//Sample for room: 泉州北门
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_beimen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泉州北门");

	set("resident", "泉州");

	add_npc("pub_playboy");

	add_door("泉州山路5", "泉州山路5", "泉州北门");
	add_door("泉州", "泉州", "泉州北门");

	set("long", "这里是南方第一港泉州的北门。出此门向北可抵中原。" );
	
	
/*****************************************************
	set("exits", ([
                "north" : "/d/fuzhou/puxian",
                "south" : __DIR__"zhongxin",
	]));
********************************************/
};


RESIDENT_END;
