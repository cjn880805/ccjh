// pub_guanzho1.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_guanzho1);

virtual void create()
{
	set_name("观众甲","guan zhong1");

	set("icon", drugstore_boss);
	set("long","他是一位十分安静的观众，但发起火来却又如此厉害。他两臂粗壮，膀阔腰圆，手持兵刃，似乎有一身武艺。");
	
	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");
	
	set("age", 40);
	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_hp", 1500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 50);
	set("combat_exp", 10000);
	set("score", 1);
	
	set_skill("force", 50);
	set_skill("hunyuan_yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("unarmed", 50);
	set_skill("banruo_zhang", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("cibei_dao", 50);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("unarmed", "banruo_zhang");
	map_skill("parry", "cibei_dao");
	map_skill("blade", "cibei_dao");
	
	carry_object("jiedao")->wield();
	carry_object("cloth")->wear();

	add_money(30);
}

virtual void init(CChar *me)
{
	CNpc::init(me);
//	ob = me;
//	me = this_object();
	
	if (! is_fighting() && userp(me) && !me->environment()->query("no_fight") )
	{
		if( !me->query_temp("warned") ) 
		{
			say("你是谁，居然敢来这儿捣乱，不想活了是不是？！");
		}
		else if( me->query_temp("stay") < 10 ) 
			me->add_temp("stay", 1);
		else 
		{
			say("大胆狂徒，哪里逃？！");
			remove_call_out(do_kill);
			call_out(do_kill, 5, me->object_id());
		//	me->set_leader(me);			
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