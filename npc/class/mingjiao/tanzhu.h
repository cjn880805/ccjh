//tanzhu.h
//����̳��NPC
//Lanwood 2000-01-09

#define MINGJIAOTANZHU_BEGIN(npc_name) class npc_name : public CNmingjiao_tanzhu	{	public:	npc_name(){};	virtual ~npc_name(){};
#define MINGJIAOTANZHU_END		};	

NPCMINGJIAO_BEGIN(CNmingjiao_tanzhu);

static char * ask_me(CNpc *who,CChar *me)
{
	who->say("���������������", me);
	who->AddMenuItem("����", "$0join $1",me);
	who->AddMenuItem("�Ҳ���", "", me);
	who->SendMenu(me);
	return 0;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "join") == 0)
	{
		return do_join(me);
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

//��������
int do_join(CChar * me)
{
	if(me->query_temp("have_letter") || me->present("tuijian xin1"))
   	{
		say("�ð���", me);
		say(g_Channel.do_emote(this, me, "heihei", 1), me);
		SendMenu(me);
		return 1;	
	}
   	if( ! me->querymap("party"))
   	{
		message_vision("$N����$nһ���Ƽ��š�", this, me);
		say("�ã��㵽����ɽ�ܶ�ȥ�ҽ���ʹ�ߣ�����������̵ġ�", me);
		me->set_temp("have_letter",1);
        load_item("tuijianxin_1")->move(me);
		SendMenu(me);
		return 1;	
	}
   	if( DIFFERSTR(me->querystr("party/party_name"), "����"))
	{
		say("���Ѿ��������������ˣ��������������̡�", me);
		SendMenu(me);
		return 1;
	}

	say("���Ѿ��������̵����ˡ�", me);
	SendMenu(me);
	return 1;
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




