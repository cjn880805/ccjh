// pub_longyun.h 龙云
//dieer 2002-7-21

NPC_BEGIN(CNpub_longyun);

virtual void create()
{
	set_name("龙云", "long yun");
	set("title", "神龙帮主");
	set("gender", "男性");
	set("age", 35);
	set("level", 157);
	set("long", 
		"这人正是长江“神龙帮”的总瓢把子龙云龙大爷，水性之高，江南第一，据说有一次曾经在水底潜伏了三日三夜，没有人看见他换过气。\n");
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",15);				//设置人物形象
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("chat_chance_combat", 25);		//设置NPC使用绝招的几率
		
	set("max_hp", 40000);
	set("max_mp", 10000);
	set("mp_factor", 80);			//设置NPC加力参数
	
	set("combat_exp", 60000000);
	set("score", 6000);
	
	set_skill("force", 350);			// 基本内功
	set_skill("shedao_qigong", 350);		// 蛇岛气功
	set_skill("shenlong_xinfa", 350);		// 神龙心法
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("yixingbu", 350);			// 意形步
	set_skill("shenlong_bashi", 350);		// 神龙八式
	set_skill("parry", 350);			// 基本招架
	set_skill("strike", 350);		        // 基本掌法
	set_skill("huagu_mianzhang", 350);		// 化骨绵掌

	map_skill("force", "shenlong_xinfa");		//设置NPC当前内功为神龙心法
	map_skill("strike", "huagu_mianzhang");	        //设置NPC的基本掌法法装备化骨绵掌
	map_skill("dodge", "yixingbu");			//设置NPC的基本轻工装备意形步
	map_skill("parry", "shenlong_bashi");		//设置NPC的基本招架装备神龙八式

	prepare_skill("strike", "huagu_mianzhang");	//设置NPC当前使用的技能为掌法组合

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 80);			//设置NPC附加攻击力
	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(3))
	{
	case 0:
		perform_action("parry yingxiong", 1);	//英雄三式
		break;
        case 1:
		perform_action("force recover", 0);	//自动吸气
		break;
        case 2:
		perform_action("force recover", 0);	//自动吸气
		break;
	}	
	return 0;
}

NPC_END;
