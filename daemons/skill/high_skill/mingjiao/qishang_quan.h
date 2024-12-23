
// qishang_quan.h 七伤拳
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSqishang_quan);

virtual void create()
{
	set_name( "七伤拳");

	set("valid_force", "jiuyang_shengong");

	Magic_t * magic;

	magic = add_magic("cangli", do_cangli);
	magic->name = "藏离诀";
	magic->mp = 800;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("sunxin", do_sunxin);
	magic->name = "损心诀";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("shangfei", do_shangfei);
	magic->name = "伤肺诀";
	magic->mp = 600;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("sanjiao", do_sanjiao);
	magic->name = "三焦齐逆诀";
	magic->mp = 2000;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("jingshi", do_jingshi);
	magic->name = "精失诀";
	magic->mp = 900;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("hunpo", do_hunpo);
	magic->name = "魂魄飞扬";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("cuiganchang", do_cuiganchang);
	magic->name = "摧肝肠诀";
	magic->mp = 700;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("yihuanghu", do_yihuanghu);
	magic->name = "意恍惚诀";
	magic->mp = 1000;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N气凝如山，一式「金戈铁马」，双拳蓄势而发，击向$n的$l",180 , 5, 0, 0,"内伤",},
		{"$N身形凝重，劲发腰背，一式「木已成舟」，缓缓向$n推出", 200, 5, 10, 10,"内伤",},
		{"$N步伐轻灵，两臂伸舒如鞭，一式「水中捞月」，令$n无可躲闪", 230, 15, 10, 20,"内伤",},
		{"$N身形跃起，一式「火海刀山」，双拳当空击下，势不可挡", 270, 5, 20, 30,"内伤",},
		{"$N身形一矮，一式「土载万物」，两拳自下而上，攻向$n", 320,10 , 15, 40,"内伤",},
		{"$N身形一转，一式「阴风惨惨」，攻向$n的身前身后", 380, 25, 25, 48,"内伤",},
		{"$N移形换位，步到拳到，一式「阳光普照」，四面八方都是拳影", 450, 15, 35, 54,"内伤",},
		{"$N长啸一声，向前踏出一步，双拳中宫直进，一式「七者皆伤」，骤然击向$n的前胸", 530, 20, 50, 60,"内伤",},
	};
 		
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("qishang_quan", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "cuff") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon()  )
		return notify_fail("练七伤拳必须空手。");
	if ( me->query_skill("jiuyang_shengong", 1) < 10)
		return notify_fail("你的九阳神功火候不够，无法学七伤拳。");
	if ( me->query("max_mp") < 50)
		return notify_fail("你的内力太弱，无法练七伤拳。");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if ( me->query("mp") < 20)
		return notify_fail("你的内力不够练七伤拳。");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
	
}

//perform 
static int do_cangli(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;
	
    int skill = me->query_skill("qishang_quan",1) + me->query_skill("jiuyang_shengong",1);
	
    if( !target || !me->is_fighting(target) )
		return notify_fail("「藏离诀」只能在战斗中使用。");
	
    if(  me->query("mp") < 800 )
		return notify_fail("你的内力还不够高！");
	
    if(  me->query_skill("cuff") < 120 )
		return notify_fail("你的拳法还不到家，无法体现七伤拳的各种总诀！");
	
    if(  me->query_skill("qishang_quan", 1) < 120)
		return notify_fail("你七伤拳的修为不够，不能够体会藏离诀! ");

	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    if(  me->query_skill("jiuyang_shengong", 1) < 120)
		return notify_fail( "你的九阳神功修为不足，不能随便使用藏离诀! "  );
	
    if( DIFFERSTR(me->query_skill_mapped("cuff"), "qishang_quan"))
		return notify_fail("你没有激发七伤拳，无法运用藏离诀！");
	
    msg =   "$N凝神定气，使出七伤拳总诀中的「藏离诀」，双拳势如雷霆，向$n击去。\n" ;
    	
    LONG ap = me->query_combat_exp() + skill * 500;
    LONG dp = target->query_combat_exp() / 4;
    if( dp < 1 )
		dp = 1;
    if( random(ap) > dp )
    {
		me->add("mp",-200);
		msg +=  "$n被$N拳风扫中，只觉全身真气失却驾驭，往外急泻！" ;
		int neili_wound = random(skill * 2);
		if(neili_wound > target->query("mp"))
			neili_wound = target->query("mp");
		target->add("mp", -neili_wound);
		target->receive_wound("hp", neili_wound);
		target->start_busy(2);
		me->start_busy(random(3));
    }
    else
    {
		msg +=   "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！" ;
		me->add("mp",-100);
		me->start_busy(2);
    }

    message_vision(msg.c_str(), me, target);
	
    return 1;
}

