//pub_trainer.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_trainer);

virtual void create()
{
	set_name("教练",  "trainer");

	set("icon", triggerman1);
	set("gender", "男性" );
	set("age", 25);
	set("long", "这是个和蔼可亲的教练。");
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	set("max_hp", 900);
	set("mp", 200);
	set("max_mp", 200);
	set("combat_exp", 30000);
	set("score", 20000);
	set_skill("force", 60);
	set_skill("dodge", 70);
	set_skill("unarmed", 70);
	set_skill("parry", 60);
	set_skill("staff",60);
	
	create_family("白驼山派",5,"弟子");
}

virtual char * greeting(CChar * ob)
{
	if ( EQUALSTR(ob->querystr("family/family_name"), "白驼山派"))
	{ 
		if(ob->query("hp")<60)
			message_vision("教练对着$N笑道：练功累吧？没关系，苦尽甜来嘛。",ob);
		else
			message_vision("教练对着$N夸道：你又来练功，精神可嘉！",ob);
	}
	return "";
}

virtual void attempt_apprentice(CChar * ob)
{
	say("我不能收徒。你还是拜李教头吧。", ob);
	SendMenu(ob);
	return;
}

virtual int accept_fight(CChar * ob)
{
	if ( EQUALSTR(ob->querystr("family/family_name"), "白驼山派"))
	{
		if( ob->query("combat_exp")<10000)
			return notify_fail("教练笑道：你的经验太低了，还是找陪练童子比划吧！(bi tongzi)");
	}
    return 1;
}

NPC_END;