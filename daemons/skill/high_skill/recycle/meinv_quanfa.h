
// meinv_quanfa.h 美女拳法
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSmeinv_quanfa);

virtual void create()
{
	set_name( "美女拳法");

	Magic_t * magic;

	magic = add_magic("duo", do_duo);
	magic->name = "空手入白刃";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("lianquan", do_lianquan);
	magic->name = "练拳";
	magic->mp = 100;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMMON;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N一招 红玉击鼓 ，举拳由上而下击向$n的$l.", 5, 1,1, 0, "瘀伤",},
		{"$N一式 红拂夜奔 ，出其不意叩关直入，对准$n的$l猛击而下。", 15, 2,1,10 , "瘀伤",},
		{"$N腑身蹲下，一式 绿珠坠楼 ，直攻$n$l.",20 ,3 , 1,20, "瘀伤",},
		{"$N双掌纷飞,一招 文姬归汉 ，连绵不断的拍向$n", 25,4 , 1,30, "瘀伤",},
		{"$N突然迈前一步，一招 红线盗盒 ，绕至$n的身后拿他颈间大穴", 30,5 , 1,40, "瘀伤",},
		{"$N一式 木兰弯弓 ，左手架开$n的攻势，右手绪力拍向$n的$l.", 35, 6, 1,50, "瘀伤",},
		{"$N双目微微上翻，双手内笼，一式 班姬赋诗 ，双手左右夹攻，击向$n的$l",40 , 7,1,60 , "瘀伤",},
		{"$N似笑非笑,双拳无形无定,一式 嫦娥窃药 ,手腕翻转急点$n全身三十六处穴道", 45, 8, 1,70, "瘀伤",},
		{"$N摆动腰肢，一式 蛮腰纤纤 ,欺近$n的身边借势攻向$n的$l", 50, 9, 1,80, "瘀伤",},
		{"$N一式 丽华梳装 ,手臂上扬，脸上露出一丝微笑，一个箭步上前双掌交互拍击，掌掌击向$n的$l", 55,10 , 1,90, "瘀伤",},
		{"$N右脚上前半步，侧身一式 西子捧心 ,手臂上扬，突然一拳击向$n的$l", 60, 11, 1,100, "瘀伤",},
	};
	
	int level = 0;
	
	for(int i=11; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("meinv_quanfa", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", me->query_skill("dodge")/4);
			m_actions.set("damage", me->query_skill("meinv_quanfa",1) * action[level].damage);
			m_actions.set("force", me->query("per") * action[level].force);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if(EQUALSTR(me->querystr("gender"), "男性"))
		return notify_fail("你一个大老爷么能学会吗？");
	if (me->query_weapon())
		return notify_fail("练美女拳法必须空手。");
	if (me->query_skill("yunv_xinjing", 1) < 10)
		return notify_fail("你的玉女心经火候不够，无法学美女拳。");
	if (me->query("max_mp") < 50)
		return notify_fail("你的内力太弱，无法练美女拳。");
	return 1;
}

//perform 
static int do_duo(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	int skill;
	CContainer * weapon;
	string msg;
	
	if(ob &&ob->is_character())
		target = (CChar *) ob;

	if( me->query_temp("duo") )
		return notify_fail("你已经在夺敌人的兵刃了。");

	skill = me->query_skill("meinv_quanfa",1);
	
	if(!target || ! me->is_fighting(target))
		return notify_fail("空手入白刃只能对战斗中的对手使用。");
	
	if ( me->query_weapon())
		return notify_fail("你必须空手。");
	
	if (!(weapon = target->query_weapon()))
		return notify_fail("对方没有兵刃，你不用担心。");
	
	if( skill < 50)
		return notify_fail("你的美女拳法等级不够, 不能空手入白刃！");
	
	if( me->query_skill("yunv_xinfa",1)<30)
		return notify_fail("你的玉女心法修为不足，不能施展空手入白刃的功夫。");
	
	if( me->query("mp") < 100 )
		return notify_fail("你的内力不够，无法空手入白刃！");
	
	msg =  "$N凝神闭息，打算施展空手入白刃的绝技.\n";
	me->add("mp",-100);

	if( me->query_skill("unarmed")+me->query_skill("unarmed")/2>target->query_skill("parry"))
	{
		msg += "$N使出空手入白刃的绝招, $n顿时觉得眼前一花，手腕一麻，手中兵刃脱手而出！" ;
		target->start_busy(2);
		weapon->move(me);
		me->start_busy(2);
	}
	else
	{
		msg += "可是$n的看破了$N的企图，立刻采取守势，使$N没能夺下兵刃。";
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
	
	return 1;
	
}

static int do_lianquan(CChar * me, CContainer * ob)
{
	int skill, jing_cost;
	string msg;
	skill = me->query_skill("meinv_quanfa",1);
	jing_cost = me->query("int") - 45;
	
	if (DIFFERSTR(me->querystr("family/family_name"), "古墓派"))  
		return notify_fail("你不是古墓派弟子，不能使用总诀式练拳法。");
	
	if( me->is_fighting() )
		return notify_fail("「总诀式」不能在战斗中演练。");
	
	if (me->query_weapon())
		return notify_fail("练美女拳法必须空手。");
	
	if (me->query_skill("tianluo_diwang",1)<30)
		return notify_fail("你的天罗地网势火候不够，不能用总诀式练拳法.");
	
	if( !skill || (skill < 20))
		return notify_fail("你的美女拳法法等级不够, 不能用总诀式练！");
	
	if( me->query("mp") < 100 )
		return notify_fail("你的内力不够，没有力气练美女拳！");
	
	if( me->query("hp") < -jing_cost )
		return notify_fail("你现在太累了，无法集中精神演练美女拳法！");
	if(me->query_skill("yunv_xinfa",1)<me->query_skill("meinv_quanfa",1))
		return notify_fail("你的玉女心法修为不足以练美女拳法了。");	
	
	msg =  "$N演练了一套美女拳法。\n";
		
	me->add("mp", -20);
	me->add("hp", - jing_cost);
	me->improve_skill("meinv_quanfa", (me->query_skill("meinv_quanfa",1)+(me->query_skill("meinv_quanfa",1)/2)));
	
	msg += "$P的「美女拳法」进步了！";
	me->start_busy(random(2));
	message_channel("practice", msg.c_str(), me);
	return 1;
}

SKILL_END;
