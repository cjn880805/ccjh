//liumangtou.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_liumangtou);

virtual void create()
{
	set_name("��åͷ","liumangtou");

	set("icon", cateran);
	set("gender", "����");
	set("age", 25);
	set("long", "�����ü�������ģ�һ���Ͳ����Ǹ����ˡ�");
	
	set("combat_exp", 7000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);

	carry_object("cloth")->wear();
	add_money(20);
};


int do_talk(CChar * me, char * ask = NULL)
{
	if(EQUALSTR(environment()->querystr("base_name"),"������ʯ���6" ))
	{
		if((me->query_temp("wei/renwu7_6") && !me->query_temp("wei/renwu8_2"))
			||(me->query_temp("wei/renwu6_2") && !me->query_temp("wei/renwu8_2")))
		{
			if(! strlen(ask))
			{
				AddMenuItem("ѯ�ʹ�������","yue",me);
			}
			else if(!strcmp(ask, "yue") )
			{
				say("��åͷ���һ��б�۵�����ү��֪����",me);
				if(me->query_temp("wei/renwu8_1")>=3 )
				{
					say("һ��֮�£������һ�ţ�����������åͷ���ϣ������åͷ��������񵾲���һ��������һ���ɳ���Զ�����ڲ�Զ����һ��¡���С�����ϡ�",me);
					say("С�������һ����Ӳ��飬��Ӳ����У�¶��һ��մ���೾��ľ׮�ӡ�",me);
					me->set_temp("wei/renwu8_2",1);//����������
				}
				else
				{
					me->add_temp("wei/renwu8_1",1);//����åͷ�Ի���Ҫ�Ĵ����ϣ�
				}
			}
			SendMenu(me);
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}
NPC_END;
