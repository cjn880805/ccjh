NPC_BEGIN(CNmonster_8k);

virtual void create()
{

	static char xunbuname[4][9]={"����","Ӷ��","��ʦ","��๤"};

	 set_name(xunbuname[random(4)],"man");

	
	set("icon", banditi);
	set("gender", "����");
	set("attitude", "peaceful");
	
	set("combat_exp", 8000);

	set_temp("apply/attack", 10);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 10);
	set_temp("apply/defense", 10);
	
	set("shen_type", -1);
	set("max_hp", 2000);

	set("mp", 100);
	set("max_mp", 100);

//    carry_object("cloth")->wear();
	add_money(100);
};

NPC_END;
