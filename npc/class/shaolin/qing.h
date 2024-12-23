//qing.h
//�������ֱ�
//Lanwood 2000-01-09

#define SHAOLINQING_BEGIN(npc_name) class npc_name : public CNshaolin_qing	{	public:	npc_name(){};	virtual ~npc_name(){};
#define SHAOLINQING_END		};	

NPC_BEGIN(CNshaolin_qing);

virtual int accept_object(CChar * who, CContainer * obj)
{
	if ( who->query_temp("have_letter") && who->present("tuijian xin1") ) 
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
		load_item("tuijianxin_1")->move(winner);
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

	if ( me->query("family/generation") == 0 )
	{
		say("�����ӷ�ƶɮ�����������ҵĵ����ˡ�");
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		return;
	}
	
	if ( me->query("family/generation") == query("family/generation") + 1) 
		
	{
		say(snprintf(msg, 255, "%s��ͽ�������ܵ���������ˣ������� !", me->querystr("family/master_name")));
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	}

	return;
}


NPC_END;
