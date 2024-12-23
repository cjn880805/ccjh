//lihongzhi.h 邪魔李洪志
//Coded by Teapot 2000-02-06

NPC_BEGIN(CNxiyu_lhz);

virtual void create()
{
	set_name("李白痴", "li baichi");
	
	set("title", "齿轮");
	set("gender", "男性");
	set("age", 64);
	set("shen_type", -1);
	set("attitude", "friendly");
	set("icon", old_man2);

	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("falun/know",100);

	set("hp", 12500);
	set("max_hp", 32500);
	
	set("mp", 15000);
	set("max_mp", 15000);
	set("mp_factor", 350);

	set("combat_exp", 10000000);
	set("score", 200000);

	set_skill("force", 300);
	set_skill("strike", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("blade", 350);
	set_skill("literate", 80);

	set_skill("falun_step", 300);
	set_skill("falun_gong", 300);
	set_skill("falun_zhanfa", 300);
	set_skill("falun_daofa", 300);

	map_skill("force", "falun_gong");
	map_skill("dodge", "falun_step");
	map_skill("strike", "falun_zhanfa");
	map_skill("blade", "falun_daofa");
	map_skill("parry", "falun_daofa");

	create_family("齿轮教",1, "教主");
	set("chat_chance_combat", 60);
	set("nkgain", 4000);



    set_inquiry("自焚", "自焚乃齿轮大法修炼至最高境界的必经道路。");
	//set_inquiry("陈果", "陈果MM修炼大法升仙，不错不错。");
	set_inquiry("真善忍", ask_tgm);
	set_inquiry("生日", ask_birthday);

	carry_object("falunblade")->wield();
	add_money(10000);
};

static char * ask_tgm(CNpc * me, CChar * who)
{
	if(!who->query("falun/know") || who->query("falun/know")<100)
	{
		me->say("伪就是假话真说，恶就是为人伪善，丑就是忍无可忍。");
		me->say("这就是我齿轮教的真善忍，你要记牢了。");
		who->add("falun/know",1);

		who->set("title","齿轮教「忍」字辈长老");		//90~99
		if(who->query("falun/know")<30)
			who->set("title","齿轮教教众");
		if(who->query("falun/know")<60)
			who->set("title","齿轮教「真」字辈长老");
		if(who->query("falun/know")<90)
			who->set("title","齿轮教「善」字辈长老");

		return "你好象领悟了一点什么！";
	}
	else
	{
		me->say("你已经完全领悟了齿轮大法的真义。");
		who->set("title","齿轮大法继承人");
		return "你成为齿轮功大法继承人！";
	}
}

static char * ask_birthday(CNpc * me, CChar * who)
{
		me->say("你看来已经知道我的生日了？");
		me->say("既然如此，留你不得！");
		me->kill_ob(who);
        return "看来李白痴想杀死你！";
}


virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if(me->query("per")<22 )
    {
        this->say("你长得不象是个好人，没有煽动性，我不收！");
		SendMenu(me);
		return;
    }
	me->set("class","falun");
	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	return;
}


virtual int accept_fight(CChar *me)
{
	char msg[20];

	say("齿轮大法弟子讲究忍，从来不和人比试！");
	say("所以我只好杀了你！");
	command(snprintf(msg, 20, "kill %ld", me->object_id()));
	return 0;
}


virtual char * chat_msg_combat()
{
	switch(random(4))
	{
	case 0:
		perform_action("blade zhuang", 1);
		break;
	case 1:
		perform_action("strike zhen", 1);
		break;
	case 2:
		perform_action("strike shan", 1);
		break;
	case 3:
		perform_action("strike ren", 1);
		break;
	}

	return 0;
}

NPC_END;
