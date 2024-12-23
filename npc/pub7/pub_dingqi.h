// pub_dingqi.h 丁弃
// jaja 2002-10-20

NPC_BEGIN(CNpub_dingqi);

virtual void create()
{
	set_name("丁弃", "din qi");
	set("title", "毒菩萨");
	set("gender", "男性");
	set("age", 44);
	set("level", 100);
	set("long", 
		"一个奇形怪状的人，不但鼻子缺了半个，耳朵也被咬得完全不像耳朵，一双眼睛里满布血丝，就像是毒蛇的红信。\n");
	
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",14);				//设置人物形象
	set("repute", -5000);
	
	set("str", 20);
	set("int", 24);
	set("con", 21);
	set("dex", 26);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// 基本内功
	set_skill("huagong_dafa", 250);			// 化功大法
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("zhaixinggong", 250);			// 摘星功
	set_skill("parry", 250);			// 基本招架
	set_skill("claw", 250);			        // 基本爪法
	set_skill("sanyin_wugongzhao", 250);		// 三阴蜈蚣抓
	set_skill("strike", 250);			// 基本掌法
	set_skill("chousui_zhang", 250);		// 抽髓掌

	map_skill("force", "huagong_dafa");		//设置NPC当前内功为化功大法
	map_skill("dodge", "zhaixinggong");		//设置NPC的基本躲闪装备摘星功
	map_skill("parry", "sanyin_wugongzhao");	//设置NPC的基本招架装备三阴蜈蚣抓
	map_skill("claw", "sanyin_wugongzhao");		//设置NPC的基本爪法装备三阴蜈蚣抓
	map_skill("strike", "chousui_duzhang");		//设置NPC的基本掌法装备抽髓掌

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

	prepare_skill("strike", "chousui_duzhang");	//设置NPC空手组合
	prepare_skill("claw", "sanyin_wugongzhao");

}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("force powerup", 0);	//化功大法(powerup)
		break;
	case 1:
		perform_action("strike throw", 1);	//抽髓掌(施毒术)
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