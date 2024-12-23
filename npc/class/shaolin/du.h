//du.h
//���ֶ��ֱ�
//Lanwood 2000-01-09

#define SHAOLINDU_BEGIN(npc_name) class npc_name : public CNshaolin_du	{	public:	npc_name(){};	virtual ~npc_name(){};
#define SHAOLINDU_END		};	

NPC_BEGIN(CNshaolin_du);

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

	if ( me->query("betrayer") >= 2)
	{
		say("����ʦ����̫���ˣ��Ҳ������㡣", me);
		SendMenu(me);
		return;
	}

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

	if ( me->query("family/generation") == query("family/generation") + 1) 
	{
		say(snprintf(msg, 255, "%s��ͽ�������ܵ���������ˣ������� !", me->querystr("family/master_name")));
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	}

	if (me->query("family/generation") == 37)
	{
		if (me->query_skill("dodge", 1) < 120 ||
		    me->query_skill("parry", 1) < 120 ||
		    me->query_skill("force", 1) < 120 ||
		    me->query_skill("buddhism", 1) < 120 ||
		    me->query_skill("hunyuan_yiqi", 1) < 120 ||
		    me->query_skill("shaolin_shenfa", 1) < 120) {
			say("���Ƿ�Ӧ���ڸ�����϶��µ㹦��", me);
			SendMenu(me);
			return;
		}

		command("chat 0 ����������������");
		command("chat 0 �벻�������ڴ���֮�꣬���ٵ�һ������֮�ţ����ǿ�ϲ�ɺء�");
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	
		say(snprintf(msg, 255, "��%s���������ҵİɣ������� !", me->querystr("family/master_name")));
		say("ƶɮ�ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !", me);

		char new_name[5], myname[5];
		strncpy(myname, me->name(), 4)[4] = 0;
		strcpy(new_name, "��");
		new_name[2] = myname[2];
		new_name[3] = myname[3];
		new_name[4] = 0;

		me->set_name( new_name);
		me->set("family/generation", 36);

		say(snprintf(msg, 255, "�ӽ��Ժ���ķ�������%s����ϲ������Ϊ���������ֱ����� !", new_name));
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));		
	}
}


NPC_END;