static int do_sunxin(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;

    int skill = me->query_skill("qishang_quan",1) + me->query_skill("jiuyang_shengong",1);
	
    if( !target || !me->is_fighting(target) )
		return notify_fail("「损心诀」只能在战斗中使用。");
	
    if(  me->query("mp") < 500 )
		return notify_fail("你的内力还不够高！");
	
    if(  me->query_skill("cuff") < 60 )
		return notify_fail("你的拳法还不到家，无法体现七伤拳的各种总诀！");
	
    if(  me->query_skill("qishang_quan", 1) < 60)
		return notify_fail("你七伤拳的修为不够，不能够体会损心诀! ");
	
    if(  me->query_skill("jiuyang_shengong", 1) < 60)
		return notify_fail( "你的九阳神功修为不足，不能随便使用损心诀! "  );

	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    if( DIFFERSTR(me->query_skill_mapped("cuff"), "qishang_quan"))
		return notify_fail("你没有激发七伤拳，无法运用损心诀！");
	
    msg =   "$N凝神定气，使出七伤拳总诀中的「损心诀」，双拳势如雷霆，向$n击去。\n" ;
    	
    LONG ap = me->query_combat_exp() + skill * 500;
    LONG dp = target->query_combat_exp() / 4;
    if( dp < 1 )
		dp = 1;
    if( random(ap) > dp )
    {
		me->add("mp",-100);
		msg +=   "$N连环拳势如风雷，$n中了$N开山裂石的一拳，顿时心神大震，不能随意出招！" ;
		LONG attack_decrease =  target->query("apply/attack") / 10;
		target->add_temp("apply/attack", -attack_decrease);
		target->start_busy(2);
		me->start_busy(random(3));
    }
    else
    {
		msg +=   "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！" ;
		me->add("mp",-100);
		me->start_busy(2);
    }

    message_vision(msg.c_str(), me, target);
	
    return 1;
}

static int do_shangfei(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;

    int skill = me->query_skill("qishang_quan",1) + me->query_skill("jiuyang_shengong",1);
	
    if( !target || !me->is_fighting(target) )
		return notify_fail("「伤肺诀」只能在战斗中使用。");
	
    if(  me->query("mp") < 600 )
		return notify_fail("你的内力还不够高！");
	
    if(  me->query_skill("cuff") < 60 )
		return notify_fail("你的拳法还不到家，无法体现七伤拳的各种总诀！");
	
    if(  me->query_skill("qishang_quan", 1) < 60)
		return notify_fail("你七伤拳的修为不够，不能够体会伤肺诀! ");
	
    if(  me->query_skill("jiuyang_shengong", 1) < 60)
		return notify_fail( "你的九阳神功修为不足，不能随便使用伤肺诀! "  );

	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    if( DIFFERSTR(me->query_skill_mapped("cuff"), "qishang_quan"))
		return notify_fail("你没有激发七伤拳，无法运用伤肺诀！");
	
    msg =   "$N凝神定气，使出七伤拳总诀中的「伤肺诀」，双拳势如雷霆，向$n击去。\n" ;
    	
    LONG ap = me->query_combat_exp() + skill * 500;
    LONG dp = target->query_combat_exp() / 4;
    if( dp < 1 )
		dp = 1;
    if( random(ap) > dp )
    {
		me->add("mp",-100);
		
		msg +=   "$N的拳风隐含风雷，“澎”的一声打在$n身上！$n只觉得呼吸不顺，顿时脚步慢了许多！" ;
		LONG dodge_decrease =  target->query("apply/dodge") / 10;
		target->add_temp("apply/dodge", -dodge_decrease);
		target->start_busy(2);
		me->start_busy(random(3));
    }
    else
    {
		msg +=   "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！" ;
		me->add("mp",-100);
		me->start_busy(2);
    }

    message_vision(msg.c_str(), me, target);
    return 1;
}

