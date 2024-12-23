//chufang.h

//Sample for room: 厨房
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGueiYun_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "厨房");

	add_npc("pub_cunfu");     // add by zdn 2001-07-13

	add_door("归云庄", "归云庄", "归云庄厨房");

	set("long"," 这里是归云庄的厨房，一个乡下妇人正在灶边忙来忙去，看来她就是这里的厨娘了。如果肚子饿了，就赶快找厨娘要 (serve)些吃的吧。" );
    
	set("ricewater", 5);

/*****************************************************
	set("exits", ([
		"south" : __DIR__"huayuan",
	]));
********************************************/
};


ROOM_END;
