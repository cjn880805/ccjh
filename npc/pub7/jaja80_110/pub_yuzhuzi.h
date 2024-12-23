// lev2_yuzhuzi.h 玉珠子
// jaja 2002-12-23

LEV2_BEGIN(CNlev2_yuzhuzi);

virtual void create()
{
	set_name("玉珠子", "yu zhuzi");
	set("title", "护国真人");
	set("gender", "男性");
	set("age", 50);
	set("level", 100);
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",13);				//设置人物形象
	set("repute", -8000);
	
	set("str", 27);
	set("int", 26);
	set("con", 29);
	set("dex", 29);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 12000+random(3000));
	set("max_mp", 7000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 6000000+random(6000000));
	set("score", 6000);
	
	set_skill("force", 230+random(30));			// 基本内功
	set_skill("taiji_shengong", 230+random(30));		// 太极神功
	set_skill("unarmed", 230+random(30));			// 基本拳脚
	set_skill("taiji_quan", 230+random(30));			// 太极拳
	set_skill("dodge", 230+random(30));			// 基本躲闪
	set_skill("tiyunzong", 230+random(30));			// 梯云纵
	set_skill("parry", 230+random(30));			// 基本招架
	set_skill("sword", 230+random(30));			// 基本剑法
	set_skill("taiji_jian", 230+random(30));			// 太极剑

	map_skill("force", "taiji_shengong");		//设置NPC当前内功为太极神功
	map_skill("unarmed", "taiji_quan");	        //设置NPC的基本拳脚装备太极拳
	map_skill("dodge", "tiyunzong");		//设置NPC的基本躲闪装备梯云纵
	map_skill("parry", "jingang_quan");		//设置NPC的基本招架装备大金刚拳
	map_skill("sword", "taiji_jian");		//设置NPC的基本剑法装备太极剑

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 40);			//设置NPC附加攻击力

	carry_object("changjian")->wield();	

}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("sword chan", 1);	//太极剑 chan
		break;
	case 1:
		perform_action("sword lian", 1);	//太极剑 lian
		break;
	case 2:
		perform_action("sword sui", 1);		//太极剑 sui
		break;
	case 3:
		perform_action("unarmed zhenup", 1);	//太极拳神功震敌
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

LEV2_END;

