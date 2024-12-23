//tongzi.h
//Lanwood 2000-01-05
void setup_char(CChar * me);

NPC_BEGIN(CNbtshan_tongzi);

virtual void create()
{
	set_name("����ͯ��", "tongzi");
	set("gender", "����" );
	set("age", 16);
	set("long", "���Ǹ���������������ͯ�ӡ�");
	set("attitude", "friendly");
	set("shen_type", -1);
	
	set("icon", young_man2);

	set("str", 21);
	set("int", 21);
	set("con", 21);
	set("dex", 20);
        set_inquiry("����","��ֻ��Ҫ֪������������ͯ�Ӿ͹��ˣ���Ҳû�б�����");
	set("max_hp", 600);
	set("combat_exp", 10000);
	set("score", 500);
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry",20);
	create_family("����ɽ��",10,"����");
	set("no_talk",1);
};

virtual void attempt_apprentice(CChar * me)
{
	say("�Ҳ�����ͽ���㻹�ǰ����ͷ�ɡ�", me);
	SendMenu(me);
    return;
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	say("�������ұȻ����С�", me);
	AddMenuItem("�ã����ҾͲ������ˡ�", "$0bi $1", me);
	AddMenuItem("������˵�ɡ�", "", me);
	SendMenu(me);
	return CNpc::do_talk(me,ask);
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "bi") == 0)
		return do_bi(me);

	return CNpc::handle_action(comm, me, arg);
}

int do_bi(CChar * me)
{
	if (me->query_combat_exp() < 10000)
	{
		set("combat_exp", me->query_combat_exp());
		set("level", me->query("level"));
	}

	Do_BiShi(this, me, "����ͯ�ӵı��Ի�");
	return 1;
	
}

virtual void is_defeated(CChar * winner, CChar * failer)
{
	set("eff_hp",200);
	set("hp",200);
	set("combat_exp", 10000);
	del("level");
	setup_char(this);

	if(failer == this)
	{
		message_vision("����ͯ�Ӷ�$N�������!", winner);
	}
	else
	{
		message_vision("����ͯ�Ӷ�$NЦЦ����Ŭ���ɡ�", winner);
	}
}

NPC_END;
