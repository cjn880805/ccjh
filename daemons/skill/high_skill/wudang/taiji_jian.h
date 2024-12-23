// taiji-jian.c 太极剑

void remove_effect(CContainer * me, LONG amount1, LONG amount2)
{
	CChar * ob = (CChar * )me;
		
	ob->add_temp("apply/attack", - amount1);
	ob->add_temp("apply/dodge", - amount2);
	ob->delete_temp("tjj_sui");
	tell_object(ob, "你的随字决运行完毕，将内力收回丹田。");
}

SKILL_BEGIN(CStaiji_jian);

virtual void create()
{
	set_name( "太极剑");
	set("valid_force", "taiji_shengong");

	Magic_t * magic;

	magic = add_magic("sui", do_sui);
	magic->name = "随字诀";
	magic->mp = 300;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("lian", do_lian);
	magic->name = "连字诀";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("chan", do_chan);
	magic->name = "缠字诀";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[] = {
		{"$N虚步提腰，一招「蜻蜓点水」，手中$w轻轻颤动，一剑剑点向$n的$l", 60,20,10,45,0,},
		{"$N向前跨上一步，左手剑诀，右手$w使出一式「指南针」直刺$n的$l", 70,15,10,50,4,},
		{"$N身形往右一挫，左手剑诀，右手$w使出一式「大魁星」刺向$n的$l", 80,15,10,50,9,},
		{"$N双膝下沉，右手$w使出一式「探海式」，由下而上疾刺$n的$l", 90,15,10,50,14,},
		{"$N一招「燕子掠波」，$w自上而下划出一个大弧，平平地向$n的$l挥去", 100,15,15,60,19,},
		{"$N上身往左侧一拧，一招「乌龙摆尾」，右手$w反手向$n的$l挥去", 110,15,15,70,24},
		{"$N一招「右拦扫」，一招「左拦扫」，剑锋平指，一气呵成横扫$n的$l", 120,10,15,70,29},
		{"$N左腿提膝，手中$w斜指，一招「宿鸟投林」刺向$n的$l", 130,15,15,70,34,},
		{"$N一招「青龙出水」，$w自下而上划出一个大弧，平平地挥向$n的$l", 140,15,15,71,39,},
		{"$N使出「三环套月」，$w划出三个圆圈，剑锋直出，绵绵不断划向$n的$l",150,10,20,73,44},
		{"$N一招「风卷荷叶」，$w轻灵地划出几个圆弧，迅速地向$n的$l挥去", 160,15,20,75,49},
		{"$N一招「虎抱头」，$w划出一个左低右高的大弧，斜斜地斩向$n的$l", 170,15,20,77,54,},
		{"$N使出「狮子摇头」，$w由右向左划出一个大８字，将$n圈在其中", 180,15,20,79,59,},
		{"$N左脚踏实，右脚虚点，一招「仙人指路」，右手$w带着一团剑花，逼向$n的$l", 190,5,20,81,64},
		{"$N轻轻跃起，一招「野马跳涧」，$w在半空中化为一圈银芒，落向$n的$l", 200,15,20,83,69,},
		{"$N两腿前箭后弓，一招「射雁式」，右手$w直刺$n的$l",210,20,20,85,74,},
		{"$N一招「小魁星」，身形往左一挫，左手剑诀，右手$w平平地向$n的$l挥去", 220,40,20,87,79,},
		{"$N猱身扑上，一招「白猿献果」，手中$w斜斜地向$n的$l挥去", 230,30,20,89,84,},
		{"$N一招「迎风掸尘」，$w看似随意地一挥，$n却陡觉一股劲气迎面袭来。", 240,20,25,91,89,},
		{"$N一招「顺水推舟」，$w自上而下划出一个大弧，平平地向$n的$l挥去。", 250,45,25,93,94,},
		{"$N一招「流星赶月」，$w疾刺$n的$l", 260,35,25,95,99,},
		{"$N突然盘蹲下身来，一招「海底捞月」，$w自下而上地向$n的$l挥去", 270,25,25,97,104,},
		{"$N一招「挑帘式」，$w自下而上徐徐划出一个大弧，平平地向$n的$l挥去", 200,35,25,99,109,},
		{"$N一招「黄蜂入洞」，$w自上而下划出一个大弧，平平地向$n的$l挥去", 290,40,25,102,104,},
		{"$N一招「大鹏展翅」，身形跃起，右手$w刺向$n的$l", 300,45,25,106,119,},
		{"$N一招「车轮剑」，$w化作一片银盘，平平地向$n的$l卷去", 310,45,25,120,124,},
		{"$N左脚轻点地面，身形往前一扑，一招「天马行空」，$w向$n的$l挥去", 320,45,30,125,129,},
		{"$N一招「风扫梅花」，身体跃在半空，手中$w扫向$n的$l", 330,45,30,130,90,},
		{"$N一招「却步抽剑」，左脚跃步落地，$w回抽，反手勾向$n的$l", 340,35,30,140,139,},
		{"$N右腿半屈般蹲，一招「如封似闭」，剑尖虚指，转身撩向$n的$l", 350,25,30,150,144,},
		{"$N回身拧腰，右手虚抱，一招「拨云瞻日」，$w中宫直进，刺向$n的$l", 380,35,30,160,149,},
	};
	int level = me->query_skill("taiji_jian", 1);
	for(int i=31; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="sword" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");
	if (me->query_skill("taiji_shengong", 1) < 20)
		return notify_fail("你的太极神功火候太浅。");
	if (me->query_skill("taiji_quan", 1) < 20)
		return notify_fail("你的太极拳火候太浅。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("$HIR你拿的武器是剑吗？你确认你拿的真的是剑？难道你拿的真的是剑吗");
	
	if (me->query("hp") < 50)
		return notify_fail("$HIR虽然你很有决心地练太极剑，可是你的体力不够了。");
	me->receive_damage("hp", 30);
	return 1;
}

//perform 
static int do_sui(CChar * me, CContainer * ob)
{
	char msg[255];
	CContainer * weapon;

	if( ! me->is_fighting() )
		return notify_fail("「随」字诀只能在战斗中使用。");
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("我知道你很想用绝招，但你手里拿的也必须是剑啊！");
	
	if( me->query_skill("taiji_jian", 1) < 40 )
		return notify_fail("你的太极剑法不够娴熟，不会使用「随」字诀。");

	if(DIFFERSTR(me->querystr("family/family_name"), "武当派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query("mp") < 300  ) 
		return notify_fail("你的内力不够。");
	
	if( me->query_temp("tjj_sui") ) 
		return notify_fail("你已经在运功中了。");
	
	int skill = me->query_skill("taiji_jian");
	strncpy(msg, "$N使出太极剑法「随」字诀，剑圈逐渐缩小将周身护住。", 255);
	message_vision(msg, me);

	if(!me->query_temp("tjj_sui") && !me->query_temp("qzj_tong") && !me->query_temp("hsj_wu") && !me->query_temp("hmg_dzjm"))
	{
		me->add_temp("apply/attack", -skill/4);
		me->add_temp("apply/dodge", skill/3);
		me->set_temp("tjj_sui", 1);
		me->call_out(remove_effect, skill, -skill/4, skill/3);
	}
	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}

static void remove_effect(CContainer * ob, LONG amount1, LONG amount2)
{
	ob->add_temp("apply/attack", - amount1);
	ob->add_temp("apply/dodge", - amount2);
	ob->delete_temp("tjj_sui");
	tell_object(ob, "你的随字决运行完毕，将内力收回丹田。");
}

/*原来的设置
static void remove_effect(CContainer * ob, LONG param1, LONG param2)
{
	ob->delete_temp("tjj_jie");
	tell_object(ob, "$HIY$N的一口真气耗尽，「连字决」便再也使不下去。$COM");
}

*/
static int do_lian(CChar * me, CContainer * ob)
{
	char msg[255];
	CChar * target = NULL;
	string str;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	int extra;
	int i;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("「连」字诀只能对战斗中的对手使用。");

	if(DIFFERSTR(me->querystr("family/family_name"), "武当派") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("我知道你很想用绝招，但你手里拿的也必须是剑啊！。");

//	if( DIFFERSTR(me->query_skill_mapped("sword"), "taiji_jian") || EQUALSTR(me->query_skill_mapped("sword"), "liangyi_jian"))
	if( DIFFERSTR(me->query_skill_mapped("sword"), "taiji_jian") )
		return notify_fail("必须配合武当派的剑法使用。");	

	if( me->query_skill("taiji_jian", 1) < 40 )
		return notify_fail("你的太极剑法不够娴熟，不会使用「连」字诀。");

	if( me->query("mp") < 100)	//add by lanwood 2000-12-25
		return notify_fail("你的内力不足。");

	message_vision(snprintf(msg, 255, "$HIR$N运起「太极神功」，同时使出「太极剑中」的「连」字诀，手中的%s一招连着一招画起圈来，闪电般的击向$n！$COM", weapon->name()), me, target);

	if(target->query_temp("apply/no_连字诀") && !random(2))
	{
		return notify_fail(snprintf(msg, 255,"可是%s看破了%s的企图，抢先下手制住了%s的连续后招。\n",target->name(),me->name(),me->name()));
	}
	else
	{

		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK); 
		message_vision("$HIW剑光一闪，消失．．．．$COM\n", me, target);
	
		extra = me->query_skill("taiji_jian",1) / 20;
		extra += me->query_skill("taiji_shengong",1) /20;	

		if(	random(me->query("combat_exp")) > target->query("combat_exp") / 20 )
		{
			i = extra/4;
			me->call_out(lianji, 1, target->object_id(), 1);
			me->add("mp", - 60 * i);
			me->start_busy(3);
		}
		return 10;
	}
}


char * hit_ob(CChar *me, CChar *victim, LONG & damage)
{
	CContainer * wp1;
	string msg;
	int p,j,skill, mp, mp1;
	
	wp1 = victim->query_weapon();
	skill = me->query_skill("taiji_quan", 1);
	mp = me->query("mp");
	mp1 = victim->query("mp");
	if(me->query_temp("tjj_jie"))
	{
		if(wp1) 
		{
			msg = "\n$N双手连划，太极真气在$n的";
			msg += wp1->name();
			msg += "上一绕，";
		}
		else msg = "\n$N双手划弧，连连打出太极真气，";
		
		if(random(me->query("str"))< victim->query("str")/3)
		{
			msg +="$n看破了$N的借力打力，向你发动攻击！\n";
			damage=damage*2+100;
			me->receive_damage("hp",damage);
			p=me->query("hp")*100/me->query("max_hp");
			
			if(damage<100)
				msg +="结果$N硬受$n的一击，闷哼一声。\n";
			
			else if(damage<200)
				msg +="结果$N硬受$n内力反震，「嘿」地一声退了两步。\n";
			
			else if(damage<300)
				msg+="结果$N被$n以内力一震，胸口有如受到一记重锤，连退了五六步！\n";
			
			else msg+="结果$N被$n的内力一震，眼前一黑，身子像断了线的风筝向后飞出丈许！！\n";
			
			msg += "( $N";
			msg += g_Combatd.eff_status_msg(p);
			msg += " )";
		}
		else if(mp >= mp1 + damage)
		{
			msg += "$n的力道被太极拳借力打力反击回去！\n",		
				victim->receive_damage("hp", 100 + damage/2 + victim->query("jiali")*2);
			p = victim->query("hp")*100/victim->query("max_hp");
			msg += g_Combatd.damage_msg(damage/2, "震伤");
			msg += "( $n";
			msg += g_Combatd.eff_status_msg(p);
			msg += " )";
			j=-8000; 
		}
		else if(mp >= mp1/2+random(mp1/2)+random(damage))
		{
			msg += "$n的力道被太极拳借力打力卸在一旁！\n";
		}
		else if(mp > mp1/2+damage)
		{
			msg += "$n的力道被太极拳借力打力卸掉了一部分！\n"; 
			me->receive_damage("hp",damage/3+random(damage));		 
			p=me->query("hp")*100/me->query("max_hp");
			msg += g_Combatd.damage_msg(damage/2, "震伤");
			msg += "( $N";
			msg += g_Combatd.eff_status_msg(p);
			msg += " )";
		}
		else
		{
			msg += "$N的力道被太极拳借力打力卸掉了一小半！\n"; 
			me->receive_damage("hp",damage/3); 
			p=me->query("hp")*100/me->query("max_hp");
			msg += g_Combatd.damage_msg(damage/2, "震伤");
			msg += "( $N";
			msg += g_Combatd.eff_status_msg(p);
			msg += " )";
		}	    
		
		message_vision(msg.c_str(), me, victim);
	}
	
	return 0;
}

static void lianji(CContainer * ob, LONG param1, LONG time)
{
	CContainer * weapon;
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);
	int extra;
	string str;
	extra = me->query_skill("taiji_jian",1) / 20;
	extra += me->query_skill("taiji_shengong",1) /20;

	if(! target || ! me->is_fighting(target)) return;
	
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_REGULAR);
	
	if(time < extra / 4  &&  EQUALSTR(me->query_skill_mapped("sword"), "taiji_jian") 
		&& ((weapon = me->query_weapon())&& EQUALSTR(weapon->querystr("skill_type"), "sword")))
	{
		str = "$HIY$N用剑画了一个圈，一剑又连了上来！$COM\n";
		message_vision(str.c_str(), me, target);
		me->call_out(lianji, 1, param1, time + 1);
	}
	else
	{
		str = "可是$p看破了$P的企图，抢先下手制住了$P的连续后招。\n";
		message_vision(str.c_str(), me, target);
		me->start_busy(4);
	}
}

static int do_chan(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("师傅教我们，要和敌人面对面地打。");

	if(DIFFERSTR(me->querystr("family/family_name"), "武当派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("虽然我很想用绝招，但我手里拿的也必须是剑啊！。");

	if( target->is_busy() )
		return notify_fail("对方目前正自顾不暇，放胆攻击吧。");

	if( DIFFERSTR(me->query_skill_mapped("sword"), "taiji_jian") || EQUALSTR(me->query_skill_mapped("sword"), "liangyi_jian"))
		return notify_fail("必须配合武当派的剑法使用。");

	if( me->query_skill("taiji_jian", 1) < 40 )
		return notify_fail("你的太极剑法不够娴熟，不会使用「缠」字诀。");

	if( me->query("mp") < 20)
		return notify_fail("你的内力不足。");
	
	msg = "$N使出太极剑法「缠」字诀，连递数个虚招企图扰乱$n的攻势。\n";
		
	if( random(me->query("combat_exp")) > target->query("combat_exp")/4 )
	{
		if(DIFFERSTR(me->querystr("family/family_name"), "武当派") ||target->query("bigboss"))
		{
			if(EQUALSTR(target->query_skill_mapped("unarmed"), "xianglong_zhang") &&(EQUALSTR(target->querystr("family/family_name"), "丐帮") ||!userp(target))&& target->query("kill/guilt")<=150 )
			{
				msg+="$HIY$n眼疾手快，门户大开，一招「履霜冰至」向$N急劈过去，顿时$N方寸大乱。\n" ;
				me->start_busy(2);
			}
			else if(target->query("no_chan")||target->query_temp("no_chan")||target->query_temp("apply/no_缠字诀")&& !random(2))
			{
				msg += "可是$p看破了$P的企图，并没有上当。";
				me->start_busy(3);
			}
			else if(target->query_temp("apply/反_缠字诀")&& !random(3))
			{
				msg+="$HIY$n揉身而上，轻灵地跃过$N，闪到了$N的背后，顿时$N方寸大乱。" ;
				me->start_busy(me->query_skill("taiji_jian", 1) / 20 + 1);
			}
			else
			{
				msg += "结果$p被$P攻了个措手不及！";
				target->start_busy( me->query_skill("taiji_jian", 1) / 20 + 1);
			}
		}
		else
		{
			if(target->query_temp("apply/反_缠字诀")&& !random(3))
			{
				msg+="$HIY$n揉身而上，轻灵地跃过$N，闪到了$N的背后，顿时$N方寸大乱。" ;
				me->start_busy(me->query_skill("taiji_jian", 1) / 30 + 1);
			}
			else if(target->query_temp("apply/no_缠字诀")&& !random(4))
			{
				msg += "可是$p看破了$P的企图，并没有上当。";
				me->start_busy(2);
			}
			else
			{
			msg += "结果$p被$P攻了个措手不及！";
			target->start_busy( me->query_skill("taiji_jian", 1) / 20 + 1);
			}
		}
	}
	else
	{
		msg += "可是$p看破了$P的企图，并没有上当。";
		me->start_busy(2);
	}

	me->add("mp", -20);
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;




