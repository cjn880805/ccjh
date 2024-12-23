//xiaowei.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_xiaowei);

virtual void create()
{
	set_name("校尉","xiaowei");

	set("icon", general);
	set("gender", "男性");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("long", "一个魁武的西夏军官。");
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 30);

	set("mp", 100); 
	set("max_mp", 100);
	set("mp_factor", 10);

	carry_object("junfu")->wear();
	carry_object("wandao")->wield();

};

NPC_END;
