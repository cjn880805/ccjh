NPC_BEGIN(CNmonster_4k);

virtual void create()
{

//	 static char xunbuname[3][9]={"灰衣小兵","黑衣小兵","乌衣小兵"};
	 static char xunbuname[4][9]={"小仆役","小用人","小厨师","小清洁工"};

	 set_name(xunbuname[random(4)],"nu yi");

	set("icon", banditi);
	set("gender", "男性");
	
	
	set("age", 10);
	set("combat_exp", 4000);
	set("attitude", "peaceful");

	set_temp("apply/attack", 5);
	set_temp("apply/damage", 5);
	set_temp("apply/armor", 5);
	set_temp("apply/defense", 5);

	
	set("max_hp", 800);

	set("shen_type", 1);

	set("mp", 100);
	set("max_mp", 100);

//    carry_object("cloth")->wear();

	add_money(10 + random(40));

};

NPC_END;
