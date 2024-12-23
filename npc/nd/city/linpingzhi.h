// linpingzhi.c 林平之
//zhangdongni 2001-07-18


NPC_BEGIN(CNcity_linpingzhi);

virtual void create()
{

	set_name("林换之", "lin huanzhi");
    set("nickname", "少当家");
	set("gender", "男性");
	set("age", 20);
	set("long", "他就是「福威镖局」的少当家－－林换之。");
	set("icon",young_man3);

	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("sword", 40);
	set_skill("unarmed", 30);
	set_skill("dodge", 40);
	set_skill("parry", 40);

	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 10);
	
//	carry_object("cloth")->wear();
//	add_money(5);
	
}
NPC_END;
	
