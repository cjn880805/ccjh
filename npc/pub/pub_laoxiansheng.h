// pub_laoxiansheng.c 老先生
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_laoxiansheng);

virtual void create()
{
	set_name("老先生", "lao xiansheng");

	set("icon", pawnshop_boss);
	set("long","这位老先生曾中过状元，做过大官，现因年老回老家襄阳颐养天年，经安抚使吕文德的再三邀请，在这儿为秀才们讲课。");
    set("gender", "男性");
	set("age", 65);
	set("no_get", 1);
	set_skill("literate", 300);
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 10);
	set("combat_exp", 4000);
	set("shen_type", 1);
	set("no_huan",1);

}

virtual int recognize_apprentice(CChar * ob)
{
	if (! ob->query_temp("mark/朱"))
		return 0;

	return 1;
}

virtual int prevent_learn(CChar * me, const char * arg)
{
	if(DIFFERSTR(arg, "literate")) return 1;
	if(! me->query_temp("mark/朱")) return 1;

	me->add_temp("mark/朱", -1);
	if(! me->query_temp("mark/朱"))
	{
		DownLoad(me);
		return 1;
	}
	
	return 0;
}

virtual int accept_object(CChar * me, CContainer * ob)
{	
	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 1000)
	{
		message_vision("老先生同意指点$N一些读书写字的问题。", me);
		me->set_temp("mark/朱", ob->query("value") / 200);
		DownLoad(me);
		if( me->query_skill("literate", 1) > 21)
		{
			tell_object(me,"你现在已有一定的文化知识，也可以自己读书深造了。");
		}
	}
	destruct(ob);
	return 1;
}

NPC_END;