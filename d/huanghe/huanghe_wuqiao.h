//wuqiao.h

//Sample for room: 黄河乌鞘岭
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_wuqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河乌鞘岭");
	
	add_npc("pub_liumang");    // add by zdn 2001-07-14


	add_door("黄河打柴沟", "黄河打柴沟", "黄河乌鞘岭");
	add_door("黄河武威", "黄河武威", "黄河乌鞘岭");

	set("long","乌鞘岭是武威东南的一个险要地段，黑石山上密林重重，时常有野兽出没。一条官道从山下蜿蜒而过。");
	

/*****************************************************
	set("exits", ([
		"south"     : __DIR__"dacaigou",
		"northwest" : __DIR__"wuwei",
	]));
********************************************/
};


CHANGAN_END;
