NPC_BEGIN(CNPub_cunmin);

virtual void create()
{
	set_name("����","cunmin");

	set("icon", banditi);
	set("gender", "����" );
	set("age", 30);
	set("long", "һ�������ׯ�ں��ӡ�");
	set("attitude", "friendly");
	set("combat_exp", 500);
	set("repute", 100);
	set("shen_type", 1);
	set("str", 22);
	set("dex", 18);
	set("con", 18);
	set("int", 13);
	set("chat_chance", 15);
	
	carry_object("cloth")->wear();
	add_money(100);
	
	
};

virtual char * chat_msg(CChar * me)
{
	switch(random(2))
	{
	case 0:
		return "����˵�������ȫ��̵ĵ�ү�ǣ���ɽ��ҧׯ�ڵ����ȫ�����Ǹ������ˡ�";
	case 1:
		return "����˵����������ճɲ����ҵø�ȫ��̵ĵ�ү���͵��ȥ�������ǳ����ʡ�";
	}
	return "";
}

NPC_END;