static int do_sanjiao(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;

	int skill = me->query_skill("qishang_quan",1) + me->query_skill("jiuyang_shengong",1);
	
    if( !target || !me->is_fighting(target) )
		return notify_fail("「三焦齐逆诀」只能在战斗中使用。");
	
    if(  me->query("mp") < 2000 )
		return notify_fail("你的内力还不够高！");
	
    if(  me->query_skill("cuff") < 200 )
		return notify_fail("你的拳法还不到家，无法体现七伤拳的各种总诀！");
	
    if(  me->query_skill("qishang_quan", 1) < 200)
		return notify_fail("你七伤拳的修为不够，不能够体会三焦齐逆诀! ");
	
    if(  me->query_skill("jiuyang_shengong", 1) < 200)
		return notify_fail( "你的九阳神功修为不足，不能随便使用三焦齐逆诀! "  );

	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    if( DIFFERSTR(me->query_skill_mapped("cuff"), "qishang_quan"))
		return notify_fail("你没有激发七伤拳，无法运用三焦齐逆诀！");
	
    msg =   "$N凝神定气，企图使出七伤拳总诀中的「三焦齐逆诀」，将敌方招数反弹！\n" ;
	
	LONG ap = me->query_combat_exp() + skill * 400;
	LONG dp = target->query_combat_exp() / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		me->add("mp",-100);
		
		msg +=   "$n只觉得胸前一阵剧痛，“哇”的一声喷出一口鲜血！" ;
		int neili_wound = 100 + random(skill);
		if(neili_wound > target->query("mp"))
			neili_wound = target->query("mp");
		
		int qi_wound = neili_wound / 5;
		if(qi_wound > target->query("hp"))
			qi_wound = target->query("hp");
		
		target->add("mp", -neili_wound);
		target->receive_wound("hp", qi_wound);
		target->start_busy(2);
		me->start_busy(random(3));
	}
	else
	{
		msg +=   "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！" ;
		me->add("mp",-100);
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
	//if(!target->is_fighting(me)) target->kill_ob(me);
	return 1;
}

static int do_jingshi(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;

    int skill = me->query_skill("qishang_quan",1) + me->query_skill("jiuyang_shengong",1);
	
    if( !target || !me->is_fighting(target) )
		return notify_fail("「精失诀」只能在战斗中使用。");
	
    if(  me->query("mp") < 900 )
		return notify_fail("你的内力还不够高！");
	
    if(  me->query_skill("cuff") < 150 )
		return notify_fail("你的拳法还不到家，无法体现七伤拳的各种总诀！");
	
    if(  me->query_skill("qishang_quan", 1) < 150)
		return notify_fail("你七伤拳的修为不够，不能够体会精失诀! ");
	
    if(  me->query_skill("jiuyang_shengong", 1) < 150)
		return notify_fail( "你的九阳神功修为不足，不能随便使用精失诀! "  );

	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    if( DIFFERSTR(me->query_skill_mapped("cuff"), "qishang_quan"))
		return notify_fail("你没有激发七伤拳，无法运用精失诀！");
	
    msg =   "$N凝神定气，使出七伤拳总诀中的「精失诀」，双拳势如雷霆，向$n击去。\n" ;
    	
    LONG ap = me->query_combat_exp() + skill * 500;
    LONG dp = target->query_combat_exp() / 4;
    if( dp < 1 )
		dp = 1;
    if( random(ap) > dp )
    {
		me->add("mp",-300);
		
		msg +=   "$N的拳只是轻轻的碰到了$n，但$N的真气趁这一瞬间已流入了$n体内！$n只觉得有点疲惫。。。" ;
		int neili_wound = 100 + random(skill);
		if(neili_wound > target->query("mp"))
			neili_wound = target->query("mp");
		
		int jing_wound = random( skill);
		int eff_jing_wound = random( skill / 3);
		target->receive_wound("hp", jing_wound);
		target->receive_damage("hp", eff_jing_wound);
		me->start_busy(2);
    }
    else
    {
		msg +=   "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！" ;
		me->add("mp",-100);
		me->start_busy(3);
    }

    message_vision(msg.c_str(), me, target);
	
    return 1;
	
}

static int do_hunpo(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;

    int skill = me->query_skill("qishang_quan",1) + me->query_skill("jiuyang_shengong",1);

	if( !target || !me->is_fighting(target) )
		return notify_fail("「魂魄飞扬」只能在战斗中使用。");
	
	if(  me->query("mp") < 500 )
		return notify_fail("你的内力还不够高！");
	
	if(  me->query_skill("cuff") < 150 )
		return notify_fail("你的拳法还不到家，无法使用魂魄飞扬！");
	
	if(  me->query_skill("qishang_quan", 1) < 60)
		return notify_fail("你七伤拳的修为不够，不能使用魂魄飞扬! ");

	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( DIFFERSTR(me->query_skill_mapped("cuff"), "qishang_quan") )
		return notify_fail("你没有激发七伤拳，无法使用魂魄飞扬！");
	
	msg =   "$N大喝一声，使出七伤拳的绝技「魂魄飞扬」，双拳势如雷霆，向$n击去。\n" ;
		
	LONG ap = me->query_combat_exp() + skill * 400;
	LONG dp = target->query_combat_exp() / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		me->add("mp",-100);
		
		msg +=   "$n只觉得胸前一阵剧痛，“哇”的一声喷出一口鲜血！" ;
		int neili_wound = 100 + random(skill);
		if(neili_wound > target->query("mp"))
			neili_wound = target->query("mp");
		
		int qi_wound = neili_wound / 5;
		if(qi_wound > target->query("hp"))
			qi_wound = target->query("hp");
		
		target->add("mp", -neili_wound);
		target->add("hp", -qi_wound);
		target->start_busy(2);
		me->start_busy(random(2));
	}
	else
	{
		msg +=   "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！" ;
		me->add("mp",-100);
		me->start_busy(4);
	}
	message_vision(msg.c_str(), me, target);
	
	return 1;
	
}

