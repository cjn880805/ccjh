
NPC_BEGIN(CNfighter_lante);

void create()
{
	set_name("��ʦ����", "lan te");

	set("title", "��ɽ�۽�������");
	set("icon", girl2);
	set("gender", "����" );
	set("age", 70);
	set("per",40);

	set("chname", "��ɽ�۽�");
	set("channel", "f1");

	set("grant", 80);
	
	set("combat_exp", 150000000);
	set("attitude", "friendly");
	
	set("biwu/name", "��ɽ�۽����");
	set("biwu/register/0", "��ȱ");
	set("biwu/turn0/0", "0");

	set("wait_time",3);
	set("no_talk",1);

	set("file_name", querystr("base_name"));

	Load();

	reset();
};

int Save()
{
	char msg[255];
	return SaveToLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);
}

int Load()
{
	char msg[255];
	return LoadFromLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);	
}

void reset()
{
	char msg[255];
	if(!query("��ɽ�۽�/count"))
	{
		for(int i=0;i<16;i++)
		{
			set(snprintf(msg, 255, "��ɽ�۽�/%d/����",i+1),"��ȱ");
			set(snprintf(msg, 255, "��ɽ�۽�/%d/Ӣ��",i+1),"��ȱ");
			set(snprintf(msg, 255, "��ɽ�۽�/%d/id",i+1),"��ȱ");
		}
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];

	int state = query("state");

	if(state == 0)		//�����׶�
	{
		if(! strlen(ask))
		{
			AddMenuItem("�鿴�������", "1", me);
			AddMenuItem("ѯ�ʱ�������", "tiaojian", me);

			if(! has_register(me))
				AddMenuItem("��Ҫ����", "register", me);

			if(me->query("grant") > 80)
			{
				AddMenuItem("��ʼ��ǩ", "chouqian", me);				
			}

		}
		else if(strcmp(ask, "1") == 0)
		{
			tell_object(me, "\n$HIR--------------------------------��ɽ�۽�Ӣ����Χ��--------------------------------");
			char msg1[255],msg2[255],msg3[255];
			char tbuf[3][255];
#define _nSPLIT 20
			for(int i=0;i<16;i++)
			{
				snprintf(msg1, 255, "��ɽ�۽�/%d/����",i+1);
				snprintf(msg2, 255, "��ɽ�۽�/%d/Ӣ��",i+1);
				snprintf(msg3, 255, "��ɽ�۽�/%d/id",i+1);
				memset(&tbuf[0][0], ' ', 3*255);
				char len = _nSPLIT - strlen(querystr(msg1));
				strcpy(&tbuf[0][len], querystr(msg1));
				len = _nSPLIT - strlen(querystr(msg2));
				strcpy(&tbuf[1][len], querystr(msg2));
				len = _nSPLIT - strlen(querystr(msg3));
				strcpy(&tbuf[2][len], querystr(msg3));
				
				tell_object(me, snprintf(msg, 255, "$HIR%s%s%s",tbuf[0],tbuf[1],tbuf[2]));
			}
			tell_object(me, "$HIR----------------------------------------------------------------------------------\n");
			return 1;
		}		
		else if(strcmp(ask, "chouqian") == 0 && wizardp(me))
		{
			chouqian();			
			set("state", 1);	//��ǩ����
			delete_temp("��ս");
			delete_temp("defy");
			Save();
			command("wiz 0 \n$HIRʮ��ĥһ����ҹҹ�����졣��̤����֮·,����������𡣡���ɽ�۽�����ʽ������\n\n");	
			start();
			return 1;
		}
		else if(strcmp(ask, "tiaojian") == 0)
		{
			say("��ɽ�۽��������¸���Ӣ��֮��ᣬֻҪ���ǽ������ˣ�����Ϊ��Ӣ�ۺú��������ʸ����μӡ�", me);
		}
		else if(strcmp(ask, "register") == 0)
			return register_me(me);		//��Ҫ����
	}
	else
	{
		if(! strlen(ask))
		{
			AddMenuItem("�鿴�������", "2", me);
		}
		else if(strcmp(ask, "2") == 0)
		{
			tell_object(me, "\n$HIR--------------------------------��ɽ�۽�Ӣ�۷����--------------------------------");
			char msg10[255],msg20[255],msg30[255];
			char tbuf1[3][255];
			for(int i=0;i<4;i++)
			{
				for(int j=1;j<5;j++)
				{
					if(i==3)
						snprintf(msg, 255,"��ɽ�۽�/��1��/D%d",j);
					else if(i==2)
						snprintf(msg, 255,"��ɽ�۽�/��1��/C%d",j);
					else if(i==1)
						snprintf(msg, 255,"��ɽ�۽�/��1��/B%d",j);
					else if(!i)
						snprintf(msg, 255,"��ɽ�۽�/��1��/A%d",j);

					snprintf(msg10, 255, "��ɽ�۽�/%s/����",querystr(msg));
					snprintf(msg20, 255, "��ɽ�۽�/%s/Ӣ��",querystr(msg));
					snprintf(msg30, 255, "��ɽ�۽�/%s/id",querystr(msg));
					memset(&tbuf1[0][0], ' ', 3*255);
					char len1 = 15 - strlen(querystr(msg10));
					strcpy(&tbuf1[0][len1], querystr(msg10));
					len1 = 15 - strlen(querystr(msg20));
					strcpy(&tbuf1[1][len1], querystr(msg20));
					len1 = 15 - strlen(querystr(msg30));
					strcpy(&tbuf1[2][len1], querystr(msg30));
					
					tell_object(me, snprintf(msg, 255, "$HIR%s��%s%s%s",msg,tbuf1[0],tbuf1[1],tbuf1[2]));
				}
			}
			tell_object(me, "$HIR----------------------------------------------------------------------------------\n");
			return 1;
		}
	}
	SendMenu(me);
	return 1;
}

