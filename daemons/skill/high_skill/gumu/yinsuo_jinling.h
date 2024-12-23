// yinsuo_jinling.h 银索金铃
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSyinsuo_jinling);

virtual void create()
{
	set_name( "银索金铃");
	
	Magic_t * magic;
	
	magic = add_magic("dian", do_dian);
	magic->name = "点穴";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("feng", do_feng);
	magic->name = "封穴";
	magic->mp = 800;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "yunv_xinjing") || EQUALSTR(arg, "yunv_xinfa"))
		return 1;
	
	return notify_fail("银索金铃必须和古墓派内功相配合。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"劲贯$w,突然之间,丝带环绕,像一条银蛇扑向$n",45 , 40, 20, 0, "点穴",},
		{"$N手上的$w窜出，在$n手腕上迅速无比的一点，", 55, 30, 25, 10, "点穴",},
		{"蓦地里$N猱身而上，$w绕到$n的身后，疾点$n的$l", 70, 60, 35, 20, "点穴",},
		{"$N突然间招法一变，$w忽伸忽缩，招式诡奇绝伦。$n惊骇之中方寸大乱", 90, 40, 50, 30, "点穴",},
		{"$N身形飘忽，有如鬼魅，转了几转，忽然$w点向$n的$l穴道", 115, 40, 70, 60, "点穴",},
		{"$N一声冷笑，纵身后跃,手中$w犹如鬼魅般点向$n的$l", 145, 50, 95, 75, "点穴",},
		{"$N绕着$n转了几个圈,跟着$w反手送出,点向$n的$l", 180, 30, 125, 90, "点穴",},
		{"$n只觉眼前一花，似乎见到$N身形一幌，但$N却似从未离开,而$w已到了$n眼前", 190, 80, 110,100 , "点穴",},
		{"$N向后疾退，$n紧追两步，突然间手腕一抬，手中$w直点$n的$l", 200, 40, 100, 120, "点穴",},
		{"$n想要冲到$N面前，$N手中$w直点$n胸口檀中穴！$n慌忙招架，不想$N的$w突然转向点向$l", 215, 4, 145, 140, "点穴",},
		{"$N手中$w飞舞，$n眼前仿佛突然出现了七八条$w一齐点向$n", 220, 60, 195, 150, "点穴",},
	};
	int level = 0;
	
	for(int i=11; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("yinsuo_jinling", 1))
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
	return (usage == "whip") ;
}

virtual int valid_learn(CChar * me)
{
	CContainer * weapon;
	if( me->query("max_mp") < 500 )
		return notify_fail("你的内力不足，没有办法练银索金铃, 多练些内力再来吧。");
	
	if (me->query_skill("yunv_xinjing", 1) < 50)
		return notify_fail("你的玉女心经火候太浅。");
	
	if ( !(weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "whip") )
		return notify_fail("你必须招一条软兵器才能练银索金铃。");
	
	if (me->query_skill("tianluo_diwang",1)< 50)
		return notify_fail("你的天罗地网势还不够纯熟.不能练银索金铃.");
	
	return 1;
}

//lanwood 增加。原来练习连体力都不费 2001-06-30
int practice_skill(CChar * me)
{
	CContainer * weapon;
	
    if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "whip"))
        return notify_fail("你使用的武器不对。");
    if (me->query("hp") < 30)
        return notify_fail("你的体力不够练银索金铃。");
    me->receive_damage("hp", 25);
    return 1;
}

