// pub_hongxian.h 红线
// dieer 2002-7-27

NPC_BEGIN(CNpub_hongxian);

virtual void create()
{
	set_name("红线", "hong xian");
	set("title", "三十三剑客之");
	set("gender", "女性");
	set("age", 19);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",3);				//设置人物形象
	set("per",39);
	set("repute", 10000);
	
	set("str", 32);
	set("int", 39);
	set("con", 32);
	set("dex", 37);
	
	set("chat_chance_combat", 30);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 70);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// 基本内功
	set_skill("bibo_shengong", 350);		// 碧波神功
	set_skill("finger", 350);			// 基本指法
	set_skill("tanzhi_shentong", 350);		// 弹指神通
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("anying_fuxiang", 350);		// 暗影浮香
	set_skill("parry", 350);			// 基本招架
	set_skill("sword", 350);		        // 基本剑法
	set_skill("yuxiao_jianfa", 350);		// 玉萧剑法

	map_skill("force", "bibo_shengong");		//设置NPC当前内功为碧波神功
	map_skill("sword", "yuxiao_jianfa");	        //设置NPC的基本剑法装备玉萧剑法
	map_skill("dodge", "anying_fuxiang");		//设置NPC的基本躲闪装备暗影浮香
	map_skill("parry", "yuxiao_jianfa");		//设置NPC的基本招架装备玉萧剑法
	map_skill("finger", "tanzhi_shentong");		//设置NPC的基本指法装备弹指神通

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 60);			//设置NPC附加攻击力

	carry_object("changjian")->wield();	
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword hua", 1);		//玉萧剑法绝招势合形离
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
