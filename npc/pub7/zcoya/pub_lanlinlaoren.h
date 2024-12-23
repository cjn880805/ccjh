// pub_lanlinlaoren.h 兰陵老人
// dieer 2002-7-29

NPC_BEGIN(CNpub_lanlinlaoren);

virtual void create()
{
	set_name("兰陵老人", "lanlin laoren");
	set("title", "三十三剑客之");
	set("gender", "男性");
	set("age", 60);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",19);				//设置人物形象
	set("per",25);	
	set("shen_type", 1);			//设置NPC好坏
	
	set("str", 40);
	set("int", 42);
	set("con", 45);
	set("dex", 41);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 100);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// 基本内功
	set_skill("zixia_shengong", 350);		// 紫霞神功
	set_skill("strike", 350);			// 基本掌法
	set_skill("hunyuan_zhang", 350);		// 混元掌
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("huashan_shenfa", 350);		// 华山身法
	set_skill("parry", 350);			// 基本招架
	set_skill("sword", 350);			// 基本剑法
	set_skill("lonely_sword", 350);			// 独孤九剑

	map_skill("force", "zixia_shengong");		//设置NPC当前内功为紫霞神功
	map_skill("strike", "hunyuan_zhang");	        //设置NPC的基本掌法为混元掌
	map_skill("dodge", "huashan_shenfa");		//设置NPC的基本躲闪装备华山身法
	map_skill("parry", "lonely_sword");		//设置NPC的基本招架装备独孤九剑
	map_skill("sword", "lonely_sword");		//设置NPC的基本剑法装备独孤九剑

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 40);			//设置NPC附加攻击力

	prepare_skill("strike", "hunyuan_zhang");

	carry_object("changjian")->wield();	

}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword pojian", 1);	//独孤九剑破剑
		break;
	case 1:
		perform_action("sword poqi", 1);	//独孤九剑破气
		break;
	case 2:
		perform_action("sword pozhang", 1);	//独孤九剑破杖
		break;
	case 3:
		perform_action("strike wuji", 1);	//混元掌(wuji混元无极)
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
