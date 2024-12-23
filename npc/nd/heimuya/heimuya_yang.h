//heimuya_yang.h 杨莲亭
//code by sound
//2001-07-10

NPC_BEGIN(CNheimuya_yang);

virtual void create()
{
	set_name("莲弟", "yang lianting");
	set("long","他身形魁梧，满脸虬髯，形貌极为雄健。");
	set("title", "日月神教成德堂总管");
	set("gender", "男性");
	set("age", 40);
	set("per", 29);
 	set("icon",young_man6);

	set("hp",500);
	set("max_hp",500);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 10);

	set("combat_exp", 50000);
	set("shen_type", -1);
	add_money(5000);
//	carry_object("yaoshi");
//	carry_object("zaohong")->wear();
}

NPC_END;	
