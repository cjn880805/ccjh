// pub_hongzhoushushen.h 洪州书生
// dieer 2002-8-10

NPC_BEGIN(CNpub_hongzhoushushen);

virtual void create()
{
	set_name("洪州书生", "hongzhou shushen");
	set("title", "三十三剑客之");
	set("gender", "男性");
	set("age", 20);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",15);				//设置人物形象
	set("per",20);
	
	set("str", 32);
	set("int", 32);
	set("con", 33);
	set("dex", 35);
	set("repute", 10000);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);

	set_skill("force", 350);			// 基本内功
	set_skill("shenghuo_shengong", 350);		// 圣火神功
	set_skill("shenghuo_xinfa", 350);		// 圣火心法
	set_skill("finger", 350);			// 基本指法
	set_skill("xuantian_zhi", 350);			// 玄天无情指
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("qingfu_shenfa", 350);		// 青蝠身法
	set_skill("parry", 350);			// 基本招架
	set_skill("lingfa", 350);		        // 基本令法
	set_skill("shenghuo_lingfa", 350);		// 圣火令法

	map_skill("force", "shenghuo_shengong");	//设置NPC当前内功为圣火神功
	map_skill("lingfa", "Shenghuo_lingfa");	        //设置NPC的基本令法装备圣火令法
	map_skill("dodge", "qingfu_shenfa");		//设置NPC的基本躲闪装备青蝠身法
	map_skill("parry", "Shenghuo_lingfa");		//设置NPC的基本招架装备圣火令法
	map_skill("finger", "xuantian_zhi");		//设置NPC的基本指法装备玄天无情指

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 50);			//设置NPC附加攻击力
	
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