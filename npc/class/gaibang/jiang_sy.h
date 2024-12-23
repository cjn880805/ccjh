//jiang_sy.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_jiang_sy);

virtual void create()
{	
	set_name("江上流", "jiang shangliu");
	set("title", "丐帮五袋弟子");
	set("gender", "男性");
	set("age", 19);
	set("long", "这是位丐帮五袋弟子，看来是个英雄人物。");
	set("attitude", "peaceful");
	set("class", "beggar");
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 27);
	set("max_hp", 660);
	set("icon",begger);
	
	set("beggarlvl", 5);
	
	set("mp",250);
	set("max_mp", 250);
	set("mp_factor",25);
	set("combat_exp", 50000);
	set_skill("force", 50);
	set_skill("huntian_qigong", 50);
	set_skill("unarmed", 50);
	set_skill("xianglong_zhang", 50);
	set_skill("dodge", 50);
	set_skill("xiaoyaoyou", 50);
	set_skill("parry", 50);
	set_skill("begging", 50);
	//        set_skill("checking", 50);
	set_skill("xunshou_shu", 50);

	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	create_family("丐帮", 20, "弟子");
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
