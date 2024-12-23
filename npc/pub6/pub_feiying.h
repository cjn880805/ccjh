//pub_feiying.h 飞影
//wjc 2002-02-24

NPC_BEGIN(CNpub_feiying);


virtual void create()
{
	set_name("飞影", "fei ying");
	set("gender", "男性");
	set("age", 19);
	set("long", "夜行贼");
	
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",young_man4);			    //设置人物形象
	
	set("str", 35);
	set("int", 34);
	set("con", 34);
	set("dex", 40);

	set("chat_chance", 5);
	set("chat_chance_combat", 10);		 //设置NPC使用绝招的几率
	
	set("hp", 15000);
	set("max_hp", 15000);
	set("mp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 50);
	
	set("combat_exp", 1600000);
	set("score", 50000);
	
	set_skill("force", 170);			    // 基本内功
	set_skill("huntian_qigong", 170);		// 混天气功
	set_skill("unarmed", 170);			    // 基本拳脚
	set_skill("xianglong_zhang", 170);		// 降龙十八掌
	set_skill("dodge", 170);			    // 基本躲闪
	set_skill("guimei_shenfa", 170);		// 鬼魅身法
	set_skill("parry", 170);			    // 基本招架
	
	map_skill("force", "huntian_qigong");		//设置NPC当前内功为混天气功
	map_skill("unarmed", "xianglong_zhang");	//设置NPC的基本拳脚装备降龙掌
	map_skill("dodge", "guimei_shenfa");		//设置NPC的基本轻功装备鬼魅身法
	map_skill("parry", "xianglong_zhang");		//设置NPC的基本招架装备降龙掌

	set("apply/armor", 100);
    set("apply/damage", 40);
	prepare_skill("unarmed","xianglong_zhang");
	
}


virtual char * chat_msg_combat()			    //NPC自动发绝招
{
	switch(random(5))
	{
	case 0:
		perform_action("unarmed xianglong", 1);	//降龙掌的绝招
		break;
	case 1:
		perform_action("force recover", 0);	    //自动吸气
		break;
	
	}	
	return 0;
}

virtual void die()
{
	message_vision("$HIR风紧，兄弟们，我先扯乎！", this);
	destruct(this);
}

char * chat_msg()
{
	message_vision("$N吹了声口哨，晃悠晃悠的远远离去。", this);
	DESTRUCT_OB(this, "pub_feiying::chat_msg");
	return 0;
}

NPC_END;




