//LingJiu_midao3.h
//Sample for room: 灵鹫缥缈峰后山密道3


ROOM_BEGIN(CRLingJiu_midao3);

virtual void create()			//Call it when Room Create
{
	set_name( "灵鹫后山密道3");

	add_door("灵鹫后山密道2", "灵鹫后山密道2", "灵鹫后山密道3");
	add_door("灵鹫后山石室", "灵鹫后山石室", "灵鹫后山密道3");
	set("no_fight",1);
};


ROOM_END;
