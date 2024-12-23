//dacaigou.h

//Sample for room: 黄河打柴沟
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_dacaigou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河打柴沟");

	//add npcs into the room
	add_npc("pub_qiaofu");

	add_door("黄河古浪", "黄河古浪", "黄河打柴沟");
	add_door("黄河乌鞘岭", "黄河乌鞘岭", "黄河打柴沟");

	set("long","打柴沟地势不如乌鞘岭那样险要，比较平坦，官道两边全是密林，时常有樵夫砍柴的声音从林中传出。");
	

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"gulang",
		"north"     : __DIR__"wuqiao",
	]));
	set("objects", ([
		__DIR__"npc/qiaofu" : 1,
	]));
********************************************/
};


CHANGAN_END;
