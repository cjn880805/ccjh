//hetao.h

//Sample for room: 黄河河套
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_hetao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河河套");
	
	add_npc("monster_8k");     //add by zdn 2001-07-14

	add_door("黄河1", "黄河1", "黄河河套");
	add_door("黄河青城", "黄河青城", "黄河河套");
	add_door("黄河黄土高原", "黄河黄土高原", "黄河河套");

	set("long","常言到“黄河九害，富了一套”。河套地区灌溉系统发达，土地肥沃，是种庄稼的好地方。");
	

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"huangtu",
		"east"      : __DIR__"huanghe_1",
		"west"      : __DIR__"qingcheng",
	]));
********************************************/
};


CHANGAN_END;
