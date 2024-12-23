// pub_xiexunfu.h 解洵妇
// dieer 2002-8-10

NPC_BEGIN(CNpub_xiexunfu);

virtual void create()
{
	set_name("解洵妇", "xiexun fu");
	set("title", "三十三剑客之");
	set("gender", "女性");
	set("age", 20);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",3);				//设置人物形象
	set("per",20);
	
	set("str", 31);
	set("int", 33);
	set("con", 36);
	set("dex", 31);
	set("repute", 10000);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);

	set_skill("force", 350);			// 基本内功
	set_skill("linji_zhuang", 350);			// 临济十二庄
	set_skill("strike", 350);			// 基本掌法
	set_skill("jinding_zhang", 350);		// 金顶绵掌
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("zhutian_bu", 350);			// 诸天化身步
	set_skill("parry", 350);			// 基本招架
	set_skill("finger", 350);		        // 基本指法
	set_skill("tiangang_zhi", 350);			// 天罡指穴法

	map_skill("force", "linji_zhuang");		//设置NPC当前内功为临济十二庄
	map_skill("finger", "tiangang_zhi");	        //设置NPC的基本指法装备天罡指穴法
	map_skill("dodge", "zhutian_bu");		//设置NPC的基本躲闪装备诸天化身步
	map_skill("parry", "tiangang_zhi");		//设置NPC的基本招架装备天罡指穴法
	map_skill("strike", "jinding_zhang");		//设置NPC的基本掌法装备金顶绵掌

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 60);			//设置NPC附加攻击力

	prepare_skill("strike", "jinding_zhang");
	prepare_skill("finger", "tiangang_zhi");
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("finger lingkong", 1);	//天罡指穴法(lingkong凌空指穴)
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