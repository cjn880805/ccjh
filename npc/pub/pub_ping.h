// pub_ping.c ƽһָ
//code by Fisho
//date : 2000-12-14
//inherit F_DEALER;

VENDOR_BEGIN(CNpub_ping);

virtual void create()
{
	set_name("ƽһ��", "ping yizhi" );

	set("icon", drugstore_boss);
	set("title", "ҩ���ϰ�");
	set("gender", "����");
	set("long", "������ҽ���߳��ġ�ɱ����ҽ��ƽһ�֡�ҽ����տ������������Ҳ�����˲����ˡ�");
	set("age", 65);
	set("int", 30);
	set("hp", 3000);
	set("max_hp", 3000);
	set("shen_type", 1);
	set("combat_exp", 500000);
	set("attitude", "heroism");
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 60);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 50);
	add_money( 1000 );
	carry_object("cloth")->wear();

//	set_inquiry ("������" , ask_wu );
	carry_good("shouwu", 50);
	carry_good("yuchandan", 20);
	set("no_huan",1);
}

static char * ask_wu(CNpc *who,CChar *me)
{
 	who->say("ʲô�������ڣ���ʮ�������", me);
	me->set_temp ("������" , 1 );
	who->SendMenu(me);
	return "";
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if (! me->query_temp("������"))
	{
        say("ҽһ�ˣ�ɱһ�ˣ��Ϸ���Ǯ��", me);
		SendMenu(me);
		return 0 ;
	}

	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 100000)
	{
		message_vision("ƽһ�ָ���$N�����ڣ�" , me);
		me->delete_temp("������" );
		ob=load_item("shouwu");//������
		ob->move(me);
	}
	destruct(ob);
	return 1;
}

VENDOR_END;