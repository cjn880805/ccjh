//xiaodao2.h

//Sample for room: 灵鹫小道2
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_xiaodao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫小道2");


	add_npc("pub_cungu");

	add_door("灵鹫小道1", "灵鹫小道1", "灵鹫小道2");
	add_door("灵鹫闭关室大门", "灵鹫闭关室大门", "灵鹫小道2");

	set("long", "一条小道蜿延曲折地通向远方, 两旁是郁郁葱葱的树林，微风吹过，树叶发出奚索的声音" );

/*****************************************************
 	set("outdoors", "lingjiu");
        set("exits", ([
            "north" : __DIR__"men3",
            "south" : __DIR__"xiaodao1",
        ]));
        set("objects",([
            "/d/baituo/npc/cungu" : 2,
        ]));
********************************************/
};


ROOM_END;
