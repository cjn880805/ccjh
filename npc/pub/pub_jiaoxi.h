// pub_jiaoxi.c
//code by Fisho
//date : 2000-12-14
//inherit F_DEALER;

NPC_BEGIN(CNpub_jiaoxi);

virtual void create()
{
	set_name("老夫子",  "lao jiaoxi" );

	set("icon", old_man2);
	set("long","一个唯利是图的苏州老教习，肚子里有墨水，可你还要有钱。");
	set("gender", "男性");
	set("age", 65);
	set_skill("literate", 200);
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);
	
	set("combat_exp", 40000);
	set("shen_type", 1);
	set_inquiry("书" , "唉!书到用时方恨少。");
	set_inquiry("借书" , "借？你不还我到哪里找你？哼!");
	set("no_huan",1);
	
}

virtual int prevent_learn(CChar * me, const char * arg)
{
	if(DIFFERSTR(arg, "literate")) return 1;

	me->add_temp("mark/朱2", -1);
	if (! me->query_temp("mark/朱2"))
	{
		DownLoad(me);
		return 1;
	}

	return 0;
}

int recognize_apprentice(CChar * ob)
{
	if (! ob->query_temp("mark/朱2"))
		return 0;
	
	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (! who->query_temp("mark/朱2")) 
		who->set_temp("mark/朱2", 0l);
	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 500)
	{
		message_vision("老夫子同意指点$N一些读书写字的问题。", who);
		who->add_temp("mark/朱2", ob->query("value") / 250);
		DownLoad(who);
	}
	destruct(ob);
	return 1;
}

NPC_END;