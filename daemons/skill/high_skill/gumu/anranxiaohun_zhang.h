
//anranxiaohun_zhang.c 黯然消魂掌
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSanranxiaohun_zhang);

virtual void create()
{
	set_name( "黯然消魂掌");

	Magic_t * magic;

	magic = add_magic("xiaohun", do_xiaohun);
	magic->name = "黯然消魂";
	magic->mp = 1000;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "yunv_xinfa") || EQUALSTR(arg, "seaforce"))
		return 1;

	return notify_fail("黯然消魂掌必须与古墓独门内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N一招 杞人忧天 抬头向天，浑若不见，呼的一掌向自己头顶空空拍出，手掌斜下，掌力化成弧形，四散落下拍向$n的$l。", 250,1, 2, 0, "内伤", },
		{"$N一招 无中生有 手臂下垂，绝无半点防御姿式，突然间手足齐动，左掌右袖、双足头锤、连得胸背腰腹尽皆有招式发出撞向$n.", 250, 1, 3, 10, "瘀伤", },
		{"$N一招 拖泥带水 右手云袖飘动，宛若流水，左掌却重滞之极，便似带着几千斤泥沙一般，左右齐攻$n。", 250, 1, 4, 20, "内伤", },
		{"$N一招 力不从心 含胸收腹，头缓缓低下，脚步沉重的迈向$n,右掌软绵绵的拍向$n的$l。", 250,1, 5, 30, "瘀伤", },
		{"$N一招 行尸走肉 踢出一脚。这一脚发出时恍恍惚惚，隐隐约约，若有若无的踢向$n", 250, 1, 6, 40, "瘀伤", },
		{"$N双掌平托，一招 庸人自扰 没精打采的拍向$n的$l.", 250,1, 7, 50, "瘀伤", },
		{"$N一招 倒行逆施 突然纵起丈余，头下脚上，倒过身子，一掌拍向$n的$l", 300, 1, 8, 60, "瘀伤", },
		{"$N一招 心惊肉跳 凝目远眺，脚下虚浮，胸前门户洞开，全身姿式与武学中各项大忌无不吻合。", 300, 1, 9, 70, "内伤", },
		{"$N一招 废寝忘食 脚下虚浮，有如几天不吃不睡后的脚步朗舱的袭到$n的身旁，左掌右拳攻向$n的$l。", 300, 1, 10, 80, "瘀伤", },
		{"$N一招 徘徊空谷 左攻右打，虚虚实实的攻向$n的$l。", 300,1, 11, 90, "瘀伤", },
		{"$N一招 饮恨吞声 左手做饮酒状，右掌斜斜劈向$n的$l。", 350, 1, 12, 100, "瘀伤", },
		{"$N一招 六神不安 身如陀螺急转，展开轻功围着$n快速游走，忽然飞身而起，拍向$n的$l。", 400, 1, 13,110 , "内伤", },
		{"$N一招 穷途末路 闪身到$n身旁，左掌举到胸前平推而出，接着右掌斜斜劈向$n的$l。", 450,1, 14, 120, "瘀伤", },
		{"$N一招 呆若木鸡 双目直直的盯着$n，身体动也不动一下的飞向$n", 500 ,1, 15, 130, "内伤", },
		{"$N低头冥想，一招 若有所失 右掌向外平平推向$n的$l。", 550,1, 16, 140, "瘀伤", },
		{"$N一招 四通八达 双掌晃出千万掌影将$n笼罩在掌力之下。", 600, 1, 17, 150, "内伤", },
		{"$N错步上前，一招 鹿死谁手 招招抢先，以快打慢，一个转身已经转到了$n的身后，运指如风点向$n的大椎穴。", 800, 1, 18, 160, "点穴", },
	};
	
	int level = 0;
	
	for(int i=17; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("anranxiaohun_zhang", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", me->query_skill("dodge") / 2);
			if(me->query("age")<200)
				m_actions.set("damage", me->query("age") * action[level].damage);
			else
				m_actions.set("damage", 200 * action[level].damage);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry");
}

virtual int valid_combine(string combo) { return combo=="anranxiaohun_zhang"; }

virtual int valid_learn(CChar * me)
{
	if (!me->query("couple_betray"))
		return notify_fail("你没有丧失过伴侣，不能领会其中的精要！");

	if (me->querymap("couple"))
		return notify_fail("你现在已有所爱，不能领会其中的精要！");

	if (DIFFERSTR(me->querystr("gender"), "男性")) 
		return notify_fail("你体会不到男人思念一个人的心情。");
		
	if (me->query_weapon() )
		return notify_fail("练黯然消魂掌必须空手。");

	if (me->query("max_mp") < 2000)
		return notify_fail("你的内力太弱，无法练黯然消魂掌。");

	if (me->query_str()< 40)
		return notify_fail("你的臂力太弱，无法练黯然消魂掌。");
	
	if (me->query_skill("seaforce", 1) < 30 || me->query_skill("yunv_xinfa", 1) < 30)
		return notify_fail("你的本门心法火候不到，无法练黯然消魂掌。");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");

	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练黯然消魂掌。");

	if (DIFFERSTR(me->querystr("family/family_name"), "古墓派"))
		return notify_fail("你不是古墓派的弟子,无法练习黯然消魂掌。");

	if (me->query_skill("seaforce", 1) < 50|| me->query_skill("yunv_xinfa", 1) < 50)
		return notify_fail("你的本门心法火候不到，无法练黯然消魂掌。");

	me->receive_damage("hp", 25);
	me->add("mp", -30);
	return 1;
}

//perform 
static int do_xiaohun(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(!target || !me->is_fighting(target) )
		return notify_fail("「黯然消魂」只能在战斗中使用。");

	if (DIFFERSTR(me->querystr("family/family_name"), "古墓派"))
		return notify_fail("你不是古墓派的弟子,无法体会「黯然消魂」中的寂寞。");

	if (!me->query("couple_betray"))
		return notify_fail("你没有丧失过伴侣，不能领会其中的精要！");

	if (me->query_weapon())
		return notify_fail("必须空手。");
	
	if( me->query("mp") < 1000 )
		return notify_fail("你的真气不够！");
	
	if( me->query_skill("anranxiaohun_zhang",1) < 170 )
		return notify_fail("你的黯然消魂掌火候不够，无法使用「黯然消魂」！");
	
	if( me->query_skill("force") < 300 )
		return notify_fail("你的内功修为不够，无法使用「黯然消魂」！");
	
	message_vision("$N心如止水，心中思念着$N的妻子，无意之中使出了“黯然消魂”！", me);
	
	if(target->query_temp("apply/no_黯然消魂") && (random(me->query_combat_exp()) < target->query_combat_exp()/3 ||target->query("bigboss")))
	{
		message_vision("可是$n看破了$N的企图，并没有上当。\n" ,me,target); 
	}
	else
	{
    	if (me->querymap("couple"))
		{
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		}
		else
		{
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		}
		me->add("mp", -500);
		me->start_busy(random(4));
	}
	return 1;
}

SKILL_END;
