//NANCHEN.h
//��衡�����ΣУá�̨�壨��Ȫ�ޣ���������������ˡ��Ѷȣ���
//Teapot 2000-01-05

NPC_BEGIN(CNquanzhou_nanchen);

virtual void create()
{
	set_name("����", "nanchen");
	set("long", "һ���ͣ͡�");
	set("title", "[�չ�������]");
	set("gender", "Ů��");
	set("age", 28);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);
	set("chat_chance", 2);
	set("cutted",5);
	set("no_huan",1);
};

virtual char * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "����һ��üͷ�����������";
	case 1:
		return "���������̾�˿�����";
	case 2:
		return "�������˸���������ɫ��㼡�";
	}

	return 0;
}


virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}



static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];

	if(! who) return;

    message_vision(snprintf(msg, 255, "$N����$n���ĵĵ�����λ%s, ���ܸ��Ҹ�������", query_respect(who)), me, who);

	return;
}



virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];

	if(! ob->is_character() ) return 0;

	if ( userp(ob) )
	{	
		say("�������ȵĽ���һ�����⡭���ҿɲ���Ҫ����", who);
		SendMenu(who);
		return 0;
	}

	if ( DIFFERSTR(ob->querystr("gender"), "����"))
	{	
		say("�������ȵĽ���һ�����⡭���ҿɲ���Ҫ����", who);
		SendMenu(who);
		return 0;
	}
	
	if ( ob->query("age") <16 )
	{	
		say("����΢΢��ü������������û�����ء�", who); 
		SendMenu(who);
		return 0;
	}
    
	if ( ob->query("age") >50 )
	{	 
		say("��������һ�ڵ��������Ϲ�ͷ������Ҫ����ʲô��", who);
		SendMenu(who);
		return 0;
	}
	
	if ( ob->query("per") <20 )
	{	 
		say("����˵�����⡭��Ҳ̫�ѿ��˵㡭��", who);
		SendMenu(who);
		return 0;
	}
	
	int i;
	i=ob->query("per");
	i=i*(ob->query("age")-16);
	if(userp(ob))	// is user? i don't know that userp() will get or not when a player unconcious.
	{
		i=i*10;
		i=i+random(ob->query("mks"));	// add kill npc num.
	}
	i=random(i)+1;

	if (!userp(ob) && i>who->query("level")*10)	//Limit bonus w.s a npc.
		i=who->query("level")*10;
	
	who->add("combat_exp",i);

	 	i=random(i)+1;

    message_vision(snprintf(msg, 255, "$n����$N���˸��򸣵�����л��λ%s��", query_respect(who)), who,this);
    message_vision(snprintf(msg, 255, "$N�����%d���飡", i), who);

    message_vision("ֻ�������ͳ�һ�Ѿ�ϸ������������",this);
    message_vision("����", this);
    message_vision("����", this);
    message_vision("����", this);
    message_vision("���꣡", this);
	if(random(query("cutted"))==0)
	{
//ʧ�֡���:)
	    message_vision("�����������ʧ���ˡ���", this);
	    message_vision("ֻ��Ѫ������", this);
		if (ob->query("max_hp")>200)
			ob->add("max_hp",-200);
		else
			ob->set("max_hp",1);
	    message_vision("������ѽ����һ������æ�ڸ�ס�����", this);
	}
	ob->set("gender","����");
	ob->set("class", "eneuch");
	ob->set("decided/nanchen",1);
	ob->add("combat_exp", random(3000));
	add("cutted",1);

    return 1;
}


virtual void die()
{
	revive(1);
	message_vision("$N��������������˿�����", this);
	set("max_hp", 30000);
	set("eff_hp",30000);
	set("hp",30000);
}

NPC_END;
