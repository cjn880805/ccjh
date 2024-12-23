// pub_lundarong.h 伦达荣
// jaja 2002-10-20

NPC_BEGIN(CNpub_lundarong);

virtual void create()
{
	set_name("伦达荣", "lun darong");
	set("title", "昆仑二怪");
	set("gender", "男性");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",19);				//设置人物形象
	set("repute", -5000);
	
	set("str", 22);
	set("int", 22);
	set("con", 22);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// 基本内功
	set_skill("xuantian_shengong", 250);		// 玄天神功
	set_skill("finger", 250);			// 基本指法
	set_skill("xuantian_zhi", 250);			// 玄天无情指
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("qingfu_shenfa", 250);		// 青蝠身法
	set_skill("parry", 250);			// 基本招架
	set_skill("blade", 250);		        // 基本刀法
	set_skill("wuyue_blade", 250);			// 巫月刀法

	map_skill("force", "xuantian_shengong");	//设置NPC当前内功为玄天神功
	map_skill("blade", "wuyue_blade");	        //设置NPC的基本刀法装备巫月刀法
	map_skill("dodge", "qingfu_shenfa");		//设置NPC的基本躲闪装备青蝠身法
	map_skill("parry", "wuyue_blade");		//设置NPC的基本招架装备巫月刀法
	map_skill("finger", "xuantian_zhi");		//设置NPC的基本指法装备玄天无情指

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

	carry_object("gangdao")->wield();

	prepare_skill("finger", "xuantian_zhi");
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("blade jiao", 1);	//巫月刀法(jiao铰字诀)
		break;
	case 1:
		perform_action("force recover", 0);	//自动吸气
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

