// pixie_jian.h 辟邪剑法
//code by oho
//date : 2000-12-06

SKILL_BEGIN(CSpixie_jian);

virtual void create()
{
	set_name( "辟邪剑法");
	set("valid_force", "kuihua_xinfa");
	
	Magic_t * magic;

	magic = add_magic("cimu", do_cimu);
	magic->name = "刺目";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("touzi", do_touzi);
	magic->name = "拼命";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][255] = {
		{"突然之间，白影急幌，$n向后滑出丈余，立时又回到了原地，躲过了$N这一招。"},
		{"$n手臂回转，在$N手肘下一推，顺势闪到一旁。"},
		{"$n右手伸出，在$N手腕上迅速无比的一按，顺势跳到一旁。"},
		{"$n身形飘忽，有如鬼魅，转了几转，移步到$N的身后，躲过了$N这一招。"},
		{"$N只觉眼前一花，似乎见到$n身形一幌，但随即又见$n回到原地，却似从未离开。"},
		{"$N眼睛一花，$n已没了踪影。突然$n从身后拍了一下$N的头，轻轻跃开。"},
		{"$n嫣然一笑，诡异之极，$N竟不知如何是好，停住了攻击。"},
	};
	return dodge_msg[random(7)];
}

virtual const char * query_parry_msg(CContainer * weapon)
{
	static char parry_msg[][255] = {
                {"$n左一拨，右一拨，上一拨，下一拨，将$N的招数尽数拨开。这四下拨挡，周身竟无半分破绽。"},
		{"$n不挡不闪，左手食指颤动，向$N的左目急刺，竟是两败俱伤的打法。"},
		{"$n右手伸出，在$N手腕上迅速无比的一按，顺势跳到一旁。"},
		{"$n右手大拇指和食指捏住一根绣花针，向上一举，挡住来势，$N的招式便使不下去。"},
		{"$N只觉眼前一花，似乎见到$n身形一幌，但随即又见$n回到原地，却似从未离开。"},
		{"$n左拨右挡，兀自好整以暇的啧啧对$N连赞：“好功夫，好功夫！"},
		{"$n从怀中取出一块雪白的绸帕，轻轻抹了抹脸，简直便如是戏台上的花旦。$N一呆，竟停住了自己的招式。"},
	};
	return parry_msg[random(7)];
}


virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"突然之间，白影急幌，$N向后滑出丈余，立时又回到了原地", 80, -40, 40, 0, "刺伤",},
		{"$N右手伸出，在$n手腕上迅速无比的一按，$n险些击中自己小腹", 90, -40, 50,0 , "刺伤",},
		{"蓦地里$N猱身而上，蹿到$n的身后，又跃回原地", 80, -40, 70, 25, "刺伤",},
		{"$N突然间招法一变，$w忽伸忽缩，招式诡奇绝伦。$n惊骇之中方寸大乱", 80, -40, 50, 5, "刺伤",},
		{"$N身形飘忽，有如鬼魅，转了几转，移步到$n的左侧", 90, -60, 90, 10, "刺伤",},
		{"$N一声冷笑，蓦地里疾冲上前，一瞬之间，与$n相距已不到一尺，$w随即递出", 140, -60, 100, 10, "刺伤",},
		{"$N喝道：“好！”，便即拔出$w，反手刺出，跟着转身离去", 80, -60, 50, 0, "刺伤",},
		{"$n只觉眼前一花，似乎见到$N身形一幌，但随即又见$N回到原地，却似从未离开", 140, -60, 100, 20, "刺伤",},
		{"$N向后疾退，$n紧追两步，突然间$N闪到$n面前，手中$w直指$n的$l", 60, -70, 40, 5, "刺伤",},
		{"$N蓦地冲到$n面前，手中$w直刺$n右眼！$n慌忙招架，不想$N的$w突然转向", 200, -70, 100, 45, "刺伤",},
		{"$N飞身跃起，$n抬眼一望，但见得$N从天直落而下，手中$w刺向$n的$l", 340, -70, 105, 64, "刺伤",},
		{"$N腰枝猛摆，$n眼前仿佛突然出现了七八个$N，七八只$w一起刺向$n",380 , -70, 130, 79, "刺伤",},
	};
	
	int level = 0;
	
	for(int i=12; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("pixie_jian", 1))
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
    return usage == "sword" || usage == "dodge" || usage == "parry"; 
}

