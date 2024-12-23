//daobaifeng.h
//Lanwood 2000-01-05

NPC_BEGIN(CNdali_daobaifeng);

virtual void create()
{
	set_name("刀凤凰", "dao fenghuang");
	set("title",  "大理国王妃");
	set("nickname",  "玉虚散人");
	set("gender", "女性");
	set("long", "这是个容貌秀丽的中年道姑，是个摆夷族女子，颇有雍容气质。");
	set("age", 35);
	set("icon", young_man3);

	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 28);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_hp", 1800);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 100);
	set("combat_exp", 500000);
	set("score", 200000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("cuff", 100);
	set_skill("strike", 100);
	set_skill("whip", 100);
	set_skill("kurong_changong", 100);
	set_skill("duanjia_sword", 100);
	set_skill("tiannan_step", 100);
	set_skill("jinyu_quan", 100);
	set_skill("wuluo_zhang", 100);
	set_skill("feifeng_whip", 100);
	set_skill("literate", 60);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("whip", "feifeng_whip");
	map_skill("cuff", "jinyu_quan");
	map_skill("strike", "wuluo_zhang");
	map_skill("parry", "feifeng_whip");
	map_skill("sword", "duanjia_sword");
	prepare_skill("cuff", "jinyu_quan");
	prepare_skill("strike", "wuluo_zhang");

	set_inquiry("婚姻","他为了那一阳指，把我都抛弃了……");

	carry_object("cynrobe")->wear();
	carry_object("fuchen")->wield();
	add_money(1000);

	create_family("大理段家",18,"王妃");
	set("no_huan",1);
};

virtual void attempt_apprentice(CChar * me)
{
	char oldtitle[40];
	char msg[80];

	strncpy(oldtitle, me->querystr("title"), 40)[39] = 0;
	if (me->query_skill("kurong_changong",1) < 30 )
	{
		say("你的本门内功心法太低了，还是努努力先提高一下吧。", me);
		SendMenu(me);
		return;
	}

	if (DIFFERSTR(me->querystr("gender"), "女性"))
	{
		say("我只收女弟子。", me);
		SendMenu(me);
		return;
	}

	if (me->query("repute") < 10000  )
	{
		say("我大理段氏向来行侠仗义，您请回吧！", me);
		SendMenu(me);
		return;
	}

	if (strstr(oldtitle, "大理镇南王府")) 
	{
		say("很好，既然入我门来就得终身为奴供我驱使。");
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		me->set("title", oldtitle);
		me->UpdateMe();
	}
	else
	{
		say("你是何人，如此大胆，假冒我府中厮仆！", me);
		SendMenu(me);
		return;
	}
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "sun_book") || DIFFERSTR(ob->querystr("name"), "一阳指诀"))
	{	
		message_vision("$N冷冷的道：这是什么东西？", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "雨月牌", "yuyue pai");

	message_vision("$N点点头，偷偷给$n一块东西。", this, who);
	ob->move(who);

	return 1;
}



NPC_END;
