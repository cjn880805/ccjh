// lev1_.h 辉月
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_huiyue);

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
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// 基本内功
	set_skill("shenghuo_shengong", 190+random(30));		// 圣火神功
	set_skill("shenghuo_xinfa", 190+random(30));		// 圣火心法
	set_skill("finger", 190+random(30));			// 基本指法
	set_skill("xuantian_zhi", 190+random(30));			// 玄天无情指
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("qingfu_shenfa", 190+random(30));		// 青蝠身法
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("lingfa", 190+random(30));		        // 基本令法
	set_skill("shenghuo_lingfa", 190+random(30));		// 圣火令法

	map_skill("force", "shenghuo_shengong");	//设置NPC当前内功为圣火神功
	map_skill("lingfa", "shenghuo_lingfa");	        //设置NPC的基本令法装备圣火令法
	map_skill("dodge", "qingfu_shenfa");		//设置NPC的基本躲闪装备青蝠身法
	map_skill("parry", "shenghuo_lingfa");		//设置NPC的基本招架装备圣火令法
	map_skill("finger", "xuantian_zhi");		//设置NPC的基本指法装备玄天无情指

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 10);			//设置NPC附加攻击力
	
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