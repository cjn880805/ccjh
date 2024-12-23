NPC_BEGIN(CNwiz_gongpingzi);

void create()
{
	set_name("���񳯷�", "chao feng");

	set("title", "������Ǽ�Ա");
	set("icon", girl2);
	set("gender", "Ů��" );
	set("age", 25);

	set("chname", "�ֳ�ֱ��");
	set("channel", "wldh");

	set("grant", 80);
	
	set("combat_exp", 150);
	set("attitude", "friendly");
	
	set("tiaojian/young", 17);
	set("tiaojian/old", 31);

	set("young/register/0", "��ȱ");
	set("middle/register/0", "��ȱ");
	set("old/register/0", "��ȱ");

	set("young/turn0/0", "0");
	set("middle/turn0/0", "0");
	set("old/turn0/0", "0");
	set("no_kill",1);

	Load();
};

int Save()
{
	return SaveToLocal("data/gongpingzi.o", &_M);
}

int Load()
{
	return LoadFromLocal("data/gongpingzi.o", &_M);	
}

//��������
int register_me(CChar * me)
{
	char msg[255];

	if(me->query("combat_exp") < 5000)
	{
		say("������ˮƽ��һ��Ъ������ɲ���", me);
	}
	else
	{		
		int ret = 0;
		if( (ret = has_register(me) ))
		{
			char str[][7] = {"������", "������", "������"};
			say(snprintf(msg, 255, "���Ѿ�����%s�������ĵȴ������Ὺʼ��", str[ret - 1]), me);
		}
		else
		{
			if(me->query("age") < query("tiaojian/young"))
			{
					//������
				register_join(me, querymap("young/register"));
				say("�����ˣ������飬�Ⱥ�����Ὺʼ��", me);
			}
			else if(me->query("age") < query("tiaojian/old"))
			{
				//������
				register_join(me, querymap("middle/register"));
				say("�����ˣ������飬�Ⱥ�����Ὺʼ��", me);
			}
			else	
			{
				//������
				register_join(me, querymap("old/register"));
				say("�����ˣ������飬�Ⱥ�����Ὺʼ��", me);
			}
		}
	}

	SendMenu(me);
	return 1;
}

//��ǩ���� 
int chouqian(const char * zu)
{		
	char msg[255];
	CMapping * reg = querymap(snprintf(msg, 255, "%s/register", zu));
	CMapping * result = querymap(snprintf(msg, 255, "%s/turn0", zu));

	if(! result)
	{
		CMapping m;
		set(msg, m);
		result = querymap(msg);
	}

	if(! reg || ! result) return 0;

	int count, team = 0, st = 0;
	char str[20];
	CVector v;
	reg->keys(v);

	if(query("state"))	//���ѷ���������¼�������
	{
		team = result->GetCount();
		for(int i=0; i<team; i++)
		{
			CMapping * ptr = result->querymap(snprintf(msg, 255, "%ld", i));
			const char * key = ptr->querystr("A");
			v.remove(key);
			key = ptr->querystr("B");

			if(key[0])
			{
				st = 0;
				v.remove(key);
			}
			else
				st = 1;			
		}

		if(st) team--;
	}	

	while(( count = v.count()))
	{
		const char * key = v[random(count)];

		if(! st)
		{
			result->set(snprintf(str, 20, "%ld/A", team), key);		
			v.remove(key);
		}

		if(count > 1 || st)
		{
			key = v[random(count - 1)];

			result->set(snprintf(str, 20, "%ld/B", team), key);
			v.remove(key);
			st = 0;
		}

		team ++;
	}

	return 1;
}

//�鿴������ʽ
int look_turn(CChar * me, int choice, int team)
{
	if(team < 0 || team > query("state")) return notify_fail("û�н��е����֡�");

	if(choice == 1)
		return show_result(me, "young", team);
	
	else if(choice == 2)
		return show_result(me, "middle", team);
	
	else if(choice == 3)
		return show_result(me, "old", team);

	else if(choice == 4)
		return show_result(me, "temp", team);

	return 0;
}

