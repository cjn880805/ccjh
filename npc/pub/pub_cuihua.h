NPC_BEGIN(CNPub_cuihua);

virtual void create()
{
	set_name("翠花","cuihua");

	set("icon", young_woman12);
	set("gender", "女性" );
	set("age", 25);
	set("long", "这是个打扮很妖艳的少妇，时不时的用眼角向电你");
	
	set("shen_type", -1);
	set("str", 15);
	set("dex", 18);
	set("con", 15);
	set("int", 17);
	set("combat_exp", 200);
	set_temp("apply/attack", 5);
	set_temp("apply/defense", 10);
	set("attitude", "peaceful");
	carry_object("shoes")->wear();
	carry_object("shoupa")->wear();
	carry_object("xiu_scarf")->wear();
	add_money(100);
	
	
};

NPC_END;
