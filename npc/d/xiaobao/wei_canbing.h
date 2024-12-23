// wei_canbing.h 吴三桂军残余部众
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNwei_canbing);

virtual void create()
{
	set_name("吴三桂军残余部众", "can bing" );

	set("icon", general);
	set("gender", "男性");
	set("age", random(20) + 30);
	set("str", 30);
	set("dex", 22);
	set("long", "这人一看就是刚刚打过败仗的残兵。");
	set("combat_exp", 100000);

	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("blade", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 90);
	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);
 	carry_object("gangdao")->wield();

	call_out(do_die, 900);
	set("no_kill",1);
}

void init(CChar * me)
{
	CNpc::init(me);
	if(me->query("help") && !is_fighting())
		kill_ob(me);
}

virtual void die()
{
	if(querystr("owner")[0])
	{
		CContainer * me;
		CContainer * env=environment();
		me=env->present(querystr("owner"));

		if(me)
		{
			me->add_temp("wei/renwu3_3",1);//打倒吴三桂军残余部众一名
			if(me->query_temp("wei/renwu3_3")==2 && !me->query_temp("wei/renwu3_4"))
			{
				me->set_temp("wei/renwu3_4",1);//获得「带血的素笺」
				load_item("xueshujian")->move(env);
			}
		}
	}
	destruct(this);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	destruct(npc);
}
NPC_END;