//��ӡ������
int show_result(CChar * me, const char * zu, int turn)
{
	char msg[255], str[20];
	CMapping * m = querymap(snprintf(msg, 40, "%s/turn%ld", zu, turn));
	CMapping * reg = querymap(snprintf(msg, 40, "%s/register", zu) );
	CMapping * ptr;
	int i;
	
	if(! m || ! reg) return notify_fail("��û�н����");

	tell_object(me, snprintf(msg, 255, "\n��%s�ֶ�����ʽ", chinese_number(turn, str)));
	tell_object(me, "-------------------------------------------------------");

	int count = (reg->GetCount() + 1) / 2;
//	for(i=0; i<turn; i++)
//		count = (count + 1) / 2;
	
	for(i=0; i<count; i++)
	{
		ptr = m->querymap(snprintf(msg, 255, "%ld", i));
		if(! ptr) continue;
		
		const char * key1 = ptr->querystr("A");
		const char * key2 = ptr->querystr("B");
		
		//�ж��Ƿ���ʤ
		CMapping * next = querymap(snprintf(msg, 40, "%s/turn%ld/%ld", zu, turn + 1, i/2));
		int win = 0;

		if(next)
		{
			if( i % 2 == 0 )
			{
				if(	EQUALSTR(next->querystr("A"), key1))
					win = 1;
				if(	EQUALSTR(next->querystr("A"), key2))
					win = 2;
			}

			else
			{
				if( EQUALSTR(next->querystr("B"), key1))
					win = 1;
				if( EQUALSTR(next->querystr("B"), key2))
					win = 2;
			}
		}
			
		tell_object(me, snprintf(msg, 255, "$HIY��%s�飺%s%s(%s)$HIY VS %s%s(%s)", 
				chinese_number(i + 1, str), 
				(win == 1 ? "$HIC" : ""),
				(key1[0] ? reg->querystr(key1) : "��ȱ"), 
				key1,
				(win == 2 ? "$HIC" : ""),
				(key2[0] ? reg->querystr(key2) : "��ȱ"), 
				key2) );
	}

	return 1;
}

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

//���俪ʼ
int do_biwu(int zu, int team)
{
	char msg[255];
	static char str[][10] = {"young", "middle", "old", "temp"};

	int state = query("state") - 1;
	if(state < 0) return 0;
	if(zu < 1 || zu > 4) return notify_fail("biwu <�������> <���>");

	CMapping * ptr = querymap(snprintf(msg, 255, "%s/turn%ld/%ld", str[zu - 1], state, team));
	if(! ptr) return notify_fail("û�и��顣");
	
	const char * key1 = ptr->querystr("A");
	const char * key2 = ptr->querystr("B");

	CUser * fighter1 = find_online(key1);
	CUser * fighter2 = find_online(key2);

	if(fighter1 && fighter2)	//���˾����ߣ���ʼ����
	{	
		fighter1->set_temp("biwu/npc", object_id());	//����NPCע��
		fighter1->set_temp("biwu/team", team);		
		fighter1->set_temp("biwu/zu", zu);		
		fighter2->set_temp("biwu/npc", object_id());	//����NPCע��
		fighter2->set_temp("biwu/team", team);
		fighter2->set_temp("biwu/zu", zu);		

		full_me(fighter1);
		full_me(fighter2);
	//	command(snprintf(msg, 255, "full %ld", fighter1->object_id()));
	//	command(snprintf(msg, 255, "full %ld", fighter2->object_id()));

		CContainer * env = Do_BiShi(fighter1, fighter2, "���ִ��", 0);
		env->set("room_locked", FIGHT_LOCKED);	//ս������.

		const char * ch = querystr("channel");
		if(ch[0])
		{
			env->set("channel_cast", ch);
			env->set("channel_id", querystr("chname"));
		}

		return 1;
	}

	if(fighter1) 
		register_winner(fighter1, team, zu);
	else if(fighter2) 
		register_winner(fighter2, team, zu);
	else
		return notify_fail("�������ߡ�");

	return 1;
}

