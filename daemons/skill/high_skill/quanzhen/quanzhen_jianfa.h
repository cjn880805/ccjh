
// quanzhen_jianfa.h 全真剑法
//code by Fisho
//date : 2000-12-07
SKILL_BEGIN(CSquanzhen_jianfa);

virtual void create()
{
	set_name( "全真剑法");
	Magic_t * magic;

	set("diff",110);

	magic = add_magic("sanqing", do_sanqing);
	magic->name = "一剑化三清";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("fugu", do_fugu);
	magic->name = "同归于尽";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "xiantian_gong") || EQUALSTR(arg, "xiantian_qigong"))
		return 1;

	return notify_fail("全真剑必须与先天功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N踏奇门，走偏锋，剑尖颤了几颤，一招巧妙无比的 分花拂柳  ，似左实右往$n刺去。", 180, -10, 80, 0, "刺伤",},
		{"$N使一招 琴心三叠  ，身形向上飘起，手中$w虚虚实实幻出三点寒光射向$n的$l刺去!", 200, 5, 80, 5, "刺伤",},
		{"$N身形绕$n一转，猛然一式  罡风扫叶  ，将$w舞出满天剑影，挟着劲风向$n扫去！", 250, 10, 90, 15, "割伤",},
		{"$N仰天长笑，身形飘然而起，在半空中身子一旋，一式  狂歌痛饮  手中$w狂风般地击向$n的$l!", 300, 10, 90, 30, "刺伤",},
		{"$N左手捏着剑诀，右足踏开一招  定阳针  向上斜刺，$w锵然跃出倏的化作几点星光射向$n的$l!", 350, 15, 110,60 , "刺伤",},
		{"$N向前迈去一大步，使出  探海屠龙  ，手中$w使成一个光球，迅若奔雷击向$n的$l！", 400, 15, 80, 80, "刺伤",},
		{"$N运力一抖$w，一式  马蹴落花  ，$w幻出点点剑花，飘然刺向$n的$l", 450,20 , 90, 80, "刺伤",},
		{"$N手中$w一指，纵起丈余，一招  横行漠北  ，$w雷霆般射向$n的$l!", 500, 15, 150, 100, "刺伤",},
		{"$N大喝一声，一招  白虹经天  ，$w闪电般划出一道大圆弧劈向$n的$l!", 500, 0, 210, 130, "割伤",},
		{"$N身形向上飘起，突然一转身，头下脚上，手握剑，一招  絮坠无声  ，无声无息地攻向$n。",500 , 25, 220, 150, "刺伤",},
		{"$N手中$w一抖，一招  照破万缘  ，$w逼出耀眼光芒，奋力击向$n!", 650, 5, 200, 160, "刺伤",},
		{"$N忽然身形高高跃起，使出  浪 迹 天 涯  ，$w幻出漫天花瓣，迅如雷霆射向$n的$l！", 600,15 , 300, 170, "刺伤",},
	};
 
	int level = 0;
	
	for(int i=12; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("quanzhen_jianfa", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
*/			m_actions.set("force", (me->query("skill_pro/全真派/全真派/全真剑法/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/全真派/全真派/全真剑法/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/全真派/全真派/全真剑法/damage")+100) * action[level].damage/100);

			break;
		}
	}
	return & m_actions;
};

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/全真派/全真派/全真剑法/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/全真派/全真剑法/force"));
			if(me->query("skill_pro/全真派/全真剑法/force_point")>=level_point)
			{
				me->add("skill_pro/全真派/全真剑法/force",1);
				me->set("skill_pro/全真派/全真派/全真剑法/force_point",1);
				tell_object(me,"\n$HIR你的全真剑法配合内功更能融汇贯通了。\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/全真派/全真剑法/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/全真派/全真剑法/dodge"));
			if(me->query("skill_pro/全真派/全真剑法/dodge_point")>=level_point)
			{
				me->add("skill_pro/全真派/全真剑法/dodge",1);
				me->set("skill_pro/全真派/全真剑法/dodge_point",1);
				tell_object(me,"\n$HIR你的全真剑法使用得更加得心应手了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/全真派/全真剑法/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/全真派/全真剑法/damage"));
			if(me->query("skill_pro/全真派/全真剑法/damage_point")>=level_point)
			{
				me->add("skill_pro/全真派/全真剑法/damage",1);
				me->set("skill_pro/全真派/全真剑法/damage_point",1);
				tell_object(me,"\n$HIR你的全真剑法威力更大了。\n");
			}
		}
	}
	return "";
}


virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if ( DIFFERSTR(me->querystr("family/master_id"), "wang chongyang"))
		return notify_fail("全真剑法只能跟重阳祖师学习。");
	if ( me->query("max_mp") < 500)
		return notify_fail("你的内力不够。");
	if ( me->query_skill("xiantian_gong", 1) < 50)
		return notify_fail("你的先天神功火候太浅无法学习全真剑法。");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	if ( me->query("hp") < 50)
		return notify_fail("你的体力不够练全真剑法。");
	me->receive_damage("hp", 25);
	return 1;
	
}

//perform 
static int do_sanqing(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(!target || !me->is_fighting(target) )
		return notify_fail("「一剑化三清」只能在战斗中使用。");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("「一剑化三清」开始时必须拿着一把剑！");

	if( DIFFERSTR(me->query_skill_mapped("sword"), "quanzhen_jianfa"))
		return notify_fail("必须配合全真剑法使用。");
	
    if(  me->query("mp") < 150 )
		return notify_fail("你的真气不够！");

	if(DIFFERSTR(me->querystr("family/family_name"), "全真教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    if(  me->query_skill("quanzhen_jianfa",1) < 100 )
		return notify_fail("你的全真剑法还不到家，无法使用「一剑化三清」！");
	
    if(  me->query_skill("xiantian_gong",1) < 60 )
		return notify_fail("你的先天神功火候不够，无法使用「一剑化三清」！");
	
    message_vision("$N 使出全真派绝技 「一剑化三清」 ，身法陡然加快,手握剑柄晃成三条白龙！", me);
    	
    me->add_temp("apply/attack",  me->query_skill("quanzhen_jianfa",1)/2);
	
    g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);
    g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);
    g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);
	
    me->add_temp("apply/attack", -  me->query_skill("quanzhen_jianfa",1)/2);
	
    me->add("mp", -150);
    me->start_busy(random(4));
	
    return 1;
	
}

static int do_fugu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;
	int skill;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target	|| ! me->is_fighting(target) )
		return notify_fail("同归于尽只能对战斗中的对手使用。");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
    if(  (skill = me->query_skill("quanzhen_jianfa", 1)) < 100 )
		return notify_fail("你的全真剑法不够娴熟，不会使用「同归剑法」。");

	if(DIFFERSTR(me->querystr("family/family_name"), "全真教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    if(  me->query_skill("xiantian_gong",1) < 80)
		return notify_fail("你的先天神功火候不够，不能使用「同归剑法」。");
    
	if(!( me->query("eff_hp")<1|| (me->query("max_hp")/me->query("eff_hp"))>=2.5))
		return notify_fail("你还没受重伤，不要使用此剑法。");
	
    if(  me->query("mp") < 500  ) 
		return notify_fail("你的内力不够。");
	
    if(  me->query_temp("qzj_tong") ) 
		return notify_fail("你已经在运功中了。");
	
    msg = "$N左手捏一个剑决，右手握起";
	msg += weapon->name();
	msg += "，拼着最后的力气，一式 「同归剑法」 ，驭剑猛烈绝伦地冲向$n, 意图与$p同归一尽！" ;
    message_vision(msg.c_str(), me, target);
	
    if(!me->query_temp("tjj_sui") && !me->query_temp("qzj_tong") && !me->query_temp("hsj_wu") && !me->query_temp("hmg_dzjm"))
	{
		me->add_temp("apply/attack",  me->query("max_mp")/20);
		me->add_temp("apply/dodge", - me->query_skill("dodge",1)/2);
		me->add_temp("apply/damage", me->query_skill("quanzhen_jianfa",1)/2);
		me->set_temp("qzj_tong", 1);
		me->call_out(remove_effect, skill/10);		//add by lanwood 2000-12-26
	}
	
	if(me->query("mp")>800)
		me->add("mp", - 800);
	else
		me->set("mp",0l);
    return 1;
}

static void remove_effect(CContainer *ob, LONG amount, LONG param)
{
	CChar *me =(CChar *) ob;
	me->add_temp("apply/attack", -  me->query("max_mp")/20);
	me->add_temp("apply/dodge",  me->query_skill("dodge",1)/2);
	me->add_temp("apply/damage",- me->query_skill("quanzhen_jianfa",1)/2);

	me->SendState();
	me->delete_temp("qzj_tong");
}

SKILL_END;
