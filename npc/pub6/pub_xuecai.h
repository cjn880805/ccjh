//pub_xuecai.h 雪菜
//wjc 2002-02-24

NPC_BEGIN(CNpub_xuecai);

virtual void create()
{
	set_name("雪菜", "xue cai");
	set("nickname", "冰女");
	set("gender", "女性");
	set("age", 16);
	set("long", "看上去是一个感情受到挫折的人。");
	
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",young_woman3);			//设置人物形象
	
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 30);
	
	set("chat_chance", 5);			    //设置自动聊天触发率
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
	
	set("hp", 13000);
	set("max_hp", 13000);
	set("mp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 40);
	
	set("combat_exp", 1200000);
	set("score", 50000);
	
	set_skill("force", 170);			// 基本内功
	set_skill("yunv_xinjing", 170);		// 玉女心经
	set_skill("hand", 170);			    // 基本手法
	set_skill("lanhua_shou", 170);		// 兰花拂穴手
	set_skill("dodge", 170);			// 基本躲闪
	set_skill("lingboweibu", 170);      // 凌波微步
	set_skill("parry", 170);			// 基本招架
	
	map_skill("force", "yunv_xinjing");		//设置NPC当前内功为玉女心经
	map_skill("hand", "lanhua_shou");	    //设置NPC的基本手法装备兰花拂穴手
	map_skill("dodge", "lingboweibu");		//设置NPC的基本轻功装备凌波微步
	map_skill("parry", "lanhua_shou");		//设置NPC的基本招架装备兰花拂穴手

	prepare_skill("hand", "lanhua_shou");
	set("apply/armor", 100);
    set("apply/damage", 50);
	
}

char * chat_msg()
{
	message_vision("$N吹了声口哨，晃悠晃悠的远远离去。", this);
	DESTRUCT_OB(this, "pub_xuecai::chat_msg");
	return 0;
}

virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(5))
	{
	case 0:
		perform_action("hand fuxue", 1);	//兰花拂穴手的绝招
		break;
	case 1:
		perform_action("force recover", 0);	//自动吸气
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




