// pub_yixia.h 义侠
// dieer 2002-8-10

NPC_BEGIN(CNpub_yixia);

virtual void create()
{
	set_name("义侠", "yi xia");
	set("title", "三十三剑客之");
	set("gender", "男性");
	set("age", 30);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",15);				//设置人物形象
	set("per",15);
	
	set("str", 37);
	set("int", 33);
	set("con", 36);
	set("dex", 31);
	set("repute", 10000);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);

	set_skill("force", 350);			// 基本内功
	set_skill("hunyuan_yiqi", 350);			// 混元一气功
	set_skill("finger", 350);			// 基本指法
	set_skill("nianhua_zhi", 350);			// 拈花指
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("shaolin_shenfa", 350);		// 少林身法
	set_skill("parry", 350);			// 基本招架
	set_skill("club", 350);			        // 基本棍法
	set_skill("zui_gun", 350);			// 醉棍

	map_skill("force", "hunyuan_yiqi");		//设置NPC当前内功为混元一气功
	map_skill("club", "zui_gun");	     		//设置NPC的基本棍法装备醉棍
	map_skill("dodge", "shaolin_shenfa");		//设置NPC的基本躲闪装备少林身法
	map_skill("parry", "zui_gun");			//设置NPC的基本招架装备醉棍
	map_skill("finger", "nianhua_zhi");		//设置NPC的基本指法装备拈花指

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 120);			//设置NPC附加攻击力

	carry_object("mugun")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("whip zuida", 1);	//少林醉棍(zuida八仙醉打)
		break;
	case 1:
		perform_action("finger foxue", 1);	//拈花指绝招拈花拂穴
		break;
	case 2:
		perform_action("force roar", 1);	//混元一气功佛门狮子吼
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
