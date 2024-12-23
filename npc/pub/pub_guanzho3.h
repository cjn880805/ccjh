// pub_guanzho3.c
//code by Fisho
//date : 2000-12-14

//inherit F_MASTER;

NPC_BEGIN(CNpub_guanzho3);

virtual void create()
{
    set_name("观众丙","guan zhong3");

	set("icon", young_woman10);
    set("gender", "女性");
    set("age", 18);
    set("long", "这是一位小姑娘。");
    set("attitude", "peaceful");
	
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);
    set("hp", 200);
    set("max_hp", 600);
    set("combat_exp", 5000);
    
    set_skill("force", 60);
    set_skill("unarmed", 60);
    set_skill("dodge", 60);
    set_skill("parry", 65);
	carry_object("pink_cloth")->wear();
	carry_object("flower_shoe")->wear();
}

virtual void init(CChar *me)
{
	CNpc::init(me);
//	ob = me;
//	me = this_object();
	if (! is_fighting() && userp(me)  && !me->environment()->query("no_fight"))
	{
		if( !me->query_temp("warned") )
		{
			say("居然有人敢不让我看戏，气死我了！");
		}
		else if( me->query_temp("stay") < 10 ) me->add_temp("stay", 1);
		else 
		{
			say("我杀了你！！！");
//			me->set_leader(me);
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