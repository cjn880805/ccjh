// pub_kunlunnu.h 昆仑奴
// dieer 2002-7-27

NPC_BEGIN(CNpub_kunlunnu);

virtual void create()
{
	set_name("昆仑奴", "kunlun nu");
	set("title", "三十三剑客之");
	set("gender", "男性");
	set("age", 20);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",14);				//设置人物形象
	set("per",10);
	set("shen_type", 1);
	
	set("str", 44);
	set("int", 44);
	set("con", 44);
	set("dex", 44);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 90);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// 基本内功
	set_skill("huntian_qigong", 350);		// 混天气功
	set_skill("strike", 350);			// 基本掌法
	set_skill("xianglong_zhang", 350);		// 降龙十八掌
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("xiaoyaoyou", 350);			// 逍遥游
	set_skill("parry", 350);			// 基本招架
	set_skill("claw", 350);		      		// 基本爪法
	set_skill("jiuyin_zhua", 350);			// 九阴白骨爪

	map_skill("force", "huntian_qigong");		//设置NPC当前内功为混天气功
	map_skill("claw", "jiuyin_zhua");	        //设置NPC的基本爪法装备九阴白骨爪
	map_skill("dodge", "xiaoyaoyou");		//设置NPC的基本躲闪装备逍遥游
	map_skill("parry", "jiuyin_zhua");		//设置NPC的基本招架装备九阴白骨爪
	map_skill("strike", "xianglong_zhang");		//设置NPC的基本掌法装备降龙十八掌

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 100);			//设置NPC附加攻击力

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
