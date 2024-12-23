
// lanhua_shou.h 兰花拂穴手
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSlanhua_shou);

virtual void create()
{
	set_name( "兰花拂穴手");
	set("valid_force", "bibo_shengong");

	set("diff",110);

	Magic_t * magic;

	magic = add_magic("fuxue", do_fuxue);
	magic->name = "拈花拂穴";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,lvl;
		char damage_type[5];
	}action[] = {
		{"$N右手五指分开，微微一拨，再并拢向外一拂，一式「花疏云淡」，拂向$n的膻中要穴",150 , 5, 0,"瘀伤",},
		{"$N侧身掠向$n，一式「轻云蔽月」，左手五指暗暗运气拨向$n的胸前大穴", 160, 5, 10,"瘀伤",},
		{"$N使一式「云破月来」，左掌虚攻，右手并指斜前翻出，拍向$n的肩井穴", 170, 15, 20,"内伤",},
		{"$N左掌护胸，微微侧身，右掌勾上，一式「幽兰弄影」，缓缓拂向$n的天突穴", 190, -5, 30,"瘀伤",},
		{"$N使一式「芳兰竟体」，身影不定地掠至$n身后，猛地拍向$n的大椎穴", 210, 10, 42,"瘀伤",},
		{"$N两臂左手下右手上地于胸前成兰花指形翻上，微吸一口气，一式「兰桂齐芳」，双手向外快速一拨，激出数道劲气逼向$n的华盖、璇玑、紫宫几处大穴", 240, 5, 54,"瘀伤",},
		{"$N衣袂飘飘，向上跃起，一式「月影花香」，居高临下，拂出一道劲力罩向$n的百会大穴", 270, 20, 66,"内伤",},
		{"$N凝神施展出「花好月圆」，双手疾拂，一环环的劲气逼向$n的上中下各大要穴", 300,25 , 80,"内伤",},
	};

	int level = me->query_skill("lanhua_shou", 1);
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level )
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
*/
			m_actions.set("force", (me->query("skill_pro/桃花岛/兰花拂穴手/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/桃花岛/兰花拂穴手/dodge")+100) * action[level].dodge/100);

			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "hand") || (usage == "parry");
}

virtual int valid_combine(string combo) { return combo=="tanzhi_shentong"; }


virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/桃花岛/兰花拂穴手/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/桃花岛/兰花拂穴手/force"));
			if(me->query("skill_pro/桃花岛/兰花拂穴手/force_point")>=level_point)
			{
				me->add("skill_pro/桃花岛/兰花拂穴手/force",1);
				me->set("skill_pro/桃花岛/兰花拂穴手/force_point",1);
				tell_object(me,"\n$HIR你的兰花拂穴手配合内功更能融汇贯通了。\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/桃花岛/兰花拂穴手/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/桃花岛/兰花拂穴手/dodge"));
			if(me->query("skill_pro/桃花岛/兰花拂穴手/dodge_point")>=level_point)
			{
				me->add("skill_pro/桃花岛/兰花拂穴手/dodge",1);
				me->set("skill_pro/桃花岛/兰花拂穴手/dodge_point",1);
				tell_object(me,"\n$HIR你的兰花拂穴手使用得更加得心应手了。\n");
			}
		}
	}
	return "";
}


virtual int valid_learn(CChar * me)
{
    if (me->query_weapon()  )
		return notify_fail( "练兰花拂穴手必须空手。" );
    if ( me->query_skill("bibo_shengong", 1) < 20)
		return notify_fail("你的碧波神功火候不够，无法学兰花拂穴手。");
    if ( me->query("max_mp") < 200)
		return notify_fail("你的内力太弱，无法练兰花拂穴手。");
    return 1;
	
}

virtual int practice_skill(CChar * me)
{
    if ( me->query("hp") < 30)
		return notify_fail("你的体力太低了，无法练兰花拂穴手。");
    me->receive_damage("hp", 25);
    return 1;
}

//perform 
static int do_fuxue(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || !me->is_fighting(target))		//add by Lanwood 2000-12-26
		return notify_fail("只能对战斗中的敌人使用。");

	if( me->query_str() < 25)
		return notify_fail("你臂力不够,不能使用这一绝技!");

	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query_weapon() )
		return notify_fail("你还拿着兵器呢，是使不出兰花一般的指法的。");	

	if( me->query_skill("bibo_shengong",1) < 100)
		return notify_fail("你碧波神功的功力不够不能使用兰花拂穴!");
	
	if( me->query_skill("hand") < 120)
		return notify_fail("你的手法修为不够,目前还不能使用兰花拂穴绝技!");
	
	if( me->query("mp") < 500)
		return notify_fail("你内力现在不够, 不能使用拈花拂穴! ");
	
	if( target->is_busy() )
		return notify_fail("%s目前正自顾不暇，放胆攻击吧 ",target->name() );
	
	msg =   "$HIY$N右手反手伸出，三个指头婉转如一朵盛开的兰花，轻盈点向了$n的胁下要穴, 使$n动弹不得。\n";
	
	if( random(me->query_combat_exp()) >  target->query_combat_exp() / 3 )
	{
		if(target->query_temp("apply/no_拈花拂穴")&& !random(2))
		{
			msg += "$HIC可是$p看破了$P的企图，轻轻一跃，跳了开去。";
		}
		else
		{
			msg +=    "$HIM结果$p被$P点个正着，顿时手足无措，呆立当地! "  ;
			target->start_busy(  me->query_skill("lanhua_shou",1) / 20 );
			me->add("mp", -100);
		}
	}
	else
	{
		msg +=   "$HIC可是$p看破了$P的企图，轻轻一跃，跳了开去。"  ;
		me->start_busy(4);
		me->add("mp", -50);		// add by lanwood 2000-12-26
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;




