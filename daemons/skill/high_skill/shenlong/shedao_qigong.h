
// shedao_qigong.h 蛇岛气功
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSshedao_qigong);

virtual void create()
{
	set_name( "蛇岛奇功");

	Magic_t * magic;

	magic = add_magic("chang", do_chang);
	magic->name = "惊魂绝唱第一段";
	magic->mp = 300;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("chang2", do_chang2);
	magic->name = "惊魂绝唱第二段";
	magic->mp = 0;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("chang3", do_chang3);
	magic->name = "惊魂绝唱第三段";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  damage,dodge,parry,force;
		char damage_type[5];
	}action[] = {
		{"$N使一招「仙鹤梳翎」手中$w一提，插向$n的$l", 40,0 , 40, 150,"挫伤",},		
		{"$N使出「灵蛇出洞」，身形微弓,手中$w倏的向$n的$l戳去", 50, 80, 10, 250,"刺伤",},		
		{"$N身子微曲,左足反踢,乘势转身,使一招「贵妃回眸」，右手$w已戳向$n$l", 60, 80, 20, 250,"刺伤",},		
		{"$N使一式「飞燕回翔」，背对着$n,右足一勾,顺势在$w上一点,$w陡然向自己咽喉疾射.接着$N身子往下一缩,$w掠过其咽喉,急奔$n急射而来", 70,50 , 40, 350,"刺伤",},		
		{"$N忽的在地上一个筋斗,使一招「小怜横陈」,从$n胯下钻过,手中$w直击$n", 80, 70, 30, 350,"刺伤",},		
		{"$N大吼一声，使一招「子胥举鼎」，反手擒拿$n极泉要穴,欲将$n摔倒在地", -25, -10, 70, 400,"内伤",},		
		{"$N双腿一缩,似欲跪拜,一招「鲁达拨柳」左手抓向$n右脚足踝,右手$w直击$n小腹", 80, 80, -10, 400,"内伤",},		
		{"$N突然一个倒翻筋斗,一招「狄青降龙」,双腿一分,跨在肩头,双掌直击$n", 90,90 , 30, 400,"内伤",},		
	};

	int level = 0;

	level = random(8);
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", action[level].damage);
	m_actions.set("parry", action[level].parry);
	m_actions.set("force", action[level].force);
	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="sword"|| usage=="staff"|| usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())) 
		return 0;
	
	if ( DIFFERSTR(weapon->querystr("skill_type"), "staff")
		&& DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
	if ( me->query_skill("shenlong_xinfa", 1) < 50)
		return notify_fail("你的神龙心法火候不够，无法学蛇岛奇功.");
	
	if ( me->query_skill("force", 1) < 50)
		return notify_fail("你的基本内功火候不够，无法学蛇岛奇功。");
	
	if ( me->query_skill("shenlong_bashi", 1) < 50)
		return notify_fail("你的神龙八式火候不够，无法学蛇岛奇功。");
	
	if ( me->query_skill("shenlong_xinfa",1) < me->query_skill("shedao_qigong",1))
		return notify_fail("你的神龙心法火候不够，无法继续学蛇岛奇功。");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 50)
		return notify_fail("你的体力太低了。");
	if ( me->query("mp") < 30)
		return notify_fail("你的内力不够练蛇岛奇功。");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
	
}

//perform 
static int do_chang(CChar * me, CContainer * ob)
{
	if(	! me->is_fighting() )
		return notify_fail("唱仙法只能在战斗中使用。");
	
	if( DIFFERSTR(me->query_skill_mapped("force"), "shenlong_xinfa") )
		return notify_fail("必须配合神龙心法使用。");	

	if(  me->query_skill("shedao_qigong", 1) < 60 )
		return notify_fail("你的蛇岛奇功不够娴熟，不会使用唱仙法。");
	
	if(  me->query("mp") < 300 )
		return notify_fail("你已经唱得精疲力竭,内力不够了。");

	if(DIFFERSTR(me->querystr("family/family_name"), "神龙教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if(  me->query_temp("chang") == 50 )
		return notify_fail("你已经唱得太久了,不能再唱了。");
	
	//int skill = me->query_skill("force");
	me->add("mp", -200);
	message_vision( "只听$N口中念念有词，顷刻之间武功大进！"  , me);
	me->add_temp("apply/attack", 1);
	me->add_temp("apply/dodge", 1);
	me->add_temp("apply/defense", 1);
	me->add_temp("chang", 1);
	return 1;
}

static int do_chang2(CChar * me ,CContainer * ob)
{
	if( !me->is_fighting() )
		return notify_fail("唱仙法只能在战斗中使用。");
	
	if( DIFFERSTR(me->query_skill_mapped("force"), "shenlong_xinfa") )
		return notify_fail("必须配合神龙心法使用。");

	if(  me->query_skill("shedao_qigong", 1) < 80 )
		return notify_fail("你的蛇岛奇功不够娴熟，不会使用唱仙法。");

	if(DIFFERSTR(me->querystr("family/family_name"), "神龙教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query_temp("apply/attack")<=0|| me->query_temp("apply/dodge") <=0|| me->query_temp("apply/defense") <=0 )
		return notify_fail("你目前战斗力太低,不能再恢复内力了。");
	
	if(  me->query_temp("chang") <=-30  )
		return notify_fail("你已经唱得太久了,不能再唱了。");
	
	message_vision(  "只听$N口中念念有词，顷刻之间内力大涨！"  , me);
	me->add_temp("apply/attack", -1);
	me->add_temp("apply/dodge", -1);
	me->add_temp("apply/defense", -1);
	me->add_temp("chang", -1);
	me->add("mp", 100);
	return 1;
}

static int do_chang3(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target	||	!me->is_fighting(target) )
		return notify_fail("唱仙法只能在战斗中使用。");

	if( DIFFERSTR(me->query_skill_mapped("force"), "shenlong_xinfa") )
		return notify_fail("必须配合神龙心法使用。");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "神龙教") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if(  me->query_skill("shedao_qigong", 1) < 100 )
		return notify_fail("你的蛇岛奇功不够娴熟，不会使用唱仙法吼字决。");
	
	if( (me->environment())->query("no_fight") )
		return notify_fail("在这里不能攻击他人。");
	
	if(  me->query("mp") < 500 )
		return notify_fail("你已经唱得精疲力竭,内力不够了。");
	
	
	int neili = me->query("mp");
	
	me->add("mp", -(300+random(200)));
	me->receive_damage("hp", 10);
	
	me->start_busy(random(5));
	
	message_vision( "$N深深地吸一囗气，忽然仰天长啸，高声狂叫：我真他妈的是个天才！！！"  , me);
	
	if( neili/2 + random(neili/2) <  target->query("mp")/10) 
		return notify_fail("敌人的内力比你高出太多,伤不了！");
	
	int damage = (neili -  target->query("max_mp")) / 10;
	if( damage > 0 )
	{
		target->receive_damage("hp", damage);
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage);
		target->receive_wound("hp", damage);
		message_vision( "$N只觉脑中一阵剧痛，金星乱冒，犹如有万条金龙在眼前舞动。"  , target);
	}
	else
	{
		message_vision( "$N只觉脑中微痛，似乎受了一点轻伤。"  , target);
		target->receive_damage("hp", 10 );
		target->receive_damage("hp", 10 );
		target->receive_wound("hp", 10);
	}
	//if( !target->is_killing(me) ) target->kill_ob(me);
	//if( !me->is_killing(target) ) me->kill_ob(target);
	return 1;
}

SKILL_END;
