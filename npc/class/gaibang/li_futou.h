//li_futou.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_li_futou);

virtual void create()
{	
	set_name("李小斧", "li xiaofu");
	set("title", "丐帮六袋弟子");
	set("gender", "男性");
	set("class", "beggar");
	set("age", 20);
	set("long",
		"这是位丐帮六袋弟子，看来是个深藏不露的高手。\n");
	set("attitude", "peaceful");
	set("str", 27);
	set("int", 25);
	set("con", 24);
	set("dex", 27);
	set("max_hp", 750);
	set("icon",begger);
	
	set("beggarlvl", 6);
	
	set("mp",300);
	set("max_mp", 300);
	set("mp_factor",30);
	set("combat_exp", 60000);
	
	set_skill("force", 60);
	set_skill("huntian_qigong", 60);
	set_skill("unarmed", 60);
	set_skill("xianglong_zhang", 60);
	set_skill("dodge", 60);
	set_skill("xiaoyaoyou", 60);
	set_skill("parry", 60);
	set_skill("begging", 60);
	//set_skill("checking", 60);
	set_skill("xunshou_shu", 60);

	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	carry_object("dawancha", 1);
	create_family("丐帮", 19, "弟子");
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * me)
{
	if( EQUALSTR(me->querystr("gender"), "无性"))
	{
		say("我们丐帮功夫走的是刚猛的路子，你。。。。。");
		return;
	}
	else
		accept_student(me);
}

NPCGAIBANG_END;
