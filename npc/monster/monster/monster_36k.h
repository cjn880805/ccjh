NPC_BEGIN(CNmonster_36k);

virtual void create()
{
	 static char xunbuname[3][11]={"����С��","����С��","ǳ����С��"};
//	 static char xunbuname[3][9]={"��ʮ�Ĵ�����","��ʮ��������","��ʮ��������"};

	 set_name(xunbuname[random(3)],"xiao bing");

	
	set("icon", banditi);
	set("gender", "����");
	set("attitude", "peaceful");

	set("title","�ɹŹ�");
	
	set("combat_exp", 36000);


	set_temp("apply/attack", 80);
	set_temp("apply/damage", 80);
	set_temp("apply/armor", 80);
	set_temp("apply/defense", 80);

	
//    carry_object("cloth")->wear();

	set("max_hp", 5000);

	set("shen_type", -1);

	set("mp", 1000);
	set("max_mp", 1000);

//    carry_object("cloth")->wear();

	add_money(800 + random(200));
};

NPC_END;
