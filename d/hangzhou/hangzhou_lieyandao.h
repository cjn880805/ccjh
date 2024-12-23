//duyezuo.h 杭州烈焰地道

ROOM_BEGIN(CRhangzhou_lieyandao);

virtual void create()		
{
	set_name( "烈焰地道");

	add_door("毒液地道右岸", "杭州毒液地道右岸", "杭州烈焰地道");
	add_door("铸铁地道", "杭州铸铁地道", "杭州烈焰地道");

	set("long","一股灼热的空气扑面而来，眼前是熊熊燃烧的烈火。");
    
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if (me->query_temp("wei/renwu8_5"))
	{
		AddMenuItem("挖", "$0wa $1", me);
	}
	SendMenu(me);
	return 1;
}

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		tell_object(me,"\n$HIR一股灼热的空气扑面而来，眼前是熊熊燃烧的烈火。");
		me->call_out(do_time, 5);
	}
}

static void do_time(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	if(EQUALSTR(env->querystr("base_name"),"杭州烈焰地道"))//在烈焰地道中
	{
		tell_object(me, "\n$HIR突然一股灼热的空气迎面扑来，你躲闪不及，结果造成了25点伤害。\n");
		me->add("hp",-25);
		if(me->query("hp")<1)
			me->set("hp",1);
		me->UpdateMe();
		me->call_out(do_time, 5);
	}
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("wei/renwu8_5"))
		return 0;
	if(strcmp(comm, "wa") == 0)
		return do_wa(me, arg);
	return 0;
}

int do_wa(CChar *me, char * arg)
{
	CContainer * weapon;
	CContainer * env=me->environment();
	weapon = me->query_weapon();
	char msg[255];
	if (! weapon)
	{
		tell_object(me,"\n$HIR手无寸铁，从何说起？");
	}
	else
	{
		if(weapon->querystr("owner")[0])
		{
			tell_object(me,snprintf(msg, 255,"\n$HIR你犹豫的看着手中的%s，舍不得用它去挖掘。",weapon->name(1)));
		}
		else
		{
			if(EQUALSTR(weapon->querystr("base_name"),"tieqiao"))
			{
				tell_object(me,"\n$HIR你用铁锹在地上挖了一条水沟。");
				if(me->query_temp("wei/renwu8_7"))
				{
					tell_object(me,"\n$HIW毒液沿水沟缓缓流了过来，逐渐把烈焰扑灭了，只留下一两处燃烧的余烬。");
					me->set_temp("wei/renwu8_10",1);//用铁锹挖出小沟扑灭烈焰
				}
			}
			else
			{
				tell_object(me,snprintf(msg, 255,"\n$HIR你拔出%s，向地上戳了几下，结果“啪”地一声折断了。",weapon->name(1)));
				weapon->move(env);
				weapon->set_name(snprintf(msg, 255, "断掉的%s", weapon->name(1)));
				weapon->set("value", 0l);
				weapon->del("apply");
			}
		}
	}
	return 1;
}

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"铸铁地道"))
	{
		if(!me->query_temp("wei/renwu8_5"))
		{
			message_vision("$HIR你是怎么混进来的？", me);
			return 0;
		}
		else
		{
			if(!me->query_temp("wei/renwu8_10") || !me->query_temp("wei/renwu8_7") )
			{
				message_vision("$HIR一股灼热的空气扑面而来，眼前是熊熊燃烧的烈火，$N不由的倒退几步。", me);
				return 0;
			}
		}
	}
	return CRoom::valid_leave(me, dir);
}
ROOM_END;
