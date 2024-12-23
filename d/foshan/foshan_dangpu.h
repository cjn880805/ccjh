//dangpu.h

//Sample for room: 英雄典当
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRFoShan_dangpu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "英雄典当");

	//add npcs into the room
	add_npc("pub_chaofeng");
	
	add_door("佛山", "佛山", "佛山英雄典当");

	set("long", "当铺里一张高高的柜台，柜台后面坐着当铺的朝奉。这家当铺是凤老爷所开，十多年来从没人来闹过事，朝奉也就很放心。柜台上挂着一个木牌子(paizi)。" );
	set("no_fight", 1);
	set("no_steal", 1);
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
