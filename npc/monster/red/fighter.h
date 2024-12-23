
#define FIGHTER_BEGIN(npc_name) class npc_name : public CNwiz_fighter	{	public:	npc_name(){};	virtual ~npc_name(){};
#define FIGHTER_END		};	

NPC_BEGIN(CNwiz_fighter);
/*
void create()
{
	set_name("ս��", "chao feng");

	set("title", "������Ǽ�Ա");
	set("icon", girl2);
	set("gender", "Ů��" );
	set("age", 25);

	set("chname", "�ֳ�ֱ��");
	set("channel", "wldh");

	set("grant", 80);
	
	set("combat_exp", 150);
	set("attitude", "friendly");
	
	set("judge/attr", "level");
	set("judge/min", 31);
	set("judge/max", 45);
	set("judge/desc", "�ȼ���31��45֮�䡣");

	set("biwu/name", "���������");
	set("biwu/register/0", "��ȱ");
	set("biwu/turn0/0", "0");

	set("file_name", querystr("base_name"));

	Load();
};
*/
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
		if( has_register(me))
		{			
			say(snprintf(msg, 255, "���ѵǼǡ������ĵȴ������Ὺʼ��"), me);
		}
		else
		{
			int attr = me->query(querystr("judge/attr"));
			if(attr >= query("judge/min") && attr < query("judge/max"))
			{
				if((me->query("level")<30 && me->query_skill("force", 1) < 110 && me->query_skill("dodge", 1) < 110 && me->query_skill("parry", 1) < 110) || (me->query("level")>=30 && me->query("level")<60 && me->query_skill("force", 1) < 220 && me->query_skill("dodge", 1) < 220 && me->query_skill("parry", 1) < 220)|| (me->query("level")>=60 && me->query("level")<80 && me->query_skill("force", 1) < 285 && me->query_skill("dodge", 1) < 285 && me->query_skill("parry", 1) < 285) || me->query("level")>=80)
				{
					register_join(me, querymap("biwu/register"));
					say("�����ˣ��Ⱥ�����Ὺʼ��", me);
				}
				else
				{
					say("������ID���зϺŵ����ɣ�Ϊ�˱�����Ĺ�ƽ����������ʱ�㻹�ǲ��μ��˰ɣ���", me);
				}
			}
			else
			{
				say("���У��㲻����������ı����ʸ�", me);
			}
		}
	}

	SendMenu(me);
	return 1;
}

//team, st�������ķ���ʼ����
void chouqian2(CVector & v, CMapping * result, int team, int st)
{
	int count;
	char str[20];

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
}

//��ǰ�������³�ǩ
int reform()
{
	char str[40];
	int state = query("state") - 1;
	if(state < 0) return notify_fail("��û�ֹ��飬���ó�ǩָ�");

	CMapping * reg = querymap(snprintf(str, 40, "biwu/turn%ld", state));
	if(! reg) return notify_fail("û�и���");

	//����Ϸ��Ƿ��Ѿ��б������
	if(querymap(snprintf(str, 40, "biwu/turn%ld", state + 1)) )
		return notify_fail("�����Ѿ��б�������ˣ������ط���");

	CVector v, team;

	reg->keys(v);
	for(int i=0; i<v.count(); i++)
	{
		CMapping * line = reg->querymap(v[i]);
		if(! line) continue;

		if(line->querystr("A")[0])
			team.append(line->querystr("A"));
		if(line->querystr("B")[0])
			team.append(line->querystr("B"));
	}
	
	reg->clear();
	chouqian2(team, reg, 0, 0);
	return 1;
}

//��ǩ���� 
int chouqian()
{		
	char msg[255];

	del("biwu/register/0");

	CMapping * reg = querymap("biwu/register");
	CMapping * result = querymap("biwu/turn0");

	if(! result)
	{
		CMapping m;
		set(msg, m);
		result = querymap(msg);
	}

	if(! reg || ! result) return 0;

	int st = 0, team = 0;
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

	chouqian2(v, result, team, st);
	return 1;
}

