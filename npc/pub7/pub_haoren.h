// pub_haoren.h 郝仁
//jaja 2002-10-20

NPC_BEGIN(CNpub_haoren);

virtual void create()
{
	set_name("郝仁", "hao ren");
	set("title", "巨手飞贼");
	set("gender", "男性");
	set("age", 71);
	set("level", 100);
	set("long", 
		"这个男人身材虽然很瘦，手脚却特别粗大，看样子鬼鬼祟祟，躲躲藏藏的。\n");
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",16);				//设置人物形象
	set("repute", -5000);
	
	set("str", 24);
	set("int", 20);
	set("con", 23);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// 基本内功
	set_skill("huntian_qigong", 250);		// 混天气功
	set_skill("strike", 250);			// 基本掌法
	set_skill("xianglong_zhang", 250);		// 降龙十八掌
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("xiaoyaoyou", 250);			// 逍遥游
	set_skill("parry", 250);			// 基本招架
	set_skill("claw", 250);		      		// 基本爪法
	set_skill("jiuyin_zhua", 250);			// 九阴白骨爪

	map_skill("force", "huntian_qigong");		//设置NPC当前内功为混天气功
	map_skill("claw", "jiuyin_zhua");	        //设置NPC的基本爪法装备九阴白骨爪
	map_skill("dodge", "xiaoyaoyou");		//设置NPC的基本躲闪装备逍遥游
	map_skill("parry", "jiuyin_zhua");		//设置NPC的基本招架装备九阴白骨爪
	map_skill("strike", "xianglong_zhang");		//设置NPC的基本掌法装备降龙十八掌

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

	prepare_skill("claw", "jiuyin_zhua");		//设置NPC的空手组合
	prepare_skill("strike", "xianglong_zhang");
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
		perform_action("force shengang", 0);	//自动神罡
		break;
	case 4:
		perform_action("force recover", 0);	//自动吸气
		break;
	case 5:
		perform_action("force recover", 0);	//自动吸气
		break;
	}	
	return 0;
}

NPC_END;