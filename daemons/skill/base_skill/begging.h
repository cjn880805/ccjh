//begging.h 乞讨之术

SKILL_BEGIN(CSbegging);

void create()
{
	set_name( "乞讨术");
	set("special", 1);

	Magic_t * magic;

	magic = add_magic("begmoney", do_beg);
	magic->name = "乞讨";
	magic->mp = 30;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;	
}

const char * type() { return "knowledge"; }

//可以学1级，然后使用法术
int valid_learn(CChar * me)
{
	if(me->query_skill("begging", 1) > 1)
		return notify_fail("乞讨术要在实践中提高。");

	return 1;
}

//perform 
static int do_beg(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if ( DIFFERSTR(me->querystr("family/family_name"), "丐帮") )
          return notify_fail("只有乞丐才能乞讨！");

	CContainer * where = me->environment();
	if( where->query("no_beg") || where->query("no_fight"))
		return notify_fail("这里不是你叫化子能来讨饭的地方！");

	if( me->query_temp("begging") )
		return notify_fail("你已经在向人家乞讨了！");

	if(!target || target == me || !living(target) )
		return notify_fail("你想向谁乞讨？");

	//增加一个让npc不被beg的no_beg_from属性
	if( target->query("no_beg_from"))
		return notify_fail("%s眉头一皱！大怒道：%s找死啊！", target->name(), query_rude(me));

    if ( EQUALSTR(target->querystr("family/family_name"), "丐帮") )
        return notify_fail("你不能向乞丐乞讨！");

	if( !wizardp(me) && wizardp(target) )
		return notify_fail("玩家不能向巫师乞讨。");

	if( me->is_fighting() )
        return notify_fail("一边打架一边要饭？你真是活腻了！");

	if( target->is_fighting() ) 
        return notify_fail("对方正在打架，没空理你！");

	if( me->query("mp") < 30)
		return notify_fail("你的法力不足！");

	CContainer * obj = RandomGetItem(target, IS_ITEM);
	
	if(! obj)
		return notify_fail( "%s身上看起来没有什麽让你感兴趣的东西。", target->name());

	CMapping * m = obj->query_entire_dbase();
	if (obj->query("equipped") || ! m->undefinedp("no_drop") 
		|| (! m->undefinedp("owner") && DIFFERSTR(obj->querystr("owner"), me->querystr("id"))) )
	{
		if(random(6)==1)
		{
			me->improve_skill("begging", 1);
			me->add("mp",-30);
		}
		return notify_fail("%s眉头一皱，骂道，臭要饭的，滚！", target->name());
	}

	

	me->add("mp", -30);
	int sp = 2 + me->query_skill("begging", 1) / 5;

	message_vision(snprintf(msg, 255, "$N装出可怜巴巴的样子，慢慢地向$n走过去，伸出手，说道：%s行行好，可怜可怜吧 ...！",
		query_respect(target)), me, target);
	
	me->set_temp("begging", obj->object_id());
	me->call_out( compelete_beg, 3, target->object_id(), sp);

	return 1;
}

static void compelete_beg(CContainer * ob, LONG param1, LONG sp)
{
	char msg[255];
	CChar * me = (CChar *)ob;
	CContainer * where = me->environment();
	CChar * who = (CChar *)where->Present(param1);

	if( ! who )
	{
		me->delete_temp("begging");
		tell_object(me, "太可惜了，你要乞讨的人已经走了。");
		return;
	}

	CContainer * obj = who->Present(me->query_temp("begging"));
	me->delete_temp("begging");

	if(! obj)
	{
		tell_object(me, "太可惜，对方改变主意，不打算施舍你了。");
		if(random(3)==1)
		{
			me->improve_skill("begging", 1);
			me->add("mp",-30);
		}
		return;
	}

	if( random(who->query_temp("last_beg_time")) > 8)
	{
		tell_object(me, snprintf(msg, 255, "%s眉头一皱骂道，臭要饭的，你们有完没完！", who->name()));
		return;
	}

	int dp = who->query("level");
	if( living(who) && (random(sp + dp) > dp) ) 
	{
		LONG amount = obj->Query_Amount();
		if( amount > 1)
		{
			if( EQUALSTR(obj->querystr("base_name"), "coin") )
				amount /= 5;
			else
				amount = 1;
			
			obj = ((CItem *)obj)->Split(amount);

			if( !obj )
			{
				tell_object(me, "看来还是走吧，这家伙身上已经没有多少油水可榨了。");
				return;
			}			
		}
		
		if(!obj->move(me) ) 
		{
			obj->move(where);
			tell_object(me, snprintf(msg, 255, "你讨到%s，可是对你而言太重了，不得不丢在地下。", obj->name()));
			me->improve_skill("begging", random(2)+1);
			me->add("mp",-30);
			me->add("combat_exp",1);
			return;
		}

		message_vision(snprintf(msg, 255, "$n低头想了一会，又看了看$N的可怜样，叹了口气，丢给$P数量%ld的%s。",
			amount, obj->name()), me, who);
			
//		me->improve_skill("begging", random(3)+1);
		me->improve_skill("begging", dp + random(dp));
		me->add("mp",-30);
		me->add("combat_exp",1);
		
		who->add_temp("last_beg_time", 1);		
		me->start_busy(6);
	} 
	else 
	{
		if( random(sp) > dp/2 ) 
		{
			message_vision("$n狠狠地瞪了$N一眼，喝道：滚！ $N吓了一跳，急忙扭头灰溜溜地走开了。", me, who);
			if(random(3)==1)
			{
				me->improve_skill("begging", 1);
				me->add("mp",-30);
			}
			who->add_temp("last_beg_time", 1);
			return;
		}
	
		message_vision("$n扭过头去，对$N理都不理。", me, who);
		me->improve_skill("begging", random(3)+1);
		me->add("mp",-30);
		me->start_busy(3);
	}
}

SKILL_END;





