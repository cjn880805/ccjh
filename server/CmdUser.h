BOOL VerifyUser(const char * userid, char * passwd);
int ChangePassword(const char * id, const char * pass);
int VerifyPassword(const char * id, const char * pass);
int ChangeVerifyPassword(const char * id, const char * pass);
void setup_char(CChar * me);
char * check_legal_name(const char * name);

#define  MAX_ENV_VARS		10
#define	 VOTE_AGE_LIMIT		15
#define	 VOTE_LEVEL_LIMIT	5

class CCmdUser
{
public:
	CCmdUser()
	{
		//m_Cmd["info"] = Info;
		//m_Cmd["item"] = Item;
		m_Cmd["skill"] = Skill;
		m_Cmd["downloadskill"] = DownLoadSkill;
		m_Cmd["downloadobject"] = DownLoadObject;
		m_Cmd["downloaduser"] = downloaduser;
	
		m_Cmd["quit"] = Quit;
		m_Cmd["save"] = Save;
		m_Cmd["wakeup"] = Wakeup;
		m_Cmd["nick"] = Nick;
		m_Cmd["talk"] = Talk;
		m_Cmd["ask"] = Talk;
		m_Cmd["set"] = SetParam;
		m_Cmd["unset"] = Unset;

		m_Cmd["refuse"] = refuse;

		m_Cmd["mudage"] = Mudage;
		m_Cmd["password"] = Passwd;
		m_Cmd["verifypass"] = VerifyPass;
		m_Cmd["upgrade"] = Upgrade;
		m_Cmd["tune"] = Tune;
		m_Cmd["vote"] = Vote;
	
		m_Cmd["refusetell"] = RefuseTell;
		m_Cmd["wantlisten"] = Listen;

		m_Cmd["nickname"] = NickName;
		m_Cmd["rexp"] = RecruitExp;

		m_Cmd["invite"] = invite;
		m_Cmd["accept"] = accept;
		m_Cmd["mv"] = mv;
		m_Cmd["loc"] = loc;

		m_Cmd["addfriend"] = addfriend;
		m_Cmd["remfriend"] = remfriend;
		m_Cmd["who"] = who;		

		m_Cmd["listgoods"] = ListGoods;
		m_Cmd["pary"] = Pary;
		m_Cmd["accept_pary"] = Accept_pary;
		m_Cmd["paryleave"] = Paryleave;
		m_Cmd["parykick"] = Parykick;
		//m_Cmd["parylist"] = Parylist;��δ���
		m_Cmd["buy"] = Buy;
		m_Cmd["validate"] = Validate;
		
	};

	~CCmdUser(){};

	typedef int (* func)(CChar * me, LONG target, char * arg);
	typedef map<string, func, less<string> > CMDMAP;
	CMDMAP m_Cmd;

	int Handlecommand(char * cmd, CChar * me, LONG target, char * arg)
	{
		CMDMAP::iterator p;
		if((p = m_Cmd.find(cmd)) == m_Cmd.end()) return -1;
		return ((*p).second)(me, target, arg);
	}

	DEFINECMD(Info)
	{
		me->FlushMyInfo();
		return 1;
	}

	//�õ�ĳ�����Ʒ�б� item #obj
	DEFINECMD(Item)
	{
		me->FlushMyEquip();
		return 1;
	}
	

	//skill
	//�鿴who�ļ��ܡ�
	DEFINECMD(Skill)
	{
		CChar * who = GetRoomChar(me, target);
		if(!who) who = me;

		//�ж�me�Ƿ���Ȩ�޿�who�ļ��ܡ�
		if( ! wizardp(me) && me != who && ! Is_Relative(me, who)
			&& ! who->recognize_apprentice(me) ) 
		return notify_fail("����Ȩ�鿴�Է����ܡ�");

		who->FlushMySkill(me);
		return 1;
	}

	//���ؼ���
	DEFINECMD(DownLoadSkill)
	{
		CSkill * skill;
		
		if( ! (skill = load_skill(arg)) ) return 0;
		skill->DownLoad(me);
		return 1;
	}

	//�������
	DEFINECMD(DownLoadObject)
	{
		CContainer * obj;
		
		if( (obj = find_object(target)) )
			obj->DownLoad(me);
		return 1;
	}
		

	//�˳���Ϸ
	DEFINECMD(Quit)
	{
		char cmd[255];

		if(me->is_fighting() && !me->query_temp("net_dead"))
			return notify_fail("ս���в����˳���");

		if(me->is_busy())
			return notify_fail("( ����һ��������û����ɣ������˳���)");
		DropAll(me);
		me->SaveToServer();

		//����
		((CUser *)me)->Offline();
		tell_room(me->environment(), snprintf(cmd, 255, "%s�뿪��Ϸ��", me->name()), me);

		g_Channel.do_channel(&g_Channel, 0, "sys", cmd);

		DESTRUCT_OB(me, "cmd::quit");
		return 1;
	}

	DEFINECMD(Wakeup)
	{
		char msg[512];
		char info[400];
		CChar * who;

		if(! (who = find_player(target)))
			return 0;

		if(! strlen(arg)) strcpy(info, "�������ˣ�");
		else strncpy(info, arg, 400);

		snprintf(msg, 512, "��������%s����%s�Ķ���󺰣�%s", me->name(), who->name(), info);
		MessageVision(me, "chat", msg);
		snprintf(msg, 512, "&C=%d&T=%ld&M=%s&", WAKEUP, me->object_id(), arg);
		who->SendCommand(msg);			//����
		return 1;
	}

