//mjleimen.h

//Sample for room: 雷字门
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_mjleimen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "雷字门");


	add_door("明教青石阶4", "明教青石阶4", "明教雷字门");
	add_door("雷门宿舍", "明教雷门宿舍", "明教雷字门");

	set("long", "前面就是明教的“雷字门”了，这里是明教中西域弟子修炼的地方。西域风俗大异中土，他们的生活习惯以及使用物品也与中土迥异。" );
	
 
/*****************************************************
    set("exits", ([
        "enter" : __DIR__"sushe",
        "northeast" : __DIR__"mjleimen",
    ]));
    set("outdoors", "mingjiao");
********************************************/
};


ROOM_END;
