// ya.c 牙将
//sound 2001-07-11

NPC_BEGIN(CNxiangyang_ya);

virtual void create()
{
	set_name("牙将", "ya jiang");
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("icon", general);
	set("long", "这是一个大宋将领，满脸征尘。");
	set("combat_exp", 35000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("changquan", 60);
	map_skill("unarmed", "changquan");
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);

	carry_object("gangjian")->wield();
	carry_object("tiejia")->wear();
}
/*
void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
*/
NPC_END;