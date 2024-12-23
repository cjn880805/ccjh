//jingzhuang2.h
//Sample for room: 大理城经幢2

ROOM_BEGIN(CRXiaoYao_jingzhuang2);

virtual void create()
{
	set_name( "大理城经幢2");
	set("no_autosave",1);

	add_door("大理城经幢1", "逍遥谷大理城经幢1", "逍遥谷大理城经幢2");
	add_door("大理城经幢3", "逍遥谷大理城经幢3", "逍遥谷大理城经幢2");

	set("long", "为四神坐像，各有表情，衣褶隆起，筋节毕现，肌肉暴起，极富立体感。" );
	
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
