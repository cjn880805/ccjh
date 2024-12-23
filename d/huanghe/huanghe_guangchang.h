//guangchang.h

//Sample for room: 黄河广场
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_guangchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河广场");

	//add npcs into the room
	add_npc("pub_qian");

	add_door("黄河帮寨门", "黄河帮寨门", "黄河广场");
	add_door("黄河侠义厅", "黄河侠义厅", "黄河广场");

	set("long","广场占地甚大，部置严谨。往西过去可达黄河帮的「侠义厅」。周围则是些房舍，供帮众居住。");

/*****************************************************
	set("exits", ([
		"east"  : __DIR__"huanghegate",
		"west"  : __DIR__"xiayiting",
	]));
	set("objects", ([
		__DIR__"npc/wu" : 1,
		__DIR__"npc/qian" : 1,
	]));
********************************************/
};


CHANGAN_END;
