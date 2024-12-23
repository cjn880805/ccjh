// lev1_murenjin.h 穆仁净
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_murenjin);

virtual void create()
{
	set_name("穆仁净", "mu renjin");
	set("title", "神剑仙猿");
	set("gender", "男性");
	set("age", 70);
	set("level", 100);
	set("long", 
		"他须眉俱白，红光满面，俨然是一个得道成仙的老神仙。\n");
	set("attitude", "friendly");		//设置NPC态度
	set("icon",19);				//设置人物形象
	set("repute", 6000);
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 50);			//设置NPC加力参数
	
	set("combat_exp", 2000000+random(300000));
	set("score", 6000);
	
	set_skill("force", 220+random(30));			// 基本内功
	set_skill("zixia_shengong", 220+random(30));		// 紫霞神功
	set_skill("strike", 220+random(30));			// 基本掌法
	set_skill("hunyuan_zhang", 220+random(30));		// 混元掌
	set_skill("dodge", 220+random(30));			// 基本躲闪
	set_skill("huashan_shenfa", 220+random(30));		// 华山身法
	set_skill("parry", 220+random(30));			// 基本招架
	set_skill("sword", 220+random(30));		        // 基本剑法
	set_skill("huashan_sword", 220+random(30));		// 华山剑法
	set_skill("fanliangyi_dao", 2970);		// 反两仪刀法

	map_skill("force", "zixia_shengong");		//设置NPC当前内功为紫霞神功
	map_skill("sword", "huashan_sword");	        //设置NPC的基本剑法装备华山剑法
	map_skill("dodge", "huashan_shenfa");		//设置NPC的基本轻工装备华山身法
	map_skill("parry", "fanliangyi_dao");		//设置NPC的基本招架装备反两仪刀法
	map_skill("strike", "hunyuan_zhang");		//设置NPC的基本掌法装备混元掌

	prepare_skill("strike", "hunyuan_zhang");

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 50);			//设置NPC附加攻击力

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword jianzhang", 1);	//华山剑法绝招剑掌五连环
		break;
	case 1:
			//自动吸气
		break;
	case 2:
			//自动吸气
		break;
	case 3:
			//自动吸气
		break;
	case 4:
			//自动吸气
		break;
	case 5:
			//自动吸气
		break;
	}	
	return 0;
}

LEV1_END;
