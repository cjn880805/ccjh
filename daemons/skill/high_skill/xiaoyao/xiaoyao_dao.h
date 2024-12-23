//xiaoyao-dao  逍遥刀法

SKILL_BEGIN(CSxiaoyao_dao);

virtual void create()
{
	set_name( "逍遥刀法");
	set("valid_force", "beiming_shengong");

	set("diff",140);
	Magic_t * magic;

	magic = add_magic("daoshenxiao", do_daoshenxiao);
	magic->name = "刀神一笑";
	magic->mp = 1000;
	magic->ap=100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, lvl, damage;
	}action[] = {
		{"$N身形微动，一招「彩虹飞天」手中$w化做一道白虹，直劈向$n的胸前", 220,5,20,0,30,},
		{"$N身形急转，一招「回风转云」，舞起一片刀花，$w飞劈$n", 260,0,8,15,40,},
		{"$N气贯刀锋，$w扬起一阵风声，一招「大风起兮」，劈向$n的头顶", 320,-10,15,30,50,},
		{"$N刀锋急转，变幻莫测，一招「北燕南归」，$w反劈向$n的后心", 340,-10,20,50,50,},
		{"$N面带微笑，刀尖化出无数白点，一招「人面桃花」，攻击向$n全身", 370,-20,15,80,60,},
		{"$N使出一招「似是而非」，刀不象刀，剑不象剑，攻击向$n周身要害", 380,-35,50,100,60,},
		{"$N使一式「轻于鸿毛」，$w如同虚无飘渺一般，不断的直向$n攻去", 390,-10,70,130,100,},
		{"$N劲运于宝刀,一招「天外来峰」，$w如有千斤一般，直直向$n劈去", 400,-10,70,150,150,},
	};

	struct {
		char action[255];
	}action1[] = {
		{"$HIG$N使一招「对酒当歌」，手中宝刀风似地向$n斩去！",},
		{"$HIR$N弯刀似月，宝刀随著一招「人生几何」由下而上撩往$n。 ",},
		{"$HIC$N身形一转，一招「譬如朝露」宝刀如朝露闪烁，斩向$n 。",},
		{"$HIC$N舞动宝刀，一招「去日苦多」往$n斜斜砍出一刀！",},
		{"$HIY$N手中宝刀一晃，一招「慨当以慷」迅捷无伦地劈向$n！",},
		{"$HIG$N提气丹田，身型乍展，一招「忧思难忘」直劈$n。",},
		{"$HIR$N移步侧身，使一招「何以解忧」刀光霍霍斩向$n。",},
		{"$HIG$N使出一招「唯有杜康」，用手中的宝刀急削$n的五指！",},
		{"$HIC$N左脚踏前一步，一招「青青子衿」，手中的宝刀从侧面飘向$n之必救！",},
		{"$HIM$N手中的宝刀一抖，挽出一片刀花，一招「悠悠我心」，撒向$n的全身！",},
		{"$HIG$N微退一步，手中的宝刀划出一条光弧，一招「但为君故」，将$n的全身围住！ ",},
		{"$HIW$N使出一招「沉吟至今」，用手中的宝刀急砍$n！",},
		{"$HIR$N左脚踏前踏，一招「呦呦鹿鸣」，手中的宝刀挥向$n之必救。",},
		{"$HIY$N手中的宝刀一抖，一招「山不厌高」，奔向$n！",},
		{"$HIG$N手中的宝刀划出一招「天下归心」，将$n的全身围住！",},
	};
		

	int level = me->query_skill("xiaoyao_dao", 1);
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			if(!me->query_temp("daoshenxiao"))
				m_actions.set("action", action[level].action);
			else
			{
				m_actions.set("action", action1[me->query_temp("daoshenxiao")-1].action);
			}
/*
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
*/
			m_actions.set("force", (me->query("skill_pro/逍遥派/逍遥刀法/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/逍遥派/逍遥刀法/dodge")+100) * action[level].dodge/100);
			m_actions.set("parry", (me->query("skill_pro/逍遥派/逍遥刀法/parry")+100) *action[level].parry);
			m_actions.set("damage", (me->query("skill_pro/逍遥派/逍遥刀法/damage")+100) * action[level].damage/100);
			
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="blade"; }

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/逍遥派/逍遥刀法/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/逍遥派/逍遥刀法/force"));
			if(me->query("skill_pro/逍遥派/逍遥刀法/force_point")>=level_point)
			{
				me->add("skill_pro/逍遥派/逍遥刀法/force",1);
				me->set("skill_pro/逍遥派/逍遥刀法/force_point",1);
				tell_object(me,"\n$HIR你的逍遥刀法配合内功更能融汇贯通了。\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/逍遥派/逍遥刀法/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/逍遥派/逍遥刀法/dodge"));
			if(me->query("skill_pro/逍遥派/逍遥刀法/dodge_point")>=level_point)
			{
				me->add("skill_pro/逍遥派/逍遥刀法/dodge",1);
				me->set("skill_pro/逍遥派/逍遥刀法/dodge_point",1);
				tell_object(me,"\n$HIR你的逍遥刀法使用得更加得心应手了。\n");
			}
		}
		else if(victim->query("parry")) 
		{
			me->add("skill_pro/逍遥派/逍遥刀法/parry_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/逍遥派/逍遥刀法/parry"));
			if(me->query("skill_pro/逍遥派/逍遥刀法/parry_point")>=level_point)
			{
				me->add("skill_pro/逍遥派/逍遥刀法/parry",1);
				me->set("skill_pro/逍遥派/逍遥刀法/parry_point",1);
				tell_object(me,"\n$HIR你熟练的使用逍遥刀法，防守能力进一步加强了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/逍遥派/逍遥刀法/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/逍遥派/逍遥刀法/damage"));
			if(me->query("skill_pro/逍遥派/逍遥刀法/damage_point")>=level_point)
			{
				me->add("skill_pro/逍遥派/逍遥刀法/damage",1);
				me->set("skill_pro/逍遥派/逍遥刀法/damage_point",1);
				tell_object(me,"\n$HIR你的逍遥刀法威力更大了。\n");
			}
		}
	}
	return "";
}

