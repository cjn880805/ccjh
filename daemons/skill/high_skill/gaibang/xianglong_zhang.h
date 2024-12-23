// xianglong_zhang.c 降龙十八掌
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSxianglong_zhang);

virtual void create()
{
	set_name( "降龙十八掌");
	set("valid_force", "huntian_qigong");
	
	set("diff",130);
	
	Magic_t * magic;
	
	magic = add_magic("leiting", do_leiting);
	magic->name = "雷霆一击";
	magic->mp = 350;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("xianglong", do_xianglong);
	magic->name = "降龙大法";
	magic->mp = 300;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
	
	magic = add_magic("wuhuei", do_wuhuei);
	magic->name = "亢龙无悔";
	magic->mp = 1500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  dodge,parry,force;
		char damage_type[5];
	}action[] = {
		{"$N使出「突如其来」，右掌从不可能的角度向$n的$l推出",-10 ,10 , 220,"瘀伤",},
		{"$N右掌一招「见龙在田」，迅捷无比地劈向$n的$l", -20, -10, 240,"瘀伤",},
		{"$N双掌施出一招「鸿渐于陆」，隐隐带着风声拍向$n的$l", -25, -10,260 ,"瘀伤",},
		{"$N身形滑动，双掌使一招「双龙取水」一前一后按向$n的$l", -20,20 , 280,"瘀伤",},
		{"$N突然身形飞起，双掌居高临下一招「飞龙在天」拍向$n的$l", -25,-20 , 300,"瘀伤",},
		{"$N左掌聚成拳状，右掌一招「潜龙勿用」缓缓推向$n的$l", -20, 10, 310,"瘀伤",},
		{"$N使出「羝羊触蕃」，双掌由下往上击向$n的$l", -25, 40, 320,"瘀伤",},
		{"$N使出「密云不雨」，左掌封住$n的退路，右掌斜斜地劈向$l", -25,20 , 330,"瘀伤",},
		{"$N左掌护胸，右掌使一招「神龙摆尾」上下晃动着击向$n的$l", -20, 40, 340,"瘀伤",},
		{"$N使出「或跃在渊」，向$n的$l连拍数掌", -30, -20, 350,"瘀伤",},
		{"$N施出一招「利涉大川」，右掌插腰，左掌劈向$n的$l", -30, 20, 360,"瘀伤",},
		{"$N使出「鱼跃于渊」，身形飞起，双掌并在一起向$n的$l劈下", -40, 30,370 ,"瘀伤",},
		{"$N双掌立起，使出「时乘六龙」向$n连砍六下", -40, 20, 390,"瘀伤",},
		{"$N大吼一声，双掌使出「震惊百里」，不顾一切般击向$n", -45, -10, 420,"瘀伤",},
		{"$N门户大开，一招「履霜冰至」向$n的$l劈去", -45, 1,440 ,"瘀伤",},
		{"$N脚下一转，突然欺到$n身前，一招「龙战于野」拍向$n的$l", -40, 40, 450,"瘀伤",},
		{"$N使出「损则有孚」，双掌软绵绵地拍向$n的$l", -45, 10, 470,"瘀伤",},
		{"$N双掌平平提到胸前，神色沉重的缓缓施出「亢龙有悔」推向$n的$l", -50, 10, 650,"瘀伤",},
	};
	
	int level = 0;
	
	if( me->query_temp("xianglong") 
		&& ( me->query("mp") > 20 ) )
	{
		me->add_temp("apply/str", me->query_temp("str_count"));
		me->add("mp", -20);
		me->add_temp("str_no", 1);
		me->add_temp("display_no", 1);
		if( me->query_temp("display_no") == 2 )
		{
			message_vision( "$HIY$N深吸了一口气，越战越勇！", me);
			me->set_temp("display_no", 0l);
		}
	}
	
	level = random(18);
	if(me->query_temp("wuhei"))
	{
		switch(me->query_temp("wuhei"))
		{
		case 1:
			m_actions.set("action", "$HIC$N脚下一转，突然欺身到$n身前，右掌斜转护住全身，左掌运劲一招「龙战于野」，猛然砍向$n的$l！");
			break;
		case 2:
			m_actions.set("action", "$HIB$N身形向前移动，双掌分使两式「双龙取水」，凌厉的掌风一左一右，但却不分先后，同时压向$n$l！");
			break;
		case 3:
			m_actions.set("action", "$HIY$N一招未完，一招又起，左掌回收，右掌向右横推，一招「见龙在田」，迅捷无比地劈向$n的$l！");
			break;
		case 4:
			m_actions.set("action", "$HIG$N右掌聚成拳状，格开$n手臂，接着左掌向前推出，一招「潜龙勿用」，雄浑的掌力缓缓压向$n！");
			break;
		case 5:
			m_actions.set("action", "$HIB但见$N左掌护胸，身体后转，背对$n，右掌紧跟着一摆，一招「神龙摆尾」拍向身后的$n！");
			break;
		case 6:
			m_actions.set("action", "$HIW$N突然一跃飞起半空，身形旋转，双掌居高临下，一招「飞龙在天」直向身下的$n压去！");
			break;
		}
	}
	else
		m_actions.set("action", action[level].action);
	m_actions.set("force", (me->query("skill_pro/丐帮/降龙十八掌/force")+100) * action[level].force/100);
	m_actions.set("dodge", (me->query("skill_pro/丐帮/降龙十八掌/dodge")+100) * action[level].dodge/100);
	m_actions.set("parry", (me->query("skill_pro/丐帮/降龙十八掌/parry")+100) * action[level].parry/100);
	
	return &m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry");
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/丐帮/降龙十八掌/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/丐帮/降龙十八掌/force"));
			if(me->query("skill_pro/丐帮/降龙十八掌/force_point")>=level_point)
			{
				me->add("skill_pro/丐帮/降龙十八掌/force",1);
				me->set("skill_pro/丐帮/降龙十八掌/force_point",1);
				tell_object(me,"\n$HIR你的降龙十八掌配合内功更能融汇贯通了。\n");
			}
		}
		else if(victim->query("parry")) 
		{
			me->add("skill_pro/丐帮/降龙十八掌/parry_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/丐帮/降龙十八掌/parry"));
			if(me->query("skill_pro/丐帮/降龙十八掌/parry_point")>=level_point)
			{
				me->add("skill_pro/丐帮/降龙十八掌/parry",1);
				me->set("skill_pro/丐帮/降龙十八掌/parry_point",1);
				tell_object(me,"\n$HIR你熟练的使用降龙十八掌，防守能力进一步加强了。\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/丐帮/降龙十八掌/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/丐帮/降龙十八掌/dodge"));
			if(me->query("skill_pro/丐帮/降龙十八掌/dodge_point")>=level_point)
			{
				me->add("skill_pro/丐帮/降龙十八掌/dodge",1);
				me->set("skill_pro/丐帮/降龙十八掌/dodge_point",1);
				tell_object(me,"\n$HIR你的降龙十八掌使用得更加得心应手了。\n");
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
	
	if (me->query_weapon())
		return notify_fail("练降龙十八掌必须空手。");
	if (me->query_skill("huntian_qigong", 1) < 20)
		return notify_fail("你的混天气功火候不够，无法练降龙十八掌。");
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练降龙十八掌。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 40)
		return notify_fail("你的体力太低了。");
	if (me->query("mp") < 10)
		return notify_fail("你的内力不够练降龙十八掌。");
	me->receive_damage("hp", 30);
	me->add("mp", -5);
	return 1;
}

