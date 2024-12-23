//zhangfu.h
//Sample for room: 张府大门

ROOM_BEGIN(CRBeiJing_zhangfu);

virtual void create()			
{
	set_name( "北京张府");

	add_npc("pub_shiwei");
	add_npc("pub_shiwei");
	
	add_door("北京东北", "北京东北", "北京张府");
	add_door("北京张府大厅", "北京张府大厅", "北京张府");

	set("long", "一座富丽堂皇的大宅院出现在你的眼前，两头高大的石狮子镇住了大门两侧。门外有带刀侍卫把守，戒备森严。门上挂着两个灯笼，赫然写着大大的“张”字。" );

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
