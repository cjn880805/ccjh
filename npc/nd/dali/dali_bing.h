// bing.c
//sound 2001-07-16

NPC_BEGIN(CNdali_bing);

virtual void create()
{
	set_name("士兵", "shi bing");
	set("age", 32);
	set("gender", "男性");
	set("long", "他是一个大理国禁卫军士兵，身着锦衣，手执钢刀，双目精光炯炯，警惕地巡视着四周的情形。");
	set("attitude", "peaceful");

	set("str", 24);
	set("per", 20);
	set("dex", 16);
	set("icon",guarder);	
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	carry_object("gangdao")->wield();
	carry_object("junfu")->wear();
}
/*
void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) 
		&& (int)ob->query_condition("killer")) 
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
	me->apply_condition("killer", 500);
	kill_ob(me);
	return 1;
}
*/
NPC_END;