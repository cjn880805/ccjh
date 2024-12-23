// girldizi.c 女弟子
//code by sound
//12-16

NPC_BEGIN(CNemei_girldizi);

virtual void create()
{
 	set("icon",girl2);
	set_name("女弟子", "dizi");
	set("long", "她是峨嵋派的第五代俗家弟子。");
	set("gender", "女性");
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", 1);
	
	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_hp", 150);
	set("hp", 150);
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
}

NPC_END;