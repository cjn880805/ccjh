// yanxing_dao.h 雁行刀法
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CSyanxing_dao);

virtual void create()
{
	set_name( "雁行刀法");
	set("valid_force", "linji_zhuang");

	Magic_t * magic;

	magic = add_magic("huanying", do_huanying);
	magic->name = "无形幻影";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge;
		char damage_type[5];
		int  lvl;
	}action[] = {
		{"$N使出「让字诀」，上身侧过，手中刀斜斜砍出，一道白光劈向$n的$l", 170, 30, "砍伤", 0,},
		{"$N使出「打字诀」，左手护顶，大喝一声，右手刀当头直劈，化作一道白芒直向$n的$l砍落", 240, 15, "砍伤", 10,},
		{"$N使出「顶字诀」，左手后撤，刀斜上招架，顺势下剁，左手自腋下穿出，托住对方手腕，刀光不停指向$n的$l", 300, 5, "砍伤", 20,},
		{"$N使出「引字诀」，侧身而上，身形突闪，左手带过对方$n兵刃，右手刀猛地弹出，把$n绞在刀光中",350 , -5, "砍伤", 30,},
		{"$N使出「套字诀」，身形向后乍然一闪，左手急速缠住$n左手，手中刀一阵乱披风，刀光罩住$n的$l", 400, 20, "砍伤", 40,},
		{"$N使出「陈字诀」，身法陡变，轻灵飘忽，捉摸不透，乘$n眼花耳鸣之际，右手刀光反卷向$n的$l", 425, 15, "砍伤", 50,},
		{"$N使出「探字诀」，轻盈地一个急转身，两脚撤步，右手刀尽力向前，直抵$n的$l",450 ,20 , "砍伤", 60,},
		{"$N凝神使出「逼字诀」，身随意转，手随心动，绕着$n疾转，手中刀光漫卷，将$n的全身笼罩在自己布下的刀网中，无从逃脱", 500, 25, "砍伤", 70,},
		{"$N凝神使出「藏字诀」，侧身藏刀，引诱$n前进了一步，刀光陡现，势如千军万马，奔腾而出", 500, 25, "砍伤", 80,},
		{"$N凝神使出「错字诀」，双手交叉，刀光批攉，$n实在看不清刀光来向，退后欲避，只觉一阵寒气直逼过来", 500, 25, "砍伤", 90,},
	};
	
	int level = 0;
	
	for(int i=10; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("yanxing_dao", 1))
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
	return (usage == "blade") || (usage == "parry");}

virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("你的师傅暂时没空指点你武功。。");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("你暂时无法指点你伴侣的武功。。");

	if (me->query("max_mp") < 50)
		return notify_fail("你的内力不够。");
    if (me->query_skill("linji_zhuang", 1) < 20)
		return notify_fail("你的临济十二庄火候太浅。");
    if (me->query_skill("blade", 1) < me->query_skill("yanxing_dao", 1) )
		return notify_fail("你的基本刀法火候太浅。");
    return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练雁行刀。");
	me->receive_damage("hp", 10);
	return 1;
}

//perform 
static int do_huanying(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target || ! me->is_fighting(target) )
		return notify_fail("「无形幻影」只能对战斗中的对手使用。");
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("开什么玩笑，没装备刀怎么使「无形幻影」？");
	
	if( DIFFERSTR(me->query_skill_mapped("blade"), "yanxing_dao"))
		return notify_fail("必须配合雁行刀法使用。");
	
    if (me->query_skill("yanxing_dao", 1) < 60 )
        return notify_fail("你雁行刀法不够娴熟，使不出「无形幻影」。");
    
	if (me->query_skill("linji_zhuang", 1) < 90 )
        return notify_fail("你临济庄火候不够，「无形幻影」不成招式。");

	if(DIFFERSTR(me->querystr("family/family_name"), "峨嵋派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
    
	if (me->query("max_mp")<300)
        return notify_fail("你的内力修为不足，无法运足「无形幻影」的内力。");
    
	if (me->query("mp")<200)
    {
        return notify_fail("你现在内力不够，没能将「无形幻影」使完！");
    }
    
	msg = "$N大喝一声，全场四处游动，$n只看到$N化做数团身影，漫天刀光席卷而来，$n奋力一架，但$N刀分数路，$n只架住一刀！";
    message_vision(msg.c_str(), me, target);
	
	//关于连砍五刀的法术
    g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
    
    me->add("mp", -200);
    me->start_busy(random(5));
    //if(!target->is_fighting(me)) 
	//	target->kill_ob(me);
    return 1;
	
}

SKILL_END;




