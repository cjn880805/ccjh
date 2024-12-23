// pub_diaoer.h 刁二
// jaja 2002-10-20

NPC_BEGIN(CNpub_diaoer);

virtual void create()
{
	set_name("刁二", "diao er");
	set("title", "簑衣老二");
	set("gender", "男性");
	set("age", 24);
	set("level", 100);
	set("long", 
		"此人是簑衣三兄弟中的老二，一双腿出奇的长，站在那儿像是两根细长的柱子。\n");
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",43);				//设置人物形象
	set("repute", -5000);
	
	set("str", 20);
	set("int", 24);
	set("con", 21);
	set("dex", 26);
	
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
	set_skill("sword", 250);		        // 基本剑法
	set_skill("yuxiao_jianfa", 250);		// 玉萧剑法
	set_skill("xuanfeng_leg", 250);			// 旋风扫叶腿

	map_skill("force", "bibo_shengong");		//设置NPC当前内功为碧波神功
	map_skill("sword", "yuxiao_jianfa");	        //设置NPC的基本剑法装备玉萧剑法
	map_skill("dodge", "anying_fuxiang");		//设置NPC的基本躲闪装备暗影浮香
	map_skill("parry", "xuanfeng_leg");		//设置NPC的基本招架装备旋风扫叶腿
	map_skill("finger", "tanzhi_shentong");		//设置NPC的基本指法装备弹指神通

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力
	
	prepare_skill("finger", "tanzhi_shentong");

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
		perform_action("parry kuangfeng", 1);	//旋风扫叶腿(狂风绝技)
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
