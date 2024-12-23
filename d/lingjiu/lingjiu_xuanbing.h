//xuanbing.h

//Sample for room: 灵鹫玄冰室
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_xuanbing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫玄冰室");


	add_door("灵鹫画廊13", "灵鹫画廊13", "灵鹫玄冰室");

	set("long", " 这是修练内功的地方。 屋子正中有一块千年玄冰(ice)，冰上冒出丝丝寒气， 屋里因此寒气逼人，你不由得打了一个寒颤。" );
	

/*****************************************************
    set("exits", ([
		"east" : __DIR__"changl13",
        ]));
	set("item_desc", ([
	    "ice" : "这是一块采自天山之巅的千年玄冰,据说在那上面打坐事半功倍.\n你可以试着爬(climb)上去.\n",
	]));
********************************************/
};


ROOM_END;
