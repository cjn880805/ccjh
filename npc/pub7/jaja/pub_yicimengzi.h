// pub_yicimengzi.h 宣慈寺门子
// dieer 2002-8-5

NPC_BEGIN(CNpub_yicimengzi);

virtual void create()
{
	set_name("宣慈寺门子", "yici mengzi");
	set("title", "三十三剑客之");
	set("gender", "男性");
	set("age", 20);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",26);				//设置人物形象
	set("per",20);
	set("repute", 10000);
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 80);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// 基本内功
	set_skill("hunyuan_yiqi", 350);			// 混元一气功
	set_skill("finger", 350);			// 基本指法
	set_skill("nianhua_zhi", 350);			// 拈花指
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("shaolin_shenfa", 350);		// 少林身法
	set_skill("parry", 350);			// 基本招架
	set_skill("whip", 350);			        // 基本鞭法
	set_skill("riyue_bian", 350);			// 日月鞭法

	map_skill("force", "hunyuan_yiqi");		//设置NPC当前内功为混元一气功
	map_skill("whip", "riyue_bian");	        //设置NPC的基本鞭法装备日月鞭法
	map_skill("dodge", "shaolin_shenfa");		//设置NPC的基本躲闪装备少林身法
	map_skill("parry", "riyue_bian");		//设置NPC的基本招架装备日月鞭法
	map_skill("finger", "nianhua_zhi");		//设置NPC的基本指法装备拈花指

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 80);			//设置NPC附加攻击力

	prepare_skill("whip", "riyue_bian");		//设置NPC的组合功夫
	prepare_skill("finger", "nianhua_zhi");

	carry_object("changbian")->wield();
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("whip chan", 1);		//日月鞭法绝招缠绕诀
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

NPC_END;
