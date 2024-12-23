// menggubing.c
//sound 2001-07-11

NPC_BEGIN(CNxiangyang_menggubing);

virtual void create()
{
	set_name("ÃÉ¹Å±ø", "menggu bing");
	set("long", "ÃÉ¹Å±ø³¤ÄêÔ¾ÂíºáÇ¹£¬Ê®·ÖæçÓÂ¡£");
	set("gender", "ÄÐÐÔ");
	set("age", 18);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 24);
	set("str", 20);
	set("int", 40);
	set("con", 20);
	set("dex", 20);
	set("icon", general);
	
	set("max_hp", 800);
	set("hp", 800);
	set("mp", 100);
	set("max_mp", 100);
	set("combat_exp", 60000);

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("unarmed", 40);
	set_skill("club", 40);
	set_skill("zhongpingqiang", 40);
	map_skill("club", "zhongpingqiang");

	set("env/wimpy", 60);
	set_temp("is_riding", "ÃÉ¹ÅÂí");
	set("env/wimpy", 40);

 	carry_object("tiejia")->wear();
	carry_object("changqiang")->wield();
}

NPC_END;