// lev1_guyi.h 古一
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_guyi);

virtual void create()
{
	set_name("古一", "gu yi");
	set("title", "簑衣老大");
	set("gender", "男性");
	set("age", 36);
	set("level", 100);
	set("long", 
		"他比他的两个兄弟大出许多年纪，看上去老实巴交，一脸的古板木纳，其实也是一肚坏水。\n");
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",43);				//设置人物形象
	set("repute", -5000);
	
	set("str", 24);
	set("int", 20);
	set("con", 23);
	set("dex", 20);
	
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
	set_skill("staff", 190+random(30));		// 基本杖法
	set_skill("tianshan_zhang", 190+random(30));		// 天山杖法

	map_skill("force", "huagong_dafa");		//设置NPC当前内功为化功大法
	map_skill("dodge", "zhaixinggong");		//设置NPC的基本躲闪装备摘星功
	map_skill("parry", "sanyin_wugongzhao");	//设置NPC的基本招架装备三阴蜈蚣抓
	map_skill("claw", "sanyin_wugongzhao");		//设置NPC的基本爪法装备三阴蜈蚣抓
	map_skill("strike", "chousui_duzhang");		//设置NPC的基本掌法装备抽髓掌
	map_skill("staff", "tianshan_zhang");		//设置NPC的基本杖法装备天山杖法

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 10);			//设置NPC附加攻击力

	prepare_skill("strike", "chousui_duzhang");	//设置NPC空手组合
	prepare_skill("claw", "sanyin_wugongzhao");

	carry_object("gangzhang")->wield();
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("force powerup", 0);	//化功大法(powerup)
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