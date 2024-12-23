// lev1_youwuyan.h 尤无艳
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_youwuyan);

virtual void create()
{
	set_name("尤无艳", "you wuyang");
	set("title", "失心人");
	set("gender", "女性");
	set("age", 55);
	set("level", 100);
	set("long", 
		"这女人的头发蓬乱，脸色发黄，看来说不出的疲倦憔悴，两眼直勾勾地不知道盯着什么。\n");
	set("attitude", "peaceful");			//设置NPC态度
	set("icon",10);					//设置人物形象
	set("repute", -5000);
	
	set("str", 21);
	set("int", 23);
	set("con", 23);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1600000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// 基本内功
	set_skill("yunv_xinjing", 190+random(30));			// 玉女心经
	set_skill("unarmed", 190+random(30));			// 基本拳脚
	set_skill("meinv_quan", 190+random(30));			// 美女拳
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("yunv_shenfa", 190+random(30));			// 玉女身法
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("whip", 190+random(30));		        // 基本鞭法
	set_skill("yinsuo_jinling", 190+random(30));	// 银索金铃
	set_skill("yunv_xinfa", 190+random(30));			// 玉女心法
	set_skill("tianluo_diwang", 190+random(30));		// 天罗地网

	map_skill("force", "yunv_xinjing");		//设置NPC当前内功为玉女心经
	map_skill("whip", "yinsuo_jinling");	//设置NPC的基本鞭法装备银索金铃
	map_skill("dodge", "yunv_shenfa");		//设置NPC的基本轻工装备玉女身法
	map_skill("parry", "yinsuo_jinling");	//设置NPC的基本招架装备银索金铃
	map_skill("unarmed", "meinv_quan");		//设置NPC的基本拳脚装备美女拳


	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 10);			//设置NPC附加攻击力

	carry_object("changbian")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("whip dian", 1);		//银索金铃(dian点穴)
		break;
	case 1:
		perform_action("unarmed you", 1);	//美女拳绝招古墓幽居
		break;
	case 2:
		perform_action("whip feng", 1);	//银索金铃(feng封穴)
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
