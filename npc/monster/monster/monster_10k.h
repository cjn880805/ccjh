NPC_BEGIN(CNmonster_10k);

virtual void create()
{
	 static char xunbuname[3][9]={"要饭的","流浪汉","小地痞"};

	 set_name(xunbuname[random(3)],"man");

	set("icon", banditi);
	set("gender", "男性");
	set("attitude", "peaceful");
	
	set("combat_exp", 10000);
	
	set("age", 20);

	set_temp("apply/attack", 10);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 10);
	set_temp("apply/defense", 10);
	
	set("shen_type", -1);
	set("max_hp", 2000);

	set("mp", 100);
	set("max_mp", 100);

//    carry_object("cloth")->wear();
};

NPC_END;
