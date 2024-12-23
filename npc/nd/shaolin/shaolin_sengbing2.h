// sengbing2.c

//code by sound
//date:2001-07-12

NPC_BEGIN(CNshaolin_sengbing2);

virtual void create()
{
	set_name("执法僧兵", "seng bing");
	set("long",
		"他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他\n"
		"手持兵刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。\n");

	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 25);
	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
        set("icon",young_monk);
	set("max_hp", 500);
	set("hp", 500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 50);
	set("combat_exp", 10000);
	set("score", 1);

	set("chat_chance", 20);
//	set("chat_msg", ({
//		(: random_move :)
//	}) );

	set_skill("force", 40);
	set_skill("hunyuan_yiqi", 40);
	set_skill("dodge", 40);
	set_skill("shaolin_shenfa", 40);
	set_skill("unarmed", 40);
	set_skill("banruo_zhang", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("cibei_dao", 40);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("unarmed", "banruo_zhang");
	map_skill("parry", "cibei_dao");
	map_skill("blade", "cibei_dao");

	carry_object("jiedao")->wield();
	carry_object("cloth")->wield();
}

/*
void init()
{
	object me, ob;
	ob = this_player();
	me = this_object();
	
	::init();

	if ( interactive(ob) && !environment(ob)->query("no_fight") )
	{
		if ( ob->query("guilty") == 1 )
		{
			if ( random(2) ==1 )
			command("say 你这佛门败类，哪里逃！ 还不速到戒律院领罪！\n");
			me->set_leader(ob);
			remove_call_out("fight_ob");
			call_out("fight_ob", 1, ob); 
		}       
		if ( ob->query("guilty") >= 2 )
		{
			if ( random(2) ==1 )
			command("say 戒律院玄痛大师请你去陈述此次下山经过 ！\n");
			me->set_leader(ob);
		}       
	}
	else if( environment(ob)->query("no_fight") ) me->set_leader(0);
}
*/
NPC_END;