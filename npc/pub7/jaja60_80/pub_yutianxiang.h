// lev1_yutianxiang.h 余天祥
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_yutianxiang);

virtual void create()
{
	set_name("余天祥", "yu tianxiang");
	set("title", "勾魂岛主");
	set("gender", "男性");
	set("age", 50);
	set("level", 100);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",14);				//设置人物形象
	set("repute", -4000);
	
	set("str", 21);
	set("int", 23);
	set("con", 23);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//设置NPC使用绝招的几率
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//设置NPC加力参数
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// 基本内功
	set_skill("taiji_shengong", 190+random(30));		// 太极神功
	set_skill("unarmed", 190+random(30));			// 基本拳脚
	set_skill("taiji_quan", 190+random(30));			// 太极拳
	set_skill("dodge", 190+random(30));			// 基本躲闪
	set_skill("tiyunzong", 190+random(30));			// 梯云纵
	set_skill("parry", 190+random(30));			// 基本招架

	map_skill("force", "taiji_shengong");		//设置NPC当前内功为太极神功
	map_skill("unarmed", "taiji_quan");	        //设置NPC的基本拳脚装备太极拳
	map_skill("dodge", "tiyunzong");		//设置NPC的基本躲闪装备梯云纵
	map_skill("parry", "jingang_quan");		//设置NPC的基本招架装备大金刚拳

	set("apply/armor", 100);			//设置NPC附加防御力
	set("apply/damage", 10);			//设置NPC附加攻击力
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("unarmed zhenup", 1);	//太极拳神功震敌
		break;
	case 1:
			//自动吸气
		break;
	case 2:
			//自动吸气
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