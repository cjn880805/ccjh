// pub_xieyulun.h 谢玉仑
//jaja 2002-10-20

NPC_BEGIN(CNpub_xieyulun);

virtual void create()
{
	set_name("谢玉仑", "xie yulun");
	set("title", "玉面冷心");
	set("gender", "男性");
	set("age", 25);
	set("level", 100);
	set("long", 
		"他腰悬长剑，头戴银狐皮帽，身着银狐皮裘，一身都是银白色的，背负双手在那儿一站，顾盼之间，傲气逼人。\n");
	set("attitude", "friendly");		//设置NPC态度
	set("icon",16);				//设置人物形象
	set("repute", 4000);
	
	set("str", 23);
	set("int", 23);
	set("con", 20);
	set("dex", 21);
	
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
	set_skill("yunv_jian", 250);			// 玉女剑
	set_skill("yunv_xinfa", 250);			// 玉女心法
	set_skill("tianluo_diwang", 250);		// 天罗地网
	set_skill("quanzhen_jian", 250);		// 全真剑法

	map_skill("force", "yunv_xinjing");		//设置NPC当前内功为玉女心经
	map_skill("sword", "yunv_jian");	        //设置NPC的基本剑法装备玉女剑
	map_skill("dodge", "xianyun_bufa");		//设置NPC的基本轻功装备纤云步法
	map_skill("parry", "quanzhen_jian");		//设置NPC的基本招架装备全真剑法
	map_skill("unarmed", "anranxiaohun_zhang");	//设置NPC的基本拳脚装备黯然消魂掌

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

	carry_object("baipao");	
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
