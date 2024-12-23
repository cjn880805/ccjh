//dao.h
//Lanwood 2000-01-06

NPC_BEGIN(CNemei_dao);

virtual void create()
{
	set_name("宁道师太",  "ningdao shitai");
	set("long", "她是一位中年出家道姑，道冠高拢，慈眉善目。");
	set("gender", "女性");
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("repute", 10000);
	set("class", "bonze");
	set("icon", taoistess);
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	
	set("max_hp", 2000);
		set("foolid",23);
	set("mp", 1500);
	set("max_mp", 1500);
	
	set("combat_exp", 250000);
	set("score", 1000);
	set_skill("persuading", 80);
	set_skill("throwing", 80);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("finger", 100);
	set_skill("parry", 100);
	set_skill("strike", 100);
	set_skill("blade", 100);
	set_skill("literate", 100);
	set_skill("mahayana", 100);
	set_skill("jinding_zhang", 100);
	set_skill("tiangang_zhi", 100);
	set_skill("yanxing_dao", 100);
	set_skill("zhutian_bu", 100);
	set_skill("linji_zhuang", 100);
	map_skill("force","linji_zhuang");
	map_skill("finger","tiangang_zhi");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");
	map_skill("blade","yanxing_dao");
	map_skill("parry","yanxing_dao");
	
	create_family("峨嵋派", 4, "弟子");
	set_inquiry("美容","据说吃西太后有可以美容养颜的秘密。");
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
	set("no_huan",1);
};

virtual void attempt_apprentice(CChar * me)
{
	say("阿弥陀佛！贫尼不收弟子。", me);
	say("你若想继续学峨嵋派的功夫，还是去找我俗家师妹吧。", me);
	SendMenu(me);
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "gongting mifang") || DIFFERSTR(ob->querystr("name"), "宫廷秘方") )
	{	
		message_vision("$N冷冷的道：这是什么东西？", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "浮月牌", "fuyue pai");

	message_vision("$N点点头，偷偷给$n一块东西。", this, who);
	ob->move(who);

	return 1;
}


NPC_END;
