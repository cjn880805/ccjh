//tangzhu.h
//��������NPC
//Lanwood 2000-01-09

#define MINGJIAOTANGZHU_BEGIN(npc_name) class npc_name : public CNmingjiao_tangzhu	{	public:	npc_name(){};	virtual ~npc_name(){};
#define MINGJIAOTANGZHU_END		};	

NPCMINGJIAO_BEGIN(CNmingjiao_tangzhu);

/*
virtual void init(CChar * me)
{
	CNmingjiao::init(me);

	if(userp(me) && ! is_fighting())
	{  
		Do_Attack(this, me, TYPE_QUICK);
		me->add_temp("beat_count", 1);
	} 	
}
*/

virtual int accept_object(CChar * me, CContainer * obj)
{
	if ( me->query_temp("have_letter") && me->present("tuijian xin4") ) 
	{
        say("�������������ҵ��Ƽ���ȥ��ʦ���� ?", me);
		SendMenu(me);
		return 0;
	}

	if( EQUALSTR(obj->querystr("id"), "tieyan ling")
		&& EQUALSTR(me->querystr("party/party_name"), "����")
		&& me->query("party/level") == 3
		&& !me->query_temp("have_letter") ) 
	{
		me->set_temp("fight_ok",1);
		destruct(obj);
        say("�ã���Ȼ�ѵõ��������ɣ����Ǿ�����֤һ���书��", me);
		AddMenuItem("��ʼ����", "$0bishi $1", me);
		AddMenuItem("ת���뿪", "", me);
		SendMenu(me);
		return 1;
	}
        
	if (EQUALSTR(obj->querystr("id"), "tuijian xin3" )
		&& me->query_temp("have_letter") )
	{
		me->set_temp("apprentice_ok",1);
		destruct(obj);
	    say("�ã���Ը�����������");
		AddMenuItem("Ը�����", "$0join $1", me);
		AddMenuItem("��ʱ����", "", me);
		SendMenu(me);
		return 1;
	}

    say(g_Channel.do_emote(this, 0, "smile", 1), me);
    say("�ⶫ�����ҿ�û��ʲ���á�", me);
    SendMenu(me);
	return 0;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "bishi") == 0 && me->query_temp("fight_ok"))
	{
		Do_BiShi(this, me, "��ʿ���Ի�");
		return 1;
	}
	if(strcmp(comm, "join") == 0 && me->query_temp("apprentice_ok"))
		return do_join(me);
	CContainer * env = load_room("pk");
	if((strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0 )&& env->query("mj/start") && userp(me))
	{
		message_vision("$n��üŭ��$N���޵����������е�ǰ֮�ʣ��㵽������ʲô������", me, this);
		me->delete_temp("mf/exp");
		me->add("hp",-me->query("hp")/2);
		me->UpdateMe();
		me->start_busy(3);
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
	    message_vision("$N����$nһ���Ƽ��š�", this, winner);
		winner->set_temp("have_letter",1);
        load_item("tuijianxin_4")->move(winner);
		say("������ʤ����������������̵ļѵ��� ! ��ϲ���� !");
		return;
	}
	
	say("�����㻹�ö����ϰ�������������������г���ͷ�أ�");
	return;	
}

int do_join(CChar * me)
{
	char msg[255];

	if ( me->query("party/level") >= query("party/level") )
	{
        say("��������ҵ� !", me);
		SendMenu(me);
		return 1;
	}

	if ( me->query("party/level") == 2 )
	{
		me->delete_temp("have_letter");
		me->delete_temp("apprentice_ok");
	
		char title[10], new_rank[40];
		strncpy(title, querystr("title"), 6)[6] = 0;
		snprintf(new_rank, 40, "%s��ʿ", title);
		me->set("party/rank", new_rank);
		me->set("party/level", 3);
		
		say("������ !", me);
        say("�����ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !", me);
	    say(snprintf(msg, 255, "��ϲ������Ϊ����%s��", new_rank), me);
		SendMenu(me);	
	}
	
	return 1;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if(me->querymap("family") && DIFFERSTR(me->querystr("family/family_name"),"����"))
	{
		say("���Ѿ������������ɣ���ذɡ�", me);
		SendMenu(me);
		return;
	}
	if(DIFFERSTR(me->querystr("party/party_name"), "����"))//���Ĳ���
	{
		say("�����뱾��������������ذɡ�", me);
		SendMenu(me);
		return;
	}
	
	if(me->query("party/level") > 3)
	{
		say("�����ڽ��еĵ�λ����������ҵ�!", me);
		SendMenu(me);
		return;
	}
	if(me->query("party/level") <= 2)
	{
		say("����δͨ������ʹ���ԣ�û������ʹ���Ƽ��ţ���������Խ����ͽ��", me);
		SendMenu(me);
		return;
	}
	else if(me->query("family/generation") == query("family/generation") + 1)//ʦ�����NPCͬ��
		say(snprintf(msg, 80, "%s��ͽ�������ܵ���������ˣ������� !", me->querystr("family/master_name")));
	else
	{
		say("�ã��Ҿ���������λ���ֵ�", me);
		SendMenu(me);
	}
	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	me->set("title", snprintf(msg, 80, "%s�״�����", querystr("title")));
	me->UpdateMe();
	return;
}

void die()
{
	char msg[255];
	CContainer * env = load_room("pk");
	if(env->query("mj/start"))
	{
		CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
		if(me && !env->query(snprintf(msg, 255,"mj/kill_%s",this->name(1))))
		{
			env->add(snprintf(msg, 255,"mj/kill_%s",this->name(1)),1);
			env->add("mj/count",1);
			g_Channel.do_channel(&g_Channel, 0, "chat", 
				snprintf(msg, 255, "$HIY%s$HIC�����湦��ն������ħͷ$HIY%s%s$HIC��",me->name(1),this->querystr("title"),this->name(1)));
		}
	}
	CNpc::die();
}
NPCMINGJIAO_END;



