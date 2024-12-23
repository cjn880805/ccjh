//xiaoyao_shishi1.h 琅擐福地石室1（掌法室）
//秦波 2003、3、15

XiaoYao_BEGIN(CRXiaoYao_shishi1);

virtual void create()
{
	set_name( "石室1");
	set("no_autosave",1);
	set("long","这是座圆形石室，四壁岩石打磨得甚是光滑，石壁上刻满了无数径长尺许的圆圈，每个圈中都刻了各种各样的图形。。");

	add_door("琅擐福地", "逍遥谷琅擐福地", "逍遥谷琅擐福地石室1");
	set("index",1);
	add_item("shiguei");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query_temp("xy/renwu6_4") && me->query("xy/renwu6") )
	{
		say("你仔细研究着墙上的图案，隐隐约约中，只见壁上画了两人在对掌，掌化万千，纵横交错，变化莫测，一看就是一种很高深的掌法。", me);
	}
	SendMenu(me);
	return 1;
}

XiaoYao_END;
