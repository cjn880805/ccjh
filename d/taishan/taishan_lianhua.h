//lianhua.h

//Sample for room: 泰山莲花峰
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_lianhua);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山莲花峰");
	
	add_npc("taishan_tianmen");        //add by zdn 2001-07-20

	set("monster_chance", 20);

	add_door("泰山天街", "泰山天街", "泰山莲花峰");
	add_door("泰山试心石", "泰山试心石", "泰山莲花峰");

	

/*****************************************************
	set("exits", ([
		"westup" : __DIR__"tianjie",
		"northup" : __DIR__"shixin",
	]));
*****************************************************/
};


FIELD_END;
