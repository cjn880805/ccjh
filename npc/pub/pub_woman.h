//woman.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_woman);

virtual void create()
{
	set_name("ά����帾Ů","woman");
	
	set("icon", young_woman8);
	set("gender", "Ů��" );
	set("age", 40);
	set("long", "һ�����ֵ�ά��������긾Ů��");
	
	set("repute", 1000);
	set("combat_exp", 150);
	set("nkgain", 40);
	set("env/wimpy", 60);
	set("chat_chance_combat", 50 );
	set("str", 13);
	set("dex", 12);
	set("con", 14);
	set("int", 13);
	set("attitude", "friendly");
	set("chat_chance", 10);
	
	carry_object("wcloth")->wear();
	add_money(100);
	
};

virtual char * chat_msg(CChar * me)
{
	switch(random(3))
	{
	case 0:
		return "ά����帾Ů������Ц������";
	case 1:
		return "ά����帾Ů˵����С������ѽ������";
	case 2:
		return "ά����帾Ů����Ŭ��Ŭ�죬��ָ��ָ���ߡ�";
	}
	return "";
}

NPC_END;
