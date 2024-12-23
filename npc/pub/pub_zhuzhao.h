//pub_zhuzhao.h 
//wuqing 2002-02-15

NPC_BEGIN(CNpub_zhuzhao);

virtual void create()
{
	set_name("朱照", "zhu zhao");
	set("gender", "男性");
	set("age", 66);
	set("class", "taoist");
	set("nickname", "佛面恶道");
	set("long","他就是全真教的。他白须飘飘，眉目清癯，颇有些仙风道骨的味道却做恶多端。");
	set("shen_type",1);
	set("str", 45);
	set("int", 45);
	set("con", 45);
	set("dex", 45);
	set("foolid",33);
	set("chat_chance_combat", 50);
	
	set("hp", 19500);
	set("max_hp", 19500);
	
	set("mp", 15000);
	set("max_mp", 15000);
	set("mp_factor", 120);
	
	set("combat_exp", 3000000);
	set("score", 500000);
	
	set_skill("force", 280);
	set_skill("sword", 280);
	set_skill("dodge", 300);
	set_skill("parry", 280);
	set_skill("unarmed",300);
	set_skill("strike",280);
	set_skill("finger",280);
	set_skill("literate",180);
	set_skill("taoism",250);
	set_skill("xiantian_qigong", 260);
	set_skill("xiantian_gong", 280);
	set_skill("quanzhen_jianfa",250);  
	set_skill("quanzhen_jian",280);  
	set_skill("jinyan_gong", 250);   
	set_skill("haotian_zhang", 250);    
	set_skill("sun_finger",250);  

	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jianfa");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jianfa");
	map_skill("strike", "haotian_zhang");
	map_skill("finger","sun_finger");

	prepare_skill("finger","sun_finger");
	prepare_skill("strike","haotian_zhang");

	set("no_kill",1);//不被列入万劫谷的任务中
	
	carry_object("changjian")->wield();
//	carry_object("greenrobe")->wear();
	
}

virtual char * chat_msg_combat()
{
	char msg[40];
	CContainer * changjian = present("changjian");

	switch(random(19))
	{
	case 0:
	case 1:
		perform_action("force recover", 0);
		break;
	case 2:
	case 3:
	case 4:
		perform_action("strike ju", 1);
		break;
	case 5:
	case 6:
	case 7:
		perform_action("sword ding", 1);
		break;
	case 8:
	case 9:
	case 10:
	case 11:
		if(query_weapon() == changjian && changjian)
			command(snprintf(msg, 40, "unwield %ld", changjian->object_id()));
		break;
	case 12:
	case 13:
	case 14:
	case 15:
		if(! query_weapon() && changjian)
			command(snprintf(msg, 40, "wield %ld", changjian->object_id()));
		break;
	case 16:
	case 17:
	case 18:
		perform_action("finger qiankun", 1);
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



