// lev1_gongzijun.h 公子俊
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_gongzijun);

virtual void create()
{
	set_name("公子俊", "gong zijun");
	set("title", "漫步飞花");
	set("gender", "男性");
	set("age", 20);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",17);				//设置人物形象
	set("repute", 4000);
	
	set("str", 24);
	set("int", 20);
	set("con", 23);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// 基本内功
	set_skill("shenghuo_shengong", 190+random(30));		// 圣火神功
	set_skill("finger", 190+random(30));			// 基本指法
	set_skill("xuantian_zhi", 190+random(30));			// 玄天无情指
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("qingfu_shenfa", 190+random(30));		// 青蝠身法
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("throwing", 190+random(30));				// 基本投掷
	set_skill("duoming_jinhua", 190+random(30));		// 夺命金花

	map_skill("force", "shenghuo_shengong");	//设置NPC当前内功为圣火神功
	map_skill("lingfa", "Shenghuo_lingfa");	    //设置NPC的基本令法装备圣火令法
	map_skill("dodge", "qingfu_shenfa");		//设置NPC的基本躲闪装备青蝠身法
	map_skill("finger", "xuantian_zhi");		//设置NPC的基本指法装备玄天无情指
	map_skill("throwing", "duoming_jinhua");	//设置NPC的基本投掷装备夺命金花

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 10);			//设置NPC附加攻击力
	
	prepare_skill("finger", "xuantian_zhi");

	carry_object("baipao")->wear();
	carry_object("kuihuazhen", 100)->wield();
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("throwing muye", 1);	//夺命金花(muye漫天花雨)
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
