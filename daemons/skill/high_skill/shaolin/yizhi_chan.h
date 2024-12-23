SKILL_BEGIN(CSyizhi_chan);

virtual void create()
{
	set_name( "一指禅");

	Magic_t * magic;

	magic = add_magic("dian", do_dian);
	magic->name = "点字决";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("jingmo", do_jingmo);
	magic->name = "惊魔一指";
	magic->mp = 800;
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
	}action[4] = {
		{"$N双指并拢，一式「佛恩济世」，和身而上，左右手一前一后戳向$n的胸腹间",
			60, -5, -5, 10, 0,},
		{"$N左掌护胸，一式「佛光普照」，右手中指前后划了个半弧，猛地一甩，疾点$n的$l",
		120, 10, 15, 30, 20,},
		{"$N身形闪动，一式「佛门广渡」，双手食指端部各射出一道青气，射向$n的全身要穴",
		240, 20, 20, 60, 40,},
		{"$N盘膝跌坐，一式「佛法无边」，左手握拳托肘，右手拇指直立，遥遥对着$n一捺",
		480, 40, 30, 90, 60,},
	};

	int level = me->query_skill("yizhi_chan", 1);
	for(int i = 4; i > 0; i--)
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
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练一指禅。");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练一指禅必须空手。");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学一指禅。");
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练一指禅。");
	return 1;
}

virtual int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
virtual int valid_combine(string combo) {return combo=="banruo_zhang"; }

