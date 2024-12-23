//riguan.h

//Sample for room: 泰山日观峰
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_riguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山日观峰");

	set("monster_chance", 15);
	add_npc("taishan_chi");        //add by zdn 2001-07-20


	add_door("泰山玉皇顶", "泰山玉皇顶", "泰山日观峰");
	add_door("泰山探海石", "泰山探海石", "泰山日观峰");

	

/*****************************************************
	set("exits", ([
		"westup" : __DIR__"yuhuang",
		"eastup" : __DIR__"tanhai",
	]));
	set("objects", ([
		__DIR__"npc/tianmen" : 1,
	]));
*****************************************************/
};


FIELD_END;
