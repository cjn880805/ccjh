SKILL_BEGIN(CSzui_gun);

virtual void create()
{
	set_name( "少林醉棍");

	Magic_t * magic;

	magic = add_magic("zuida", do_zuida);
	magic->name = "八仙醉打";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("一指禅必须与少林独门内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[8] = {
		{"「蓝采和，提篮劝酒醉朦胧」，$N手中$w半提，缓缓划向$n的$l",
			180, 0, 5, 10, 10,},
		{"「何仙姑，拦腰敬酒醉仙步」，$N左掌护胸，右臂挟棍猛地扫向$n的腰间",
		200, 5, 10, 15, 20,},
		{"「曹国舅，千杯不醉倒金盅」，$N倒竖$w，指天打地，向$n的$l劈去",
		230, 5, 5, 20, 30,},
		{"「韩湘子，铁棍提胸醉拔萧」，$N横提$w，棍端划了个半圈，击向$n的$l",
		270, 5, 5, 25, 40,},
		{"「汉钟离，跌步翻身醉盘龙」，$N手中棍花团团，疾风般向卷向$n",
		320, 10, 15, 30, 50,},
		{"「铁拐李，踢倒金山醉玉池」，$N单腿支地，一腿一棍齐齐击向$n的$l",
		380, 5, 15, 35, 55,},
		{"「张果老，醉酒抛杯倒骑驴」，$N扭身反背，$w从胯底钻出，戳向$n的胸口",
		450, 5, 20, 40, 60,},
		{"「吕洞宾，酒醉提壶力千钧」，$N腾空而起，如山棍影，疾疾压向$n",
		530, 10, 25, 50, 64,},
	};

	int level = me->query_skill("zui_gun", 1);
	for(int i = 8; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);

			break;
		}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "club"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练少林醉棍。");
	me->receive_damage("hp", 25);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候太浅。");
	return 1;
}

virtual int valid_enable(string usage) { return (usage == "club") || (usage == "parry");}

static int do_zuida(CChar * me, CContainer * ob)	//[八仙醉打]
{
	CChar * target = NULL;
	CContainer * weapon;	
  	string msg;
	int count, count1, cnt, skill;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(! target || !me->is_fighting(target) )
	    return notify_fail("「八仙醉打」只能在战斗中使用。");


	if(DIFFERSTR(me->querystr("family/family_name"), "少林派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "club"))
			return notify_fail("你使用的武器不对。");

	if( me->query_temp("zuida") ) 
		return notify_fail("你已经在运功中了。");

	if( me->query_str() < 25 )
		return notify_fail("你的臂力不够，目前不能使用此绝技! ");

	if( me->query_skill("hunyuan_yiqi", 1) < 60)
		return notify_fail("你的混元一气功的功力不够，不能使用此项绝技！");

	if( me->query_skill("club") < 90)
		return notify_fail("你的棍法修为不够，不能使用此项绝技! ");

    if( me->query("mp") < 500 )
		return notify_fail("你的真气不足！");

	msg = "$HIY$N使出少林醉棍的绝技「八仙醉打」，臂力陡然增加, 身法陡然加快！$COM";
	
   	message_vision(msg.c_str(), me, target);
	skill = me->query_skill("zui_gun",1);
	cnt = me->query_condition("drunk") / 3 ;
	count = me->query("str") * random(cnt + 2);
	count1 = me->query("dex") * random(cnt + 2);

	me->add_temp("str", count);
	me->add_temp("dex", count1);
	me->set_temp("zuida", 1);

	me->call_out( remove_effect, skill / 3, count, count1);
	me->add("mp", -150);
   	return 1;
}

static void remove_effect(CContainer * ob, LONG amount, LONG amount1)
{
	CChar * me = (CChar *)ob;
	
	if (me->query_temp("zuida") ) 
	{
		me->add_temp("str", -amount);
		me->add_temp("dex", -amount1);
		me->delete_temp("zuida");
		tell_object(me, "$HIY你的八仙醉打运功完毕，将内力收回丹田。");
		me->start_busy(4);
		me->SendState(me);
	}
}

SKILL_END;