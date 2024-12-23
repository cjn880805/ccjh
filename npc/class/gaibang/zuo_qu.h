//zuo_qu.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_zuo_qu);

virtual void create()
{
	set_name("左齐", "zuo qi");
	set("title", "丐帮七袋弟子");
	set("gender", "男性");
	set("age", 35);
	set("long", "这是位豪爽大方的丐帮七袋弟子，看来是个北地豪杰。");
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 26);
	set("icon",begger);

	set("beggarlvl", 7);
	
	set("hp", 360);
	set("max_hp", 1200);
	set("mp", 710);
	set("max_mp", 710);
	set("mp_factor", 36);
	
	set("combat_exp", 68000);
	
	set_skill("force", 73); 
	set_skill("huntian_qigong", 70); 
	set_skill("unarmed", 70); 
	set_skill("xianglong_zhang", 73); 
	set_skill("dodge", 70); 
	set_skill("xiaoyaoyou", 71); 
	set_skill("parry", 70); 
	set_skill("begging", 50); 
//	set_skill("checking", 50);
	set_skill("xunshou_shu", 40);
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
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
	else
		accept_student(me);
}

NPC_END;