virtual int valid_learn(CChar * me)
{

	if ( DIFFERSTR(me->querystr("family/family_name"), "逍遥派"))
		return	notify_fail("逍遥刀必须是逍遥派弟子方可以学习");

	if (me->query_skill("blade", 1) < 20)
		return notify_fail("你的基本刀法太差了练不了逍遥刀法。");

	if (me->query_skill("blade", 1) < me->query_skill("xiaoyao_dao", 1))
		return notify_fail("你的基本刀法火候不够，不能继续修炼逍遥刀法了。");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if ( DIFFERSTR(me->querystr("family/family_name"), "逍遥派"))
		return	notify_fail("逍遥刀必须是逍遥派弟子方可以练习");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");

	if (me->query_skill("blade", 1) < me->query_skill("xiaoyao_dao", 1))
		return notify_fail("你的基本刀法火候不够，不能继续修炼逍遥刀法了。");
	
	if (me->query("hp") < 30)
		return notify_fail("你的体力不够练不了逍遥刀法。");

	me->receive_damage("hp", 30);

	return 1;
}

static int do_daoshenxiao(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	int harm;
	string msg;
	CContainer * weapon;
	char cmd[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || ! me->is_fighting(target))		
		return notify_fail("只能对战斗中的敌人使用！");

	if(me->query_str() < 25)
		return notify_fail("你臂力不够,不能使用这一绝技!");

	if ( !wizardp(me) && (DIFFERSTR(me->querystr("family/family_name"), "逍遥派")))
		return	notify_fail("［刀神一笑］必须是逍遥派弟子方可以使用");

	if(me->query_skill("beiming_shengong",1) < 100)
		return notify_fail("你的北冥神功功力不够，不能使用［刀神一笑］!");
	
	if(me->query_skill("xiaoyao_dao",1) < 180)
		return notify_fail("你的逍遥刀法功力不够，不能使用［刀神一笑］!");

	if (! (weapon = me->query_weapon())	|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("手中无刀，怎能施展出到刀中绝技［刀神一笑］!");

	if(me->query_skill("blade") < 180)
		return notify_fail("你的基本刀法修为不够,目前还不能使用［刀神一笑］绝技!");

	if(me->query("mp") < 1000)
		return notify_fail("你内力现在不够, 不能使用［刀神一笑］! ");

	if ( me->query("xiaoyao/禁用绝招")==1 )
		return notify_fail("今生今世已经无法再使用本门至上绝招［刀神一笑］了!"); 

	if ( me->query("xiaoyao/xiaoyaodao") < 1 )
		return notify_fail("未得师尊许可，不敢擅用本门禁招！");

	if ( me->query("xiaoyao/挨骂")>=1)
		return notify_fail("刚给师傅骂过，不敢再用绝招了！");

	if( target->is_busy() )
		return notify_fail("%s目前正自顾不暇，放胆攻击吧！", target->name());

	msg = "\n$HIM$N身形如鬼魅般的逼近$n,竟使出一招逍遥刀法中失传已久的旷世绝技$HIR「刀神一笑」。$COM\n";
	msg += "$HIM内力自右手手中宝刀激荡而出，竟将宝刀硬生生的化做一片片碎片刀片，朝$n击来。$COM\n";
	msg += "$HIM口中放声长啸，伴随着刀片破空的嗡鸣，高唱起一曲「短歌行」。$COM\n";
	message_vision(msg.c_str(), me, target);

	if( random(me->query_combat_exp()) > target->query_combat_exp() / 10 )
	{
		if(!EQUALSTR(target->query_skill_mapped("finger"), "liumai_shenjian"))
		{		
			if(me->query_temp("apply/刀神一笑"))
			{
				me->set_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				me->add_temp("daoshenxiao",1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

				msg =  "\n\n$HIR$n全身上下被笼罩在一片刀光碎影之中，飞舞的刀片割的$n遍体鳞伤。 $COM";
				message_vision(msg.c_str(), me, target);
				
				harm=(random((me->query_str()/4+me->query_combat_exp()/30000)/2)+120)*me->query_skill("xiaoyao_dao", 1)/20;
				target->add("hp", -harm);
				snprintf(cmd ,255,"$HIR结果造成了%d点的伤害。$COM\n",harm);
				message_vision(cmd,me,target);
				me->add("mp", -me->query("mp"));
				me->delete_temp("daoshenxiao");
				me->start_busy(99);	
				
			}
			else
			{
				msg =  "\n$HIG$N使一招「对酒当歌」，手中宝刀风似地向$n斩去！$COM\n";
				msg +=  "\n$HIR$N弯刀似月，宝刀随著一招「人生几何」由下而上撩往$n $COM\n";
				msg +=  "\n$HIC$N身形一转，一招「譬如朝露」宝刀如朝露闪烁，斩向$n $COM\n";
				msg +=  "\n$HIC$N舞动宝刀，一招「去日苦多」往$n斜斜砍出一刀！ $COM\n";
				message_vision(msg.c_str(), me, target);
				msg =  "\n$HIY$N手中宝刀一晃，一招「慨当以慷」迅捷无伦地劈向$n！ $COM\n";
				msg +=  "\n$HIG$N提气丹田，身型乍展，一招「忧思难忘」直劈$n $COM\n";
				msg +=  "\n$HIR$N移步侧身，使一招「何以解忧」刀光霍霍斩向$n $COM\n";
				msg +=  "\n$HIG$N使出一招「唯有杜康」，用手中的宝刀急削$n的五指！ $COM\n";
				message_vision(msg.c_str(), me, target);
				msg =  "\n$HIC$N左脚踏前一步，一招「青青子衿」，手中的宝刀从侧面飘向$n之必救！ $COM\n";
				msg +=  "\n$HIM$N手中的宝刀一抖，挽出一片刀花，一招「悠悠我心」，撒向$n的全身！ $COM\n";
				msg +=  "\n$HIG$N微退一步，手中的宝刀划出一条光弧，一招「但为君故」，将$n的全身围住！ $COM\n";
				message_vision(msg.c_str(), me, target);
				msg =  "\n$HIW$N使出一招「沉吟至今」，用手中的宝刀急砍$n！ $COM\n";
				msg +=  "\n$HIR$N左脚踏前踏，一招「呦呦鹿鸣」，手中的宝刀挥向$n之必救。 $COM\n";
				msg +=  "\n$HIY$N手中的宝刀一抖，一招「山不厌高」，奔向$n！ $COM\n";
				message_vision(msg.c_str(), me, target);
				msg =  "\n$HIG$N手中的宝刀划出一招「天下归心」，将$n的全身围住！$COM\n\n";
				msg +=  "\n$HIR$n全身上下被笼罩在一片刀光碎影之中，飞舞的刀片割的$n遍体鳞伤。 $COM";
				message_vision(msg.c_str(), me, target);
				harm=(random((me->query_str()/4+me->query_combat_exp()/30000)/2)+120)*me->query_skill("xiaoyao_dao", 1)/20;
				target->add("hp", -harm);
				snprintf(cmd ,255,"$HIR结果造成了%d点的伤害。$COM\n",harm);
				message_vision(cmd,me,target);
				me->add("mp", -1000);
				me->start_busy(5);		
			}
		}
		else
		{
			msg = "$HIR$p身法忽然加快，直逼到$P的面前，手指已经按上$P小腹，六脉剑气猛然射出！！\n$COM";
			message_vision(msg.c_str(), me, target);
			harm=(random(target->query("age")/4+target->query("per")/3)+1)*(random(target->query_skill("liumai_shenjian", 1)/20)+25)*4;
			snprintf(cmd ,255,"$HIR结果$N受到了%d点的伤害。$COM\n",harm);
			message_vision(cmd,me,target);
			me->add("mp", -500);
			me->start_busy(6);
		}
	}
	else
	{
		msg = "$HIM可是$p看破了$P的企图，并没有上当。\n$COM";
		message_vision(msg.c_str(), me, target);
		me->start_busy(4);
		me->add("mp", -500);
	}
	destruct(weapon);
	msg ="$HIW宝刀的碎片化成一道白光，消散不见了……$COM\n";
	if(!me->query_temp("apply/刀神一笑"))
	{
		msg+="$HIY$N见状心中连连后悔，暗恨自己只图呈一时之快，震碎了师父下山前赠送给自己的宝刀。$COM\n";
		msg+="$HIY不由的担心起今后见到师父时，要是师父发现宝刀不见而察觉自己偷用禁招而带来的麻烦。$COM\n\n";
		msg+="$HIR巫师公告：本绝招目前还在测试阶段，正式推出后将有重大改动。敬请留意金智塔公司论坛通知。$COM\n";
				
		if ( me->query("xiaoyao/xiaoyaodao") >0 )
		{
			me->add("xiaoyao/xiaoyaodao", -1);
		}
		else
		{
			me->set("xiaoyao/禁用绝招", 1);
		}
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;





