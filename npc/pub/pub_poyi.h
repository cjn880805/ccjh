//poyi.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_poyi);

virtual void create()
{
	set_name("朴仪","poyi");

	set("icon", young_monk);
	set("age", 22);
	set("gender", "男性");
	set("long", "他是一个和尚，是赤眉大师的大弟子。");
	set("attitude", "peaceful");

	set("str", 24);
	set("per", 20);
	set("dex", 26);
	set("combat_exp", 60000);
	set("shen_type", 1);
	set("class", "bonze");

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 60);

	carry_object("dao_cloth")->wear();



};


NPC_END;