	DEFINECMD(Save)
	{
		if(current_time < me->query_temp("last_save_time"))
		{
			MessageVision(me, "tell", "������ʮ���ڸմ���̡�");
			return 1;
		}

		me->set_temp("last_save_time", current_time + 30);

		CContainer * where = me->environment();
		if( where->query("valid_startroom") 
			|| EQUALSTR(where->querystr("owner"), me->querystr("id"))
			|| EQUALSTR(where->querystr("second_owner"), me->querystr("id")))
		{
			me->set("start_city", where->querystr("base_name"));
			tell_object(me, "�����´����߽���ʱ��������￪ʼ��");
		}

		if(me->Save())
			tell_object(me, "����������ϡ�");
		else
			tell_object(me, "����ʧ�ܡ�");
		
		return 1;
	}

	//Ϊ��������
	DEFINECMD(Nick)
	{
		int len = strlen(arg);
		char msg[80];
		CChar * who;

		if(! (who = FindSprite(me))) return 0;

		if(! len || len > 10)
		{
			MessageVision(me, "tell", "���ֳ��Ȳ��Ϸ���");
			return 0;
		}
	
		//����������з�Ƿ��ַ�
		if(! CheckValidChar(arg))
			return notify_fail("�����к��зǷ��ַ���");
	
		snprintf(msg, 80, "[����]%s", arg);
		who->set_name( msg);

		who->UpdateMe();
	
		tell_object(me, snprintf(msg, 80, "�㽫��������Ϊ%s��", arg));
		
		return 1;
	}

	DEFINECMD(Talk)
	{
		//��ֹ������Ϊno_talk�ĳ���ʹ��Talk���� �ز� 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_talk")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹ����˵����");
		
		CChar * who;
		char msg[80], tmp[40];

		if(! (who = GetRoomChar(me, target)) ) return notify_fail("��Ҫ��˭������������㣡");
		if(! living(who) || who == me) return notify_fail("�Է���Ȼ�޷����㽲����");

		notify_fail("�Է�����Ը�����㡣");
		if(me->is_fighting() || who->is_fighting() )
		{
			if( who->Query(CChar::IS_NPC) && EQUALSTR(who->querystr("name"), "˪��"))
				return ((CNpc *)who)->do_talk(me, arg);
			else
				return 0;
		}

		if(who->Query(CChar::IS_NPC))
		{		
			return ((CNpc *)who)->do_talk(me, arg);
		}

		CContainer * where = me->environment();

		//����ҵĽ���
		
		//����ҽ���
		who->AddMenuItem(snprintf(msg, 80, "�鿴%s�Ļ�Ʒ", who->name()), "$0listgoods $1", me);
		//��������
		if(EQUALSTR(me->querystr_temp("pary/master"),who->querystr("id")))
			who->AddMenuItem(snprintf(msg, 80, "�����%s�����", who->name()), "$0paryleave $1", me);
		else if(me->query_temp(snprintf(msg, 80,"pary/friend_%s",who->querystr("id"))))
		{
			who->AddMenuItem(snprintf(msg, 80, "�߳�%s����", who->name()), "$0parykick $1", me);
//			who->AddMenuItem("�鿴���߶�Ա", "$0parylist $1", me);
		}
		else
			who->AddMenuItem(snprintf(msg, 80, "��%s���", who->name()), "$0pary $1", me);

		
		if(me->querystr("resident")[0])	//���Լ��ķ���
		{
			//����ڼ���
			if(DIFFERSTR(where->querystr("owner"), me->querystr("id"))
				&& DIFFERSTR(where->querystr("second_owner"), me->querystr("id")))
			{
				who->AddMenuItem(snprintf(msg, 80, "����%s����", who->name()),	"$0invite $1",me);
			}
			else	//�ڼ��� ���ܸϷ���
			{
				if(DIFFERSTR(where->querystr("owner"), who->querystr("id")))
					who->AddMenuItem(snprintf(msg, 80, "��%s�ϳ�����", who->name()), snprintf(tmp, 40, "$0kickout 0 %s", who->id(1)), me);
			}
		}

		if( where->query("sleep_room") 
			&& DIFFERSTR(who->querystr("gender"), me->querystr("gender")) )	//����˯��
			who->AddMenuItem(snprintf(msg, 80, "���%s˯��", who->name()), "$0sleep $1", me);

		if( EQUALSTR(who->querystr("couple/id"), me->querystr("id"))	//���޿��Դ���
			&& EQUALSTR(who->querystr("id"), me->querystr("couple/id")))
		{
			who->AddMenuItem(snprintf(msg, 80, "�鿴%s�ļ���", me->querystr("couple/gender")), "$0skill $1", me);
			who->AddMenuItem(snprintf(msg, 80, "��%s����", me->querystr("couple/gender")), "$0teach $1", me);
		}

		if( me->query("recruit_exp") / 50 > me->recruit_num())
			who->AddMenuItem(snprintf(msg, 80, "��%sΪͽ", who->name()), "$0recruit $1", me);

		if( who->query("recruit_exp") / 50 > who->recruit_num())
			who->AddMenuItem(snprintf(msg, 80, "��%sΪʦ", who->name()), "$0apprentice $1", me);
			
		if( who->query_condition("prostitute") && where->query("wench_room"))
			who->AddMenuItem("�μ�", "$0wench $1", me);

		who->AddMenuItem(snprintf(msg, 80, "��%sûʲô��˵��", who->name()), "", me);
		who->SendMenu(me);
		return 1;
	}

