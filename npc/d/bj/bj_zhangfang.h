//bj_zhangfang.h �ʷ�����

NPC_BEGIN(CNbj_zhangfang);

virtual void create()
{
	set_name("�ʷ�����", "zhang fang");
	set("gender", "����");
	set("age", 44);
	set("long","��λ�������ฮ����ʷ�������" );
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 30);
	set("int", 29);
	set("con", 29);
	set("dex", 29);
	set("icon",young_man1);
	set("no_talk",1);
	set("no_huan",1);
}

int do_talk(CChar * me, char * ask = NULL)
{	
	if(me->query("zhang/����"))
	{
		AddMenuItem("����������Լ������ζ�", "$0pingju $1", me);
		me->set_temp("���ζ�",1);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(me->query_temp("���ζ�"))
	{
		if(strcmp(comm, "pingju") == 0 && me->query("zhang/����"))
		{
			return pingju(me);
		}
	}
	return CNpc::handle_action(comm, me, arg);
}

//��ѯ�����ó������
int pingju(CChar * me)
{
	if(me->query("zhang/����"))
	{
		char msg[255];
		if(me->query_temp("xinren"))
		{
			say(snprintf(msg, 255,"����ү���㻹�ǱȽ����εģ����ζ����ڿ���%ld��ѽ��", me->query("zhang/����")),me);
			me->delete_temp("xinren");
			me->delete_temp("���ζ�");
		}
		else
			say("����ү���㻹�ǱȽ����εģ���ֻ֪����ô�ࡣ", me);
		SendMenu(me);
	}
	return 1;
}


int accept_object(CChar * me, CContainer * item)
{
	char msg[255];

	if(EQUALSTR(item->querystr("id"),"coin") && item->query("value") >=1000000 )
	{
		me->set_temp("xinren",1);
		tell_object(me,snprintf(msg, 255, "$HIW�ʷ�������������%d�Ľ��$COM",item->query("value")));
		destruct(item);
		return 1;
	}
	return 0;
}
NPC_END;



