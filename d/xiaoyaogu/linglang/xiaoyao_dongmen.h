//xiaoyao_dongmen.h 琅擐福地洞门
//秦波 2003、3、15

XiaoYao_BEGIN(CRXiaoYao_dongmen);

virtual void create()
{
	set_name( "琅擐福地洞门");
	set("no_autosave",1);
	set("long","只见洞门上的山石中，刻着四个龙飞凤舞的大字“琅擐福地”。");

	add_door("琅擐福地", "逍遥谷琅擐福地", "逍遥谷琅擐福地洞门");
	add_door("飞凌九宵阁正门", "逍遥谷飞凌九宵阁正门", "逍遥谷琅擐福地洞门");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

XiaoYao_END;
