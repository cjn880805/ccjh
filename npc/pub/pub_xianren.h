NPC_BEGIN(CNpub_xianren);

virtual void create()
{
	set_name("С���","xianren");

	set("icon", cateran);
	set("long", "�����������С��죬��������û�¸ɡ�\n");
	set("gender", "����");
	set("age", 15);
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 15);
	set("str", 15);
	set("int", 14);
	set("con", 15);
	set("dex", 16);
	set("hp", 100);
	set("max_hp", 300);
	set("mp", 10);
	set("max_mp", 10);
	set("combat_exp", 200);

	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set("chat_chance", 10);
	add_money(100);

	carry_object("cloth")->wear();

};


virtual char * chat_msg(CChar * me )
{
	switch(random(2))
	{
	case 0:
		return "С������һ�������壬��ɽ���ϻ����ϻ�û�Է���ר�Դ󻵵���";
	case 1:
		return "С���������²��ã�����Ҫ����ĸ��ĸ���ҿ��������ܣ���";
	}
	return "";
}

NPC_END;
