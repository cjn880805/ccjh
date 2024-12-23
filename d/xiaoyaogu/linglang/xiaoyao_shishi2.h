//xiaoyao_shishi2.h 琅擐福地石室2（剑法室）
//秦波 2003、3、15

XiaoYao_BEGIN(CRXiaoYao_shishi2);

virtual void create()
{
	set_name( "石室2");
	set("no_autosave",1);
	set("long","这是座圆形石室，四壁岩石打磨得甚是光滑，石壁上刻满了无数径长尺许的圆圈，每个圈中都刻了各种各样的图形。。");

	add_door("琅擐福地", "逍遥谷琅擐福地", "逍遥谷琅擐福地石室2");
	set("index",2);
	add_item("shiguei");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query_temp("xy/renwu6_4") && me->query("xy/renwu6") )
	{
		say("你仔细研究着墙上的图案，但见千百文字之中，有些笔划宛然便是一把长剑，共有二三十把，觉得其中似乎隐藏着一种很高深的剑法。", me);
	}
	SendMenu(me);
	return 1;
}

XiaoYao_END;
