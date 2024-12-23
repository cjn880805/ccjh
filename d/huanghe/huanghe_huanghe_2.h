//huanghe_2.h

//Sample for room: 黄河2
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe_2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河2");
	
	add_npc("monster_20k");        //add by zdn 2001-07-14
	add_npc("pub_hahazi");

	add_door("黄河3", "黄河3", "黄河2");
	add_door("黑木崖龙门渡口", "黑木崖龙门渡口", "黄河2");

	set("long","黄河出了青海，经甘肃之后，向东受到黄土高原的阻挡，转而向东北流去。在流经黄土高原的过程中泥沙含量猛增，水色澄黄，就被称为黄河。");
    

/*****************************************************
	set("exits", ([
		"west"      : __DIR__"huanghe_3",
		"northeast" : __DIR__"huangtu",
	]));
********************************************/
};


CHANGAN_END;
