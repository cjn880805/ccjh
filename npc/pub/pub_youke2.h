//youke2.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_youke2);

virtual void create()
{
	set_name("游客乙","youke");

	set("icon", young_man4);
	set("gender", "男性" );
	set("age", random(20)+10);
	set("long", "这是一个游山玩水的游人。");
	
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 20);
	set("combat_exp", 2000);
	set("shen_type", 1);
	set("str", 24);
	set("dex", 20);
	set("con", 20);
	set("int", 18);
	set("attitude","friendly");
	
	carry_object("cloth")->wear();
	add_money(500);
	
};



NPC_END;
