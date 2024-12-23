// pub_guanzho5.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_guanzho5);

virtual void create()
{
	set_name("观众戊", "guan zhong5");

	set("icon", young_man4);
	set("long", "此人相貌奇丑，狮鼻阔口，一望而知不是中土人士。");
	set("gender", "男性");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 28);
	set("int", 20);
	set("con", 26);
	set("dex", 22);
	set("max_hp", 600);
	set("mp", 200);
	set("max_mp", 200);
	set("mp_factor", 5);
	set("combat_exp", 20000);
	set("score", 30000);
	set_skill("dodge", 40);
	set_skill("zhaixinggong", 30);
	set_skill("unarmed", 50);
	set_skill("xingxiu_duzhang", 40);
	set_skill("parry", 60);
	map_skill("dodge", "zhaixinggong");
	map_skill("unarmed", "xingxiu_duzhang");
	map_skill("parry", "xingxiu_duzhang");
	carry_object("cloth")->wear();
}

virtual void init(CChar *me)
{
	CNpc::init(me);

	if (! is_fighting() && userp(me) && !me->environment()->query("no_fight"))
	{
		if( ! me->query_temp("warned") )
		{
			say("今天看戏不成，真想让你尝尝大爷我毒掌的厉害！");
			me->set_temp("warned", 1);
		}
		else if( me->query_temp("stay") < 10 ) me->add_temp("stay", 1);
		else 
		{
//			me->set_leader(me);
			say("看你这次往哪儿跑！");
			remove_call_out(do_kill);
			call_out(do_kill, 5, me->object_id());
		}
	}       
	
}

static void do_kill(CContainer * ob, LONG param1, LONG param2)
{
	CChar * who = (CChar * )ob;
	CChar * me = (CChar *)(who->environment())->Present(param1);

	if(! me) return;
	who->kill_ob(me);
}

NPC_END;