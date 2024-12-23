// lev1_sasannang.h 沙三娘
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_sasannang);

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
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// 基本内功
	set_skill("huagong_dafa", 190+random(30));			// 化功大法
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("zhaixinggong", 190+random(30));			// 摘星功
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("claw", 190+random(30));			        // 基本爪法
	set_skill("sanyin_wugongzhao", 190+random(30));		// 三阴蜈蚣抓
	set_skill("strike", 190+random(30));			// 基本掌法
	set_skill("chousui_zhang", 190+random(30));		// 抽髓掌
	set_skill("throwing", 190+random(30));		// 基本投掷
	set_skill("feixing_shu", 190+random(30));		// 飞星术

	map_skill("force", "huagong_dafa");		//设置NPC当前内功为化功大法
	map_skill("dodge", "zhaixinggong");		//设置NPC的基本躲闪装备摘星功
	map_skill("parry", "feixing_shu");		//设置NPC的基本招架装备飞星术
	map_skill("claw", "sanyin_wugongzhao");		//设置NPC的基本爪法装备三阴蜈蚣抓
	map_skill("strike", "chousui_duzhang");		//设置NPC的基本掌法装备抽髓掌
	map_skill("throwing", "feixing_shu");		//设置NPC的基本投掷装备飞星术

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 10);			//设置NPC附加攻击力

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
			//自动吸气
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
