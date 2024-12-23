// pub_dongmengqin.h 东门庆
// jaja 2002-10-20

NPC_BEGIN(CNpub_dongmengqin);

virtual void create()
{
	set_name("东门庆", "dong mengqin");
	set("title", "妓院老板");
	set("gender", "男性");
	set("age", 40);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",15);				//设置人物形象
	set("repute", -5000);
	
	set("str", 25);
	set("int", 21);
	set("con", 20);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// 基本内功
	set_skill("taixuan_gong", 250);			// 侠客岛太玄功
	set_skill("strike", 250);			// 基本掌法
	set_skill("lovestrike", 250);			// 戏花掌
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("shenxing_baibian", 250);		// 神行百变
	set_skill("parry", 250);			// 基本招架
	set_skill("sword", 250);		        // 基本剑法
	set_skill("songshan_sword", 250);		// 嵩山剑法

	map_skill("force", "taixuan_gong");		//设置NPC当前内功为侠客岛太玄功
	map_skill("sword", "songshan_sword");	        //设置NPC的基本剑法装备嵩山剑法
	map_skill("dodge", "shenxing_baibian");		//设置NPC的基本轻功装备神行百变
	map_skill("parry", "songshan_sword");		//设置NPC的基本招架装备嵩山剑法
	map_skill("strike", "lovestrike");		//设置NPC的基本掌法装备戏花掌

	prepare_skill("strike", "lovestrike");		//设置NPC的空手组全	

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

	carry_object("zheshan")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("force recover", 0);	//自动吸气
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
