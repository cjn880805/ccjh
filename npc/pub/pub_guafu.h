NPC_BEGIN(CNpub_guafu);

virtual void create()
{

	set_name("С�Ѹ�","guafu");

	set("icon", young_woman12);
	set("gender", "Ů��" );
	set("age", 25);
	set("long", "һ������Ư���ֲ��ʼ�į��С�Ѹ���");
	set("shen_type", -1);
	set("combat_exp", 10000);
	set("str", 18);
	set("dex", 19);
	set("con", 19);
	set("int", 19);
	set("attitude", "friendly");
	set("chat_chance",20);

	carry_object("green_cloth")->wear();

	add_money(120);


};

virtual char * chat_msg(CChar * me )
{
	switch(random(2))
	{
	case 0:
		return "С�Ѹ��޵����ҿ����ķ��ۣ�����ôƲ���Ҳ�����Ӵ :~(";
	case 1:
		return "С�Ѹ�Ĩ�˰����ᣬ���������һ�ۡ�";
	}
	return "";
}


NPC_END;
