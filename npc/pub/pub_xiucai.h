//xiucai.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_xiucai);

virtual void create()
{
	set_name("老秀才","xiucai");

	set("icon", old_man2);
	set("long", "一个穷困潦倒的落第秀才，在这里开堂授课为生。");
	set("gender", "男性");
	set("age", 65);

	set_skill("literate", 100);
	set_skill("taoism", 100);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 40000);
	set("shen_type", 1);

	carry_object("cloth")->wear();
	set("no_huan",1);

};

virtual int prevent_learn(CChar * me, const char * arg)
{
	if(DIFFERSTR(arg, "literate")) return 1;

	me->add_temp("mark/朱3", -1);
	if(! me->query_temp("mark/朱3"))
	{
		DownLoad(me);
		return 1;
	}
	
	return 0;
}

virtual int recognize_apprentice(CChar * me)
{
	if(!me->query_temp("mark/朱3"))
		return 0;
	
	return 1;
}

virtual int accept_object(CChar * me ,CContainer * ob)
{
	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 5000) 
	{
		message_vision("老秀才同意指点$N一些问题。", me);
		me->add_temp("mark/朱3", ob->query("value") / 1000);
		DownLoad(me);
		destruct(ob);
		return 1;
	}
	return 0;
}

NPC_END;
