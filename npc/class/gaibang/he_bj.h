//he_bj.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_he_bj);

virtual void create()
{
	set_name("何不污", "he buwu");
	set("title", "丐帮七袋弟子");
	set("gender", "男性");
	set("age", 30);
	set("long", 
		"这是位衣著邋塌，蓬头垢面的丐帮七袋弟子。");
	set("attitude", "heroism");
	set("class", "beggar");
	set("str", 28);
	set("int", 18);
	set("con", 24);
	set("dex", 20);
	set("icon",begger);

	set("beggarlvl", 7);

	set("hp", 380);
	set("max_hp", 1000);
	set("mp", 680);
	set("max_mp", 680);
	set("mp_factor", 34);
	
	set("combat_exp", 90000);
	
	set_skill("force", 70); 
	set_skill("huntian_qigong", 75); 
	set_skill("unarmed", 75); 
	set_skill("xianglong_zhang", 75); 
	set_skill("dodge", 65); 
	set_skill("xiaoyaoyou", 70); 
	set_skill("parry", 93); 
	set_skill("begging", 60); 
	set_skill("stealing", 70); 
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("parry", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	
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
	if( me->query_combat_exp() < 30000 )
	{
		say("我生平第一喜好就是打架斗欧，你看来没这种嗜好吧？");
		return;
	}
	else
		accept_student(me);
}

NPC_END;
