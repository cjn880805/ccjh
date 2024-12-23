//xuan.h
//�������ֱ�
//Lanwood 2000-01-09

#define SHAOLINXUAN_BEGIN(npc_name) class npc_name : public CNshaolin_xuan	{	public:	npc_name(){};	virtual ~npc_name(){};
#define SHAOLINXUAN_END		};	

NPC_BEGIN(CNshaolin_xuan);

virtual int accept_object(CChar * who, CContainer * obj)
{
	if ( who->query_temp("have_letter") && who->present("tuijian xin5") ) 
	{
		say("�������������ҵ��Ƽ���ȥ��ʦ���� ?", who);
		SendMenu(who);
		return 0;
	}

	if (EQUALSTR(obj->querystr("id"), "tuijian xin4" )
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
	
	if ( me->query("family/generation") == query("family/generation") + 1)
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
			say(snprintf(msg, 255, "�ӽ��Ժ���ķ�������%s����ϲ������Ϊ�����ɳ��ֱ����� !", new_name));
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
