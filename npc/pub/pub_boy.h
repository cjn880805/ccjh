NPC_BEGIN(CNPub_boy);

virtual void create()
{
	set_name("�к�","boy");

	set("icon", boy1);
	set("long","���Ǹ�ƽ�����꣬��С�ڳ��л�죬�����ú��ˡ�");
	set("gender", "����" );
	
	set("age", 13);
	set("str", 17);
	set("dex", 16);
	set("con", 15);
	set("int", 17);
	set("shen_type", 1);
	set_temp("apply/defense", 10);
	set("combat_exp", 100);
	set("attitude", "peaceful");

	set("nkgain", 30);
	
//	carry_object("cloth")->wear();
	add_money(10);
	
};

NPC_END;
