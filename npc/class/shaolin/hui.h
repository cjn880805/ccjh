//hui.h
//���ֻ��ֱ�
//Lanwood 2000-01-09

#define SHAOLINHUI_BEGIN(npc_name) class npc_name : public CNshaolin_hui	{	public:	npc_name(){};	virtual ~npc_name(){};
#define SHAOLINHUI_END		};	

NPC_BEGIN(CNshaolin_hui);

virtual int accept_object(CChar * who, CContainer * obj)
{
	if ( who->query_temp("have_letter") && who->present("tuijian xin3") ) 
	{
		say("�������������ҵ��Ƽ���ȥ��ʦ���� ?", who);
		SendMenu(who);
		return 0;
	}

	if((EQUALSTR(obj->querystr("id"), "damo ling"))
		&& who->query("family/generation") == query("family/generation") + 1
		&& ! who->query_temp("have_letter") ) 
	{
		who->set_temp("fight_ok",1);
		destruct(obj);
	    say("�ã���Ȼ�ѵõ�������ɣ����Ǿ�����֤һ���书��", who);
		AddMenuItem("��ʼ����", "$0bishi $1", who);
		AddMenuItem("ת���뿪", "", who);
		SendMenu(who);
		return 1;
	}
        
	if (EQUALSTR(obj->querystr("id"), "tuijian xin2" )
		&& who->query_temp("have_letter") )
	{
		who->set_temp("apprentice_ok",1);
		destruct(obj);

	    say("�ã���Ը�����Ϊʦ��", who);
		AddMenuItem("��Ը��", "$0apprentice $1", who);
		AddMenuItem("�Ҳ�Ը��", "", who);
		SendMenu(who);
		return 1;
	}

    say(g_Channel.do_emote(this, 0, "smile", 1), who);
    say("�ⶫ�����ҿ�û��ʲ���á�", who);
    return 0;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "bishi") == 0 && me->query_temp("fight_ok"))
	{
		Do_BiShi(this, me, "���ֱ��Ի�");
		return 1;
	}

	return CNpc::handle_action(comm, me, arg);
}

//���Խ���
virtual void is_defeated(CChar * winner, CChar * failer)
{
	if(failer == this)
	{
		if(! winner->query_temp("fight_ok"))	return;

		winner->delete_temp("fight_ok");
        say("������ʤ����������������µļѵ��� ! ��ϲ���� !");

		message_vision("$N����$nһ���Ƽ��š�", this, winner);
		winner->set_temp("have_letter",1);
		load_item("tuijianxin_3")->move(winner);
		return;
	}
	
	say("���ö����ϰ�������������������г���ͷ�� !");
	return;	
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];
	if (DIFFERSTR(me->querystr("family/family_name"), "������"))
	{
		say("���뱾��������������֪�˻��Ӻ�̸��", me);
		SendMenu(me);
		return;
	}

	if ( DIFFERSTR(me->querystr("class"), "bonze") && EQUALSTR(me->querystr("family/family_name"), "������")) 
	{
		say("�����׼ҵ��ӣ�����������ѧ�ա�", me);
		SendMenu(me);
		return;
	}

	if ( me->query("family/generation") <= query("family/generation") )
	{
		say("�⣬ƶɮ����ҵ� !", me);
		SendMenu(me);
		return;
	}

	char myname[5], prename[3];
	strncpy(myname, me->name(), 4)[4] = 0;
	strncpy(prename, myname, 2)[2] = 0;
	
	if ( ( me->query("family/generation") == query("family/generation") + 1) 
		&& strcmp(prename, "��") == 0)
	{
		say(snprintf(msg, 255, "%s��ͽ�������ܵ���������ˣ������� !", me->querystr("family/master_name")));
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	}

	if ( me->query("family/generation") == query("family/generation") + 2 )
	{
		if ( me->query_temp("apprentice_ok") )
		{
			me->delete_temp("have_letter");
			me->delete_temp("apprentice_ok");
	
			say(snprintf(msg, 255, "��%s���������ҵİɣ������� !", me->querystr("family/master_name")));
			say("ƶɮ�ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !", me);

			char new_name[5];

			strcpy(new_name, "��");
			new_name[2] = myname[2];
			new_name[3] = myname[3];
			new_name[4] = 0;

			me->set_name( new_name);
			say(snprintf(msg, 255, "�ӽ��Ժ���ķ�������%s����ϲ������Ϊ�����ɵ��ֱ����� !", new_name));
			command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		}
		else
		{
			say("��û���Ƽ��ţ�����Խ����ʦ��", me);
			SendMenu(me);
			return;
		}
	}

	return;
}


NPC_END;