	//���û�������
	DEFINECMD(SetParam)
	{
		char str_wiz_only[] = "({\"invisibility\",\"immortal\"})";
		CVector wiz_only;
		char val[40], msg[255];
		CMapping * env;
		char key[40];
				
		env = me->querymap("env");
		if( ! strlen(arg))
		{
			tell_object(me, "��Ŀǰ�趨�Ļ��������У�");
			if(! env)
				tell_object(me, "û���趨�κλ���������");
			else
			{
				CVector v;
				int i;

				env->keys(v);

				for(i = 0; i < v.count(); i++)
				{
					CMapping::svalue_t * sv = env->find_string_in_mapping(v[i]);
					if(sv->type == T_NUMBER)
						tell_object(me, snprintf(msg, 80, "%s = %d", v[i], sv->u.number) );
					else if(sv->type == T_STRING)
						tell_object(me, snprintf(msg, 80, "%s = %s", v[i], sv->u.string) );
				}
			}
			return 1;
		}
 
		if( env && env->GetCount() >= MAX_ENV_VARS )
			return notify_fail("����Ļ�������̫���ˣ������� unset ɾ�������ɡ�");

		analyse_string(arg, val, 40);
		me = FindMaster(me);

		wiz_only.LoadBuffer(str_wiz_only);
		//allowed.LoadBuffer(str_allowed);
		//if(! wizardp(me) && allowed.find(arg) == allowed.end())
		//	return notify_fail("��ֻ���趨settings�ж�����Ļ���������");
        if(! wizardp(me) && wiz_only.find(arg) != wiz_only.end() )
            return notify_fail("ֻ����ʦ��������趨��");

		if(strcmp(arg, "wimpy") == 0 && ( atol(val) < 0 || atol(val) > 80) )
			return notify_fail("wimpy [<����ʱ�������İٷֱ�>]");
		
		if(! CheckValidChar(arg))
			return notify_fail("�����û����������Ƿ���");
			
			snprintf(key, 40, "env/%s", arg);

		if(val[0] == '-' || (val[0] >='0' && val[0] <='9'))
			{
				me->set(key, atol(val));
				snprintf(msg, 255, "�����û���������%s Ϊ %s��", arg, val);
				MessageVision(me, "tell", msg);
			}
//		else 
//				me->set(key, val);
		else 
			{
				snprintf(msg, 255, "�����û���������%s Ϊ %s �Ƿ���", arg, val);
				MessageVision(me, "tell", msg);
			}
		return 1;
	}

	DEFINECMD(Unset)
	{
		char key[80];
		if(! strlen(arg)) return 0;
		
		snprintf(key, 80, "env/%s", arg);
		me->del(key);
		tell_object(me, "Ok.");
		return 1;
	}

	DEFINECMD(Mudage)
	{
		int sec, min, hrs, day, mon, age;
		char msg[80], tmp[255], str[255];
   
		if( me->query("hp") < 10 )
			return notify_fail("��ľ����ܼ��������Լ������ꡣ");
     
		age = me->query("mud_age");

		sec = age % 60;
		age /= 60;
		min = age % 60;
		age /= 60;
		hrs = age % 24;
		age /= 24;
		day = age % 30;
		mon = age / 30;
   
		msg[0] = 0;
		if(mon)
			snprintf(msg, 80, "%s��",  chinese_number(mon, str));
		
		if(day)
		{
			snprintf(tmp, 80, "%s��", chinese_number(day, str));
			strcat(msg, tmp);
		}
		
		if(hrs)
		{
			snprintf(tmp, 80, "%sСʱ", chinese_number(hrs, str));
			strcat(msg, tmp);
		}

		me->add("hp", -5);

		tell_object(me, snprintf(tmp, 255, "���Ѿ�Ϊ%s�ܶ�%s�ˡ�", MUD_NAME, msg));
		return 1;
	}

	//�޸�����
	DEFINECMD(Passwd)
	{		
		char msg[40];

		analyse_string(arg, msg, 40);

		//��������
		if(! me->query_temp("pending/modify_pass"))
		{			
			if(! VerifyUser(me->querystr("id"), arg))
				return notify_fail("��ԭ���벻�����������������룡");
			
			if(! VerifyPassword(me->id(1), msg))
				return notify_fail("�����֤δͨ��!");

			me->set_temp("pending/modify_pass", 1);
			tell_object(me, "��������ͨ������������������룡");
			return 1;
		}

		if(strlen(arg) < 5) return notify_fail("���벻������5����Ԫ��");
		if(strlen(arg) > 20) return notify_fail("��������Ҳ̫���ˣ�");

		if(! ChangePassword(me->querystr("id"), arg))
			return notify_fail("�޸�����ʧ�ܣ�");

		me->delete_temp("pending/modify_pass");
		tell_object(me, "�޸�����ɹ���");
		return 1;
	}

	//��֤������
	DEFINECMD(Validate)
	{		
		char msg[40];
		
		analyse_string(arg, msg, 40);
		
		if(!me->query_temp("validate"))
		{			
			if(! VerifyUser(me->querystr("id"), arg))
				return notify_fail("���벻�������ܽ��н�һ�������������");
			
			if(! VerifyPassword(me->id(1), msg))
				return notify_fail("���벻�������ܽ��н�һ�������������");
			
			me->set_temp("validate", 1);
			tell_object(me, "�����֤ͨ���������ڿ��Լ���������Ĳ�����");
		}
		return 1;
	}