//perform 
static int do_leiting(CChar * me, CContainer * ob)
{
	int damage;
	CChar * target = NULL;
	string msg;
	char cmd[255];
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target || !me->is_fighting(target) )
		return notify_fail("「雷霆一击」只能对战斗中的对手使用。");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "丐帮") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query_skill("huntian_qigong", 1) < 100 )
		return notify_fail("你的混天气功火候不够，使不出「雷霆一击」。");
	
	if( me->query_skill("xianglong_zhang", 1) < 100 )
		return notify_fail("你的降龙十八掌不够熟练，不会使用「雷霆一击」。");
	
	if( me->query("mp") < 500 )
		return notify_fail("你的内力修为还不够高。");
	
	if (me->query_weapon() )
		return notify_fail("「雷霆一击」必须空手才能使用。");
	
	msg = "$N默运混天气功，施展出「雷霆一击」，全身急速转动起来，越来越快，就犹如一股旋风，骤然间，$N已卷向正看得发呆的$n。\n";  
	
	if(random(me->query_combat_exp()) > target->query_combat_exp()/3) 
	{ 
		me->start_busy(3);
		target->start_busy(random(3));
		me->add("mp", -350);
		damage = me->query_skill("xianglong_zhang", 1)*6+me->query_skill("huntian_qigong",1)*2;
		
		damage = damage + random(damage);
		if(me->query("kill/guilt")>100)
		{
			damage = damage - me->query("kill/guilt")*20;
			if(damage<0)
			{
				damage=200;
			}
		}
		if(me->query("kill/guilt")< target->query("kill/guilt") && target->query("kill/guilt")>50)
		{
			damage = damage + target->query("kill/guilt")*20;
			if(target->query("kill/guilt")>150)
			{
				msg +=" $N凛然大喝道：$n这个恶贼，我今天要替天行道！\n";
			}
		}
		if(damage >=target->query("hp"))
		{
			damage=target->query("hp")-10;
		}
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/2);
		me->start_busy(1);
		msg += "$n只见一阵旋风影中陡然现出$N的双拳，根本来不及躲避，被重重击中，五脏六腑翻腾不休，口中鲜血如箭般喷出！！！";
		message_vision(msg.c_str(), me, target);
		snprintf(cmd,255,"$HIR结果造成了%d点的伤害。$COM\n",damage);
		message_vision(cmd,me,target);
	}
	else
	{
		me->add("mp", -50);
		me->start_busy(1);
		msg += "可是$p看破了$P的企图，闪在了一边。";
		message_vision(msg.c_str(), me, target);
	}
	
	
	if(!target->is_fighting(me)) target->kill_ob(me);
	return 1;
	
}

