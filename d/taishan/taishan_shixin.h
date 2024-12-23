//shixin.h

//Sample for room: 泰山试心石
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_shixin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山试心石");

	set("monster_chance", 30);

	add_door("泰山莲花峰", "泰山莲花峰", "泰山试心石");

	set("long","这里便是莲花峰的峰顶，由两块巨石勾连在一起，据说若果你心存诚意，登上试心石时石快便不会动摇，反之则摇动不止。");
	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"lianhua",
	]));
	set("objects", ([
		__DIR__"npc/yujizi" : 1,
		__DIR__"npc/yuyinzi" : 1,
		__DIR__"npc/yuqingzi" : 1,
	]));
*****************************************************/
};


FIELD_END;
