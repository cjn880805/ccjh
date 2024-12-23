// lev1_xianfeitian.h 向飞天
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_xianfeitian);

virtual void create()
{
	set_name("向飞天", "xian feitian");
	set("title", "大牯牛");
	set("gender", "男性");
	set("age", 26);
	set("level", 100);
	set("long", 
		"别看他长得瘦瘦小小，这人不说话则已，一说话，就是副想要找麻烦的神气。\n");
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",14);				//设置人物形象
	set("repute", -3000);
	
	set("str", 23);
	set("int", 23);
	set("con", 20);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// 基本内功
	set_skill("hunyuan_yiqi", 190+random(30));			// 混元一气功
	set_skill("sword", 190+random(30));			// 基本剑法
	set_skill("zhanjiang_jue", 190+random(30));		// 斩将决
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("shaolin_shenfa", 190+random(30));		// 少林身法
	set_skill("parry", 190+random(30));			// 基本招架
	set_skill("unarmed", 190+random(30));		        // 基本拳脚
	set_skill("jingang_quan", 190+random(30));			// 大金刚拳

	map_skill("force", "hunyuan_yiqi");		//设置NPC当前内功为混元一气功
	map_skill("unarmed", "jingang_quan");	        //设置NPC的基本拳脚装备大金刚拳
	map_skill("dodge", "shaolin_shenfa");		//设置NPC的基本躲闪装备少林身法
	map_skill("parry", "yizhi_chan");		//设置NPC的基本招架装备一指禅
	map_skill("sword", "zhanjiang_jue");		//设置NPC的基本剑法装备斩将决

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 10);			//设置NPC附加攻击力

	carry_object("changjian")->wield();		//设置NPC装备的物品
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
			//自动吸气
		break;
	case 1:
		perform_action("force roar", 1);	//混元一气功佛门狮子吼
		break;
	case 2:
		perform_action("force roar", 1);	//混元一气功佛门狮子吼
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