//��������
int register_me(CChar * me)
{
	if(me->query_temp("��ɽ�۽�/����"))
	{
		if(has_register(me))
		{			
			say("���ѵǼǣ������ĵȴ������Ὺʼ��������Ҫ���������ǣ����ͬ�ſ�����ʱ����ս����۽��ʸ����������߻�ս�ܣ�������������ȡ�����֮��", me);
		}
		else if(query(me->querystr("family/family_name")))
		{
			say("���������˱�������������ȡ����֮��", me);
			AddMenuItem("������ս", "$0tiaozhan $1", me);
			AddMenuItem("�Ǿ�����", "", me);
			SendMenu(me);
			return 1;
		}
		else if(query("��ɽ�۽�/count")>=16)
		{
			say("��ɽ�۽�ʮ�����������������ɻ��ǵ���һ�ΰɣ�", me);
		}
		else
		{
			char msg[255];
			add("��ɽ�۽�/count",1);
			set(snprintf(msg, 255, "��ɽ�۽�/%d/����",query("��ɽ�۽�/count")),me->querystr("family/family_name"));
			set(snprintf(msg, 255, "��ɽ�۽�/%d/Ӣ��",query("��ɽ�۽�/count")),me->name(1));
			set(snprintf(msg, 255, "��ɽ�۽�/%d/id",query("��ɽ�۽�/count")),me->id(1));
			set(snprintf(msg, 255, "%s",me->querystr("family/family_name")),query("��ɽ�۽�/count"));
			register_join(me, querymap("biwu/register"));
			say("�����ˣ����͵Ⱥ�����Ὺʼ�ɡ�������Ҫ���������ǣ����ͬ�ſ�����ʱ����ս����۽��ʸ����������߻�ս�ܣ�������������ȡ�����֮��", me);			
		}
	}
	else
	{
		say("��������ʤ�˶�����������ʸ�μӻ�ɽ�۽���", me);
		me->set_temp("��ɽ�۽�/�Ǽ�",1);
	}
	SendMenu(me);
	return 1;
}

