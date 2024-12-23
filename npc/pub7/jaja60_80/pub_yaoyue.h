// lev1_yaoyue.h 妖月
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_yaoyue);

virtual void create()
{
	set_name("妖月", "yao yue");
	set("title", "落花宫主");
	set("gender", "女性");
	set("age", 40);
	set("level", 100);

	set("attitude", "friendly");		//设置NPC态度
	set("icon",2);				//设置人物形象
	set("repute", -5000);
	
	set("str", 21);
	set("int", 23);
	set("con", 23);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 2100000+random(300000));
	set("score", 6000);
	
	set_skill("force", 210+random(30));			// 基本内功
	set_skill("shedao_qigong", 210+random(30));		// 蛇岛气功
	set_skill("shenlong_xinfa", 210+random(30));		// 神龙心法
	set_skill("dodge", 210+random(30));			// 基本躲闪
	set_skill("yixingbu", 210+random(30));			// 意形步
	set_skill("shenlong_bashi", 210+random(30));		// 神龙八式
	set_skill("parry", 210+random(30));			// 基本招架
	set_skill("strike", 210+random(30));		        // 基本掌法
	set_skill("huagu_mianzhang", 210+random(30));		// 化骨绵掌

	map_skill("force", "shenlong_xinfa");		//设置NPC当前内功为神龙心法
	map_skill("strike", "huagu_mianzhang");	        //设置NPC的基本掌法法装备化骨绵掌
	map_skill("dodge", "yixingbu");			//设置NPC的基本轻工装备意形步
	map_skill("parry", "shenlong_bashi");		//设置NPC的基本招架装备神龙八式

	prepare_skill("strike", "huagu_mianzhang");	//设置NPC当前使用的技能为掌法组合

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 60);			//设置NPC附加攻击力
	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(3))
	{
	case 0:
		perform_action("parry meiren", 1);	//美人三招
		break;
        case 1:
			//自动吸气
		break;
        case 2:
			//自动吸气
		break;
	}	
	return 0;
}

LEV1_END;