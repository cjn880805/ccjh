//zhao_gouer.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_zhao_gouer);

virtual void create()
{	
	set_name("赵猫儿", "zhao maoer");
	set("title", "丐帮一袋弟子");
	set("gender", "男性");
	set("age", 15);
	set("long",
		"这是位地痞似的丐帮一袋弟子，看来是个小地痞。");
	set("attitude", "peaceful");
	set("class", "beggar");
	set("str", 18);
	set("int", 20);
	set("con", 20);
	set("dex", 23);
	set("icon",begger);

	set("beggarlvl", 1);
	
	set("max_hp", 360);
	
	set("mp", 150);
	set("max_mp", 150);
	set("mp_factor", 5);
	set("combat_exp", 2500);

	set_skill("force", 10);
	set_skill("huntian_qigong", 10);
	set_skill("unarmed", 10);
	set_skill("xianglong_zhang", 10);
	set_skill("dodge", 10);
	set_skill("xiaoyaoyou", 10);
	set_skill("parry", 10);
	set_skill("begging", 10);
	//set_skill("checking", 10);
	set_skill("xunshou_shu", 10);

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
