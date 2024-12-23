SKILL_BEGIN(CSluohan_quan);

virtual void create()
{
	set_name( "罗汉拳");

	Magic_t * magic;

	magic = add_magic("foxue", do_foxue);
	magic->name = "佛云以杀止杀";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("罗汉拳必须与少林独门内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, lvl;
	}action[8] = {
		{"$N连续上步，一式「黄莺落架」，左右手分靠，变拳为掌，击向$n的$l",
			180, 5, 0,},
		{"$N左脚虚踏，全身右转，一招「丹凤朝阳」，右掌猛地插向$n的$l",
		200, 10, 8,},
		{"$N双手大开大阖，宽打高举，使一招「洛钟东应」，双拳向$n的$l打去",
		220, 15, 15,},
		{ "$N左掌圈花扬起，屈肘当胸，虎口朝上，一招「偏花七星」打向$n的$l",
		260, 20, 24,},
		{ "$N使一招「苦海回头」，上身前探，双手划了个半圈，击向$n的$l",
		300, 25, 33,},
		{ "$N双掌划弧，一记「挟山超海」，掌出如电，一下子切到$n的手上",
		360, 30, 42,},
		{"$N施出「慑服外道」，双拳拳出如风，同时打向$n头，胸，腹三处要害",
		420, 35, 50,},
		{ "$N左脚内扣，右腿曲坐，一式「三入地狱」，双手齐齐按向$n的胸口",
		480, 40, 58,},
	};

	int level = me->query_skill("luohan_quan", 1);
	for(int i = 8; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
		
			break;
		}

	if (me->query_temp("teapot/yishazhisha")==1)
		m_actions.set("action","$HIG杀！");
	if (me->query_temp("teapot/yishazhisha")==2)
		m_actions.set("action","$HIY杀！！！");
	if (me->query_temp("teapot/yishazhisha")==3)
		m_actions.set("action","$HIR杀！！！！！！！$GRN");

	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if ((int)me->query("mp") < 20)
		return notify_fail("你的内力不够练罗汉拳。");
	me->receive_damage("hp", 25);
	me->add("mp", -5);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon() )
		return notify_fail("练罗汉拳必须空手。");
	if (me->query_skill("hunyuan_yiqi", 1) < 10)
		return notify_fail("你的混元一气功火候不够，无法学罗汉拳。");
	if (me->query("max_mp") < 50)
		return notify_fail("你的内力太弱，无法练罗汉拳。");
	return 1;
}

virtual int valid_enable(string usage) {return usage=="cuff" || usage=="parry"; }


static int do_foxue(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
//	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || ! me->is_fighting(target))
		return notify_fail("只能对战斗中的对手使用。");

	if(DIFFERSTR(me->query_skill_prepared("cuff"),"luohan_quan"))
		return notify_fail("不准备罗汉拳，不能使出「佛云以杀止杀」!");

	if(me->query_skill("hunyuan_yiqi",1) < 200)
		return notify_fail("你混元一气功的功力不足使用「佛云以杀止杀」!");

	if (me->query_weapon())
			return notify_fail("你不能使用武器！");

	if(me->query_skill("luohan_quan",1) < 200)
		return notify_fail("你的拳法修为不够,还不能使用「佛云以杀止杀」!");

	if(me->query("mp") < 1350)
		return notify_fail("你内力现在不够, 不能使用「佛云以杀止杀」! ");

	if(DIFFERSTR(me->querystr("family/family_name"), "少林派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if(me->query("repute") < 500000)
		return notify_fail("你的杀气不够, 不能使用「佛云以杀止杀」! ");


	message_vision("$CYN\n$N向西合十道：“出家人慈悲为怀。但佛有云：邪魔当道，亦可以杀止杀！",me);
	message_vision("$HIC说罢猛一回头，大喝一声：",me);

	int i;
	i=me->query_str();

	me->add_temp("apply/str",i/3);
	me->set_temp("teapot/yishazhisha",1);
	g_Combatd.Do_Attack(me,target,CCombatd::TYPE_QUICK);
	me->add_temp("apply/str",-i/3);

	me->add_temp("apply/str",i*2/3);
	me->set_temp("teapot/yishazhisha",2);
	g_Combatd.Do_Attack(me,target,CCombatd::TYPE_QUICK);
	me->add_temp("apply/str",-i*2/3);

	me->add_temp("apply/str",i*4/3);
	me->set_temp("teapot/yishazhisha",3);
	g_Combatd.Do_Attack(me,target,CCombatd::TYPE_QUICK);
	me->add_temp("apply/str",-i*4/3);
	me->delete_temp("teapot/yishazhisha");

	me->add("mp",-1350);
	me->start_busy(6);

	return 1;
}

virtual void skill_improved(CChar * me)
{
	int lvl = me->query_skill("luohan_quan", 1);

	if(lvl == 200)
		tell_object(me,"当武功练到高深的境界，就连最基础的拳法也会变成最有效的拳法。。。\n你领悟了罗汉拳至上一式：「佛云以杀止杀」！" );
}


SKILL_END;

