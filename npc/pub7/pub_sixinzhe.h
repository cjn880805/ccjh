// pub_sixinzhe.h 寺行者
// dieer 2002-8-10

NPC_BEGIN(CNpub_sixinzhe);

virtual void create()
{
	set_name("寺行者", "si xinzhe");
	set("title", "三十三剑客之");
	set("gender", "男性");
	set("age", 30);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",28);				//设置人物形象
	set("per",20);
	set("repute", 10000);
	
	set("str", 32);
	set("int", 37);
	set("con", 33);
	set("dex", 31);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);

	set_skill("force", 350);			// 基本内功
	set_skill("hunyuan_yiqi", 350);			// 混元一气功
	set_skill("finger", 350);			// 基本指法
	set_skill("yizhi_chan", 350);			// 一指禅
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("shaolin_shenfa", 350);		// 少林身法
	set_skill("parry", 350);			// 基本招架
	set_skill("unarmed", 350);		        // 基本拳脚
	set_skill("jingang_quan", 350);			// 大金刚拳

	map_skill("force", "hunyuan_yiqi");		//设置NPC当前内功为混元一气功
	map_skill("unarmed", "jingang_quan");	        //设置NPC的基本拳脚装备大金刚拳
	map_skill("dodge", "shaolin_shenfa");		//设置NPC的基本躲闪装备少林身法
	map_skill("parry", "yizhi_chan");		//设置NPC的基本招架装备一指禅
	map_skill("finger", "yizhi_chan");		//设置NPC的基本指法装备一指禅

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 120);			//设置NPC附加攻击力

	prepare_skill("unarmed", "jingang_quan");	//设置NPC的组合功夫
	prepare_skill("finger", "yizhi_chan");
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("finger dian", 1);	//一指禅(dian点字决)
		break;
	case 1:
		perform_action("finger jingmo", 1);	//一指禅(jingmo惊魔一指)
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