//�鿴������ʽ
int look_turn(CChar * me, int turn)
{
	if(turn < 0 || turn > query("state")) return notify_fail("û�н��е����֡�");

	char msg[255], str[20];
	CMapping * m = querymap(snprintf(msg, 40, "biwu/turn%ld", turn));
	CMapping * reg = querymap("biwu/register");
	CMapping * ptr;
	int i;
	
	if(! m || ! reg) return notify_fail("��û�н����");

	tell_object(me, snprintf(msg, 255, "\n��%s�ֶ�����ʽ", chinese_number(turn, str)));
	tell_object(me, "-------------------------------------------------------");

	int count = (reg->GetCount() + 1) / 2;
//	for(i=0; i<turn; i++)
//		count = (count + 1) / 2;

	//�ж��Ƿ���ʤ
	CMapping * next = querymap(snprintf(msg, 40, "biwu/turn%ld", turn + 1));
	int win;
	CVector v, team;

	if(next)
	{
		next->keys(v);
		for(int t = 0; t<v.count(); t++)
		{
			CMapping * line = next->querymap(v[t]);
			if(! line) continue;

			if(line->querystr("A")[0])
				team.append(line->querystr("A"));
			if(line->querystr("B")[0])
				team.append(line->querystr("B"));
		}
	}

	for(i=0; i<count; i++)
	{
		ptr = m->querymap(snprintf(msg, 255, "%ld", i));
		if(! ptr) continue;
		
		const char * key1 = ptr->querystr("A");
		const char * key2 = ptr->querystr("B");

		if(team.find(key1) != team.end())
			win = 1;
		else if(team.find(key2) != team.end())
			win = 2;
		else 
			win = 0;
/*		
		CMapping * next = querymap(snprintf(msg, 40, "biwu/turn%ld/%ld", turn + 1, i/2));
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
*/			
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
int do_biwu(int team)
{
	char msg[255];

	int state = query("state") - 1;
	if(state < 0) return 0;
	
	CMapping * ptr = querymap(snprintf(msg, 255, "biwu/turn%ld/%ld", state, team));
	if(! ptr) return notify_fail("û�и��顣biwu <���>");
	
	const char * key1 = ptr->querystr("A");
	const char * key2 = ptr->querystr("B");

	CUser * fighter1 = find_online(key1);
	CUser * fighter2 = find_online(key2);

	if(fighter1 && fighter2)	//���˾����ߣ���ʼ����
	{	
		fighter1->set_temp("biwu/npc", object_id());	//����NPCע��
		fighter1->set_temp("biwu/team", team);		
		fighter2->set_temp("biwu/npc", object_id());	//����NPCע��
		fighter2->set_temp("biwu/team", team);

		full_me(fighter1);
		full_me(fighter2);
	//	command(snprintf(msg, 255, "full %ld", fighter1->object_id()));
	//	command(snprintf(msg, 255, "full %ld", fighter2->object_id()));

		CContainer * env = Do_BiShi(fighter1, fighter2, "���ִ��", 0);
		env->set("room_locked", FIGHT_LOCKED);	//ս������.

		//����ս���������
		set_biwu(env);

		CContainer * oldenv = find_object(query_temp("is_boardcast"));
		if(! oldenv) do_snoop(env);
		
		return 1;
	}

	if(fighter1) 
		register_winner(fighter1, team);
	else if(fighter2) 
		register_winner(fighter2, team);
	else
		return notify_fail("�������ߡ�");

	return 1;
}

//ץ��
int do_summon(CChar * me, int team)
{
	char msg[255];

	int state = query("state") - 1;
	if(state < 0) return 0;

	CMapping * ptr = querymap(snprintf(msg, 255, "biwu/turn%ld/%ld", state, team));
	if(! ptr) return notify_fail("û�и��顣summon <���>");
	
	const char * key1 = ptr->querystr("A");
	const char * key2 = ptr->querystr("B");

	CUser * fighter1 = find_online(key1);
	CUser * fighter2 = find_online(key2);
	
	CContainer * r = me->environment();

	if(fighter1) 
	{
		fighter1->move(r);
		if(fighter1->query("mp")>fighter1->query("max_mp")*4)
			fighter1->set("mp",fighter1->query("max_mp")*4);
		message_vision("$N���������", fighter1);
	}
	
	if(fighter2) 
	{
		fighter2->move(r);
		if(fighter2->query("mp")>fighter2->query("max_mp")*4)
			fighter2->set("mp",fighter2->query("max_mp")*4);
		message_vision("$N���������", fighter2);
	}
	
	return 1;
}

int do_ready(CChar * me, int team)
{
	char msg[255];
	int state = query("state") - 1;
	if(state < 0) return 0;

	CMapping * ptr = querymap(snprintf(msg, 255, "biwu/turn%ld/%ld", state, team));
	if(! ptr) return notify_fail("û�и��顣summon <���>");
	
	const char * key1 = ptr->querystr("A");
	const char * key2 = ptr->querystr("B");

	CUser * fighter1 = find_online(key1);
	CUser * fighter2 = find_online(key2);
	
	int wait_time = query("wait_time");

	command(snprintf(msg, 255, "wiz 0 ���%ld��(%s VS %s)����׼������������%ld���Ӻ���С�", team + 1, key1, key2, wait_time));

	if(fighter1 && fighter2)
	{		
		snprintf(msg, 255, "\n\n$HIG�����䡿%s��%s��׼���ã�", fighter1->name(1), fighter2->name(1), wait_time);

		tell_object(fighter1, msg);
		tell_object(fighter2, msg);	
	}
	else
	{
		command("wiz 0 ���䵱ʱ�����ߵİ���Ȩ���������Զ��������֡�");	
	}

	do_ready(this, wait_time, team);
	return 1;
}

static void do_ready(CContainer * ob, LONG wait_time, LONG team)
{
	CNwiz_fighter * me = (CNwiz_fighter *)ob;

	if(wait_time <= 0)
	{
		me->do_summon(me, team);
		me->do_biwu(team);
		return;
	}

	char msg[255];
	int state = me->query("state") - 1;
	if(state < 0) return;

	CMapping * ptr = me->querymap(snprintf(msg, 255, "biwu/turn%ld/%ld", state, team));
	if(! ptr) return;
	
	const char * key1 = ptr->querystr("A");
	const char * key2 = ptr->querystr("B");

	CUser * fighter1 = find_online(key1);
	CUser * fighter2 = find_online(key2);
	
	snprintf(msg, 255, "\n\n$HIR�����䡿������������%ld���ӣ�ʱ�䵽�Զ�����ս����������׼����\n\n", wait_time);

	if(fighter1)
		tell_object(fighter1, msg);
	if(fighter2)
		tell_object(fighter2, msg);

	me->call_out(do_ready, 60, wait_time - 1, team);
}

void is_defeated(CChar * winner, CChar * failer)
{
	if(winner == this || failer == this) return;

	int team = winner->query_temp("biwu/team");

	//�����Ǳ����ʤ�ߵĴ���
	register_winner(winner, team);

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

//��ʤ�߽�����һ������
void register_winner(CChar * who, int team)
{
	char msg[255], tmp[20];
	int state = query("state");
			
	if(team % 2 == 0)
		snprintf(msg, 255, "biwu/turn%ld/%ld/A", state, team/2);
	else
		snprintf(msg, 255, "biwu/turn%ld/%ld/B", state, team/2);

	set(msg, who->querystr("id"));	

	const char * zuname = querystr("biwu/name");
	g_Channel.do_channel(this, NULL, "wiz", snprintf(msg, 255, "��ϲ%s(%s)˳������%s��%s�ֱ�����", 			
			who->name(1), who->id(1), zuname, chinese_number(state, tmp) ));

	Save();
}

int ask_zhanbao(CChar * me)
{
	char msg[255];
	CContainer * obj = load_item("wiz_zhanbao");
	obj->set_name(snprintf(msg, 255, "%sս��", querystr("biwu/name")), "zhan bao");

	obj->move(me);
	obj->set("biwu", object_id());
	
	tell_object(me, snprintf(msg, 255, "$YEL����һ��%s������������ʱ���ı������¶�ս���ơ�", obj->name(1)));
	
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
			AddMenuItem("�鿴�������", "1", me);
			AddMenuItem("��ȡ��ʱս��", "ask", me);
			AddMenuItem("ѯ�ʱ�������", "tiaojian", me);

			if(! has_register(me))
				AddMenuItem("��Ҫ����", "register", me);
			else
				AddMenuItem("ȡ������", "cancel", me);

			if(me->query("grant") > 80)
			{
				AddMenuItem("��ʼ��ǩ", "chouqian", me);				
			}

		}
		else if(strcmp(ask, "1") == 0)
		{
			say(snprintf(msg, 255, "����%ld�˱�����", query_count(querymap("biwu/register"))), me);
		}		
		else if(strcmp(ask, "ask") == 0)
		{
			return ask_zhanbao(me);
		}
		else if(strcmp(ask, "chouqian") == 0 && wizardp(me))
		{
			chouqian();			
			set("state", 1);	//��ǩ����
			return 1;
		}
		else if(strcmp(ask, "tiaojian") == 0)
		{
			say(querystr("judge/desc"), me);
		}
		else if(strcmp(ask, "register") == 0)
			return register_me(me);		//��Ҫ����
		else 
		{
			del(snprintf(msg, 255, "biwu/register/%s", me->id(1)));
			Save();
			say("ȡ���˱���", me);
		}
	}
	else	//����׶� state = ��N��
	{		
		char cmd[20];

		if(! strlen(ask))
		{
			AddMenuItem("�鿴������", "1", me);			
			AddMenuItem("��ȡ��ʱս��", "ask", me);
			//AddMenuItem("��Ҫ����", "baoming", me);
			
			if(me->query("grant") > 80)
			{					
				AddMenuItem(snprintf(msg, 255, "�����%ld��", state), "next", me);
				AddMenuItem("�ص�ǰһ��", "prev", me);
				AddMenuItem("�������·���", "reform", me);				
				//AddMenuItem("���µǼ��˷���", "chouqian", me);
			}
		}
		else if(strcmp(ask, "ask") == 0)
		{
			return ask_zhanbao(me);
		}
		else if(strcmp(ask, "chouqian") == 0 && wizardp(me))
		{
			chouqian();
			return 1;
		}
		else if(strcmp(ask, "next") == 0 && wizardp(me))
		{
			add("state", 1);
		}
		else if(strcmp(ask, "prev") == 0 && wizardp(me))
		{
			add("state", -1);
		}
		else if(strcmp(ask, "baoming") == 0)
		{
			return register_me(me);		//��Ҫ����
		}
		else if(strcmp(ask, "reform") == 0 && wizardp(me))
		{						
			if(reform())
				return 1;
			else
				say("����ʧ��", me);
		}
		else
		{			
			for(int i=0; i<=state; i++)
			{
				AddMenuItem(snprintf(msg, 255, "�鿴��%ld�ֶ�������", i), 
					snprintf(cmd, 20, "$0lookup $1 %ld", i), me);	
			}
		}		
	}
	
	SendMenu(me);
	return 1;
}

//�ӵ�ע�����
int do_register(CChar * me, const char * id)
{
	char msg[255];
	int load = 0;

	CUser * user = find_online(id);
	if(! user)
	{
		load = 1;
		user = add_user();
		user->set("id", id);

		if(! user->LoadFromServer())
			return notify_fail("û�������!");
	}

	set(snprintf(msg, 255, "biwu/register/%s", id), user->name(1));
	tell_object(me, snprintf(msg, 255, "��%sע��.", user->name(1)));

	if(load)
		destruct(user);

	Save();
	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{	
	char msg[40];

	if(strcmp(comm, "lookup") == 0)
	{			
		return look_turn(me, atol(arg));
	}
	else if(strcmp(comm, "opench") == 0)
	{
		CVector * tuned_ch = me->queryvec("channels");
		const char * channel = querystr("channel");
		if(channel[0])
		{
			if( ! tuned_ch )
			{
				CVector v;
				v.append(channel);
				me->set("channels", v);
			}
			else if( tuned_ch->find(channel) == tuned_ch->end() )
			{
				tuned_ch->append(channel);
			}
		}
		return 1;
	}
	else if(strcmp(comm, "closech") == 0)
	{
		const char * channel = querystr("channel");
		if(channel[0])
			me->command(snprintf(msg, 40, "tune 0 %s", channel));
		return 1;
	}
	
	if(wizardp(me))
	{
		if(strcmp(comm, "biwu") == 0)	//ָ���÷�: biwu ��N��
		{			
			return do_biwu(atol(arg) - 1);
		}
		else if(strcmp(comm, "summon") == 0)
		{			
			return do_summon(me, atol(arg) - 1);
		}
		else if(strcmp(comm, "register") == 0)	//�Ǽ� register 1193
		{			
			return do_register(me, arg);
		}
		else if(strcmp(comm, "ready") == 0)
		{
			return do_ready(me, atol(arg) - 1);
		}
		else if(strcmp(comm, "snoop") == 0)
		{
			transfer_info();
			return 1;
		}
		else if(strcmp(comm, "goto") == 0)
		{
			command(snprintf(msg, 40, "goto %ld", me->object_id()));
			return 1;
		}
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

int query_count(CMapping * team)
{
	if(! team) return 0;
	return team->GetCount();
}

int has_register(CChar * me)
{
	CMapping * team = querymap("biwu/register");
	if(! team) return 0;
	return team->querystr(me->querystr("id"))[0];
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