//ץ��
int do_summon(CChar * me, int zu, int team)
{
	char msg[255];
	static char str[][10] = {"young", "middle", "old", "temp"};

	int state = query("state") - 1;
	if(state < 0) return 0;
	if(zu < 1 || zu > 4) return notify_fail("biwu <�������> <���>");

	CMapping * ptr = querymap(snprintf(msg, 255, "%s/turn%ld/%ld", str[zu - 1], state, team));
	if(! ptr) return notify_fail("û�и��顣");
	
	const char * key1 = ptr->querystr("A");
	const char * key2 = ptr->querystr("B");

	CUser * fighter1 = find_online(key1);
	CUser * fighter2 = find_online(key2);
	
	CContainer * r = me->environment();

	if(fighter1) 
	{
		fighter1->move(r);
		message_vision("$N���������", fighter1);
	}
	
	if(fighter2) 
	{
		fighter2->move(r);
		message_vision("$N���������", fighter2);
	}
	
	return 1;
}


void is_defeated(CChar * winner, CChar * failer)
{
	if(winner == this || failer == this) return;

	int team = winner->query_temp("biwu/team");

	//�����Ǳ����ʤ�ߵĴ���
	register_winner(winner, team, winner->query_temp("biwu/zu"));

	winner->delete_temp("biwu");
	failer->delete_temp("biwu");
}

//��ʤ�߽�����һ������
void register_winner(CChar * who, int team, int zu)
{
	char msg[255], tmp[20];
	int state = query("state");

	//����ʤ�߷�����һ��
	if(zu < 1 || zu > 4 ) return;	

	static char str[][10] = {"young", "middle", "old", "temp"};
			
	if(team % 2 == 0)
		snprintf(msg, 255, "%s/turn%ld/%ld/A", str[zu - 1], state, team/2);
	else
		snprintf(msg, 255, "%s/turn%ld/%ld/B", str[zu - 1], state, team/2);

	set(msg, who->querystr("id"));	

	const char * zuname = querystr(snprintf(msg, 255, "%s/name", str[zu - 1]));
	g_Channel.do_channel(this, NULL, "wiz", snprintf(msg, 255, "��ϲ%s(%s)˳������%s��%s�ֱ�����", 			
			who->name(1), who->id(1), zuname, chinese_number(state, tmp) ));

	Save();
}

