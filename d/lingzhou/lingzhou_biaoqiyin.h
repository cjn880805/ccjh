//biaoqiyin.h

//Sample for room: 骠骑营
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_biaoqiyin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "骠骑营");

	//add npcs into the room
	add_npc("pub_xixiabing");/////////////////////////

	add_door("灵州西", "灵州西", "灵州骠骑营");

	set("long", "这里是皇室禁卫军的驻地，在灵州城西北，骠骑营占地面积庞大，北面是营房，南面是小校场，西面紧挨着城墙是一排马厩，有东营门和南营门通向皇宫和大街。骠骑营的军士俱是西夏军中千挑万选的猛士，平时负责皇城外围的警戒，皇上出巡时便挑起开道护卫的重责，战时更是一支生力军。");  

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
