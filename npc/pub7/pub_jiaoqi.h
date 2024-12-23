// pub_jiaoqi.h 焦七
//jaja 2002-10-20

NPC_BEGIN(CNpub_jiaoqi);

virtual void create()
{
	set_name("焦七", "lei meng");
	set("title", "霹雳手");
	set("gender", "男性");
	set("age", 66);
	set("level", 100);
	set("long", 
		"这是个乾枯瘦小的小老头，一张乾瘪蜡黄的脸上，长着双小小的叁角眼，留着几根稀疏的山羊胡子，花花的头发，几乎已快掉光了。\n");
	
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",20);				//设置人物形象
	set("repute", -5000);
	
	set("str", 27);
	set("int", 20);
	set("con", 20);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// 基本内功
	set_skill("hunyuan_yiqi", 250);			// 混元一气功
	set_skill("claw", 250);				// 基本爪法
	set_skill("longzhua_gong", 250);		// 龙爪功
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("shaolin_shenfa", 250);		// 少林身法
	set_skill("parry", 250);			// 基本招架
	set_skill("cuff", 250);				// 基本拳法
	set_skill("jingang_quan", 250);			// 大金刚拳

	map_skill("force", "hunyuan_yiqi");		//设置NPC当前内功为混元一气功
	map_skill("cuff", "jingang_quan");	        //设置NPC的基本拳法装备大金刚拳
	map_skill("dodge", "shaolin_shenfa");		//设置NPC的基本躲闪装备少林身法
	map_skill("parry", "jingang_quan");		//设置NPC的基本招架装备大金刚拳
	map_skill("claw", "longzhua_gong");		//设置NPC的基本爪法装备龙爪功

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

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
		perform_action("force recover", 0);	//自动吸气
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

NPC_END;

