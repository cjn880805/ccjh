//xiaoyao_jianfa.h 逍遥剑法

SKILL_BEGIN(CSxiaoyao_jianfa);

virtual void create()
{
	set_name( "逍遥剑法");
	set("valid_force", "beiming_shengong");
	Magic_t * magic;
	set("diff",150);
	
	magic = add_magic("baji", do_baji);
	magic->name = "燕云八击";
	magic->mp = 1300;
	magic->ap = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "beiming_shengong"))
		return 1;
	
	return notify_fail("逍遥剑法必须与北冥神功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct{
			char action[100];
			int force,dodge, damage ;
			char damage_type[5];
	}action[16]={
		{"$N手中$w剑光四散，一招「轻云闭月」，剑光如云，笼罩了$n的$l，令人不知剑来自何方。",100,-30,200,"刺伤"},
		{"$N身形拔地而起，手中$w舞动，满天剑气森森，一招「流风回雪」罩向$n的$l。",140,-30,220,"刺伤"},
		{"$N长啸连连，使一招「神光离合」，双手闪电般击向$n的$l！",180,-30,180,"刺伤"},
		{"$N将手中$w连晃几个虚招，一招「乍阴乍阳」向$n刺去。",220,-40,160,"刺伤"},
        {"$N舞动$w，一招「轻躯鹤立」，剑如飞星人如闪电，人剑合一，扑向$n的$l。",300,-30,250,"刺伤"},
       	{"$N一招「将飞未翔」，身行飘渺如云烟，忽地向$n的$l一拂！",330,-40,240,"刺伤"},
		{"$N使出一招「若危若安」，身形婉如流水，手中$w从天而降，斩向$n的$l。",350,-30,230,"刺伤"},
		{"$N身行跃起，手中$w挽出朵朵剑花，一招「进止难期」裹住$n的全身。",400,-20,220,"刺伤"},
		
		{"$HIW$N飘然有出尘之意，一招「飞燕凌波」回拍$n的$l！",100,-30,200,"刺伤"},
		{"$HIW$N$w闪动，幻出满天剑影，团团簇簇，一招「燕舞杨柳」往$n$l刺去。",140,-20,220,"刺伤"},
		{"$HIW$N身形一晃，一招「燕弄秋晴」向$n$l刺出一剑。",180,-30,180,"刺伤"},
		{"$HIW$N使一招「燕侣莺俦」，手中$w如一风一般卷向$n的$l。",220,-20,260,"刺伤"},
        {"$HIW$N的$w凭空一指，一招「燕隐惊雷」刺向$n的$l。",300,-10,250,"刺伤"},
       	{"$HIW$N手中的$w一招「雨落幽燕」如绵绵细雨，无孔不入的刺向$n的$l。",330,-10,240,"刺伤"},
		{"$HIW$N手中$w向外一分，使一招「燕处焚巢」反手对准$n$l一剑刺去。",350,-20,230,"刺伤"},
		{"$HIW$N一抖手中$w，使出「劳燕分飞」，不由得暗自情伤，以情驭剑，向$n的$l刺出一剑。",400,-10,220,"刺伤"},
	};
		
	int level = random(8);

	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", action[level].damage);

	if (me->query_temp("teapot/baji"))
	{
		level=me->query_temp("teapot/baji")+7;
		m_actions.set("action", action[level].action);
		m_actions.set("force", action[level].force);
		m_actions.set("dodge", action[level].dodge);
		m_actions.set("damage", action[level].damage);
	}

	if ( !wizardp(me) && (DIFFERSTR((me->environment())->querystr("area"), "逍遥") ||!me->query("xy/save")))
	{
		m_actions.set("force", 0l);
		m_actions.set("dodge", 0l);
		m_actions.set("damage", 0l);
	}

	return & m_actions;
}

virtual int valid_enable(string usage) 
{ 
	return usage=="sword" ; 
}

virtual int valid_learn(CChar * me)
{
	return notify_fail("浮生长恨欢娱少，不痴不嗔自逍遥。");
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("浮生长恨欢娱少，不痴不嗔自逍遥。");
}


static int do_baji(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	CContainer * env=me->environment();
	CContainer * weapon;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if(! target || ! me->is_fighting(target))		
		return notify_fail("只能对战斗中的敌人使用！");
	
	if ( !wizardp(me) && (DIFFERSTR(env->querystr("area"), "逍遥")))
		return	notify_fail("「燕云八击」无法在这里使用。");

	if( !wizardp(me) && !me->query("xy/save"))
		return	notify_fail("「燕云八击」无法在这里使用。。");

	//if( !wizardp(me) && !me->query("xy/renwu5_1"))
	//	return	notify_fail("「燕云八击」无法在这里使用。。");

	if (! (weapon = me->query_weapon())|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
	if(me->query_skill("beiming_shengong",1) < 200)
		return notify_fail("你的北冥神功功力不够，不能使用「燕云八击」!");

	if(me->query_skill("sword") < 250)
		return notify_fail("你的基本剑法修为不够,目前还不能使用「燕云八击」绝技!");
	
	if (me->query_skill("xiaoyao_jianfa", 1) < 300)
		return notify_fail("你的逍遥剑法修为不够,目前还不能使用「燕云八击」绝技!");
	
	if(me->query("mp") < 1300)
		return notify_fail("你内力现在不够, 不能使用「燕云八击」! ");

	if(me->query_temp("fight/ap") < 300)
		return notify_fail("你的AP值现在不够, 不能使用「燕云八击」! ");
	
	if( target->is_busy() )
		return notify_fail("%s目前正自顾不暇，放胆攻击吧！", target->name());
	
	char cmd[255];
	snprintf(cmd, 255,"\n$HIY$N手中%s一圈，带起满天沙尘，突然剑身一颤，化出无数剑尖，一招「燕云八击」笼住$n。",weapon->name(1));
	message_vision(cmd, me, target);

	me->add_temp("fight/ap",-300);
	
	if( random(me->query_combat_exp()) > target->query_combat_exp() / 4 )
	{
		if(!EQUALSTR(target->query_skill_mapped("dodge"), "lingboweibu"))
		{	
			for(int n = 0; n < 8; n++)
			{
				if( EQUALSTR(me->query_skill_mapped("sword"), "xiaoyao_jianfa") 
					&& ((weapon = me->query_weapon())&& EQUALSTR(weapon->querystr("skill_type"), "sword")))
				{
					me->set_temp("teapot/baji",n+1);
					g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
				}
				else
					break;
			}
			
			me->delete_temp("teapot/baji");
			me->start_busy(4);
			me->add("mp", -1300);
		}
		else
		{
			msg += "$HIM$p变幻莫测的步法反而让$P看的眼睛发花,惊讶间顿时不知动弹。\n$COM";
			message_vision(msg.c_str(), me, target);
			me->start_busy(6);
			me->add("mp", -1300);
		}
	}
	else
	{
		msg += "$HIM可是$p看破了$P的企图，并没有上当。\n$COM";
		message_vision(msg.c_str(), me, target);
		me->start_busy(4);
		me->add("mp", -1300);
	}
	
	return 1;
}

SKILL_END;