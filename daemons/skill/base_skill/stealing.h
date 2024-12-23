//stealing.h 偷窃之术

SKILL_BEGIN(CSstealing);

virtual void create()
{
	set_name( "偷窃术");

	set("special", 1);

	Magic_t * magic;

	magic = add_magic("steal", do_steal);
	magic->name = "偷窃";
	magic->mp = 30;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;	
}

virtual const char * type() { return "knowledge"; }

//可以学1级，然后使用法术
virtual int valid_learn(CChar * me)
{
	if(me->query_skill("stealing", 1) > 20)
		return notify_fail("偷窃术要在实践中提高。");

	return 1;
}

//perform 
static int do_steal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( (me->environment())->query("no_fight") )
		return notify_fail("这里禁止行窃。");

	if( me->query_temp("stealing") )
		return notify_fail("你已经在找机会下手了！");

	if(!target || target == me )
		return notify_fail("你想偷谁的东西？");

	if( !wizardp(me) && wizardp(target) )
		return notify_fail("玩家不能偷巫师身上的东西。");

	if(me->is_fighting() && target->is_fighting()
		&& me->query_team() == target->query_team())
		return notify_fail("不能偷本方队员的物品！");

	CContainer * obj = RandomGetItem(target, IS_ITEM);
	
	if(! obj)
		return notify_fail( "%s身上看起来没有什麽值钱的东西好偷。", target->name());

	CMapping * m = obj->query_entire_dbase();
	if (! m->undefinedp("no_drop") 
		|| (! m->undefinedp("owner") && DIFFERSTR(obj->querystr("owner"), me->querystr("id"))) )
		return notify_fail("%s是%s的随身家伙，你偷不到。", obj->name(), target->name());

	if( me->query("mp") < 30)
		return notify_fail("你的法力不足！");
	me->add("mp", -30);

	LONG sp = me->query("dex") * 2 + me->query_skill("stealing", 1) * 5 - me->query("thief") * 20;

	if ( EQUALSTR(me->querystr("family/family_name"), "丐帮" ))
		sp = me->query_skill("stealing", 1) * 10 + me->query("dex") * 5 - me->query("thief") * 10;

	if( sp < 1 ) sp = 1;

	if( me->is_fighting()) 
	{
		sp /= 2;
		me->start_busy(3);
	}

	char msg[255];
	tell_object(me, snprintf(msg, 255, "你不动声色地慢慢靠近%s，等待机会下手 ...", target->name()));

	me->set_temp("stealing", obj->object_id());
	me->call_out( compelete_steal, 3, target->object_id(), sp);

	return 1;
}

static void compelete_steal(CContainer * ob, LONG param1, LONG sp)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);
	char msg[255];
	
	if(! target)
	{
		me->delete_temp("stealing");
		tell_object(me, "太可惜了，你下手的目标已经走了。");
		return;
	}

	CContainer * obj = target->Present(me->query_temp("stealing"));
	me->delete_temp("stealing");
	if(! obj)
	{
		tell_object(me, "太可惜了，你下手的目标已经不在对方身上了。");
		return;
	}

	LONG dp = target->query("hp") + obj->Query_Weight() / 20;
	if( target->is_fighting() ) dp *= 10;
	if( obj->query("equipped") ) dp *= 10;

	if( !living(target) || (random(sp + dp) > dp) ) 
	{
		if( ! obj->move(me) ) 
		{
			tell_object(me, snprintf(msg, 255, "你摸到一%s，可是对你而言太重了，不得不放弃。", obj->name()));
			return;
		}

		tell_object(me, "$HIW得手了！$COM");
		tell_object(me, snprintf(msg, 255, "你成功地偷到%s！", obj->name()));

		if( living(target) ) 
		{
			me->improve_skill("stealing", random(me->query_int()));
		    if ( EQUALSTR(me->querystr("family/family_name"), "丐帮" ) )
			{
				me->add("combat_exp", 1);
			}
		}

		if( random(sp) < dp/2 )
		{
			MessageVision(me, "chat", 
				snprintf(msg, 255, "你看到%s鬼鬼祟祟地从%s身上偷走了%s。！", me->name(), target->name(), obj->name()),
				me, target);
		} 
	}
	else 
	{
		if( random(sp) > dp/2 ) 
		{
			tell_object(me, snprintf(msg, 255, "%s不经意地一转头，你急忙将手缩了回去！\n还好，没有被发现。", target->name()));
			return;
		}
			
		tell_object(me, "$HIR糟糕！你失手了！$COM");
		message_vision(snprintf(msg, 255, "$N一回头，正好发现$n的手正抓着$P身上的%s！\n\n$N喝道：「干什么！」\n", obj->name()),
			target, me);

		me->improve_skill("stealing", 1, 1);
		if(!userp(target))
		{
			target->kill_ob(me);			
			me->kill_ob(target);
		}
		else
		{
			me->add("hp",-(me->query("hp")/10));
		}

	}
		
	me->start_busy(3);
	me->add("thief", 1);	
}

SKILL_END;





