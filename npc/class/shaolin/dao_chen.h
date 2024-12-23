//dao_chen.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_dao_chen);

virtual void create()
{
	set_name("道尘禅师", "daochen chanshi");
	set("long",	"他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。");

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
set("foolid",79);
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
	set_skill("damo_jian", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("strike", "banruo_zhang");
	map_skill("parry", "damo_jian");

	prepare_skill("strike", "banruo_zhang");
	create_family("少林派", 39, "弟子");

 	set("wuqi_count", 5);

    carry_object("xu_cloth")->wear();
	set("no_talk",1);

};

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(EQUALSTR(me->querystr("family/family_name"), "少林派"))
	{
		if(strcmp(ask, "齐眉棍") == 0)
			return ask_me(me, "qimeigun");
		if(strcmp(ask, "戒刀") == 0)
			return ask_me(me, "jiedao");
		if(strcmp(ask, "禅杖") == 0)
			return ask_me(me, "chanzhang");
		if(strcmp(ask, "长剑") == 0)
			return ask_me(me, "changjian");
		if(strcmp(ask, "皮鞭") == 0)
			return ask_me(me, "changbian");
				
		AddMenuItem("向道尘禅师索要齐眉棍", "齐眉棍", me);
		AddMenuItem("向道尘禅师索要戒刀", "戒刀", me);
		AddMenuItem("向道尘禅师索要禅杖", "禅杖", me);
		AddMenuItem("向道尘禅师索要长剑", "长剑", me);
		AddMenuItem("向道尘禅师索要皮鞭", "皮鞭", me);
		SendMenu(me);	
		return 1;
	}

	return CNpc::do_talk(me, ask);
}

int ask_me(CChar * me, char * wuqi)
{
    if ( me->PresentName(wuqi, IS_ITEM) )
	{
		say("你现在身上不是有这样武器吗，怎麽又来要了？ 真是贪得无餍！", me);
		SendMenu(me);
		return 1;
	}

	if (query("wuqi_count") < 1)
	{
		say("抱歉，你来得不是时候，武器已经发完了。", me);
		SendMenu(me);
		return 1;
	}

	CContainer * ob = load_item(wuqi);
	ob->move(me);

	add("wuqi_count", -1);

	message_vision("道尘给$N一件$n。", me, ob);

	say("拿去吧。不过要记住，武器只可防身练武，不可凭此杀害生灵。", me);
	SendMenu(me);
	return 1;
}

NPC_END;
