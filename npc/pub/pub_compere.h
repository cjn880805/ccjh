// pub_compere.h �����շ���


NPC_BEGIN(CNpub_compere);

virtual void create()
{
	set_name("��ƽ��", "gongping zi");
	set("gender", "����");
	set("age", 45);
	set("icon",triggerman1);
	set("no_kill",1);
	set("long", "��ɽ�۽���������");
	
	set_inquiry("�����۽�", "��ƽ��˵���������������д裬ÿ���轻3�������ѡ�");
	set("no_huan",1);
};


virtual int accept_object(CChar * who, CContainer * ob)
{
	if(who->is_busy())
		return notify_fail("����һ��������û�����");

	if (DIFFERSTR(ob->querystr("id"), "coin") )
	{	
		say("��ƽ����ü˵��������ҵ���ʲô�������ҿ���ֻ��ʶǮ�ġ�", who);
		SendMenu(who);
		return 0;
	}

	if (ob->query("value") <30000) 
	{	
		say("��ƽ��Ц����˵������������������д裬����Ƚ���3����������˵����һ�����Ӷ����㻻������ȥˣ��", who);
		SendMenu(who);
		return 0;
	}
	
	message_vision("��ƽ��˵��������$N����������������������ѱ���ʹ��KILLָ���д��ˣ����佫�ɱ�������֤��", who);
	who->set_temp("����",1);
	destruct(ob);
	add("biwu/count",1);
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		me->start_busy(2);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}
NPC_END;



