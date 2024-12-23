//LingJiu_midao1.h

//Sample for room: 灵鹫缥缈峰后山密道1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_midao1);

virtual void create()			//Call it when Room Create
{
	set_name( "灵鹫后山密道1");

	add_door("灵鹫后山密道2", "灵鹫后山密道2", "灵鹫后山密道1");
	add_door("灵鹫花园", "灵鹫花园", "灵鹫后山密道1");
	set("no_fight",1);
};


ROOM_END;
