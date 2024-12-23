// qufeng.h 驱蜂之术
//秦波 2002、1、17修改

SKILL_BEGIN(CSqufeng);

virtual void create()
{
	set_name( "驱蜂之术");

	Magic_t * magic;

	magic = add_magic("wanfengsiyue", do_wanfengsiyue);
	magic->name = "万蜂噬骨";
	magic->mp = 300;
	magic->ap= 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  dodge, force,damage,lvl;
		char damage_type[5];
	}action[] = {
			{"$N口中轻吟，$n仿佛听见一阵嗡嗡的声音自远而近，突然间树林中灰影闪动，飞出一群玉蜂，往$n头顶扑来。",
			 -60, 120,100, 0, "内伤",},
			{"$N双手一挥手中的丝带，只见蜂群突分为二，一群正面扑来，另一群却从后向$n攻至。",
			 -50, 240, 140,39, "内伤",},
			{"$N右袖慢舞，口中哨音急变，群蜂顿时散了开来，上下左右、四面八方的向$n扑击。",
		     -55, 300, 180,69, "内伤",},
			{"$N身形猛然一转,左手变掌为诀，口中发出一高两低的哨声，顿闻林中起了一阵嗡嗡异声，接着灰影幌动，一群白色蜂子从树叶间飞出，向$n面前扑来。",
			 -55, 380,220,121, "内伤",},
			{"$N左指轻弹，两只蜂子猛地从空隙中飞了进去，在$n右颊上各螫了一针。片刻之间，$n只感麻痒难当，似乎五脏六腑也在发痒。",
			 -40, 500,400,250, "内伤",}
	};

	int level = 0;
	
	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("qufeng", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	if (me->query_temp("teapot/qufeng"))
	{
			level=me->query_temp("teapot/qufeng")-1;
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
	}
	return & m_actions;
}

virtual int valid_enable(string usage) { return usage=="music";}


virtual int valid_learn(CChar * me)
{
	if( DIFFERSTR(me->querystr("family/family_name"), "古墓派")|| DIFFERSTR(me->querystr("family/master_id"), "long er"))
		return notify_fail("驱蜂之术只有向小龙女学习。");

	if (DIFFERSTR(me->querystr("gender"), "女性")) 
		return notify_fail("一个大男人整天的招蜂舞蝶，不大好吧！。");	

	if ( me->query_skill("wudu_shenzhang",1)
		|| me->query_skill("chousui_zhang",1)
		|| me->query_skill("shexing_diaoshou",1)
		|| me->query_skill("jiuyin_zhua",1)
		|| me->query_skill("huagu_mianzhang",1)
		|| me->query_skill("dashou_yin",1) 
		|| me->query_skill("hanbing_mianzhang",1))
		return notify_fail("你满身邪门武功，我不能教你！");

	if(me->query("repute") < 50000)
	{
		return notify_fail("你的品行不好，这个武功我不能教你！");
	}

	if(me->query("dex") < 20)
		return notify_fail("你的身体敏捷太低,不能领悟驱蜂之术。");

	if(me->query_int() < 35)
		return notify_fail("你的资质太低,不能领悟驱蜂之术。");

	if (me->query_skill("yunv_shenfa", 1) < 100)
		return notify_fail("你的玉女身法火候还不够,不能领悟驱蜂之术。");

	if (me->query_skill("music", 1) < 100)
		return notify_fail("你的音律之术火候还不够,不能领悟驱蜂之术。");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("没有龙儿师父的指点，你怎么能领悟的更高呢？");
}


