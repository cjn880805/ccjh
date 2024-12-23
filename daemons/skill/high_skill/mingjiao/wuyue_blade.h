
// wuyue_blade.h 巫月刀法
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSwuyue_blade);

virtual void create()
{
	set_name( "巫月刀法");

	Magic_t * magic;

	magic = add_magic("jiao", do_jiao);
	magic->name = "铰字诀";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenghuo_shengong") || EQUALSTR(arg, "jiuyang_shengong"))
		return 1;

	return notify_fail("巫月刀法必须与圣火神功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N手中$w轻挥，一招「冬去春来」，身形一转，一刀向$n的$l撩去",100 , -10, 0,0 ,"割伤",},
		{"$N一招「月上西楼」，左脚虚点，$w一收一推，平刃挥向$n的脸部",130 , -10, 8, 10,"割伤",},
		{"$N虚步侧身，一招「推窗望月」，刀锋一卷，拦腰斩向$n", 160, -5, 20, 20,"割伤",},
		{"$N一招「梦断巫山」，$w自上而下划出一个大弧，笔直劈向$n", 190, 5, 35, 34,"割伤",},
		{"$N侧步拧身，一招「似是而非」，拦腰反切，$w砍向$n的胸口", 220, 10,50 ,45 ,"割伤",},
		{"$N挥舞$w，使出一招「月挂中天」，幻起片片刀影，齐齐罩向$n", 240, 15, 60, 59,"割伤",},
		{"$N一招「日月交辉」，只见漫天刀光闪烁，重重刀影向$n的全身涌去", 320, 20, 90, 80,"割伤",},
	};
 		
	int level = 0;
	
	for(int i=7; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("wuyue_blade", 1))
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
	return (usage == "blade") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
    if ( me->query("max_mp") < 80)
		return notify_fail("你的内力不够。");
	if ( me->query_skill("blade", 1) < 30)
		return notify_fail("你的刀术造诣太浅。");
    	if ( me->query_skill("shenghuo_shengong", 1) < 50)
		return notify_fail("你的圣火神功火候太浅。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");
    if ( me->query("hp") < 50)
		return notify_fail("你的体力不够练巫月刀法。");
    me->receive_damage("hp", 25);
    return 1;
	
}

//perform 
static int do_jiao(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * my_w, * target_w;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || ! me->is_fighting(target) )
		return notify_fail("你只能对战斗中的对手使用「铰字诀」。");

	if(! (my_w = me->query_weapon()) 
		|| DIFFERSTR(my_w->querystr("skill_type"), "blade"))
		return notify_fail("你的武器不对。");

	if(! (target_w = target->query_weapon()) )
		return notify_fail("%s是空手，你想绞什么？", target->name());

	target_w = target->query_weapon();
	if( EQUALSTR(target_w->querystr("skill_type"), "throwing") )
		return notify_fail("%s用的是暗器，你想怎么绞？", target->name());

	if( target->is_busy() )
		return notify_fail("%s目前正疲于招架，加紧攻击吧",target->name() );
	
	if(  me->query_skill("wuyue_blade", 1) < 50 )
		return notify_fail("你的巫月刀法不够娴熟，不能使用「铰」字诀。");

	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query("mp") < 50)		//add by Lanwood 2000-12-26
		return notify_fail("你的内力不足。");

	me->add("mp", -50);

	msg =  "$N大喝一声，展开巫月刀法「铰」字诀，连递数个急招企图铰碎$n的兵刃。\n";
	me->start_busy(3);
	
	if(target_w->query("no_duo") && !random(3))
		msg += "可是$n看破了$N的企图，并没有上当。\n";
	else
	{
		char msg1[40];
		if( random(me->query_combat_exp()) > target->query_combat_exp()/2 ) 
		{
			if( target_w->weight() > random(my_w->weight()) ) 
			{
				msg += "结果$p手中的刀刃被$P强力一铰，再也把握不住，立即脱手飞出！"  ;
				if(target_w->query("no_duo") )
				{
					target->command(snprintf(msg1, 40, "unwield %ld", target_w->object_id()));
				}
				else
				{
					target_w->move(target->environment());
					target->start_busy(  me->query_skill("wuyue_blade", 1) / 40 );
				}
			}
			else
			{
				if(target_w->query("no_duo") )
				{
					msg += "结果$p手中的刀刃被$P强力一铰，再也把握不住，立即脱手飞出！"  ;
					target->command(snprintf(msg1, 40, "unwield %ld", target_w->object_id()));
				}
				else
				{
					msg += "结果$p手中的兵刃被$P的强力一击铰了个粉碎！"  ;
					target_w->move(target->environment());
					
					char tmp[40];
					target_w->set_name( snprintf(tmp, 40, "%s的碎片", target_w->name()) );
					target_w->set("value", 0l);
					target_w->del("apply");
					DESTRUCT_OB(target_w, "wuyun_blade::do_jiao");
					target->start_busy(  me->query_skill("wuyue_blade", 1) / 40 );
				}
			}
		} 
		else 
		{
			msg += "可是$p通过巧妙的招架，并没有让$P的计谋得逞。"  ;
		}
	}
	message_vision(msg.c_str(), me, target);

	return 1;
}

SKILL_END;