static int do_xianglong(CChar * me, CContainer * ob)
{
	int skill, count;
	
	if( me->query_temp("xianglong") ) 
		return notify_fail("你已经在运功中了。");
	
	if( !me->is_fighting() )
		return notify_fail("降龙大法只能在战斗中使用。");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "丐帮") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query_skill("xianglong_zhang", 1) < 150 )
		return notify_fail("你的降龙十八掌不够熟练，不会使用「降龙大法」。");
	
	if( me->query("mp") < 300  ) 
		return notify_fail("你的内力不够。");
	
	count = me->query("str");
	skill = me->query_skill("xianglong_zhang",1);
	me->add("mp", -100);
	message_vision(  "$N深吸一口气，运起降龙大法，结果越战越勇！" , me);
	me->set_temp("xianglong", 1);
	me->set_temp("str_count", count/5);
	me->set_temp("str_no", 0l);
	me->set_temp("display_no", 0l);
	me->call_out(remove_effect, skill / 2 );
	return 1;
}

static void remove_effect(CContainer *ob, LONG amount, LONG param)
{
	CChar *me =(CChar *) ob;
	
	LONG dmount = me->query_temp("str_no") * me->query_temp("str_count");
	me->add_temp("apply/str", - dmount );
	me->delete_temp("xianglong");
	me->delete_temp("str_count");
	me->delete_temp("str_no");
	me->delete_temp("display_no");
	
	tell_object(me, "你的降龙大法运行完毕，将内力收回丹田。");
}