static int do_wanfengsiyue(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char cmd[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(!target || !me->is_fighting(target) )
		return notify_fail("「万蜂噬骨」只能在战斗中使用。");

	if( DIFFERSTR(me->querystr("family/family_name"), "古墓派") ||DIFFERSTR(me->querystr("gender"), "女性"))
		return notify_fail("古墓派女弟子才可以使用「万蜂噬骨」绝招。");

	if( me->query("mp") < 600 )
		return notify_fail("你的真气不够！");

	if( me->query_skill("yunv_shenfa",1) < 200 )
		return notify_fail("你的玉女身法火候不够，无法使用「万蜂噬骨」！");

	if (me->query_skill("music", 1) < 180)
		return notify_fail("你的音律之术火候还不够,无法使用「万蜂噬骨」。");

	if(me->query("dex") < 25 || me->query_dex() < 40)
		return notify_fail("你的身体敏捷太低,无法使用「万蜂噬骨」！");

	if (me->query_skill("qufeng", 1) < 200)
		return notify_fail("你的驱蜂之术火候还不够,无法使用「万蜂噬骨」。");

	if(!EQUALSTR(me->query_skill_mapped("music"), "qufeng"))
		return notify_fail("你的「万蜂噬骨」必须装备在音律之术上才能使用。");

	if(me->query_int() < 40)
		return notify_fail("你的资质太低,无法使用「万蜂噬骨」！");

	message_vision("\n$HIM$N轻挥长袖，微退一步，口中嗡嗡低吟。刹那间，$n身边出现了漫天飞舞的无数玉蜂。$COM\n" ,me,target); 

	if (random(me->query("combat_exp"))> target->query("combat_exp")/3 )
	{
		if(target->query_temp("apply/反_万蜂噬骨")&& (!random(3)||wizardp(me)))
		{
			message_vision("$HIY$n将箫靠在唇边，用无比雄厚的内力吹出一曲《鹧鸪飞》，漫天蜂群竟全部为箫声所夺，纷纷向$N袭来。。$COM\n" ,me,target); 	
			me->add("mp",-300);	
			int m= (target->query_skill("dodge",1)/2+target->query_skill("music",1)/2)*(random(target->query("age")/4)+1);
			me->add("hp",-m);
			snprintf(cmd ,255,"$HIY结果$N受到了%d点的伤害。",m);
			if(random(3))
			{
				me->apply_condition("yufeng_poison", 5);
			}
			message_vision(cmd,me,target);
			me->start_busy(5);
		}
		else if(!EQUALSTR(target->query_skill_mapped("strike"), "haotian_zhang") && !EQUALSTR(target->query_skill_mapped("strike"), "luoying_shenzhang") && ! EQUALSTR(target->query_skill_mapped("unarmed"), "xianglong_zhang"))
		{
			me->start_busy(1);
			int m;
			if( me->querymap("couple") || me->query("max_atman")|| me->query("wench/sleep"))
			{
				m=3;
			}
			else
			{
				m=5;
			}
			for(int n = 0; n <	m; n++)
			{
				me->set_temp("teapot/qufeng",n+1);
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			}
			if(random(2))
			{
				target->apply_condition("yufeng_poison", 5);
			}
			me->delete_temp("teapot/qufeng");
			me->add("mp",-300);	
			message_vision("\n$HIR$n忽觉身上刺痛，睁开眼来，只见无数白色蜂子在身周飞舞来去，耳中听到的尽是嗡嗡之声。" ,me,target); 
			message_vision("$HIR跟着全身奇痒入骨，眼前白茫茫的一片，不知是真是幻，又晕了过去。$COM" ,me,target); 
			me->start_busy(random(1)+2);
		}
		else
		{
			if(EQUALSTR(target->query_skill_mapped("strike"), "haotian_zhang") )
			{
				message_vision("$HIY$n双掌缩入袖中，双袖飞起扫向四周，却是一招「长江流水」，仪态潇洒。" ,me,target); 
			}
			else if(EQUALSTR(target->query_skill_mapped("strike"), "luoying_shenzhang") )
			{
				message_vision("$HIY但只见$n使一式「狂风卷叶」，全身突然飞速旋转，双掌忽前忽后，猛地拍向四周。" ,me,target); 
				
			}
			else
			{
				message_vision("$HIY$n双掌平平提到胸前，神色沉重的缓缓施出「亢龙有悔」推向蜂群。" ,me,target); 	
			
			}
			message_vision("$HIY顿时$n周围的群蜂一片混乱，被强烈的掌风卷向$N,一起朝$N扑来。$COM\n" ,me,target); 	
			message_vision("$HIR$N眼前白茫茫的一片，不知是真是幻，$n紧接着一掌打个正着，$N不由的晕了过去。$COM" ,me,target); 	
			me->add("mp",-300);	
			int m= (target->query_skill("parry",1)/2+1)*(random(target->query("age")/4)+1);
			me->add("hp",-m);
			snprintf(cmd ,255,"$HIY结果$N受到了%d点的伤害。",m);
			if(random(3))
			{
				me->apply_condition("yufeng_poison", 5);
			}
			message_vision(cmd,me,target);
			me->start_busy(5);
		}
	} 
	else 
	{ 
		message_vision("$HIC可是$n看破了$N的招式,趁机发动进攻！$COM\n" ,me,target);
		me->add("mp",-200);	
		me->start_busy(3);
	}  
	return 1;
}

SKILL_END;
