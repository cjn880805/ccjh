//damen.h

//Sample for room: 达门
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_damen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "达门");

	set("resident", "关外达门");

	//add npcs into the room
	add_npc("guanwai_hufei");     // add by zdn 2001-07-13

	add_door("关外长白瀑布", "关外长白瀑布", "关外达门");
	add_door("关外龙门峰", "关外龙门峰", "关外达门");

    set("long","天池三面壅注不流，惟独北面偏东一线斜垂，白练飞舞，这就是达门。池水经达门外流，水流清冷，在石壁间冲撞有声。" );
    

/*****************************************************
	set("exits", ([
		"southwest"  : __DIR__"longmen",
		"northwest"  : __DIR__"pubu",
	]));
********************************************/
};


RESIDENT_END;
