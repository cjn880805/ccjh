// pub_fengwuchang.h 风无常
// jaja 2002-10-20

NPC_BEGIN(CNpub_fengwuchang);

virtual void create()
{
	set_name("风无常", "feng wuchang");
	set("title", "风中之神");
	set("gender", "男性");
	set("age", 30);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",17);				//设置人物形象
	set("repute", -5000);
	
	set("str", 24);
	set("int", 20);
	set("con", 23);
	set("dex", 20);
	
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
	set_skill("leg", 250);			        // 基本腿法
	set_skill("xuanfeng_leg", 250);			// 狂风扫叶腿

	map_skill("force", "bibo_shengong");		//设置NPC当前内功为碧波神功
	map_skill("leg", "xuanfeng_leg");	        //设置NPC的基本腿法装备狂风扫叶腿
	map_skill("dodge", "anying_fuxiang");		//设置NPC的基本躲闪装备暗影浮香
	map_skill("parry", "xuanfeng_leg");		//设置NPC的基本招架装备狂风扫叶腿
	map_skill("finger", "tanzhi_shentong");		//设置NPC的基本指法装备弹指神通

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 30);			//设置NPC附加攻击力

	prepare_skill("leg", "xuanfeng_leg");	//设置NPC的空手组合
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("parry kuangfeng", 1);	//旋风扫叶腿(kuangfeng狂风绝技)
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

