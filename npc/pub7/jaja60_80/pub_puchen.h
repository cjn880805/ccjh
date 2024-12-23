// lev1_puchen.h 普尘师太
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_puchen);

virtual void create()
{
	set_name("普尘师太", "pu chen");
	set("title", "南海神尼");
	set("gender", "女性");
	set("age", 90);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",21);				//设置人物形象
	set("repute", 6000);
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 2200000+random(300000));
	set("score", 6000);
	
	set_skill("force", 210+random(30));			// 基本内功
	set_skill("linji_zhuang", 210+random(30));			// 临济十二庄
	set_skill("strike", 210+random(30));			// 基本掌法
	set_skill("jinding_zhang", 210+random(30));		// 金顶绵掌
	set_skill("dodge", 210+random(30));			// 基本躲闪
	set_skill("zhutian_bu", 210+random(30));			// 诸天化身步
	set_skill("parry", 210+random(30));			// 基本招架
	set_skill("sword", 210+random(30));		        // 基本剑法
	set_skill("huifeng_jian", 210+random(30));			// 回风拂柳剑

	map_skill("force", "linji_zhuang");		//设置NPC当前内功为临济十二庄
	map_skill("sword", "huifeng_jian");	        //设置NPC的基本剑法装备回风拂柳剑
	map_skill("dodge", "zhutian_bu");		//设置NPC的基本躲闪装备诸天化身步
	map_skill("parry", "huifeng_jian");		//设置NPC的基本招架装备回风拂柳剑
	map_skill("strike", "jinding_zhang");		//设置NPC的基本掌法装备金顶绵掌

	set("apply/armor", 130);			//设置NPC附加防御力
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

