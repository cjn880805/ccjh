NPC_BEGIN(CNmonster_28k);

virtual void create()
{
	// static char xunbuname[3][11]={"À¶ÒÂÐ¡×ä","À¶²¼ÒÂÐ¡×ä","µåÒÂÐ¡×ä"};
	 static char xunbuname[3][9]={"Ë£ºòÈË","Ëá¸¯ÊéÉú","ÓØ¸¯ÎÄÉú"};

	 set_name(xunbuname[random(3)],"man");

	
	set("icon", banditi);
	set("gender", "ÄÐÐÔ");
	set("attitude", "peaceful");

		
	set("combat_exp", 56000);
		
	
	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 20);
	set_temp("apply/defense", 20);

//    carry_object("cloth")->wear();

	set("max_hp", 4500);

	set("shen_type", 1);

	set("mp", 500);
	set("max_mp", 500);

//    carry_object("cloth")->wear();

	add_money(500 + random(200));
};

NPC_END;
