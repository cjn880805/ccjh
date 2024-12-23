//zhangren.h

//Sample for room: 泰山丈人峰
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_zhangren);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山丈人峰");

	set("monster_chance", 20);
	//add npcs into the room
	add_npc("pub_weishi2");
	
	add_door("泰山玉皇顶", "泰山玉皇顶", "泰山丈人峰");
	add_door("泰山北天门", "泰山北天门", "泰山丈人峰");

	set("long","这里位于玉皇顶以西里许的地方，形状有如一个伛偻的老人。靠西有黄华洞，因洞路极为危险，后人在进路处写上「回车岩」。从这里往北走便是岱顶的北天门。");
	

/*****************************************************
	set("exits", ([
		"east" : __DIR__"yuhuang",
		"northup" : __DIR__"beitian",
	]));
	set("objects",([
		__DIR__"npc/wei-shi1" : 2,
	]));
*****************************************************/
};


FIELD_END;
