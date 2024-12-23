//xy_jingzhuang7.h
//Sample for room: 大理城经幢7

ROOM_BEGIN(CRXiaoYao_jingzhuang7);

virtual void create()
{
	set_name( "大理城经幢7");
	set("no_autosave",1);

	add_door("闭关室", "逍遥谷闭关室", "逍遥谷大理城经幢1");
	add_door("大理城经幢6", "逍遥谷大理城经幢6", "逍遥谷大理城经幢7");

	set("long", "这里是经幢的顶部，圆弧形顶篷，向徵天穹。上面刻有诸天神佛，飞天力士等。" );
	
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
