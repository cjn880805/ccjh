NPC_BEGIN(CNpub_guanjia);

virtual void create()
{
	
	set_name("财主管家","guanjia");
	
	set("icon", pawnshop_boss);
	set("long","这是一位尖嘴候腮的老管家，一对小绿豆眼总在不停地转动着。");
	set("gender", "男性");
	set("age", 65);
	
	set("combat_exp", 7500);
	set_skill("unarmed", 35);
	set_skill("force", 35);
	set_skill("dodge", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 40);
	set("shen_type", -1);
	
	carry_object("magua")->wear();
	add_money(200);
	
	
	
};


NPC_END;
