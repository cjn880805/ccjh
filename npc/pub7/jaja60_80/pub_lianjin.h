// lev1_lianjin.h 联晋
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_lianjin);

virtual void create()
{
	set_name("联晋", "lian jin");
	set("title", "红缨公子");
	set("gender", "男性");
	set("age", 20);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",16);				//设置人物形象
	set("repute", 5000);
	
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
	set_skill("kurong_changong", 190+random(30));		// 枯荣禅功
	set_skill("unarmed", 190+random(30));			// 基本拳脚
	set_skill("changquan", 190+random(30));		// 长拳
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("shenxing_baibian", 190+random(30));		// 神行百变
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("club", 190+random(30));		        // 基本棍法
	set_skill("zhongpingqiang", 190+random(30));		// 中平枪法

	map_skill("force", "kurong_changong");		//设置NPC当前内功为枯荣禅功
	map_skill("club", "zhongpingqiang");	        //设置NPC的基本棍法装备中平枪法
	map_skill("dodge", "shenxing_baibian");		//设置NPC的基本轻功装备神行百变
	map_skill("parry", "zhongpingqiang");		//设置NPC的基本招架装备中平枪法
	map_skill("unarmed", "changquan");		//设置NPC的基本拳脚装备长拳

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 10);			//设置NPC附加攻击力

	carry_object("changqiang")->wield();	
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