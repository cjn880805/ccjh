//daotong.h
//code by zwb
//1-15

NPC_BEGIN(CNwudang_daotong);

virtual void create()
{
	set_name("道童", "daotong");
	set("long","他是武当山的小道童。");
	set("gender", "男性");
	set("age", 16);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("icon",taoist);	
	set("foolid",136);
	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_hp", 900);
	set("mp", 200);
	set("max_mp", 200);

	set("combat_exp", 2000);
	set("score", 1000);

	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);

	create_family("武当派", 5, "弟子");
	carry_object("greyrobe")->wear();
}

NPC_END;