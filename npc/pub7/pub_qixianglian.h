// pub_qixianglian.h 齐香怜
//jaja 2002-10-20

NPC_BEGIN(CNpub_qixianglian);

virtual void create()
{
	set_name("齐香怜", "qi xianglian");
	set("title", "痴婆婆");
	set("gender", "女性");
	set("age", 86);
	set("level", 100);
	set("long", 
		"这是个很老的老太婆，穿着一身红衣裳，就像是新娘子穿的那种绣花的红衣裳，脚上还穿着双用大红绸子做的红绣鞋。她脸上的皱纹比棋盘格子还多，嘴里牙齿已经掉得比两岁的孩子还少。\n");
	set("attitude", "friendly");		//设置NPC态度
	set("icon",21);				//设置人物形象
	set("repute", 5000);

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
	set_skill("bahuang_gong", 250);			// 八荒六合唯我独尊功
	set_skill("strike", 250);			// 基本掌法
	set_skill("liuyang_zhang", 250);		// 六阳掌
	set_skill("hand", 250);				// 基本手法
	set_skill("zhemei_shou", 250);			// 折梅手
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("yueying_wubu", 250);			// 月影舞步
	set_skill("parry", 250);			// 基本招架
	set_skill("sword", 250);		        // 基本剑法
	set_skill("tianyu_qijian", 250);		// 天羽奇剑

	map_skill("force", "bahuang_gong");		//设置NPC当前内功为八荒
	map_skill("sword", "tianyu_qijian");	        //设置NPC的基本剑法装备天羽奇剑
	map_skill("dodge", "yueying_wubu");		//设置NPC的基本躲闪装备月影舞步
	map_skill("parry", "tianyu_qijian");		//设置NPC的基本招架装备天羽奇剑
	map_skill("strike", "liuyang_zhang");		//设置NPC的基本掌法装备六阳掌
	map_skill("hand", "zhemei_shou");		//设置NPC的基本手法装备折梅手

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 40);			//设置NPC附加攻击力

	prepare_skill("hand", "zhemei_shou");		//设置NPC的空手组合
	prepare_skill("strike", "liuyang_zhang");

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword san", 1);		//天羽奇剑(san天女散花)
		break;
	case 1:
		perform_action("hand duo", 1);		//折梅手(duo空手入白刃)
		break;
	case 2:
		perform_action("sword kuangwu", 1);	//天羽奇剑(kuangwu天女狂舞)
		break;
	case 3:
		perform_action("force powerup", 0);	//自动激励
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

