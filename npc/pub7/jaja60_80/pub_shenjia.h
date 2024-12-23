// lev1_shenjia.h 申甲
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_shenjia);

virtual void create()
{
	set_name("申甲", "shen jia");
	set("title", "鬼骷髅");
	set("gender", "男性");
	set("age", 35);
	set("level", 100);
	set("long", 
		"他的人已经瘦得不成人形，而且至少已有几个月没洗过澡，一张又脏又瘦的脸上长满了胡子，让人简直连看都不敢看。\n");
	
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",17);				//设置人物形象
	set("repute", -5000);
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// 基本内功
	set_skill("huntian_qigong", 190+random(30));		// 混天气功
	set_skill("strike", 190+random(30));			// 基本掌法
	set_skill("xianglong_zhang", 190+random(30));		// 降龙十八掌
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("xiaoyaoyou", 190+random(30));			// 逍遥游
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("claw", 190+random(30));		      		// 基本爪法
	set_skill("jiuyin_zhua", 190+random(30));			// 九阴白骨爪
	set_skill("staff", 190+random(30));			// 基本杖法
	set_skill("dagou_bang", 190+random(30));			// 打狗棒法


	map_skill("force", "huntian_qigong");		//设置NPC当前内功为混天气功
	map_skill("claw", "jiuyin_zhua");	        //设置NPC的基本爪法装备九阴白骨爪
	map_skill("dodge", "xiaoyaoyou");		//设置NPC的基本躲闪装备逍遥游
	map_skill("parry", "jiuyin_zhua");		//设置NPC的基本招架装备九阴白骨爪
	map_skill("strike", "xianglong_zhang");		//设置NPC的基本掌法装备降龙十八掌
	map_skill("staff", "dagou_bang");		//设置NPC的基本杖法装备打狗棒法

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 10);			//设置NPC附加攻击力

	prepare_skill("claw", "jiuyin_zhua");		//设置NPC的空手组合
	prepare_skill("strike", "xianglong_zhang");

	carry_object("gangzhang")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("claw zhua", 1);		//九阴白骨爪绝招亡魂一击
		break;
	case 1:
		perform_action("strike leiting", 1);	//降龙十八掌绝招雷霆一击
		break;
	case 2:
		perform_action("strike xianglong", 1);	//降龙十八掌绝招降龙大法
		break;
	case 3:
		perform_action("staff zhuang", 1);	//打狗棒(zhuang千环套狗)
		break;
	case 4:
			//自动吸气
		break;
	case 5:
			//自动吸气
		break;
	}	
	return 0;
}

LEV1_END;