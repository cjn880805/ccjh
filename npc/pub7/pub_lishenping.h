// pub_lishenping.h 厉生平
//jaja 2002-10-20

NPC_BEGIN(CNpub_lishenping);

virtual void create()
{
	set_name("厉生平", "li shenping");
	set("title", "癫剑魔");
	set("gender", "男性");
	set("age", 52);
	set("level", 100);
	set("long", 
		"一个披头散发，又脏又臭的人，他坐在那里，看着某处，有时彷佛已看得出神，有时忽然跳起来，此划几下，谁也猜不出他比的是什麽招式。\n");
	
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",50);				//设置人物形象
	
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
	set_skill("yunv_xinjing", 250);			// 玉女心经
	set_skill("unarmed", 250);			// 基本拳脚
	set_skill("anranxiaohun_zhang", 250);		// 黯然消魂掌
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("xianyun_bufa", 250);			// 纤云步法
	set_skill("parry", 250);			// 基本招架
	set_skill("sword", 250);		        // 基本剑法
	set_skill("smithsword", 250);			// 玄铁重剑式
	set_skill("yunv_xinfa", 250);			// 玉女心法
	set_skill("tianluo_diwang", 250);		// 天罗地网

	map_skill("force", "yunv_xinjing");		//设置NPC当前内功为玉女心经
	map_skill("sword", "smithsword");	        //设置NPC的基本剑法装备玄铁重剑式
	map_skill("dodge", "xianyun_bufa");		//设置NPC的基本轻工装备纤云步法
	map_skill("parry", "smithsword");		//设置NPC的基本招架装备玄铁重剑式
	map_skill("unarmed", "anranxiaohun_zhang");	//设置NPC的基本拳脚装备黯然消魂掌

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 40);			//设置NPC附加攻击力

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword flood", 1);	//玄铁重剑式(flood奔潮诀)
		break;
	case 1:
		perform_action("unarmed xiaohun", 1);	//黯然消魂
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
