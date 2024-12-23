// huifeng_jian.h 回风拂柳剑
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CShuifeng_jian);

virtual void create()
{
	set_name( "回风拂柳剑");
	set("valid_force", "linji_zhuang");

	Magic_t * magic;

	magic = add_magic("mie", do_mie);
	magic->name = "灭剑";
	magic->mp = 200;
	magic->valid_cast = CAST_IN_COMBAT;

}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[8];
	}action[] = {
		{"$N剑尖剑芒暴长，一招「清风袭月」，手中$w自左下大开大阖，一剑向右上向$n的$l", 120, 20, 300,0 ,"刺伤",},
		{"$N长剑圈转，一招「飘雪穿云」，手中$w平展下刺，一剑轻轻划过$n的$l", 120, 20, 280, 0,"刺伤",},
		{"$N长剑轻灵跳动，剑随身长，右手$w使出一式「千峰竞秀」刺向$n的$l",140 , 15, 350, 0,"刺伤",},
		{"$N长剑下指，剑意流转，一招「万流归宗」直取$n的$l", 150, 15, 280, 0,"刺伤",},
		{"$N剑芒吞吐，幻若灵蛇，右手$w使出一式「乌龙搅柱」，剑势曼妙，刺向$n的$l", 130, 25,300 ,0 ,"刺伤",},
		{"$N屈腕云剑，剑光如彩碟纷飞，幻出点点星光，右手$w使出一式「大雁啼沙」跃跃洒洒飘向$n的$l", 120, 25,320 , 0,"刺伤",},
		{"$N挥剑分击，剑势自胸前跃出，右手$w一式「进退龙游」，毫无留恋之势，刺向$n的$l", 110, 15,0 ,400 ,"刺伤",},
		{"$N退步，左手剑指划转，腰部一扭，右手$w一记「天地鹤翔」自下而上刺向$n的$l", 150,35 , 400, 0,"刺伤",},
	};
	
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("huifeng_jian", 1))
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
	return (usage == "sword") || (usage == "parry");
}

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
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练回风拂柳剑。");
	me->receive_damage("hp", 10);
	return 1;
}

//perform 
static int do_mie(CChar * me, CContainer * ob)
{
	string msg;
	CContainer * weapon;
	int damage;
	CChar * target= NULL;
	
	if (ob && ob->Query(IS_CHAR))
		target=(CChar *) ob;

	if (!(weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("开什么玩笑，没装备剑就想使「灭剑」？");
	
	if (!target || !me->is_fighting(target) )
		return notify_fail("「灭剑」只能对战斗中的对手使用。");
	
	if (me->query_skill("huifeng_jian", 1) < 60 )
		return notify_fail("你的回风拂柳剑法不够娴熟，还使不出「灭剑」。");
	
	if (me->query_skill("linji_zhuang", 1) < 60 )
		return notify_fail("你的临济十二庄火候不够，「灭剑」不成招式。");

	if (me->query("max_mp")<400)
		return notify_fail("你的内力修为不足，无法运足「灭剑」的内力。");

	if(DIFFERSTR(me->querystr("family/family_name"), "峨嵋派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if (me->query("mp")<200)
	{
		return notify_fail("你现在内力不够，没能将「灭剑」使完！");
	}
	msg =  "$N手中长剑剑芒跃动，剑光暴长，幻出死亡的色彩，剑尖渐";
	msg += "渐逼近$n，$n看到漫天剑光，抽身后跃，只这一刹，漫天剑";
	msg += "影化为一剑直刺$n前胸，快捷无伦，只有一剑！";
	if (random(me->query_skill("force") + 1)>target->query_skill("force")/2 || 
		random(me->query_combat_exp() + 1)>target->query_combat_exp()/3)
	{
		me->start_busy(2);
		target->start_busy(random(3));
		damage = me->query_skill("huifeng_jian", 1);
		if(damage > 0)
			damage = damage + random(damage);
		target->receive_damage("hp", damage/2);
		target->receive_wound("hp", damage);
        msg += "$n根本没法躲避，一式「回风拂柳剑」的绝招「灭剑」端端正";
        msg += "正扎进在$n胸口！$n一低头，看长剑自胸口拔出！";
		me->add("mp", -200);
	} 
	else
	{
		me->start_busy(2);
        msg += "可是$p轻轻一笑，侧身右转，伸出两指，正弹在$P的剑上，长";
        msg += "剑在$p身侧划过，毫发无伤。";
		me->add("mp", -200);
	}
	message_vision(msg.c_str(), me, target);
	//if(!target->is_fighting(me)) target->kill_ob(me);
	return 1;
}

SKILL_END;




