// lev2_gongsundanang.h 公孙大娘
// jaja 2002-12-16

LEV2_BEGIN(CNlev2_gongsundanang);

virtual void create()
{
	set_name("公孙大娘", "gongsun danang");
	set("title", "舞剑隹人");
	set("gender", "女性");
	set("age", 20);
	set("level", 130);

	set("icon",2);				//设置人物形象
	set("per",36);
	
	set("str", 30);
	set("int", 28);
	set("con", 29);
	set("dex", 29);
	set("repute", 8000);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 15000+random(5000));
	set("max_mp", 8000);
	set("mp_factor", 50);			//设置NPC加力参数
	
	set("combat_exp", 20000000+random(10000000));
	set("score", 6000);

	set_skill("force", 250+random(50));			// 基本内功
	set_skill("linji_zhuang", 250+random(50));			// 临济十二庄
	set_skill("strike", 250+random(50));			// 基本掌法
	set_skill("jinding_zhang", 250+random(50));		// 金顶绵掌
	set_skill("dodge", 250+random(50));			// 基本躲闪
	set_skill("zhutian_bu", 250+random(50));			// 诸天化身步
	set_skill("parry", 250+random(50));			// 基本招架
	set_skill("sword", 250+random(50));		        // 基本剑法
	set_skill("huifeng_jian", 250+random(50));			// 回风拂柳剑

	map_skill("force", "linji_zhuang");		//设置NPC当前内功为临济十二庄
	map_skill("sword", "huifeng_jian");	        //设置NPC的基本剑法装备回风拂柳剑
	map_skill("dodge", "zhutian_bu");		//设置NPC的基本躲闪装备诸天化身步
	map_skill("parry", "huifeng_jian");		//设置NPC的基本招架装备回风拂柳剑
	map_skill("strike", "jinding_zhang");		//设置NPC的基本掌法装备金顶绵掌

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

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

LEV2_END;