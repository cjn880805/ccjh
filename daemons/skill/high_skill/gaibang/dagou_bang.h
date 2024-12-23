
// dagou_bang.h 打狗棒
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSdagou_bang);

virtual void create()
{
	set_name( "打狗棒");
	set("valid_force", "huntian_qigong");
	
	set("diff",150);
	
	Magic_t * magic;
	
	magic = add_magic("zhuang", do_zhuang);
	magic->name = "千环套狗";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("linglong", do_linglong);
	magic->name = "玲珑棒诀";
	magic->mp = 800;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N使出一招「棒打双犬」，手中$w化作两道青光砸向$n的$l", 50, -20,30 ,1 , "挫伤",},
		{"$N手中$w左右晃动，一招「拨草寻蛇」向$n的$l攻去", 100, -30, 55, 33, "挫伤",},
		{"$N举起$w，居高临下使一招「打草惊蛇」敲向$n的$l", 180, -40, 80, 66, "挫伤",},
		{"$N施出「拨狗朝天」，$w由下往上向$n撩去", 250, -30, 100, 100, "挫伤",},
		{"$HIY$N眼中射出一道青芒，手中玉竹杖使出「天下无狗」，劈天盖地般攻向$n$COM", 300, -40, 500, 0, "挫伤",},
	};
	
	int level = 0;
	
	if (random(me->query_skill("staff")) > 100 &&
		me->query_skill("force") > 60 &&
		me->query("mp") > 100 &&
		EQUALSTR((me->query_weapon())->querystr("base_name"), "yuzhu_zhang") ) 
	{
		me->add("mp", -100);
		level = 4;
	}
	else
		level = random(4);
	
	m_actions.set("action", action[level].action);
	m_actions.set("force", (me->query("skill_pro/丐帮/打狗棒/force")+100) * action[level].force/100);
	m_actions.set("dodge", (me->query("skill_pro/丐帮/打狗棒/dodge")+100) * action[level].dodge/100);
	m_actions.set("damage", (me->query("skill_pro/丐帮/打狗棒/damage")+100) * action[level].damage/100);
	
	if (me->query_temp("teapot/dagou"))
	{
		int lv = me->query_skill("begging", 1)/2;
		if(lv>200)lv=200+(lv-200)/2;
		int damage1;
		m_actions.set("action", "$HIR$N手中$w化作一个圈圈，套向$n$COM");
		m_actions.set("force",  100);
		int dodge=int(me->query("level")/3)+10;
		m_actions.set("dodge",  -dodge);
		if(me->query_temp("dagou/target")==1)
		{
			damage1=500 * (100 + lv) / 200;
			if(me->query("kill/guilt")>=100)
			{
				damage1 = damage1 - me->query("kill/guilt")*10;
				if(damage1<0) damage1=50;
			}
			if(me->query("kill/guilt")< me->query_temp("dagou/target_kill") && me->query_temp("dagou/target_kill")>100)
				damage1 = damage1 +me->query_temp("dagou/target_kill")*5;
			m_actions.set("damage", damage1 );
		}
		else
			m_actions.set("damage",  500 * (100 + lv) / 125 );
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "staff") || (usage == "parry");
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/丐帮/打狗棒/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/丐帮/打狗棒/force"));
			if(me->query("skill_pro/丐帮/打狗棒/force_point")>=level_point)
			{
				me->add("skill_pro/丐帮/打狗棒/force",1);
				me->set("skill_pro/丐帮/打狗棒/force_point",1);
				tell_object(me,"\n$HIR你的打狗棒配合内功更能融汇贯通了。\n");
			}
		}
		else if(victim->query("parry")) 
		{
			me->add("skill_pro/丐帮/打狗棒/parry_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/丐帮/打狗棒/parry"));
			if(me->query("skill_pro/丐帮/打狗棒/parry_point")>=level_point)
			{
				me->add("skill_pro/丐帮/打狗棒/parry",1);
				me->set("skill_pro/丐帮/打狗棒/parry_point",1);
				tell_object(me,"\n$HIR你熟练的使用打狗棒，防守能力进一步加强了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/丐帮/打狗棒/damage_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/丐帮/打狗棒/damage"));
			if(me->query("skill_pro/丐帮/打狗棒/damage_point")>=level_point)
			{
				me->add("skill_pro/丐帮/打狗棒/damage",1);
				me->set("skill_pro/丐帮/打狗棒/damage_point",1);
				tell_object(me,"\n$HIR你的打狗棒威力更大了。\n");
			}
		}
	}
	char msg[255];
	CContainer * weapon;
	CContainer * weapon1;
	static char xue_name[5][20]={"强间穴","风府穴","大雅穴","灵台穴","悬枢穴"};
	
	weapon = me->query_weapon();
	weapon1 = victim->query_weapon();
	int i = me->query_skill("huntian_qigong", 1);
	int j = me->query_skill("dagou_bang", 1);
	int damage1;
	int damage2=damage;
	if( damage < 800 ) return "";
	
	if((random(100)>70 &&
		EQUALSTR(me->querystr("family/family_name"), "丐帮") &&
		!victim->is_busy() && i > 100 &&
		victim->query("mp") && j > 100 &&
		EQUALSTR(me->query_skill_mapped("parry") , "dagou_bang") &&
		me->query("mp") > 400 && me->query("max_mp") > 1200 )||wizardp(me))
	{
		if (random(40)>13)
		{
			switch(random(4))
			{
			case 0 :
				message_vision(snprintf(msg, 255,
					"\n$GRN$N%s挥出，以“绊”字诀着地扫去，一绊不中，二绊续至，连环钩盘，绵绵而不绝。",weapon->name()),me, victim);
				victim->start_busy(3);
				if (!random(2))
				{
					message_vision(snprintf(msg, 255,
						"$HIR$n纵身稍慢，被%s在左胫上一拨，右踝上一钩，扑地倒了。\n",weapon->name()),me, victim); 
					damage1 = damage2*j/10;
					victim->receive_wound("hp",damage1);
				}
				break;
			case 1 :
				message_vision(snprintf(msg, 255,
					"\n$GRN$N使出“劈”字诀，挥舞起手中%s如狂风暴雨般的打去！\n",weapon->name()),me, victim);
				damage1 = damage2/10 + random(damage2)/5*j/20;
				victim->receive_damage("hp",damage1/5);
				victim->receive_wound("hp", damage1/5);
				me->add("mp", -50);
				break;
			case 2 :
				message_vision(snprintf(msg, 255,
					"\n$GRN$N使出“戳”字诀，手中%s直上直下，点东打西，招招向$n的要害戳去！\n",weapon->name()),me, victim);
				damage1 = damage/5*j/20 + random(damage)/10;
				victim->receive_wound("hp", damage1/2);
				me->add("mp", -damage/5);
				break;
			case 3 :
				message_vision(snprintf(msg, 255,
					"\n$GRN$N棒法再变，使出了“转”字诀。但见%s化成了一团碧影，猛点$n后心各大要穴。\n",weapon->name()),me, victim);
				if(!random(2))
				{
					victim->start_busy(5);
					me->add("mp",-40);
					victim->receive_wound("hp", me->query_skill("dagou_bang",1)/10+damage/5*j/20);       
					message_vision(snprintf(msg, 255,
						"$HIR$n被%s点中$RED%s$HIR，受了点伤！" ,weapon->name(),xue_name[random(5)]),me, victim);
					message_vision(snprintf(msg, 255,
						"$HIR$n尚未落地，被%s又是一挑一打，$n立足不住，仰天一交摔倒。\n",weapon->name()),me, victim);   
				}                 
				break;
			}
		} 
		else if (weapon1 && random(35)<7) 
		{
			switch(random(2))
			{
			case 0 :
				if (random(2))
				{ 
					message_vision(snprintf(msg, 255,
						"\n$GRN$N%s疾翻，搭在%s尺许之处，运起“引”字诀，顺势向外牵引! \n",weapon->name(),weapon1->name()),me, victim);
				} 
				else 
				{
					message_vision(snprintf(msg, 255,
						"\nGRN$N%s缩回，使起“挑”字诀，搭住%s向上甩出，将$n疾奔的力道传到%s上! \n",weapon->name(),weapon1->name(),weapon1->name()),me, victim);
				}
				victim->start_busy(j/20);
				if (!random(3))
				{
					message_vision(snprintf(msg, 255,
						"$HIR$n只感%s似欲脱手飞出，一个把握不住，手中兵器被对方夺了过去。\n",weapon1->name()),me, victim);            
					
					if(weapon1->query("no_duo") || weapon1->querystr("owner")[0])
					{
						char msg1[40];
						victim->command(snprintf(msg1, 40, "unwield %ld", weapon1->object_id()));
					}
					else
					{
						weapon1->move(victim->environment());
					}
				}
				else 
					victim->start_busy(3); 
				break;
			case 1 :
				message_vision(snprintf(msg, 255,
					"\n$GRN$N使个“缠”字诀,%s挥到东，%s跟向东%s打到西，%s随到西，如影随形，借力制敌。\n"
					,weapon1->name(),weapon->name(),weapon1->name(),weapon->name()),me, victim);
				damage1 = damage/10 + random(damage)/5*j/20;
				if (victim->query("mp")<=damage) 
				{ 
					victim->set("mp",0l); 
				}
				else 
				{
					victim->add("mp", -damage1); 
				}
				victim->start_busy(3);  
				me->add("mp", -damage1/3); 
				if(me->query("mp")<0)
					me->set("mp",0l);
				break;
			}
		}
	}
	
	return "";
}

virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("你的师傅暂时没空指点你武功。。");
	
	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("你暂时无法指点你伴侣的武功。。");
	
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练打狗棒法。");
	me->receive_damage("hp", 40);
	return 1;
}

static int do_zhuang(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	char msg[255];
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target || !me->is_fighting(target) )
		return notify_fail("千环套狗无法使用。");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("千环套狗无法使用。");
	
	if( me->query("mp") < 400 )
		return notify_fail("你的真气不够！");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "丐帮") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if ( random(me->query_combat_exp()) > target->query_combat_exp()/4 )
	{
		me->set("mp_factor",0l);
		me->set_temp("teapot/dagou",1);
		me->set_temp("dagou/target_kill",target->query("kill/guilt"));
		me->set_temp("dagou/target_hp",target->query("hp"));
		if(target->query("kill/guilt")>100 && userp(target))
		{
			me->set_temp("dagou/target",1);
			snprintf(msg ,255,"$YEL$N凛然大喝道：$n这个恶贼，我今天要替天行道！\n$YEL$N大喝一声：看我的千环套狗！\n"  );
		}
		else
			snprintf(msg ,255,"$YEL$N大喝一声：看我的千环套狗！\n"  );
		message_vision(msg, me,target);
		if(target->query_temp("apply/no_千环套狗")&& (random(2)||target->query("bigboss")))
			message_vision("$YEL可是$n侧身避让，不慌不忙，躲过了$N的雷霆一击。", me,target);
		else
			g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);
		me->delete_temp("dagou/target_kill");
		me->delete_temp("dagou/target_hp");
		me->delete_temp("teapot/dagou");
		me->set_temp("dagou/target",2);
		
		//	target->add("level",-n);
		//	target->add("combat_exp",-i);
		me->add("mp", -500);
		me->start_busy(random(3));	
	}
	else
	{
		me->start_busy(2);
		message_vision("$YEL$N大喝一声：看我的千环套狗！\n\n可是$n侧身避让，不慌不忙，躲过了$N的雷霆一击。", me,target);
		me->add("mp", -200);
	}
	return 1;
}

