NPC_BEGIN(CNPub_caisunren);

virtual void create()
{
	set_name("������","caisunren");

	set("icon", young_woman2);
	set("gender", "Ů��" );
	set("age", 22);
	set("long", "һ��¬¹��������̨�ĸ�Ů�������˸��������һ�ѿ��񵶣���������");
	set_temp("apply/defense", 15);
	set("combat_exp", 170);
	set("shen_type", 1);
	set("per", 18);
	set("str", 24);
	set("dex", 25);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	
	carry_object("tongqun")->wear();
	carry_object("kandao")->wield();
	
	
};

NPC_END;
