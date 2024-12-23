// jinding_zhang.h 金顶绵掌
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CSjinding_zhang);

virtual void create()
{
	set_name( "金顶绵掌");
	set("valid_force", "linji_zhuang");

	
	Magic_t * magic;

	magic = add_magic("bashi", do_bashi);
	magic->name = "八式合一";
	magic->mp = 200;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge;
		char damage_type[5];
		int lvl;
	}action[] = {
		{"$N身形微晃，一招「三阳开泰」，掌起风生，$n只觉得一股暖气袭向$l", 100, 10,"内伤", 0,},
		{"$N双手变幻，五指轻弹，一招「五气呈祥」，力分五路，招罩十方，抓向$n的$l", 120, 10,"内伤",11 ,},
		{"$N左手前引，右手倏出，抢在头里，一招「罡风推云」，疾抓向$n的$l", 150,15 ,"内伤", 22,},
		{"$N左手圈转，轻拂$n的左手，反向推出，右手连续磕击，一招「逆流捧沙」，猛地击向$n的下巴", 200, 25,"内伤", 33,},
		{"$N舌绽春雷，一声娇喝，在$n一愣间，右手一招「雷洞霹雳」，直捣$n的$l", 100, 10,"内伤", 44,},
		{"$N双手平举握拳，脸露微笑，$n恍惚间看到$N分身为二，便见$N四掌齐出，一招「金顶佛光」不知哪两掌是实？掌风已经袭面", 200,15 ,"内伤", 55,},
		{"$N一幅宝像庄严，使出「梵心降魔」，掌势如虹，绕着$n漂移不定",230, 20 ,"内伤", 66,},
		{"$N全场游走，双臂疾舞，化为点点掌影，一招「法尊八荒」铺天盖地袭向$n全身各处大穴", 300, 30,"内伤", 77,},
	};
	
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("jinding_zhang", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "strike") || (usage == "parry");
}

virtual int valid_combine(string combo) { return combo=="tiangang_zhi"; }

virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("你的师傅暂时没空指点你武功。。");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("你暂时无法指点你伴侣的武功。。");

	if ( me->query_weapon() )
		return notify_fail("练金顶绵掌必须空手。");
	
	if (me->query_skill("linji_zhuang", 1) < 10)
		return notify_fail("你的临济庄心法火候不够，不能练金顶绵掌。");
	if (me->query("max_mp") < 30)
		return notify_fail("你的内力太弱，无法练金顶绵掌。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if (me->query_skill("jinding_zhang", 1) < 100)
		me->receive_damage("hp", 10);
	else
        me->receive_damage("hp", 20);
	return 1;
}

//perform 
static int do_bashi(CChar * me, CContainer * ob)
{
	string msg;
	int damage;
	CChar * target = NULL;
	
	if(! ob || !ob->is_character())
		return notify_fail("「八式合一」要对谁使用？");

	target = (CChar *)ob;

	if( !me->is_fighting(target) )
		return notify_fail("「八式合一」只能在战斗中使用。");
	
	if( target->query_temp("bashi") )
		return notify_fail("你已经在运功中了。");
	
	if( me->query("mp") < 200 )
		return notify_fail("你的内力还不够高！");
	
	if( me->query_skill("linji_zhuang", 1) < 40)
		return notify_fail("你的临济使二庄的修为不够，不能使用八式合一!");
	
	if( me->query_skill("jinding_zhang",1) <100)
		return notify_fail("你的金顶绵掌的八式修习不全，无法使用八式合一！");
	
	if( DIFFERSTR(me->query_skill_mapped("strike"), "jinding_zhang"))
		return notify_fail("你没有激发金顶绵掌，无法使用八式合一！");

	if(DIFFERSTR(me->querystr("family/family_name"), "峨嵋派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( !target->is_killing(me) ) target->kill_ob(me);
	
	msg =  "$N深深吸了一口气，提起全身的功力于双掌，只听的$N骨骼一阵爆响！" ;
	if( random(me->query_combat_exp() + 1) > target->query_combat_exp()/2)
	{
		damage = me->query_skill("linji_zhuang", 1)/2;
		damage = damage +  me->query_skill("jinding_zhang", 1);
		target->set_temp("bashi", 1);
		target->add_temp("apply/attack", -damage/3);
		target->add_temp("apply/dodge", -damage/3);
		msg +=  "$N腾空而起，使出了「八式合一」，漫天的掌影，飘忽不定的罩向$n全身各个部位，" ;
		target->call_out( remove_effect, damage/3, damage/3);
		me->add("mp",-100);
		target->start_busy(3);
		target->SendState(target);
	}
	else 
	{
		msg += "可是$p猛地向前一跃,跳出了$P的攻击范围。";
		me->start_busy(1);
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

static void remove_effect(CContainer *ob,LONG amount,LONG param)
{
	CChar * target=(CChar *)ob;
	target->add_temp("apply/attack", amount);
	target->add_temp("apply/dodge", amount);
	target->delete_temp("bashi");
	target->SendState(target);
	message_vision("$HIR$N从猛烈的攻击中摆脱了出来，连退数步,稳住了脚步", target);

}

SKILL_END;




