NPC_BEGIN(CNmonster_32k);

virtual void create()
{
	 static char xunbuname[3][11]={"����С��","����С��","�����С��"};
//	 static char xunbuname[3][9]={"��ʮ�ߴ�����","��ʮ��������","��ʮ�������"};

	 set_name(xunbuname[random(3)],"xiao bing");

	
	set("icon", banditi);
	set("gender", "����");
	set("attitude", "peaceful");

	set("title","�ɹŹ�");
	
	set("combat_exp", 64000);


	set_temp("apply/attack", 30);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 30);
	set_temp("apply/defense", 30);

	set_skill("force", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("hand", 50);

//	carry_object("cloth")->wear();

	set("max_hp", 5000);

	set("shen_type", -1);

	set("mp", 800);
	set("max_mp", 800);

//    carry_object("cloth")->wear();

	add_money(600 + random(400));

};

NPC_END;
