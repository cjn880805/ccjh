// lev1_linhongyin.h 林虹瑛
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_linhongyin);

virtual void create()
{
	set_name("林虹瑛", "lin hongyin");
	set("title", "红白双剑之红剑");
	set("gender", "女性");
	set("age", 40);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",8);				//设置人物形象
	set("repute", 4000);
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// 基本内功
	set_skill("yunv_xinjing", 190+random(30));			// 玉女心经
	set_skill("unarmed", 190+random(30));			// 基本拳脚
	set_skill("meinv_quan", 190+random(30));		// 美女拳
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("yunv_shenfa", 190+random(30));			// 玉女身法
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("sword", 190+random(30));		        // 基本剑法
	set_skill("yunv_jian", 190+random(30));			// 玉女剑
	set_skill("yunv_xinfa", 190+random(30));			// 玉女心法
	set_skill("tianluo_diwang", 190+random(30));		// 天罗地网
	set_skill("quanzhen_jian", 190+random(30));		// 全真剑法

	map_skill("force", "yunv_xinjing");		//设置NPC当前内功为玉女心经
	map_skill("sword", "yunv_jian");	        //设置NPC的基本剑法装备玉女剑
	map_skill("dodge", "yunv_shenfa");		//设置NPC的基本轻功装备玉女身法
	map_skill("parry", "quanzhen_jian");		//设置NPC的基本招架装备全真剑法
	map_skill("unarmed", "meinv_quan");	//设置NPC的基本拳脚装备美女拳

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 10);			//设置NPC附加攻击力

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword he", 1);		//玉女剑法双剑合壁
		break;
	case 1:
		perform_action("unarmed you", 1);	//美女拳(you古墓幽居)
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