// peng.c
//sound 2001-07-16

NPC_BEGIN(CNhuanghe_peng);

virtual void create()
{
	set_name("彭单虎", "peng lianhu");
	set("gender", "男性");
	set("nickname", "千手人屠");
	set("age", 43);
	set("str", 25);
	set("dex", 16);
	set("per", 20);
	set("icon",banditi);
	
	set("long", 
		"彭单虎五短身材，满眼红丝，目光如电，上唇短须翘起。他生性残暴，和沙通天有深厚的交情。");
	set("combat_exp", 200000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("dagger", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);
	
	set("mp", 800); 
	set("max_mp", 800);
	set("mp_factor", 50);
	
//	carry_object("bi")->wield();
	carry_object("beixin")->wear();
}

NPC_END;