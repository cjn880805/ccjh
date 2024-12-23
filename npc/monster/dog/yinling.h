//zhou.h
//Lanwood 2000-01-05

NPC_BEGIN(CNyinling);

virtual void create()
{
	set_name("银铃", "yinling");
	set("long", "一个看上去很伤心的女孩子。");
	set("icon", young_woman2);
	
	set("gender", "女性");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "fighter");
	
	set_inquiry("她在等什么？", "你见过我的它吗？");


	set("foolid",1000);	

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	
	set("max_hp", 3500);
	set("mp", 3500);
	set("max_mp", 3500);
	set("mp_factor", 1000);
	
	set("combat_exp", 1500000);
	set("score", 1000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set_skill("strike", 100);
	set_skill("sword", 100);
	set_skill("hubo", 300);
	set_skill("literate", 100);
	set_skill("wudu_zhang", 100);
	set_skill("jiuyin_zhua", 100);
	set_skill("hengshan_sword", 200);
	set_skill("lingxu_bu", 200);
	set_skill("wudu_xinfa", 200);
	map_skill("force","wudu_xinfa");
	map_skill("dodge","lingxu_bu");
	map_skill("strike","wudu_zhang");
	map_skill("sword","hengshan_sword");
	create_family("旺财派", 4, "掌门弟子");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	set("no_huan",1);


virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "diablo2") || DIFFERSTR(ob->querystr("name"), "旺财" ) )
	{	
		message_vision("$N眼泪夺眶而出？", this);
		return 0;
	}

	destruct(ob);

	CContainer * obj = load_item("baozi");

	obj->set_name( "包子", "bao zi");

	message_vision("$N含泪望着$n点点头，给$p一样东西。", this, who);
	obj->move(who);

	return 1;
}


NPC_END;
