//poorman.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_poorman);

virtual void create()
{
	set_name("�","poorman");
	
	set("icon", young_man4);
	set("gender", "����" );
	set("age", 33);
	set("long", "һ���������������ɫ�����");
	set("attitude", "friendly");
	set("combat_exp", 250);
	set("shen_type", 1);
	set("str", 20);
	set("dex", 18);
	set("con", 17);
	set("int", 13);
	
	set("chat_chance", 15);
	carry_object("cloth")->wear();
	
	
};

virtual char * chat_msg(CChar * me )
{
	switch(random(2))
	{
	case 0:
		return "�������ش��˸���Ƿ��";
	case 1:
		return "�˵������Щ�ɹ����Ӻ����Ҽ���������";
	}
	return "";
}

NPC_END;
