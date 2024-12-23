//mjtianmen.h

//Sample for room: 天字门
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_mjtianmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天字门");

	add_door("明教青石阶4", "明教青石阶4", "明教天字门");
	add_door("天门男舍", "明教天门男舍", "明教天字门");

	set("long", "前面就是明教的“天字门”了，这里是明教中男弟子修炼的地方，从门口看进去，汗衫扬臭，木桌流酒。此处不允女人随意进入。" );
	

/*****************************************************
    set("exits", ([
        "enter" : __DIR__"nanshe",
        "southeast" : __DIR__"mjtianmen",
    ]));
    set("outdoors", "mingjiao");
********************************************/
};


ROOM_END;
