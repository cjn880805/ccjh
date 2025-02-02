NPC_BEGIN(CNPub_boydizi);

virtual void create()
{
	set_name("男弟子","boydizi");
	
	set("icon", taoist);
	set("long","他是峨嵋派的第五代俗家弟子。");
	set("gender", "男性");
	set("age", 16);
	set("attitude", "peaceful");
	set("shen_type", 1);
	
	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_hp", 450);
	set("mp", 150);
	set("max_mp", 150);
	
	set("combat_exp", 2000);
	set("score", 1000);
	
	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
	
	create_family("峨嵋派", 5, "弟子");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	
	
};

NPC_END;
