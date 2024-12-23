//xixiabing.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_xixiabing);

virtual void create()
{
	set_name("西夏兵","xixiabing");

	set("icon", general);
	set("gender", "男性");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("long", "一个魁武的西夏士兵。");
	set("combat_exp", 8000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 30);
	set_skill("force", 30);
	set_skill("club", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/armor", 20);
	set_temp("apply/damage", 20);

	set("mp", 100); 
	set("max_mp", 100);
	set("mp_factor", 10);

	carry_object("changqiang")->wield();
	carry_object("junfu")->wear();

};



NPC_END;