//���������ǩ
int chouqian()
{		
	char msg[255];
	int i,j;
	i=query("��ɽ�۽�/count");
	//��ʼ����������
	for(j=0;j<i;j++)
	{
		set(snprintf(msg, 255,"%d",j+1),1);
	}
	//��ʼ����
	for(j=0;j<i;j++)
	{
		snprintf(msg, 255,"%d",random(i)+1);
		if(query(msg))
		{
			del(msg);
			char msg1[40];
			if(j>11)
				snprintf(msg1, 255,"��ɽ�۽�/��1��/D%d",j-11);
			else if(j>7)
				snprintf(msg1, 255,"��ɽ�۽�/��1��/C%d",j-7);
			else if(j>3)
				snprintf(msg1, 255,"��ɽ�۽�/��1��/B%d",j-3);
			else
				snprintf(msg1, 255,"��ɽ�۽�/��1��/A%d",j+1);
			set(msg1,msg);

		}
		else
			j--;
	}
	Save();
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(!strcmp(comm, "kill") || !strcmp(comm, "fight")	|| !strcmp(comm, "cast") )
	{
		message_vision("$n��$N������ü.", me, this);
		return 1;
	}

	if(!strcmp(comm, "tiaozhan") )//��սͬ�ţ�ȡ����֮
	{
		if(!query_temp(me->querystr("family/family_name")))
		{
			set_temp(me->querystr("family/family_name"),1);
			defy(me);
		}
		else
		{
			message_vision("$n��˵���������������ڽ�����ս��$N���ǵ�һ��ɣ���", me, this);
		}
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}

//�Ǽ�
void register_join(CChar * me, CMapping * team)
{
	if(team)
	{
		team->set(me->id(1), me->name(1));
		Save();
	}
}

//����ע��
int has_register(CChar * me)
{
	CMapping * team = querymap("biwu/register");
	if(! team) return 0;
	return team->querystr(me->querystr("id"))[0];
}

//��ս�Ѿ�������ͬ��
void defy(CChar * me)
{
	char msg[255];
	CUser * player;
	snprintf(msg, 255,"��ɽ�۽�/%d/id",query(me->querystr("family/family_name")));
	player=find_online(querystr(msg));
	if(!player)
	{
		//����ս�߲�����ֱ���滻
		register_join(me, querymap("biwu/register"));
		del(snprintf(msg, 255, "biwu/register/%s",querystr(msg)));
		set(snprintf(msg, 255, "��ɽ�۽�/%d/Ӣ��",query(me->querystr("family/family_name"))),me->name(1));
		set(snprintf(msg, 255, "��ɽ�۽�/%d/id",query(me->querystr("family/family_name"))),me->id(1));
		message_vision("\n$HIR���ڶ��ֲ����ߣ�$N����˴���μӡ���ɽ�۽������ʸ�\n", me);
		delete_temp(me->querystr("family/family_name"));
		Save();
	}
	else
	{
		//�жϱ���ս���Ƿ�Ļ�������
		if(DIFFERSTR(player->querystr("family/family_name"),querystr(snprintf(msg, 255,"��ɽ�۽�/%d/����",query(me->querystr("family/family_name"))))))
		{
			//�绻������������ս��ֱ���滻
			set(snprintf(msg, 255, "��ɽ�۽�/%d/Ӣ��",query(me->querystr("family/family_name"))),me->name(1));
			set(snprintf(msg, 255, "��ɽ�۽�/%d/id",query(me->querystr("family/family_name"))),me->id(1));
			message_vision("\n$HIR����$n�Ѿ��Ļ����ɣ������ٴ�����ɳ�ս��$N����˲μӡ���ɽ�۽������ʸ�\n", me,player);
			register_join(me, querymap("biwu/register"));
			del(snprintf(msg, 255, "biwu/register/%s",player->id(1)));
			delete_temp(me->querystr("family/family_name"));
			Save();
		}
		else
		{
			//3���Ӻ�ս
			snprintf(msg, 255, "\n\n$HIG����ɽ�۽���%s��ʽ��ս%s�Ļ�ɽ�۽��ʸ���%s����׼������ս����3���Ӻ�ʼ��", me->name(1), player->name(1), player->name(1));
			tell_object(me, msg);
			tell_object(player, msg);
			do_defy(me,player,query("wait_time"));
		}
	}

}

int do_defy(CChar * me, CChar * who,int wait_time)
{
	char msg[255];

	command(snprintf(msg, 255, "wiz 0 �롾%s��%s(%s) VS %s(%s)����׼��������ɽ�۽�����ս������%ld���Ӻ���С�\n", me->querystr("family/family_name"),me->name(1),me->id(1),who->name(1),who->id(1), wait_time));

	if(me && who)
	{		
		snprintf(msg, 255, "\n$HIG����ɽ�۽���%s��%s��׼���ã�\n", me->name(1), who->name(1) );

		tell_object(me, msg);
		tell_object(who, msg);	
	}
	else
	{
		if(me)
		{
			set(snprintf(msg, 255, "��ɽ�۽�/%d/Ӣ��",query(me->querystr("family/family_name"))),me->name(1));
			set(snprintf(msg, 255, "��ɽ�۽�/%d/id",query(me->querystr("family/family_name"))),me->id(1));
			command(snprintf(msg, 255,"wiz 0 ���ڶ��ֲ����ߣ�%s%s(%s)����˴���μӡ���ɽ�۽������ʸ�\n",me->querystr("family/family_name"),me->name(1),me->id(1)));	
			register_join(me, querymap("biwu/register"));
			del(snprintf(msg, 255, "biwu/register/%s",who->id(1)));
			delete_temp(me->querystr("family/family_name"));
			Save();
		}
		else if(who)
		{
			command(snprintf(msg, 255,"wiz 0 ���ڶ�����;��Ȩ��%s%s(%s)�������ֲμӡ���ɽ�۽������ʸ�\n",who->querystr("family/family_name"),who->name(1),who->id(1)));	
			delete_temp(who->querystr("family/family_name"));
		}
		return 1;
	}
	add_temp("��ս",1);
	set_temp(snprintf(msg, 255,"defy/%d/A",query_temp("��ս")),me->id(1));
	set_temp(snprintf(msg, 255,"defy/%d/B",query_temp("��ս")),who->id(1));
	do_defy1(this,wait_time,query_temp("��ս"));
	return 1;
}

static void do_defy1(CContainer * ob, LONG wait_time, LONG team)
{
	CNfighter_lante * npc = (CNfighter_lante *)ob;
	
	if(wait_time <= 0)
	{
		npc->do_summon(npc, team);
		npc->do_biwu(team);
		return;
	}
	
	char msg[255];
	
	const char * key1 = npc->querystr_temp(snprintf(msg, 255,"defy/%d/A",team));
	const char * key2 = npc->querystr_temp(snprintf(msg, 255,"defy/%d/B",team));
	
	CUser * me = find_online(key1);
	CUser * who = find_online(key2);

	snprintf(msg, 255, "\n$HIR����ɽ�۽����������ս������%ld���ӣ�ʱ�䵽�Զ�����ս����������׼����\n", wait_time);

	if(me)
		tell_object(me, msg);
	if(who)
		tell_object(who, msg);

	npc->call_out(do_defy1, 60, wait_time-1,team);
}

//ץ��
int do_summon(CChar * npc, int team)
{
	char msg[255];
	
	const char * key1 = npc->querystr_temp(snprintf(msg, 255,"defy/%d/A",team));
	const char * key2 = npc->querystr_temp(snprintf(msg, 255,"defy/%d/B",team));
	
	CUser * me = find_online(key1);
	CUser * who = find_online(key2);
	
	CContainer * r = npc->environment();

	if(me) 
	{
		me->move(r);
		if(me->query("mp")>me->query("max_mp")*4)
			me->set("mp",me->query("max_mp")*4);
		message_vision("$N���������", me);
	}
	
	if(who) 
	{
		who->move(r);
		if(who->query("mp")>who->query("max_mp")*4)
			who->set("mp",who->query("max_mp")*4);
		message_vision("$N���������", who);
	}
	
	return 1;
}

//��ս����ʼ
int do_biwu(int team)
{
	char msg[255];

	const char * key1 = querystr_temp(snprintf(msg, 255,"defy/%d/A",team));
	const char * key2 = querystr_temp(snprintf(msg, 255,"defy/%d/B",team));
	
	CUser * me = find_online(key1);
	CUser * who = find_online(key2);

	if(me && who)	//���˾����ߣ���ʼ����
	{	
		me->set_temp("biwu/npc", object_id());	//����NPCע��
		me->set_temp("biwu/team", 1);		
		who->set_temp("biwu/npc", object_id());	//����NPCע��
		who->set_temp("biwu/team", 2);

		full_me(me);
		full_me(who);

		CContainer * env = Do_BiShi(me, who, "��ɽ�۽���ս��", 0);
		env->set("room_locked", FIGHT_LOCKED);	//ս������.

		//����ս���������
		set_biwu(env);

		CContainer * oldenv = find_object(query_temp("is_boardcast"));
		if(! oldenv) do_snoop(env);
		
		return 1;
	}

	if(me) 
	{
		set(snprintf(msg, 255, "��ɽ�۽�/%d/Ӣ��",query(me->querystr("family/family_name"))),me->name(1));
		set(snprintf(msg, 255, "��ɽ�۽�/%d/id",query(me->querystr("family/family_name"))),me->id(1));
		command(snprintf(msg, 255,"wiz 0 ���ڶ��ֲ����ߣ�%s%s(%s)����˴���μӡ���ɽ�۽������ʸ�\n",me->querystr("family/family_name"),me->name(1),me->id(1)));	
		register_join(me, querymap("biwu/register"));
		del(snprintf(msg, 255, "biwu/register/%s",key2));
		delete_temp(me->querystr("family/family_name"));
		Save();
	}
	else if(who) 
	{
		command(snprintf(msg, 255,"wiz 0 ���ڶ�����;��Ȩ��%s%s(%s)�������ֲμӡ���ɽ�۽������ʸ�\n",who->querystr("family/family_name"),who->name(1),who->id(1)));	
		delete_temp(who->querystr("family/family_name"));
	}
	else
		return notify_fail("�������ߡ�");

	return 1;
}

//����ǰ����HP��MP
void full_me(CChar * me)
{
	int hp = me->query("hp");
	int max_hp = me->query("max_hp");

	if(hp < max_hp)
	{
		me->set("hp", max_hp);
		me->set("eff_hp", max_hp);
	}

	hp = me->query("mp");
	max_hp = me->query("max_mp");

	if(hp < max_hp * 2)
	{
		me->set("mp", max_hp * 2);
	}
	
	message_vision("$YELֻ��$N������է�֣�ɢ�����������", me);
	me->FlushMyInfo();	
}

//��ʤ�߻�á���ɽ�۽������ʸ�
void register_winner(CChar * me, int team,CChar * who)
{
	char msg[255];
	if(team==1)
	{
		//��ս�߻�ʤ
		set(snprintf(msg, 255, "��ɽ�۽�/%d/Ӣ��",query(me->querystr("family/family_name"))),me->name(1));
		set(snprintf(msg, 255, "��ɽ�۽�/%d/id",query(me->querystr("family/family_name"))),me->id(1));
		command(snprintf(msg, 255,"wiz 0 %s%s(%s) ��ս�ɹ�������˲μӡ���ɽ�۽������ʸ�\n",me->querystr("family/family_name"),me->name(1),me->id(1)));	
		register_join(me, querymap("biwu/register"));
		del(snprintf(msg, 255, "biwu/register/%s",who->id(1)));
		Save();
	}
	else if(team==2)
	{
		//����ս�߻�ʤ
		command(snprintf(msg, 255,"wiz 0 %s%s(%s) Ӧս�ɹ����������ֲμӡ���ɽ�۽������ʸ�\n",me->querystr("family/family_name"),me->name(1),me->id(1)));	
	}
	delete_temp(me->querystr("family/family_name"));
	Save();
}

//����ɽ�۽�����ʤ����
void register1_winner(CChar * winner,CChar * failer)
{
	char msg[255];
	switch(query("state"))
	{
	case 1://��һ����ѭ��������Ҫ���ݻ�����ȷ��С������ʸ�
		if(failer)
			command(snprintf(msg, 255,"wiz 0 ��ϲ��%s��%s(%s) սʤ ��%s��%s(%s)����á���ɽ�۽�����һ�ֱ�����%d����ʤ����\n",winner->querystr("family/family_name"),winner->name(1),winner->id(1),failer->querystr("family/family_name"),failer->name(1),failer->id(1),query("��ɽ�۽�/��һ��/����")));	
		add(snprintf(msg, 255,"��ɽ�۽�/�ɼ���/%s",winner->id(1)),1);
		add(snprintf(msg, 255,"��ɽ�۽�/��һ��/��%dȦ/��������", query("��ɽ�۽�/��һ��/����")),1);
		if(query(msg)==8)//�ĸ�С�鵱ǰһȦ����ȫ��������������һȦѭ����
		{
			del(msg);
			add("��ɽ�۽�/��һ��/����",1);
			//С��ѭ��������������Ȧ����ѭ����������������һ����̭��
			if(query("��ɽ�۽�/��һ��/����")>=3)
			{
				command(snprintf(msg, 255,"wiz 0 ��һ�ֱ������ڽ�����������ʼ�ڶ��ֵı�����"));	
				add("state",1);
				delete_temp("�۽�");
				delete_temp("lunjian");
				del("��ɽ�۽�/��һ��");//�����һ��ѭ�����ر����õı�־
				re_fenzu();//ѭ��������������ѡ�ְ��ɼ����±��
			}
			start();
		}
		break;
	case 2://�ڶ�������̭����ʤ�߽���8ǿ����ű�ΪF�飬���߽���8-16������ű�ΪP��
		command(snprintf(msg, 255,"wiz 0 ��ϲ%s%s(%s) սʤ %s%s(%s)����á���ɽ�۽�����%d�ֱ�����ʤ��,˳��������һ�֡�\n",winner->querystr("family/family_name"),winner->name(1),winner->id(1),failer->querystr("family/family_name"),failer->name(1),failer->id(1),query("state")));	
		break;
	}
	Save();
}

int re_fenzu()
{
	char msg[255],msg1[255],msg2[255],first[255],sec[255];
	int i,j;
	int one,two;
	for(j=1;j<5;j++)
	{
		one=0;
		two=0;
		snprintf(sec, 255,"%s","��ȱ");
		snprintf(first, 255,"%s","��ȱ");
		for(i=1;i<5;i++)
		{
			switch(j)
			{
			case 1:
				snprintf(msg, 255,"��ɽ�۽�/��1��/A%d",i);
				break;
			case 2:
				snprintf(msg, 255,"��ɽ�۽�/��1��/B%d",i);
				break;
			case 3:
				snprintf(msg, 255,"��ɽ�۽�/��1��/C%d",i);
				break;
			case 4:
				snprintf(msg, 255,"��ɽ�۽�/��1��/D%d",i);
				break;
			}
			snprintf(msg1, 255, "��ɽ�۽�/%s/id",querystr(msg));
			snprintf(msg2, 255,"��ɽ�۽�/�ɼ���/%s",querystr(msg1));
			if(query(msg2)>one)
			{
				two=one;
				one=query(msg2);
				snprintf(sec, 255,"%s",first);
				snprintf(first, 255,"%s",querystr(msg));
			}
			else if(query(msg2)>two)
			{
				two=query(msg2);
				snprintf(sec, 255,"%s",querystr(msg));
			}
		}
		if(DIFFERSTR(first,"��ȱ"))
		{
			add_temp("��ɽ�۽�/��2��/count",1);
			set(snprintf(msg, 255,"��ɽ�۽�/��2��/E%d",query_temp("��ɽ�۽�/��2��/count")),first);
			querystr(snprintf(msg, 255, "��ɽ�۽�/%s/id",first));
			command(snprintf(msg, 255,"wiz 0 ��ϲ��%s��%s(%s)��С���һ������˳������ڶ��ֵ���̭����",
				querystr(snprintf(msg, 255, "��ɽ�۽�/%s/����",first)),querystr(snprintf(msg, 255, "��ɽ�۽�/%s/Ӣ��",first)),
				querystr(snprintf(msg, 255, "��ɽ�۽�/%s/id",first))));	
		}
		if(DIFFERSTR(sec,"��ȱ"))
		{
			add_temp("��ɽ�۽�/��2��/count",1);
			set(snprintf(msg, 255,"��ɽ�۽�/��2��/E%d",query_temp("��ɽ�۽�/��2��/count")),sec);
			command(snprintf(msg, 255,"wiz 0 ��ϲ��%s��%s(%s)��С��ڶ�������˳������ڶ��ֵ���̭����",
				querystr(snprintf(msg, 255, "��ɽ�۽�/%s/����",sec)),querystr(snprintf(msg, 255, "��ɽ�۽�/%s/Ӣ��",sec)),
				querystr(snprintf(msg, 255, "��ɽ�۽�/%s/id",sec))));	
		}
	}

	return 1;
}

//������������
void is_defeated(CChar * winner, CChar * failer)
{
	if(winner == this || failer == this) return;

	int team = winner->query_temp("biwu/team");

	//�����Ǳ����ʤ�ߵĴ���
	if(!query("state"))
		register_winner(winner,team,failer);
	else
		register1_winner(winner,failer);

	winner->delete_temp("biwu");
	failer->delete_temp("biwu");

	winner->revive(1);
	failer->revive(1);

	full_me(winner);
	full_me(failer);

	CContainer * env = winner->environment();
	remove_biwu(env);

	if(env->object_id() == query_temp("is_boardcast"))
		transfer_info();
}

//����ɽ�۽�������
int start()
{
	//��һ�֣�С��ѭ����
	if(query("state")==1)
	{
		int i;
		char one[255],two[255],thr[255],fou[255];
		for(i=0;i<4;i++)
		{
			switch(i)
			{
			case 0:
				snprintf(one, 255, "��ɽ�۽�/%s/id",querystr("��ɽ�۽�/��1��/A1"));
				snprintf(two, 255, "��ɽ�۽�/%s/id",querystr("��ɽ�۽�/��1��/A2"));
				snprintf(thr, 255, "��ɽ�۽�/%s/id",querystr("��ɽ�۽�/��1��/A3"));
				snprintf(fou, 255, "��ɽ�۽�/%s/id",querystr("��ɽ�۽�/��1��/A4"));
				break;
			case 1:
				snprintf(one, 255, "��ɽ�۽�/%s/id",querystr("��ɽ�۽�/��1��/B1"));
				snprintf(two, 255, "��ɽ�۽�/%s/id",querystr("��ɽ�۽�/��1��/B2"));
				snprintf(thr, 255, "��ɽ�۽�/%s/id",querystr("��ɽ�۽�/��1��/B3"));
				snprintf(fou, 255, "��ɽ�۽�/%s/id",querystr("��ɽ�۽�/��1��/B4"));
				break;
			case 2:
				snprintf(one, 255, "��ɽ�۽�/%s/id",querystr("��ɽ�۽�/��1��/C1"));
				snprintf(two, 255, "��ɽ�۽�/%s/id",querystr("��ɽ�۽�/��1��/C2"));
				snprintf(thr, 255, "��ɽ�۽�/%s/id",querystr("��ɽ�۽�/��1��/C3"));
				snprintf(fou, 255, "��ɽ�۽�/%s/id",querystr("��ɽ�۽�/��1��/C4"));
				break;
			case 3:
				snprintf(one, 255, "��ɽ�۽�/%s/id",querystr("��ɽ�۽�/��1��/D1"));
				snprintf(two, 255, "��ɽ�۽�/%s/id",querystr("��ɽ�۽�/��1��/D2"));
				snprintf(thr, 255, "��ɽ�۽�/%s/id",querystr("��ɽ�۽�/��1��/D3"));
				snprintf(fou, 255, "��ɽ�۽�/%s/id",querystr("��ɽ�۽�/��1��/D4"));
				break;
			}
			
			switch(query("��ɽ�۽�/��һ��/����"))
			{
			case 0://��һ����1-2��3-4
				check_id(one,two);
				check_id(thr,fou);
				break;
			case 1://�ڶ�����1-3��2-4
				check_id(one,thr);
				check_id(two,fou);
				break;
			case 2://��������1-4��2-3
				check_id(one,fou);
				check_id(two,thr);
				break;
			}
		}
	}
	//�ڶ��֣�9-16ǿ��
	//�ڶ�һ�֣�13-16ǿ��
	//�ڶ����֣�9-12ǿ��
	//�����֣�1-8ǿ��
	//����һ�֣�5-8ǿ��
	//�������֣�1-4ǿ��
	return 1;
}

//���ѡ���Ƿ����ߡ��Ƿ��Ѿ��������ɣ�����������
int check_id(char player1_id[255], char player2_id[255])
{
	char msg[255];
	CUser * player1 = find_online(querystr(player1_id));
	CUser * player2 = find_online(querystr(player2_id));

	//command(snprintf(msg, 255, "wiz 0 player1�� %s player2��%s��", querystr(player1_id),querystr(player2_id)));
	
	if(player1 && player2)	//���˾�����
	{	
		//���ѡ���Ƿ��Ѿ���������
		snprintf(msg, 255,"��ɽ�۽�/%d/����",query(player1->querystr("family/family_name")));
		if(EQUALSTR(querystr(msg),player1->querystr("family/family_name")))
		{
			//player1 ok
			set_temp("player1",1);
		}
		snprintf(msg, 255,"��ɽ�۽�/%d/����",query(player2->querystr("family/family_name")));
		if(EQUALSTR(querystr(msg),player2->querystr("family/family_name")))
		{
			//player2 ok
			set_temp("player2",1);
		}
		if(query_temp("player1") && query_temp("player2")) //��ʼ����
		{
			delete_temp("player1");
			delete_temp("player2");
			do_lunjian(player1,player2,query("wait_time"));
		}
		else if(query_temp("player1"))
		{
			//player2 �Ѿ����������ɣ�ʧȥ�˱����ʸ�player1 ��ʤ
			command(snprintf(msg, 255, "wiz 0 ����%s%s(%s)�Ѿ����������ɣ������ٴ���ԭ�����ɲ�����%s%s(%s)�Զ�����ˡ���ɽ�۽�������������ʤ����\n", player2->querystr("family/family_name"),player2->name(1),player2->id(1),player1->querystr("family/family_name"),player1->name(1),player1->id(1)));
			register1_winner(player1,player2);
		}
		else if(query_temp("player2"))
		{
			//player1 �Ѿ����������ɣ�ʧȥ�˱����ʸ�player2 ��ʤ
			command(snprintf(msg, 255, "wiz 0 ����%s%s(%s)�Ѿ����������ɣ������ٴ���ԭ�����ɲ�����%s%s(%s)�Զ�����ˡ���ɽ�۽�������������ʤ����\n", 
				player1->querystr("family/family_name"),player1->name(1),player1->id(1),
				player2->querystr("family/family_name"),player2->name(1),player2->id(1)));
			register1_winner(player2,player1);
		}
		else
		{
			//player1��2 ���Ѿ����������ɣ���ʧȥ�˱����ʸ�
			command(snprintf(msg, 255, "wiz 0 ���˶��������ɣ�"));
		}
		
	}
	else if(player1)
	{
		//player2�����ߣ�ʧȥ�˱����ʸ�player1 ��ʤ
		command(snprintf(msg, 255, "wiz 0 ���ڶ��ֲ����ߣ���%s��%s(%s)�Զ�����ˡ���ɽ�۽�������������ʤ����\n", 
			player1->querystr("family/family_name"),player1->name(1),player1->id(1)));
		register1_winner(player1,player2);
	}
	else if(player2)
	{
		//player1 �����ߣ�ʧȥ�˱����ʸ�player2 ��ʤ
		command(snprintf(msg, 255, "wiz 0 ���ڶ��ֲ����ߣ���%s��%s(%s)�Զ�����ˡ���ɽ�۽�������������ʤ����\n",
			player2->querystr("family/family_name"),player2->name(1),player2->id(1)));
		register1_winner(player2,player1);
	}
	else
	{
		//player1��2 ���Ѿ����������ɣ���ʧȥ�˱����ʸ�
		//command(snprintf(msg, 255, "wiz 0 ���˶����ڣ�\n"));
		add(snprintf(msg, 255,"��ɽ�۽�/��һ��/��%dȦ/��������", query("��ɽ�۽�/��һ��/����")),1);
	}
	return 1;
}

int do_lunjian(CChar * player1, CChar * player2,int wait_time)
{
	char msg[255];
	command(snprintf(msg, 255, "wiz 0 �롾%s��%s(%s) VS ��%s��%s(%s)����׼��������ɽ�۽�����һ��ѭ������%d����������%ld���Ӻ���С�\n", player1->querystr("family/family_name"),player1->name(1),player1->id(1), player2->querystr("family/family_name"),player2->name(1),player2->id(1), query("��ɽ�۽�/��һ��/����"),wait_time));
	
	snprintf(msg, 255, "\n$HIG����ɽ�۽���%s��%s��׼���ã�\n", player1->name(1), player2->name(1) );
	
	tell_object(player1, msg);
	tell_object(player2, msg);

	add_temp("�۽�",1);
	set_temp(snprintf(msg, 255,"lunjian/%d/A",query_temp("�۽�")),player1->id(1));
	set_temp(snprintf(msg, 255,"lunjian/%d/B",query_temp("�۽�")),player2->id(1));
	
	do_lunjian1(this,wait_time,query_temp("�۽�"));
	
	return 1;
}

static void do_lunjian1(CContainer * ob, LONG wait_time, LONG team)
{
	CNfighter_lante * npc = (CNfighter_lante *)ob;
	
	if(wait_time <= 0)
	{
		npc->do_summon1(npc, team);
		npc->do_biwu1(team);
		return;
	}
	
	char msg[255];
	
	const char * key1 = npc->querystr_temp(snprintf(msg, 255,"lunjian/%d/A",team));
	const char * key2 = npc->querystr_temp(snprintf(msg, 255,"lunjian/%d/B",team));
	
	CUser * player1 = find_online(key1);
	CUser * player2 = find_online(key2);

	snprintf(msg, 255, "\n$HIR����ɽ�۽���������������%ld���ӣ�ʱ�䵽�Զ�����ս����������׼����\n", wait_time);

	if(player1)
		tell_object(player1, msg);
	if(player2)
		tell_object(player2, msg);

	npc->call_out(do_lunjian1, 60, wait_time-1,team);
}

//ץ�˽�����ʽ����
int do_summon1(CChar * npc, int team)
{
	char msg[255];
	
	const char * key1 = npc->querystr_temp(snprintf(msg, 255,"lunjian/%d/A",team));
	const char * key2 = npc->querystr_temp(snprintf(msg, 255,"lunjian/%d/B",team));
	
	CUser * me = find_online(key1);
	CUser * who = find_online(key2);
	
	CContainer * r = npc->environment();

	if(me) 
	{
		me->move(r);
		if(me->query("mp")>me->query("max_mp")*4)
			me->set("mp",me->query("max_mp")*4);
		message_vision("$N���������", me);
	}
	
	if(who) 
	{
		who->move(r);
		if(who->query("mp")>who->query("max_mp")*4)
			who->set("mp",who->query("max_mp")*4);
		message_vision("$N���������", who);
	}
	
	return 1;
}

//��ɽ�۽���ʽ������ʼ
int do_biwu1(int team)
{
	char msg[255];

	const char * key1 = querystr_temp(snprintf(msg, 255,"lunjian/%d/A",team));
	const char * key2 = querystr_temp(snprintf(msg, 255,"lunjian/%d/B",team));
	
	CUser * me = find_online(key1);
	CUser * who = find_online(key2);

	if(me && who)	//���˾����ߣ���ʼ����
	{	
		me->set_temp("biwu/npc", object_id());	//����NPCע��
		me->set_temp("biwu/team", 1);		
		who->set_temp("biwu/npc", object_id());	//����NPCע��
		who->set_temp("biwu/team", 2);

		full_me(me);
		full_me(who);

		CContainer * env = Do_BiShi(me, who, "��ɽ�۽�����", 0);
		env->set("room_locked", FIGHT_LOCKED);	//ս������.

		//����ս���������
		set_biwu(env);

		CContainer * oldenv = find_object(query_temp("is_boardcast"));
		if(! oldenv) do_snoop(env);
		
		return 1;
	}

	if(me) 
	{
		//who �����ߣ�me ��ʤ
	}
	else if(who) 
	{
		//me �����ߣ�who ��ʤ
	}
	else
		return notify_fail("�������ߡ�");

	return 1;
}

void set_biwu(CContainer * ob)
{
	char msg[40];

	snprintf(msg, 40, snprintf(msg, 40, "%ld", ob->object_id()));

	if( m_biwulist.find(msg) == m_biwulist.end() )
		m_biwulist.append(msg);
}

void remove_biwu(CContainer *ob)
{
	char msg[80];
	m_biwulist.remove(snprintf(msg, 40, "%ld", ob->object_id()));
}

//���ת��
void transfer_info()
{
	while(m_biwulist.count())
	{
		CContainer * env = find_object(atol(m_biwulist[0]));
		if(env)
		{
			do_snoop(env);
			return;
		}
		m_biwulist.remove(m_biwulist[0]);
	}
}

void do_snoop(CContainer * env)
{
	const char * ch = querystr("channel");
	if(! ch[0])	return;
		
	env->set("channel_cast", ch);
	env->set("channel_id", querystr("chname"));
	set_temp("is_boardcast", env->object_id());			
}
protected:
	CVector		m_biwulist;

NPC_END;



