NPC_BEGIN(CNmonster_44k);

virtual void create()
{
	 static char xunbuname[3][9]={"����С��","����С��","����С��"};
//	 static char xunbuname[3][9]={"�ڰ˴�����","���ߴ�����","����������"};

	 set_name(xunbuname[random(3)],"xiao bing");

	
	set("icon", banditi);
	set("gender", "����");
	set("attitude", "peaceful");

	set("title","�ɹŹ�");
	
	set("combat_exp", 88000);

	set_temp("apply/attack", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/defense", 50);

	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("hand", 70);
	
	set("max_hp", 8000);

	set("shen_type", -1);

	set("mp", 1000);
	set("max_mp", 1000);

//    carry_object("cloth")->wear();

	add_money(500 + random(800));
};

NPC_END;
