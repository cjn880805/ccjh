// pub_jinxilaoren.h 京西店老人
// dieer 2002-7-27

NPC_BEGIN(CNpub_jinxilaoren);

virtual void create()
{
	set_name("京西店老人", "jinxi laoren");
	set("title", "三十三剑客之");
	set("gender", "男性");
	set("age", 60);
	set("level", 157);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",19);				//设置人物形象
	set("per",20);	
	set("repute", 10000);			//设置NPC好坏
	
	set("str", 37);
	set("int", 32);
	set("con", 35);
	set("dex", 36);
	
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 70);			//设置NPC加力参数
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// 基本内功
	set_skill("taiji_shengong", 350);		// 太极神功
	set_skill("unarmed", 350);			// 基本拳脚
	set_skill("taiji_quan", 350);			// 太极拳
	set_skill("dodge", 350);			// 基本躲闪
	set_skill("tiyunzong", 350);			// 梯云纵
	set_skill("parry", 350);			// 基本招架
	set_skill("sword", 350);			// 基本剑法
	set_skill("taiji_jian", 350);			// 太极剑

	map_skill("force", "taiji_shengong");		//设置NPC当前内功为太极神功
	map_skill("unarmed", "taiji_quan");	        //设置NPC的基本拳脚装备太极拳
	map_skill("dodge", "tiyunzong");		//设置NPC的基本躲闪装备梯云纵
	map_skill("parry", "jingang_quan");		//设置NPC的基本招架装备大金刚拳
	map_skill("sword", "taiji_jian");		//设置NPC的基本剑法装备太极剑

	set("apply/armor", 160);			//设置NPC附加防御力
	set("apply/damage", 80);			//设置NPC附加攻击力

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

NPC_END;
