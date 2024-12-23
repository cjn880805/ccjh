// pub_shenmike.h 神秘客
//dieer 2002-7-21

NPC_BEGIN(CNpub_shenmike);

virtual void create()
{
	set_name("神秘客", "shen mike");
	set("gender", "男性");
	set("age", 36);
	set("level", 157);
	set("long", 
		"他身上穿着件灰朴朴的衣服，头上戴着顶大帽，帽沿低压，谁也看不到他的表情。\n");
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",38);				//设置人物形象
	
	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 40000);
	set("max_mp", 10000);
	set("mp_factor", 80);			//设置NPC加力参数
	
	set("combat_exp", 60000000);
	set("score", 6000);
	
	set_skill("force", 350);			// 基本内功
	set_skill("yunv_xinjing", 350);			// 玉女心经
	set_skill("unarmed", 350);			// 基本拳脚
	set_skill("anranxiaohun_zhang", 350);		// 黯然消魂掌
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("xianyun_bufa", 350);			// 纤云步法
	set_skill("parry", 350);			// 基本招架
	set_skill("sword", 350);		        // 基本剑法
	set_skill("yunv_jian", 350);			// 玉女剑
	set_skill("yunv_xinfa", 350);			// 玉女心法
	set_skill("tianluo_diwang", 350);		// 天罗地网
	set_skill("quanzhen_jian", 350);		// 全真剑法

	map_skill("force", "yunv_xinjing");		//设置NPC当前内功为玉女心经
	map_skill("sword", "yunv_jian");	        //设置NPC的基本剑法装备玉女剑
	map_skill("dodge", "xianyun_bufa");		//设置NPC的基本轻工装备纤云步法
	map_skill("parry", "quanzhen_jian");		//设置NPC的基本招架装备全真剑法
	map_skill("unarmed", "anranxiaohun_zhang");	//设置NPC的基本拳脚装备黯然消魂掌

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 80);			//设置NPC附加攻击力

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword he", 1);		//玉女剑法双剑合壁
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
