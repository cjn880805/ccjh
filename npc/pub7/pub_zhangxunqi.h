// pub_zhangxunqi.h 张训妻
// dieer 2002-8-10

NPC_BEGIN(CNpub_zhangxunqi);

virtual void create()
{
	set_name("张训妻", "zhangxun qi");
	set("title", "三十三剑客之");
	set("gender", "女性");
	set("age", 20);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",7);				//设置人物形象
	set("per",16);
	
	set("str", 32);
	set("int", 24);
	set("con", 39);
	set("dex", 37);
	set("repute", -10000);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);

	set_skill("force", 350);			// 基本内功
	set_skill("huagong_dafa", 350);			// 化功大法
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("zhaixinggong", 350);			// 摘星功
	set_skill("parry", 350);			// 基本招架
	set_skill("claw", 350);			        // 基本爪法
	set_skill("sanyin_wugongzhao", 350);		// 三阴蜈蚣抓
	set_skill("strike", 350);			// 基本掌法
	set_skill("chousui_zhang", 350);		// 抽髓掌

	map_skill("force", "huagong_dafa");		//设置NPC当前内功为化功大法
	map_skill("dodge", "zhaixinggong");		//设置NPC的基本躲闪装备摘星功
	map_skill("parry", "sanyin_wugongzhao");	//设置NPC的基本招架装备三阴蜈蚣抓
	map_skill("claw", "sanyin_wugongzhao");		//设置NPC的基本爪法装备三阴蜈蚣抓
	map_skill("strike", "chousui_duzhang");		//设置NPC的基本掌法装备抽髓掌

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 80);			//设置NPC附加攻击力

	prepare_skill("strike", "chousui_duzhang");	//设置NPC空手组合
	prepare_skill("claw", "sanyin_wugongzhao");

}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("force powerup", 0);	//化功大法(powerup)
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
