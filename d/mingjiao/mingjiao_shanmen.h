//shanmen.h
//Sample for room: 刑堂
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_shanmen);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "明教山门");
	
	add_npc("pub_menwei1");	
	add_npc("pub_menwei1");	
	add_npc("mingjiao_jieyinshi");	
	add_npc("zm_mingjiao");	

	add_item("was_mache");
	set("count",1);

	add_door("明教青石大道2", "明教青石大道2", "明教山门");
	add_door("明教青石大道3", "明教青石大道3", "明教山门");

	set("long", "一个巨大的天然石桥横跨在两片山壁之间，石桥正上方龙盘凤舞刻着两个大字：『明教』。字迹有些剥落，看上去年代久远。两位三十来岁的大汉手持钢剑守在山门两侧。    冷谦执掌明教刑堂。");
    
};

ROOM_END;
