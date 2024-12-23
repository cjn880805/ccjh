//tanhai.h

//Sample for room: 泰山探海石
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_tanhai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山探海石");

	set("monster_chance", 30);

	add_door("泰山日观峰", "泰山日观峰", "泰山探海石");
	add_door("泰山东天门", "泰山东天门", "泰山探海石");

	set("long","这是一块从山崖向横突出的巨石，长约二丈余，向东直指渤海。巨石三面无所凭依，视野广阔，但除非有绝高胆色的人，普通人一般都不敢攀登这块探海石。");
	

/*****************************************************
	set("exits", ([
		"westdown" : __DIR__"riguan",
		"east" : __DIR__"dongtian",
	]));
*****************************************************/
};


FIELD_END;
