//pub_huanhai.h 幻海
//wjc 2002-02-24

NPC_BEGIN(CNpub_huanhai);


virtual void create()
{
	set_name("幻海", "huan hai");
	set("gender", "女性");
	set("age", 60);
	set("long", "自小因被抛弃而造成心理上的扭曲，虽有一身道家神功，但仍有时不能控制自己的举止。");
	
	set("attitude", "peaceful");		//设置NPC态度
	set("icon",old_woman);			    //设置人物形象
	
	set("str", 25);
	set("int", 35);
	set("con", 35);
	set("dex", 40);
	
	set("chat_chance", 5);			    //设置自动聊天触发率
	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
	
	set("hp", 15000);
	set("max_hp", 15000);
	set("mp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 50);
	
	set("combat_exp", 1300000);
	set("score", 50000);
	
	set_skill("force", 170);			        // 基本内功
	set_skill("xuantian_shengong", 170);		// 玄天神功
	set_skill("finger", 170);			        // 基本指法
	set_skill("sun_finger", 170);		        // 正品一阳指
	set_skill("dodge", 170);			        // 基本躲闪
	set_skill("lingboweibu", 170);		    	// 凌波微步
	set_skill("parry", 170);			        // 基本招架
	
	map_skill("force", "xuantian_shengong");		//设置NPC当前内功为玄天神功
	map_skill("finger", "sun_finger");	            //设置NPC的基本指法装备正品一阳指
	map_skill("dodge", "lingboweibu");		        //设置NPC的基本轻功装备凌波微步
	map_skill("parry", "sun_finger");		        //设置NPC的基本招架装备正品一阳指
	
	prepare_skill("finger", "sun_finger");
	set("apply/armor", 100);
    set("apply/damage", 40);
}


virtual char * chat_msg_combat()			        //NPC自动发绝招
{
	switch(random(5))
	{
	case 0:
		perform_action("finger qiankun", 1);	    //正品一阳指的绝招
		break;
	case 1:
		perform_action("force recover", 0);	        //自动吸气
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
	DESTRUCT_OB(this, "pub_huanhai::chat_msg");
	return 0;
}

NPC_END;




