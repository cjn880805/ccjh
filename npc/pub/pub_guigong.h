NPC_BEGIN(CNpub_guigong);

virtual void create()
{
	set_name("�깫","guigong");
	
	set("icon", young_man2);
	set("gender", "����");
	set("age", 25);
	
	set("long", "һ����������ĺ��ӣ�������Ժ���Ӿ��ˣ����İװ׷ʷʡ�");
	set("combat_exp", 30000);
	set("shen_type", 2);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	carry_object("cloth")->wear();
};

virtual char * chat_msg(CChar * me )
{
	switch(random(3))
	{
	case 0:
		return "�깫����С��Ƥ����������͹ԹԵ��̺��ү�ǰɡ�";
	case 1:
		return "�깫�������ܣ��ܵ����ĺ��Ƕ�����׷������";
	case 2:
		return "�깫�����ߣ�������ЩС���ˣ���ã�";
	}
	return "";
}

NPC_END;
