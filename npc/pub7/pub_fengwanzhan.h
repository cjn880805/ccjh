// pub_fengwanzhan.h 冯万盏
// jaja 2002-10-20

NPC_BEGIN(CNpub_fengwanzhan);

virtual void create()
{
	set_name("冯万盏", "feng wanzhan");
	set("title", "一杯就倒");
	set("gender", "男性");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",19);				//设置人物形象
	set("repute", 3000);
	
	set("str", 25);
	set("int", 21);
	set("con", 20);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force",250);			// 基本内功
	set_skill("yunlong_shengong",250);		// 云龙神功
	set_skill("claw",250);			// 基本爪法
	set_skill("yunlong_zhua",250);		// 云龙爪
	set_skill("dodge",250);			// 基本躲闪
	set_skill("yunlong_shenfa",250);		// 云龙身法
	set_skill("parry",250);			// 基本招架
	set_skill("sword",250);		        // 基本剑法
	set_skill("yunlong_jian",250);		// 云龙剑法

	map_skill("force", "yunlong_shengong");		//设置NPC当前内功为云龙神功
	map_skill("sword", "yunlong_jian");	        //设置NPC的基本剑法装备云龙剑法
	map_skill("dodge", "yunlong_shenfa");		//设置NPC的基本轻功装备云龙身法
	map_skill("parry", "yunlong_jian");		//设置NPC的基本招架装备反云龙剑法
	map_skill("claw", "yunlong_zhua");		//设置NPC的基本爪法装备云龙爪

	prepare_skill("claw", "yunlong_zhua");	//设置NPC的空手组全

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

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