virtual int valid_learn(CChar * me)
{
	return notify_fail("辟邪剑法只能通过研习《葵花宝典》来学习。");
}

//perform 
static int do_cimu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || !me->is_fighting(target))		//add by Lanwood 2000-12-26
		return notify_fail("只能对战斗中的敌人使用。");

	if( me->query_dex() < 25)
		return notify_fail("你身手不够快,不能使用这一绝技!");
	
	if( me->query_skill("kuihua_xinfa",1) < 80)
		return notify_fail("你葵花心法的功力不够不能使用刺目!");

	if(DIFFERSTR(me->querystr("family/family_name"), "日月神教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query_skill("pixie_jian", 1) < 80)
		return notify_fail("你的辟邪剑修为不够,目前还不能使用刺目绝技!");
	
	if( me->query("mp") < 300)
		return notify_fail("你内力现在不够, 不能使用刺目! ");
	
	if( target->is_busy() )
		return notify_fail("%s目前正自顾不暇，还不杀他，欲待何时？ ",target->name() );
	
	msg =   "$N身形一晃，身形猛然突进！然后退回原地。\n";
	
	if( random(me->query_combat_exp()) >  target->query_combat_exp() / 4 )
	{
		msg +=    "只见$p大声惨呼，眼中两道细细的血线流了下来 "  ;
		target->start_busy(me->query_temp("apply/pro_刺目")+ me->query_skill("pixie_jian",1) / 20 + 2);
		me->add("mp", -100);
		if(random(4))
		{
			me->improve_skill("pixie_jian", 1);
		}
	}
	else
	{
		msg +=   "可是$p看破了$P的企图，轻轻一跃，跳了开去。"  ;
		me->start_busy(4);
		me->add("mp", -50);		// add by lanwood 2000-12-26
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

static int do_touzi(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	CContainer * weapon;
	string msg;

	if( !target || !me->is_fighting(target) )
		return notify_fail("拼命只能对战斗中的对手使用。");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("装备剑才能使用拼命。");
		
	if( me->query_skill("pixie_jian", 1) < 100 )
		return notify_fail("你辟邪剑法不够娴熟，使不出拼命。");

	if(DIFFERSTR(me->querystr("family/family_name"), "日月神教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	                        
	if( me->query_skill("kuihua_xinfa", 1) < 100 )
		return notify_fail("你葵花心法火候不够，使不出拼命。");
			
	if( me->query("max_mp") < 600 )
		return notify_fail("你内力修为不足，无法运足内力。");

	if (me->query("mp") < 400)
        return notify_fail("你现在内力不够，没能发出绝招！");

	if(weapon->query("index"))
	{
		if(weapon->query("攻击")>0)
			me->add_temp("apply/damage", -weapon->query("攻击"));
		if(me->query_temp("apply/damage")<0)
			me->set_temp("apply/damage",0l);
	}
			
	msg = "$HIR$N眼中满是怨毒，突然间手指一弹，手中兵器向$n飞射过去！\n";
	if(target->query_temp("apply/no_拼命")&& (random(2)||target->query("bigboss")))
	{
		msg += "可是$n轻轻一笑，侧身躲过。";
		me->start_busy(4);
	}
	else
	{
		
		if ( random(me->query_combat_exp()) > target->query_combat_exp()/3 )
		{
			me->start_busy(2);
			target->start_busy(random(3));
			int damage = target->query("hp");
			target->receive_damage("hp", damage - 10);
			target->receive_wound("hp", damage/2);
			msg += "$HIR$n疾忙躲闪，但已经来不及了，只觉一阵剧痛，鲜血飞溅，也不知伤在了那里！";
			me->set("mp", 100);
		} 
		else
		{
			me->start_busy(2);
			msg += "可是$n轻轻一笑，侧身躲过。";
		}
	}
	
	weapon->move(me->environment());
	message_vision(msg.c_str(), me, target);
    
	return 1;
}

SKILL_END;




