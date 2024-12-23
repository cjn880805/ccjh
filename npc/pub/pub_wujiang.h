NPC_BEGIN(CNPub_wujiang);

virtual void create()
{
	set_name("武将","wujiang");

	set("icon", general);
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "他站在那里，的确有说不出的威风。");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);

	carry_object("gangjian")->wield();
	carry_object("tiejia")->wear();



};


virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && !is_fighting())
	{
		if(me->query_condition("killer"))
			kill_ob(me);
	}
}

NPC_END;
