//zhanshu.h
ITEM_BEGIN(CIwas_leitinglin)

virtual void create(int nFlag = 0)		
{
	set_name("�����ȱ�����", "lei ting lin");
	set("long",	"����Ǻ���������ơ�");
	set("unit", "��");
	set_weight(1000);
};


virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * who)
{
	CContainer * env =me->environment();
	if(who == me)
	{
		return notify_fail("���ܶ��Լ�ʹ�á�");
	}
	else if(!who->Query(CChar::IS_LIVING) )
	{
		return notify_fail("��ʱ���ܶԴ���ʹ�ã�");
	}
	else if(!userp(who))
	{
		return notify_fail("���ܶԴ���ʹ�ã�");
	}
	else if(!who->query_temp("was/renwu2_3"))
	{
		return notify_fail("���ܶԴ���ʹ�ã���");
	}
	else if(DIFFERSTR(env->querystr("name"),"������"))
	{
		return notify_fail("�����ڴ˵�ʹ�ã���");
	}
	else if(!me->query_temp("was/renwu2_3")||EQUALSTR(querystr("owner"),me->id(1)))
	{
		return notify_fail("�㲻��ʹ�ô���Ʒ��");
	}
	else if(EQUALSTR(who->querystr("family/family_name"),me->querystr("family/family_name")))
	{
		return notify_fail("���ܶԴ���ʹ�ã�����");
	}
	else if(who->query_temp("was/renwu2_4"))
	{
		return notify_fail("���ܶԴ���ʹ�ã�������");
	}
	else
	{
		message_vision("\n$YEL$N��$nʹ�������ȱ����ơ�", me,who);
		who->set_temp("was/renwu2_4",1);//���������Աʹ���������ȱ�����
		if(me->query_temp("was/renwu2_4"))
		{
			message_vision("$YELֻ�����������ȱ�������˸��ҫ�۵Ĺ�ԣ�Ȼ����ʧ�ˡ�\n", me);
			message_vision("\n$YEL$N����$n���Ӫ��С�ֶӡ�", me,who);
			me->set_temp("was/renwu2_5",1);//������
			who->set_temp("was/renwu2_5",1);
			me->set_temp("was/����",who->id(1));
			who->set_temp("was/����",me->id(1));
			me->set_temp("was/master",1);//�ӳ�
			who->set_temp("was/leader",1);//������
			me->call_out(go_end,60);
			who->call_out(go_end,60);
			((CChar * )who)->set_leader(me);
			message_vision("\n$YEL$N������$nһ���ж���", me,who);
		}
		destruct(this);
	}
	return 1;
}

static void go_end(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me =(CChar *)ob;
	CContainer * env =me->environment();
	if(env->query("count")>1)
	{
		tell_object(me,"\n$YEL�㾭��һ����᫵�·�̣�����󺰵�������~~~����λ�������³������ˣ���\n");
		me->move(load_room("����������"));
	}

}
ITEM_END;


