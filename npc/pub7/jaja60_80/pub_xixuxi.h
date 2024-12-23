// lev1_xixuxi.h 希熙玺
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_xixuxi);

virtual void create()
{
	set_name("希熙玺", "xi xusi");
	set("title", "西侍卫总领");
	set("gender", "男性");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",42);				//设置人物形象
	set("repute", -4000);
	
	set("str", 23);
	set("int", 23);
	set("con", 20);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// 基本内功
	set_skill("yunlong_shengong", 190+random(30));		// 云龙神功
	set_skill("claw", 190+random(30));			// 基本爪法
	set_skill("yunlong_zhua", 190+random(30));		// 云龙爪
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("yunlong_shenfa", 190+random(30));		// 云龙身法
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("sword", 190+random(30));		        // 基本剑法
	set_skill("yunlong_jian", 190+random(30));		// 云龙剑法

	map_skill("force", "yunlong_shengong");		//设置NPC当前内功为云龙神功
	map_skill("sword", "yunlong_jian");	        //设置NPC的基本剑法装备云龙剑法
	map_skill("dodge", "yunlong_shenfa");		//设置NPC的基本轻功装备云龙身法
	map_skill("parry", "yunlong_jian");		//设置NPC的基本招架装备反云龙剑法
	map_skill("claw", "yunlong_zhua");		//设置NPC的基本爪法装备云龙爪

	prepare_skill("claw", "yunlong_zhua");	//设置NPC的空手组全

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 10);			//设置NPC附加攻击力

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword xian", 1);	//云龙剑(xian云龙三现)
		break;
	case 1:
			//自动吸气
		break;
	case 2:
			//自动吸气
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
