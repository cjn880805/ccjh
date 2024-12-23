// pub_xiaoer1.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_xiaoer1);

virtual void create()
{
	set_name("��С��","xiaoer1" );
	
	set("icon", waiter);
	set("gender", "����" );
	set("age", 22);
	set("long","��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������");
	set("combat_exp", 100);
	set("nkgain", 30);

	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("no_huan",1);
}

virtual char * greeting(CChar * ob)
{
	char msg[255];
	switch( random(2) ) 
	{
	case 0:
		return snprintf(msg,255, "��С��Ц�����˵������λ%s�������ȱ��裬ЪЪ�Ȱɡ�",query_respect(ob) );
	case 1:
		return snprintf(msg,255, "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ%s����������",query_respect(ob) );
	}
	return "";
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	
	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 1000)
	{
		tell_object(who, "С��һ������˵������л���ϣ��͹�����¥ЪϢ��");
		who->set_temp("rent_paid",1);
		destruct(ob);
		return 1;
	}
	return 0;
}
NPC_END;