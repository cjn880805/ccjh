//zhongxin.h

//Sample for room: 城中心
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRQuanZhou_zhongxin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "城中心");
	
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	add_npc("pub_playboy");                  //add by zdn 2001-07-14


	add_door("泉州", "泉州", "泉州城中心");

	set("long", "泉州是一个安静的港城。虽然这里是城中心，人们也只是脚步轻轻地过往，并不喧哗。东面是一个港口，从那里可以出海。西面有一条小巷。 " );
	set("outdoors", "quanzhou");
/*****************************************************
	set("exits", ([
                "north" : __DIR__"beimen",
                "south" : __DIR__"nanmen",
                "east"  : __DIR__"haigang",
                "west"  : __DIR__"ximen",
	]));
        set("objects",([
		__DIR__"npc/youxun" : 1,
        ]));
//	

********************************************/
};


ROOM_END;
