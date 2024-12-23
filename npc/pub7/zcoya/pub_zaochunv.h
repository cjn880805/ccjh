// pub_zaochunv.h 赵处女
// dieer 2002-7-27

NPC_BEGIN(CNpub_zaochunv);

virtual void create()
{
	set_name("赵处女", "zaochu nv");
	set("title", "三十三剑客之");
	set("gender", "女性");
	set("age", 16);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",3);				//设置人物形象
	set("per",38);
	set("shen_type", 1);
	
	set("str", 46);
	set("int", 47);
	set("con", 45);
	set("dex", 44);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 80);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// 基本内功
	set_skill("yunv_xinjing", 350);			// 玉女心经
	set_skill("unarmed", 350);			// 基本拳脚
	set_skill("meinv_quan", 350);			// 美女拳
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("yunv_shenfa", 350);			// 玉女身法
	set_skill("parry", 350);			// 基本招架
	set_skill("sword", 350);		        // 基本剑法
	set_skill("yunv_jian", 350);			// 玉女剑
	set_skill("yunv_xinfa", 350);			// 玉女心法
	set_skill("tianluo_diwang", 350);		// 天罗地网
	set_skill("quanzhen_jian", 350);		// 全真剑法

	map_skill("force", "yunv_xinjing");		//设置NPC当前内功为玉女心经
	map_skill("sword", "yunv_jian");	        //设置NPC的基本剑法装备玉女剑
	map_skill("dodge", "yunv_shenfa");		//设置NPC的基本轻工装备玉女身法
	map_skill("parry", "yunv_jian");		//设置NPC的基本招架装备全真剑法
	map_skill("unarmed", "meinv_quan");		//设置NPC的基本拳脚装备美女拳


	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 50);			//设置NPC附加攻击力

	carry_object("shunvjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword he", 1);		//玉女剑法双剑合壁
		break;
	case 1:
		perform_action("unarmed you", 1);	//美女拳绝招古墓幽居
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
