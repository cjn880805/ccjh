// yinchang_zhang.c 张三丰

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_zhang);

virtual void create()
{
	set_name("张三丰","zhang sanfeng");
	set("nickname", "邋遢真人");
	set("long", "他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。身穿一件污秽的灰色道袍，不修边幅。身材高大，年满百岁，满脸红光，须眉皆白。");
	set("gender", "男性");
	set("age", 100);
        set("icon",old_man1);

	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_hp", 15000);
	set("mp", 5000);
	set("max_mp", 5000);
	set("mp_factor", 100);
	set("combat_exp", 2000000);
	set("score", 500000);
	set_skill("force", 200);
	set_skill("taiji_shengong", 200);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 150);
	set_skill("unarmed", 200);
	set_skill("taiji_quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji_jian", 200);
	set_skill("liangyi_jian", 200);
	set_skill("wudang_jian", 200);
	set_skill("taoism", 150);
	set_skill("literate", 100);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "liangyi_jian");
	
	create_family("武当派", 1, "开山祖师");
	set("class", "taoist");
	
	carry_object("changjian")->wield();
}
/*
	set("chat_msg_combat", ({
		(: perform_action, "sword.ren" :),
			(: exert_function, "powerup" :),
			(: exert_function, "recover" :),
	}) );
	*/
virtual char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("sword ren", 1);
		break;
	case 1:
		perform_action("force powerup", 0);
		break;
	case 2:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

/*
virtual char * greeting(CChar * ob)
{
	CContainer *obj;
	int i;
	
	obj = all_inventory(me->environment());
	say(" 这招好象应该这样，直中有曲，曲中有直。");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="feng-qingyang")
		{
			Do_Attack(this, ob, 0 );
			Do_Attack(this, ob, 0 );
		}
	}
	return "";
}
*/

NPC_END;