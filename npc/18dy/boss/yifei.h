//yifei �׷� 
//���������BOSS

BOSS_BEGIN(CNyifei);

virtual void create()
{
	set_name("�׷�", "yi fei");
	set("title", "һ������");
	set("gender", "����");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "�����ĸߴ�����,�������������֮��,�ý��������Ů��һ���㵹��");
   
	set("str", 95);
	set("int", 95);
	set("con", 95);
	set("dex", 95);
	set("per",24);
	set("level",200);
	set("repute",50000000);

	set("chat_chance_combat", 20);		//����NPCʹ�þ��еļ���
	
	set_inquiry("����", "Ψ�ж���,�������ġ�");
	set_inquiry("Ү����", "�����ﻹ��˭��ʶ����");
	set_inquiry("����һ��", "�ļ�ʮ��Ĺ���������͸��һ�С�");

	set("hp", 102000);
	set("max_hp", 102000);
	set("mp", 57000);
	set("max_mp", 57000);
	set("mp_factor", 500);
	
	set("combat_exp", 180000000);
	set("score", 500000);
	
	set_skill("force", 720);
	set_skill("sword", 720);
	set_skill("dodge", 720);
	set_skill("parry", 720);
	set_skill("unarmed",720);
	set_skill("strike",720);
	set_skill("finger",720);
	set_skill("literate",720);
	set_skill("taoism",720);

	set_skill("xiantian_qigong", 720);
	set_skill("xiantian_gong", 720);
	set_skill("quanzhen_jianfa",720);  //ȫ�潣
	set_skill("quanzhen_jian",720);  //ȫ�潣
	set_skill("jinyan_gong", 720);   //���㹦
	set_skill("haotian_zhang", 720);    //�����
	set_skill("sun_finger",720);  //һ��ָ

	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jianfa");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jianfa");
	map_skill("strike", "haotian_zhang");
	map_skill("finger","sun_finger");

	prepare_skill("finger","sun_finger");
	prepare_skill("strike","haotian_zhang");
	
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

	set("apply/armor", 900);
    set("apply/damage", 770);

	set("chat_chance", 5);
    carry_object("changjian")->wield();

	set("family/family_name","ȫ���");
	
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
		return "�׷��������ε�̾����������ƽֻ��Ƿ���ˡ���";
	case 1:
		return "�׷����о�����Ȼһ��������������ȫ��һ��������ľ������ڶ��顣��";
	case 2:
		return "�׷ɹ���һЦ�������ȵ�����ȫ��ı���������ʩչ����,�������ơ���";
	case 3:
		return "�׷ɹ���һЦ�������ȵ������Һ�������ʱ�������Ǹ��������Դ󷢣�������Ҳ�����������ȫ�����ϵľ�ѧ����";
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
			perform_action("sword ding", 1);
			break;
		case 1:
			perform_action("strike ju", 1);
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
			perform_action("strike ju", 1);
			break;
		case 2:
			perform_action("finger qiankun", 1);
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>140 )
		{
			message_vision("$HIR$N�Ļ��������������ն����������ͨ��,���ɴ򲻹�$n,$n����ȥ��һ���ˣ���", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level8"))
				me->set("18dy/level9",1);
			me->move(load_room("�߲��𺣵���"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
