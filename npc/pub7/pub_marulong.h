// pub_marulong.h 马如龙
//jaja 2002-10-20

NPC_BEGIN(CNpub_marulong);

virtual void create()
{
	set_name("马如龙", "ma rulong");
	set("title", "病书生");
	set("gender", "男性");
	set("age", 24);
	set("level", 100);
	set("long", 
		"他脸色苍白，仿佛带着病容，但却笑容温和、举止优雅，服饰也极华丽。\n");
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",17);				//设置人物形象
	
	set("str", 22);
	set("int", 22);
	set("con", 22);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// 基本内功
	set_skill("kuihua_xinfa", 250);			// 葵花心法
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("parry", 250);			// 基本招架
	set_skill("sword", 250);			// 基本剑法
	set_skill("pixie_jian", 250);			// 辟邪剑法

	map_skill("force", "kuihua_xinfa");		//设置NPC当前内功为葵花心法
	map_skill("sword", "pixie_jian");	        //设置NPC的基本剑法装备辟邪剑法
	map_skill("dodge", "pixie_jian");		//设置NPC的基本躲闪装备辟邪剑法
	map_skill("parry", "riyue_bian");		//设置NPC的基本招架装备辟邪剑法

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

	prepare_skill("sword", "pixie_jian");		//设置NPC的组合功夫

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword cimu", 1);	//辟邪剑法绝招刺目
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

