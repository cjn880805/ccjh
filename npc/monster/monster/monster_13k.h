NPC_BEGIN(CNmonster_13k);

virtual void create()
{

	 //static char xunbuname[3][11]={"����С��","����С��","�����С��"};
	 static char xunbuname[3][9]={"���ǵ���","�������","�������"};

	 set_name(xunbuname[random(3)],"di zi");

	
	set("icon", banditi);
	set("gender", "����");
	set("attitude", "peaceful");
	
	set("combat_exp", 26000);

	set_temp("apply/attack", 15);
	set_temp("apply/damage", 15);
	set_temp("apply/armor", 15);
	set_temp("apply/defense", 20);

	set("shen_type", -1);
	set("max_hp", 3000);

	set("mp", 200);
	set("max_mp", 200);
	
//    carry_object("cloth")->wear();
	add_money(random(300) + 50);

};

NPC_END;
