// pub_jiarenqi.h 贾人妻
// dieer 2002-8-5

NPC_BEGIN(CNpub_jiarenqi);

virtual void create()
{
	set_name("贾人妻", "jiaren qi");
	set("title", "三十三剑客之");
	set("gender", "女性");
	set("age", 30);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",5);				//设置人物形象
	set("per",30);
//	set("repute", -10000);
	
	set("str", 33);
	set("int", 33);
	set("con", 33);
	set("dex", 33);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// 基本内功
	set_skill("bibo_shengong", 350);		// 碧波神功
	set_skill("finger", 350);			// 基本指法
	set_skill("tanzhi_shentong", 350);		// 弹指神通
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("anying_fuxiang", 350);		// 暗影浮香
	set_skill("parry", 350);			// 基本招架
	set_skill("hand", 350);			        // 基本手法
	set_skill("lanhua_shou", 350);			// 兰花拂穴手

	map_skill("force", "bibo_shengong");		//设置NPC当前内功为碧波神功
	map_skill("hand", "lanhua_shou");	        //设置NPC的基本手法装备兰花拂穴手
	map_skill("dodge", "anying_fuxiang");		//设置NPC的基本躲闪装备暗影浮香
	map_skill("parry", "lanhua_shou");		//设置NPC的基本招架装备兰花拂穴手
	map_skill("finger", "tanzhi_shentong");		//设置NPC的基本指法装备弹指神通

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 60);			//设置NPC附加攻击力

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