	//�޸İ���
	DEFINECMD(VerifyPass)
	{		
		char msg[40];

		analyse_string(arg, msg, 40);
		if(! msg[0])
		{
			strncpy(msg, arg, 40)[39] = 0;	
			arg[0] = 0;			
		}
		
		if(! VerifyPassword(me->id(1), arg))
			return notify_fail("�����֤δͨ��!");
			
		if(strlen(msg) < 5) return notify_fail("���벻������5����Ԫ��");
		if(strlen(msg) > 20) return notify_fail("���İ���Ҳ̫���ˣ�");

		if(! ChangeVerifyPassword(me->querystr("id"), msg))
			return notify_fail("�޸İ���ʧ�ܣ�");

		tell_object(me, "�޸İ���ɹ���");
		return 1;
	}

	//����ϵͳ
	DEFINECMD(Upgrade)
	{
		int level = me->query("level");
		LONG valid_exp = me->query_valid_exp();	//�����������ľ���
		LONG need_exp = CChar::Level2Exp(level + 1) - CChar::Level2Exp(level);
	
		if(valid_exp < need_exp)
			return notify_fail("�㵱ǰ�ľ��鲻����һ����");

		me->set("level", level + 1);
		setup_char(me);
		tell_object(me, "�����ɹ���");
		me->FlushMyInfo();
		return 1;
	}

	//�ر�Ƶ��
	DEFINECMD(Tune)
	{
		CVector * v;
		char msg[80];
		
		v = me->queryvec("channels");

		if(arg) 
		{
			if(v && v->find(arg) != v->end() )
			{
				tell_object(me, snprintf(msg, 80, "�ر�%sƵ����", arg));
				v->remove(arg);			 	
				return 1;
			}
		}     
        
		tell_object(me, "Ҫ��ĳ��Ƶ��ֻҪ�ø�Ƶ��˵�����ɡ�");
		return 1;
   	}

	

	//ͶƱ
	DEFINECMD(Vote)
	{
		char channel[20];
		CMapping voted_player;
		char msg[255];
				
		static LONG vote_id = 100;

		analyse_string(arg, channel, 20);
		if(strcmp(arg, "open")!=0 && strcmp(arg, "close")!=0 ||! strlen(channel))
			return notify_fail("��ָ��/vote <close|open> <Ƶ��>");

		if (me->query("age") < VOTE_AGE_LIMIT || me->query("level") < VOTE_LEVEL_LIMIT) 
		{
			if (me->query("age") < VOTE_AGE_LIMIT) 
				return notify_fail("�����䲻��%d�꣬û��ͶƱȨ��", VOTE_AGE_LIMIT);

			if (me->query("level") < VOTE_LEVEL_LIMIT) 
				return notify_fail("��ȼ�����%d����û��ͶƱȨ��", VOTE_LEVEL_LIMIT);
		}

		const char * choicename = (strcmp(arg, "open")== 0 ? "��":"�ر�");
    
		if(strcmp(channel, "chat") != 0 && strcmp(channel, "party") != 0
			&& strcmp(channel, "new") != 0)
			return notify_fail("����%s%s���Ƶ����", choicename, channel);

		CUser * player;
		if (! (player = find_player(target))) 
			return notify_fail("Ŀǰ�Ҳ�������ˡ�");

		char myvariable[80];
		const char * myid = me->id(1);

		snprintf(myvariable, 80, "%s_%s_%s", arg, channel, player->id(1)); // for checking double votes.
    
		char block_key[20];
		
		snprintf(block_key, 20, "chblk/%s", channel);

		if( strcmp(arg, "close") == 0)
		{			
		   if (current_time < player->query(block_key))
				return notify_fail("%s�Ľ�̸Ƶ���Ѿ����ر��ˡ�", player->name());
		}
		else 
		{
			if (current_time > player->query(block_key))
				return notify_fail("%s�Ľ�̸Ƶ���Ѿ������ˡ�", player->name());
		}
		
		voted_player.copyMapping(g_Channel.voted_players.querymap(myvariable));

		if (! voted_player.undefinedp(myid)) 
			return notify_fail("���Ѿ�Ͷ����ͬ��Ʊ�ˡ�");
		else 
		{
			CMapping m;

			m.set("obj", me->object_id());
			m.set("ip", GetIP(me));
			voted_player.set(myid, m);
		}

		int total_votes_required = determine_total();
		int votes_count = counting(&voted_player, myvariable);

		g_Channel.voted_players.set(myvariable, voted_player);

        // remove vote in 5 min if not enough people respond
		
        if( g_Channel.votes_casted.undefinedp(myvariable))
        {
            g_Channel.votes_casted.set(myvariable, 1);

			//ȡ������
			vote_id++;
			g_Channel.set(snprintf(msg, 80, "cancel_vote%ld/myvariable", vote_id), myvariable);
			g_Channel.set(snprintf(msg, 80, "cancel_vote%ld/choicename", vote_id), choicename);
			g_Channel.set(snprintf(msg, 80, "cancel_vote%ld/playername", vote_id), player->name(1));
			g_Channel.call_out(nullify_vote, 600, vote_id);
        }

        int diff = total_votes_required - votes_count;
		
        // announce to mu
		MAP2USER * ulist = users();
		const char * ch_channel = "����";

		if(strcmp(channel, "new") == 0)
			ch_channel = "����";
		if(strcmp(channel, "party") == 0)
			ch_channel = "����";

        if (diff>0)
		{
			Message("vote", snprintf(msg, 255, "$BLK�������%s(%s)ͶƱ%s%s(%s)��%sƵ������Ҫ%dƱͨ��������%dƱ��$COM",
				me->name(1), me->id(1), choicename, player->name(1), player->id(1),
				ch_channel,
				total_votes_required, diff), ulist);
		}
        else
        {
			if (strcmp(arg, "open") == 0) 
				player->del(block_key);
			else 
				player->set(block_key, current_time + 86400);
       
			// block for 1 day.
			g_Channel.voted_players.del(myvariable);
			g_Channel.votes_casted.del(myvariable);
			Message("vote", snprintf(msg, 255, "$HIW�������%s(%s)ͶƱ%s%s(%s)��%sƵ����%s�Ľ�̸Ƶ����%s�ˣ�$COM", 
				me->name(1), me->id(1), choicename, player->name(1), player->id(1),
				ch_channel,				
				player->name(1), choicename), ulist);
		}

		return 1;
	}

