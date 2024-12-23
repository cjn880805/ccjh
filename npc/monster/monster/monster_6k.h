NPC_BEGIN(CNmonster_6k);

virtual void create()
{

//	 static char xunbuname[3][11]={"青衣小兵","淡青衣小兵","绿衣小兵"};
	 static char xunbuname[3][9]={"小杂工","小混混","小流氓"};

	 set_name(xunbuname[random(3)],"worker");

	
	set("icon", banditi);
	set("gender", "男性");
	
	
	set("age", 10);
	set("combat_exp", 6000);
	set("attitude", "peaceful");
	
	set_temp("apply/attack", 8);
	set_temp("apply/damage", 8);
	set_temp("apply/armor", 8);
	set_temp("apply/defense", 8);

	
	set("max_hp", 1000);

	set("shen_type", -1);

	set("mp", 100);
	set("max_mp", 100);

//    carry_object("cloth")->wear();

	add_money(50 + random(50));
};

NPC_END;
