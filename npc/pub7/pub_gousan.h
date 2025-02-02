// pub_gousan.h 勾三
//jaja 2002-10-20

NPC_BEGIN(CNpub_gousan);

virtual void create()
{
	set_name("勾三", "gou san");
	set("title", "簑衣老三");
	set("gender", "男性");
	set("age", 22);
	set("level", 100);
	set("long", 
		"此人是簑衣三兄弟中最小的一个，为人歼险狡诈，三兄弟中最难緾的就是他。\n");
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",43);				//设置人物形象
	set("repute", -5000);
	
	set("str", 24);
	set("int", 20);
	set("con", 23);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// 基本内功
	set_skill("hamagong", 250);			// 蛤蟆功
	set_skill("hand", 250);			// 基本手法
	set_skill("shexing_diaoshou", 250);			// 蛇形刁手
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("chanchu_bufa", 250);			// 蟾蜍步法
	set_skill("parry", 250);			// 基本招架
	set_skill("staff", 250);		        // 基本杖法
	set_skill("lingshe_zhangfa", 250);		// 灵蛇杖法
	set_skill("quanzhen_jian", 250);		// 全真剑法

	map_skill("force", "hamagong");			//设置NPC当前内功为蛤蟆功
	map_skill("staff", "lingshe_zhangfa");	        //设置NPC的基本杖法装备灵蛇杖法
	map_skill("dodge", "chanchu_bufa");		//设置NPC的基本轻功装备蟾蜍步法
	map_skill("parry", "lingshe_zhangfa");		//设置NPC的基本招架装备灵蛇杖法
	map_skill("hand", "shexing_diaoshou");		//设置NPC的基本手法装备蛇形刁手


	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

	carry_object("gangzhang")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("staff pili", 1);	//灵蛇杖法(雷霆霹雳)
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