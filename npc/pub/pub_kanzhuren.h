NPC_BEGIN(CNpub_kanzhuren);

virtual void create()
{
	set_name("������","kanzhuren");
	
	set("icon", waiter);
	set("gender", "����" );
	set("age", 22);
	set("long", "һ��׳�����ס��ɽ�µĴ��������ɽ���������ӵġ�");
	set_temp("apply/defense", 15);
	set("combat_exp", 1700);
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
