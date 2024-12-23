//fanting.h

//Sample for room: 斋厅
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_fanting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "斋厅");

	CBox * box = Add_Box();
	box->add_object("qingshui_hulu", 1);	
	box->set_name( "铁柜");	

	add_door("少林寺厨房", "少林寺厨房", "少林寺斋厅");
	add_door("少林寺勤修场", "少林寺勤修场", "少林寺斋厅");




/*****************************************************
	set("exits", ([
		"east" : __DIR__"guangchang3",
		"north" : __DIR__"fanting1",
	]));
	set("objects",([
		__DIR__"obj/qingshui-hulu" : 1,
		names[random(sizeof(names))]: 1,
		names[random(sizeof(names))]: 1,		
	]));
//	
********************************************/
};


ROOM_END;