	static int determine_total()
	{
		int total_required = 0;
		CMapping site;
		const char * ip;

		// to determine how many votes necessary to block channel

		MAP2USER * ulist = users();
		iterator_user p;

		for(p = ulist->begin(); p != ulist->end(); p++)
		{
			if ((p->second)->query("age") > VOTE_AGE_LIMIT && 
				(p->second)->query("level") > VOTE_LEVEL_LIMIT ) 
			{
				ip = GetIP(p->second);
				site.add(ip, 1);
			
    			//ÿ��IPֻ��һƱ
				if(site.query(ip) <= 1) 
					total_required++;
			}
		}

		total_required = total_required / 3;
		if (total_required < 3) total_required=3;
		if (total_required > 20) total_required = 20;
		return total_required;
	}

	static int counting(CMapping * players, const char * myvariable) 
	{
		CMapping site;
		const char * ip;
		int count = 0;
    
		CVector v;

		players->keys(v);

		for(int i=0; i<v.count(); i++)
		{
			CMapping * m = players->querymap(v[i]);
			if(! m) continue;

			CUser * obj = find_player(m->query("obj"));

			if(! obj)// this player has logged out.
			{ 
				players->del(v[i]);
				continue;
			}
   
			ip = GetIP(obj);
			site.add(ip, 1);			
	
			// each site can count to max_voter.
			if(site.query(ip) <= 1) 
				count++;
		}    
		
		return count;
	}

	static void nullify_vote(CContainer * ob, LONG vote_id, LONG param2)
	{
		char msg[80];
		const char * myvariable = g_Channel.querystr(snprintf(msg, 80, "cancel_vote%ld/myvariable", vote_id));
		const char * choice = g_Channel.querystr(snprintf(msg, 80, "cancel_vote%ld/choicename", vote_id));
		const char * playername = g_Channel.querystr(snprintf(msg, 80, "cancel_vote%ld/playername", vote_id));

		if (! g_Channel.voted_players.undefinedp(myvariable)) 
		{
			Message("vote", snprintf(msg, 255, "$HIW���������Ϊû���㹻������Ӧ%s%s�Ľ�̸Ƶ����ͶƱȡ���ˣ�$COM", 
				choice, playername), users());

			g_Channel.voted_players.del(myvariable);
			g_Channel.votes_casted.del(myvariable);
		}
	}	

	//��ѯĳ����Ƿ�����
	DEFINECMD(IfOnline)
	{
		CUser * obj;
		char msg[255];
		
		obj = find_online(snprintf(msg, 40, "%ld", target)); 
					
		if(obj && ! obj->query_temp("net_dead"))
		{
			snprintf(msg, 255, "&C=%d&O=1&U=%ld&N=%s&I=%s&L=%ld&R=%ld&rank=%s&", 
				SENDUSER, obj->object_id(), obj->name(), 
				obj->querystr("id"),
				obj->query("level"), obj->query("repute"),
				query_rank(obj));			
		}
		else
		{
			snprintf(msg, 80, "&C=%d&O=0&U=%ld&I=%ld&", 
				SENDUSER, 0, target);
		}

		me->SendCommand(msg, 1);
		return 1;
	}

	DEFINECMD(RefuseTell)
	{
		char key[80]; 
		CUser * player;

		if(target)
		{
			char msg[80];
			if (! (player = find_player(target))) 
				return notify_fail("Ŀǰ�Ҳ�������ˡ�");
				
		
			snprintf(key, 80, "notell/%s", player->querystr("id"));			
			tell_object(me, snprintf(msg, 80, "��ܾ�����%s�����Ļ���", player->name()));
		}
		else
		{
			strcpy(key, "notell/all");
			tell_object(me, "��ܾ����������˵����Ļ���");
		}
		 
		me->set_temp(key, 1);
		return 1;
	}

