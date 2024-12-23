// lev1_baoqinguang.h 包清光
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_baoqinguang);

virtual void create()
{
	set_name("包清光", "bao qinguang");
	set("title", "一铺清光");
	set("gender", "男性");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",19);				//设置人物形象
	set("repute", -5000);			//设置NPC好坏
	
	set("str", 22);
	set("int", 24);
	set("con", 23);
	set("dex", 20);
	
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
	set_skill("hand", 190+random(30));		        	// 基本手法
	set_skill("shexing_diaoshou", 190+random(30));		// 蛇形刁手

	map_skill("force", "huntian_qigong");		//设置NPC当前内功为混天气功
	map_skill("strike", "xianglong_zhang");	        //设置NPC的基本掌法装备降龙十八掌
	map_skill("dodge", "xiaoyaoyou");		//设置NPC的基本轻功装备逍遥游
	map_skill("parry", "xianglong_zhang");		//设置NPC的基本招架装备降龙十八掌
	map_skill("hand", "shexing_diaoshou");		//设置NPC的基本手法装备蛇形刁手

	prepare_skill("hand", "shexing_diaoshou");		
	prepare_skill("strike", "xianglong_zhang");	

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 60);			//设置NPC附加攻击力
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("strike leiting", 1);	//降龙十八掌 雷霆一击
		break;
	case 1:
		perform_action("strike xianglong", 1);	//降龙十八掌 降龙大法
		break;
	case 2:
			//自动吸气
		break;
	case 3:
			//自动吸气
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
