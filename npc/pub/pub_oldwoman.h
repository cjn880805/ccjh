// pub_oldwoman.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_oldwoman);

virtual void create()
{
	set_name("�ϴ���", "old woman");

	set("icon", old_woman);
	set("gender", "Ů��" );
	set("age", 63);
	set("long", "һ��������˪֮ɫ�������š�");
 	set("shen_type", 1);
	set("combat_exp", 150);
	set("nkgain", 40);
	set("env/wimpy", 60);
	set("chat_chance_combat", 50 );
 	set("str", 13);
	set("dex", 12);
	set("con", 14);
	set("int", 13);
	set("attitude", "friendly");
 	set("chat_chance", 10);
	carry_object("cloth")->wear();
	add_money( 100);
	set_inquiry ("��" , "������ĸ����...һ�����Ǽ���������ҵ��С��å�ɵġ�" );
	set_inquiry ("��å" , "�Ǽ���С��å���첻����ҵ������С��ͬ��Ⱦƶ�Ǯ��" );
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "�ϴ������ĵ�˵�����Ǹ���ɱ�ģ�͵���ҵ���ĸ����";
	case 1:
		return "�ϴ���̾�˿�����˵�������Ǹ�ʲ����������";
	case 2:
		return "�ϴ�����������ż�������������ˡ�";
	}
	return "";
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(EQUALSTR(environment()->querystr("base_name"),"����é�Ҳ�" ))
	{
		if(me->query("wei/renwu1") )
		{
			if(! strlen(ask))
			{
				AddMenuItem("�����彣������Ϣ","mu",me);
				AddMenuItem("������褵���Ϣ","fang",me);
				SendMenu(me);
				return 1;
			}
			else if(!strcmp(ask, "fang") && !me->query("wei/renwu6"))
			{
				say("�ϴ���������죬˵������Ѿͷ�ҿɲ�ϲ����һ��Ů���Ӽң������װͰ͵ģ���ѧ�����赶Ū�����ⲻ������һ�����Űѽ����ֲ�֪�����Ķ�ȥ�ˣ�",me);
				me->set_temp("wei/renwu6_1",1);//���ϴ���������ڷ�褵���Ϣ
				SendMenu(me);
				return 1;
			}
			else if(!strcmp(ask, "mu") && !me->query("wei/renwu5") && !me->query_temp("wei/renwu5_7"))
			{
				if(me->query_temp("wei/renwu5_3") )
				{
					say("�ϴ���̾�˿�����˵�����������Ǹ��������У��������ǲ������ģ�",me);
					me->set_temp("wei/renwu5_4",1);//���ϴ�����������彣������Ϣ2
					SendMenu(me);
					return 1;
				}
				else if(!me->query_temp("wei/renwu5_1"))
				{
					say("�ϴ���̾�˿�����˵������С����ѽ��ģ�������ǿ����ɾ��ǲ�֪��Ϊʲô��һ�쵽����Ÿ����������Ұ������Ŷ����ۣ����ˣ��������֪���ǲ��ǵ�ʲô���ˣ����Ա��⽭�����е����չ�ҩ���أ�",me);
					me->set_temp("wei/renwu5_1",1);//���ϴ�����������彣������Ϣ1
					SendMenu(me);
					return 1;
				}
			}
		}
	}
	return CNpc::do_talk(me,ask);
}

NPC_END;