static int do_wuhuei(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	string msg;
	int extra = me->query("death_times");
	if (extra>50)	extra = 50;
	if(extra<1)		extra=1;
	if(wizardp(me))		extra=99;
	
	if( !target	||!me->is_fighting(target) )
		return notify_fail("「$HIY亢$HIC龙$HIW无$HIR悔$COM」只能对战斗中的对手使用。\n");
	
	if (me->query_weapon() )
		return notify_fail("你必须空手使用「$HIY亢$HIC龙$HIW无$HIR悔$COM」！\n");
	
	if( (int)me->query_skill("xianglong_zhang", 1) < 220 )
		return notify_fail("你的降龙十八掌不够娴熟，无法施展出「$HIY亢$HIC龙$HIW无$HIR悔$COM」。\n");
	
	if (me->query_skill("huntian_qigong", 1)<220)
		return notify_fail("你的本门内功火候未到！\n");
	
	if(me->query_temp("gaibang/linglong"))
		return notify_fail("你的江湖阅历不够,无法连续施展「$HIY亢$HIC龙$HIW无$HIR悔$COM」！\n");
	
	if(!me->query("门派/gaibang/wuhui"))
		return notify_fail("你还没有领会到降龙十八掌最厉害的武功。\n"); 
	
	if(DIFFERSTR(me->querystr("family/family_name"), "丐帮") && me->Query(CChar::IS_USER) )
		return notify_fail("你虽然听说过「$HIY亢$HIC龙$HIW无$HIR悔$COM」这一招，可是早已忘记使用的诀窍所在。\n");
	
	if (DIFFERSTR(me->query_skill_mapped("unarmed"), "xianglong_zhang"))
		return notify_fail("「$HIY亢$HIC龙$HIW无$HIR悔$COM」无法在招架上使用。\n");
	
	if (me->query("max_mp") < 3000)
		return notify_fail("你的内力不够，无法施展出「$HIY亢$HIC龙$HIW无$HIR悔$COM」。\n");
	
	if (me->query("mp") < 1500)
		return notify_fail("你的真气不够，无法施展出「$HIY亢$HIC龙$HIW无$HIR悔$COM」。\n");
	
	me->add_temp("apply/str", extra);
	me->add_temp("apply/attack", extra*6);
	me->add_temp("apply/damage", extra);
	me->add("mp", -1500);
	
	char msg1[255],tmp[80];
	message_vision(snprintf(msg1, 255,
		"$HIR\n\n$N想起自己平生遭遇过的%s次生死危亡。\n\n现在又处于生死关头。求生欲望大增。\n\n$HIW双掌平平提到胸前，使出降龙十八掌的最后绝学「$HIY亢$HIC龙$HIW无$HIR悔$HIW」，排山倒海般推向$n！" ,
		chinese_number(me->query("death_times"),tmp)), me, target); 
	
	for(int i=0;i<6;i++)
	{
		me->add_temp("wuhei",1);
		if(me->is_fighting(target)) 
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	}
	me->delete_temp("wuhei");
	
	me->add_temp("apply/str", -extra);
	me->add_temp("apply/attack", -extra*6);
	me->add_temp("apply/damage", -extra);
	
	if( random(me->query("combat_exp")) > target->query("combat_exp")/4 && me->is_fighting(target))
		//&& me->query("xlz/hang")
	{
		msg = "$HIR\n\n$N咬紧牙关，双掌护身，心中默念降龙十八掌的口诀!    $HIY亢  $HIC龙  $HIW无  $HIR悔$COM ";
		msg += "$RED\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n";
		target->receive_damage("hp",me->query_skill("strike")*5+random(me->query_skill("strike")));
		target->receive_wound("hp",me->query_skill("strike")*5);
		
		if (!target->is_busy()) target->start_busy(2);
		message_vision(msg.c_str(), me, target);
	}
	me->start_busy(6);
	me->set_temp("gaibang/wuhuei",1);
	
	if(EQUALSTR(target->querystr("family/family_name"), "丐帮") && !target->query_weapon() 
		&&  (int)target->query_skill("xianglong_zhang", 1) > 220 && !target->query("门派/gaibang/wuhui")
		&& EQUALSTR(target->query_skill_mapped("unarmed"), "xianglong_zhang")
		&& target->query("hp") > target->query("max_hp")/10)
	{
		target->add("门派/gaibang/wuhui_imp",1);
		if(target->query("门派/gaibang/wuhui_imp")>1000)
		{
			tell_object(target, "$HIR你脑袋嗡的一声炸响，对手的刚才每一个动作如同定格般的在你脑海中闪现，虽一晃即逝，但你已经深深的体会到了「$HIY亢$HIC龙$HIW无$HIR悔$COM」的精髓所在。\n你历经无数的生死存亡，终于在垂死中顿悟了降龙十八掌的无上绝学「$HIY亢$HIC龙$HIW无$HIR悔$COM」！");
			target->set("门派/gaibang/wuhui",1);
			target->del("门派/gaibang/wuhui_imp");
			target->set("mp",0l);
			if(target->query("hp")>1)
			{
				target->set("hp",1);
				target->set("eff_hp",1);
			}
		}
		else
			tell_object(target, "$HIR你擦拭去嘴角的血迹，稳住起伏不定的心跳，深深的吸了一口气，凝视着对手的身形，若有所思！");
	}
				
	int delay=100-extra;
	if(delay<1)
		delay=1;
	me->call_out(remove_effect1, delay);
	return 1;
}

static void remove_effect1(CContainer * ob, LONG param1, LONG count)
{
	CChar * me = (CChar *)ob;
	if(me->query_temp("gaibang/wuhuei"))
		me->delete_temp("gaibang/wuhuei");
}

SKILL_END;