	//����
	DEFINECMD(Listen)
	{
		char key[80];
		CUser * player;

		if(target)
		{
			char msg[80];
			if (! (player = find_player(target))) 
				return notify_fail("Ŀǰ�Ҳ�������ˡ�");
				
			snprintf(key, 80, "notell/%s", player->querystr("id"));
			me->delete_temp(key);
			me->delete_temp("notell/all");
			tell_object(me, snprintf(msg, 80, "�㿪ʼ����%s�����Ļ���", player->name()));
		}
		else
		{
			me->delete_temp("notell");
			tell_object(me, "�㿪ʼ���������˵����Ļ���");
		}

		return 1;
	}

	//����º�
	DEFINECMD(NickName)
	{
		char msg[80];
		int len = strlen(arg);
		if(len < 1 || len > 20)
			return notify_fail("���������Ĵºţ�");

		const char * ptr;

		ptr = check_legal_name(arg);
		if(ptr[0])
			return notify_fail(ptr);
		
		me->set("nickname", arg);
		tell_object(me, snprintf(msg, 80, "��ı�º�Ϊ��%s����", arg));
		return 1;
	}

	//��������
	DEFINECMD(Pary)
	{
		//��ֹ������Ϊno_invite�ĳ���ʹ��Talk���� �ز� 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_invite")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹ�������ˡ�");

		CChar * who;
		char msg[80];

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("��Ҫ����˭������Ķ��飿");

		if(who == me)
			return notify_fail("����Լ�˵�����˻����Լ������Լ��ɡ�");

		if(me->querystr_temp("pary/master")[0])
			return notify_fail("��������������˶����У�Ҫ���Լ��齨������Ҫ������ӡ�");

		if(me->query_temp("pary/number")>4)
			return notify_fail("�Ѿ���������ô��Ķ��ѣ��㹻���������˰ɣ�");

		if(EQUALSTR(who->querystr_temp("pary/master"), me->querystr("id")))
			return notify_fail("�Է��Ѿ�������������롣");

		message_vision("$HIC$N����Ķ�$n˵�����ѣ�һ��������߽�����", me, who);
		me->set_temp("pary/pary", who->querystr("id"));

		//���Ӳ˵�ָ�� lanwood 2001-03-23 ע�⣬�˴�������$1�����Լ�����Ϊ�Է�δ��ѡ�е����㡣
		char tmp[40];

		me->AddMenuItem(snprintf(msg, 80, "����%s���������", me->name()), 
			snprintf(tmp, 40, "$0accept_pary %ld", me->object_id()), who);

		me->AddMenuItem("�ܾ��������", "", who);
		me->SendMenu(who);

		return 1;
	}

	//�����������
	DEFINECMD(Accept_pary)
	{
		CChar * who;
		char msg[40];

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("��Ҫ����˭�����룿");
		
		if(who == me)
			return notify_fail("����Լ�˵�����˻����Լ������Լ��ɡ�");

		if(me->querystr_temp("pary/master")[0])
			return notify_fail("�������Ѿ��ͱ�����ӹ��ˡ�");

		if(DIFFERSTR(who->querystr_temp("pary/pary"), me->querystr("id")))
			return notify_fail("�Է���û�������㡣");

		if(me->querystr_temp("pary/pary")[0])
			return notify_fail("���Ѿ��������˷�����������룬��ʱ���ܽ��ܱ��˵�������롣");

		message_vision("$HIC$N������$n��������롣", me, who);
		me->set_temp("pary/master", who->querystr("id"));
		me->set_leader(who);
		who->delete_temp("pary/pary");
		who->add_temp("pary/number",1);
		who->set_temp(snprintf(msg, 40,"pary/friend_%s",me->querystr("id")),1);

		who->say("�������������롣", me);
		who->SendMenu(me);

		return 1;
	}

	//�뿪����
	DEFINECMD(Paryleave)
	{
		CChar * who;
		char msg[255];

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("��Ҫ�����˭����ӹ�ϵ��");
		
		if(who == me)
			return notify_fail("���������󲻺��ʰɣ�");

		if(DIFFERSTR(me->querystr_temp("pary/master"), who->querystr("id")))
			return notify_fail("�㲢û�кͶԷ���ӡ�");

		if(!who->query_temp(snprintf(msg, 255,"pary/friend_%s",me->querystr("id"))))
		{
			me->delete_temp("pary/master");
			return notify_fail("�Է���û��������ӣ����Ѿ�����ϳ��˶��顣");
		}

		message_vision("$HIC$Nȡ����$n����ӡ�", me, who);
		tell_object(who, snprintf(msg, 255, "$HIR%s(%s)ȡ�����������ӡ�",me->name(),me->id()));
		me->delete_temp("pary/master");
		me->set_leader(me);
		who->add_temp("pary/number",-1);
		who->delete_temp(snprintf(msg, 255,"pary/friend_%s",me->querystr("id")));

		me->say(snprintf(msg, 255,"��ȡ������%s����ӡ�",who->name()),me);
		who->SendMenu(me);

		return 1;
	}

