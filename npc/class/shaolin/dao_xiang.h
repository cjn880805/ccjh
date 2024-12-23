//dao_xiang.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_dao_xiang);

virtual void create()
{
	set_name("道相禅师", "daoxiang chanshi");
	set("long",	"他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。");
	
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
set("foolid",78);
	set("age", 40);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_hp", 1200);
	
	set("mp", 450);
	set("max_mp", 450);
	set("mp_factor", 40);
	set("combat_exp", 10000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("hunyuan_yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("strike", 50);
	set_skill("banruo_zhang", 50);
	set_skill("parry", 50);
	set_skill("sword", 50);
	set_skill("damo_jian", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("strike", "banruo_zhang");
	map_skill("sword", "damo_jian");
	map_skill("parry", "damo_jian");

	prepare_skill("strike", "banruo_zhang");
	create_family("少林派", 39, "弟子");

    set("huju_count", 5);
	set("beixin_count", 1);

    carry_object("changjian")->wield();
    carry_object("xu_cloth")->wear();
	set("no_talk",1);

};

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(EQUALSTR(me->querystr("family/family_name"), "少林派"))
	{
		if(strcmp(ask, "铁护腕") == 0)
			return ask_me(me, "huwan");
		if(strcmp(ask, "铁护腰") == 0)
			return ask_me(me, "huyao");
		if(strcmp(ask, "皮手套") == 0)
			return ask_me(me, "shoutao");
		if(strcmp(ask, "皮围脖") == 0)
			return ask_me(me, "weibo");
		if(strcmp(ask, "铁指套") == 0)
			return ask_me(me, "zhitao");
		if(strcmp(ask, "僧鞋") == 0)
			return ask_me(me, "sengxie");
		if(strcmp(ask, "铁背心") == 0)
			return ask_me_2(me);
		
		AddMenuItem("向道相禅师索要铁护腕", "铁护腕", me);
		AddMenuItem("向道相禅师索要铁护腰", "铁护腰", me);
		AddMenuItem("向道相禅师索要皮手套", "皮手套", me);
		AddMenuItem("向道相禅师索要皮围脖", "皮围脖", me);
		AddMenuItem("向道相禅师索要铁指套", "铁指套", me);
		AddMenuItem("向道相禅师索要僧鞋", "僧鞋", me);
		AddMenuItem("向道相禅师索要铁背心", "铁背心", me);
		SendMenu(me);	
		return 1;
	}

	return CNpc::do_talk(me, ask);
}

int ask_me(CChar * me, char * huju)
{
	if ( me->PresentName(huju, IS_ITEM))
	{
		say("你现在身上不是有这样防具吗，怎麽又来要了？ 真是贪得无餍！", me);
		SendMenu(me);
		return 1;
	}

	if (query("huju_count") < 1)
	{
		say("抱歉，你来得不是时候，防具已经发完了。", me);
		SendMenu(me);
		return 1;
	}

	CContainer * ob = load_item(huju);
	ob->move(me);
	add("huju_count", -1);

	message_vision("道相给$N一件$n。", me, ob);
	say("拿去吧。不过要记住，防具只可防身练武，不可凭此妨害他人。", me);
	SendMenu(me);
	return 1;
}

int ask_me_2(CChar * me)
{
	if (query("beixin_count") < 1)
	{
		say("抱歉，你来得不是时候，武器已经发完了。", me);
		SendMenu(me);
		return 1;
	}

	CContainer * ob = load_item("beixin");
	ob->move(me);

	add("beixin_count", -1);

	message_vision("道相给$N一件$n。", me, ob);

	say("拿去吧。不过要记住，铁背心乃是防身宝物，不可凭此妨害他人。", me);
	SendMenu(me);
	return 1;
}

NPC_END;
