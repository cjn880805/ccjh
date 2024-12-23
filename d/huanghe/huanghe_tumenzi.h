//tumenzi.h

//Sample for room: 黄河土门子
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_tumenzi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河土门子");
	
	add_npc("monster_32k");       // add by zdn 2001-07-14


	add_door("黄河武威", "黄河武威", "黄河土门子");
	add_door("黄河石峡子", "黄河石峡子", "黄河土门子");

	set("long","土门子也是以前驻军的地方，周围全是沙漠，中间一块小小的绿洲，本来这里有当地的牧民居住，可是前不就来了一伙马贼占据了这里以这里为大本营四出劫掠，无恶不做。");
	

/*****************************************************
	set("exits", ([
		"south"     : __DIR__"wuwei",
		"northeast" : __DIR__"shixiazi",
	]));
********************************************/
};


CHANGAN_END;
