//hong.h
//code by cat
//2001-4-2

NPC_BEGIN(CNGuMu_hong);

virtual void create()
{
	set_name("洪绫绫","hong lingling");

	set("gender", "女性");
	set("age", 24);
	set("long","她肤色白润 ，双颊晕红，两眼水汪汪的。让人看了还想看。");
	set("attitude", "friendly");
	set("icon",taoistess);
	set("rank_info/respect", "道姑");
set("foolid",57);	
	set("per", 27);
	set("str", 26);
	set("int", 25);
	set("con", 17);
	set("dex", 35);
	set("shen_type", -1);
	set("hp", 3500);
	set("max_hp", 5400);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 40);
	
	set("combat_exp", 800000);
	set("score", 5000);
	
	set_skill("force", 100);
	set_skill("yunv_xinfa", 100);    //玉女心法
	set_skill("sword", 120);
	set_skill("yunv_jian", 120);     //玉女剑
	set_skill("dodge", 120);
	set_skill("yunv_shenfa", 120);   //玉女身法
	set_skill("parry", 100);
	set_skill("unarmed",100);
	set_skill("wudu_shenzhang", 100);    //五毒神掌
	set_skill("wudu_xinfa", 100);
	set_skill("swsb_whip", 100);
	set_skill("whip", 100);
	set_skill("literate",100);
	set_skill("tianluo_diwang", 150);
	
	map_skill("force", "yunv_xinfa");
	map_skill("sword", "yunv_jian");
	map_skill("dodge", "yunv_shenfa");
	map_skill("parry", "swsb_whip");
	map_skill("whip", "swsb_whip");
	map_skill("unarmed", "wudu_shenzhang");
	
	create_family("古墓派", 4, "弟子");
	set("chat_chance_combat", 30);
	set_inquiry("冰魄银针", "那是我师父的独门暗器，听说那个龙儿也有一种玉蜂针，不知道她那边的毒性怎么样。");
	
	carry_object("daogu_cloth")->wear();
	carry_object("fuchen")->wield();
	set("no_huan",1);
}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("unarmed you", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}
	return 0;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "fengmi") || DIFFERSTR(ob->querystr("name"), "玉蜂蜜") )
	{	
		message_vision("$N冷冷的道：这是什么东西？", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("jingxin_san");

	message_vision("$N给了$n一瓶静心口服液道：“有了你的蜂蜜就想找出玉蜂针的解药来，谢谢。”", this, who);
	ob->move(who);

	return 1;
}

virtual void attempt_apprentice(CChar  * player)
{
	if(player->query("per") < 20)
	{
		say(" 尊容实在不敢恭维，恐怕学不了玉女心法。",player);
		SendMenu(player);
		return;
	}
	if(player->query_dex() < 20)
	{
		say(" 你的身法太差，不适合学我古墓派的武功。",player);
		SendMenu(player);
		return;
	}
	if(player->query_int() < 25)
	{
		say(" 你的悟性太差，不适合学我古墓派的武功。",player);
		SendMenu(player);
		return;
	}
	if(player->query("repute") > 0)
	{
		say(" 你的行事作风，我师傅不会喜欢的。",player);
		SendMenu(player);
		return;
	}
	if((EQUALSTR(player->querystr("family/family_name"), "古墓派")) && (DIFFERSTR(player->querystr("class"), "taoist")) )
	{
		say(" 你不去钻地道当死人来找我干什么？",player);
		SendMenu(player);
		return;
	}
	if(DIFFERSTR(player->querystr("gender"), "女性"))
	{
		say("对不起，本门只收女弟子，臭男人流滚一边去。",player);
		SendMenu(player);
		return;
	}
	else
	{
		player->set("class", "taoist");
	    say(" 好吧，我就收下你这个徒弟了。");
		recruit_apprentice(player);
	}
	return;
}
NPC_END;