	//�߳�����
	DEFINECMD(Parykick)
	{
		CChar * who;
		char msg[255];

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("��Ҫ�����˭����ӹ�ϵ��");
		
		if(who == me)
			return notify_fail("���������󲻺��ʰɣ�");

		if(DIFFERSTR(who->querystr_temp("pary/master"), me->querystr("id")))
		{
			me->add_temp("pary/number",-1);
			me->delete_temp(snprintf(msg, 255,"pary/friend_%s",who->querystr("id")));
			return notify_fail("�Է���û��������ӣ����Ѿ��Լ��뿪�˶��顣");
		}

		if(who->query_temp(snprintf(msg, 255,"pary/friend_%s",who->querystr("id"))))
			return notify_fail("�㲢û�кͶԷ���ӡ�");

		message_vision("$HIC$Nȡ����$n����ӡ�", me, who);
		tell_object(who, snprintf(msg, 255, "$HIR%s(%s)ȡ�����������ӡ�",me->name(),me->id()));
		who->delete_temp("pary/master");
		who->set_leader(who);
		me->add_temp("pary/number",-1);
		me->delete_temp(snprintf(msg, 255,"pary/friend_%s",who->querystr("id")));

		who->say(snprintf(msg, 255,"��ȡ������%s����ӡ�",who->name()),me);
		who->SendMenu(me);

		return 1;
	}

	//�鿴�Է�����
	DEFINECMD(ListGoods)
	{
		CChar * who;
		char msg[255], cmd[40];

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("��Ҫ�鿴˭�Ļ��");
		
		if(who == me)
			return notify_fail("���ú춥���˵��߲鿴��");

		DTItemList * list = who->Get_ItemList();
		POSITION p = list->GetHeadPosition();
		int i = 0;
		
		while(p)
		{
			CContainer * obj = list->GetNext(p);
			LONG val = obj->query_temp("trade/value");

			if(! val) continue;
			if(DIFFERSTR(obj->querystr_temp("trade/owner"), who->id(1)) ) continue;

			snprintf(msg, 255, "%s ��%ld", obj->name(), val);
			who->AddMenuItem(msg, snprintf(cmd, 40, "$0buy $1 %ld", obj->object_id()), me);
			i++;
		}

		if(! i)
			who->say(snprintf(msg, 255, "���%s����Ʒ�ƺ�������Ȥ��", who->name()), me);

		who->SendMenu(me);
		return 1;
	}

	//����Է��Ļ���
	DEFINECMD(Buy)
	{
		CChar * who;
		char msg[255];
		LONG val = 0;

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("��Ҫ��˭�Ļ��");
		
		if(who == me)
			return notify_fail("�ǻ�������");

		CContainer * obj = who->Present(atol(arg));

		if(! obj || obj->querystr("owner")[0] || DIFFERSTR(obj->querystr_temp("trade/owner"), who->id(1))
			|| ! (val = obj->query_temp("trade/value")) )
			return notify_fail("�Է������������㡣");

		if(! CMoney::Player_Pay(me, val))
			return notify_fail("�������%s�����������ڴ���ֻ��������뿪�ˡ�", obj->name());

		message_vision(snprintf(msg, 255, "$N��$n����������%s������$n����%ld�Ľ�ҡ�", obj->name(), val), me, who);		

		if(! obj->move(me))
		{
			obj->move(me->environment());
			tell_object(me, snprintf(msg, 255, "��������%s�������ò�����ֻ�ð������ڵ��ϡ�", obj->name()));
		}
		
		CMoney::Pay_Player(who, val);

		return 1;
	}

	//�������������Լ���
	DEFINECMD(invite)
	{
		//��ֹ������Ϊno_invite�ĳ���ʹ��Talk���� �ز� 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_invite")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("�����ֹ�������ˡ�");

		CChar * who;
		char msg[80];

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("��Ҫ����˭ȥ��ļ����ͣ�");

		if(! me->querystr("resident")[0])
			return notify_fail("�㻹û�ж��ӣ���ô�����˼ң�");

		if(who == me)
			return notify_fail("����Լ�˵�����˻����Լ������Լ��ɡ�");

		if(EQUALSTR(who->querystr_temp("invite"), me->querystr("id")))
			return notify_fail("�Է��Ѿ�������������롣");

		message_vision("$HIC$N����Ķ�$n˵���뵽�Ҽ�����ɣ�", me, who);
		me->set_temp("pending/invite", who->querystr("id"));

		//���Ӳ˵�ָ�� lanwood 2001-03-23 ע�⣬�˴�������$1�����Լ�����Ϊ�Է�δ��ѡ�е����㡣
		char tmp[40];

		me->AddMenuItem(snprintf(msg, 80, "����%s������", me->name()), 
			snprintf(tmp, 40, "$0accept %ld", me->object_id()), who);

		me->AddMenuItem("�ܾ�����", "", who);
		me->SendMenu(who);

		return 1;
	}

	//��������
	DEFINECMD(accept)
	{
		CChar * who;

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("��Ҫ����˭�����룿");
		
		if(who == me)
			return notify_fail("����Լ�˵�����˻����Լ������Լ��ɡ�");

		if(EQUALSTR(me->querystr_temp("invite"), who->querystr("id")))
			return notify_fail("���Ѿ������˶Է������롣");

		if(DIFFERSTR(who->querystr_temp("pending/invite"), me->querystr("id")))
			return notify_fail("�Է���û�������㡣");

		message_vision("$HIC$N������$n�����롣", me, who);
		me->set_temp("invite", who->querystr("id"));
		who->delete_temp("pending/invite");

		who->say("����������롣", me);
		who->SendMenu(me);

		return 1;
	}

