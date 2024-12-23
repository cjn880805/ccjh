//huangtu.h

//Sample for room: 黄河黄土高原
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huangtu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河黄土高原");
	
	add_npc("monster_8k");
	add_npc("monster_6k");            // add by zdn 200-07-14
	add_npc("pub_lianjin");

	add_door("黑木崖龙门渡口", "黑木崖龙门渡口", "黄河黄土高原");
	add_door("黄河河套", "黄河河套", "黄河黄土高原");

	set("long","黄河像一把厉刃将黄土高原切开。无数条小溪流夹带着泥沙汇入黄河，形成千沟万壑。沟壑之间的一块块平地叫做台塬。黄河沿蒙古高原南边向东流淌，遇太行山脉的阻拦，便转头南下，形成晋陕的分界。");
    

/*****************************************************
	set("exits", ([
		"northeast" : __DIR__"hetao",
		"southwest" : __DIR__"huanghe_2",
	]));
********************************************/
};


CHANGAN_END;
