//xinxinshou ��ɽ������ 
//�����ھŲ�BOSS

BOSS_BEGIN(CNxinxinshou);

virtual void create()
{
	set_name("��ɽ������", "huashan xinxinshou");
	set("title", "��ħ");
	set("gender", "����");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "������ȥ�ǳ��Ͱ�,�ؽ���ϵ��һ��컨,���е��ǰѳ�������������ƽ����һ����");
   
	set("str", 115);
	set("int", 115);
	set("con", 115);
	set("dex", 95);
	set("per",27);
	set("level",216);
	set("repute",50000000);

	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
	
	set_inquiry("���¾Ž�", "�Ž�һ���ƾ����±�����");
	set_inquiry("�컨��", "���Ǹ��˲żüõİ��,��ϧ���ڶ��Ѿ������ˡ�");
	set_inquiry("���޵�", "�������ǵжԵİ���,�����ڶ��ϧ����а����");

	set("hp", 142000);
	set("max_hp",142000);
	set("max_mp", 77000);
	set("mp", 77000);
	set("mp_factor", 500);
	
	set("combat_exp", 220000000);
	set("score", 500000);
	
	set_skill("cuff", 800);
	set_skill("force", 800);
	set_skill("dodge", 800);
	set_skill("parry", 800);
	set_skill("sword", 800);
	set_skill("strike",800);
	set_skill("unarmed", 800);
	set_skill("zixia_shengong", 800);
	set_skill("poyu_quan", 800);
	set_skill("huashan_sword", 800);
	set_skill("hunyuan_zhang", 800);
	set_skill("lonely_sword", 800);
	set_skill("huashan_shenfa",800);
	set_skill("literate", 800);
	set_skill("zhengqijue", 800);

	map_skill("cuff", "poyu_quan");
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "lonely_sword");
	map_skill("sword", "lonely_sword");
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

	set("apply/armor", 1100);
    set("apply/damage", 970);

	set("chat_chance", 5);
    carry_object("changjian")->wield();

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
	switch(random(4))
	{
	case 0:
		return "��ɽ������˵�������컨��ء���";
	case 1:
		return "��ɽ��������������������Զ������˵���������ϡ����ܡ����䡢�������ǻ����� ��";
	case 2:
		return "��ɽ�����ֺ���˵���������޵���������Ĳ���������";
	case 3:
		return "��ɽ�����ֲ����̾�������컨���㶼��֪��,��̫��ª�����˰ɣ���";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * ling = PresentName("changjian", IS_ITEM);
	if(query_weapon() == ling && ling)
	{
		switch(random(3))
		{
		case 0:
			perform_action("sword poqi", 1);
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>155 )
		{
			message_vision("$HIR$N�͵����һ����Ѫ��ŭ�������$n��Ȼɱ����,�컨����ֵܲ���Ź���ġ�", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level12"))
				me->set("18dy/level13",1);
			me->move(load_room("�߲���������"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
