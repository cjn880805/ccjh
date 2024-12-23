//qian.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_qian);

virtual void create()
{
	set_name("路青健","qian");

	set("icon", young_man2);
	set("gender", "男性");
	set("title", "黄河四鬼老四");
	set("nickname", "丧门斧");
	set("age", 32);
	set("str", 25);
	set("dex", 16);
	set("per", 16);
	set("long", "路青健是黄河四鬼的老四，是鬼门龙王沙彻地四弟子，擅于斧法。");
	set("combat_exp", 20000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("unarmed", 30);
	set_skill("force", 30);
	set_skill("axe", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);

	carry_object("axe")->wield();
	carry_object("cloth")->wear();

};


NPC_END;
