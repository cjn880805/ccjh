// lev1_wufa.h 无法道人
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_wufa);

virtual void create()
{
	set_name("无法道人", "wu fa");
	set("title", "无法无天");
	set("gender", "男性");
	set("age", 70);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",30);				//设置人物形象
	set("repute", -5000);
	
	set("str", 23);
	set("int", 23);
	set("con", 20);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// 基本内功
	set_skill("xiantian_gong", 190+random(30));		// 先天神功
	set_skill("sword", 190+random(30));			// 基本剑法
	set_skill("quanzhen_jianfa", 190+random(30));		// 全真剑法
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("jinyan_gong", 190+random(30));			// 金雁功
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("strike", 190+random(30));		        // 基本掌法
	set_skill("haotian_zhang", 190+random(30));		// 昊天掌

	map_skill("force", "xiantian_gong");		//设置NPC当前内功为先天神功
	map_skill("strike", "haotian_zhang");	        //设置NPC的基本掌法装备昊天掌
	map_skill("dodge", "jinyan_gong");		//设置NPC的基本躲闪装备金雁功
	map_skill("parry", "quanzhen_jianfa");		//设置NPC的基本招架装备全真剑法
	map_skill("sword", "quanzhen_jianfa");		//设置NPC的基本剑法装备全真剑法
	
	prepare_skill("strike", "haotian_zhang");

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 10);			//设置NPC附加攻击力

	carry_object("changjian")->wield();		//设置NPC装备的物品
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword sanqing", 1);	//全真剑法(sanqing一剑化三清)
		break;
	case 1:
		perform_action("strike ju", 1);		//昊天掌(ju三花聚顶)
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