int ask_zhanbao(CChar * me)
{
	if(me->query_temp("ask_zhanbao"))
	{
		say("�㶼�Ѿ�Ҫ��һ���ˡ�", me);
		SendMenu(me);
	}
	else
	{
		me->set_temp("ask_zhanbao", 1);
		CContainer * obj = load_item("wiz_zhanbao");
		obj->move(me);
		obj->set("biwu", object_id());

		tell_object(me, "$YEL����һ�ݼ�ʱս��������������ʱ�������¶�ս���ơ�");
	}

	return 1;
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];

	int state = query("state");

	if(state == 0)		//�����׶�
	{
		if(! strlen(ask))
		{
			AddMenuItem("�����鱨�����", "1", me);
			AddMenuItem("�����鱨�����", "2", me);
			AddMenuItem("�����鱨�����", "3", me);			
			AddMenuItem("��ȡ��ʱս��", "ask", me);
			AddMenuItem("��Ҫ����", "4", me);
			if(me->query("grant") > 90)
				AddMenuItem("��ʼ��ǩ", "chouqian", me);
		}
		else if(strcmp(ask, "1") == 0)
		{
			say(snprintf(msg, 255, "����%ld�˱�����", query_count(querymap("young/register"))), me);
		}
		else if(strcmp(ask, "2") == 0)
		{
			say(snprintf(msg, 255, "����%ld�˱�����", query_count(querymap("middle/register"))), me);
		}
		else if(strcmp(ask, "3") == 0)
		{
			say(snprintf(msg, 255, "����%ld�˱�����", query_count(querymap("old/register"))), me);
		}
		else if(strcmp(ask, "ask") == 0)
		{
			return ask_zhanbao(me);
		}
		else if(strcmp(ask, "chouqian") == 0 && wizardp(me))
		{
			chouqian("young");
			chouqian("middle");
			chouqian("old");

			set("state", 1);	//��ǩ����
			return 1;
		}
		else
			return register_me(me);		//��Ҫ����
	}
	else	//����׶� state = ��N��
	{		
		char cmd[20];

		if(! strlen(ask))
		{
			AddMenuItem("�鿴�����������", "1", me);
			AddMenuItem("�鿴�����������", "2", me);
			AddMenuItem("�鿴�����������", "3", me);
			AddMenuItem("�鿴��ʱ�������", "4", me);
			AddMenuItem("��ȡ��ʱս��", "ask", me);
			AddMenuItem("��Ҫ����", "baoming", me);

			if(me->query("grant") > 90)
			{
				AddMenuItem("���µǼ��˷���", "chouqian", me);
			}
		}
		else if(strcmp(ask, "ask") == 0)
		{
			return ask_zhanbao(me);
		}
		else if(strcmp(ask, "chouqian") == 0 && wizardp(me))
		{
			chouqian("young");
			chouqian("middle");
			chouqian("old");
			chouqian("temp");
			return 1;
		}
		else if(strcmp(ask, "baoming") == 0)
		{
			return register_me(me);		//��Ҫ����
		}
		else
		{			
			for(int i=0; i<=state; i++)
			{
				AddMenuItem(snprintf(msg, 255, "�鿴��%ld�ֶ�������", i), 
					snprintf(cmd, 20, "$0lookup $1 %s %ld", ask, i), me);	
			}
		}		
	}
	
	SendMenu(me);
	return 1;
}

//�ӵ�ע�����
int do_register(CChar * me, const char * zu, const char * id)
{
	char msg[255];
	CUser * user = find_online(id);
	if(! user) return notify_fail("���˲�����!");

	set(snprintf(msg, 255, "%s/register/%s", zu, id), user->name(1));
	tell_object(me, snprintf(msg, 255, "��%sע�ᵽ%s��.", user->name(1), zu));
	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{	
	char team[40];

	if(strcmp(comm, "lookup") == 0)
	{			
		analyse_string(arg, team, 20);
		return look_turn(me, atol(arg), atol(team));
	}
	
	if(wizardp(me))
	{
		if(strcmp(comm, "biwu") == 0)	//ָ���÷�: biwu ��N��
		{
			analyse_string(arg, team, 20);
			return do_biwu(atol(arg), atol(team));
		}
		else if(strcmp(comm, "summon") == 0)
		{
			analyse_string(arg, team, 20);
			return do_summon(me, atol(arg), atol(team));
		}
		else if(strcmp(comm, "register") == 0)	//�Ǽ� register temp 1193
		{
			analyse_string(arg, team, 20);
			return do_register(me, arg, team);
		}
	}

	return CNpc::handle_action(comm, me, arg);
}

//�Ǽ�
void register_join(CChar * me, CMapping * team)
{
	if(team)
		team->set(me->id(1), me->name(1));
}

int query_count(CMapping * team)
{
	if(! team) return 0;
	return team->GetCount();
}

int has_register(CChar * me)
{
	if( query_register(me, querymap("young/register")) )
		return 1;
	if( query_register(me, querymap("middle/register")) )
		return 2;
	if( query_register(me, querymap("old/register")) )
		return 3;
	return 0;
}

int query_register(CChar * me, CMapping * team)
{
	if(! team) return 0;
	return team->querystr(me->querystr("id"))[0];
}

NPC_END;