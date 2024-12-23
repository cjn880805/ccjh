//wuxiuwen.h
//code by zwb
//12-16

NPC_BEGIN(CNgaibang_wuxiuwen);

virtual void create()
{
	set_name("小武","wu xiu wen");

	set("title", "靖哥哥二弟子");
	set("gender", "男性");
	set("age", 21);
	set("long", "他是靖哥哥的二弟子，精明强干，眼神如虎袭人，专门负责后勤。\n");
 	set("attitude", "peaceful");
 	set("icon",young_man1);
	
	set("per", 23);
	set("str", 20);
	set("int", 20);
	set("con", 30);
	set("dex", 25);

	set_inquiry("蓉儿","那是我师母。");
	set_inquiry("靖哥哥","那是我师父。");
	set_inquiry("防具",do_select);

	set("hp", 1000);
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	
	set("combat_exp", 80000);
	set("score", 20000);

	set("huju_count", 2);
	set("beixin_count", 2);
	 
	set_skill("force", 50);			// 基本内功
	set_skill("huntian_qigong", 50);	// 混天气功
	set_skill("unarmed", 50);		// 基本拳脚
	set_skill("xianglong_zhang", 50);	// 降龙十八掌
	set_skill("dodge", 50);			// 基本躲闪
	set_skill("xiaoyaoyou", 50);		// 逍遥游
	set_skill("parry", 50);			// 基本招架

	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong_zhang");
	
	carry_object("cloth")->wear();
};

virtual void init(CChar * player)
{
	player->set_temp("pending/what",0l);
}

static char * do_select(CNpc * npc , CChar * player)
{
	player->set_temp("pending/what",1);

	npc->say("请问你要什么防具呢?",player);

	npc->AddMenuItem("铁背心","tiebeixin",player);
	npc->AddMenuItem("铁手掌","tieshou",player);
	npc->AddMenuItem("铁甲","tiejia",player);
	npc->AddMenuItem("铁护腰","tiehuyao",player);
	npc->AddMenuItem("铁护腕","tiehuwan",player);
	npc->AddMenuItem("铁指套","tiezhitao",player);
	npc->SendMenu(player);
	return "";
}

virtual int do_talk(CChar * player ,char * ask = NULL)
{
	if(! strlen(ask)) return 0;

	if(player->query_temp("pending/what"))
		return do_get(player,ask);

	return CNpc::do_talk(player,ask);
}

int do_get(CChar * player , char * select)
{
	char msg[255];
	CContainer * obj;

	player->set_temp("pending/what",0l);

	if(player->present(select))
	{
		say(snprintf(msg,255,"%s你现在身上不是有这样防具吗，怎麽又来要了？ 真是贪得无餍！",query_respect(player)),player);
		SendMenu(player);
		return 0;
	}

	if(DIFFERSTR(select, "tiebeixin") && query("huju_count")<1)
	{
		say("抱歉，你来得不是时候，防具已经发完了。",player);
		SendMenu(player);
		return 0;
	}

	if(EQUALSTR(select, "tiebeixin") && query("beixin_count")<1)
	{
		say("抱歉，你来得不是时候，武器已经发完了。",player);
		SendMenu(player);
		return 0;
	}
	
	obj=load_item(select);
	obj->move(player);

	if(EQUALSTR(select, "tiebeixin"))
		add("beixin_count",-1);
	else 
		add("huju_count",-1);

	message_vision(snprintf(msg,255,"小武给$N一件%s",obj->name()),player);
	
	say("拿去吧。不过要记住，防具乃是防身宝物，不可凭此妨害他人。",player);
	SendMenu(player);

	return 1;
}
NPC_END;
