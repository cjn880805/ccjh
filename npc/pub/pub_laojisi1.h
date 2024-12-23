//laojisi1.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_laojisi1);

virtual void create()
{
	set_name("乌夷老祭司","laojisi");

	set("icon", pub_boss);
	set("gender", "男性");
	set("age", random(10) + 60);
	set("str", 25);
	set("dex", 16);
	set("long", "一个乌夷族的祭司，身披乌夷大麾，戴着颇多金银饰物，显示其地位不凡。");
	set("combat_exp", 3000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 30);
	set_skill("force", 30);
	set_skill("sword", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 30);

	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);

	carry_object("wdahui")->wear();

};

virtual void init(CChar * me)
{
	if(me->query_condition("killer"))
		kill_ob(me);
}
NPC_END;
