// pub_xiuzhoucike.h 秀州刺客
// dieer 2002-8-10

NPC_BEGIN(CNpub_xiuzhoucike);

virtual void create()
{
	set_name("秀州刺客", "xiuzhou cike");
	set("title", "三十三剑客之");
	set("gender", "男性");
	set("age", 30);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",17);				//设置人物形象
	set("per",23);
	
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
	set_skill("kurong_changong", 350);		// 枯荣禅功
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("tiannan_step", 350);			// 天南步法
	set_skill("parry", 350);			// 基本招架
	set_skill("finger", 350);		        // 基本指法
	set_skill("liumai_shenjian", 350);		// 六脉神剑

	map_skill("force", "kurong_changong");		//设置NPC当前内功为枯荣禅功
	map_skill("dodge", "tiannan_step");		//设置NPC的基本躲闪装备天南步法
	map_skill("parry", "liumai_shenjian");		//设置NPC的基本招架装备六脉神剑
	map_skill("finger", "liumai_shenjian");		//设置NPC的基本指法装备六脉神剑

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 80);			//设置NPC附加攻击力

	prepare_skill("finger", "liumai_shenjian");

}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("finger ci", 1);		//六脉神剑(ci刺)
		break;
	case 1:
		perform_action("finger feng", 1);	//六脉神剑(feng封)
		break;
	case 2:
		perform_action("finger tan", 1);	//六脉神剑(tan弹)
		break;
	case 3:
		perform_action("finger guiyi", 1);	//六脉神剑(guiyi六脉归一)
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
