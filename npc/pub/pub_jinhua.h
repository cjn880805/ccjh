// pub_jinhua.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_jinhua);

virtual void create()
{
	set_name("��","jin hua");

	set("icon", young_woman5);
	set("gender", "Ů��" );
	set("age", 24);
	set("long", "һ������ò���Ĺ��");
	set("shen_type", 1);
	set("combat_exp", 800);
	set("str", 18);
	set("dex", 18);
	set("con", 18);
	set("int", 18);
	set("gold_times", 1);
	set("attitude", "friendly");
	set("chat_chance",20);
	set_inquiry("����","���������۾�����֪������������������������ҿ�����");
	set_inquiry("�廨Ь","�𻨳Ծ��ؿ����㣺�������廨Ь�𣿿���ҿ�����");
	set("no_huan",1);
}

virtual char *	chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "�𻨿����ţ��ҵ�����ô��ô��Ӵ��";
	case 1:
		return "��Ĩ�����᣺��ѽ���Һ�����ѽ��";
	case 2:
		return "��̾����˵������֪���������ܷ��ټ��������";
	}
	return "";
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	return snprintf(msg,255,"��һ�����˽�����æ˵����λ%s�������ǡ�����ɽׯ������Ӷ�ˡ������������Ϣ��",query_respect(ob) );
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	
	if (query("gold_times") < 1) return notify_fail("�����廨Ь�ˡ�");

	if ( DIFFERSTR(ob->querystr("base_name"), "shoe"))
		return notify_fail("�𻨲���Ҫ���������");
	
	say( "��˫�������廨Ь���������£� ��������ڣ���������Ů�������һ���Ϊ�����أ�", who);
	
	say( snprintf(msg,255,"��λ%s��Ц�ˡ� ��Ҳûʲô���������㣬��ֻ֪��ɽ��ͷ�и�Ǯ����ڴ��¡� ����͸���������",query_respect(who)), who);

	CMoney::Pay_Player(who,10000);
	set("gold_times",0l);
	return 1;
}

NPC_END;