//perform 
static int do_dian(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("点穴只能对战斗中的对手使用。");
	
	if (!(weapon = me->query_weapon()) 
		|| DIFFERSTR(weapon->querystr("base_name"), "ring_whip"))
		return notify_fail("你手上没有金铃索，无法施展这一绝技。");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "古墓派") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query_skill("yinsuo_jinling", 1) < 120 )
		return notify_fail("你的银索金铃不够纯熟，还不能认穴");
	
	if( me->query_skill("tianluo_diwang",1)<100)
		return notify_fail("你的天罗地网势火候不足，手法还不够灵活");
	if( me->query_skill("yunv_xinjing",1)< 135)
		return notify_fail("你的内功修为太差，劲力无法封闭穴道");
	
	if( me->query("max_mp")<1000)
		return notify_fail("你的内力不足以施展点穴功夫.");
	
	if ( me->query("mp") < 300 )
		return notify_fail("你的内力不够点穴。");
	me->add("mp", - 500);
	
	msg = "$N手上金铃飞出,使出银索金铃的上乘点穴功夫,直取$p的大椎穴。\n";
	
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
		ob = target->query_weapon();
		if( random( me->query_skill("force") ) > random( target->query_skill("force") ) )
		{
			me->start_busy(3);
			if (! ob)
			{
				int damage = 0;
				
				if (target->query_skill("dodge") > 200 && random(2) == 0)
				{
					switch (random(2))
					{
					case 0:
						msg +="$p连续变了几种上乘身法，终于没能躲过，$N的金铃正点在$p的檀中穴上，$p只觉得一口凉气，自丹田而上，心里有种说不出的难受。";
						damage = 3;
						break;
					case 1:
						msg+="$p轻身飘开，身法灵动之极，众人正要喝彩，听「噗」的一声，如击败革，$p脸色煞白，摇摇欲坠。";
						damage = 5;
						break;
					}
				} 
				else
					if (target->query_skill("force") > 200 && random(2) == 0)
					{
						switch(random(2))
						{
						case 0:
							msg +="$p冷哼一声，自持内力高强，反手出招，「啵」的一声轻响，掌铃相交，$p身行微晃，脸如金纸。";
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
							msg +="$p看到这招，竟然不知躲避，「嗤」的一声，$N的金铃正点在$p的大椎穴上,$p全身酸软,跌倒在地。";
							//						target->unconcious();
							damage = 5;
							break;
						case 1:
							msg += "$p一转念，已经想出了九十九种化解的办法，尚未来得及施展，只听「嗤」的一声，已被$N点中大椎穴,$p全身酸软,跌倒在地。";
							//						target->unconcious();
							damage = 6;
							break;
						}
					}
					if (damage > 0)
						target->receive_damage("hp", target->query("max_hp") * damage / 24);
					
					message_vision(msg.c_str(), me, target);
					return 1;
			}
			/*		
			if (ob->query("item_make"))
			{
			msg += "$p忙用";
			msg += ob->name();
			msg += "招架，只觉得虎口剧震，所幸兵器完好无损。";
			} 
			else
			{
			msg += "$p连忙招架，只听见「啪」地一声，$p手中的";
			msg += ob->name();
			msg += "寸寸断裂，散落一地！";
			ob->move(target->environment());
			string new_name;
			new_name = "断掉的";
			new_name += ob->name();
			ob->set_name( new_name.c_str());
			ob->set("value", 0l);
			ob->del("apply");
			}
			target->start_busy(2);
			*/
		} 
		else
		{
			int busy = 0;
			if (target->query_skill("dodge") > 200 && random(2) == 0)
			{
				switch (random(2))
				{
				case 0:
					msg += "$p一声轻笑，连续变化了几次身法，扰人耳目，一时让$N无法进攻。";
					busy = 2;
					break;
				case 1:
					msg += "$p突然向后飘去，疾若闪电，令$N所有的后继变化无从施展。";
					busy = 1;
					break;
				}
			} 
			else
				if (target->query_skill("force") > 200 && random(2) == 0)
				{
					switch (random(2))
					{
					case 0:
						msg += "$p脸色凝重，加快格架，以巧对巧，让$N无从下手，只能收回金铃。";
						busy = 3;
						break;
					case 1:
						msg += "$p满脸不屑，冷笑一声，双掌齐出，其快无比，令$N只能回招自救。";
						busy = 1;
						break;
					}
				}
				else
				{
					switch (random(3))
					{
					case 0:
						msg += "$p左摇右晃，看上去毫无章法，偏偏躲过了$N这一击。";
						busy = 2;
						break;
					case 1:
						msg += "$p身影流动，看上去灵动精妙，$N一呆，攻势顿缓。";
						busy = 2;
						break;
					case 2:
						msg += "$p摄住心神，真气贯注堪堪封住了$N的进攻。";
						busy = 2;
						break;
					}
				}
				target->start_busy(busy);
				me->start_busy(4);
		}
	}
	message_vision(msg.c_str() , me, target);
	
	return 1;
	
}

static int do_feng(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("封穴只能对战斗中的对手使用。");
	
	if (!(weapon = me->query_weapon()) 
		|| DIFFERSTR(weapon->querystr("skill_type"), "whip"))
		return notify_fail("你使用的武器不对。");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "古墓派") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if(me->query_skill("yunv_xinjing",1) < 100)
		return notify_fail("你玉女心经的功力不够不能封住敌人穴道!");
	
	if(me->query_skill("yinsuo_jinling",1) < 150)
		return notify_fail("你的银索金铃修为不够,目前还不能封住敌人穴道!");
	
	if(me->query_skill("tianluo_diwang")< 100)
		return notify_fail("你的天罗地网势还不够纯熟，连穴道都认不准！");
	
	if(me->query("mp") < 800)
		return notify_fail("你内力现在不够, 不能封穴! ");
	
	if( target->is_busy() )
		return notify_fail( "%s的穴道已经被你封住了，你还怕什么",target->name());
	
	msg = "$N使出银索金铃的上乘封穴功夫，手中";
	msg += weapon->name();
	msg += "罩住了$n的全身要穴, 使$n动弹不得。\n";
	
	if( random(me->query("combat_exp")) > target->query("combat_exp")/2 )
	{
		msg += "结果$p的檀中大穴被点，不能动弹！";
		target->start_busy( me->query_skill("yinsuo_jinling",1) / 20 - 2);
		me->add("mp", -150);
	} 
	else 
	{
		msg += "可是$p几经艰难终于躲过了$P的攻击。";
		me->start_busy(4);
	}
	
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;
