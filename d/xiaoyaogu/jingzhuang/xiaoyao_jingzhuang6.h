//jingzhuang6.h
//Sample for room: 大理城经幢6

ROOM_BEGIN(CRXiaoYao_jingzhuang6);

virtual void create()
{
	set_name( "大理城经幢6");
	set("no_autosave",1);

	add_door("大理城经幢5", "逍遥谷大理城经幢5", "逍遥谷大理城经幢6");
	add_door("大理城经幢7", "逍遥谷大理城经幢7", "逍遥谷大理城经幢6");

	set("long", "有神龛五座，内中雕有佛像浮雕二百余座。布局严密，层次分明；表情各异，比例协条；刀痕尤劲，备极精巧；线条流畅，栩栩如生；不愧是滇南石雕艺术的珍品。世代金文家皆赞 滇中艺术，此及品也 。" );
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"大理城经幢7"))
	{
		if(me->query("xy/renwu7_1") && !me->query("xy/renwu8"))
		{
			me->add_temp("xy/renwu7_2",1);//闭关室的入口需连续进入七次可以
			if(me->query_temp("xy/renwu7_2")>7 )
				return CRoom::valid_leave(me, dir);
		}
		me->move(load_room("逍遥谷大理城经幢1"));
		return notify_fail("你觉得眼前的路似曾相识，仿佛又回到了入口。");;
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
