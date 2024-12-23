// lev1_chenmin.h 成明
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_chenmin);

virtual void create()
{
	set_name("成明", "chen min");
	set("title", "浑圆霹雳手");
	set("gender", "男性");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",27);				//设置人物形象
	set("repute", -6000);
	
	set("str", 20);
	set("int", 24);
	set("con", 21);
	set("dex", 26);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 2000000+random(300000));
	set("score", 6000);
	
	set_skill("force", 210+random(30));			// 基本内功
	set_skill("hunyuan_yiqi", 210+random(30));			// 混元一气功
	set_skill("claw", 210+random(30));				// 基本爪法
	set_skill("longzhua_gong", 210+random(30));		// 龙爪功
	set_skill("dodge", 210+random(30));			// 基本躲闪
	set_skill("shaolin_shenfa", 210+random(30));		// 少林身法
	set_skill("parry", 210+random(30));			// 基本招架
	set_skill("cuff", 210+random(30));				// 基本拳法
	set_skill("jingang_quan", 210+random(30));			// 大金刚拳

	map_skill("force", "hunyuan_yiqi");		//设置NPC当前内功为混元一气功
	map_skill("cuff", "jingang_quan");	        //设置NPC的基本拳法装备大金刚拳
	map_skill("dodge", "shaolin_shenfa");		//设置NPC的基本躲闪装备少林身法
	map_skill("parry", "jingang_quan");		//设置NPC的基本招架装备大金刚拳
	map_skill("claw", "longzhua_gong");		//设置NPC的基本爪法装备龙爪功

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 45);			//设置NPC附加攻击力

	prepare_skill("claw", "longzhua_gong");		//设置NPC的组合功夫
	prepare_skill("cuff", "jingang_quan");

}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("cuff jingang", 1);	//大金刚拳(jingang大金刚神通)
		break;
	case 1:
			//自动吸气
		break;
	case 2:
		perform_action("force roar", 1);	//混元一气功佛门狮子吼
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
