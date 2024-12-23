//longmen.h

//Sample for room: 泰山龙门
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_longmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山龙门");
	
	add_npc("taishan_tiansong");       //add by zdn 2001-07-20

	set("monster_chance", 30);
	set("monster_type", 2);

	add_door("泰山升仙坊", "泰山升仙坊", "泰山龙门");

	add_door("泰山五大夫松", "泰山五大夫松", "泰山龙门");


/*****************************************************
	set("exits", ([
		"northup" : __DIR__"shengxian",
		"southdown" : __DIR__"wudafu",
	]));
	set("objects", ([
		__DIR__"npc/chi" : 1,
	]));
*****************************************************/
};


FIELD_END;
