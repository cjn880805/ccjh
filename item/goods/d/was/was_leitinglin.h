//zhanshu.h
ITEM_BEGIN(CIwas_leitinglin)

virtual void create(int nFlag = 0)		
{
	set_name("雷霆救兵令牌", "lei ting lin");
	set("long",	"这就是黑黝黝的令牌。");
	set("unit", "块");
	set_weight(1000);
};


virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * who)
{
	CContainer * env =me->environment();
	if(who == me)
	{
		return notify_fail("不能对自己使用。");
	}
	else if(!who->Query(CChar::IS_LIVING) )
	{
		return notify_fail("此时不能对此人使用！");
	}
	else if(!userp(who))
	{
		return notify_fail("不能对此人使用！");
	}
	else if(!who->query_temp("was/renwu2_3"))
	{
		return notify_fail("不能对此人使用！！");
	}
	else if(DIFFERSTR(env->querystr("name"),"大型马车"))
	{
		return notify_fail("不能在此地使用！！");
	}
	else if(!me->query_temp("was/renwu2_3")||EQUALSTR(querystr("owner"),me->id(1)))
	{
		return notify_fail("你不能使用此物品！");
	}
	else if(EQUALSTR(who->querystr("family/family_name"),me->querystr("family/family_name")))
	{
		return notify_fail("不能对此人使用！！！");
	}
	else if(who->query_temp("was/renwu2_4"))
	{
		return notify_fail("不能对此人使用！！！！");
	}
	else
	{
		message_vision("\n$YEL$N对$n使用雷霆救兵令牌。", me,who);
		who->set_temp("was/renwu2_4",1);//对欲组队人员使用了雷霆救兵令牌
		if(me->query_temp("was/renwu2_4"))
		{
			message_vision("$YEL只见两面雷霆救兵令牌闪烁出耀眼的光辉，然后都消失了。\n", me);
			message_vision("\n$YEL$N对与$n组成营救小分队。", me,who);
			me->set_temp("was/renwu2_5",1);//完成组队
			who->set_temp("was/renwu2_5",1);
			me->set_temp("was/队友",who->id(1));
			who->set_temp("was/队友",me->id(1));
			me->set_temp("was/master",1);//队长
			who->set_temp("was/leader",1);//跟随者
			me->call_out(go_end,60);
			who->call_out(go_end,60);
			((CChar * )who)->set_leader(me);
			message_vision("\n$YEL$N决定与$n一起行动。", me,who);
		}
		destruct(this);
	}
	return 1;
}

static void go_end(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me =(CChar *)ob;
	CContainer * env =me->environment();
	if(env->query("count")>1)
	{
		tell_object(me,"\n$YEL你经过一段崎岖的路程，车夫大喊道：“吁~~~！各位客倌请下车，到了！”\n");
		me->move(load_room("北京万安寺外"));
	}

}
ITEM_END;


