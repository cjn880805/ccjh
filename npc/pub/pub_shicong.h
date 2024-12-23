//shicong.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_shicong);

virtual void create()
{
	set_name("侍从","shicong");

	set("icon", young_man2);
	set("age", 32);
	set("gender", "男性");
	set("long", "这位倒也打扮的利索，一身短打，白布包头，翘起的裤腿，一双洁白的布鞋，格外醒目。他正准备出去酬备白尼族一年一度的大会。");
	set("attitude", "peaceful");

	set("str", 24);
	set("per", 20);
	set("dex", 16);
	set("combat_exp", 20000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 100);
	set_skill("parry", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	carry_object("cloth")->wear();
};


NPC_END;
