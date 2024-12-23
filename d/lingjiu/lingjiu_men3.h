//men3.h

//Sample for room: 灵鹫闭关室大门
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_men3);

virtual void create()			
{

	set_name( "灵鹫闭关室大门");


	add_npc("lingjiu_shi");/////////////////////////

	add_door("灵鹫小道2", "灵鹫小道2", "灵鹫闭关室大门");
	add_door("灵鹫闭关室", "灵鹫闭关室", "灵鹫闭关室大门");


	

/*****************************************************
        set("exits", ([
		"north" : __DIR__"biguan",
		"south" : __DIR__"xiaodao2",
        ]));
    	set("objects",([
                __DIR__"npc/shisao" : 1,
        ]));
********************************************/
};


ROOM_END;
