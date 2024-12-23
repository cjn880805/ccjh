//shanlu4.h

//Sample for room: 杭州山路4
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shanlu4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州山路4");
	
	add_npc("pub_flowerg");        //add by zdn 2001-07-14


	add_door("杭州山路5", "杭州山路5", "杭州山路4");
	add_door("杭州法喜寺", "杭州法喜寺", "杭州山路4");

	set("long","走在这弯弯的小路上，看着沿途山峰云影，松竹青葱，岩石斑驳。不禁感到胸怀舒畅。西上便到了上天竺。东下就到了龙井。" );

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
