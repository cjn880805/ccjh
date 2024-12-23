//dmyuan2.h

//Sample for room: 达摩院二楼")
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_dmyuan2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "达摩院二楼");

	add_npc("shaolin_xuan_bei");

	CBox * box = Add_Box();
	box->add_object("xisuijing", 1);	
	box->set_name( "漆柜");
	
	add_door("少林寺达摩院", "少林寺达摩院", "少林寺达摩院二楼");


/*****************************************************
	set("exits", ([
		"down" : __DIR__"dmyuan",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/xuan-bei" : 1,
		"/clone/book/xisuijing" : 1,
		__DIR__"npc/xiao-bei" : 1,
	]));
********************************************/
};


ROOM_END;
