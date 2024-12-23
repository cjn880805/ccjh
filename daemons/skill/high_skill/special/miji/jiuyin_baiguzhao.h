//jiuyin_baiguzhao.h 九阴白骨爪
//code by sound
//date : 2001-07-23

SKILL_BEGIN(CSjiuyin_baiguzhao);

virtual void create()
{
	set_name("九阴白骨爪");
	
	Magic_t * magic;
	
	magic = add_magic("zhua", do_zhua);
	magic->name = "亡魂一击";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("cuijin", do_zhua);
	magic->name = "摧筋破骨";
	magic->mp = 800;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge, damage;
		int  lvl;
		char damage_type[5];
	}action[5] = {
		{"$N左爪虚晃，右爪蓄力，一招「勾魂夺魄」直插向$n的$l", 
		320, 10, 30, 0, "内伤",},
		{"$N双手连环成爪，爪爪钩向$n，「九子连环」已向$n的$l抓出",
		380, 20, 45, 20, "内伤",},
		{"$N身形围$n一转，使出「天罗地网」，$n的$l已完全笼罩在爪影下",
		440, 30, 55, 40, "内伤",},
		{"$N使一招「风卷残云」，双爪幻出满天爪影抓向$n全身", 
		520, 40, 70, 60, "内伤",},
		{"$N吐气扬声，一招「唯我独尊」双爪奋力向$n天灵戳下", 
		620, 50, 100, 100, "内伤",},
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

virtual char * hit_ob(CChar *me, CChar *victim, LONG &damage_bonus)
{
	if( damage_bonus < 100 ) return 0;
	
	if( random(damage_bonus/2) > victim->query_str() ) 
	{
		victim->receive_wound("hp", (damage_bonus - 100) / 2 );
		return "$HIR你听到「喀啦」一声轻响，竟似是骨碎的声音！$COM\n";
	}
	return 0;
}

virtual int valid_learn(CChar * me)
{
	if ( me->query_weapon())
		return notify_fail("练九阴白骨爪必须空手。");
	
	if (me->query_skill("force", 1) < 50)
		return notify_fail("你的内功心法火候不够，练九阴白骨爪会走火入魔。");

	if (me->query("max_mp") < 200)
		return notify_fail("你的内力太弱，无法练九阴白骨爪。");

	return 1;
}

virtual int practice_skill(CChar * me)
{

	if( me->query("hp") < 250)
		return notify_fail("你的体力太低了。");

	if( me->query("mp") < 250)
		return notify_fail("你的内力不够练九阴白骨爪。");

	if( (me->environment())->query("no_fight") )
		return notify_fail("这里练功会误伤他人。");

	if( (me->environment())->query("sleep_room") )
		return notify_fail("这里练功会打扰别人休息。");

	CContainer * env = me->environment();
	CContainer * obj;
	
	if ( ! (obj = env->PresentName("corpse_ob", IS_CORPSE))
		&& ! (obj = me->PresentName("corpse_ob", IS_CORPSE)) )
		return notify_fail("练九阴白骨抓需有尸体。");

	if( me->query_skill("jiuyin_baiguzhao",1) > 100 && me->query("repute") > -100)
		return notify_fail("这种邪恶武功不是侠义道当练的。");

	me->receive_damage("hp", 40);
	me->add("mp", -100);
	char msg[255];
	tell_room(me->environment(), snprintf(msg, 255, "$HIB只见%s左手上圈下钩、左旋右转，连变了七八般花样，蓦地里右手一伸，噗的一响，五根手指直插入地上尸体的脑门。随后五根手指$HIR血淋淋$HIB的提将起来。", me->query("name")), me);
/*
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( !living(ob[i]) || ob[i]==me ) continue;
		if(skill+random(skill/2)<ob[i]->query("con")*2) continue;
		damage = skill - (ob[i]->query("mp") );
		if( damage > 0 )
		{
			ob[i]->receive_damage("hp", damage );
			if( ob[i]->query("mp") < skill * 2 )
				ob[i]->receive_wound("hp", damage);
			tell_object(ob[i], 
				HIB"忽然眼前黑影狂舞，你觉得眼前一阵阴气直袭面门，全身骤然感到要被撕裂开一样！$COM\n");
		}
		if( userp(ob[i]) ) ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
	}
*/
	return 1;
}

virtual void skill_improved(CChar * me)
{
    tell_object(me, "$HIR你忽然从心底生出一股恶念：杀、杀、杀！我要杀绝天下人！$COM\n" );
    me->add("repute", -200);
}

// zhua.c  九阴白骨爪「亡魂一击」
static int do_zhua(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

    int extra = me->query_skill("jiuyin_baiguzhao",1);

	if( !target ||! me->is_fighting(target) )
        return notify_fail("「亡魂一击」只能对战斗中的对手使用。");
	
    if( me->query("repute") > 0)
        return notify_fail("你是侠义道人士，怎麽能「亡魂一击」这种阴毒武功。");
	
    if( me->query_skill("jiuyin_baiguzhao", 1) < 85 )
        return notify_fail("你的九阴白骨爪不够娴熟，还使不出「亡魂一击」。");

    if( me->query("mp") < 300 )
		return notify_fail("你内力不够了。");

    if( me->query_skill("force", 1) < 85 )
        return notify_fail("你的内功心法火候不够，使用「亡魂一击」会震伤自己的经脉。");

	me->add_temp("apply/attack",extra*2);
	me->add_temp("apply/damage",extra*2);

	message_vision("$HIR$N突然将双掌变爪合于胸前，然后象风车般急转数圈，而后施展出「亡魂一击」，双爪向外一翻，随后绕着$n疾转数圈，又回到原地。$COM\n", me, target);
	
//	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

    me->add("mp", -100);
	me->start_busy(2);
	me->add_temp("apply/attack",-extra*2);
	me->add_temp("apply/damage",-extra*2);

    return 1;
}

// cuijin.c  九阴白骨爪「摧筋破骨」
static int do_cuijin(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

    int damage;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("「摧筋破骨」只能对战斗中的对手使用。");
	
    if( me->query_skill("jiuyin_baiguzhao", 1) < 180 )
		return notify_fail("$WHT你的九阴白骨爪不够娴熟，还使不出「摧筋破骨」。$COM");

    if( me->query_skill("force", 1) < 180 )
		return notify_fail("$RED你的内功心法火候不够，使用「摧筋破骨」会震伤自己的经脉。$COM");

    if( me->query("mp") < 800 )
		return notify_fail("你内力不够了。");

    msg = "$HIC$N一声怪啸，绕着$n急转数圈，而后施展出「摧筋破骨」，双爪齐出，直插$n前胸。$COM\n";

    if (random(me->query("combat_exp")) > target->query("combat_exp")/2)
	{
		if (me->query("mp") > target->query("mp")/2)
		{
			me->start_busy(3);
			damage = target->query("max_hp");
			target->receive_damage("hp", damage/2);
			target->receive_wound("hp", damage/2);                         
			me->add("mp", -300);

			msg += "$HIR$N已在$n前胸留下了五个整整齐齐的指洞！$n只觉胸口巨痛，鲜血狂喷而出！！！$COM\n";
		} 
		else 
		{
			me->start_busy(3);
			damage = target->query("max_hp");
			target->receive_damage("hp", damage/20);
			target->receive_wound("hp", damage/20);                         
			me->add("mp", -400);

			msg += "$HIY$N只觉$n内力浑厚！双爪竟不能惯胸而入,只在$n胸前留下了一道血痕！！！$COM\n";
		} 
	} 
    else
	{
		me->start_busy(3);
		me->add("mp", -300);
		msg += "$HIY可是$p早有防备，不慌不忙,卸开了$P的双爪。$COM\n";
	}
	message_vision(msg.c_str(), me, target);

	if( !target->is_killing(me) ) target->kill_ob(me);
/*
    if(userp(target)) target->fight_ob(me);

    else if( !target->is_killing(me) ) target->kill_ob(me);
*/
    return 1;
}

SKILL_END;
