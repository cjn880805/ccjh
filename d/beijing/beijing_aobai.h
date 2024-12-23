//aobai.h

//Sample for room: 鳌府大门
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_aobai);

virtual void create()
{
	set_name( "鳌府");

	add_npc("pub_bing");
	add_npc("shaolin_aobai");
	add_npc("pub_sunchengxian");//礼部侍郎孙承宪
	
	add_door("北京东南", "北京东南", "北京鳌府");

	set("long", "一座富丽堂皇的大宅院出现在你的眼前，两头高大的石狮子镇住了大门两侧。门额上悬挂一方横匾，写着‘满洲第一勇士鳌拜府’几个大字，门外有官兵把守，戒备森严。门上挂着两个灯笼，赫然写着“鳌”字。" );

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