static int do_cuiganchang(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;

    int skill = me->query_skill("qishang_quan",1) + me->query_skill("jiuyang_shengong",1);
	
    if(!target || !me->is_fighting(target) )
		return notify_fail("「摧肝肠诀」只能在战斗中使用。");
	
    if(  me->query("mp") < 700 )
		return notify_fail("你的内力还不够高！");
	
    if(  me->query_skill("cuff") < 120 )
		return notify_fail("你的拳法还不到家，无法体现七伤拳的各种总诀！");
	
    if(  me->query_skill("qishang_quan", 1) < 90)
		return notify_fail("你七伤拳的修为不够，不能够体会摧肝肠诀! ");

	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    if(  me->query_skill("jiuyang_shengong", 1) < 90)
		return notify_fail( "你的九阳神功修为不足，不能随便使用摧肝肠诀! "  );
	
    if( DIFFERSTR(me->query_skill_mapped("cuff"), "qishang_quan"))
		return notify_fail("你没有激发七伤拳，无法运用摧肝肠诀！");
	
    msg =   "$N凝神定气，使出七伤拳总诀中的「摧肝肠诀」，双拳势如雷霆，向$n击去。\n" ;
    	
    LONG ap = me->query_combat_exp() + skill * 500;
    LONG dp = target->query_combat_exp() / 4;
    if( dp < 1 )
		dp = 1;
    if( random(ap) > dp )
    {
		me->add("mp",-200);
		
		msg +=   "$n前胸中了$N全力一击，只觉一阵剧痛，“哇”的一声喷出一口鲜血！" ;
		int qi_wound = 250 + random(skill);
		if(qi_wound > target->query("hp"))
			qi_wound = target->query("hp");
		
		target->receive_wound("hp", qi_wound);
		target->start_busy(2);
		me->start_busy(random(3));
    }
    else
    {
		msg +=   "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！" ;
		me->add("mp",-100);
		me->start_busy(2);
    }

    message_vision(msg.c_str(), me, target);
	
    return 1;
	
}

static int do_yihuanghu(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;

    int skill = me->query_skill("qishang_quan",1) + me->query_skill("jiuyang_shengong",1);
	
    if( !target || !me->is_fighting(target) )
		return notify_fail("「意恍惚诀」只能在战斗中使用。");
	
    if(  me->query("mp") < 1000 )
		return notify_fail("你的内力还不够高！");
	
    if(  me->query_skill("cuff") < 150 )
		return notify_fail("你的拳法还不到家，无法体现七伤拳的各种总诀！");
	
    if(  me->query_skill("qishang_quan", 1) < 150)
		return notify_fail("你七伤拳的修为不够，不能够体会意恍惚诀! ");

	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    if(  me->query_skill("jiuyang_shengong", 1) < 150)
		return notify_fail( "你的九阳神功修为不足，不能随便使用意恍惚诀! "  );
	
    if( DIFFERSTR(me->query_skill_mapped("cuff"), "qishang_quan"))
		return notify_fail("你没有激发七伤拳，无法运用意恍惚诀！");
	
    msg =   "$N凝神定气，使出七伤拳总诀中的「意恍惚诀」，双拳势如雷霆，向$n击去。\n" ;
    	
    LONG ap = me->query_combat_exp() + skill * 500;
    LONG dp = target->query_combat_exp() / 4;
    if( dp < 1 )
		dp = 1;
    if( random(ap) > dp )
    {
		me->add("mp",-300);
		msg +=  "结果$N双拳击中时，却是若有若无。\n$n正在奇怪间，已被$N的真气制住，神情恍恍忽忽的！" ;
		target->start_busy( skill/20);
		me->start_busy(2);
    }
    else
    {
		msg +=   "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！" ;
		me->add("mp",-100);
		me->start_busy(4);
    }
    message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;
