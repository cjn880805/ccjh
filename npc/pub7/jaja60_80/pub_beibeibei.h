// lev1_beibeibei.h 邶备悲
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_beibeibei);

virtual void create()
{
	set_name("邶备悲", "bei beibei");
	set("title", "北侍卫总领");
	set("gender", "男性");
	set("age", 60);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",42);				//设置人物形象
	set("repute", -5000);			//设置NPC好坏
	
	set("str", 22);
	set("int", 24);
	set("con", 23);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp", 10000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 350);			// 基本内功
	set_skill("beiming_shengong", 139);		// 北冥神功
	set_skill("strike", 190+random(30));			// 基本掌法
	set_skill("liuyang_zhang", 190+random(30));		// 六阳掌
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("lingboweibu", 190+random(30));			// 凌波微步
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("sword", 190+random(30));		        // 基本剑法
	set_skill("lingxiao_kuaijian", 190+random(30));		// 凌霄快剑
	set_skill("hand", 190+random(30));				// 基本手法
	set_skill("zhemei_shou", 190+random(30));			// 反两仪刀法

	map_skill("force", "beiming_shengong");		//设置NPC当前内功为北冥神功
	map_skill("sword", "lingxiao_kuaijian");	//设置NPC的基本剑法装备凌霄快剑
	map_skill("dodge", "lingboweibu");		//设置NPC的基本轻功装备凌波微步
	map_skill("parry", "lingxiao_kuaijian");	//设置NPC的基本招架装备凌霄快剑
	map_skill("strike", "liuyang_zhang");		//设置NPC的基本掌法装备六阳掌
	map_skill("hand", "zhemei_shou");		//设置NPC的基本手法装备折梅手

	prepare_skill("strike", "liuyang_zhang");	//设置NPC的空手组合
	prepare_skill("hand", "zhemei_shou");

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 50);			//设置NPC附加攻击力

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword mixhit", 1);	//凌霄快剑绝招凌霄十三剑
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
