NPC_BEGIN(CNmonster_416k);

virtual void create()
{
	// static char xunbuname[3][9]={"�ٷ�","ʮ��","�ֶӶӳ�"};
	 static char xunbuname[3][9]={"��������","����Ů","��Ů"};

	 set_name(xunbuname[random(3)],"girl");

	
	set("icon", girl1);
	set("gender", "Ů��");
	set("attitude", "peaceful");

		
	set("combat_exp", 4000+random(12000));
	
	
	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 20);
	set_temp("apply/defense", 20);

	
	set("max_hp", 1000);

	set("shen_type", 1);

	set("mp", 200);
	set("max_mp", 200);

//    carry_object("cloth")->wear();

	add_money(180 + random(200));
};

NPC_END;
