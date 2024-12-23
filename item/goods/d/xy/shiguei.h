//shiguei.h ���
ITEM_BEGIN(CIshiguei)

virtual void create(int nFlag = 0)		
{
	set_name("���","shi guei");
	set("unit", "��");
	set("no_get", "");
	set_weight(1);
};

virtual int do_look(CChar * me)
{
	say("����һ��ľ����ܣ�����ǽ���ŵ���������,�������У����Ǹ��Ÿ����书��ͼ�׾�����", me);
	if(me->query_temp("xy/renwu6_4") && me->query("xy/renwu6") )
	{
		static char book1[15][20]={"ϴ�辭","���¾Ž�����","��������","������ܸ","��ϼ��ܸ","��ɽ��÷�ַ�ͼ","����Ʒ���","��Ů�ľ�","��Ů����","������ʽ�ַ�","����ɨҶ�ȷ�","Τ�ӹ���","�����ؼ�","���󵶷�","���Ƶ���"};
		static char book2[15][20]={"�������","�޳��ȷ�","�ն��ȷ�","��ħ����","��Ħ����","��צ����","ӥצ����","�黨ָ��","һָ����","�ȱ�����","���޵���","��ɽ����","�����潣����","��а����","�����"};
		static char book3[17][20]={"�����ľ�","���ֿտ������ؼ�","�����澭","�����澭","̫��ʮ����","���޶���","���ҵ���","��ƽǹ��","̫����","���������Ʒ�","����׶��","���߽���","�廢���ŵ���","���꽣��","��˼����","������Ӱ����","���콣��"};
		static char book4[20][20]={"�嶾�Ʒ�","�嶾�ķ�","�嶾��","�嶾�޷�","̩ɽ����","��ɽ����","��ɽ����","��ɽ����","���鲽��","���Ź���","���ڵ���","���ǰ˴�","������","��ȭȭ��","����ħ��","����צ��","ޱ������","�����ؼ�","�����ķ�","��˪����"};
		CContainer * env=me->environment();
		if(env->query("index"))
		{
			int i;
			switch(env->query("index"))
			{
			case 1:
				for(i=0;i<15;i++)
				{
					AddMenuItem(book1[i], "$9na $1", me);
				}
				break;
			case 2:
				for(i=0;i<15;i++)
				{
					AddMenuItem(book2[i], "$9na $1", me);
				}
				break;
			case 3:
				for(i=0;i<17;i++)
				{
					AddMenuItem(book3[i], "$9na $1", me);
				}
				break;
			case 4:
				for(i=0;i<20;i++)
				{
					AddMenuItem(book4[i], "$9na $1", me);
				}
				break;
			}
		}
	}
	SendMenu(me);
	
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query_temp("xy/renwu6_4") && me->query("xy/renwu6") )
	{
		if(!strcmp(comm, "na")  )
		{
			say("�������鿴��һ�����ȴ������ôҲ�����������д��Щʲô��",me);
			SendMenu(me);
			return 1;
		}
	}
	return 0;
}

ITEM_END;




