// lev1_ruanjiao.h 阮鲛
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_ruanjiao);

virtual void create()
{
	set_name("阮鲛", "ruan jiao");
	set("title", "水蛇");
	set("gender", "男性");
	set("age", 31);
	set("level", 100);
	set("long", 
		"神龙帮二帮主，身材不高，简直可说是瘦小枯干，脸上黄一块，白一块，仿佛长了满脸的白癣，一双眼睛里也布满了红丝，全无神采。\n");
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",14);				//设置人物形象
	set("repute", 4000);
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// 基本内功
	set_skill("shedao_qigong", 190+random(30));		// 蛇岛气功
	set_skill("shenlong_xinfa", 190+random(30));		// 神龙心法
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("yixingbu", 190+random(30));			// 意形步
	set_skill("shenlong_bashi", 190+random(30));		// 神龙八式
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("strike", 190+random(30));		        // 基本掌法
	set_skill("huagu_mianzhang", 190+random(30));		// 化骨绵掌

	map_skill("force", "shenlong_xinfa");		//设置NPC当前内功为神龙心法
	map_skill("strike", "huagu_mianzhang");	        //设置NPC的基本掌法法装备化骨绵掌
	map_skill("dodge", "yixingbu");			//设置NPC的基本轻工装备意形步
	map_skill("parry", "shenlong_bashi");		//设置NPC的基本招架装备神龙八式

	prepare_skill("strike", "huagu_mianzhang");	//设置NPC当前使用的技能为掌法组合

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 10);			//设置NPC附加攻击力
	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(3))
	{
	case 0:
		perform_action("parry yingxiong", 1);	//英雄三式
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
