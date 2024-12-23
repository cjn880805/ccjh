NPC_BEGIN(CNPub_cunfu);

virtual void create()
{
	set_name("村妇","cunfu");

	set("icon", young_woman10);
	set("gender", "女性" );
	set("age", 27);
	set("long", "一个年轻的摆夷村妇。");
	set_temp("apply/defense", 5);
	set("combat_exp", 3000);
	set("shen_type", 1);
	set("per", 20);
	set("str", 24);
	set("dex", 25);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	carry_object("tduanqun")->wear();
	
};

NPC_END;
