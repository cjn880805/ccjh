NPC_BEGIN(CNmonster_24k);

virtual void create()
{
	// static char xunbuname[3][11]={"����С��","������С��","����С��"};
	 static char xunbuname[3][9]={"Сѧͽ","С����","ĩ������"};

	 set_name(xunbuname[random(3)],"di zi");

	
	set("icon", banditi);
	set("gender", "����");
	set("attitude", "peaceful");

		
	set("combat_exp", 24000);

			
	set_temp("apply/attack", 35);
	set_temp("apply/damage", 35);
	set_temp("apply/armor", 35);
	set_temp("apply/defense", 35);

	set("max_hp", 3500);

	set("shen_type", 1);

	set("mp", 300);
	set("max_mp", 300);

//    carry_object("cloth")->wear();

	add_money(400 + random(200));

};

NPC_END;
