//huanghe7.h

//Sample for room: 黄河岸边7
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河岸边7");
	
	add_npc("monster_8k");        //add by zdn 2001-07-14


	add_door("黄河岸边6", "黄河岸边6", "黄河岸边7");
	add_door("黄河入海口", "黄河入海口", "黄河岸边7");

	set("long","这里是黄河岸边。黄河流淌到这里，河床宽阔。黄色的河水在静静地向东流去，使人忘记它发洪水时的狂威。");
    

/*****************************************************
	set("exits", ([
		"northeast" : __DIR__"huanghe8",
		"southwest" : __DIR__"huanghe6",
	]));
********************************************/
};


CHANGAN_END;
