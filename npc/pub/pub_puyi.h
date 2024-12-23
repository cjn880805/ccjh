// pub_puyi.c
// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_puyi);

virtual void create()
{
	set_name("����",  "pu yi");

	set("icon", waiter);
	set("gender", "����" );
	set("age", 25);
	set("int", 28);
	set("long","���Ǹ����۴��������ˣ�������ת���Ĵ�������ͣ,������ʲô��");
	set("attitude", "peaceful");
    set("combat_exp",10000+random(5000));
	set("chat_chance", 3);
	carry_object("cloth")->wear();
	
	set_inquiry("����" ,ask_meili);
	set_inquiry("����","Ҫ�뵱�ٵý���������ȥ��");
	set_inquiry("����","��Ҳ֪�����������飿");
	set_inquiry("��ʮ���¾�",ask_shu);
	set("no_huan",1);
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "����ͻȻ˵��: ��������Ҫ������ֵ�߿���׷��MM��";
	case 1: 
		return "���۵����˵: ���������ٸ�Щ�˾�ȥ׷������";
	case 2:
		return "���۶��������̫���ˡ�";
	}
	return "";
}

static char * ask_meili(CNpc * who, CChar *me)
{
	char msg[255];
	who->say(snprintf(msg,255,"�����ڵ�����ֵ��%ld ", me->query("per") ), me);
	who->say("���������ֵ�ܸߣ�����ٸ��������������㡣�㻹���Խ���ȥ�����ϣ������������ٶ�����Ϳ��Դ����� ����������", me);
	who->say("�������˹ٻ������񣬸㲻�û�ɱͷ�ġ�", me);
	who->SendMenu(me);
	return "";
}

static char * ask_shu(CNpc * who,CChar *me)
{
	if (me->query_temp("money2_paid"))
	{
		me->delete_temp("money2_paid");
		who->say("������ʦ�����ϡ�", me);
		who->say("�����ʵ������ƭ��ġ�ʵ�ڲ������ͷ�����ҡ�", me);
		who->SendMenu(me);
		return "";
	}

	who->say("��ʲôҲ���Ƚ�Ǯ����", me);
	who->say("�һ���һ���ʱ��Ų鵽������µ����ڣ�����һ����𣬿ɲ��Ǻ�׬�ġ�", me);
	who->SendMenu(me);
	return "";
} 

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 1000000) 
	{
		who->set_temp("money2_paid",1);
		destruct(ob);
		return 1;
	}
	return 0;
}

NPC_END;