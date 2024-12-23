//huanggongzhengmen.h

//Sample for room: 皇宫正门
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_huanggongzhengmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "皇宫正门");

	//add npcs into the room
	add_npc("pub_shiwei2");
	add_npc("pub_wujiang");
	add_npc("pub_bing");
	
	add_door("北京", "北京", "北京皇宫正门");

	set("long", " 这便是皇宫正门。巍峨雄伟的城墙上，'紫禁城'三个大字十分显眼，气势辉煌。一张镶金边的告示(gaoshi)贴在墙上，许多官兵立在两旁。" );
	set("outdoors", "city2");

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
