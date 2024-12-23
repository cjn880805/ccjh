SKILL_BEGIN(CSjingang_quan);

virtual void create()
{
	set_name( "大金刚拳");

	Magic_t * magic;

	magic = add_magic("jingang", do_jingang);
	magic->name = "大金刚神通";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[8] = {
		{ "$N盘膝而坐，二手合十，一式「莲花座」，双拳蓄势而发，击向$n的$l",
			180, -5, 0, 0,},
		{"$N一式「烈火锥」，双掌轮流下击，拳势如焰，吡啪爆响",
		200, 5, 10, 10,},
		{ "$N腾空飞起，一式「八方雨」，双手双腿齐出，令$n无可躲藏",
		230, 15, 10, 20,},
		{"$N双掌虚含，掌缘下沉，一式「掌心雷」，缓缓向$n推出",
		270, 5, 20, 30,},
		{ "$N一臂前伸，一臂后指，一式「五指山」，攻向$n的身前身后",
		320, 10, 15, 40,},
		{ "$N一式「观音渡」，两手十指虚点$n的全身三十六道要穴",
		380, 25, 25, 48,},
		{ "$N两目内视，双手内笼，一式「天龙唱」，四面八方响起震人心魄的龙吟",
		450, 15, 35, 54,},
		{ "$N似笑非笑，双拳无形无定，一式「如来笑」，骤然击向$n的前胸",
		530, 20, 50, 60,},
		};

	int level = me->query_skill("jingang_quan", 1);
	for(int i = 8; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	
	return & m_actions;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("大金刚拳必须与少林独门内功配合使用。");
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练大金刚拳。");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练大金刚拳必须空手。");
	if (me->query_skill("hunyuan_yiqi", 1) < 10)
		return notify_fail("你的混元一气功火候不够，无法学大金刚拳。");
	if (me->query("max_mp") < 50)
		return notify_fail("你的内力太弱，无法练大金刚拳。");
	return 1;
}

virtual int valid_enable(string usage) { return  usage=="cuff" || usage=="parry";}

static int do_jingang(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	int d_count, count, qi, maxqi, skill;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( me->query_temp("jingang") ) 
		return notify_fail("你已经在运功中了。");

	if(!target || !me->is_fighting(target) )
    	return notify_fail("「大金刚神通」只能在战斗中使用。");

    if( me->query("mp") < 500 )
		return notify_fail("你的内力还不够高！");

	if( me->query_skill("hunyuan_yiqi", 1) < 60)
		return notify_fail("你的混元一气功的修为不够，不能使用大金刚神通! ");

	if( me->query_skill("cuff") < 150 )
		return notify_fail("你的拳法还不到家，无法使用大金刚神通！");

	if( DIFFERSTR(me->query_skill_mapped("cuff"), "jingang_quan") )
		return notify_fail("你没有激发金刚拳，无法使用大金刚神通！");

	if(DIFFERSTR(me->querystr("family/family_name"), "少林派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
		
    qi = me->query("hp");
	maxqi = me->query("max_hp");
	skill = me->query_skill("jingang_quan", 1) / 3;
	count = me->query_str();
	d_count = me->query_dex() / 2;

	if(qi > (maxqi * 0.4))
	{	
    	message_vision("$N使出大金刚拳的绝技「大金刚神通」，臂力陡然增加！", me);
		
		me->add_temp("str", count * 2);	
		me->add_temp("dex", 0 - d_count);
		me->set_temp("jingang", 1);
		me->call_out(remove_effect, skill, count * 2, d_count);
		me->add("mp", -150);
	}
	else
	{
		message_vision("$N拼尽毕生功力使出了大金刚拳的终极绝技, 全身骨骼一阵爆响, 欲与敌人同归于尽!", me, target);
		me->add_temp("str", count * 9);
		me->set_temp("jingang", 1);

		me->call_out(remove_effect, 2, count * 9, 0);

//		me->add_temp("str",  -(count * 29));		
//		me->delete_temp("jingang");
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		me->set("mp",0l);
		me->add("max_mp",-10);

		message_vision("$N用尽了最后一点气力, 喷出一口鲜血, 一头栽倒在地!", me, target);

		me->set("hp",0l);
//		me->unconcious();
	}
	return 1;
}

static void remove_effect(CContainer * ob, LONG aamount, LONG damount)
{
	CChar * me = (CChar *) ob;

	if ( me->query_temp("jingang") ) 
	{
		me->add_temp("str", -aamount);
		me->add_temp("dex", damount);
		me->delete_temp("jingang");
		me->SendState(me);
		tell_object(me, "你的大金刚神通运行完毕，将内力收回丹田。");
		me->start_busy(random(4));
	}
}

SKILL_END;