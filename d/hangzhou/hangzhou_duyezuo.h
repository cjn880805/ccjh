//duyezuo.h 杭州毒液地道左岸

ROOM_BEGIN(CRhangzhou_duyezuo);

virtual void create()		
{
	set_name( "毒液地道左岸");

	add_door("黄泥地道", "杭州黄泥地道", "杭州毒液地道左岸");
	add_door("毒液地道右岸", "杭州毒液地道右岸", "杭州毒液地道左岸");

	set("long","眼前是一个宽达数丈的水坑，坑中满是绿兮兮的毒液，看样子正是江湖中人见之胆寒的剧毒之物“化尸水”。除非中间有个物品支撑一下，否则以你的轻功是无法渡过的。");
    
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	AddMenuItem("跳", "$0tiao $1", me);
	SendMenu(me);
	return 1;
}


virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("wei/renwu8_5"))
		return 0;
	if(strcmp(comm, "tiao") == 0)
		return do_tiao(me, arg);
	return 0;
}


int do_tiao(CChar *me, char * arg)
{
	if(me->query_temp("wei/renwu8_9"))
	{
		tell_object(me,"\n$HIC你使足全力一跳，平平稳稳地落在了毒液地道右岸。");
		me->move(load_room("杭州毒液地道右岸"));
	}
	else if(me->query_temp("wei/renwu8_8"))
	{
		tell_object(me,"\n$HIC你奋力一跳，正好落在泥像头上。");
		me->set_temp("wei/renwu8_9",1);//跳到泥像头上
	}
	else
	{
		if(random(2))
			tell_object(me,"\n$HIC你刚准备跳起，突然脚底一滑，跌的鼻青脸肿。");
		else
			tell_object(me,"\n$HIC你看着满池的“化尸水”，心中不禁直发寒，两腿不由的哆嗦起来。");
	}
	return 1;
}

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"毒液地道右岸"))
	{
		if(!me->query_temp("wei/renwu8_5"))
		{
			message_vision("$HIR你是怎么混进来的？", me);
			return 0;
		}
		else
		{
			message_vision("$HIR眼前是一个宽达数丈的水坑，杭中满是绿兮兮的毒液，看样子正是江湖中人见之胆寒的剧毒之物“化尸水”。除非中间有个物品支撑一下，否则以$N的轻功是无法渡过的。", me);
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}
ROOM_END;
