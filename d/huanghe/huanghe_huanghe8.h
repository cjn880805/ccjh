//huanghe8.h

//Sample for room: 黄河入海口
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河入海口");

	add_npc("pub_tangseng");
	
	add_door("黄河岸边7", "黄河岸边7", "黄河入海口");

	set("long","黄河流经青藏高原、黄土高原、华北平原，总长一万零九百里，在这里汇入大海。");
	

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"huanghe7",
	]));
********************************************/
};


CHANGAN_END;