static int do_linglong(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	
	int ap,dp,damage;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target || !me->is_fighting(target) )
		return notify_fail("「玲珑棒诀」只能在战斗中使用。\n");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("你手里无棒，如何使用「玲珑棒诀」？\n");
	
	if(me->query_int() < 25)
		return notify_fail("你悟性不够,不能使用「玲珑棒诀」！\n");
	
	if(me->query_skill("huntian_qigong", 1) < 150 )
		return notify_fail("你的混天气功修为不够，使不出「玲珑棒诀」绝技。\n");
	
	if(DIFFERSTR(me->query_skill_mapped("force") , "huntian_qigong"))
		return notify_fail("没有混天气功作为根基，是无法使出「玲珑棒诀」绝技的！\n"); 
	
	if(me->query_skill("dagou_bang",1) < 180)
		return notify_fail("你的打狗棒法修为不够,目前还不能使用「玲珑棒诀」！\n");
	
	if(me->query("max_mp") < 2000)
        return notify_fail("你内力修为现在不够, 不能用「玲珑棒诀」！\n");
	
	if (me->query("mp")<800)
        return notify_fail("你内力用尽, 不能用「玲珑棒诀」！\n");
	
	if(me->query_temp("gaibang/linglong"))
		return notify_fail("你的悟性不够,无法连续施展「玲珑棒诀」！\n");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "丐帮") )
		return notify_fail("你虽然听说过「玲珑棒诀」这一招，可是早已忘记使用的诀窍所在。\n");
	
	message_vision("\n$HIY$N轻声一笑，潇洒已极，双目精光四射，口中念念有词。\n但见棒子化成了一团碧影，猛点$n后心“强间”、“风府”、“大椎”、“灵台”、“悬枢”各大要穴。只要被棒端点中，非死即伤。\n", me, target);  
	
	ap=random(me->query("combat_exp"))+me->query_skill("dagou_bang",1)*(1+random(me->query("int")/2));
	dp=target->query("combat_exp");
	
	if(ap>dp ) 
	{
		damage=me->query_skill("huntian_qigong",1)*(1+random(me->query("str")/5))+me->query_skill("dagou_bang",1)*(1+random(me->query("int")/3));
		if (damage>50000)
			damage=50000+random(3000);
		target->receive_damage("hp",damage);
		target->receive_wound("hp",damage);
		me->add("mp", -800);
		me->start_busy(2);
		message_vision("$CYN$n叫声不好，势在不及回身招架，只得向前窜跃趋避，岂知$N的点打连绵不断，一点不中，又点一穴，棒影只在$n背后各穴上晃来晃去。\n$n一个疏神，连连中招!" , me, target);
	}
	else if(ap>dp/2)
	{
		message_vision("$HIG$N朗声诵道：「狗急跳墙如何打？ 快击狗臀劈狗尾。」\n随之向$n下盘接连攻出数招。\n",me,target); 
		for (int i=0;i<3;i++)
            g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		me->add("mp", -800);
		me->start_busy(2);
	}
	else if(ap>dp/4)
	{
		message_vision("$HIG$N悄声念道：「棒回掠地施妙手 ，横打双犬莫回头」, 随之棒影横掠而下，$n躲闪不及连中几下。\n", me, target);
		target->start_busy(4);
		me->add("mp", -800);
	}
	else
	{
		me->start_busy(random(5));
		me->add("mp", -400);
		message_vision("$n早识得丐帮打狗神技「玲珑棒诀」的厉害,料敌机先远远逃了开去。\n", me, target);
	}
	me->set_temp("gaibang/linglong",1);
	int delay=50-me->query("int");
	if(delay<1)
		delay=1;
	me->call_out(remove_effect, delay);
	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG count)
{
	CChar * me = (CChar *)ob;
	if(me->query_temp("gaibang/linglong"))
		me->delete_temp("gaibang/linglong");
}
SKILL_END;




