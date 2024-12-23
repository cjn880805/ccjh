// pub_xiafuren.h 侠妇人
// dieer 2002-8-10

NPC_BEGIN(CNpub_xiafuren);

virtual void create()
{
	set_name("侠妇人", "xia furen");
	set("title", "三十三剑客之");
	set("gender", "女性");
	set("age", 20);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",2);				//设置人物形象
	set("per",28);
	
	set("str", 37);
	set("int", 33);
	set("con", 36);
	set("dex", 31);
	set("repute", 10000);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);

	set_skill("force", 350);			// 基本内功
	set_skill("beiming_shengong", 350);		// 北冥神功
	set_skill("strike", 350);			// 基本掌法
	set_skill("liuyang_zhang", 350);		// 六阳掌
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("lingboweibu", 350);			// 凌波微步
	set_skill("parry", 350);			// 基本招架
	set_skill("hand", 350);			        // 基本手法
	set_skill("zhemei_shou", 350);			// 折梅手
	set_skill("blade", 350);			// 基本刀法
	set_skill("xiaoyao_dao", 350);			// 逍遥刀

	map_skill("force", "beiming_shengong");		//设置NPC当前内功为北冥神功
	map_skill("hand", "zhemei_shou");	        //设置NPC的基本手法装备折梅手
	map_skill("dodge", "lingboweibu");		//设置NPC的基本躲闪装备凌波微步
	map_skill("parry", "zhemei_shou");		//设置NPC的基本招架装备折梅手
	map_skill("strike", "liuyang_zhang");		//设置NPC的基本掌法装备六阳掌
	map_skill("blade", "xiaoyao_dao");		//设置NPC的基本刀法装备逍遥刀

	prepare_skill("hand", "zhemei_shou");		//设置NPC的空手组合
	prepare_skill("strike", "liuyang_zhang");

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 70);			//设置NPC附加攻击力

	carry_object("gangdao")->wield();
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