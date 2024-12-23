//houquan.h 猴拳

SKILL_BEGIN(CShouquan);

virtual void create()
{
	set_name( "猴拳");

	Magic_t * magic;

	magic = add_magic("zhen", do_zhen);
	magic->name = "震字诀";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  force, dodge,  damage, lvl;
	}action[6] = {
		{"$N单腿微曲，忽的向前扑出，一式「仙猴摘桃」，二爪直出，抓向$n的双眼",
			180, 5, 10, 0,},
		{"$N左手虚晃，一式「灵猴攀枝」，右手直击，反扣$n的肩井大穴",
		200, 10, 20, 8,},
		{"$N一臂前伸，一臂后指，一式「猿臂轻舒」，攻向$n的两肋",
		230, 10, 25, 15,},
		{"$N忽然缩成一团，使一式「八方幻影」，双掌无形无定，一爪抓向$n的胸口",
		230, 25, 20, 15,},
		{"$N猛吸一口气，一弯腰，使一式「水中揽月」，双爪疾扣向$n的小腹",
		220, 15, 10, 20,},
		{"$N猛的向上高高跃起，一式「落地摘星」，居高临下，一爪罩向$n的头骨",
		240, 20, 20, 30,},
	};

  	int level = me->query_skill("houquan", 1);
	for(int i = 6; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
	
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
			
	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"|| usage=="hand"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon() )
		return notify_fail("练猴拳必须空手。");
	if (me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候不够，无法学猴拳。");
	if (me->query("max_mp") < 200)
		return notify_fail("你的内力太弱，无法练猴拳。");

	return 1;
}


virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if (me->query("mp") < 10)
		return notify_fail("你的内力不够练猴拳。");
	me->receive_damage("hp", 15);
	me->add("mp", -5);

	return 1;
}

static int do_zhen(CChar * me, CContainer * ob)
{
	int damage;
	string msg;
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||  ! me->is_fighting(target) )
		return notify_fail("神功震敌只能对战斗中的对手使用。");

	if( me->query_weapon())
		return notify_fail("你必须空手才能使用「震」字诀！");

	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");		
		
    if( me->query_skill("houquan", 1) < 40 )
		return notify_fail("你的猴拳不够娴熟，不会使用「震」字诀。");
	                        
    if( me->query("mp") < 100 )
		return notify_fail("你现在内力太弱，不能使用「震」字诀。");
			
	msg = "$N默运神功，使出猴拳「震」字诀，企图以内力震伤$n。";
	
	me->add("mp", -50);

    //if( !target->is_killing(me) ) target->kill_ob(me);

	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		
		damage = me->query_skill("force", 1);
		
        damage = damage/2 + random(damage/2);
		
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/3);
        me->add("mp", -damage/3);
		
		if( damage < 20 ) msg += "结果$n受到$N的内力反震，闷哼一声。";
		else if( damage < 40 ) msg += "结果$n被$N以内力反震，「嘿」地一声退了两步。";
        else if( damage < 80 ) msg += "结果$n被$N以内力一震，胸口有如受到一记重锤，连退了五六步！";
        else msg += "结果$n被$N的内力一震，眼前一黑，身子向后飞出丈许！！";
		
	} 
	else 
	{
        me->start_busy(3);
		msg += "可是$p看破了$P的企图，并没有上当。";
	}

	message_vision(msg.c_str(), me, target);

	return 1;
}

SKILL_END;

