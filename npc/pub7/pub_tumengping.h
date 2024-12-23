// pub_tumengping.h 屠梦平
// jaja 2002-10-20

NPC_BEGIN(CNpub_tumengping);

virtual void create()
{
	set_name("屠梦平", "tu mengping");
	set("title", "飞虹剑");
	set("gender", "男性");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",36);				//设置人物形象
	
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
	set_skill("zixia_shengong", 250);		// 紫霞神功
	set_skill("strike", 250);			// 基本掌法
	set_skill("hunyuan_zhang", 250);		// 混元掌
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("huashan_shenfa", 250);		// 华山身法
	set_skill("parry", 250);			// 基本招架
	set_skill("sword", 250);		        // 基本剑法
	set_skill("huashan_sword", 250);		// 华山剑法
	set_skill("fanliangyi_dao", 250);		// 反两仪刀法

	map_skill("force", "zixia_shengong");		//设置NPC当前内功为紫霞神功
	map_skill("sword", "huashan_sword");	        //设置NPC的基本剑法装备华山剑法
	map_skill("dodge", "huashan_shenfa");		//设置NPC的基本轻工装备华山身法
	map_skill("parry", "fanliangyi_dao");		//设置NPC的基本招架装备反两仪刀法
	map_skill("strike", "hunyuan_zhang");		//设置NPC的基本掌法装备混元掌

	prepare_skill("strike", "hunyuan_zhang");

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

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

