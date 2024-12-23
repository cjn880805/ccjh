// pub_guanzho4.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_guanzho4);

virtual void create()
{
	set_name("观众丁",  "guan zhong4" );

	set("icon", pub_boss);
	set("long", "此人身材瘦小，却是气宇暄昂, 似乎身怀惊人艺业。");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("max_hp", 600);
	set("mp", 200);
	set("max_mp", 200);
	set("mp_factor", 20);
	set("combat_exp", 30000);
	set("score", 3000);
	
	set_skill("huashan_zhangfa", 40);
	set_skill("unarmed",60);
	set_skill("force", 60);
	set_skill("zixia_shengong", 30);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("huashan_sword", 35);
	set_skill("huashan_shenfa",35);
	
	map_skill("force", "zixia_shengong");
	map_skill("unarmed", "huashan_zhangfa");
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "huashan_sword");
	map_skill("sword", "huashan_sword");
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
}

virtual void init(CChar *me)
{
	CNpc::init(me);
	
	if (! is_fighting() && userp(me) && !me->environment()->query("no_fight") && ! is_fighting())
	{
		if( !me->query_temp("warned") ) 
		{
			say("你也不看看长自己什么样，居然到这儿来撒野！");
		}
		else if( me->query_temp("stay") < 10 ) me->add_temp("stay", 1);
		else 
		{
	//		me->set_leader(me);
			say("你还想跑，我非宰了你不可！");
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