// quanzhen_qiu.c 丘处机

//code by Fisho
//date:2000-12-21

NPCQUANZHEN_BEGIN(CNquanzhen_qiu);

virtual void create()
{
	set_name("丘在机", "qiu zaiji");
	set("gender", "男性");
	set("age", 36);
	set("class", "taoist");
	set("nickname","长春子");
	set("long","他就是江湖上人称‘长春子’的丘在机丘真人，他方面大耳，满面红光，剑目圆睁，双眉如刀，相貌威严，平生疾恶如仇。");
	set("attitude", "heroism");
	set("shen_type",1);
	set("str", 32);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("icon",taoist);
	set("foolid",37);
	set("title","全真七子之四");
	
	set("chat_chance_combat", 60);
	set("hp", 4000);
	set("max_hp", 12000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 300000);
	
	set_skill("force", 220);
	set_skill("xiantian_qigong", 220);    //先天气功
	set_skill("sword", 250);
	set_skill("quanzhen_jian",250);  //全真剑
	set_skill("dodge", 200);
	set_skill("jinyan_gong", 200);   //金雁功
	set_skill("parry", 220);
	set_skill("unarmed",220);
	set_skill("haotian_zhang", 220);    //昊天掌
	set_skill("literate",160);
	set_skill("strike",180);
	set_skill("taoism",150);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("全真教", 2, "弟子");
	
	set("book_count",1);
	set_inquiry("全真教","我全真教是天下道家玄门正宗。");
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	
}

virtual void init(CChar * me)
{
	if(userp(me))
	{
		remove_call_out(do_kill);
		call_out(do_kill, 5, me->object_id());
	}
}

static void do_kill(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar * )ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];
	
	if(! who || (me->environment())->query("no_fight")) return;
	
	if (DIFFERSTR(who->querystr("family/family_name"), "全真教"))
	{
		if (who->query("repute") > -5000) 
		{
			me->say("这里是本教重地，你走动小心些。");
		}
		else 
		{
			me->say(" 你这魔头，竟敢闯入我全真重地，我一定要杀了你！");
			me->kill_ob(who);
		}
	}
	else 
	{
		me->command(snprintf(msg,255,"smile %ld", who->object_id() ));
	}
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	if ( ob->query_skill("xiantian_qigong",1) < 80 )
	{
		say("你的本门内功心法火候不足,难以领略更高深的武功。", ob);
		SendMenu(ob);
		return;
	}
	if ( ob->query("repute")<30000) 
	{
		say("行侠仗义是我辈学武人的基本品质，你若能多做些狭义之事，我一定收你为徒。", ob);
		SendMenu(ob);
		return;
	}

	say("好吧，我就收下你这个徒弟了。");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

NPCQUANZHEN_END;