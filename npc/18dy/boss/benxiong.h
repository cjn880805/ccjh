//benxiong ���� 
//�������߲�BOSS

BOSS_BEGIN(CNbenxiong);

virtual void create()
{
	set_name("����", "ben xiong");
	set("title", "��Ŀ��");
	set("gender", "����");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "�����ޱ߷�,��ͷ���Ե�����,������������֪��������������");

	set("per",28);
	set("str", 105);
	set("int", 105);
	set("con", 105);
	set("dex", 95);
	set("level",210);
	set("repute",50000000);

	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
	
	set_inquiry("������", "û����,ֹͣ�����ˡ�");
	set_inquiry("ʮ�˵���", "������,�Ҿͳ���������ػ���");
	set_inquiry("�컨��", "�컨��ص������Ѿ���ȥ�ˡ�");

	set("hp", 122000);
	set("max_hp", 122000);
	set("mp", 67000);
	set("max_mp", 67000);
	set("mp_factor", 500);
	
	set("combat_exp", 200000000);
	set("score", 500000);
	
	set_skill("cuff", 760);
	set_skill("force", 760);
	set_skill("dodge", 760);
	set_skill("parry", 760);
	set_skill("blade", 760);
	set_skill("strike",760);
	set_skill("unarmed", 760);
	set_skill("zixia_shengong", 760);
	set_skill("poyu_quan", 760);
	set_skill("fanliangyi_dao", 760);
	set_skill("hunyuan_zhang", 760);
	set_skill("lonely_sword", 760);
	set_skill("huashan_shenfa",760);
	set_skill("literate", 760);
	set_skill("zhengqijue", 760);

	map_skill("cuff", "poyu_quan");
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "lonely_sword");
	map_skill("blade", "fanliangyi_dao");
	map_skill("strike", "hunyuan_zhang");
	
	prepare_skill("strike","hunyuan_zhang");
	prepare_skill("cuff","poyu_quan");
	
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

	set("apply/armor", 1000);
    set("apply/damage", 870);

	set("chat_chance", 5);

    carry_object("gangdao")->wield();

	set("family/family_name","��ɽ��");
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
	switch(random(3))
	{
	case 0:
		return "������ɫ��������겻�ѣ�̾���������޵�һս,˫����Ӣ���˲��ء���";
	case 1:
		return "����˵�������컨�����彣���� ";
	case 2:
		return "�����ƺ�������ʲô����Ȼ˵���������·��Ƴ��ұ�,һ�뽭�����´ߡ���";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * ling = PresentName("gangdao", IS_ITEM);
	if(query_weapon() == ling && ling)
	{
		switch(random(3))
		{
		case 0:
			perform_action("blade sanshen", 1);
			break;
		case 1:
			perform_action("cuff leidong", 1);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		}
	}
	else
	{
		switch(random(3))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("cuff leidong", 1);
			break;
		case 2:
			perform_action("strike wuji", 1);
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>150 )
		{
			message_vision("$HIR$N������$n�㾹Ȼɱ���ң��컨����ֵܽ��ò���Ź���ģ���", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level10"))
				me->set("18dy/level11",1);
			me->move(load_room("�߲���������"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
