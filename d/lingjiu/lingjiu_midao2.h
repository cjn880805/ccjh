//LingJiu_midao2.h
//Sample for room: 灵鹫缥缈峰后山密道2


ROOM_BEGIN(CRLingJiu_midao2);

virtual void create()			//Call it when Room Create
{
	set_name( "灵鹫后山密道2");

	add_door("灵鹫后山密道1", "灵鹫后山密道1", "灵鹫后山密道2");
	add_door("灵鹫后山密道3", "灵鹫后山密道3", "灵鹫后山密道2");
	set("no_fight",1);
};


ROOM_END;
