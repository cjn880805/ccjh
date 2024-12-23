// lev1_situshashou.h 司徒挲寿
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_situshashou);

virtual void create()
{
	set_name("司徒挲寿", "situ shashou");
	set("title", "大内密探总管");
	set("gender", "男性");
	set("age", 70);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",20);				//设置人物形象
	set("repute", -5000);
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// 基本内功
	set_skill("taiji_shengong", 190+random(30));		// 太极神功
	set_skill("unarmed", 190+random(30));			// 基本拳脚
	set_skill("changquan", 190+random(30));			// 长拳
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("tiyunzong", 190+random(30));			// 梯云纵
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("hand", 190+random(30));				// 基本手法
	set_skill("tangshoudao", 190+random(30));			// 唐手道

	map_skill("force", "taiji_shengong");		//设置NPC当前内功为太极神功
	map_skill("unarmed", "changquan");	        //设置NPC的基本拳脚装备长拳
	map_skill("dodge", "tiyunzong");		//设置NPC的基本躲闪装备梯云纵
	map_skill("parry", "tangshoudao");		//设置NPC的基本招架装备唐手道
	map_skill("hand", "tangshoudao");		//设置NPC的基本手法装备唐手道

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 50);			//设置NPC附加攻击力

	prepare_skill("hand", "tangshoudao");		//设置NPC的空手组合
	prepare_skill("unarmed", "changquan");
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("force powerup", 0);	//太极神功激励
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
