// lev1_baiyuer.h 白玉儿
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_baiyuer);

virtual void create()
{
	set_name("白玉儿", "bai yuer");
	set("title", "眦目仙子");
	set("gender", "女性");
	set("age", 23);
	set("level", 100);
	set("long", 
		"她无疑是个美人,雪白的面庞，鼻子挺直而秀气，但是她却没有眼睛，她的眼帘似已被某种奇异的魔法缝起，变成一片光滑的皮肤，变成一片空白，绝望的空白！");
	set("attitude", "friendly");		//设置NPC态度
	set("icon",2);				//设置人物形象
	set("repute", 5000);			//设置NPC好坏
	
	set("str", 20);
	set("int", 22);
	set("con", 23);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// 基本内功
	set_skill("zixia_shengong", 190+random(30));		// 紫霞神功
	set_skill("strike", 190+random(30));			// 基本掌法
	set_skill("hunyuan_zhang", 190+random(30));		// 混元掌
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("huashan_shenfa", 190+random(30));		// 华山身法
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("sword", 190+random(30));		        // 基本剑法
	set_skill("yunv_swords", 190+random(30));			// 玉女金针十三剑

	map_skill("force", "zixia_shengong");		//设置NPC当前内功为紫霞神功
	map_skill("sword", "yunv_swords");	        //设置NPC的基本剑法装备玉女金针十三剑
	map_skill("dodge", "huashan_shenfa");		//设置NPC的基本轻功装备华山身法
	map_skill("parry", "yunv_swords");		//设置NPC的基本招架装备玉女金针十三剑
	map_skill("strike", "hunyuan_zhang");		//设置NPC的基本掌法装备混元掌

	prepare_skill("strike", "hunyuan_zhang");	//设置NPC当前使用的空手组合


	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 70);			//设置NPC附加攻击力

	carry_object("sword_1")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword wushuang", 1);	//华山剑法绝招剑掌五连环
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
