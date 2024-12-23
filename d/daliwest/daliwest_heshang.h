//heshang.h

//Sample for room: 河上
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_heshang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "河上");
	
	add_npc("dali_enu");      //add by zdn 2001-07-20


	add_door("大理城河边", "大理城河边", "大理城河上");
	add_door("大理城苍山山路", "大理城苍山山路", "大理城河上");

	set("long", "你正身处波涛滚滚的泸水之上百多尺的空中。这是一座乌夷族特有之藤桥，三根粗大的藤条呈一个倒“品”字形，脚踩下面一条，手扶左右两条，攀援而过看来惊险，实际上倒也不十分困难。一阵山风挟着脚下激流飞溅的水花吹过，你感到一阵寒意。" );
	
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
