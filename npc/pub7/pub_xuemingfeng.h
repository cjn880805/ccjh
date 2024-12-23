// pub_xuemingfeng.h 薛冥锋
// dieer 2002-8-26

NPC_BEGIN(CNpub_xuemingfeng);

virtual void create()
{
	set_name("薛冥锋", "xue mingfeng");
	set("title", "漠北三煞之狂风煞");
	set("gender", "男性");
	set("age", 50);
	set("level", 80);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",20);				//设置人物形象
	
	set("str", 20);
	set("int", 22);
	set("con", 23);
	set("dex", 21);
	set("repute", -5000);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// 基本内功
	set_skill("bibo_shengong", 250);		// 碧波神功
	set_skill("leg", 250);				// 基本腿法
	set_skill("xuanfeng_leg", 250);			// 旋风扫叶腿
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("anying_fuxiang", 250);		// 暗影浮香
	set_skill("parry", 250);			// 基本招架

	map_skill("force", "bibo_shengong");		//设置NPC当前内功为碧波神功
	map_skill("dodge", "anying_fuxiang");		//设置NPC的基本躲闪装备暗影浮香
	map_skill("parry", "xuanfeng_leg");		//设置NPC的基本招架装备旋风扫叶腿
	map_skill("lge", "xuanfeng_leg");		//设置NPC的基本腿法装备旋风扫叶腿

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 60);			//设置NPC附加攻击力

	prepare_skill("lge", "xuanfeng_leg");		//设置NPC的空手组合
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("leg kuangfeng", 1);	//旋风扫叶腿(kuangfeng狂风绝技)
		break;
	case 1:
		perform_action("force powerup", 0);	//自动激励
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
