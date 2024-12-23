//wudafu.h

//Sample for room: 泰山五大夫松
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_wudafu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山五大夫松");

	set("monster_chance", 30);
	set("monster_type", 2);

	add_door("泰山二天门", "泰山二天门", "泰山五大夫松");
	add_door("泰山龙门", "泰山龙门", "泰山五大夫松");

	set("long","相传当年秦始皇上泰山，来到这里下起雨来，他就到两棵松树底下避雨，结果没淋着。因此，他就封这两棵松树为「五大夫」。后来不知从哪里来了一块巨大的飞来石把两棵松树砸死了。后人再在旁补种五株松树。在不远处还有一个御帐坪，据说就是秦始皇当年结帐的位置。从这里再往山上走便会到达十八盘的入口。");
	

/*****************************************************
	set("exits", ([
		"northup" : __DIR__"longmen",
		"southdown" : __DIR__"ertian",
	]));
*****************************************************/
};


FIELD_END;
