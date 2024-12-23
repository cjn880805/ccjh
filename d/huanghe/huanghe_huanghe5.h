//huanghe5.h

//Sample for room: 黄河岸边5
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河岸边5");
	
	add_npc("pub_liumang");
	add_npc("pub_liumang");         //add by zdn 2001-07-14


	add_door("黄河岸边4", "黄河岸边4", "黄河岸边5");
	add_door("黄河岸边6", "黄河岸边6", "黄河岸边5");
	add_door("泰山山脚", "泰山山脚", "黄河岸边5");
	add_door("南阳城", "南阳城", "黄河岸边5");	

	set("long","这里是黄河岸边。黄河流淌到这里，河床宽阔。黄色的河水在静静地向东流去，使人忘记它发洪水时的狂威。");
    

/*****************************************************
	set("exits", ([
		"east"      : "/d/taishan/daizong",
		"northeast" : __DIR__"huanghe6",
		"southwest" : __DIR__"huanghe4",
	]));
********************************************/
};


CHANGAN_END;
