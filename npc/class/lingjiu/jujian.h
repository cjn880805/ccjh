//jujian.h
//cat 2001-4-4

NPC_BEGIN(CNlingjiu_jujian);

virtual void create()
{
	set_name("����", "jian ju");
	set("long", "���Ǹ���ò毺õ�Ů��, ��������, �������, ������ס����ܾ������ļ�������");
	set("gender", "Ů��");
	set("per", 28);
	set("title", "������Ů");
	set("age", 18);
	
	set("attitude", "peaceful");
	set("icon",young_woman1);

	set("per", 32);
	set("class", "officer");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("hp", 1000);
	set("max_hp", 3000);
	
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 100);

	set("combat_exp", 1200000);
	set("score", 10000);
	set_skill("force", 150);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("hand",150);
	set_skill("strike", 150);
	set_skill("sword",200);

	set_skill("zhemei_shou",150);
	set_skill("liuyang_zhang",150);
	set_skill("tianyu_qijian",150);
	set_skill("yueying_wubu",150);
	set_skill("bahuang_gong", 150);

	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
	map_skill("sword", "tianyu_qijian");

	prepare_skill("strike","liuyang_zhang");
	prepare_skill("hand","zhemei_shou");
	create_family("���չ�",3,"����");
	set("chat_chance_combat", 50);
	
	carry_object("changjian")->wield();
	carry_object("qingyi")->wear();
    carry_object("doupeng")->wear();
	carry_object("jiudai");
	add_money(1500);
};

virtual char * chat_msg_combat()
{
	char msg[40];
	CContainer * jian = PresentName("changjian", IS_ITEM);

	switch(random(8))
	{
	case 0:
			perform_action("strike zhong", 1);
			break;
	case 1:
			perform_action("hand duo", 1);
			break;
	case 2:
			perform_action("sword san", 1);
			break;
	case 3:
	case 4:
			if(query_weapon() == jian && jian)
				command(snprintf(msg, 40, "unwield %ld", jian->object_id()));
			break;
	case 5:
	case 6:
			if(jian && ! query_weapon())
				command(snprintf(msg, 40, "wield %ld", jian->object_id()));
			break;
	case 7:
	case 8:
			perform_action("force recover", 0);
			break;
	}
	
	return 0;
}

virtual void init(CChar * me)
{
	CNpc::init(me);
	
	if(userp(me) && !is_fighting())
	{
		if(me->query_temp("lj/dating")&&!me->query_temp("lj/hm/����") )
		{
			me->add_temp("lj/humang",1);
			me->add_temp("lj/hm/����",1);
			tell_object(me, "���ջ̻�ãã���ʵ�:����ʧ���ˣ��㿴��������ô?");
		}
		if(DIFFERSTR(me->querystr("family/family_name"), "���չ�") )
		{
			if( !me->query_temp("warned") ) 
			{
				say("����������˲��ý������չ��������뿪��");
				me->set_temp("warned", 1);
			}
			else
			{
				if( me->query_temp("stay") < 5 ) me->add_temp("stay",1);
				else 
				{
					say("�󵨿�ͽ�������ô����չ�������");
					kill_ob(me);
				}
			}
		}
	}
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if (DIFFERSTR(me->querystr("gender"), "Ů��"))
    {
 		say("�����ˣ���������!", me);
		SendMenu(me);
		return;
	}
	
	if (me->query_skill("bahuang_gong", 1) < 50) 
    {
		say("���Ƿ�Ӧ�ö������˻�����Ψ�Ҷ��𹦣�", me);
		SendMenu(me);
		return;
	}

	if (me->query_con() < 20) 
    {
		say("���Ź�����Ϊ����,��ĸ����ƺ�����.", me);
		SendMenu(me);
		return;
	 }
	
	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	me->set("class", "scholar");
	me->UpdateMe();
	return;
}

NPC_END;
