// pub_wuweiyang.h 武维扬
//jaja 2002-10-20

NPC_BEGIN(CNpub_wuweiyang);

virtual void create()
{
	set_name("武维扬", "wu weiyang");
	set("title", "神箭射日");
	set("gender", "男性");
	set("age", 52);
	set("level", 100);
	set("long", 
		"这老人正是凤尾帮的总瓢把子，他华美的绵袍上系着用七根不同颜色的丝条编成的腰带，看上去富贵而威武。\n");
	set("attitude", "friendly");		//设置NPC态度
	set("icon",19);				//设置人物形象
	set("repute", -5000);
	
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
	set_skill("bibo_shengong", 250);		// 碧波神功
	set_skill("finger", 250);			// 基本指法
	set_skill("tanzhi_shentong", 250);		// 弹指神通
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("anying_fuxiang", 250);		// 暗影浮香
	set_skill("parry", 250);			// 基本招架
	set_skill("hand", 250);			        // 基本手法
	set_skill("lanhua_shou", 250);			// 兰花拂穴手

	map_skill("force", "bibo_shengong");		//设置NPC当前内功为碧波神功
	map_skill("hand", "lanhua_shou");	        //设置NPC的基本手法装备兰花拂穴手
	map_skill("dodge", "anying_fuxiang");		//设置NPC的基本躲闪装备暗影浮香
	map_skill("parry", "lanhua_shou");		//设置NPC的基本招架装备兰花拂穴手
	map_skill("finger", "tanzhi_shentong");		//设置NPC的基本指法装备弹指神通

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

	prepare_skill("finger", "tanzhi_shentong");	//设置NPC的空手组合
	prepare_skill("hand", "lanhua_shou");
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("hand fuxue", 1);	//兰花拂穴手(fuxue拈花拂穴)
		break;
	case 1:
		perform_action("finger hui", 1);	//弹指神通绝招挥斥方遒
		break;
	case 2:
		perform_action("finger jinglei", 1);	//弹指神通绝招弹指惊雷
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