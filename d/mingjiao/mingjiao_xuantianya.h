//xuantianya.h
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_xuantianya);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "明教悬天崖");

	add_npc("mingjiao_xiaozhao");

	add_door("明教青石大道3", "明教青石大道3", "明教悬天崖");
	add_door("明教烈火旗牌坊", "明教烈火旗牌坊", "明教悬天崖");

	set("long", "这里山路陡峭，仅有一人多宽，路左是峭壁高耸，路右紧临万丈深渊，实在是一夫当关、万夫莫开的险要之处。继续上攀，就要到达明教五行旗了。紧挨路右，天然生有一块巨石，高近三丈，名为“悬天石”，常有侠客于上远观云海。    冷谦执掌明教刑堂。");
    

/*****************************************************
	set("exits", ([
		"west" : __DIR__"rjqmenlou1",
		"north" : __DIR__"rjqdating",
		"south" : __DIR__"rjqlwch",
        "out": __DIR__"rjqmen",
	]));
********************************************/

};



ROOM_END;
