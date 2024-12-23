// pub_weiyangyu.h 维扬河街上臾
// dieer 2002-8-5

NPC_BEGIN(CNpub_weiyangyu);

virtual void create()
{
	set_name("维扬河街上臾", "weiyang yu");
	set("title", "三十三剑客之");
	set("gender", "男性");
	set("age", 70);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",19);				//设置人物形象
	set("per",18);
	set("repute", 10000);
	
	set("str", 36);
	set("int", 33);
	set("con", 36);
	set("dex", 33);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// 基本内功
	set_skill("xuantian_shengong", 350);		// 玄天神功
	set_skill("finger", 350);			// 基本指法
	set_skill("xuantian_zhi", 350);			// 玄天无情指
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("qingfu_shenfa", 350);		// 青蝠身法
	set_skill("parry", 350);			// 基本招架
	set_skill("blade", 350);		        // 基本刀法
	set_skill("wuyue_blade", 350);			// 巫月刀法

	map_skill("force", "xuantian_shengong");	//设置NPC当前内功为玄天神功
	map_skill("blade", "wuyue_blade");	        //设置NPC的基本刀法装备巫月刀法
	map_skill("dodge", "qingfu_shenfa");		//设置NPC的基本躲闪装备青蝠身法
	map_skill("parry", "wuyue_blade");		//设置NPC的基本招架装备巫月刀法
	map_skill("finger", "xuantian_zhi");		//设置NPC的基本指法装备玄天无情指

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 60);			//设置NPC附加攻击力

	carry_object("gangdao")->wield();

	prepare_skill("finger", "xuantian_zhi");
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("blade jiao", 1);	//巫月刀法(jiao铰字诀)
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
