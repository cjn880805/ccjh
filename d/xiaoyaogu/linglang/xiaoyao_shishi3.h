//xiaoyao_shishi3.h 琅擐福地石室3(刀法室)
//秦波 2003、3、15

XiaoYao_BEGIN(CRXiaoYao_shishi3);

virtual void create()
{
	set_name( "石室3");
	set("no_autosave",1);
	set("long","这是座圆形石室，四壁岩石打磨得甚是光滑，石壁上刻满了无数径长尺许的圆圈，每个圈中都刻了各种各样的图形。。");

	add_door("琅擐福地", "逍遥谷琅擐福地", "逍遥谷琅擐福地石室3");
	set("index",3);
	add_item("shiguei");
	add_npc("xy_xiaoyaozi1");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query_temp("xy/renwu6_4") && me->query("xy/renwu6") )
	{
		say("你仔细研究着墙上的图案，隐隐约约中，觉得其中似乎隐藏着一种很高深的刀法。", me);
	}
	SendMenu(me);
	return 1;
}
XiaoYao_END;
