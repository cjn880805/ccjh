// pub_zhangzhongding.h 张忠定
// dieer 2002-8-10

NPC_BEGIN(CNpub_zhangzhongding);

virtual void create()
{
	set_name("张忠定", "zhang zhongding");
	set("title", "三十三剑客之");
	set("gender", "男性");
	set("age", 30);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",13);				//设置人物形象
	set("per",22);
	
	set("str", 38);
	set("int", 31);
	set("con", 34);
	set("dex", 32);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);

	set_skill("force", 350);			// 基本内功
	set_skill("xiantian_gong", 350);		// 先天神功
	set_skill("sword", 350);			// 基本剑法
	set_skill("quanzhen_jianfa", 350);		// 全真剑法
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("jinyan_gong", 350);			// 金雁功
	set_skill("parry", 350);			// 基本招架
	set_skill("strike", 350);		        // 基本掌法
	set_skill("haotian_zhang", 350);		// 昊天掌

	map_skill("force", "xiantian_gong");		//设置NPC当前内功为先天神功
	map_skill("strike", "haotian_zhang");	        //设置NPC的基本掌法装备昊天掌
	map_skill("dodge", "jinyan_gong");		//设置NPC的基本躲闪装备金雁功
	map_skill("parry", "quanzhen_jianfa");		//设置NPC的基本招架装备全真剑法
	map_skill("sword", "quanzhen_jianfa");		//设置NPC的基本剑法装备全真剑法

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 80);			//设置NPC附加攻击力

	carry_object("changjian")->wield();		//设置NPC装备的物品

}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword sanqing", 1);	//全真剑法(sanqing一剑化三清)
		break;
	case 1:
		perform_action("strike ju", 1);		//昊天掌(ju三花聚顶)
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
