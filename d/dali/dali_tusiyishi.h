//tusiyishi.h

//Sample for room: 议事厅
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_tusiyishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "议事厅");

	//add npcs into the room
	add_npc("dali_datusi");/////////////////////////
	add_npc("pub_zutouren");

	add_door("大理城土司府", "大理城土司府", "大理城土司府议事厅");

	set("long", "议事厅中央有神龛，龛下陈列着刀、叉、矛、戟等兵器。宽阔的大楼上下，柱梁粗实。厅堂宽敞，前后各有一长排坐栏，供人纳凉憩息。" );

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
