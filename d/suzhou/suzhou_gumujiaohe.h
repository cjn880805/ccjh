//gumujiaohe.h

//Sample for room: 古木交诃
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_gumujiaohe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "古木交诃");
	
	add_npc("pub_dipi");     //add by zdn 2001-07-16

	add_npc("pub_nieming");
	add_door("苏州荷花厅", "苏州荷花厅", "苏州古木交诃");

	set("long", "古木交诃在荷花厅的西面，一排不同图案的漏窗，使你透过漏窗隐隐看到中部的水光山色和高低错落的楼阁，此处赏景，有“移步幻影”之妙。向西窗孔可以遥望绿荫轩、明瑟楼，给人一种“庭院深深深几许”和空间不尽之感。" );
	

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
