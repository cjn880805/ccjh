NPC_BEGIN(CNmonster_1632k);

virtual void create()
{
	 static char xunbuname[3][9]={"СͷĿ","ʿ��","���˴̿�"};
//	 static char xunbuname[3][9]={"��ɽ����","���ŵ���","��������"};

	 set_name(xunbuname[random(3)],"shi zu");
	
	set("icon", banditi);
	set("gender", "����");
	set("attitude", "peaceful");

	set("combat_exp", 32000+random(32000));
		
	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 20);
	set_temp("apply/defense", 20);
	
	set_skill("force", 30);
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("hand", 30);

//    carry_object("cloth")->wear();

	set("shen_type", -1);
	set("max_hp", 5000);

	set("mp", 100);
	set("max_mp", 100);

	add_money(100 + random(500));
};

NPC_END;
