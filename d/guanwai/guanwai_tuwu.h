//tuwu.h

//Sample for room: 小土屋
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuanWai_tuwu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "小土屋");

	set("monster_chance", 50);
	//add npcs into the room
	add_npc("pub_heersu");
	
	add_door("关外宁远", "关外宁远", "关外宁远小土屋");

    set("long","这是一座用黄土垒成的小屋，屋内打扫的很干净。四周的墙壁上挂满了各种棍子，钎子，开山斧，小锯子等工具，看来似乎是采参所用的工具。屋内西面的火炕上坐着一位上了年纪的老人，正在吸着旱烟袋。" );

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
