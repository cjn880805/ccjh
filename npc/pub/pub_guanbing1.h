// pub_guanbing1.c �ٱ�
//code by Fisho
//date : 2000-12-13

NPC_BEGIN(CNpub_guanbing1);

virtual void create()
{
	set_name("�ٱ�", "guan bing1");

	set("icon", guarder);
	set("age", 22);
	set("gender", "����");
	set("long", "��Ȼ�ٱ������ղ��ܺ�������ʿ��ȣ��������ǽ��������˶�������");
	set("attitude", "peaceful");
	
	set("str", 24);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);
	
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
	
	set("chat_chance_combat", 10);

	carry_object("gangdao")->wield();
	carry_object("junfu")->wear();
	carry_object("jitui");
}

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		return "�ٱ�˵���󵨵��񣬾����췴���ɣ�";
	case 1:
		return "�ٱ�˵���ܵ��˺����ܲ������㻹�ǿ�����־��ܣ�";
	}
	return "";
}

virtual void init(CChar *me)
{
	CNpc::init(me);

	if(userp(me) && me->query_condition("killer")) 
	{
		kill_ob(me);
	}
}

virtual int accept_fight(CChar * me)
{
	say("��ү����������ɱ�ţ��������㵹ù��");
//	me->apply_condition("killer", 500);
	kill_ob(me);
	return 1;
}

NPC_END;