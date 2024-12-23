//huanghe6.h

//Sample for room: 黄河岸边6
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河岸边6");
	
	add_npc("pub_tufei1");       //add by zdn 2001-07-14


	add_door("黄河岸边5", "黄河岸边5", "黄河岸边6");
	add_door("黄河岸边7", "黄河岸边7", "黄河岸边6");

	set("long","这里是黄河岸边。黄河流淌到这里，河床宽阔。黄色的河水在静静地向东流去，使人忘记它发洪水时的狂威。");

/*****************************************************
	set("exits", ([
		"northeast" : __DIR__"huanghe7",
		"southwest" : __DIR__"huanghe5",
	]));
	set("objects", ([
		__DIR__"npc/zu" : 1,
	]));
********************************************/
};


CHANGAN_END;
