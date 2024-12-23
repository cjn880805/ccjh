//li.h
//Lanwood 2000-01-05

NPC_BEGIN(CNbtshan_li);

virtual void create()
{
	set_name("李教头",  "li" );
	set("gender", "男性" );
	set("age", 25);
	set("long", "这是个和蔼可亲的教头。");
	set("attitude", "friendly");
	set("shen_type", -1);
	set("icon", young_man4);

	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
        set_inquiry("白老庄主","老庄主以前对我那么好，虽然他现在变成这样子，但是我还是会继续为传播白驼的武功而努力");
        set_inquiry("练武","在这个世上，武功不是全部，但是也很重要");
	set("max_hp", 1200);
	set("mp", 300);
	set("max_mp", 300);
	set("combat_exp", 250000);
	set("score", 20000);

	set_skill("force", 80);
	set_skill("dodge", 90);
	set_skill("unarmed", 90);
	set_skill("parry", 80);
	set_skill("staff",80);

	set_skill("xunshou_shu", 40);
	
	set_skill("hamagong",70);
	set_skill("chanchu_bufa", 80);
	set_skill("lingshe_zhangfa", 80);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	
	map_skill("parry", "lingshe_zhangfa");
	map_skill("staff", "lingshe_zhangfa");

	create_family("白驼山派",2,"弟子");

	set("chat_chance", 2);
			
};

virtual char * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "李教头说道: 勤学苦练方可出神功..";
	case 1:
		return "李教头鼓励小弟子们不畏艰苦，好好练功。";
	case 2:
		return "李教头拍拍学徒的头说：好样的！";
	}
	return 0;
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

	if(!who) return;

	if (EQUALSTR(who->querystr("family/family_name"), "白驼山派"))
	{
	    message_vision("李教头冲着$N点点头，微微笑了笑。", who);
        return;
	}
	
	if (! who->querymap("family"))
	{
	    message_vision("李教头冲着$N微笑说：你是来拜师的吧，拜我吧。", who);
	    return;
	}
	
	message_vision("李教头对$N嚷道:小家伙,你瞎逛什么呢?", who);
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	say("好吧，我收下你。");
    command(snprintf(msg, 80, "recruit %ld", me->object_id()));
    if(me->query_combat_exp() < 10000)
		say("你先到东边练功室找陪练童子比划几招吧。");

    return;
}

NPC_END;
