//huanghe_1.h

//Sample for room: 黄河1
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe_1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河1");
	
	add_npc("huanghe_shen");      //add by zdn 2001-07-14


	add_door("黄河河套", "黄河河套", "黄河1");
	add_door("黄河渭汾流域", "黄河渭汾流域", "黄河1");

	set("long","黄河沿蒙古高原南边向东流淌，遇太行山脉的阻拦，便转头南下，形成晋陕的分界。东北方向好象有个渡口。");
    

/*****************************************************
	set("exits", ([
		"south"     : __DIR__"weifen",
		"west"      : __DIR__"hetao",
	]));
********************************************/
};


CHANGAN_END;
