//rjyuan.h
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_rjyuan);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "明教大院");

	add_door("天微堂", "明教天微堂", "明教大院");
	add_door("天微堂", "明教天微堂", "明教大院");

	set("long", "你走进了锐金旗的大院，却发现这里人影稀疏，虽听见叮叮咚咚的打铁声，却见不到打铁铺，那声音似乎是从深远的地下传来的。向西走，就要进入门楼了。院子左首可能是练武场，隐约传来打斗声；右首是一座大厅，象是锐金旗的议会场所。    冷谦执掌明教刑堂。");
    

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
