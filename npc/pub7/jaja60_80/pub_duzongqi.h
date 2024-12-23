// lev1_duzongqi.h 杜仲奇
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_duzongqi);

virtual void create()
{
	set_name("杜仲奇", "du zongqi");
	set("title", "七星鞭");
	set("gender", "男性");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",19);				//设置人物形象
	set("repute", 5000);
	
	set("str", 25);
	set("int", 21);
	set("con", 20);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// 基本内功
	set_skill("yunlong_shengong", 190+random(30));		// 云龙神功
	set_skill("hand", 190+random(30));			// 基本手法
	set_skill("yunlong_shou", 190+random(30));		// 云龙手
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("yunlong_shenfa", 190+random(30));		// 云龙身法
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("whip", 190+random(30));		        // 基本鞭法
	set_skill("yunlong_bian", 190+random(30));		// 云龙鞭法

	map_skill("force", "yunlong_shengong");		//设置NPC当前内功为云龙神功
	map_skill("whip", "yunlong_bian");	        //设置NPC的基本鞭法装备云龙鞭法
	map_skill("dodge", "yunlong_shenfa");		//设置NPC的基本轻功装备云龙身法
	map_skill("parry", "yunlong_bian");		//设置NPC的基本招架装备反云龙鞭法
	map_skill("hand", "yunlong_shou");		//设置NPC的基本手法装备云龙手

	prepare_skill("hand", "yunlong_shou");	//设置NPC的空手组全

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 10);			//设置NPC附加攻击力

	carry_object("changbian")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("whip chan", 1);	//云龙鞭法(chan缠字诀)
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
