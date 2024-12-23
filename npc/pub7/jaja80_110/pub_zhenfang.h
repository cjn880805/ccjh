// lev2_zhenfang.h 证方大师
// jaja 2002-12-23

LEV2_BEGIN(CNlev2_zhenfang);

virtual void create()
{
	set_name("证方大师", "zhen fang");
	set("title", "我佛慈悲");
	set("gender", "男性");
	set("age", 70);
	set("level", 120);

	set("attitude", "friendly");		//设置NPC态度
	set("icon",27);				//设置人物形象
	set("repute", 8000);
	
	set("str", 26);
	set("int", 29);
	set("con", 27);
	set("dex", 25);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 12000+random(3000));
	set("max_mp", 7000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 6000000+random(6000000));
	set("score", 6000);
	
	set_skill("force", 250+random(30));			// 基本内功
	set_skill("hunyuan_yiqi", 250+random(30));			// 混元一气功
	set_skill("finger", 250+random(30));			// 基本指法
	set_skill("nianhua_zhi", 250+random(30));			// 拈花指
	set_skill("dodge", 250+random(30));			// 基本躲闪
	set_skill("shaolin_shenfa", 250+random(30));		// 少林身法
	set_skill("parry", 250+random(30));			// 基本招架
	set_skill("blade", 250+random(30));		        // 基本刀法
	set_skill("cibei_dao", 250+random(30));			// 慈悲刀

	map_skill("force", "hunyuan_yiqi");		//设置NPC当前内功为混元一气功
	map_skill("blade", "cibei_dao");	     	//设置NPC的基本刀法装备慈悲刀
	map_skill("dodge", "shaolin_shenfa");		//设置NPC的基本躲闪装备少林身法
	map_skill("parry", "cibei_dao");		//设置NPC的基本招架装备慈悲刀
	map_skill("finger", "nianhua_zhi");		//设置NPC的基本指法装备拈花指

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 50);			//设置NPC附加攻击力
	
	prepare_skill("finger", "nianhua_zhi");

	carry_object("mudao")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("force recover", 0);	//自动吸气
		break;
	case 1:
		perform_action("finger foxue", 1);	//拈花指绝招拈花拂穴
		break;
	case 2:
		perform_action("force roar", 1);	//混元一气功佛门狮子吼
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
