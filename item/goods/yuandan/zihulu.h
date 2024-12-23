//zihulu.h
ITEM_BEGIN(CIzihulu)

virtual void create(int nFlag = 0)		
{
	set_name("С�Ϻ�«", "zi hulu");
	set("long",	"һ���͹ⷢ������ɫС��«�����滹װ��һЩ���ƣ�");
	set("unit", "��");
	set_weight(1000);
	set("value", 1);
	set("count",100);

//	call_out(do_die, 100);	
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * who)
{
	if(who == me)
	{
		tell_object(me,"�����һС�ں�«�еľƣ������о�����ԴԴ����ӿ�����ڡ�");
		add("count",-1);
		if(!query("count"))
		{
			set("long","С�Ϻ�«��տ���Ҳ����Ȼ�Ѿ�û�о��ˡ�");
			return 0;
		}
		else if(query("count")<0)
		{
			tell_object(me,"������ҡ��ҡС�Ϻ�«��ϣ������ҡ��һ���ξ�����ȴ����žһ���죬��«���������ѳ�����Ƭ��");
			destruct(this);
			return 0;
		}
		else
		{
			if(me->query("mp")<me->query("max_mp"))
				me->add("mp",1000);
			me->UpdateMe();

			double value = 20;		//20��
			time_t t;
			time(&t);
			if(!me->query("yuandna/jiou/time"))
				me->set("yuandna/jiou/time",t);
			else
			{
				double time=t-me->query("yuandna/jiou/time");
				if(time<value)
				{
					me->add("yuandna/jiou/sos",1);
					if(me->query("yuandna/jiou/sos")>=3)
					{	
						if(me->query("yuandna/jiou/sos_level")<3)
							me->add("yuandna/jiou/sos_level",1);
						me->del("yuandna/jiou/sos");
						me->apply_condition("drunk1", 20 + random(20));

						if(me->query("yuandna/jiou/sos_level")==1)
						{
							tell_object(me,"\n$HIR�����ͷ�������ģ�\n");
						}
						else if(me->query("yuandna/jiou/sos_level")==2)
						{
							tell_object(me,"\n$HIR�����ͷ�������ģ�����Ҫ���ˣ�\n");
						}
						else if(me->query("yuandna/jiou/sos_level")==3)
						{
							tell_object(me,"\n$HIR��͵�һ�ɣ�������ߡ�\n");
						}
					}
					me->set("yuandna/jiou/time",t);
				}
				else
				{
					me->del("yuandna/jiou/sos");
					me->del("yuandna/jiou/sos_level");
					me->set("yuandna/jiou/time",t);
				}
			}
			return 1;
		}
	}

	return notify_fail("��ֻ���Լ��ȡ�");
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	//���ϵͳʱ��
	time_t t;	
	struct tm * newtime;

	time(&t);
	newtime = localtime(&t); 

	int month = newtime->tm_mon + 1;
	int day = newtime->tm_mday;

	if(month!=1 ||day>13)
	{
		CContainer * env = load_room("jy");
		if(!env->query("�"))
			destruct(ob);
	}
	else
		ob->call_out(do_die, 3600);
}
ITEM_END;
