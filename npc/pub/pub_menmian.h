//menmian.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_menmian);

virtual void create()
{
	set_name("蒙面人","menmian");

	set("icon", masked_man);
	set("gender", "男性");
	set("age", random(10) + 40);
	set("str", 25);
	set("dex", 16);
	set("per", 20);
	set("long", "一个黑布蒙面，神秘兮兮的家伙。");
	set("combat_exp", 20000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("unarmed", 30);
	set_skill("force", 30);
	set_skill("dagger", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 20);

	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);

	carry_object("fenshuici")->wield();
	carry_object("shuikao")->wear();
};

NPC_END;
