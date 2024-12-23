//jiading.h
//Lanwood 2000-01-05

NPC_BEGIN(CNdali_jiading);

virtual void create()
{
	set_name("�Ҷ�", "jia ding");
	set("title", "������������");
	set("icon", young_man3);

	set("long", "���Ǵ�������������ļҶ���");
	set("gender", "����");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_hp", 900);
	set("mp", 200);
	set("max_mp", 200);
	set("mp_factor", 10);
	set("combat_exp", 10000);
	set("score", 2000);
	set("env/wimpy", 5);

    set_skill("force", 25);
    set_skill("dodge", 25);
    set_skill("parry", 25);
    set_skill("sword", 25);
    set_skill("cuff", 25);
	set_skill("kurong_changong", 25);
    set_skill("duanjia_sword", 25);
    set_skill("tiannan_step", 25);
    set_skill("jinyu_quan", 25);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("sword", "duanjia_sword");
	map_skill("cuff", "jinyu_quan");
	map_skill("parry", "jinyu_quan");

	set_inquiry("ָ���书", ask_me );
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
	add_money(200);
};

static char * ask_me(CNpc * me, CChar * who)
{
	const char * oldtitle;
	
	if (who->query_skill("kurong_changong",1) < 30)
		return "���뵱�ҳ����������깦��ȥ��";
	
	oldtitle = who->querystr("title");
//	tell_object(me,oldtitle);
	if (strstr(oldtitle, "�������������Ҷ�")
		|| strstr(oldtitle, "�������������Ů"))
	{
		who->set_temp("fight_ok", 1);
		me->say("�ã���Ȼ������д裬�ǾͿ���ı�������ˡ�", who);
		me->AddMenuItem("��ʼ����", "$0bishi $1", who);
		me->AddMenuItem("��������", "", who);
		me->SendMenu(who);
		return 0;
	}
	
	return "ֻ�мҶ����Ů�������ҳ���";		
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "bishi") == 0 && me->query_temp("fight_ok"))
	{
		Do_BiShi(this, me, "�ҳ����Ի�");
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
		say("���Ѿ�����ʤ�δ���ҳ� !");
		
		upgrade_title(winner, "�������������ҳ�");
		return;
	}

	say("�����㻹�ö����ϰ�������ڴ���μ��������г���ͷ�� !");
}

void upgrade_title(CChar * me, char * arg)
{
	me->set("title", arg);
	me->UpdateMe();
}

const char * clear_title(const char * arg)
{
	static char msg[80];

	strncpy(msg, arg, 80);

	replace_string(msg, "�������������Ҷ�", "", 80);
	replace_string(msg, "�������������Ů", "", 80);
	
	return msg;
}

NPC_END;
