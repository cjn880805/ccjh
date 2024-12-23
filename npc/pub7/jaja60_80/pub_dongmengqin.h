// lev1_dongmengqin.h 东门庆
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_dongmengqin);

virtual void create()
{
	set_name("东门庆", "dong mengqin");
	set("title", "妓院老板");
	set("gender", "男性");
	set("age", 40);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",15);				//设置人物形象
	set("repute", -5000);
	
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
	set_skill("kurong_changong", 190+random(30));			// 枯荣禅功
	set_skill("strike", 190+random(30));			// 基本掌法
	set_skill("wuluo_zhang", 190+random(30));			// 五罗轻烟掌
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("shenxing_baibian", 190+random(30));		// 神行百变
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("sword", 190+random(30));		        // 基本剑法
	set_skill("songshan_sword", 190+random(30));		// 嵩山剑法

	map_skill("force", "kurong_changong");		//设置NPC当前内功为枯荣禅功
	map_skill("sword", "songshan_sword");	        //设置NPC的基本剑法装备嵩山剑法
	map_skill("dodge", "shenxing_baibian");		//设置NPC的基本轻功装备神行百变
	map_skill("parry", "songshan_sword");		//设置NPC的基本招架装备嵩山剑法
	map_skill("strike", "wuluo_zhang");		//设置NPC的基本掌法装备五罗轻烟掌

	prepare_skill("strike", "wuluo_zhang");		//设置NPC的空手组全	

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 10);			//设置NPC附加攻击力

	carry_object("zheshan")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
			//自动吸气
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