static int do_dian(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
//	char str[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target	||	!me->is_fighting(target) )
		return notify_fail("绝技「点」字决指法只能对战斗中的对手使用。");

	if (me->query_weapon())
			return notify_fail("你不能使用武器！");

	if( me->query_skill("yizhi_chan", 1) < 150 )
		return notify_fail("你的一指禅太生疏，不会使用「点」字决。");

	if(DIFFERSTR(me->querystr("family/family_name"), "少林派") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if ( me->query("mp") < 500)
		return notify_fail("你的内力不够，现在无法使用「点」字决。");

	
	me->add("mp", -100);

	msg = "$HIY$N深深吸了一口气，伸出中指，使出佛门伏魔无上绝技指法，慢慢得向$p点了过了。\n";
	
	if(target->query_temp("apply/no_点字决")&& (random(2)||target->query("bigboss")))
	{
		switch(random(9))
		{
		case 0:
			msg +="$p冷哼一声，自持内力高强，反手出招，「啵」的一声轻响，掌指相交，$p身行微晃，脸如金纸。";
			break;
		case 1:
			msg +="$p一声长啸，双手幻化出无数掌影，护住身前。只听「嗤」的一声，掌影顿消，$p已经变得脸色惨白。";
			break;
		case 2:
			msg += "$p一声轻笑，连续变化了几次身法，扰人耳目，一时让$N无法进攻。\n";
			break;
		case 3:
			msg += "$p突然向后飘去，疾若闪电，令$N这一指所有的后继变化无从施展。\n";
			break;
		case 4:
			msg += "$p脸色凝重，缓缓出掌，以拙对拙，竟然让$N无从下手，只得收指。\n";
			break;
		case 5:
			msg += "$p满脸不屑，冷笑一声，双掌齐出，其快无比，令$N只能回招自救。\n";
			break;
		case 6:
			msg += "$p左摇右晃，看上去毫无章法，偏偏躲过了$N这一击。\n";
			break;
		case 7:
			msg += "$p一指点出，看上去恍若也是佛门精妙指法，$N一呆，攻势顿缓。\n";
			break;
		case 8:
			msg += "$p摄住心神，真气贯注，堪堪封住了$N的进攻。\n";
			break;
		}
		me->start_busy(4);
	}
	else
	{
		CContainer * weapon = target->query_weapon();
		if( random( me->query_skill("force") ) > random( target->query_skill("force") ) )
		{
			me->start_busy(3);
			if (! weapon)	//对手无武器
			{
				int damage = 0;
				
				if (target->query_skill("dodge") > 200 && random(2) == 0)
				{
					switch (random(2))
					{
					case 0:
						msg +="$p连续变了几种上乘身法，终于没能躲过，$N的手指正点在$p的檀中穴上，$p只觉得一口凉气，自丹田而上，心里有种说不出的难受。";
						damage = 3;
						break;
					case 1:
						msg+="$p轻身飘开，身法灵动之极，众人正要喝彩，听「噗」的一声，如击败革，$p脸色煞白，摇摇欲坠。";
						damage = 5;
						break;
					}
				} 
				else if (target->query_skill("force") > 200 && random(2) == 0)
				{
					switch(random(2))
					{
					case 0:
						msg +="$p冷哼一声，自持内力高强，反手出招，「啵」的一声轻响，掌指相交，$p身行微晃，脸如金纸。";
						damage = 3;
						break;
					case 1:
						msg +="$p一声长啸，双手幻化出无数掌影，护住身前。只听「嗤」的一声，掌影顿消，$p已经变得脸色惨白。";
						damage = 4;
						break;
					}
				} 
				else
				{
					switch(random(2))
					{
					case 0:
						msg +="$p看到这招，竟然不知躲避，「嗤」的一声，$N的手指正点在$p的大椎穴上,$p全身酸软,跌倒在地。";
						//						target->unconcious();
						damage = 6;
						break;
					case 1:
						msg += "$p一转念，已经想出了九十九种化解的办法，尚未来得及施展，只听「嗤」的一声，已被$N点中大椎穴,$p全身酸软,跌倒在地。";
						//						target->unconcious();
						damage = 8;
						break;
					}
				}
				if (damage > 0)
				{
					int damage_hp=target->query("max_hp") * damage / 15;
					if(damage_hp>=target->query("hp"))
						damage_hp=target->query("hp")-50;
					target->receive_damage("hp", damage_hp);
				}
				
				message_vision(msg.c_str(), me, target);
				return 1;
			}
			else
			{
				if(weapon->query("no_duo") && !random(3) )
					msg += "可是$n看破了$N的企图，并没有上当。\n";
				else
				{
					msg += "$p连忙招架，只听见「啪」地一声，$p手中的";
					msg += weapon->name();
					
					if(weapon->query("no_duo") )
					{
						msg += "脱手而出！\n";
						char msg1[40];
						target->command(snprintf(msg1, 40, "unwield %ld", weapon->object_id()));
					}
					else
					{
						msg += "寸寸断裂，散落一地！";
						weapon->move(target->environment());
						char new_name[40]; 
						weapon->set_name(snprintf(new_name, 40, "断掉的%s", weapon->name(1)) );
						weapon->set("value", 0l);
						weapon->del("apply");
						target->start_busy(2);
					}	
				}
			}
		} 
		else
		{
			int busy = 0;
			if (target->query_skill("dodge") > 200 && random(2) == 0)
			{
				switch (random(2))
				{
				case 0:
					msg += "$p一声轻笑，连续变化了几次身法，扰人耳目，一时让$N无法进攻。\n";
					busy = 2;
					break;
				case 1:
					msg += "$p突然向后飘去，疾若闪电，令$N这一指所有的后继变化无从施展。\n";
					busy = 1;
					break;
				}
			} 
			else if (target->query_skill("force") > 200 && random(2) == 0)
			{
				switch (random(2))
				{
				case 0:
					msg += "$p脸色凝重，缓缓出掌，以拙对拙，竟然让$N无从下手，只得收指。\n";
					busy = 3;
					break;
				case 1:
					msg += "$p满脸不屑，冷笑一声，双掌齐出，其快无比，令$N只能回招自救。\n";
					busy = 1;
					break;
				}
			} 
			else
			{
				switch (random(3))
				{
				case 0:
					msg += "$p左摇右晃，看上去毫无章法，偏偏躲过了$N这一击。\n";
					busy = 2;
					break;
				case 1:
					msg += "$p一指点出，看上去恍若也是佛门精妙指法，$N一呆，攻势顿缓。\n";
					busy = 2;
					break;
				case 2:
					msg += "$p摄住心神，真气贯注，堪堪封住了$N的进攻。\n";
					busy = 2;
					break;
				}
			}
			target->start_busy(busy);
			me->start_busy(4);
		}
	}
	message_vision(msg.c_str(), me, target);

	return 1;
}

static int do_jingmo(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||	!me->is_fighting(target) )
		return notify_fail("牵制攻击只能对战斗中的对手使用。");

	if(me->query_str() < 30)
		return notify_fail("你臂力不够,不能使用这一绝技!");

	if(DIFFERSTR(me->querystr("family/family_name"), "少林派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if(me->query_skill("hunyuan_yiqi",1) < 100)
		return notify_fail("你混元一气功的功力不够不能使用惊魔一指!");

    if(me->query_skill("finger") < 150)
		return notify_fail("你的指法修为不够,目前还不能使用惊魔一指绝技!");

	if(me->query("mp") < 800)
		return notify_fail("你内力现在不够, 不能使用惊魔一指! ");

	if( target->is_busy() )
		return notify_fail("%s目前正自顾不暇，放胆攻击吧！", target->name());

    msg = "$HIY$N使出拈花指绝技「惊魔一指」，罩住了$n的全身要穴, 使$n动弹不得。\n";

	if( random(me->query_combat_exp()) > target->query_combat_exp() / 2 ) 
	{
		msg += "结果$p被$P攻了个措手不及！\n$COM";
		target->start_busy( me->query_skill("yizhi_chan",1) / 20 + 2);
		me->add("mp", -150);
	} else 
	{
		msg += "$HIG可是$p看破了$P的企图，并没有上当。$COM";
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);

	return 1;
}

SKILL_END;



