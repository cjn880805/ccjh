// pub_liguishou.h 李龟寿
// dieer 2002-8-5

NPC_BEGIN(CNpub_liguishou);

virtual void create()
{
	set_name("李龟寿", "li guishou");
	set("title", "三十三剑客之");
	set("gender", "无性");
	set("age", 30);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",44);				//设置人物形象
	set("per",15);
	set("repute", -10000);
	
	set("str", 34);
	set("int", 34);
	set("con", 34);
	set("dex", 34);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// 基本内功
	set_skill("kuihua_xinfa", 350);			// 葵花心法
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("parry", 350);			// 基本招架
	set_skill("sword", 350);			// 基本剑法
	set_skill("pixie_jian", 350);			// 辟邪剑法

	map_skill("force", "kuihua_xinfa");		//设置NPC当前内功为葵花心法
	map_skill("sword", "pixie_jian");	        //设置NPC的基本剑法装备辟邪剑法
	map_skill("dodge", "pixie_jian");		//设置NPC的基本躲闪装备辟邪剑法
	map_skill("parry", "riyue_bian");		//设置NPC的基本招架装备辟邪剑法

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 50);			//设置NPC附加攻击力

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
