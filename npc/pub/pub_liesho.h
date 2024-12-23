//liesho.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_liesho);

virtual void create()
{
	set_name("台夷猎人","liesho");
	
	set("icon", young_man1);
	set("age", 32);
	set("gender", "男性");
	set("long", "一位台夷族的猎手，擅用短弩，射飞鸟。");
	set("attitude", "peaceful");
	
	set("str", 24);
	set("per", 20);
	set("dex", 16);
	set("combat_exp", 20000);
	set("shen_type", 1);
	
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 20);
	
	carry_object("ttoujin")->wear();
	carry_object("xiaoao")->wear();
};

NPC_END;
