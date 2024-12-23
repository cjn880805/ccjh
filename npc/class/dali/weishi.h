//weishi.h
//��������ʿ, ��ʦ
//Lanwood 2000-01-05

#define DALIWEISHI_BEGIN(npc_name) class npc_name : public CNdali_weishi	{	public:	npc_name(){};	virtual ~npc_name(){};
#define DALIWEISHI_END		};	

NPC_BEGIN(CNdali_weishi);

static char * ask_me(CNpc * me, CChar * who)
{
	if (who->query_skill("kurong_changong",1) < 60)
		return "���뵱��ʿ���������깦�ɡ�";
		

	const char * oldtitle = who->querystr("title");
	
	if (strstr(oldtitle, "�������������ҳ�"))
	{
		who->set_temp("fight_ok",1);
		me->say("�ã���Ȼ������д裬�ǾͿ���ı�������ˡ�", who);

		me->AddMenuItem("��ʼ���ԡ�", "$0bishi $1", who);
		me->AddMenuItem("�������ԡ�", "", who);
		me->SendMenu(who);
		return 0;
	}
	
	return "ֻ�мҳ���������ʿ��";
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "bishi") == 0 && me->query_temp("fight_ok"))
	{
		Do_BiShi(this, me, "��ʿ���Ի�");
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
		say("������ʤ����������Ǵ���μҵĺõ��� ! ��ϲ���� !");
		say("���Ѿ�����ʤ�δ�����ʿ !");
		
		upgrade_title(winner, "��������������ʿ");
		return;
	}
	
	say("�����㻹�ö����ϰ�������ڴ���μ��������г���ͷ�� !");
	return;	
}

void upgrade_title(CChar * me, char * arg)
{
	me->set("title", arg);
	me->UpdateMe();
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

/*	if (me->querystr("title") != "��������������ū")
	{
		g_Channel.do_emote(this, me, "shake", 1);
		say("������Ͷ�����Ϊ�����������㽭�����񣬲�����ͽ�ˡ�", me);
		SendMenu(me);
		return;
	}
*/
	if (me->query("repute") < 0  )
	{
		say("�Ҵ�������������������ֺڵ�����򽻵�������ذɣ�", me);
		SendMenu(me);
		return;
	}
/*
	if (me->query_combat_exp() > 10000 || me->query("age") >17 )
	{
		say("�����������˴�������Ҳ����̫�����˰ɣ�", me);
		SendMenu(me);
		return;
	}
*/
	say("�ܺã��ܺá������븮���㵱���ұ�������������Ҳ�Ͳ����Լ����ˡ�");
	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	
	if( EQUALSTR(me->querystr("gender"), "����"))
		me->set("title", "�������������Ҷ�");
	else
		me->set("title","�������������Ů");

	me->UpdateMe();
}

NPC_END;