	//ˢ�������ͽ����
	DEFINECMD(RecruitExp)
	{
		LONG recruit_exp = 0;
		char msg[255];

		const char * master = me->id(1);

		if(wizardp(me))
		{
			CChar * who;

			if(! (who = GetRoomChar(me, target)) 
				&& ! (who = find_player(target)) )
					who = me;
						
			if(strlen(arg)) 
				master =arg;
			else 
				master = who->id(1);
		}
		
		CMapping * ptr = g_Channel.query_recruit(master);

		if(! ptr || ! ptr->GetCount())
			return notify_fail("�㻹û����ͽ���飡");

		tell_object(me, snprintf(msg, 255, "��ǰ����ͽ��%ld����", ptr->GetCount()));

		CVector v;

		ptr->keys(v);

		for(int i=0; i<v.count(); i++)
		{
			CMapping * p = ptr->querymap(v[i]);
			tell_object(me, 
				snprintf(msg, 255, "ͽ��%s(%s)���׾��飺%ld��(%s)",
					p->querystr("name"),
					v[i], 					
					p->query("exp") / 100,
					p->query("apprentice") ? "����" : "----"));

			recruit_exp += (p->query("exp") / 100);
		}
		
		if(recruit_exp > 50)
			me->set("recruit_exp", recruit_exp);
		else
			me->set("recruit_exp", 50);

		me->FlushMyInfo();

		tell_object(me, snprintf(msg, 255, "�����ͽ���鹲��%ld��", recruit_exp));
		return 1;
	}	

	//ͬ��
	DEFINECMD(mv)
	{
		LONG bx, by, ex, ey, ac;
		sscanf(arg, "%ld %ld %ld %ld %ld", &bx, &by, &ex, &ey, &ac);

		//��Ҷ�λ
		me->set_temp("map/bx", bx);
		me->set_temp("map/by", by);
		me->set_temp("map/ex", ex);
		me->set_temp("map/ey", ey);
		me->set_temp("map/ac", ac);

		//�򷿼���������ҷ�����Ϣ
		DTItemList * t = (me->environment())->Get_ItemList();
		POSITION p = t->GetHeadPosition();
		CContainer * obj;

		while(p)
		{
			obj = t->GetNext(p);
			if(obj == me) continue;
			if(userp(obj))		//�����
				((CUser *)obj)->LocationObject(me);
		}

		return 1;	
	}

	//Loading ��������ʼ��λ loc 0 x y
	DEFINECMD(loc)
	{
		LONG x, y;
		
		if(! userp(me)) return 0;

		//if(! me->is_loading())
		//	return notify_fail("�㲢û��װ�ص�ͼ��");

		sscanf(arg, "%ld %ld", &x, &y);
		me->set_temp("map/bx", x);
		me->set_temp("map/by", y);
		me->set_temp("map/ex", x);
		me->set_temp("map/ey", y);
		me->set_temp("map/ac", 0l);
		
		me->delete_temp("client/loading");

		(me->environment())->OnEnter(me);			//��ʽ�����ͼ
		
		((CUser * )me)->LocationObject(me);

		return 1;
	}	

	//----------------------1.71��-------lanwood 2001-03-25 --------------------------
	//���Ӻ���
	DEFINECMD(addfriend)
	{
		CChar * who;
		
		notify_fail("Ŀ�겻���ڣ�");

		if(! strlen(arg))
		{
			if( ! (who = find_player(target)) )
				return 0;
		}
		else if( !(who = find_online(arg)) )
				return 0;

		if(((CUser *)me)->SetFriend(who->id(1), 1))
		{
			//֪ͨ�ͻ���
			((CUser *)me)->notify_online(who);
			return 1;
		}

		return 0;
	}

	//ɾ������
	DEFINECMD(remfriend)
	{
		notify_fail("��Ŀ���Ѳ�����������С�");
		return ((CUser *)me)->SetFriend(arg, 0);
	}

	//��ʾ��������б� who 0 1 1��ҳ�� ��0��ʼ ��������Ʒ��Ϣ
	//ÿҳ��ʾ10��
	DEFINECMD(who)
	{
		char type[20];
		analyse_string(arg, type, 20);
		int nBegin = atol(arg) * 12;		
		((CUser *)me)->SendUserOnline(nBegin, nBegin + 12, atol(type));
		return 1;
	}

	//�����û���ϸ����
	DEFINECMD(downloaduser)
	{
		CUser * who = find_player(target);
		if(! who) return 0;

		((CUser *)me)->ReceiveUserInfo(who);
		return 1;
	}

	//�ܾ�����ĳƵ����Ϣ
	DEFINECMD(refuse)
	{
		CMapping m;
		char msg[80];

		m.set("practice", 1);
		m.set("study", 1);
		m.set("exercise", 1);
		m.set("combat", 1);

		if(! strlen(arg))
		{
			CMapping * ch = me->querymap_temp("refuse");
			if(! ch) return notify_fail("��Ŀǰû�������κ���Ϣͨ����");	

			tell_object(me, "��Ŀǰ�Ѿ��رյ���Ϣͨ���У�");

			CVector v;

			ch->keys(v);
			for(int i=0; i<v.count(); i++)
				tell_object(me, snprintf(msg, 80, "%sͨ��", v[i]));
			
			return 1;
		}

		//������ͨ��
		if(strcmp(arg, "none") == 0)
		{
			me->delete_temp("refuse");
			tell_object(me, "��Ϣͨ���ָ�������");
			return 1;
		}

		if(! m.query(arg))
			return notify_fail("������رո���Ϣͨ����");

		me->set_temp(snprintf(msg, 80, "refuse/%s", arg), 1);
		tell_object(me, snprintf(msg, 80, "OK���ر���%s����Ϣͨ����", arg));
		return 1;
	}
	
};
