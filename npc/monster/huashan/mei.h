//mei.h
//梅念笙·秘密ＮＰＣ·华山·神照经·难度5０
//Teapot 2001-02-07

MONSTERHUASHAN_BEGIN(CNhuashan_mei);

virtual void create()
{	 
	set_name("梅燕笙", "mei");
	set("title", "烟雨漫天");
	set("gender", "男性");
	set("age", 77);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", old_man1);
	set("level",80);

	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	
	set("hp", 12500);
	set("max_hp", 25500);
	
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 250);

	set("combat_exp", 10000000);
	set("score", 2000000);

	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("sword", 350);
	set_skill("literate", 300);
	set_skill("unarmed", 300);

	set_skill("shenzhao_gong", 300);
	set_skill("piaoyibu", 300);
	set_skill("doomsword", 350);
	set_skill("changquan", 300);

	map_skill("force", "shenzhao_gong");
	map_skill("dodge", "piaoyibu");
	map_skill("sword", "doomsword");
	map_skill("parry", "doomsword");
	map_skill("unarmed", "changquan");

	set("chat_chance_combat", 30);
	set("nkgain", 4000);    

	set("no_缠字决",1);
	set_temp("apply/no_势合形离",1);
	set("bigboss",1);

	carry_object("plumsword")->wield();
};


virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("teapot/xmdog"))
	{
		AddMenuItem("向梅燕笙打听关于连城剑法的消息", "$0liancheng $1", me);
		SendMenu(me);
		return 1;
	}

	return CNpc::do_talk(me, ask);
}

virtual int handle_action(char * comm, CChar * me, char * arg)
{
	if(me->query_temp("teapot/xmdog"))
	{
		 if(strcmp(comm, "liancheng") == 0)
			return kill_me(me);
		 if(strcmp(comm, "qiang") == 0)
			 return qiang(me);
	}

	return CNpc::handle_action(comm, me, arg);
}

int kill_me(CChar * me)
{
		say("梅燕笙悠长的叹了口气。", me);
		say("世间之人，为何总是如此之贪？", me);
		say("纵能练就天下无敌的武功，到头来也不过是一捧黄土而已。", me);
		say("古来将相今何在？百年惟见山水存……", me);

		if (me->query("repute")<=10000 && me->query_temp("teapot/xmdog") > 3)
		{
			AddMenuItem("老头子，什么废话这么多！你交是不交？", "$0qiang $1", me);
		}
		
		me->add_temp("teapot/xmdog", 1);
		AddMenuItem("继续向老先生询问连城剑法的事情。", "$0liancheng $1", me);
		AddMenuItem("老先生教训的是，晚辈受教了。", "", me);		
		SendMenu(me);
		return 1;
}

int qiang(CChar * me)
{
	tell_object(me, "你连问三声，梅燕笙却不回答，你一怒之下，向他出手！");
	me->set_temp("teapot/lcj",1);
	me->set_temp("teapot/lcj2", current_time);
	me->kill_ob(this);		
	return 1;
}

virtual void die()
{
	CChar * me;
	me=(CChar *)find_object(query_temp("last_damage_from"), 1);
	
	if(! me)		//smash no killer
	{
		CNpc::die();
		return;
	}

	if (!me->query_temp("teapot/lcj") || me->query_temp("teapot/lcj") == 0 || me->query_temp("teapot/lcj3") || me->query_temp("teapot/lcj4") || me->query_temp("teapot/lcj5"))
	{
		revive(1);
		message_vision("$N望空中深深的吸了口气。", this);
		set("max_hp",30000);
		set("eff_hp",30000);
		set("hp",30000);
		set("mp", 3000);
		set("max_mp", 3000);
		set_temp("apply/damage", query_temp("apply/damage")+60);			//设置NPC附加攻击力
		set_temp("apply/armor", query_temp("apply/armor")+60);			//设置NPC附加防御力
		set_temp("apply/attack", query_temp("apply/attack")+60);
		set_temp("apply/defense", query_temp("apply/defense")+60);
		return;
	}
	me->set_temp("teapot/lcj",0l);
	me->set_temp("teapot/lcj3",0l);
	me->set_temp("teapot/lcj4",0l);
	me->set_temp("teapot/lcj5",0l);

	CChar * qi;
	CChar * yan;
	CChar * wang;

	qi=load_npc("huashan_qi");
	yan=load_npc("huashan_yan");
	wang=load_npc("huashan_wang");

	CContainer * env = me->environment();

	qi->move(env);
	yan->move(env);
	wang->move(env);

	CContainer * ob;
	ob=load_item("poembook");
	ob->move(me);
	
	message_vision("$N一弯腰自梅燕笙尸体上寻出一本黄皮小册子...", me);
	message_vision("突然只见三道黑影一掠而过，将$N围在核心！", me);
	message_vision("三人一言不发，便向$N出手！", me);
	
	qi->set_killer(me);
	yan->set_killer(me);
	wang->set_killer(me);

	if(env->Query(IS_FIGHTROOM))
	{
		CFightRoom * fi = (CFightRoom *)env;

		fi->Join_Team(qi, query_team());
		fi->Join_Team(yan, query_team());
		fi->Join_Team(wang, query_team());
	}
	else
	{		
		qi->kill_ob(me);
	}
	
	CNpc::die();

	return;
}

MONSTERHUASHAN_END;

// Group: * Mei,* Qi,* Yan,* Wang,* PoemBook,* PlumSword,DoomSword,ShenZhaoGong.