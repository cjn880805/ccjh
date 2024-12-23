// pub_linjinzhi.h 林金芝
//jaja 2002-10-20

NPC_BEGIN(CNpub_linjinzhi);

virtual void create()
{
	set_name("林金芝", "lin jinzhi");
	set("title", "毒手美妇");
	set("gender", "女性");
	set("age", 30);
	set("level", 100);
	set("long", 
		"她穿了件质料很高贵，并不太花的衣服，头上戴的珍翠既不大多，也不太少。她端端正正，规规矩矩的站在那里，看来既不刺眼，也绝不寒伧，正是位世家大宅中的千金小姐应该有的模样。\n");
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",3);				//设置人物形象
	set("repute", -5000);
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// 基本内功
	set_skill("beiming_shengong", 250);		// 北冥神功
	set_skill("strike", 250);			// 基本掌法
	set_skill("liuyang_zhang", 250);		// 六阳掌
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("lingboweibu", 250);			// 凌波微步
	set_skill("parry", 250);			// 基本招架
	set_skill("hand", 250);			        // 基本手法
	set_skill("zhemei_shou", 250);			// 折梅手

	map_skill("force", "beiming_shengong");		//设置NPC当前内功为北冥神功
	map_skill("hand", "zhemei_shou");	        //设置NPC的基本手法装备折梅手
	map_skill("dodge", "lingboweibu");		//设置NPC的基本躲闪装备凌波微步
	map_skill("parry", "zhemei_shou");		//设置NPC的基本招架装备折梅手
	map_skill("strike", "liuyang_zhang");		//设置NPC的基本掌法装备六阳掌

	prepare_skill("hand", "zhemei_shou");		//设置NPC的空手组合
	prepare_skill("strike", "liuyang_zhang");

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 50);			//设置NPC附加攻击力
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("force neilisuck", 1);	//北冥神功neilisuck吸功术
		break;
	case 1:
		perform_action("hand duo", 1);		//折梅手(duo空手入白刃)
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