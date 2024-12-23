//chashi.h

//Sample for room: 茶室
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRhangzhou_chashi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "茶室");
	
	add_npc("pub_susu");             // add by zdn 2001-07-14

	add_door("杭州龙井", "杭州龙井", "杭州茶室");

	set("long","这里是龙井茶茶室。在这里可以品到最新鲜的龙井。" );
	

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
