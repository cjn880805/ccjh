//jingzhuang4.h
//Sample for room: 大理城经幢4

ROOM_BEGIN(CRXiaoYao_jingzhuang4);

virtual void create()
{
	set_name( "大理城经幢4");
	set("no_autosave",1);

	add_door("大理城经幢3", "逍遥谷大理城经幢3", "逍遥谷大理城经幢4");
	add_door("大理城经幢5", "逍遥谷大理城经幢5", "逍遥谷大理城经幢4");

	set("long", "雕有八坐佛，四隅略大，其中东、南两佛面目驳落，容不可辨。坐佛莲花座皆有梵文佛经。经文尾处刻有“慈济和尚--大理人”字样。" );
	
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
