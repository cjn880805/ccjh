//dangpu.h

//Sample for room: 当铺
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_dangpu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "当铺");

	//add npcs into the room
	//add_npc("jia");
	
	add_door("北京皇城", "北京皇城", "北京当铺");

	set("long", "这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，柜台上摆着一个牌子(paizi)，柜台后坐着贾老板，一双精明的眼睛上上下下打量着你。" );
	set("no_fight", 1);
	set("no_beg",1);

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
