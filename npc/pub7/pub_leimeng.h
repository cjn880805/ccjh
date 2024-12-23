// pub_leimeng.h 雷猛
//jaja 2002-10-20

NPC_BEGIN(CNpub_leimeng);

virtual void create()
{
	set_name("雷猛", "lei meng");
	set("title", "蛮牛");
	set("gender", "男性");
	set("age", 40);
	set("level", 100);
	set("long", 
		"他是一个衣着华丽神态威猛的彪形大汉，目光焖焖，威风凛凛。\n");
	set("repute", 2000);
	
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",42);				//设置人物形象
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// 基本内功
	set_skill("taiji_shengong", 250);		// 太极神功
	set_skill("unarmed", 250);			// 基本拳脚
	set_skill("changquan", 250);			// 长拳
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("tiyunzong", 250);			// 梯云纵
	set_skill("parry", 250);			// 基本招架
	set_skill("hand", 250);				// 基本手法
	set_skill("tangshoudao", 250);			// 唐手道

	map_skill("force", "taiji_shengong");		//设置NPC当前内功为太极神功
	map_skill("unarmed", "changquan");	        //设置NPC的基本拳脚装备长拳
	map_skill("dodge", "tiyunzong");		//设置NPC的基本躲闪装备梯云纵
	map_skill("parry", "tangshoudao");		//设置NPC的基本招架装备唐手道
	map_skill("hand", "tangshoudao");		//设置NPC的基本手法装备唐手道

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

	prepare_skill("hand", "tangshoudao");		//设置NPC的空手组合
	prepare_skill("unarmed", "changquan");
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("force powerup", 1);	//太极神功激励
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
