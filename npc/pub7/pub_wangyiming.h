// pub_wangyiming.h 汪一鸣
// jaja 2002-10-20

NPC_BEGIN(CNpub_wangyiming);

virtual void create()
{
	set_name("汪一鸣", "wang yiming");
	set("title", "河朔双剑");
	set("gender", "男性");
	set("age", 40);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",14);				//设置人物形象
	
	set("str", 23);
	set("int", 23);
	set("con", 20);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// 基本内功
	set_skill("hunyuan_yiqi", 250);			// 混元一气功
	set_skill("finger", 250);			// 基本指法
	set_skill("nianhua_zhi", 250);			// 拈花指
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("shaolin_shenfa", 250);		// 少林身法
	set_skill("parry", 250);			// 基本招架
	set_skill("sword", 250);		        // 基本剑法
	set_skill("damo_jian", 250);			// 达摩剑

	map_skill("force", "hunyuan_yiqi");		//设置NPC当前内功为混元一气功
	map_skill("sword", "damo_jian");	        //设置NPC的基本剑法装备达摩剑
	map_skill("dodge", "shaolin_shenfa");		//设置NPC的基本躲闪装备少林身法
	map_skill("parry", "damo_jian");		//设置NPC的基本招架装备达摩剑
	map_skill("finger", "nianhua_zhi");		//设置NPC的基本指法装备拈花指
	
	prepare_skill("finger", "nianhua_zhi");

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

	carry_object("changjian")->wield();
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword sanjue", 1);	//达摩剑(sanjue达摩三绝剑)
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
