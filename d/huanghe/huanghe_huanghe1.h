//huanghe1.h

//Sample for room: 黄河岸边1
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河岸边1");

	//add npcs into the room
	add_npc("pub_houxiahai");

	add_door("黄河田地4", "黄河田地4", "黄河岸边1");
	add_door("黄河岸边2", "黄河岸边2", "黄河岸边1");
	add_door("黄河帮寨门", "黄河帮寨门", "黄河岸边1");
	add_door("黄河渭汾流域", "黄河渭汾流域", "黄河岸边1");

	set("long","这里是黄河岸边。黄河流淌到这里，已经泥沙浑浊了。黄色的河水在河床里翻滚着，咆哮着，卷起一个个巨大的漩窝。西边有个寨子。");
    

/*****************************************************
	set("exits", ([
		"south" : __DIR__"tiandi4",
		"north" : __DIR__"weifen",
		"east"  : __DIR__"huanghe2",
		"west"  : __DIR__"huanghegate",
	]));
	set("objects", ([
		__DIR__"npc/hou" : 1,
	]));
********************************************/
};


CHANGAN_END;
