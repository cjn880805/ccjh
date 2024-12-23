// pub_nieyinnang.h 聂隐娘
// dieer 2002-7-27

NPC_BEGIN(CNpub_nieyinnang);

virtual void create()
{
	set_name("聂隐娘", "nie yinnang");
	set("title", "三十三剑客之");
	set("gender", "女性");
	set("age", 20);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",2);				//设置人物形象
	set("per",26);
	set("repute", 10000);	
	
	set("str", 35);
	set("int", 34);
	set("con", 31);
	set("dex", 32);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 70);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// 基本内功
	set_skill("linji_zhuang", 350);			// 临济十二庄
	set_skill("strike", 350);			// 基本掌法
	set_skill("jinding_zhang", 350);		// 金顶绵掌
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("zhutian_bu", 350);			// 诸天化身步
	set_skill("parry", 350);			// 基本招架
	set_skill("sword", 350);		        // 基本剑法
	set_skill("huifeng_jian", 350);			// 回风拂柳剑

	map_skill("force", "linji_zhuang");		//设置NPC当前内功为临济十二庄
	map_skill("sword", "huifeng_jian");	        //设置NPC的基本剑法装备回风拂柳剑
	map_skill("dodge", "zhutian_bu");		//设置NPC的基本躲闪装备诸天化身步
	map_skill("parry", "huifeng_jian");		//设置NPC的基本招架装备回风拂柳剑
	map_skill("strike", "jinding_zhang");		//设置NPC的基本掌法装备金顶绵掌

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 60);			//设置NPC附加攻击力

	prepare_skill("strike", "jinding_zhang");

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword mie", 1);		//回风拂柳剑绝招灭剑
		break;
	case 1:
		perform_action("strike bashi", 1);	//金顶绵掌绝招八式合一
		break;
	case 2:
		perform_action("force powerup", 0);	//自动激励
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
