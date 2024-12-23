// pub_baixiaosheng ������
//�ز� 2002��3��5

NPC_BEGIN(CNpub_baixiaosheng);

virtual void create()
{
	set_name("������", "bai xiao sheng");
	set("gender", "����");
	set("age", 45);
	set("icon",triggerman2);
	
	set("combat_exp", 7000);
	set("shen_type", 1);
	
	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
	set("no_talk",1);
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	CContainer * bot;
	if(me->query_temp("gumu/jq_gu"))
	{
		say("���Ѿ�ͨ���˿��飬������ڳ���ɽһ��,���ȥ����ɡ�", me);
	}
	else if(me->query_temp("gumu/jq_dan"))
	{
		if(me->query_temp("gumu/jq_kill"))
		{
			if(me->query_temp("gumu/jq_kill")<5)
			{
				if(me->query_temp("gumu/jq_renwu")==1)
					say(snprintf(msg, 255, "����ɱ��%s(%s)��", me->querystr_temp("gumu/kill_name"),me->querystr_temp("gumu/kill_id")), me);
				else
				{
					me->add_temp("gumu/jq_kill",1);
					me->add_temp("gumu/jq_renwu",-do_jq_kill(me));
				}
			}
			else
			{
				say("���������ҵ���������������������ˡ�",me);
				say("�úúã���ı��ֲ����Ѿ�ͨ���˿��飬���Կ������ȥ��������ڳ���ɽһ����", me);
				bot = load_item("anjinmenkey");
				bot->set("owner",me->querystr("id"));
//				bot->set_name(snprintf(msg, 40, "%s������", me->name(1)));
				bot->move(me);
				me->delete_temp("gumu/jq_dan");
				me->delete_temp("gumu/jq_kill");
				me->delete_temp("gumu/jq_renwu");
				me->set_temp("gumu/jq_gu",1);
			}
		}
		else
		{
			if(! strlen(ask))
			{
				AddMenuItem("ѯ��[�����]��λ��", "wen", me);
			}
			else if(strcmp(ask, "wen") == 0)
			{
				say("����ȥ����ȣ�����Σ�յĺܰ��������Ը��ȥ��", me);
				AddMenuItem("Ը��", "y", me);
				AddMenuItem("���˻����´ΰ�", "n", me);
			}
			else if(strcmp(ask, "y") == 0)
			{
				me->set_temp("gumu/jq_kill",1);
				say("�����Ȱ���ȥɱ�������ˣ����ҿ������ʵ���ɣ�", me);
				me->set_temp("gumu/jq_renwu",do_jq_kill(me));
			}
			else if(strcmp(ask, "n") == 0)
			{
				say("�Ǻǣ��������㻹�ö����ӵ㵨ɫ�ųɰ���", me);
				me->delete_temp("gumu/jq_dan");
			}
		}
	}
	SendMenu(me);
	return 1;
}
int do_jq_kill(CChar * me)
{
	static struct{
		char name[20];
		char id[20];
		int  exp;			
	} lvlmax[5] = {			
		{"׿һ��","zhun yi hang", 60,},
		{"ˮ����", "shui yun yan", 60,},
		{"�����", "li qiou hen", 60,},
		{"������", "du gu qiu", 60,},
		{"����", "ning yue", 60,},
	};

	char msg[255];
	const char * shuiname = "";
	const char * shuiid = "";
	int shuiexp = 0;

	int task = me->query_temp("gumu/jq_kill")-1;
	shuiname=lvlmax[task].name;
	shuiid=lvlmax[task].id;
	shuiexp=lvlmax[task].exp;
	
	me->set_temp("gumu/kill_name",shuiname);
	me->set_temp("gumu/kill_id",shuiid);

	if(!me->query_temp("gumu/jq_renwu"))
		say(snprintf(msg, 255, "������˵����Ȼ����Լ��������ģ���ô���ȥ���Ұ�%s(%s)ɱ�˰ɣ�", shuiname, shuiid), me);
	else
	{
		say("������˵���������ҵ��������������ֿ��Թ���һ���ˡ�", me);
		say(snprintf(msg, 255, "������˵�������Ҷ�������������е㲻���ģ�����ȥ���Ұ�%s(%s)ɱ�˰ɣ�", shuiname, shuiid), me);
	}
	int exp=shuiexp+random(shuiexp);
	exp=exp+(me->query("level")-50)*2/3;
	me->set_temp("gumu/kill_exp", exp);

	return 1;
}
NPC_END;