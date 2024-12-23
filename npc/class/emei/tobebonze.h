//tobebonze.h
//����
//Lanwood 2000-01-05

#define EMEIBONZE_BEGIN(npc_name) class npc_name : public CNemei_tobebonze	{	public:	npc_name(){};	virtual ~npc_name(){};
#define EMEIBONZE_END		};	

NPC_BEGIN(CNemei_tobebonze);

static char * ask_for_join(CNpc * me, CChar * who)
{
    if ( DIFFERSTR(who->querystr("family/family_name"), "������")) 
        return "��Ͷ���û��ԨԴ��ƶ�᲻�Ҹ�����ȡ�";

	if( who->query("bonze/justonetime"))
		return "ʩ�����ѻ��ף��ֺο��ٴγ��ң�";

	if( EQUALSTR(who->querystr("class"), "bonze") )
        return "�����ӷ𣡳����˲���ڿ����Ѿ��ǳ������ˡ�";

    if( DIFFERSTR(who->querystr("gender"), "Ů��") )
        return "�����ӷ����գ����գ�ʩ������������ҷ𣬿�ȥ�������ܽ䡣";

    who->set_temp("pending/join_bonze", 1);
        
	me->say("�����ӷ����գ����գ�ʩ������������ҷ�������ܽ䡣", who);
    me->say("��ס��һ�����˼ң��ǲ��ܻ��׵ģ����򽫻��ܵ��ͷ���", who);
	me->AddMenuItem("�����ܽ�", "$0kneel $1", who);
	me->AddMenuItem("ת���뿪", "", who);
	me->SendMenu(who);
	return 0;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "kneel") == 0)
	{
		return do_kneel(me);
	}

	return CNpc::handle_action(comm, me, arg);
}

int do_kneel(CChar * me)
{
    char prename[][3] ={ "��","��"};
    char name[3], new_name[40], msg[255];

    if( ! me->query_temp("pending/join_bonze") ) return 0;

    message_vision("$N��˫�ֺ�ʮ�����������ع���������\n$n����$N˵�����ðɣ�����ڱ������аɡ�\n$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��\n", me, this);
    
	strncpy(name, me->name(1), 2)[2] = 0;
	snprintf(new_name, 40, "%s%s", prename[random(2)], name);
    
    say(snprintf(msg, 255, "�ӽ��Ժ���ķ�������%s��", new_name), me);
    command(snprintf(msg, 255, "chat 0 %s����Ϊ�ᣬ�ڶ���ɽ���У�ȡ����%s��", me->name(), new_name) );
    g_Channel.do_emote(this, 0, "smile", 0);
    me->set("bonze/old_name", me->name());
    me->delete_temp("pending/join_bonze");
    me->set_name( new_name);
    me->set("class", "bonze");
    me->set("K_record", me->query("pks") + me->query("mks"));
    me->set("shen_record", me->query("repute"));
    me->set("repute", 0l);
	me->set("bonze/justonetime", 1);

	me->UpdateMe();
    return 1;
}

NPC_END;
