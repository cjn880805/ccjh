NPC_BEGIN(CNmonster_6k);

virtual void create()
{

//	 static char xunbuname[3][11]={"����С��","������С��","����С��"};
	 static char xunbuname[3][9]={"С�ӹ�","С���","С��å"};

	 set_name(xunbuname[random(3)],"worker");

	
	set("icon", banditi);
	set("gender", "����");
	
	
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
