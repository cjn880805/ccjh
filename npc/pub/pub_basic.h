NPC_BEGIN(CNPub_basic);

virtual void create()
{
	set_name("花无缺","basic");

	set("icon", young_man1);
	set("nickname", "铁掌降龙");
	set("gender", "男性");
	set("age", 20);
	set("long","他就是大侠花无缺。");

	set("combat_exp", 500000);
	
	carry_object("jinduan")->wear();
};

NPC_END;
