NPC_BEGIN(CNPub_caisunren1);

virtual void create()
{
	set_name("������","caisunren1");
	
	set("icon", banditi);
	set("gender", "����" );
	set("age", 22);
	set("long", "һ��׳�����ס��������Ĵ�ׯ�������˸��������һ�ѿ��񵶣���ɽ��������");
	
	set_temp("apply/defense", 15);
	set("combat_exp", 170);
	set("shen_type", 1);
	set("per", 18);
	set("str", 24);
	set("dex", 25);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	
	carry_object("maotan")->wear();
	carry_object("kandao")->wield();
	
};

NPC_END;
