//pub_sangyuan.h 桑原和真
//wjc 2002-02-24

NPC_BEGIN(CNpub_sangyuan);


virtual void create()
{
	set_name("桑原真", "sang yuan");
	set("nickname", "桑原");
	set("gender", "男性");
	set("age", 19);
	set("long", "看起来不象是个中土人士，眉目里透露出阴深奸诈。");
	
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",young_man3);			    //设置人物形象
	
	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 42);
	
	set("chat_chance", 5);
	set("chat_chance_combat", 10);		 //设置NPC使用绝招的几率
	
	set("hp", 25500);
	set("max_hp", 25500);
	set("mp", 10000);
	set("max_mp", 10000);
	set("mp_factor", 80);
	
	set("combat_exp", 2000000);
	set("score", 50500);
	
	set_skill("force", 170);			      // 基本内功
	set_skill("jiuyang_shengong", 170);		  // 九阳神功
	set_skill("sword", 170);			      // 基本剑法
	set_skill("lonely_sword", 170);		      // 独孤九剑
	set_skill("dodge", 170);			      // 基本躲闪
	set_skill("shenkong_xing", 170);          // 身空行
	set_skill("parry", 170);			      // 基本招架
	set_skill("hand",170);
	set_skill("strike", 170);
	set_skill("zhemei_shou",170);
	set_skill("liuyang_zhang",170);

	map_skill("strike","liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");

	map_skill("force", "jiuyang_shengong");		//设置NPC当前内功为九阳神功
	map_skill("sword", "lonely_sword");	        //设置NPC的基本剑法装备独孤九剑
	map_skill("dodge", "shenkong_xing");		//设置NPC的基本轻功装备身空行
//	map_skill("parry", "lonely_sword");		    //设置NPC的基本招架装备独孤九剑

	prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
	set("apply/armor", 150);
    set("apply/damage", 80);
	carry_object("changjian")->wield();
	
}

virtual char * chat_msg_combat()			    //NPC自动发绝招
{
	switch(random(5))
	{
	case 0:
		perform_action("sword pojian", 1);	    //独孤九剑的绝招
		break;
	case 1:
		perform_action("force recover", 0);   	//自动吸气
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
	DESTRUCT_OB(this, "pub_sangyuan::chat_msg");
	return 0;
}

NPC_END;



