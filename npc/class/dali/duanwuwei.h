//duanwuwei.h
//code by zwb
//12-16
//inherit F_MASTER;

NPC_BEGIN(CNdali_duanwuwei);

virtual void create()
{
	set_name("����ζ","duan wuwei");

	set("title",  "���������ܼ�" );
	set("long", "���Ǵ�������������ܼҡ�");
	set("gender", "����");
	set("age", 40);
	set("icon", young_man2);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_hp", 1800);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 10);
	set("combat_exp", 30000);
	set("score", 2000);

    set_skill("force", 45);
    set_skill("dodge", 45);
    set_skill("parry", 45);
    set_skill("cuff", 45);
	set_skill("kurong_changong", 45);
    set_skill("tiannan_step", 45);
    set_skill("jinyu_quan", 45);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("cuff", "jinyu_quan");
	map_skill("parry", "jinyu_quan");

	set_inquiry("����", ask_me, "�����ζ����");

	carry_object("cloth")->wear();
	add_money(200);
};

static char * ask_me(CNpc * me, CChar * who)
{
	if (who->query_skill("kurong_changong",1) < 30)
		return "������ҵ���";
	
	who->set_temp("fight_ok", 1);
	me->say("�ã���Ȼ������д裬�ǾͿ���ı�������ˡ�", who);
	me->AddMenuItem("��ʼ����", "$0bishi $1", who);
	me->AddMenuItem("��������", "", who);
	me->SendMenu(who);
	return 0;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "bishi") == 0 && me->query_temp("fight_ok"))
	{
		Do_BiShi(this, me, "����ζ�ı��Ի�");
		return 1;
	}

	return CNpc::handle_action(comm, me, arg);
}

//���Խ���
virtual void is_defeated(CChar * winner, CChar * failer)
{
	if(failer == this)
	{
		if(! winner->query_temp("fight_ok")) return;

		winner->delete_temp("fight_ok");

		say("������ʤ����������Ǵ���μҵĺõ��� ! ��ϲ���� !");
		say("����书���Խ�һ�������� !");
		
		winner->set_temp("have_fight1", 1);
		return;
	}

	say("�����㻹�ö����ϰ�������ڴ���μ��������г���ͷ�� !");
}

NPC_END;
