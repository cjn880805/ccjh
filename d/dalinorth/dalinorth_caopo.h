//caopo.h

//Sample for room: 大理城村外草坡
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiNorth_caopo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城村外草坡");

	//add npcs into the room
	add_npc("pub_muyangren");
	add_npc("pub_muyangnu");
	add_npc("baiyang");
	add_npc("baiyang");

	add_door("大理城乌蒙村落", "大理城乌蒙村落", "大理城村外草坡");

	set("long", "一大片山坡长满青草，正是放牧牛羊的好地方。这里地势甚高，天空呈深蓝色，附近山岭树木已经甚少，基本上都是低矮灌木或草地。不少附近的村民在此放牧。");
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
