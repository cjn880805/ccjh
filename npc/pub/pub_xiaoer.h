// pub_xiaoer.c
//code by Fisho
//date : 2000-12-14

VENDOR_BEGIN(CNpub_xiaoer);

virtual void create()
{
	set_name("��С��","xiaoer");

	set("icon", waiter);
	set("gender", "����" );
	set("age", 22);
	set("long","��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������");
	set("combat_exp", 100);
	set("nkgain", 30);

	set("attitude", "friendly");
	set("rank_info/respect", "С����");

	carry_good("jitui", 50);
	carry_good("jiudai", 50);
	carry_good("huicheng_juanzhou", 10);
	carry_good("jinchuang", 20);
	set("no_huan",1);
}

virtual char * greeting(CChar * ob)
{
	char msg[255];
	if (!(ob->query_temp("welcome100")) || ob->query("mud_age")<1000)
	{
		ob->set_temp("welcome100","1");
		say(snprintf(msg,255,"��λ%s����ӭ���� �ݺ����¡�������������Ϸ����ƺ͹�����ʲô���������� mailto lanwood ������һ�������濼�ǵġ�",query_respect(ob) ));
	}
	switch( random(2) ) 
	{
	case 0:
		return snprintf(msg,255, "��С��Ц�����˵������λ%s�������ȱ��裬ЪЪ�Ȱɡ�",query_respect(ob) );
	case 1:
		return snprintf(msg,255, "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ%s����������", query_respect(ob) );
	}
	return "";
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	
	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 2000) 
	{
		tell_object(who, "С��һ������˵������л���ϣ��͹�����¥ЪϢ��");
		who->set_temp("rent_paid",1);
		destruct(ob);
		return 1;
	}
	return 0;
}
VENDOR_END;