NPC_BEGIN(CNPub_caisangnu);

virtual void create()
{
	set_name("��ɣŮ","caisangnu");

	set("icon", young_woman3);
	set("gender", "Ů��" );
	set("age", 17);
	set("long", "һ������İ��Ĳ�ɣ���");
	
	set_temp("apply/defense", 5);
	set("combat_exp", 7000);
	set("shen_type", 1);
	set("per", 23);
	set("str", 14);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	carry_object("bduanqun")->wear();
	carry_object("rice3")->wear();
	
	
};

NPC_END;
