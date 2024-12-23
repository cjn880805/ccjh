// pub_.h 辉月
//jaja 2002-10-20

NPC_BEGIN(CNpub_huiyue);

virtual void create()
{
	set_name("辉月", "yui yue");
	set("title", "圣火使者");
	set("gender", "女性");
	set("age", 36);
	set("level", 100);

	set("attitude", "friendly");		//设置NPC态度
	set("icon",6);				//设置人物形象
	
	set("str", 27);
	set("int", 20);
	set("con", 20);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// 基本内功
	set_skill("shenghuo_shengong", 250);		// 圣火神功
	set_skill("shenghuo_xinfa", 250);		// 圣火心法
	set_skill("finger", 250);			// 基本指法
	set_skill("xuantian_zhi", 250);			// 玄天无情指
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("qingfu_shenfa", 250);		// 青蝠身法
	set_skill("parry", 250);			// 基本招架
	set_skill("lingfa", 250);		        // 基本令法
	set_skill("shenghuo_lingfa", 250);		// 圣火令法

	map_skill("force", "shenghuo_shengong");	//设置NPC当前内功为圣火神功
	map_skill("lingfa", "shenghuo_lingfa");	        //设置NPC的基本令法装备圣火令法
	map_skill("dodge", "qingfu_shenfa");		//设置NPC的基本躲闪装备青蝠身法
	map_skill("parry", "shenghuo_lingfa");		//设置NPC的基本招架装备圣火令法
	map_skill("finger", "xuantian_zhi");		//设置NPC的基本指法装备玄天无情指

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力
	
	prepare_skill("finger", "xuantian_zhi");

	carry_object("shenghuo_ling")->wield();
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("lingfa xiyanling", 1);	//圣火令法(xiyanling「吸焰」令)
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