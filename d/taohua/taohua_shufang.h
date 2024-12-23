//shufang.h

//Sample for room: 桃花山庄书房
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_shufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "桃花山庄书房");

	add_npc("taohua_qu");

	CBox * box = Add_Box();
	if(!random(10))
		box->add_object("baomingdan", 1);	
	else
	{
		box->add_object("jiuhua", 1);
		box->add_object("jiuhua", 1);
		box->add_object("jiuhua", 1);
	}
	box->set_name("药瓶", "hole");
	box->Locked("密封", 10000);
		
	add_door("桃花岛卧房", "桃花岛卧房", "桃花山庄书房");


/*****************************************************
	set("exits", ([
		"down" : __DIR__"daojufang",
	]));
	set("objects", ([
		"/clone/book/yijing"+random(4) : 1,
		"/clone/book/yijing"+random(4) : 1,
		"/clone/book/bagua"+random(2)  : 1,
		CLASS_D("taohua")+"/qu": 1,
	]) );
********************************************/
};


ROOM_END;
