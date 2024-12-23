//scavenger.h
//Teapot 2000-01-05

NPC_BEGIN(CNpub_scavenger);

virtual void create()
{
	set_name("�ķ�Ѳ��ʹ��", "Scavenger");
	set("long", "��һ��Ʈ�ݵİ�ɫ���������ĺ���˵�е����ơ�");
	set("title", "[������]");
	set("gender", "����");
	set("age", 27);
	set("per", 5);
	set("attitude", "friendly");
	set("icon", young_man3);

	set("chat_chance", 5);
	set("no_huan",1);
};

virtual char * chat_msg()
{
	random_move();
	return 0;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (!ob->query("pub_rubbish"))
		return 0;

	int i;
	i=ob->query("valued");
	char msg[255];
	who->add("combat_exp",i);
	message_vision(snprintf(msg, 255, "$N�����%d���飡", i), who);
	DESTRUCT_OB(ob, "pub_scavenger::accept_object");

	return 1;
}

NPC_END;
