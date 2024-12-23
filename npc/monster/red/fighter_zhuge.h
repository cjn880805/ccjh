
NPC_BEGIN(CNfighter_zhuge);

void create()
{
	set_name("���С��", "zhu ge");

	set("title", "��̨��������");
	set("icon", 34);
	set("gender", "����" );
	set("age", 88);
	set("per",36);

	set("chname", "������̨");
	set("channel", "f1");

	set("chat_chance", 2);

	set("grant", 80);
	
	set("combat_exp", 150000000);
	set("attitude", "friendly");
	
	set("biwu/name", "������̨��");
	set("biwu/register/0", "��ȱ");
	set("biwu/turn0/0", "0");

	set("wait_time",2);
	set("count",100);

	set("��̨/��������","��ɽ��");
	set("��̨/��������","�������");
	set("��̨/����ID","wiz");

	set("file_name", querystr("base_name"));

	Load();

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

char * chat_msg()
{
	if(query("count") && !random(10))
	{
		char msg[255];
		switch(random(8))
		{
		case 0:
			command("wiz 0 �����ˣ������£�������Թ��𽭺��ˡ�\n");
			break;
		case 1:
			if(query("��̨/count"))
				command(snprintf(msg, 255,"wiz 0 ȭ����ɽ�ͻ������߱���������������̨��һ�ˣ�Ψ��%s��%s(%s)��Ҳ��\n",querystr("��̨/��������"),	querystr("��̨/��������"),querystr("��̨/����ID")));
			break;
		case 2:
			command("wiz 0 ʮ��ĥһ����ҹҹ�����졣��̤����֮·,�����������\n");
			break;
		case 3:
			command("wiz 0 Ǧ����ȥ���������ɡ���̤��������·��\n");
			break;
		case 4:
			command("wiz 0 �ݺὭ���ľ��Σ�������֡���\n");
			break;
		case 5:
			command("wiz 0 ʮ��ɱһ�ˣ�ǧ�ﲻ���У����Ͻ�����Թ������������𡭡�\n");
			break;
		case 6:
			command(snprintf(msg, 255,"wiz 0 ������̨���Ѿ�������%d���������������ս��ʣ%d��������\n",	query("��̨/count"),query("count")-query("��̨/count")));
			break;
		case 7:
			command(snprintf(msg, 255,"wiz 0 ������̨�����������ɻ�ý�Ʒ��%s��һ�ݡ�",check_jp()));
			break;
		}
	}
	return "";
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(query("count"))
	{
		char msg[255];
		if(! strlen(ask))
		{
			AddMenuItem("�鿴��ǰ���", "1", me);
			AddMenuItem("ѯ�ʱ�������", "tiaojian", me);
			AddMenuItem("�鿴��Ʒ", "jiangpin", me);
			if(me->query("zhang/����") && check(me))
				AddMenuItem("��Ҫ����", "register", me);
			AddMenuItem("��ȡս��", "zhanbao", me);
			AddMenuItem("��ѯ�������", "$0baoming $1", me);
		}
		else if(strcmp(ask, "1") == 0)
		{
			say(snprintf(msg, 255,"������̨���Ѿ�������%d���������������ս��ʣ%d��������",	query("��̨/count"),query("count")-query("��̨/count")) ,me);
			say(snprintf(msg, 255,"��ǰ��̨��������%s��%s(%s)���Ѿ��������޳ɹ�%d����",
				querystr("��̨/��������"),	querystr("��̨/��������"),querystr("��̨/����ID"),query("��̨/����������")) ,me);
		}		
		else if(strcmp(ask, "tiaojian") == 0)
			say(check_say(),me);

		else if(strcmp(ask, "jiangpin") == 0)
			say(snprintf(msg, 255,"������̨�����������ɻ�ý�Ʒ��%s��һ�ݡ�",check_jp()), me);

		else if(strcmp(ask, "register") == 0)
			return register_me(me);		//��Ҫ����

		else if(strcmp(ask, "zhanbao") == 0)
			return ask_zhanbao(me);
		
		SendMenu(me);
	}
	return 1;
}

//��⵱ǰ�������Ƿ���ϱ�������
int check(CChar * me)
{
	switch(query("����"))
	{
	//��һ��
	case 0://60�����¿��Բ���
		if(me->query("level")>60)	return 0;
		break;
	case 1://60-100�����Բ���
		if(me->query("level")>100 || me->query("level")<60)	return 0;
		break;
	case 2://100�����Ͽ��Բ���
		if(me->query("level")<100)	return 0;
		break;
	case 3://25�����¿��Բ���
		if(me->query("age")>25)	return 0;
		break;
	case 4://25-60�����¿��Բ���
		if(me->query("age")>60 || me->query("age")<25)	return 0;
		break;
	case 5://60�����Ͽ��Բ���
		if(me->query("age")<60)	return 0;
		break;
	case 6://�к�֮ս
		if(EQUALSTR(me->querystr("gender"), "Ů��"))	return 0;
		break;
	case 7://Ů��֮ս
		if(DIFFERSTR(me->querystr("gender"), "Ů��"))	return 0;
		break;
	case 8://�ܾ���50�����¿��Բ���
		if(me->query("combat_exp")>500000)	return 0;
		break;
	case 9://�ܾ���50-500�����¿��Բ���
		if(me->query("combat_exp")>5000000 || me->query("combat_exp")<500000)	return 0;
		break;
	case 10://�ܾ���500-1500�����¿��Բ���
		if(me->query("combat_exp")>15000000 || me->query("combat_exp")<5000000)	return 0;
		break;
	case 11://�ܾ���1500�����Ͽ��Բ���
		if(me->query("combat_exp")<15000000)	return 0;
		break;
	case 12://�޼����ս
		break;
	}
	return 1;	
}

char * check_say()
{
	switch(query("����"))
	{
	case 0:
		return "60�����µ�ID���ɲμӱ�����̨������";
	case 1:
		return "60��-100��֮���ID���ɲμӱ�����̨������";
	case 2:
		return "100�����ϵ�ID���ɲμӱ�����̨������";
	case 3:
		return "25�����µ�ID���ɲμӱ�����̨������";
	case 4:
		return "25��-60��֮���ID���ɲμӱ�����̨������";
	case 5:
		return "60�����ϵ�ID���ɲμӱ�����̨������";
	case 6:
		return "����ֻ�����Ժ͹����ǵ�ID���ɲμӱ�����̨������";
	case 7:
		return "����ֻ��Ů�Ե�ID���ɲμӱ�����̨������";
	case 8:
		return "�ܾ���50�����µ�ID���ɲμӱ�����̨������";
	case 9:
		return "�ܾ���50��-500��֮���ID���ɲμӱ�����̨������";
	case 10:
		return "�ܾ���500��-1500��֮���ID���ɲμӱ�����̨������";
	case 11:
		return "�ܾ���1500�����ϵ�ID���ɲμӱ�����̨������";
	case 12:
		return "��̨�����������¸���Ӣ��֮��ᣬֻҪ���ǽ������ˣ�����Ϊ��Ӣ�ۺú��������ʸ����μӡ�";
	}
	return "";
}

char * check_jp()
{
	switch(query("����"))
	{
	case 0:
		set("��Ʒ","38huoqiang");
		return "�����˻�ǹ";
	case 1:
		set("��Ʒ","zidiaopifeng");
		return "��������";
	case 2:
		set("��Ʒ","haoseshan");
		return "���Ӻ�ɫ����";
	case 3:
		set("��Ʒ","ruanweijia");
		return "������⬼�";
	case 4:
		set("��Ʒ","xuantiebishou");
		return "����ذ��";
	case 5:
		set("��Ʒ","xuanwupao");
		return "�������";
	case 6:
		set("��Ʒ","newyear1");
		return "���̴���";
	case 7:
		set("��Ʒ","newyear");
		return "�������";
	case 8:
		set("��Ʒ","xuanwupao");
		return "��ͷ��";
	case 9:
		set("��Ʒ","kuihuaao");
		return "����С��";
	case 10:
		set("��Ʒ","xuanwupao");
		return "�������";
	case 11:
		set("��Ʒ","zwsword");
		return "���佣";
	case 12:
		set("��Ʒ","yinguozhu");
		return "�������";
	}
	return "";
}

//��ȡս��
int ask_zhanbao(CChar * me)
{
	char msg[255];
	CContainer * obj = load_item("wiz_leitaizhanbao");
	obj->set_name(snprintf(msg, 255, "%sս��", querystr("biwu/name")), "zhan bao");
	
	obj->move(me);
	obj->set("biwu", object_id());
	
	tell_object(me, snprintf(msg, 255, "$YEL����һ��%s������������ʱ���ı�����̨�����ı���ʵ����", obj->name(1)));
	
	return 1;
}

//��������
int register_me(CChar * me)
{
	//���ﻹ��Ҫ����һ�����жϣ���ֹ�������ô���֮���ID�μӱ���
	if(!me->query_temp("��̨/lost"))
	{
		char msg[255];
		if(has_register(me))
		{			
			command(snprintf(msg, 255, "wiz 0 ��%s��%s(%s) �Ѿ����ϡ�������̨������������Ӣ��ǰ����ս��\n", me->querystr("family/family_name"),me->name(1),me->id(1)));
			say("���ѻ����̨�����ʸ������ĵȴ��������ѵ���ս��������Ҫ���������ǣ����������߻�ս�ܣ�������������ȡ�����֮��", me);
			set("��̨/��������",me->querystr("family/family_name"));
			set("��̨/��������",me->name(1));
			set("��̨/����ID",me->id(1));
		}
		else
		{
			say(snprintf(msg, 255,"��ǰ��̨��������%s��%s(%s)���Ѿ��������޳ɹ�%d����",
				querystr("��̨/��������"),	querystr("��̨/��������"),querystr("��̨/����ID"),query("��̨/����������")) ,me);
			AddMenuItem("������ս", "$0tiaozhan $1", me);
			AddMenuItem("�Ǿ�����", "", me);
			SendMenu(me);
			return 1;
		}
	}
	else
	{
		say("�����롾������̨����̨��ʧ�ܣ������½�����Ϸǰ�����Ѿ�ʧȥ���ٴβμ���̨�����ʸ�", me);
	}
	SendMenu(me);
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	char msg[255],msg1[255];
	if(!strcmp(comm, "kill") || !strcmp(comm, "fight")	|| !strcmp(comm, "cast") )
	{
		message_vision("$n��$N������ü��", me, this);
		return 1;
	}
	if(!strcmp(comm, "baoming") && query("count") )
	{
		if(query_temp("����/��ս����")<=query_temp("����/����"))
		{
			tell_object(me,"---------------------------�Ǽ���ս���--------------------------------");
			for(int i=query_temp("����/��ս����");i<=query_temp("����/����");i++)
			{
				//��ʾ����������
				tell_object(me,snprintf(msg, 255,"��%d���Ǽ���ս���ID:    %s  ",i, querystr_temp(snprintf(msg1, 255,"�Ǽ�/%d",i))));
			}
			tell_object(me,"-----------------------------------------------------------------------");
		}
		else
		{
			tell_object(me,"��ǰ���˱����Ǽ���ս");
		}
		return 1;
	}
	else if(!strcmp(comm, "tiaozhan") && query("count") && check(me) && me->query("zhang/����"))
	{
		if(!query_temp("��̨/��ս"))
		{
			if(EQUALSTR(me->id(1),querystr("��̨/����ID")))//����������ս�Լ�������
			{
				tell_object(me,"���С������������ü����������û�£��Լ�����ս�Լ�����" );
				return 1;
			}
			else
			{
				add_temp("����/��ս����",1);
				add_temp("����/����",1);
				set_temp("��̨/��ս",atoi(me->id(1)));
				defy(me);
			}
		}
		else if(EQUALSTR(me->id(1),querystr("��̨/����ID")) || query_temp(snprintf(msg, 255,"����/%s",me->id(1))))//������ս�󲻵��ٴ�ѡ����ս
		{
			tell_object(me,"���С������˵�������Ѿ������Ǽǹ��ˣ��㻹��ץ��ʱ��ȥ��Щ׼�������ɣ���");
		}
		else
		{
			add_temp("����/����",1);
			set_temp(snprintf(msg, 255,"����/%s",me->id(1)),1);
			set_temp(snprintf(msg, 255,"�Ǽ�/%d",query_temp("����/����")),me->id(1));
			tell_object(me,"���С������˵�����Ѿ�����Ǽ��ˣ����������Ѿ��ڽ�����ս���㻹�ǵ�һ�°ɣ�");
		}
/*		else if(query_temp("��̨/��ս")==atoi(me->id(1)))//������ս�󲻵��ٴ�ѡ����ս
		{
			tell_object(me,"���С������˵�������Ѿ�����ս״̬�ˣ��㻹��ץ��ʱ��ȥ��Щ׼�������ɣ���");
		}
		else
		{
			tell_object(me,"���С������˵�����Ѿ������ڽ�����ս���㻹�ǵ�һ��ɣ�");
		}
*/		return 1;
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
	else if(strcmp(comm, "chaxun") == 0)
	{
		say(snprintf(msg, 255,"������̨���Ѿ�������%d���������������ս��ʣ%d��������",	query("��̨/count"),query("count")-query("��̨/count")) ,me);
		say(snprintf(msg, 255,"��ǰ��̨��������%s��%s(%s)���Ѿ��������޳ɹ�%d����",
			querystr("��̨/��������"),	querystr("��̨/��������"),querystr("��̨/����ID"),query("��̨/����������")) ,me);
		SendMenu(me);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}

//����ע��
int has_register(CChar * me)
{
	if(!atoi(querystr("��̨/����ID")))
		return 1;
	return 0;
}

//��ս
void defy(CChar * me)
{
	char msg[255];
	CUser * player;
	player=find_online(querystr("��̨/����ID"));
	if(!player)
	{
		//����ս�߲�����ֱ���滻
		set("��̨/��������",me->querystr("family/family_name"));
		set("��̨/��������",me->name(1));
		set("��̨/����ID",me->id(1));
		del("��̨/����������");
		command(snprintf(msg, 255,"wiz 0 ���ڶ��ֲ����ߣ�%s%s(%s)����ˡ�������̨�������ʸ�\n",me->querystr("family/family_name"),me->name(1),me->id(1)));
		delete_temp("��̨/��ս");
		defy_next();
		Save();
	}
	else
	{
		//3���Ӻ�ս
		snprintf(msg, 255, "\n\n$HIG ��%s�� %s(%s)���ϡ�������̨����ս��%s�� %s(%s)�������ʸ���%s����׼������ս����%d���Ӻ�ʼ��", 
			me->querystr("family/family_name"),me->name(1),me->id(1),
			me->querystr("family/family_name"),player->name(1), player->id(1),
			player->name(1),query("wait_time"));
		tell_object(me, msg);
		tell_object(player, msg);
		do_defy(me,player,query("wait_time"));
	}

}

int do_defy(CChar * me, CChar * who,int wait_time)
{
	char msg[255];

	command(snprintf(msg, 255, "wiz 0 �롾%s��%s(%s) VS ��%s��%s(%s)����׼������������̨����ս������%ld���Ӻ���С�\n", me->querystr("family/family_name"),me->name(1),me->id(1),
		who->querystr("family/family_name"),who->name(1),who->id(1), wait_time));

	if(me && who)
	{		
		snprintf(msg, 255, "$HIG��������̨��%s��%s��׼���ã�", me->name(1), who->name(1) );

		tell_object(me, msg);
		tell_object(who, msg);	
	}
	else
	{
		if(me)
		{
			set("��̨/��������",me->querystr("family/family_name"));
			set("��̨/��������",me->name(1));
			set("��̨/����ID",me->id(1));
			del("��̨/����������");
			command(snprintf(msg, 255,"wiz 0 ���ڶ��ֲ����ߣ�%s%s(%s)����ˡ�������̨�������ʸ�\n",me->querystr("family/family_name"),me->name(1),me->id(1)));	
			delete_temp("��̨/��ս");
			defy_next();
			Save();
		}
		else if(who)
		{
			command(snprintf(msg, 255,"wiz 0 ���ڶ�����;��Ȩ��%s%s(%s)�������֡�������̨�������ʸ�\n",who->querystr("family/family_name"),who->name(1),who->id(1)));	
			delete_temp("��̨/��ս");
			defy_next();
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
	CNfighter_zhuge * npc = (CNfighter_zhuge *)ob;
	
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

	snprintf(msg, 255, "\n$HIR��������̨���������̨��ս������%ld���ӣ�ʱ�䵽�Զ�����ս����������׼����\n", wait_time);

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
		
		me->set_weight(50000000);
		who->set_weight(50000000);

		me->set_temp("no_fei", 1);	//��ֹ����	
		who->set_temp("no_fei", 1);	

		CContainer * env = Do_BiShi(me, who, "��̨��ս��", 0);
		env->set("room_locked", FIGHT_LOCKED);	//ս������.

		//����ս���������
		set_biwu(env);

		CContainer * oldenv = find_object(query_temp("is_boardcast"));
		if(! oldenv) do_snoop(env);
		
		return 1;
	}

	if(me) 
	{
		set("��̨/��������",me->querystr("family/family_name"));
		set("��̨/��������",me->name(1));
		set("��̨/����ID",me->id(1));
		del("��̨/����������");
		command(snprintf(msg, 255,"wiz 0 ���ڶ��ֲ����ߣ�%s%s(%s)����ˡ�������̨�������ʸ�\n",me->querystr("family/family_name"),me->name(1),me->id(1)));	
		delete_temp("��̨/��ս");
		defy_next();
		Save();
	}
	else if(who) 
	{
		command(snprintf(msg, 255,"wiz 0 ���ڶ�����;��Ȩ��%s%s(%s)�������֡�������̨�������ʸ�\n",who->querystr("family/family_name"),who->name(1),who->id(1)));	
		delete_temp("��̨/��ս");
		defy_next();
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


//������������
void is_defeated(CChar * winner, CChar * failer)
{
	if(winner == this || failer == this) return;

	int team = winner->query_temp("biwu/team");

	//�����Ǳ����ʤ�ߵĴ���
	
	winner->delete_temp("biwu");
	failer->delete_temp("biwu");

	winner->revive(1);
	failer->revive(1);
	failer->set_temp("��̨/lost",1);

	winner->delete_temp("no_fei");
	failer->delete_temp("no_fei");	

	full_me(winner);
	full_me(failer);

	winner->set_weight(50000);
	failer->set_weight(50000);

	CContainer * env = winner->environment();
	remove_biwu(env);

	if(env->object_id() == query_temp("is_boardcast"))
		transfer_info();

	register_winner(winner,team,failer);

}

//��ʤ�߻�á�������̨�������ʸ�
void register_winner(CChar * me, int team,CChar * who)
{
	char msg[255];
	if(team==1)	//��ս�߻�ʤ
	{
		set("��̨/��������",me->querystr("family/family_name"));
		set("��̨/��������",me->name(1));
		set("��̨/����ID",me->id(1));
		add("��̨/count",1);
		if(query("��̨/����������")>10)
		{
			//����ԭ������һ������Ʒ
		}
		del("��̨/����������");
		command(snprintf(msg, 255,"wiz 0 ��%s��%s(%s) ��ս�ɹ�������ˡ�������̨�������ʸ�\n",me->querystr("family/family_name"),me->name(1),me->id(1)));	
	}
	else if(team==2)	//������ʤ
	{
		add("��̨/count",1);
		add("��̨/����������",1);
		int repute=100*query("��̨/����������");
		CContainer * RMB=load_item("coin");
		RMB->set_amount(repute);
		if(RMB) RMB->move(me);
		if(me->query("repute")<0)repute=-repute;
		me->add("repute",repute);
		command(snprintf(msg, 255,"wiz 0 ��%s��%s(%s) Ӧս�ɹ����������֡�������̨�������ʸ�ͬʱ�����Ŀ %d �����޲ʽ� ��\n",me->querystr("family/family_name"),me->name(1),me->id(1),repute));	
		
		tell_object(me,snprintf(msg, 255,"$HIR�����޳ɹ�����������������%d�㡣" ,repute));
		me->UpdateMe();
	}
	delete_temp(querystr(snprintf(msg, 255,"����/%s",who->id(1))));//���ʧ���ߵǼǼ�¼
	if(query("��̨/count")==query("count"))
	{
		command(snprintf(msg, 255,"wiz 0 ��������̨��������̨����������%s��%s(%s) ��Ϊ������̨����������ʤ���ߡ�\nӮ����̨����Ʒ��%s��һ�ݡ�\n",me->querystr("family/family_name"),me->name(1),me->id(1),check_jp()));	
		load_item(querystr("��Ʒ"))->move(me);
		del("��̨");
		add("����",1);
		if(query("����")>12)
			del("count");
		delete_temp("��ս");
		delete_temp("����");
		delete_temp("defy");
		delete_temp("��̨");
		delete_temp("�Ǽ�");
	}
	else
	{
		//������ս
		defy_next();
	}
	Save();
}

void defy_next()
{
	add_temp("����/��ս����",1);
	if(query_temp("����/��ս����")<=query_temp("����/����"))
	{
		CUser * player;
		char msg[255];
		player=find_online(querystr_temp(snprintf(msg, 255,"�Ǽ�/%d",query_temp("����/��ս����"))));
		if(player)
		{
			set_temp("��̨/��ս",atoi(querystr_temp(snprintf(msg, 255,"�Ǽ�/%d",query_temp("����/��ս����")))));
			defy(player);
		}
		else
			defy_next();
	}
	else
	{
		delete_temp("��̨/��ս");
	}
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




