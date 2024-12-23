// pub_changhentian.h 常恨天
// jaja 2002-10-20

NPC_BEGIN(CNpub_changhentian);

virtual void create()
{
	set_name("常恨天", "chang hentian");
	set("title", "易天而行");
	set("gender", "男性");
	set("age", 40);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",14);				//设置人物形象
	set("repute", 5000);			
	
	set("str", 22);
	set("int", 24);
	set("con", 23);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// 基本内功
	set_skill("huagong_dafa", 250);			// 化功大法
	set_skill("strike", 250);			// 基本掌法
	set_skill("chousui_zhang", 250);		// 抽髓掌
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("zhaixinggong", 250);			// 摘星功
	set_skill("parry", 250);			// 基本招架
	set_skill("staff", 250);		        // 基本杖法
	set_skill("tianshan_zhang", 250);		// 天山杖法
	set_skill("fanliangyi_dao", 250);		// 反两仪刀法

	map_skill("force", "huagong_dafa");		//设置NPC当前内功为化功大法
	map_skill("staff", "tianshan_zhang");	        //设置NPC的基本杖法装备天山杖法
	map_skill("dodge", "zhaixinggong");		//设置NPC的基本轻功装备摘星功
	map_skill("parry", "tianshan_zhang");		//设置NPC的基本招架装备天山杖法
	map_skill("strike", "chousui_zhang");		//设置NPC的基本掌法装备抽髓掌

	prepare_skill("strike", "chousui_duzhang");	//设置NPC的空手组全

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

	carry_object("gangzhang")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("strike throw", 1);	//抽髓掌(throw施毒术)
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
