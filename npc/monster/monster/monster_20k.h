NPC_BEGIN(CNmonster_20k);

virtual void create()
{
	// static char xunbuname[3][9]={"ºÚÒÂÐ¡×ä","»ÒÒÂÐ¡×ä","ÎÚÒÂÐ¡×ä"};
	 static char xunbuname[3][9]={"Âô³ªÕß","ÂôÒÕÈË","ÄÁÑòÈË"};

	 set_name(xunbuname[random(3)],"man");

	
	set("icon", banditi);
	set("gender", "ÄÐÐÔ");
	set("attitude", "peaceful");

	set("combat_exp", 20000 + random(50000));
	
	
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 30);
	set_temp("apply/defense", 30);

	set("max_hp", 2000);

	set("shen_type", 1);

	set("mp", 100);
	set("max_mp", 100);

//    carry_object("cloth")->wear();

	add_money(200 + random(300));

};

NPC_END;
