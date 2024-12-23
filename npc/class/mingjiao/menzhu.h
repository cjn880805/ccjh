//menzhu.h
//��������NPC
//Lanwood 2000-01-09

#define MINGJIAOMENZHU_BEGIN(npc_name) class npc_name : public CNmingjiao_menzhu	{	public:	npc_name(){};	virtual ~npc_name(){};
#define MINGJIAOMENZHU_END		};	

NPCMINGJIAO_BEGIN(CNmingjiao_menzhu);

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if(me->querymap("family") && DIFFERSTR(me->querystr("family/family_name"),"����"))//���ɵĲ���
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
	if(me->query("party/level") > 1)//ֻ�ո����ŵ�
	{
		say("�����ڽ��еĵ�λ����������ҵ�!", me);
		SendMenu(me);
		return;
	}
	else
	{
	 	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		me->set("title", snprintf(msg, 80, "%s�״�����", querystr("title")));
		say("�ã��Ҿ���������λ���ֵ�", me);
		SendMenu(me);
		me->UpdateMe();
		return;
	}
}

virtual int accept_object(CChar * me, CContainer * obj)
{
	if ( me->query_temp("have_letter") && me->present("tuijian xin2")) 
	{
		say("�������������ҵ��Ƽ���ȥ������ʹ���� ?", me);
		SendMenu(me);
		return 0;
	}

	if( EQUALSTR(obj->querystr("id"), "tieyan ling")
		&& EQUALSTR(me->querystr("party/party_name"), "����")
		&& me->query("party/level") == 1
		&& !me->query_temp("have_letter") ) 
	{
		me->set_temp("fight_ok", 1);
		destruct(obj);
		say("�ã���Ȼ�ѵõ�������ɣ����Ǿ�����֤һ���书��", me);
		AddMenuItem("��ʼ����", "$0bishi $1", me);
		AddMenuItem("ת���뿪", "", me);
		SendMenu(me);
		return 1;
	}
        
    say(g_Channel.do_emote(this, 0, "?", 1), me);
    say("�ⶫ�����ҿ�û��ʲ���á�", me);
	SendMenu(me);
	return 0;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "bishi") == 0 && me->query_temp("fight_ok"))
	{
		Do_BiShi(this, me, "�������Ի�");
		return 1;
	}
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
        say("������ʤ����������������̵ļѵ��� ! ��ϲ���� !");

		message_vision("$N����$nһ���Ƽ��š�", this, winner);
		winner->set_temp("have_letter",1);
		load_item("tuijianxin_2")->move(winner);
		return;
	}
	
	say("�����㻹�ö����ϰ�������������������г���ͷ�� !");
	return;	
}

void die()
{
	char msg[255];
	CContainer * env = load_room("pk");
	if(env->query("mj/start"))
	{
/*		CContainer * obj = environment();
		DTItemList * list = obj->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		CChar * me;
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(! obj->is_character()) continue; 
			me = (CChar *)obj; 
			if(me==this||is_fighting(me)==is_fighting(this)) continue;
			if(EQUALSTR(me->querystr("family/family_name"), "����")&& !userp(me)) continue;
			break;
		}
*/		CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
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




