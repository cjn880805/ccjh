NPC_BEGIN(CNmonster_3248k);

virtual void create()
{
	 static char xunbuname[3][9]={"领兵","流寇","马贼"};
//	 static char xunbuname[3][9]={"种子弟子","当红弟子","散步弟子"};

	 set_name(xunbuname[random(3)],"man");

	
	set("icon", banditi);
	set("gender", "男性");
	set("attitude", "peaceful");

	
	set("combat_exp", 64000+random(32000));

	set_temp("apply/attack", 30);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 30);
	set_temp("apply/defense", 30);

	set_skill("force", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("hand", 50);
	
//    carry_object("cloth")->wear();

	set("max_hp", 5000);

	set("shen_type", -1);

	set("mp", 800);
	set("max_mp", 800);

//    carry_object("cloth")->wear();

	add_money(200 + random(600));

};

NPC_END;
