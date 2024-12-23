#include "../server/Room.h"
#include "../server/Npc.h"

#define ZUSHI_BEGIN(npc_name)	class npc_name : public CNzushi	{	public:	npc_name(){};	virtual ~npc_name(){};
#define ZUSHI_END		};	

//��׼��ɽ��ʦ
//����Ȩ����
//Lanwood 2001-02-03

NPC_BEGIN(CNzushi);

virtual void setup()
{
	CNpc::setup();

	//�ٴ�����ѯ��
	set_inquiry("����", ask_zhangmen);	
}

//���������ߵ��ӣ�������˺�ٺ�Լ
int do_expell(CChar * me, char * arg)
{
	//�г����Կ����ĵ���
	CMapping * ptr = g_Channel.query_recruit(me->id(1));
	char msg[255], cmd[80];

	if(! ptr || ! ptr->GetCount())
		return notify_fail("�㻹û����ͽ���飡");

	if(strlen(arg))
	{
		ptr->del(arg);

		g_Channel.update_recruit(me->id(1), arg, "----", 0, 0);

		say("�õġ�", me);
		SendMenu(me);
		return 1;
	}

	say("������Ӳ��ڷ����������������������ռ�е���ͽ���", me);
	say("���ǣ���Ϊ�㹱�׵����ž���Ҳ�����۳�������ؿ��������", me);
	
	CVector v;

	ptr->keys(v);

	for(int i=0; i<v.count(); i++)
	{
		const char * key = v[i];
		CMapping * p = ptr->querymap(key);

		if(! p) continue;

		if(! p->query("apprentice")) continue;

		AddMenuItem(snprintf(msg, 255, "ͽ��%s(%s)��%ld",
					p->querystr("name"),
					key, 					
					p->query("exp") / 100	),
			snprintf(cmd, 80, "$0wantexpell $1 %s", key), me);
	}

	SendMenu(me);
	return 1;
}

static char * ask_zhangmen(CNpc * me, CChar * who)
{
	//�����ҵĸ����
	CMapping * skills = who->query_skills();
	int count = 0;

	if(DIFFERSTR(who->querystr("family/family_name"), me->querystr("family/family_name")))
	{
		return "����˭��";
	}

	if(who->query("zhangmen"))
	{
		me->say("��󣬱��ɵĹ⸴��ָ�����ˣ�");
		me->AddMenuItem("��лʦ��ָ�̣�", "", who);
		me->AddMenuItem("���뿪�����ӡ�", "$0wantexpell $1", who);
		me->SendMenu(who);
		return 0;
	}

	if(who->query("recruit_exp"))
	{
		//����10��ͽ�ܼ�����ս����֮λ
		if(who->recruit_num() >= 10)
		{
			who->set_temp("fight_zhangmen", 1);

			me->say("������Ϊ��������º����ͣ������ˣ�", who);
			me->say("���ھ���ս���ʦ��Ӯ������֮λ�ɣ�", who);
			me->SendMenu(who);			
			return 0;
		}

		me->say("Ҫ�����Яͽ�ܣ����������Լ������ž��顣", who);
		me->say("������һ�������ž���󣬲��ܴ������ͽ�ܡ�", who);
		me->say("�������ʮ��ͽ�ܺ������������Űɡ�", who);
		me->AddMenuItem("��лʦ��ָ�̣�", "", who);
		me->AddMenuItem("���뿪�����ӡ�", "$0wantexpell $1", who);
		me->AddMenuItem("�Ҿ����˳��������š�", "$0fqzm $1", who);
		me->SendMenu(who);
		return 0;
	}

	CVector v;

	skills->keys(v);

	for(int i=0; i<v.count(); i++)
		if( (* skills)[v[i]] > 150) count ++;

	if(count < 10)
		return "�㻹û���ʸ��������š�";

	who->set("recruit_exp", 50);
	return "��ô�Ͷ����ͽ������һ�°ɣ�";
}
	
int handle_action(char * comm, CChar *me, char * arg)
{
	if(strcmp(comm, "fqzm") == 0)
	{
		say("������̫��ϧ�ˣ�", me);
		me->del("recruit_exp");
		SendMenu(me);
		return 1;
	}
	else if(strcmp(comm, "wantexpell") == 0)
		return do_expell(me, arg);

	return CNpc::handle_action(comm, me, arg);
}

NPC_END;