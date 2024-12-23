//zhanshu.h
ITEM_BEGIN(CIzhanshu)

virtual void create(int nFlag = 0)		
{
	set_name("ս��", "zhan shu");
	set("long",	"����Ǻ�����������ץ������Ͱ͵İ�ֽ��������������֣�����Ҫս����");
	set("unit", "��");
	set_weight(1000);
};


virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * who)
{
	char msg[255];
	if(query("use"))
	{
		return notify_fail("����ս���Ѿ�ʹ�ù��ˣ�");
	}
	if(who == me)
	{
		return notify_fail("�ѵ������Լ�ȥ��ս�����Բ������ˣ�");
	}
	else if(!who->Query(CChar::IS_LIVING) )
	{
		return notify_fail("�����ԶԷ������Ѿ��޷�����ս�飡");
	}
	else if(!who->Query(CChar::IS_NPC))
	{
		return notify_fail("�����ԶԷ������޷�����ս�飡");
	}
	else
	{
		if(EQUALSTR(who->id(1),"hu na") && !userp(who))
			return notify_fail("����������һ����ֵ��۹⿴���㡣");

		if(DIFFERSTR(who->id(1),"haju ba") || userp(who))
			return notify_fail(snprintf(msg, 255,"%sͷ����ֱ˦�����������û��Ū��ɣ����������Σ���ô�ܺ��������ء���",who->name(1)));
		else if(!me->query_temp("zhang/renwu6_3"))
		{
			tell_object(me, "\n$HIR���ްԵ�ͷһɨս�飬�ȵ����������ǣ��������������µĺ��������");
			tell_object(me, "$HIR�漴�Ӻ���ԭֽ�ϻ��飺����Ҫս���Ǳ�ս����\n");
			destruct(this);
			CContainer * zhanshu=load_item("baozi");
			zhanshu->set_name("ս��","zhan shu");
			zhanshu->set("use",1);
			zhanshu->set("owner1",me->id(1));
			zhanshu->set("long","����Ǻ�����������ץ������Ͱ͵İ�ֽ��������������֣�����Ҫս��������ظ���������Ҫս���Ǳ�ս��������Լս˫�����ǲ������ܡ�");
			zhanshu->move(me);
			me->set_temp("zhang/renwu6_3",1);
		}
		else
			return notify_fail("���Ѿ��ù���ս�飬������ʲô��");
	}
	return 1;
}

ITEM_END;




