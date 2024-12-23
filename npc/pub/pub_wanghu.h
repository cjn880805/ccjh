//pub_wanghu.h
//wuqing 2002-2-10 

NPC_BEGIN(CNpub_wanghu);

virtual void create()
{
	set_name("王虎","wang hu");
	set("long", "绿林大盗因为当初和林震南的私冤，专和福威镖局的过不去。");
	set("gender", "男性");
	set("age", 80);
	
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("icon",taoist);	
	set("title","飞天虎");
	set("max_hp", 15000);
	set("mp", 10000);
	set("max_mp", 10000);
	set("mp_force", 100);
	set("combat_exp", 1400000);
	set("score", 1200000);

	set_skill("force", 200);
	set_skill("taiji_shengong", 200);
	set_skill("dodge", 200);
	set_skill("tiyunzong", 200);
	set_skill("unarmed", 200);
	set_skill("taiji_quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji_jian", 200);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");	

	set("class", "taoist");
    set("apply/armor", 300);
	set("apply/damage", 150);
	set("chat_chance_combat", 60);
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	set("no_kill",1);//不被列入万劫谷的任务中

}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(! strlen(ask))
	{
		AddMenuItem("老兄，你该下岗了！", "xiagang", me);
		SendMenu(me);
		return 1;
	}
	else if(strcmp(ask, "xiagang") == 0)
	{
		me->set_temp("下岗",1);
		set("下岗",me->id(1));
		message_vision("小子，看来你是不想活了！",me);
		((CUser *)this)->Ready_PK();
		((CUser *)me)->Ready_PK();
		me->kill_ob(this);	
		this->kill_ob(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual char * chat_msg_combat(CChar * player)
{
	switch(random(4))
	{
	case 0:
		perform_action("sword lian", 1);
		break;
	case 1:
		perform_action("sword chan", 1);
		break;
	case 2:
		perform_action("sword sui", 1);
		break;
	case 3:
		perform_action("force recover",0);
		break;
	}

	return 0;
}

virtual void die()
{
	if(atoi(querystr("下岗")))
	{
		CUser * me;
		me=find_online(querystr("下岗"));
		if(me)
		{
			me->delete_temp("下岗");
			me->set_temp("劫镖",1);
		}
	}
	message_vision("$HIR风紧，兄弟们，我先扯乎！", this);
	destruct(this);
}

NPC_END;



