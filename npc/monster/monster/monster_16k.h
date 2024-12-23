NPC_BEGIN(CNmonster_16k);

virtual void create()
{

	// static char xunbuname[3][11]={"����С��","����С��","ǳ����С��"};
	 static char xunbuname[3][11]={"ʧѧ����","�ѧ����","���ܵ���"};

	 set_name(xunbuname[random(3)],"di zi");

	set("icon", banditi);
	set("gender", "����");
	set("attitude", "peaceful");

	
	set("combat_exp", 32000 + random(16000));
	
	set_temp("apply/attack", 25);
	set_temp("apply/damage", 25);
	set_temp("apply/armor", 25);
	set_temp("apply/defense", 25);

	set("max_hp", 2000);

	set("shen_type", 1);

	set("mp", 100);
	set("max_mp", 100);

//    carry_object("cloth")->wear();

	add_money(180);
};

NPC_END;
