
// tiangang_zhi.h 天罡指穴法
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CStiangang_zhi);

virtual void create()
{
	set_name( "天罡指穴法");
	set("valid_force", "linji_zhuang");

	Magic_t * magic;

	magic = add_magic("lingkong", do_lingkong);
	magic->name = "凌空指穴";
	magic->mp = 300;
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
		{"$N左手轻轻拨动，右手五指徐徐弹出拨，一式「浪起湖心」，拂向$n的$l", 150, 5, "瘀伤", 0, },
		{"$N双手上下起落，俯身掠向$n，一式「瀑落清潭」，左手化掌成指，汹涌袭向$n的$l", 200, 5, "瘀伤", 12, },
		{"$N左手由拳变掌，右手扭曲如灵蛇，一式「龟蛇竞渡」，左右并用，拍向$n的$l", 250, 15, "内伤", 24, },
		{"$N一式「倒索攀山」，左手抽回，右手前探，戟指点向$n的$l", 300, -5, "瘀伤", 36, },
		{"$N使一式「闪现雷鸣」，身影变幻不定地掠至$n身后，猛地拍向$n的$l", 350, 10, "瘀伤", 48, },
		{"$N两臂大开大阖，吸一口气，一式「地动山摇」，劲力透彻，双手快速一拨，激出数道劲气逼向$n的$l",400 , 5, "瘀伤", 60, },
		{"$N身形纵起，衣袂飘荡，双手轻轻拍动，一式「水拍云崖」，居高临下，连绵不绝拍向$n的$l", 450, 20, "内伤", 72, },
		{"$N腾空而起，双掌合一，十指如钩，一招「泰山压顶」，疾向$n的击落，势道凶猛已极", 500, 25, "内伤", 84, },
	};
	
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("tiangang_zhi", 1))
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
	return (usage == "finger") || (usage == "parry");
}

virtual int valid_combine(string combo) { return combo=="jinding_zhang"; }

virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("你的师傅暂时没空指点你武功。。");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("你暂时无法指点你伴侣的武功。。");

    if (me->query_weapon())
		return notify_fail("练天罡指穴法必须空手。");
    if (me->query_skill("linji_zhuang", 1) < 20)
		return notify_fail("你的临济十二庄火候不够，无法学天罡指穴法。");
    if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练天罡指穴法。");
    return 1;
}

virtual int practice_skill(CChar * me)
{
    if (me->query("hp") < 30)
		return notify_fail("你的体力太低了，无法练天罡指穴法。");
    me->receive_damage("hp", 20);
    return 1;
}

static int do_lingkong(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || ! me->is_fighting(target))
		return notify_fail("只能对战斗中的对手使用！");

	if(me->query_str() < 25)
		return notify_fail("你臂力不够,不能使用这一绝技!");
	
	if(me->query_skill("linji_zhuang",1) < 100)
		return notify_fail("你临济十二庄的功力不够不能使用凌空指穴!");
	
	if(me->query_skill("finger") < 100)
		return notify_fail("你的指法修为不够,目前还不能使用凌空指穴绝技!");
	
	if(me->query("mp") < 300)
		return notify_fail("你内力现在不够, 不能使用凌空指穴! ");

	if(DIFFERSTR(me->querystr("family/family_name"), "峨嵋派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( target->is_busy() )
		return notify_fail( "%s目前正自顾不暇，放胆攻击吧 ",target->name());
	
	msg = "$N使出天罡指穴法绝技「凌空指穴」，回过身来，背后竟似生了眼睛一般，左手食中二指向$n接连戳去，一连七指，全是对向$n的头脸与前胸重穴。$n不及攻敌，拼力躲避$N指力顿时动作大乱。\n";
	if( random(me->query_combat_exp() + 1) > target->query_combat_exp() / 4 )
	{
		msg +=   "结果$n被$N指力点中几处穴道! " ;
		target->start_busy( me->query_skill("tiangang_zhi",1) / 20 + 2);
		me->add("mp", -100);
	}
	else
	{
		msg +=  "$n情急智生，狠力一跃，退出老远。" ;
		me->start_busy(4);
	}
	message_vision(msg.c_str(), me, target);
	
	return 1;
	
}

SKILL_END;




