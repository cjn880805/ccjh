// pub_jiaojindaoren.h 角巾道人
// dieer 2002-8-10

NPC_BEGIN(CNpub_jiaojindaoren);

virtual void create()
{
	set_name("角巾道人", "jiaojin daoren");
	set("title", "三十三剑客之");
	set("gender", "男性");
	set("age", 50);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",13);				//设置人物形象
	set("per",16);
	
	set("str", 31);
	set("int", 33);
	set("con", 36);
	set("dex", 31);
	set("repute", 10000);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 60);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);

	set_skill("force", 350);			// 基本内功
	set_skill("taiji_shengong", 350);		// 太极神功
	set_skill("unarmed", 350);			// 基本拳脚
	set_skill("taiji_quan", 350);			// 太极拳
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("tiyunzong", 350);			// 梯云纵
	set_skill("parry", 350);			// 基本招架

	map_skill("force", "taiji_shengong");		//设置NPC当前内功为太极神功
	map_skill("unarmed", "taiji_quan");	        //设置NPC的基本拳脚装备太极拳
	map_skill("dodge", "tiyunzong");		//设置NPC的基本躲闪装备梯云纵
	map_skill("parry", "jingang_quan");		//设置NPC的基本招架装备大金刚拳

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 90);			//设置NPC附加攻击力
}


virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(6))
	{
	case 0:
		perform_action("unarmed zhenup", 1);	//太极拳神功震敌
		break;
	case 1:
		perform_action("force recover", 0);	//自动吸气
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