//pub_gu.c
//code by Fisho
//date : 2000-12-14


NPC_BEGIN(CNpub_gu);

virtual void create()
{
	set_name("顾炎武",  "gu yanwu"  );

	set("icon", old_man2);
	set("long", "顾先生被称为当世第一大文学家，肚子里的墨水比海还要深。");
	set("gender", "男性");
	set("age", 65);
	
	set_skill("literate", 300);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	
	set("combat_exp", 400000);
	set("shen_type", 1);
	
	set("chat_chance", 3);
 	carry_object("cloth")->wear();
	set("no_huan",1);
}

virtual char *chat_msg()
{
	switch (random(4))
	{
	case 0:
		return "顾炎武说道：普天之下，莫非王土；率土之滨，莫非王臣。";
	case 1:
		return "顾炎武说道：出家人，小过损益焉；无妄大过，未济咸困之。";
	case 2:
		return "顾炎武说道：大学之道，在明明德。在亲民，在止于至善。 ";
	case 3:
		return "顾炎武说道：格物致知，诚意正心，修身齐家，治国平天下。";
	}
	return "";
}

virtual int prevent_learn(CChar * me, const char * arg)
{
	if(DIFFERSTR(arg, "literate")) return 1;

	me->add_temp("mark/朱", -1);
	if(! me->query_temp("mark/朱"))
	{
		DownLoad(me);
		return 1;
	}

	return 0;
}

int recognize_apprentice(CChar *ob)
{
	if (! ob->query_temp("mark/朱") )
		return 0; 
	return 1;
}

virtual int accept_object(CChar * who, CContainer *ob)
{
	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 5000) 
	{
		message_vision("顾炎武同意指点$N一些读书识字的问题。", who);
		who->add_temp("mark/朱", ob->query("value") / 1000);
		DownLoad(who);
		destruct(ob);
		return 1;
	}

	return 0;
}
NPC_END;