// pub_wangjinhongpu.h 王敬宏仆
// dieer 2002-7-27

NPC_BEGIN(CNpub_wangjinhongpu);

virtual void create()
{
	set_name("王敬宏仆", "wangjin hongpu");
	set("title", "三十三剑客之");
	set("gender", "男性");
	set("age", 10);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",22);				//设置人物形象
	set("per",20);
//	set("shen_type", 1);
	
	set("str", 46);
	set("int", 47);
	set("con", 45);
	set("dex", 44);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 70);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// 基本内功
	set_skill("taiji_shengong", 350);		// 太极神功
	set_skill("unarmed", 350);			// 基本拳脚
	set_skill("changquan", 350);			// 长拳
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("tiyunzong", 350);			// 梯云纵
	set_skill("parry", 350);			// 基本招架
	set_skill("hand", 350);				// 基本手法
	set_skill("tangshoudao", 350);			// 唐手道

	map_skill("force", "taiji_shengong");		//设置NPC当前内功为太极神功
	map_skill("unarmed", "changquan");	        //设置NPC的基本拳脚装备长拳
	map_skill("dodge", "tiyunzong");		//设置NPC的基本躲闪装备梯云纵
	map_skill("parry", "tangshoudao");		//设置NPC的基本招架装备唐手道
	map_skill("hand", "tangshoudao");		//设置NPC的基本手法装备唐手道

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 70);			//设置NPC附加攻击力

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
