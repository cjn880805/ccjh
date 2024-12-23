//pub_youzhu.h 浦饭幽助
//wjc 2002-02-24

NPC_BEGIN(CNpub_youzhu);


virtual void create()
{
	set_name("浦饭助", "you zhu");
	set("nickname", "幽助");
	set("gender", "男性");
	set("age", 18);
	set("long", "看起来不象是中原人士，举止轻浮。");
	
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",young_man3);			    //设置人物形象
	
	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 45);
	
	set("chat_chance", 5);			    //设置自动聊天触发率
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
	
	set("hp", 16000);
	set("max_hp", 16000);
	set("mp", 12000);
	set("max_mp", 6000);
	set("mp_factor", 50);
	
	set("combat_exp", 1200000);
	set("score", 55000);
	
	set_skill("force", 170);			    // 基本内功
	set_skill("kurong_shengong", 170);		// 枯荣神功
	set_skill("finger", 170);			    // 基本指法
	set_skill("sun_finger", 170);		    // 正品一阳指
	set_skill("dodge", 170);			    // 基本躲闪
	set_skill("xiaoyaoyou", 170);			// 逍遥游
	set_skill("parry", 170);			    // 基本招架
	
	map_skill("force", "kurong_shengong");		//设置NPC当前内功为枯荣神功
	map_skill("finger", "sun_finger");	        //设置NPC的基本指法装备正品一阳指
	map_skill("dodge", "xiaoyaoyou");		    //设置NPC的基本轻功装备逍遥游
	map_skill("parry", "sun_finger");		    //设置NPC的基本招架装备正品一阳指

	prepare_skill("finger", "sun_finger");
	set("apply/armor", 100);
    set("apply/damage", 60);

	
}

char * chat_msg()
{
	message_vision("$N吹了声口哨，晃悠晃悠的远远离去。", this);
	DESTRUCT_OB(this, "pub_youzhu::chat_msg");
	return 0;

}

virtual char * chat_msg_combat()			    //NPC自动发绝招
{
	switch(random(5))
	{
	case 0:
		perform_action("finger qiankun", 1);	//正品一阳指的绝招
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
NPC_END;




