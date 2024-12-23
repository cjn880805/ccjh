//weifen.h

//Sample for room: 黄河渭汾流域
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_weifen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河渭汾流域");
	
	add_npc("pub_menmian");   //add by zdn 2001-07-14

	add_door("黄河1", "黄河1", "黄河渭汾流域");
	add_door("黄河岸边1", "黄河岸边1", "黄河渭汾流域");

	set("long","汾河和渭河汇入黄河，增大了其水势，也带来了更多的泥沙。这里河东是晋，河西是陕。");
    

/*****************************************************
	set("exits", ([
		"south" : __DIR__"huanghe1",
		"north" : __DIR__"huanghe_1",
		"southwest" : "/d/heimuya/road5",
		"northeast" : "/d/heimuya/dukou2",
	]));
********************************************/
};


CHANGAN_END;
