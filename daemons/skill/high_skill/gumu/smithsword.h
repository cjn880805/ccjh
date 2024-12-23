// smithsword.h 玄铁重剑式
//code by Teapot @ 2001-03-19
// CCJH里最复杂技能,grin

SKILL_BEGIN(CSsmithsword);

virtual void create()
{
	set_name( "玄铁重剑式");
	
	Magic_t * magic;
	
	magic = add_magic("flood", do_flood);
	magic->name = "奔潮诀";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "yunv_xinfa") || EQUALSTR(arg, "seaforce"))
		return 1;
	
	return notify_fail("玄铁重剑式必须与古墓独门内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,parry,damage,lvl;
		char damage_type[5];
	}action[6] = {
		{"$N提起$w，夹带海潮之声压向$n！", 380, 35, 30,175 , 139, },
		{"$N提起$w，沉寂无声的重刺$n！", 380, 35, 30,175 , 149, },
		{"$N提起$w，以潮水奔涌之势推向$n！", 380, 35, 30,175 , 159, },
		{"$N提起$w，夹带风雷之声压向$n！", 380, 35, 30,175 , 169, },
		{"$N提起$w，以九天十地的威势对$n砍去！", 380, 35, 30,175 , 179,},
		{"$N提起$w，剑随心至，砸向$n！", 380, 35, 30,175 , 189,},
	};
	
	int level = 0;
	
	int ml;
	ml=me->query_skill("smithsword",1);
	
	for(int i=6; i > 0; i--)
	{
		if(action[i - 1].lvl < ml)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("parry", action[level].parry);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	
	if (ml<140)	// 0~10
		m_actions.set("action", "$N提起$w,带细微破风之声刺向$n！");
	if (ml<130)	// 10~20
		m_actions.set("action", "$N提起$w,带轰鸣之声刺向$n！");
	if (ml<120)	// 0~10
		m_actions.set("action", "$N提起$w,带细微破风之声刺向$n！");
	if (ml<110)	// 10~20
		m_actions.set("action", "$N提起$w,带轰鸣之声刺向$n！");
	if (ml<100)	// 0~10
		m_actions.set("action", "$N提起$w,带细微破风之声刺向$n！");
	if (ml<90)	// 10~20
		m_actions.set("action", "$N提起$w,带轰鸣之声刺向$n！");
	if (ml<80)	// 0~10
		m_actions.set("action", "$N提起$w,带细微破风之声刺向$n！");
	if (ml<70)	// 10~20
		m_actions.set("action", "$N提起$w,带轰鸣之声刺向$n！");
	if (ml<60)	// 0~10
		m_actions.set("action", "$N提起$w,带细微破风之声刺向$n！");
	if (ml<50)	// 10~20
		m_actions.set("action", "$N提起$w,带轰鸣之声刺向$n！");
	if (ml<40)	// 0~10
		m_actions.set("action", "$N提起$w,带细微破风之声刺向$n！");
	if (ml<30)	// 10~20
		m_actions.set("action", "$N提起$w,带轰鸣之声刺向$n！");
	if (ml<20)	// 0~10
		m_actions.set("action", "$N提起$w,带细微破风之声刺向$n！");
	if (ml<10)	// 10~20
		m_actions.set("action", "$N提起$w,带轰鸣之声刺向$n！");
//	声自无而响，又自响返无，往复七次而绝，终于欲响便响，欲无则无。
	
	CContainer * weapon;
	weapon = me->query_weapon();
	if (! weapon || weapon->Query_Weight()<80000 || ml<80)
	{
		if(userp(me))
		{
			m_actions.set("action", "$N提起$w刺向$n，却仿佛无着力之处，显然$w太轻了……！");
			m_actions.set("force", 0l);
			m_actions.set("dodge", 0l);
			m_actions.set("parry", 0l);
			m_actions.set("damage",0l);
		}
	}
	
	if (me->query_temp("teapot/smithwave"))
		m_actions.set("action", "$HIB$N使出玄铁重剑式中「奔潮诀」，内力磅礴而出，\n辅以$w剑气，如大潮滔天而至扑向$n！$COM");
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_skill("seaforce", 1) < 30)
		return notify_fail("你的狂潮心法火候不到，无法学习玄铁重剑式。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon()) 
        || DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 30)
		return notify_fail("你的体力不够练玄铁重剑式。");
	if (me->query("mp") < 30)
		return notify_fail("你的内力不足以练玄铁重剑式。");
	if (DIFFERSTR( ( me->environment())->querystr("base_name"), "黄河入海口" ))
	{
//		me->receive_wound("hp", 30);
		me->add("hp",-30);
		me->add("mp",-30);
	}
	else
	{
		me->receive_wound("hp", 3);
		me->add("mp",-1);
	}
	
	return 1;
}

//perform 
static int do_flood(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
    if( !target || !me->is_fighting(target) )
		return notify_fail("奔潮诀只能对战斗中的对手使用。");
	
    if( me->query_skill("smithsword", 1) < 200 )
		return notify_fail("你的玄铁重剑式不够娴熟，不能使用奔潮诀。");

	if(DIFFERSTR(me->querystr("family/family_name"), "古墓派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    if( me->query("mp") < 1300 )
		return notify_fail("你现在内力太弱，不能使用奔潮诀。");
	
	me->add("mp",-1300);
	
	int extra;
	extra = me->query_skill("sword");
	
//	me->add_temp("apply/damage",extra*2);
	me->add_temp("apply/damage",extra/2);
	me->add_temp("apply/attack",extra);
	me->set_temp("teapot/smithwave",1);
//	g_Combatd.Do_Attack(me,target, CCombatd::TYPE_REGULAR);
	message_vision("\n$MAG第一剑：黄河之水天上来！$COM\n" ,me,target);
	if(target->query_temp("apply/no_奔潮诀") && !random(2))
	{
		message_vision("可是$n看破了$N的企图，并没有上当。\n" ,me,target); 
	}
	else
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_REGULAR);

	if (me->query("combat_exp")> target->query("combat_exp")/2 )
	{                
		message_vision("\n$RED第二剑：奔流自古不复还！$COM\n" ,me,target);
		if(target->query_temp("apply/no_奔潮诀") && !random(2))
		{
			message_vision("可是$n看破了$N的企图，并没有上当。\n" ,me,target); 
		}
		else
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_REGULAR);
	}

	if(EQUALSTR(me->querystr("family/family_name"), "古墓派"))
	{
		if (me->query("combat_exp")> target->query("combat_exp") )
		{                
			message_vision("\n$HIY第三剑：但愿长醉不愿醒！$COM\n" ,me,target);
			if(target->query_temp("apply/no_奔潮诀") &&  (!random(2)||target->query("bigboss")))
			{
				message_vision("可是$n看破了$N的企图，并没有上当。\n" ,me,target); 
			}
			else
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_REGULAR);
		}
		
		if (me->query("combat_exp")> target->query("combat_exp")*3 )
		{                
			message_vision("\n$HIR第四剑：与尔同消万古愁！$COM\n" ,me,target);
			if(target->query_temp("apply/no_奔潮诀") && (!random(2)||target->query("bigboss")))
			{
				message_vision("可是$n看破了$N的企图，并没有上当。\n" ,me,target); 
			}
			else
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_REGULAR);
		}
	}

	me->delete_temp("teapot/smithwave");
	me->add_temp("apply/damage",-extra/2);
//	me->add_temp("apply/damage",-extra*2);
	me->add_temp("apply/attack",-extra);
	me->start_busy(3);

	
	return 1;
}

SKILL_END;
