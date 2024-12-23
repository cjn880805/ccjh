//pub_wooden 少林无敌木人
//Coded by Teapot 2000-02-17

NPC_BEGIN(CNpub_wooden);

virtual void create()
{
	set_name("木人", "wooden man");
	set("gender", "无性");
	set("age", 100);
	set("attitude", "friendly");
	set("icon", old_man2);

	set("no_get",1);
	
	set("str", 25);
	set("int", 45);
	set("con", 50);
	set("dex", 25);
	
	set("mp", 3000);
	set("max_mp", 5000);
	set("mp_factor", 40);

	set("combat_exp", 1500000);

	set_skill("force", 200);
	set_skill("hunyuan_yiqi", 200);
	set_skill("dodge", 200);
	set_skill("shaolin_shenfa", 200);
	set_skill("parry", 200);

	set_skill("finger", 200);
	set_skill("yizhi_chan", 200);

	set_skill("whip", 200);
	set_skill("riyue_bian", 200);

	set_skill("sword", 200);
	set_skill("wuying_jian", 200);

	set_skill("cuff", 200);
	set_skill("jingang_quan", 200);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("finger", "yizhi_chan");
	map_skill("whip", "riyue_bian");
	map_skill("sword", "wuying_jian");
	map_skill("cuff", "jingang_quan");

	set("chat_chance_combat", 20);

	int i;
	i=random(4);
	set("type",i);

	switch(i)
	{
	case 0:
		map_skill("parry","yizhi_chan");
		prepare_skill("finger", "yizhi_chan");
		break;
	case 1:
		map_skill("parry","riyue_bian");
		prepare_skill("finger", "yizhi_chan");
		carry_object("tiebian")->wield();
		break;
	case 2:
		map_skill("parry","wuying_jian");
		prepare_skill("cuff", "jingang_quan");
		carry_object("plumsword")->wield();
		break;
	case 3:
		map_skill("parry","jingang_quan");
		prepare_skill("cuff", "jingang_quan");
		break;
	}



};



virtual char * chat_msg_combat()
{
	add("mp_factor", 5);
	set("mp",3000);

	if (query("chat_chance_combat") < 80)
		add("chat_chance_combat", 5);

	if(random(2))
	{
		switch(query("type"))
		{
		case 0:
			perform_action("finger dian", 1);
			break;
		case 1:
			perform_action("whip chan", 1);
			break;
		case 2:
			perform_action("sword wuying", 1);
			break;
		case 3:
			perform_action("cuff jingang", 1);
			break;
		}
		return 0;
	}
	else
	{
		if(random(2))
		{
			message_vision("木人大阵团团旋转，又紧了一分！",this);
			add("str",random(2)+1);

		}
		else
		{
			message_vision("木人大阵团团旋转，速度越来越快！",this);
			add("dex",random(2)+1);
		}

	}

	return 0;
}



virtual void die()
{
	CContainer * me = environment();

	if(userp(me))
		tell_object((CChar *)me, "木人炸成了一堆碎片。");
	else
		tell_room(me, "木人炸成了一堆碎片。");

	destruct(this);
	return;
}


NPC_END;
