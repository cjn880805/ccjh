//mo_bu.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_mo_bu);

virtual void create()
{	
	set_name("莫不纳", "mo buna");
	set("title", "丐帮三袋弟子");
	set("gender", "男性");
	set("age", 17);
	set("long",
		"这是位丐帮三袋弟子，看来是个很吃得开的一方霸主。");
	set("attitude", "peaceful");
	set("class", "beggar");
	set("str", 21);
	set("int", 20);
	set("con", 20);
	set("dex", 23);
	set("max_hp", 520);
	set("icon",begger);
	
	set("beggarlvl", 3);

	set("mp", 180);
	set("max_mp", 180);
	set("mp_factor", 15);
	set("combat_exp", 18000);
	set_skill("force", 40);
	set_skill("huntian_qigong", 40);
	set_skill("unarmed", 40);
	set_skill("xianglong_zhang", 40);
	set_skill("dodge", 40);
	set_skill("xiaoyaoyou", 40);
	set_skill("parry", 40);
	set_skill("begging", 40);
	//        set_skill("checking", 40);
	set_skill("xunshou_shu", 40);

	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 20, "弟子");
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * me)
{
	if( DIFFERSTR(me->querystr("gender"), "男性"))
	{
		say("我们丐帮功夫走的是刚猛的路子，mm你学了会有失仪态的。");
		return;
	}
	else
		accept_student(me);
}

NPCGAIBANG_END;
