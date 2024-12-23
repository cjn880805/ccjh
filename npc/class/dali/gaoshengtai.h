//gaoshengtai.h
//Lanwood 2000-01-05

NPC_BEGIN(CNdali_gaoshengtai);

virtual void create()
{
	set_name("����ƽ", "gao shengping");
	set("title",  "�����Ʋ���" );
	set("long", "�������ү������λ���۴�����������ӣ����Ƴ��ף���ò���š�");
	set("gender", "����");
	set("age", 33);
	set("icon", young_man5);

	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 25);
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
	
	set("max_hp", 4500);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 80);
	set("combat_exp", 800000);
	set("score", 150000);

	set_skill("force", 110);
	set_skill("dodge", 110);
	set_skill("parry", 100);
	set_skill("cuff", 110);
	set_skill("strike", 110);
	set_skill("sword", 120);
	set_skill("staff", 120);
	set_skill("kurong_changong", 110);
	set_skill("tiannan_step", 120);
	set_skill("jinyu_quan", 110);
	set_skill("wuluo_zhang", 110);
	set_skill("duanjia_sword", 110);
	set_skill("literate", 60);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("cuff", "jinyu_quan");
	map_skill("strike", "wuluo_zhang");
	map_skill("sword", "duanjia_sword");
	map_skill("staff", "duanjia_sword");
	map_skill("parry", "duanjia_sword");
	prepare_skill("cuff", "jinyu_quan");
	prepare_skill("strike", "wuluo_zhang");

	set_inquiry("ָ���书", ask_me);
	
	carry_object("magcloth")->wear();
	carry_object("marz")->wear();
	carry_object("cleansword")->wield();
	add_money(2000);

	create_family("����μ�",19,"�佫");
};

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];
	char oldtitle[40];
	
	strncpy(oldtitle, me->querystr("title"), 40)[39] = 0;

	if (me->query_skill("kurong_changong",1) < 30 )
	{
		say("��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°ɡ�", me);
		SendMenu(me);
		return;
	}

	if (me->query("repute") < 10000  )
	{
		say("�Ҵ�����������������壬����ذɣ�", me);
		SendMenu(me);
		return;
	}

	if (strstr(oldtitle, "������������")) 
	{
		say("�ܺã���Ȼ���������͵�����Ϊū������ʹ��");
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		me->set("title", oldtitle);
		me->UpdateMe();
	}
	else
	{
		say("���Ǻ��ˣ���˴󵨣���ð�Ҹ������ͣ�");
		SendMenu(me);
		return;
	}
}

static char * ask_me(CNpc * me, CChar * who)
{
	const char * oldtitle;
	
	if (who->query_skill("kurong_changong",1) < 80)
		return "����书�����ǲ���ʤ���佫��нٺ���������깦��ɡ�";
	
	oldtitle = who->querystr("title");
	if (strstr(oldtitle, "��������������ʿ"))
	{
		who->set_temp("fight_ok", 1);
		me->say("�ã���Ȼ������д裬�ǾͿ���ı�������ˡ�", who);
		me->AddMenuItem("��ʼ����", "$0bishi $1", who);
		me->AddMenuItem("��������", "", who);
		me->SendMenu(who);
		return 0;
	}
	
	return "ֻ����ʿ�������佫��";		
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "bishi") == 0 && me->query_temp("fight_ok"))
	{
		Do_BiShi(this, me, "�佫���Ի�");
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
		say("���Ѿ�����ʤ�δ����佫 !");
		
		upgrade_title(winner, "�������������佫");
		return;
	}

	say("�����㻹�ö����ϰ�������ڴ���μ��������г���ͷ�� !");
}

void upgrade_title(CChar * me, char * arg)
{
	me->set("title", arg);
	me->UpdateMe();
}

NPC_END;
