//jingzhuang3.h
//Sample for room: 大理城经幢3

ROOM_BEGIN(CRXiaoYao_jingzhuang3);

virtual void create()
{
	set_name( "大理城经幢3");
	set("no_autosave",1);

	add_door("大理城经幢2", "逍遥谷大理城经幢2", "逍遥谷大理城经幢3");
	add_door("大理城经幢4", "逍遥谷大理城经幢4", "逍遥谷大理城经幢3");

	set("long", "雕绕绫坐像四座，坐像间之四面各雕佛及菩萨一组。识者谓北面多臂观音，南面为地藏菩萨。合神佛面目和蔼，雕刻精细，造形优美。" );
	
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
