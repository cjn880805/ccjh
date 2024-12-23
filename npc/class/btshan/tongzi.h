//tongzi.h
//Lanwood 2000-01-05
void setup_char(CChar * me);

NPC_BEGIN(CNbtshan_tongzi);

virtual void create()
{
	set_name("陪练童子", "tongzi");
	set("gender", "男性" );
	set("age", 16);
	set("long", "这是个陪人练功的陪练童子。");
	set("attitude", "friendly");
	set("shen_type", -1);
	
	set("icon", young_man2);

	set("str", 21);
	set("int", 21);
	set("con", 21);
	set("dex", 20);
        set_inquiry("身世","你只需要知道我是陪练的童子就够了，我也没有别的身份");
	set("max_hp", 600);
	set("combat_exp", 10000);
	set("score", 500);
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry",20);
	create_family("白驼山派",10,"弟子");
	set("no_talk",1);
};

virtual void attempt_apprentice(CChar * me)
{
	say("我不能收徒。你还是拜李教头吧。", me);
	SendMenu(me);
    return;
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	say("快来跟我比划几招。", me);
	AddMenuItem("好，那我就不客气了。", "$0bi $1", me);
	AddMenuItem("改日再说吧。", "", me);
	SendMenu(me);
	return CNpc::do_talk(me,ask);
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "bi") == 0)
		return do_bi(me);

	return CNpc::handle_action(comm, me, arg);
}

int do_bi(CChar * me)
{
	if (me->query_combat_exp() < 10000)
	{
		set("combat_exp", me->query_combat_exp());
		set("level", me->query("level"));
	}

	Do_BiShi(this, me, "陪练童子的比试会");
	return 1;
	
}

virtual void is_defeated(CChar * winner, CChar * failer)
{
	set("eff_hp",200);
	set("hp",200);
	set("combat_exp", 10000);
	del("level");
	setup_char(this);

	if(failer == this)
	{
		message_vision("陪练童子对$N大加赞赏!", winner);
	}
	else
	{
		message_vision("陪练童子对$N笑笑道：努力吧。", winner);
	}
}

NPC_END;
