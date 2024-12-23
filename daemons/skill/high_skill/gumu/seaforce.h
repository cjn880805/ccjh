// seaforce.h 狂潮心法
//code by Teapot @ 2001-03-19

FORCE_BEGIN(CSseaforce);

virtual void create()
{
	CForce::create();

	set_name( "狂潮心法");

	Magic_t * magic;

	magic = add_magic("flood", do_flood);
	magic->name = "情却千里";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force");
}

virtual int valid_learn(CChar * me)
{
	if (DIFFERSTR(me->querystr("family/family_name"), "古墓派"))
		return notify_fail("你不是古墓派的弟子,不能学习狂潮心法。");
	
	if(DIFFERSTR(me->querystr("gender"), "男性"))
		return notify_fail("你刚听一会儿，便觉心智迷糊，原来你不是男的，只能领会到其中至阴之理。");
	
	if ( me->query_skill("bibo_shengong",1)
		|| me->query_skill("beiming_shengong",1)
		|| me->query_skill("biyun_xinfa",1)
		|| me->query_skill("xuedao_xinfa",1)
		|| me->query_skill("shenzhao_shengong",1)
		|| me->query_skill("tianlong_shengong",1)
		|| me->query_skill("bahuang_gong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1)
		|| me->query_skill("huntian_qigong",1)
		|| me->query_skill("jiuyang_shengong",1)
		|| me->query_skill("xiantian_gong",1)
		|| me->query_skill("wudu_xinfa",1)
		|| me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("longxiang",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("zixia_shengong",1)
		|| me->query_skill("yijinjing",1)
		|| me->query_skill("shenlong_xinfa",1)
		|| me->query_skill("kurong_changong",1)
		|| me->query_skill("taiji_shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学狂潮心法？！");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("狂潮心法只能靠请教来提高。");
}

//perform 

static int do_flood(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar * )ob;

	if(! target)
		return notify_fail("你想骗谁啊？");

	if( !me->is_fighting(target) )
		return notify_fail("...搞错了吧？");
	
	if( me->query_skill("seaforce",1) < 130 )
		return notify_fail("你的狂潮心法修为不够。");

	if(me->query("couple/have_couple")) 
		return notify_fail("既然已经结婚了，还是老实一点吧.");

	if( me->query("max_mp") < 1200 )
		return notify_fail("你的内力修为不够。");
	
	if( me->query("mp") < 400 )
		return notify_fail("你的真气不够。");

	if(DIFFERSTR(me->querystr("family/family_name"), "古墓派") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if (target->is_busy())
		return notify_fail("现在没有施展的必要．");
	
	message_vision( "$N运起狂潮心法，身形微展．行云流水般的滑出，化作一片人影，处处留情！" ,me, target );

	me->add("mp", -400);

	if(target->query_temp("apply/反_情却千里")&& (!random(3)||wizardp(me)))
	{
		message_vision("\n$HIY$n心似枯木、古井不波，绿竹箫中疾吹出一丝真气，穿透重重幻影击中$N丹田，足已令$N在数招内无法动弹。\n",me, target);
		me->start_busy(3);
	}
	else if(target->query_temp("apply/no_情却千里") && !random(2))
	{
		message_vision("但$N灵光妙悟，乘机攻击！",target);
	}
	else
	{
		if(random(target->query("combat_exp")) < me->query("combat_exp"))
		{
			message_vision("结果$N晕头转向，不知所为！",target);
			target->start_busy(3);
		}
		else
		{
			message_vision("但$N灵光妙悟，乘机攻击！",target);
			g_Combatd.Do_Attack(target,me, CCombatd::TYPE_QUICK);
		}
	}
	me->set("mp_factor", 0l);
	return 1;
}


FORCE_END;




