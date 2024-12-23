
// xiantian_gong.h 先天神功
//code by Fisho
//date : 2000-12-07

FORCE_BEGIN(CSxiantian_gong);

virtual void create()
{
	CForce::create();

	set_name( "先天神功");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "自疗术";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("life_heal", do_life_heal);
	magic->name = "医疗术";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("bidu", do_bidu);
	magic->name = "逼毒";
	magic->mp = 0;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMMON;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force")  ;
}

virtual int valid_learn(CChar * me)
{
	int lvl =  me->query_skill("xiantian_gong", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;
	if ( DIFFERSTR(me->querystr("family/master_id"), "wang chongyang"))
		return notify_fail("先天神功只能跟重阳祖师学习。");

	if ( EQUALSTR(me->querystr("gender"), "无性") && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的先天神功。");
	
	if ( EQUALSTR(me->querystr("class"), "bonze") )		
		return notify_fail("先天神功讲究阴阳调合，有违佛家六根清净之意，%s欲修此功，已是罪过。",query_respect(me));
	
	if ( me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。");
	
	if(lvl<=100)
	{
		if (lvl > 10 &&  me->query("repute") < t * 100) 
			return notify_fail("你的侠义正气太低了。");
	}
	else
	{
		if ( me->query("repute") < (51200 + (lvl - 100) * 1000)) 
			return notify_fail("你的侠义正气太低了。");
	}
	
	if  (  me->query_skill("bibo_shengong",1)
		|| me->query_skill("beimin_shengong",1)
		|| me->query_skill("bahuang_gong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1)
		|| me->query_skill("huntian_qigong",1)
	//	|| me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("longxiang",1)
	//	|| me->query_skill("jiuyang_shengong",1)
	//	|| me->query_skill("taiji_shengong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("zixia_shengong",1)
		|| me->query_skill("taiji_shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学先天神功？！");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("先天神功只能用请教的来增加熟练度。");
}

//perform 
static int do_bidu(CChar * me, CContainer * ob)
{
	char msg[255];

    if( me->is_fighting() )
		return notify_fail("战斗中不能逼毒。");
	
    if ( me->query_skill("xiantian_gong", 1) < 40)
		return notify_fail("你的先天神功修为还不够。");

    if(  me->query("mp") <  me->query("max_mp")/15 ) 
		return notify_fail("你的真气不够。");

	if(DIFFERSTR(me->querystr("family/family_name"), "全真教") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    tell_object(me,   "你全身放松，坐下来开始运功逼毒。"  );
	tell_room(me->environment(),snprintf(msg,255,"%s坐下来运功逼毒。",me->name()),me);

	if ( me->query("condition/zm_poison") > 0 )
	{
		if ( me->query("condition/zm_poison") <  me->query_skill("xiantian_gong",1)/20 + 1 )
		{
			me->apply_condition("zm_poison", 0);
			message_vision( "$N 身上的 子母飞针之毒 尽退 ，脸色看上去好多了。" , me); 
		}
		else {
			me->apply_condition("zm_poison",  me->query("condition/zm_poison") - me->query_skill("xiantian_gong",1)/20 );
			message_vision( "$N 身上的 子母飞针之毒 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
		
	}

	if ( me->query("condition/ice_poison") > 0 )
	{
		if ( me->query("condition/ice_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
		{
			me->apply_condition("ice_poison", 0);
			message_vision( "$N 身上的 寒冰绵掌 尽退 ，脸色看上去好多了。" , me); 
		}
		else 
		{
			me->apply_condition("ice_poison",  me->query("condition/ice_poison") - me->query_skill("xiantian_gong",1)/20);
			message_vision( "$N 身上的 寒冰绵掌 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
		
	}
	if ( me->query("condition/jy_poison") > 0 )
	{
		if ( me->query("condition/jy_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
			
		{
			me->apply_condition("jy_poison", 0);
			message_vision( "$N 身上的 九阴白骨爪毒 尽退 ，脸色看上去好多了。" , me); 
		}
		else {
			me->apply_condition("jy_poison",  me->query("condition/jy_poison") - me->query_skill("xiantian_gong",1)/20);
			message_vision( "$N 身上的 九阴白骨爪毒 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
    if ( me->query("condition/xx_poison") > 0 )
	{
		if ( me->query("condition/xx_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
			
		{
			me->apply_condition("xx_poison", 0);
			message_vision( "$N 身上的 星宿掌毒 尽退 ，脸色看上去好多了。" , me); 
		}
		else 
		{
			me->apply_condition("xx_poison",  me->query("condition/xx_poison") - me->query_skill("xiantian_gong",1)/20);
			message_vision( "$N 身上的 星宿掌毒 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
    if ( me->query("condition/ss_poison") > 0 )
	{
		if ( me->query("condition/ss_poison") <  me->query_skill("xiantian_gong",1)/8+1 )
			
		{
			me->apply_condition("ss_poison", 0);
			message_vision( "$N 身上的 生死符 尽退 ，脸色看上去好多了。" , me); 
		}
		else {
			me->apply_condition("ss_poison",  me->query("condition/ss_poison") - me->query_skill("xiantian_gong",1)/8);
			message_vision( "$N 身上的 生死符 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
	if ( me->query("condition/rose_poison") > 0 )
	{
		if ( me->query("condition/rose_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
		{
			me->apply_condition("rose_poison", 0);
			message_vision( "$N 身上的 火玫瑰毒 尽退 ，脸色看上去好多了。" , me); 
		}
		else
		{
			me->apply_condition("rose_poison",  me->query("condition/rose_poison") - me->query_skill("xiantian_gong",1)/20);
			message_vision( "$N 身上的 火玫瑰毒 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
	if ( me->query("condition/zhua_poison") > 0 )
	{
		if ( me->query("condition/zhua_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
		{
			me->apply_condition("zhua_poison", 0);
			message_vision( "$N 身上的 凝血神爪 尽退 ，脸色看上去好多了。" , me); 
		}
		else 
		{
			me->apply_condition("zhua_poison",  me->query("condition/zhua_poison") - me->query_skill("xiantian_gong",1)/20);
			message_vision( "$N 身上的 凝血神爪 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}
	
	if ( me->query("condition/snake_poison") > 0 )
	{
		if ( me->query("condition/snake_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
			
		{
			me->apply_condition("snake_poison", 0);
			message_vision( "$N 身上的 蛇毒 尽退 ，脸色看上去好多了。" , me); 
		}
		else 
		{
			me->apply_condition("snake_poison",  me->query("condition/snake_poison") - me->query_skill("xiantian_gong",1)/20);
			message_vision( "$N 身上的 蛇毒 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}

    if ( me->query("condition/wudu_poison") > 0 )
	{
		if ( me->query("condition/wudu_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
			
		{
			me->apply_condition("wudu_poison", 0);
			message_vision( "$N 身上的 五毒气 尽退 ，脸色看上去好多了。" , me); 
		}
		else 
		{
			me->apply_condition("wudu_poison",  me->query("condition/wudu_poison") - me->query_skill("xiantian_gong",1)/20);
			message_vision( "$N 身上的 五毒气 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}

	if ( me->query("condition/yufeng_poison") > 0 )
	{
		if ( me->query("condition/yufeng_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
			
		{
			me->apply_condition("yufeng_poison", 0);
			message_vision( "$N 身上的 玉蜂针毒 尽退 ，脸色看上去好多了。" , me); 
		}
		else 
		{
			me->apply_condition("yufeng_poison",  me->query("condition/yufeng_poison") - me->query_skill("xiantian_gong",1)/20);
			message_vision( "$N 身上的 玉蜂针毒 清去小半 脸色渐渐红润起来。" , me);
		}
		me->add("mp", - me->query("max_mp")/15);
		me->set("mp_factor", 0l);
		me->start_busy(4);   
		return 1;
	}

    if ( me->query("condition/bingpo_poison") > 0 )
	{
		if ( me->query("condition/bingpo_poison") <  me->query_skill("xiantian_gong",1)/20+1 )
			
		{
			me->apply_condition("bingpo_poison", 0);
			message_vision( "$N 身上的 冰魄银针毒 尽退 ，脸色看上去好多了。" , me); 
		}
		else
		{
			me->apply_condition("bingpo_poison",  me->query("condition/bingpo_poison") - me->query_skill("xiantian_gong",1)/20);
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

static int do_life_heal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target )
		return notify_fail("你要用真气为谁疗伤？");
	
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！");
	
	if(target == me)
		return notify_fail("你没有为自己疗伤的能力！");
	
	if(  me->query_skill("xiantian_gong",1) < 40 )
		return notify_fail("你的先天神功修为不够。");
	
	if(  me->query("max_mp") < 300 )
		return notify_fail("你的内力修为不够。");
	
	if(  me->query("mp") < 150 )
		return notify_fail("你的真气不够。");
	
	if(  target->query("eff_hp") <  target->query("max_hp") / 5 )
		return notify_fail( "%s已经受伤过重，经受不起你的真气震荡！",target->name() );

	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%s没有受伤。", target->name());
	
	message_vision("$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。"  ,	me, target );
	
	target->receive_curing("hp", 10 +  me->query_skill("force")/3 );
	target->add("hp", 10 +  me->query_skill("force")/3 );
	if(  target->query("hp") >  target->query("eff_hp") ) target->set("hp",  target->query("eff_hp"));
	
	me->add("mp", -150);
	me->set("mp_factor", 0l);
	//疗伤经验奖励    秦波 2002、7、18
	char expmsg[80];
	int addexp = me->query("level") / 4 + 1;
	int addrpt = 10 - target->query("level");

	addexp = int(((addexp + random(addexp)) / 2) *0.5);
	if(addrpt < 1) addrpt = 1;
	addrpt = (addrpt + random(addrpt)) / 2;

	addexp=1;
	addrpt=1;
	me->add("combat_exp", addexp);
	me->add("repute", addrpt);
	
	tell_object(me, snprintf(expmsg, 80, "你的修行提高了%ld点！声望提高了%ld点！", addexp, addrpt));
	//疗伤经验奖励
	me->start_busy(5);
	target->start_busy(5);
	return 1;
	
}

/*
static int do_jing(CChar * me, CContainer * ob)
{
	if( me->is_fighting() )
		return notify_fail("战斗中疗精？找死吗？");
	
	if ( me->query_skill("xiantian_gong", 1) < 50)
		return notify_fail("你的先天神功修为还不够。");
	if(  me->query("mp") < 50 ) 
		return notify_fail("你的真气不够。");
	
	if(  me->query_skill("xiantian_gong",1) < 30 )
		return notify_fail("你的先天神功修为不够。");
	
	if(  me->query("eff_hp") <  me->query("max_hp") / 2 )
		return notify_fail("你的精损伤太多，只怕一运真气便有生命危险！");
	
	tell_object(me,   "你全身放松，坐下来开始打座疗精。"  );
	tell_room(me->environment(),snprintf(tmp,255,"%s头上冒出屡屡热气，精神看起来好多了。"  ,me->name()),me);
	me->receive_curing("hp", 10 +  me->query_skill("taoism")/10 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	me->start_busy(4);
	
	return 1;
	
}
*/

static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？");
	
	if ( me->query_skill("xiantian_gong", 1) < 20)
		return notify_fail("你的先天神功修为还不够。");
	if(  me->query("mp") < 50 ) 
		return notify_fail("你的真气不够。");
	
	if(  me->query("eff_hp") <  me->query("max_hp") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！");
	
	tell_object(me,   "你全身放松，坐下来开始运功疗伤。"  );
	tell_room(me->environment(),snprintf(msg,255, "%s吐出一口瘀血，脸色看起来好多了。"  ,me->name() ),me);
	
	me->receive_curing("hp", 10 +  me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	me->start_busy(4);
	
	return 1;
	
}

FORCE_END;
