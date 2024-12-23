// xueshan_lama.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxueshan_lama);

virtual void create()
{
	set_name("喇嘛", "lama");
	set("long","这是一个高大喇嘛，两臂粗壮，膀阔腰圆，似乎不是中土人士。 ");
	
	set("gender", "男性");
	set("attitude", "aggressive");
	set("class", "bonze");
        set("icon",old_monk);
	
	set("age", 20+random(30));
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_hp", 1500);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 50+random(50));
	set("combat_exp", 50000);
	set("score", 1);
	
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("unarmed", 70);
	set_skill("parry", 70);
	set_skill("blade", 70);
	
	carry_object("jiedao")->wield();
	carry_object("cloth")->wear();
}

virtual void init(CChar * me)
{
	CNpc::init(me);
	if(userp(me) && !is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(!who || who->query_temp("hastrystab")==6) return;	

	if( !who->query_temp("warned2") ) 
	{
		if(who->query_temp("hastrystab")) 
			me->say("气死我了，你居然暗算我兄弟！");
		else
			me->say("你是谁，居然敢破坏大爷的好事，不想活了是不是？！");
		
		who->set_temp("warned2", 1);
	}
	else 
	{
		if(who->query_temp("hastrystab")) 
			me->say(" 我...我..一定要杀了你这背后捅人的江湖败类！");
		else
			me->say(" 你这家伙不要跑，让佛爷我宰了你！！！ ");
	
		me->kill_ob(who); 
	}	
}

NPC_END;