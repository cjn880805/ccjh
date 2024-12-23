//ertian.h

//Sample for room: 泰山二天门
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_ertian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山二天门");

	set("monster_chance", 40);
	set("monster_type", 2);

	add_door("泰山回马岭", "泰山回马岭", "泰山二天门");
	add_door("泰山五大夫松", "泰山五大夫松", "泰山二天门");

	set("long","这里又叫「中天门」。一般的登山者来到这里都已累极，但是这里才是泰山的一半啊！面对前面险峻的十八盘，很多人都不禁犹豫起来。");
	

/*****************************************************
	set("exits", ([
		"northup" : __DIR__"wudafu",
		"southdown" : __DIR__"huima",
	]));
	set("objects",([
		__DIR__"npc/tiao-fu" : 1,
		__DIR__"npc/tiansong" : 1,
		__DIR__"npc/tianbai" : 1,
	]));
*****************************************************/
};


FIELD_END;
