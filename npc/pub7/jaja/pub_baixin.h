//pub_baixin.h 白星
//dieer 2002-7-21

NPC_BEGIN(CNpub_baixin);

virtual void create()
{
	set_name("白星", "bai xin");
	set("title", "白蜡烛");
	set("gender", "男性");
	set("age", 24);
	set("level", 157);
	set("long", 
		"他的皮肤很白，在灯光下看来，简直白得像透明，可以看到里面的血脉骨骼，这种白虽然是病态，却又带着种说不出的奇异魅力。\n");
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",17);				//设置人物形象
	
	set("str", 34);
	set("int", 35);
	set("con", 35);
	set("dex", 34);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 40000);
	set("max_mp", 10000);
	set("mp_factor", 20);			//设置NPC加力参数
	
	set("combat_exp", 60000000);
	set("score", 6000);
	
	set_skill("force", 350);			// 基本内功
	set_skill("zixia_shengong", 350);		// 紫霞神功
	set_skill("strike", 350);			// 基本掌法
	set_skill("hunyuan_zhang", 350);		// 混元掌
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("huashan_shenfa", 350);		// 华山身法
	set_skill("parry", 350);			// 基本招架
	set_skill("sword", 350);		        // 基本剑法
	set_skill("huashan_sword", 350);		// 华山剑法
	set_skill("fanliangyi_dao", 350);		// 反两仪刀法

	map_skill("force", "zixia_shengong");		//设置NPC当前内功为紫霞神功
	map_skill("sword", "huashan_sword");	        //设置NPC的基本剑法装备华山剑法
	map_skill("dodge", "huashan_shenfa");		//设置NPC的基本轻工装备华山身法
	map_skill("parry", "fanliangyi_dao");		//设置NPC的基本招架装备反两仪刀法
	map_skill("strike", "hunyuan_zhang");		//设置NPC的基本掌法装备混元掌

	prepare_skill("sword", "huashan_sword");	//设置NPC当前使用的技能
	prepare_skill("parry", "fanliangyi_dao");
	prepare_skill("strike", "hunyuan_zhang");

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 20);			//设置NPC附加攻击力

	carry_object("sword_1")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword jianzhang", 1);	//华山剑法绝招剑掌五连环
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
