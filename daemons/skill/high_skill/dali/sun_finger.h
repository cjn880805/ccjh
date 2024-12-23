//sun_finger.h  一阳指诀

SKILL_BEGIN(CSsun_finger);

virtual void create()
{
	set_name("正品一阳指");

	Magic_t * magic;

	magic = add_magic("qiankun", do_qiankun);
	magic->name = "一指乾坤";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "kurong_changong") || EQUALSTR(arg, "xiantian_gong"))
		return 1;

	return notify_fail("正品一阳指需要独特内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge,  damage, lvl;
		char damage_type[5];
	}action[] = {
		{"$N一式「阳关三叠」，真气自指间喷薄而出，连出三指，快如电闪，点向$n的$l", 100, 25, 10,0 ,"内伤",},
		{"$N身形一转，一步跨到$n身后。$n急忙转身，$N又如闪电般跃回，一式「鲁阳返日」，右手食指疾出，指向$n的$l", 120, 25, 20, 20,"内伤",},
		{"$N向左踏出一步，左手轻扬，右手食指挟着雄浑内力疾点$n的$l，招式光明坦荡，正是一式「阳春白雪」", 160, 20,40 , 40,"内伤",},
		{"$N身影飘起，一式「阳钩挥天」，自上而下，左脚弯曲如钩，踹向$n的右肩，$n侧身相避，$N右手趁势点向$n的$l", 190,30 , 50, 60,"内伤",},
		{"只见$N脸上忽地一红，左手一收，一式「烈日骄阳」，右手食指斜指，向$n的$l点去", 220, 30, 70, 70,"内伤",},
		{"$N左掌斜削，突然间变掌为指，嗤的一声响，一式「丹凤朝阳」，使出一阳指力，疾点$n的$l", 250, 20, 80, 90,"内伤",},
		{"$N反身一跃，闪身到$n背后，左膝一屈，右手食指回身一式「阴阳交错」，射向$n的后脑", 280, 25, 100, 100,"内伤",},
		{"$N一声大吼, 一式「三阳开泰」，用尽全力向$n的$l点去", 300, 10, 120,130 ,"内伤",},
	};

	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("sun_finger", 1))
		{
			int level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

virtual int valid_combine(string combo) { return combo=="haotian_zhang"; }

virtual int valid_learn(CChar * me)
{
	if ( me->query_weapon() )
		return notify_fail("练一阳指必须空手。");
	
	if (DIFFERSTR(me->querystr("gender"), "男性"))
		return notify_fail("你阳气不足，无法学一阳指。");
	
	if (me->query("max_mp") < 700)
		return notify_fail("你的内力太弱，无法练一阳指。");

	//一阳指应该是全真的绝学吧。

	//和六脉一样，大了就不能学。什么呀。
	/*if (me->query_skill("kurong_changong", 1) < 80 ||
		me->query_skill("tianlong_shengong", 1) < 80)
		return notify_fail("你的本门内功火候不够，无法学一阳指。");
	else
	*/

	return 1;
}

virtual int practice_skill(CChar * me)
{
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力太低了。");
	
	if (me->query("mp") < 30)
		return notify_fail("你的内力不够练一阳指");
	
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

//exert heal
static int do_qiankun(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || ! me->is_fighting(target) )
		return notify_fail("「一指乾坤」只能在战斗中对对手使用。");

	if(me->query_str() < 28)
		return notify_fail("你臂力不够,不能使用这一绝技!");
	
	if (me->query_skill("kurong_changong", 1) < 90)
		return notify_fail("你枯荣禅功的功力不够不能使用一指乾坤");

	if (me->query_skill("sun_finger", 1) < 90)
		return notify_fail("你的一阳指修为不够,目前还不能使用一指乾坤绝技!");

	if( me->query("max_mp") < 850 ) 
		return notify_fail("你内力修为不够, 不能使用一指乾坤!");
	
	if( me->query("mp") < 200 ) 
		return notify_fail("你内力修为不够, 不能使用一指乾坤!");

	if(DIFFERSTR(me->querystr("family/family_name"), "大理段家") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( target->is_busy() )
		return notify_fail("%s目前正自顾不暇，放胆攻击吧 ",target->name());

	msg = "$N使出一阳指绝技「一指乾坤」，罩住了$n的全身要穴, 使$n动弹不得。\n";
	
	if( random(me->query_combat_exp()) > target->query_combat_exp() / 3 )
	{
		msg += "结果$n被$N攻了个措手不及! 一时不能动弹! " ;
		target->start_busy( me->query_skill("sun_finger",1) / 20 );
	}
	else
	{
		msg += "可是$n看破了$N的企图，并没有上当。";
		me->start_busy(4);
	}

	me->add("mp", -200);
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;

