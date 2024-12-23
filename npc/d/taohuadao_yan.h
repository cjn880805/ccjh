//taohuadao_yan.c
//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNtaohuadao_yan);

virtual void create()
{
	set_name("程英英", "cheng ying");
	set("gender", "女性" );
	set("age",18);
        set("icon",girl2);

	set("long","程英英是黄老怪从小收养的孤女。由黄老怪亲手教得了一手人人称绝的烹调手法，因此桃花岛的膳食就由她负责。");
	set("per", 30);
	set("class", "scholar");
	set("combat_exp", 10000);
	
	set_skill("unarmed",30);
	set_skill("luoying_shenzhang",30);
	set_skill("dodge", 30);
	set_skill("anying_fuxiang" , 30);
	set_skill("force",30);
	map_skill("dodge", "anying_fuxiang");
	map_skill("unarmed","luoying_shenzhang");
	
	set("force", 500);
	set("max_force", 500);
	set("force_factor",0l);
	
	set("chat_chance", 7);
	create_family("桃花岛", 3, "弟子");
	
	carry_object("cloth")->wear();
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "我们桃花岛景色优美，欢迎来作客！ ";
	case 1:
		return "有幸见到您真高兴！ ";
	case 2:
		return "您饿不饿？我桃花岛的烹调功夫可算天下第一呀。 ";
	}
	return "";
}

virtual void init(CChar * me)
{
	if(userp(me))
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 2, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	CContainer * teatp;
	char msg[255];

	if(! who) return;

	if ( who->query_temp("taohua/茶饭") )
		me->say(snprintf(msg,255,"这位%s，你好！欢迎来到桃花岛！ ", query_respect(who) ));
	else
	{
		tell_room(me->environment(),snprintf(msg,255,"程英英奉上茶饭，微笑着说道：这位 %s，你好！欢迎来到桃花岛。请用饭！ ",query_respect(who) ));
		teatp= load_item("cha");//醉仙茶
		teatp->move(who);
		teatp= load_item("gao");//冰雪翡翠糕
		teatp->move(who);
		
		me->say("这是我亲手做的，请您品尝！ ");
		who->set_temp("taohua/茶饭", 1);
	}
}

NPC_END;