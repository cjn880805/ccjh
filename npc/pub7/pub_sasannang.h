// pub_sasannang.h 沙三娘
// jaja 2002-10-20

NPC_BEGIN(CNpub_sasannang);

virtual void create()
{
	set_name("沙三娘", "sa sannang");
	set("title", "漠北三煞之飞沙煞");
	set("gender", "女性");
	set("age", 50);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",21);				//设置人物形象
	set("repute", -5000);
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// 基本内功
	set_skill("huagong_dafa", 250);			// 化功大法
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("zhaixinggong", 250);			// 摘星功
	set_skill("parry", 250);			// 基本招架
	set_skill("claw", 250);			        // 基本爪法
	set_skill("sanyin_wugongzhao", 250);		// 三阴蜈蚣抓
	set_skill("strike", 250);			// 基本掌法
	set_skill("chousui_zhang", 250);		// 抽髓掌
	set_skill("throwing", 250);		// 基本投掷
	set_skill("feixing_shu", 250);		// 飞星术

	map_skill("force", "huagong_dafa");		//设置NPC当前内功为化功大法
	map_skill("dodge", "zhaixinggong");		//设置NPC的基本躲闪装备摘星功
	map_skill("parry", "feixing_shu");		//设置NPC的基本招架装备飞星术
	map_skill("claw", "sanyin_wugongzhao");		//设置NPC的基本爪法装备三阴蜈蚣抓
	map_skill("strike", "chousui_duzhang");		//设置NPC的基本掌法装备抽髓掌
	map_skill("throwing", "feixing_shu");		//设置NPC的基本投掷装备飞星术

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

	prepare_skill("strike", "chousui_duzhang");	//设置NPC空手组合
	prepare_skill("claw", "sanyin_wugongzhao");

	carry_object("yaoqin");
	carry_object("kuihuazhen", 100)->wield();
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("force powerup", 1);	//化功大法(powerup)
		break;
	case 1:
		perform_action("force recover", 0);	//自动吸气
		break;
	case 2:
		perform_action("force recover", 0);	//自动吸气
		break;
	case 3:
		perform_action("force recover", 0);	//自动吸气
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
