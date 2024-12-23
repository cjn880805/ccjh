// jiuyin_baiguzhao.h 九阴白骨爪
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CSjiuyin_baiguzhao);

virtual void create()
{
	set_name( "九阴白骨爪");

	Magic_t * magic;

	magic = add_magic("du", do_du);
	magic->name = "施毒术";
	magic->mp = 50;
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
		{"$N左爪虚晃，右爪蓄力，一招「勾魂夺魄」直插向$n的$l", 320,10 ,30 ,0 ,"抓伤",},
		{"$N双手连环成爪，爪爪钩向$n，「九子连环」已向$n的$l抓出", 380, 20, 45, 20,"抓伤",},
		{"$N身形围$n一转，使出「天罗地网」，$n的$l已完全笼罩在爪影下", 440, 30, 55,40 ,"抓伤",},
		{"$N使一招「风卷残云」，双爪幻出满天爪影抓向$n全身", 520, 40, 70, 60,"抓伤",},
		{"$N吐气扬声，一招「唯我独尊」双爪奋力向$n天灵戳下", 620, 50,100 ,100 ,"抓伤",},
	};
	
	int level = 0;
	
	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("jiuyin_baiguzhao", 1))
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
	return usage == "claw" || usage == "unarmed" || usage == "parry";
}

virtual int valid_learn(CChar * me)
{
	if ( me->query_weapon())
		return notify_fail("练九阴白骨爪必须空手。");
	
	if (me->query("max_mp") < 200)
		return notify_fail("你的内力太弱，无法练九阴白骨爪。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练九阴白骨爪。");
	me->receive_damage("hp", 30);
	me->add("mp", -20);
	return 1;
}

virtual void skill_improved(CChar * me)
{
	tell_object(me,  "你忽然从心底生出一股恶念：杀、杀、杀！我要杀绝天下人！"  );
	me->add("repute", -200);
}

virtual char * hit_ob(CChar *me, CChar *victim, LONG &damage)
{
	if( damage< 100 ) return 0;
	
	if( random(damage/2) > victim->query_str() )
	{
		victim->receive_wound("hp", (damage - 100) / 2 );
		return  "你听到「喀啦」一声轻响，竟似是骨碎的声音！" ;
	}
	return 0;
}

//perform 
static int do_du(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || ! me->is_fighting(target) )
		return notify_fail("施毒只能对战斗中的对手使用。");
	
	if( me->query_skill("bibo_shengong", 1) < 40 )
		return notify_fail("你的碧波神功不够娴熟，不能施毒。");
	
	if( me->query_skill("jiuyin_baiguzhao", 1) < 40 )
		return notify_fail("你的九阴白骨爪不够娴熟，不能施毒。");
	
	if( me->query("mp") < 20)		//add By Lanwood 2000-12-25
		return notify_fail("你的内力不足！");

	msg = "$N将毒质运于指上，双手手指微微泛出蓝光，抓向$n。\n";
	
	me->start_busy(1);
	if( random( me->query_skill("jiuyin_baiguzhao",1) + 1)  >  random(target->query_skill("dodge") + 1 ) )
	{
		msg +=  " 结果$p被$N抓出一条长长的血痕！" ;
		target->receive_damage("hp",me->query_skill("jiuyin_baiguzhao",1));
		target->receive_wound("hp",15 + random(10));
		target->apply_condition("jy_poison", random(me->query_skill("jiuyin_baiguzhao",1)/5 + 1) + 1 +
			target->query("condition/jy_poison"));
		target->start_busy(random(2));
	} 
	else
	{
		msg += "可是$p急忙闪在一旁，躲了开去。" ;
		me->start_busy(random(4));
	}

	me->add("mp", -20);

	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;
