// liang.c
//sound 2001-07-16

NPC_BEGIN(CNhuanghe_liang);

virtual void create()
{
	set_name("梁老头", "liang ziwen");
	set("gender", "男性");
	set("nickname", "参仙老怪");
	set("age", 43);
	set("str", 25);
	set("per", 20);
	set("dex", 16);
	set("icon",old_man1);
	
	set("long", 
		"梁老头身材中等，满头白发如银，但脸色光润，神采弈弈，穿一\n"
		"件葛布长袍，打扮非道非俗。他是长白山武学的一派宗师。\n");

	set("combat_exp", 200000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);
	
	set("mp", 800); 
	set("max_mp", 800);
	set("mp_factor", 50);
	
//	carry_object("changpao")->wear();
}

NPC_END;