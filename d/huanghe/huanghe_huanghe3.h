//huanghe3.h

//Sample for room: 黄河岸边3
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河岸边3");

	//add npcs into the room
	add_npc("pub_bangzong");

	add_door("黄河岸边2", "黄河岸边2", "黄河岸边3");
	add_door("黄河岸边4", "黄河岸边4", "黄河岸边3");

	set("long","这里是黄河岸边。黄河流淌到这里，已经泥沙浑浊了。黄色的河水在河床里翻滚着，咆哮着，卷起一个个巨大的漩窝。");
	

/*****************************************************
	set("exits", ([
		"east"  : __DIR__"huanghe4",
		"west"  : __DIR__"huanghe2",
	]));
	set("objects", ([
		__DIR__"npc/bangzong" : 1,
	]));
********************************************/
};


CHANGAN_END;
