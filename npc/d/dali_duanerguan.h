//duanerguan.h
//code by zwb
//12-16
//inherit F_MASTER;

NPC_BEGIN(CNDaLi_duanerguan);

virtual void create()
{
	set_name("段恶贯","duan er guan");

        set("gender", "男性");
        set("nickname","恶贯满盈");
        set("age", 45);
        set("long","他就是四大恶人之首，人称恶贯满盈的段恶贯。他本是大理段氏皇子，由于大臣反叛作乱而双腿残废、罹毒甚深。脸上常年戴一张人皮面具，喜怒哀乐一丝不露。体格瘦长，双腿齐膝而断,只能用腋下的两根镔铁拐杖代步，但行走如飞，反比常人更快！");
        set("attitude", "peaceful");
 	set("icon",old_man1);

        set("str", 60);
        set("int", 35);
        set("con", 35);
        set("dex", 50);
        set("per", 14);

        set("chat_chance_combat", 3);
  
	set("chat_chance", 8);
        set("hp", 4000);
        set("max_hp", 12000);
        set("mp", 30000);
        set("max_mp", 3000);
        set("mp_factor", 500);

        set("combat_exp", 180000);
        set("shen_type", -1);

        set_skill("force", 120);
        set_skill("hunyuan_yiqi", 120);
        set_skill("hand", 120);              // 基本手法
        set_skill("shexing_diaoshou", 120);
        set_skill("dodge", 120);
        set_skill("xiaoyaoyou", 120);        // 逍遥游
        set_skill("parry", 120);
        set_skill("staff", 120);
        set_skill("tianshan_zhang", 120);

        map_skill("force", "hunyuan_yiqi");
        map_skill("hand", "shexing_diaoshou");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "tianshan_zhang");
        map_skill("staff", "tianshan_zhang");

        carry_object("gangzhang")->wield();
        carry_object("cloth")->wear();
};

virtual char * chat_msg(CChar *me)
{
	switch(random(2))
	{
	case 0:
		return "段恶贯叹了口气道：“唉……不知何时才能重登大理宝座！”";
	case 1:
		return "段恶贯喃喃道：“段贞德那厮若知我回来，定会将皇位拱手相让，哈哈哈！";
	}
	return "";
}

virtual char * chat_msg_combat(CChar *me)
{
	char msg[255];

	command(snprintf(msg, 255,"cast force recover"));
	return "";
}

virtual void init(CChar * me)
{
	remove_call_out(check_skills);
	call_out(check_skills,2, me->object_id());
}

static void check_skills(CContainer * ob,LONG param1,LONG param2)
{
	CMapping * skl;

	CChar * npc=(CChar *)ob;
	CChar * player=(CChar *)(ob->environment())->Present(param1);

	if(! player ) return;

    int counter, npc_shen;

	skl=player->query_skills();

	npc_shen = player->query("repute");

	counter=0;

	CVector v;

	skl->keys(v);

	for(int i=0; i<v.count(); i++)
	{
		if((* skl)[v[i]] <100 )
			counter++;
	}

	if((counter>=3) && (npc_shen>0))
	{
		if(!(player->environment())->query("no_fight"))
		{
			npc->call_out(do_kill,1,param1);
			return ;
		}
		else
		{
			npc->call_out(waiting,0,param1);
			return ;
		}
	}
	return ;
}

static void do_kill(CContainer * ob,LONG param1 ,LONG param2)
{
	CChar * npc =(CChar *)ob;
	CChar * player=(CChar *)(ob->environment())->Present(param1);

	if(player && ! (npc->environment())->query("no_fight"))
	{
		message_vision("$N对$n说道：老子一见正派高手就生气。纳命来!",npc,player);
		npc->kill_ob(player);
		player->fight_ob(npc);

		npc->call_out(checking,0,param1);
	}
	else
		npc->call_out(waiting,1,param1);

}

static void waiting(CContainer * ob,LONG param1, LONG param2)
{
	CChar * npc =(CChar *)ob;
	CChar * player=(CChar *)(ob->environment())->Present(param1);

	if(player)
	{
		if(npc->is_fighting() )
		{
			npc->call_out(checking,0,param1);
			return ;
		}
		else if(living(npc) && ! (player->environment())->query("no_fight"))
			return ;
	}

	npc->remove_call_out(waiting);
	npc->call_out(waiting,60);
}

static void checking(CContainer * ob, LONG param1 ,LONG param2)
{
	CChar * npc =(CChar *)ob;
	CChar * player=(CChar *)(ob->environment())->Present(param1);
	CContainer * obj;

	if(npc->is_fighting())
	{
		npc->call_out(checking,1);
		return ;
	}

	obj=(npc->environment())->present("corpse");

	if(obj && EQUALSTR(obj->querystr("victim_name"), player->querystr("name")))
	{
		npc->call_out(do_back,1,param1);
		return ;
	}

	npc->call_out(waiting,0,param1);
}

static void do_back(CContainer * ob ,LONG param1,LONG param2)
{
	CChar * npc =(CChar *)ob;

	npc->move(load_room("xidajie2"));
	npc->say("又除了一个道貌岸然的伪君子。");

}
NPC_END;
