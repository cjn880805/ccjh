//dongtian.h

//Sample for room: 泰山东天门
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_dongtian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山东天门");
	
	add_npc("taishan_jianchu");        //add by zdn 2001-07-20

	set("monster_chance", 20);

	add_door("泰山探海石", "泰山探海石", "泰山东天门");

	set("long","这里是岱顶的东面出口。往东依次经过伏虎门峡口、鹰愁涧等，便可下山。");
	

/*****************************************************
	set("exits", ([
		"west" : __DIR__"tanhai",
	]));
*****************************************************/
};


FIELD_END;
