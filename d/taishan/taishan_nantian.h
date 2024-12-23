//nantian.h

//Sample for room: 泰山南天门
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_nantian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山南天门");

	//add npcs into the room
	add_npc("pub_weishi2");/////////////////////////

	set("monster_chance", 50);
	set("monster_type", 2);

	add_door("泰山升仙坊", "泰山升仙坊", "泰山南天门");
	add_door("泰山天街", "泰山天街", "泰山南天门");
	add_door("泰山月观峰", "泰山月观峰", "泰山南天门");
	add_door("泰山玉皇顶", "泰山玉皇顶", "泰山南天门");

	set("long","走完了十八盘，这里便是泰山顶的入口处。从这里附视山下，群山如龟伏地，河流如蚓缠绕，天地空阔，无可名状。从这里往东北走可到一个市集，往西走便是月观峰，往北走则是到玉皇顶之路。");

/*****************************************************
	set("exits", ([
		"eastup" : __DIR__"tianjie",
		"northup" : __DIR__"yuhuang",
		"west" : __DIR__"yueguan",
		"southdown" : __DIR__"shengxian",
	]));
	set("objects",([
		__DIR__"npc/jiang" : 1,
		__DIR__"npc/wei-shi3" : 2,
	]));
*****************************************************/
};


FIELD_END;
