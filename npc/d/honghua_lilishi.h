//lilishi.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHongHua_lilishi);

virtual void create()
{

	set_name("李立世","li li shi");

	set("title", "天地会青木堂会众");
	set("gender", "男性");
	set("age", 45);
	set("str", 25);
	set("dex", 20);
	set("long", "这是一个高大威猛的中年人，身上的衣服满是绣花，看上去有点变态。");
	set("combat_exp", 35000);
	set("score", 5000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 50);
	set_skill("force", 60);
	set_skill("blade", 90);
	set_skill("dodge", 70);
	set_skill("parry", 50);
	set_skill("wuhuduanmendao", 90);
	set_skill("yunlong_shenfa", 60);
	map_skill("blade", "wuhuduanmendao");
	map_skill("dodge", "yunlong_shenfa");
 	set("icon",young_man6);

	set("mp", 150); 
	set("max_mp", 150);
	set("mp_facotr", 10);
	set("chat_chance", 2);

    set_inquiry("陈近南","想见总舵主可不容易啊。");
	set_inquiry("天地会","只要是英雄好汉，都可以入我天地会(join tiandihui)。");
	set_inquiry("入会","只要入了我天地会，可以向会中各位好手学武艺。");
    set_inquiry("反清复明","去棺材店和回春堂仔细瞧瞧吧！");
    set_inquiry("暗号","敲三下！");
    set_inquiry("切口","敲三下！");
    set_inquiry("进宫",ask_zhu);
    set_inquiry("花雕芙苓猪",ask_zhu);
    set_inquiry("燕窝人参猪",ask_zhu);
    set_inquiry("威望",ask_weiwang);

	carry_object("tudao")->wield();
	carry_object("cloth")->wear();
	add_money(20);
	set("no_huan",1);
}

virtual int accept_object(CChar * player ,  CContainer * ob)
{
	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 10000) 
	{
		message_vision("李立世对$N一揖作礼，说道：这位客官，要什么尽管说",player);
		player->set_temp("money_paid",1);
		destruct(ob);
		return 1;
	}
	return 0;
}

static char * ask_weiwang(CNpc * npc , CChar * player)
{
	char msg[255];

	npc->say(snprintf(msg,255,"%s你现在的江湖威望是%ld。",player->name(),player->query("威望")),player);
//	npc->say(snprintf(msg,255,"%s你现在的江湖威望是%ld。",player->name(),player->query("weiwang")),player);
	npc->say("如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息",player);
	npc->say("杀某些坏人或救某些好人可以提高江湖威望。",player);
	npc->SendMenu(player);

	return "";

}


virtual char * chat_msg(CChar * player)
{
	switch(random(5))
	{
	case 0:
		return "呆会儿我还得把猪送到宫里去。";
	case 1:
		return "花雕芙苓猪啊，只卖黄金一两，谁买谁买啊？";
	case 2:
		return "燕窝人参猪啊，只卖黄金一两，谁买谁买啊？";
	case 3:
		return "这么好的猪肉怎么没人要啊。";
	case 4:
		return "初进洪门结义兄，对天明誓表真心。";
	}
	return "";
}

static char * ask_zhu(CNpc * npc , CChar * player)
{
	if (player->query_temp("money_paid"))
	{
		player->delete_temp("money_paid");
		player->set("huanggong/canenter",1);
		return "您老现在可以走啦！";
	}
	return "干什么也得先交钱啊。";
} 



virtual int recognize_apprentice(CChar * player)
{
    if (player->query("weiwang")<50)
		return 0;

	return 1;
}


NPC_END;