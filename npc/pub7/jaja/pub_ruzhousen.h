// pub_ruzhousen.h 汝州僧
// dieer 2002-7-27

NPC_BEGIN(CNpub_ruzhousen);

virtual void create()
{
	set_name("汝州僧", "ruzhou sen");
	set("title", "三十三剑客之");
	set("gender", "男性");
	set("age", 30);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",27);				//设置人物形象
	set("per",20);	
	set("repute", 10000);			//设置NPC好坏
	
	set("str", 34);
	set("int", 37);
	set("con", 34);
	set("dex", 36);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 70);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// 基本内功
	set_skill("hunyuan_yiqi", 350);			// 混元一气功
	set_skill("claw", 350);				// 基本爪法
	set_skill("longzhua_gong", 350);		// 龙爪功
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("shaolin_shenfa", 350);		// 少林身法
	set_skill("parry", 350);			// 基本招架
	set_skill("cuff", 350);				// 基本拳法
	set_skill("jingang_quan", 350);			// 大金刚拳

	map_skill("force", "hunyuan_yiqi");		//设置NPC当前内功为混元一气功
	map_skill("cuff", "jingang_quan");	        //设置NPC的基本拳法装备大金刚拳
	map_skill("dodge", "shaolin_shenfa");		//设置NPC的基本躲闪装备少林身法
	map_skill("parry", "jingang_quan");		//设置NPC的基本招架装备大金刚拳
	map_skill("claw", "longzhua_gong");		//设置NPC的基本爪法装备龙爪功

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 80);			//设置NPC附加攻击力

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
