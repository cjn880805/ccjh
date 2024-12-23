//tiancai_hunhun ���С��� 
//�������Ĳ�BOSS

BOSS_BEGIN(CNtiancai_hunhun);

virtual void create()
{
	set_name("���С���", "tiancai hunhun");
	set("title", "������");
	set("gender", "����");
	set("age", 98);
	set("class", "bonze");
	set("icon",young_monk);
	set("long",  "���ʮ�塢�����ģ��������һ�������̴桢ͯ��δ������������������������������Բ�����ǵ�˫����ֱͦ���εı����������������������Ц��Ц��΢���ţ���������������޺��ĹԱ�����");
   
	set("str", 90);
	set("int", 90);
	set("con", 90);
	set("dex", 90);
	set("per",25);
	set("level",190);
	set("repute",-60000000);

	set("chat_chance_combat", 15);		//����NPCʹ�þ��еļ���
	
	set_inquiry("����", "�����ҵ��Ǹ�..�Ǹ�..��");
	set_inquiry("�޶���", "�����Ĵ�����������");
	set_inquiry("�׶�԰", "������ı��������ҵİ������׶�԰Ŷ��");

	set("hp", 92000);
	set("max_hp", 92000);
	set("mp", 52000);
	set("max_mp", 52000);
	set("mp_factor", 500);
	
	set("combat_exp", 160000000);
	set("score", 500000);
	
	set_skill("mizong_xinfa", 700);
	set_skill("literate", 700);
	set_skill("force", 700);
	set_skill("parry", 700);
	set_skill("blade", 700);
	set_skill("sword", 700);
	set_skill("dodge", 700);
	set_skill("longxiang", 700);
	set_skill("shenkong_xing", 700);
	set_skill("hand", 700);
	set_skill("dashou_yin", 700);
	set_skill("mingwang_jian", 700);
	set_skill("xue_dao", 700);
	set_skill("poison", 700);
	   
	map_skill("force", "longxiang");
	map_skill("dodge", "shenkong_xing");
	map_skill("hand", "dashou_yin");
	map_skill("parry", "xue_dao");
	map_skill("blade", "xue_dao");
	map_skill("sword", "mingwang_jian");
	   
	prepare_skill("hand","dashou_yin");
	
	set("no_kill",1);
	set("no_���־�",1);
	set_temp("apply/no_���־�",1);
	set_temp("apply/no_ǧ���׹�",1);
	set_temp("apply/no_��˼����",1);
	set_temp("apply/no_�ƺ�����",1);
	set_temp("apply/no_���־�",1);
	set_temp("apply/no_�������",1);
	set_temp("apply/no_ƴ��",1);
	set_temp("apply/no_��Ѫ��",1);
	set_temp("apply/no_���־�",1);
	
	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 850);
    set("apply/damage", 720);

	set("chat_chance", 5);
	carry_object("xblade")->wield();
	carry_object("p_jiasha")->wear();
	carry_object("sengmao")->wear();

	set("family/family_name","ѩɽ��");
	
	call_out(do_full, 7200);
	
}

static void do_full(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(!me->query_temp("fight/is_fighting"))
	{
		message_vision("\n$HIR$N�������£��˹���Ϣ��", me);
		me->set("mp",me->query("max_mp"));
		me->set("hp",me->query("max_hp"));
	}
	me->call_out(do_full, 7200);
}

virtual char * chat_msg()				
{
	switch(random(4))
	{
	case 0:
		return "���С���üͷһ̧���ȵ�������Ѿ�Ĳ���ʶ�ң��Ҿ��Ǵ�˵�е�ѩɽ�ɿ�ɽ�������С��졣��";
	case 1:
		return "���С����Ȼ˵�������Ҿ���ɱ�ָ���ϴ�Ѫ������һ�����Ӳ�ʧ��Ŷ�� ��";
	case 2:
		return "���С�����Ȼ̾�������뵱��,�Һ����������������Ľ��һ��,���ȴ......��";
	
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * ling = PresentName("xblade", IS_ITEM);
	if(query_weapon() == ling && ling)
	{
		switch(random(3))
		{
		case 0:
			perform_action("blade jixue", 1);
			break;
		case 1:
			perform_action("force fanchang", 1);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		}
	}
	else
	{
		switch(random(4))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("hand tianyin", 1);
			break;
		case 2:
			perform_action("force fanchang", 1);
			break;
		case 3:
			carry_object("xblade")->wield();
			break;
		}
	}
	return 0;
}

void die()
{
	CContainer * obj = environment();
	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	CChar * me;
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		me = (CChar *)obj;  
		if(!userp(me))	continue;
		//���һ���򵹵��˽���ý�����һ����ʸ�
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>135 )
		{
			message_vision("$HIR$N�����ź���̾������һ�����˻����ˣ����Ľ������Ѿ��첻��ȥ���𣿡�", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level7"))
				me->set("18dy/level8",1);
			me->move(load_room("�߲��������"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
