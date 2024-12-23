// hamagong.c 蛤蟆功

// code by Fisho
// date : 2000-11-28

void reserve_remove_effect(CContainer * ob, LONG amount_one, LONG amount_two)
{
	CChar * me = (CChar *)ob;
	
	me->add_temp("apply/attack", - amount_one);
	me->add_temp("apply/dodge", - amount_two);
	me->delete_temp("hmg_dzjm");
	
	me->SendState(me);
	tell_object(me, "你双手一撑，一跃而起，将内力收回丹田。");
}


FORCE_BEGIN(CShamagong);

virtual void create()
{
	CForce::create();
	
	set_name( "蛤蟆功");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "自疗术";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "激励术";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("qudu", do_qudu);
	magic->name = "驱毒术";
	magic->mp = 200;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("reserve", do_reserve);
	magic ->name = "经脉倒转";
	magic->mp = 300;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}

int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("你的师傅暂时没空指点你武功。。");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("你暂时无法指点你伴侣的武功。。");
	
	int i = me->query_skill("hamagong", 1);
	int t = 1, j;

	if( i <= 100)
		for (j = 1; j < i / 10; j++)
			t*= 2;

	if ( EQUALSTR(me->querystr("gender"), "无性") && i > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的蛤蟆功。");
	if (me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学蛤蟆功。");

	if(i<=100)
	{
		if (i > 10 && -me->query("repute") < t * 100) 
			return notify_fail("学蛤蟆功，要心狠手辣，奸恶歹毒，你可做得不够呀！");
	}
	else
	{
		if (-me->query("repute") < (51200 + (i - 100) * 1000)) 
			return notify_fail("学蛤蟆功，要心狠手辣，奸恶歹毒，你可做得不够呀！");
	}

	if ( me->query_skill("bibo_shengong",1)
	|| me->query_skill("beiming_shengong",1)
	|| me->query_skill("bahuang_gong",1)
//	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong_dafa",1)
	|| me->query_skill("huntian_qigong",1)
	|| me->query_skill("hunyuan_yiqi",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("jiuyang_shengong",1)
	|| me->query_skill("taiji_shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong_shengong",1)
	|| me->query_skill("zixia_shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学蛤蟆功？！");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("蛤蟆功只能用请教的来增加熟练度。");
}

static int do_heal(CChar * me, CContainer * target)
{
	char msg[255];

	if( me->is_fighting() )
			return notify_fail("战斗中运功疗伤？找死吗？");
	
	if (me->query_skill("hamagong", 1) < 20)
		return notify_fail("你的蛤蟆功修为还不够。");
	
	if( me->query("mp") < 50 )
		return notify_fail("你的真气不够。");

	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！");

	tell_object(me, "你全身放松，坐下来开始运功疗伤。");
	tell_room(me->environment(), snprintf(msg, 255, "%s吐出一口瘀血，脸色看起来好多了。", me->name()), me);
	
	me->receive_curing("hp", 10 + me->query_skill("force") / 3 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	me->start_busy(4);
	return 1;
}

static int do_powerup(CChar * me, CContainer * target)
{
	int skill;

	if( target != me )
		return notify_fail("你只能用蛤蟆功来提升自己的战斗力。");

	if( me->query("mp") < 100  )
		return notify_fail("你的内力不够。");

	if( me->querymap_temp("powerup") )
		return notify_fail("你已经在运功中了。");
		
			if(DIFFERSTR(me->querystr("family/family_name"), "白驼山派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	skill = me->query_skill("force");
	me->add("mp", -90);
	me->receive_damage("hp", 0);
	message_vision("$N微一凝神，运起蛤蟆功，全身骨节发出一阵爆豆般的声响", me );
	
	start_powerup(me, skill, skill/3, skill/3, "你的蛤蟆功运行完毕，将内力收回丹田。");

	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}

static int do_qudu(CChar * me, CContainer * ob)
{
	char msg[255];

    if( me->is_fighting() )
		return notify_fail("战斗中不能逼毒。");
		
			if(DIFFERSTR(me->querystr("family/family_name"), "白驼山派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    if ( me->query_skill("hamagong", 1) < 40)
		return notify_fail("你的蛤莫功修为还不够。");

    if(  me->query("mp") <  me->query("max_mp")/15 ) 
		return notify_fail("你的真气不够。");
	
    tell_object(me,   "你全身放松，坐下来开始运功逼毒。"  );
	tell_room(me->environment(),snprintf(msg,255,"%s坐下来运功逼毒。",me->name()),me);

	if ( me->query("condition/zm_poison") > 0 )
	{
		if ( me->query("condition/zm_poison") <  me->query_skill("hamagong",1)/20 + 1 )
		{
			me->apply_condition("zm_poison", 0);
			message_vision( "$N 身上的 子母飞针之毒 尽退 ，脸色看上去好多了。" , me); 
		}
		else {
			me->apply_condition("zm_poison",  me->query("condition/zm_poison") - me->query_skill("hamagong",1)/20 );
			message_vision( "$N 身上的 子母飞针之毒 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
		
	}

	if ( me->query("condition/ice_poison") > 0 )
	{
		if ( me->query("condition/ice_poison") <  me->query_skill("hamagong",1)/20+1 )
		{
			me->apply_condition("ice_poison", 0);
			message_vision( "$N 身上的 寒冰绵掌 尽退 ，脸色看上去好多了。" , me); 
		}
		else 
		{
			me->apply_condition("ice_poison",  me->query("condition/ice_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N 身上的 寒冰绵掌 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
		
	}
	if ( me->query("condition/jy_poison") > 0 )
	{
		if ( me->query("condition/jy_poison") <  me->query_skill("hamagong",1)/20+1 )
			
		{
			me->apply_condition("jy_poison", 0);
			message_vision( "$N 身上的 九阴白骨爪毒 尽退 ，脸色看上去好多了。" , me); 
		}
		else {
			me->apply_condition("jy_poison",  me->query("condition/jy_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N 身上的 九阴白骨爪毒 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
    if ( me->query("condition/xx_poison") > 0 )
	{
		if ( me->query("condition/xx_poison") <  me->query_skill("hamagong",1)/20+1 )
			
		{
			me->apply_condition("xx_poison", 0);
			message_vision( "$N 身上的 星宿掌毒 尽退 ，脸色看上去好多了。" , me); 
		}
		else 
		{
			me->apply_condition("xx_poison",  me->query("condition/xx_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N 身上的 星宿掌毒 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
    if ( me->query("condition/ss_poison") > 0 )
	{
		if ( me->query("condition/ss_poison") <  me->query_skill("hamagong",1)/8+1 )
			
		{
			me->apply_condition("ss_poison", 0);
			message_vision( "$N 身上的 生死符 尽退 ，脸色看上去好多了。" , me); 
		}
		else {
			me->apply_condition("ss_poison",  me->query("condition/ss_poison") - me->query_skill("hamagong",1)/8);
			message_vision( "$N 身上的 生死符 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
	if ( me->query("condition/dog_poison") > 0 )
	{
		if ( me->query("condition/rose_poison") <  me->query_skill("hamagong",1)/20+1 )
		{
			me->apply_condition("dog_poison", 0);
			message_vision( "$N 身上的 火玫瑰毒 尽退 ，脸色看上去好多了。" , me); 
		}
		else
		{
			me->apply_condition("dog_poison",  me->query("condition/dog_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N 身上的 火玫瑰毒 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
	if ( me->query("condition/zhua_poison") > 0 )
	{
		if ( me->query("condition/zhua_poison") <  me->query_skill("hamagong",1)/20+1 )
		{
			me->apply_condition("zhua_poison", 0);
			message_vision( "$N 身上的 凝血神爪 尽退 ，脸色看上去好多了。" , me); 
		}
		else 
		{
			me->apply_condition("zhua_poison",  me->query("condition/zhua_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N 身上的 凝血神爪 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
	if ( me->query("condition/snake_poison") > 0 )
	{
		if ( me->query("condition/snake_poison") <  me->query_skill("hamagong",1)/20+1 )
			
		{
			me->apply_condition("snake_poison", 0);
			message_vision( "$N 身上的 蛇毒 尽退 ，脸色看上去好多了。" , me); 
		}
		else 
		{
			me->apply_condition("snake_poison",  me->query("condition/snake_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N 身上的 蛇毒 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}

    if ( me->query("condition/wudu_poison") > 0 )
	{
		if ( me->query("condition/wudu_poison") <  me->query_skill("hamagong",1)/20+1 )
			
		{
			me->apply_condition("wudu_poison", 0);
			message_vision( "$N 身上的 五毒气 尽退 ，脸色看上去好多了。" , me); 
		}
		else 
		{
			me->apply_condition("wudu_poison",  me->query("condition/wudu_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N 身上的 五毒气 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}

	if ( me->query("condition/yufeng_poison") > 0 )
	{
		if ( me->query("condition/yufeng_poison") <  me->query_skill("hamagong",1)/20+1 )
			
		{
			me->apply_condition("yufeng_poison", 0);
			message_vision( "$N 身上的 玉蜂针毒 尽退 ，脸色看上去好多了。" , me); 
		}
		else 
		{
			me->apply_condition("yufeng_poison",  me->query("condition/yufeng_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N 身上的 玉蜂针毒 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}

    if ( me->query("condition/bingpo_poison") > 0 )
	{
		if ( me->query("condition/bingpo_poison") <  me->query_skill("hamagong",1)/20+1 )
			
		{
			me->apply_condition("bingpo_poison", 0);
			message_vision( "$N 身上的 冰魄银针毒 尽退 ，脸色看上去好多了。" , me); 
		}
		else
		{
			me->apply_condition("bingpo_poison",  me->query("condition/bingpo_poison") - me->query_skill("hamagong",1)/20);
			message_vision( "$N 身上的 冰魄银针毒 清去小半 脸色渐渐红润起来。" , me);
		}
		
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	else 
		tell_object(me, "你现在没有中毒。"   );
	return 1;
	
}

static int do_reserve(CChar * me, CContainer * target)
{
	int skill;
	
	if( me->query_skill("hamagong", 1) < 40 )
		return notify_fail("你的蛤蟆功不够娴熟，不会经脉倒转。");
	
	if( me->query("mp") < 500  ) 
		return notify_fail("你的内力不够。");
	
	if( me->query_temp("hmg_dzjm") ) 
		return notify_fail("你已经倒转经脉了。");
		
			if(DIFFERSTR(me->querystr("family/family_name"), "白驼山派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
		
	
	skill = me->query_skill("hamagong",1);

	message_vision("$N忽地双手撑地倒立，逆运经脉，顿时内息暗生，防御力大增。", me);
	
	if(!me->query_temp("tjj_sui") && !me->query_temp("qzj_tong") && !me->query_temp("hsj_wu") && !me->query_temp("hmg_dzjm"))
	{
		me->add_temp("apply/attack", -skill/6);
		me->add_temp("apply/dodge", skill/2);
		me->set_temp("hmg_dzjm", 1);
		me->call_out(reserve_remove_effect, skill, -skill/6, skill/2);
	}
		
	me->add("mp", -300);
	if( me->is_fighting() ) me->start_busy(2);
		
	return 1;
}

FORCE_END;




