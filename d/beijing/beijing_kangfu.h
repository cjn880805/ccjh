//kangfu.h

//Sample for room: 康府大门
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_kangfu);

virtual void create()			
{
	set_name( "北京康府");

	add_npc("pub_shiwei");
	add_npc("shaolin_shenzhao");
	add_npc("pub_jinjiu");

	set("no_fight",1);
	set("no_cast",1);
	
	add_door("北京东北", "北京东北", "北京康府");

	set("long", "一座富丽堂皇的大宅院出现在你的眼前，两头高大的石狮子镇住了大门两侧。门外有带刀侍卫把守，戒备森严。门上挂着两个灯笼，赫然写着大大的“康”字。" );

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
