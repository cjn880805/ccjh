NPC_BEGIN(CNPub_cungu);

virtual void create()
{
	set_name("���","cungu");

	set("icon", young_woman8);
	set("gender", "Ů��" );
	set("age", 20);
	set("long", "һ�������������ũ��������һֻ���Ų�С���ӡ�");
	set("shen_type", 1);
	set("combat_exp", 4000);
	set("str", 15);
	set("dex", 16);
	set("con", 15);
	set("int", 17);
	set("attitude", "friendly");
	
	carry_object("cloth")->wear();
    carry_object("caomei");
    carry_object("turou");
	
};


virtual char * combat_chat_msg()
{
	switch(random(4))
	{
	case 0:
		return "���˵������ѽ�����컯��֮�£�ǿ��ɱ��ѽ��";
	case 1:
	case 2:
		return "���˵���๫����ѽ����������Ҫǿ���ң�";
	case 3:
		return "���˵����Ҫɱ���ҵ��ˣ�";
	}

	return "";
}

NPC_END;
