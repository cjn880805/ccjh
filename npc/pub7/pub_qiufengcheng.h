// pub_qiufengcheng.h 邱凤城
//jaja 2002-10-20

NPC_BEGIN(CNpub_qiufengcheng);

virtual void create()
{
	set_name("邱凤城", "qiu fengcheng");
	set("title", "银枪公子");
	set("gender", "男性");
	set("age", 26);
	set("level", 100);
	set("long", 
		"他年轻、健康、高大、英俊，而且有一种教养良好的气质。他身上穿的是一袭价值千金的貂裘，手里拿着光华夺目的银枪。枪杆是纯银的。\n");
	set("attitude", "friendly");		//设置NPC态度
	set("icon",18);				//设置人物形象
	set("repute", 3000);
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// 基本内功
	set_skill("taixuan_gong", 250);		// 侠客岛太玄功
	set_skill("unarmed", 250);			// 基本拳脚
	set_skill("changquan", 250);		// 长拳
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("shenxing_baibian", 250);		// 神行百变
	set_skill("parry", 250);			// 基本招架
	set_skill("club", 250);		        // 基本棍法
	set_skill("zhongpingqiang", 250);		// 中平枪法

	map_skill("force", "taixuan_gong");		//设置NPC当前内功为侠客岛太玄功
	map_skill("club", "zhongpingqiang");	        //设置NPC的基本棍法装备中平枪法
	map_skill("dodge", "shenxing_baibian");		//设置NPC的基本轻功装备神行百变
	map_skill("parry", "zhongpingqiang");		//设置NPC的基本招架装备中平枪法
	map_skill("unarmed", "changquan");		//设置NPC的基本拳脚装备长拳

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

	carry_object("doupeng");	
	carry_object("changqiang")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("force recover", 0);	//自动吸气
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
