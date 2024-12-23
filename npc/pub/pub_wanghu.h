//pub_wanghu.h
//wuqing 2002-2-10 

NPC_BEGIN(CNpub_wanghu);

virtual void create()
{
	set_name("����","wang hu");
	set("long", "���ִ����Ϊ�����������ϵ�˽ԩ��ר�͸����ھֵĹ���ȥ��");
	set("gender", "����");
	set("age", 80);
	
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("icon",taoist);	
	set("title","���컢");
	set("max_hp", 15000);
	set("mp", 10000);
	set("max_mp", 10000);
	set("mp_force", 100);
	set("combat_exp", 1400000);
	set("score", 1200000);

	set_skill("force", 200);
	set_skill("taiji_shengong", 200);
	set_skill("dodge", 200);
	set_skill("tiyunzong", 200);
	set_skill("unarmed", 200);
	set_skill("taiji_quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji_jian", 200);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");	

	set("class", "taoist");
    set("apply/armor", 300);
	set("apply/damage", 150);
	set("chat_chance_combat", 60);
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	set("no_kill",1);//����������ٹȵ�������

}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(! strlen(ask))
	{
		AddMenuItem("���֣�����¸��ˣ�", "xiagang", me);
		SendMenu(me);
		return 1;
	}
	else if(strcmp(ask, "xiagang") == 0)
	{
		me->set_temp("�¸�",1);
		set("�¸�",me->id(1));
		message_vision("С�ӣ��������ǲ�����ˣ�",me);
		((CUser *)this)->Ready_PK();
		((CUser *)me)->Ready_PK();
		me->kill_ob(this);	
		this->kill_ob(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual char * chat_msg_combat(CChar * player)
{
	switch(random(4))
	{
	case 0:
		perform_action("sword lian", 1);
		break;
	case 1:
		perform_action("sword chan", 1);
		break;
	case 2:
		perform_action("sword sui", 1);
		break;
	case 3:
		perform_action("force recover",0);
		break;
	}

	return 0;
}

virtual void die()
{
	if(atoi(querystr("�¸�")))
	{
		CUser * me;
		me=find_online(querystr("�¸�"));
		if(me)
		{
			me->delete_temp("�¸�");
			me->set_temp("����",1);
		}
	}
	message_vision("$HIR������ֵ��ǣ����ȳ�����", this);
	destruct(this);
}

NPC_END;



