//yueying_wubu.h 月影舞步

SKILL_BEGIN(CSyueying_wubu);

virtual void create()
{
	set_name( "月影舞步");

	Magic_t * magic;
	
	magic = add_magic("jianwu", do_jianwu);
	magic->name = "剑之舞";
	magic->mp = 120;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("huawu", do_huawu);
	magic->name = "花之舞";
	magic->mp = 350;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[9][80]={	
		{"$n身形一晃，纤腰一扭，一招「星河鹭起」，弹地而起。"},
		{"$n一招「歌尽桃花扇底风」，$N只觉眼前一花，不见了$n的身影。"},
		{"$n一招「扫尽浮云风不定」，身形微晃，有惊无险地避开了$N这一招。"},
		{"只见$n身子向后一翻，一招「缥渺孤鸿影」，后荡而起，掠向一旁。"},
		{"$n一招「起舞弄清影」，长袖翻飞，躲过$N这一招。"},
		{"却见$n「万顷江田一鹭飞」，冲天而起，一波三折，端是美观。"},
		{"可是$n一个「流水落花春去也」，侧身一让，$N这一招扑了个空。"},
		{"只见$n一招「月轮穿沼水无痕」，倒掠身形，凌空两个翻转，退出两丈开外。"},
		{"$n息气上升，意存玉枕，一招「月在青天影在波」，身子飘然而起。"},
	};

	return dodge_msg[random(9)];
}

virtual int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 45 )
		return notify_fail("你的体力太差了，不能练月影舞步。");

	me->receive_damage("hp", 35);
	return 1;
}

//剑之舞
static int do_jianwu(CChar * me, CContainer * ob)
{
	if(!me->is_fighting() )
		return notify_fail("\n「剑之舞」只能在战斗中使用。");
	
	if(me->query_skill("yueying_wubu",1) < 200 )
		return notify_fail("\n你的月影舞步不够娴熟，不会使用「剑之舞」！");
	
	if(me->query_skill("bahuang_gong",1) < 120 )
		return notify_fail("\n你的八荒六合唯我独尊功等级不够，不能使用「剑之舞」！");  

	if(me->query_dex() < 26 )
		return notify_fail("\n你的身法太低，不能使用「剑之舞」！");
	
	if(me->query_skill("dodge",1) < 200 )
        return notify_fail("\n你的基本轻功太差，身体笨拙，不能使用「剑之舞」！");

	if(me->query_skill("sword",1) < 120 )
		return notify_fail("\n你的剑术太差，无法领会到「剑之舞」的要诀！");  
	
	if(me->query("mp") < 120 )
		return notify_fail("\n你的内力太少了，无法使用出「剑之舞」！");   
	
	if (DIFFERSTR(me->query_skill_mapped("dodge"), "yueying_wubu"))
		return notify_fail("\n你现在激发的轻功无法使用「剑之舞」绝技。");  

	if (DIFFERSTR(me->querystr("gender"), "女性"))
		return notify_fail("\n$HIR你试图踩着「剑之舞」的节奏舞动起来，可是看看自己魁梧的身躯不由地止住步伐。"); 

	if( me->query_temp("wu"))
		return notify_fail("\n你正在随剑而舞！");

	if(DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫") )
		return notify_fail("\n你依稀记得曾经学过「剑之舞」这一招，可是间隔时间太久已经无法全部记起了。\n");
	
	message_vision( "\n$HIW$N略一提气，运起轻功，拔剑起舞。只见$N足不沾地，手中剑越舞越快，逐渐幻做一团白雾，满堂滚动。\n", me); 

	int skill_dodge = me->query_skill("dodge"); 
	int skill_sword=me->query_skill("sword");
	int attack_amount=skill_sword*random(6)/10;
	int dodge_amount=skill_dodge*(5+random(6))/10; 
	me->add_temp("apply/attack", -attack_amount);  
	me->add_temp("apply/dodge",dodge_amount); 

	me->set_temp("wu",1);  
	me->add("mp", -100);
	me->UpdateMe();

	me->call_out(remove_effect, me->query_skill("yueying_wubu") * 2/3,attack_amount,dodge_amount);

	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;  
	int attack_amount=(int)param1;
	int dodge_amount=(int)param2;
	me->add_temp("apply/attack", attack_amount);  
	me->add_temp("apply/dodge",-dodge_amount); 
	me->UpdateMe();

	me->delete_temp("wu");
	message_vision("\n$HIW$N渐感气力不支，不得不放慢脚步，放缓剑招。\n",me);
}

//花之舞
static int do_huawu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || ! me->is_fighting(target))
		return notify_fail("\n「花之舞」只能在战斗中使用。");

	if(target->is_busy() )
        return notify_fail("%s目前不能动弹，放胆攻击吧！", target->name());
	
	if(me->query_skill("yueying_wubu",1) < 220 )
		return notify_fail("\n你的月影舞步不够娴熟，不会使用「花之舞」！");
	
	if(me->query_skill("bahuang_gong",1) < 180 )
		return notify_fail("\n你的八荒六合唯我独尊功等级不够，不能使用「花之舞」！");  

	if(me->query_dex() < 28 )
		return notify_fail("\n你的身法太低，不能使用「花之舞」！");
	
	if(me->query_skill("dodge",1) < 220 )
        return notify_fail("\n你的基本轻功太差，身体笨拙，不能使用「花之舞」！");
	
	if(me->query("mp") < 350 )
		return notify_fail("\n你的内力太少了，无法使用出「花之舞」！");   
	
	if (DIFFERSTR(me->query_skill_mapped("dodge"), "yueying_wubu"))
		return notify_fail("\n你现在激发的轻功无法使用「花之舞」绝技。");  

	if (DIFFERSTR(me->querystr("gender"), "女性"))
		return notify_fail("\n$HIR你试图踩着「花之舞」的节奏舞动起来，可是看看自己魁梧的身躯不由地止住步伐。"); 
	
	if(DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫") )
		return notify_fail("\n你依稀记得曾经学过「花之舞」这一招，可是间隔时间太久已经无法全部记起了。\n");
	
	message_vision( "\n$HIY$N嫣然一笑，暗运真气，对着$n跳起舞来，$n不由一楞。\n$N身体飞速旋转着，顿时化成了一条美丽的圆弧，$N软若无骨的娇躯如桂花一般洒向天空。", me,target); 

	int lv = me->query_skill("yueying_wubu",1)/80;
	lv=lv+me->query("per")/15;

	if(random(me->query("combat_exp")) > target->query("combat_exp")/2)
	{
		message_vision( "$HIR结果$n被$N围个水泄不通！", me,target); 
		target->start_busy(lv);
		me->add("mp", -300);
		me->start_busy(1);
	} 
	else
	{
		message_vision( "$HIG$n只是一个箭步，便闪开了。", me,target); 
		me->add("mp", -150);
		me->start_busy(1);
	}
	
	me->UpdateMe();

	return 1;
}

SKILL_END;

