//zhangdanfeng �ŵ��� 
//������ʮ���BOSS

BOSS_BEGIN(CNzhangdanfeng);

virtual void create()
{	
	set_name("�ŵ���", "zhang dan feng");
	set("title", "��ͷ����");
	set("gender", "����");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "�����Ŀ���������һ�ž�����˪�����ϴ���ǳǳ��΢Ц����������¶��һ˿�����������üͷ����ڵĵ���������ôһ����Ƥ��");
		
	set("str", 125);
	set("int", 125);
	set("con", 125);
	set("dex", 95);
	set("per",25+random(10));
	set("level",220);
	set("repute",50000000);

	set("chat_chance_combat", 15);		//����NPCʹ�þ��еļ���
	
	set_inquiry("��ͷ�ܶ�", "����������ͷ�ɵ��ֵ����齨�����İ��ɡ�");
	set_inquiry("�Ĵ����", "�����Ĵ�����ҡ���С¥�����С��졢��ˮ���ˡ�");
	set_inquiry("��ɽ��", "�������ǵĵ��ˡ�");

	set("hp", 192000);
	set("max_hp",192000);
	set("max_mp", 95000);
	set("mp", 95000);
	set("mp_factor", 500);
	
	set("combat_exp", 310000000);
	set("score", 500000);
	
	set_skill("force", 900);
	set_skill("taiji_shengong", 900);
	set_skill("dodge", 900);
	set_skill("tiyunzong", 900);
	set_skill("unarmed", 900);
	set_skill("taiji_quan", 900);
	set_skill("parry", 900);
	set_skill("sword", 900);
	set_skill("taiji_jian", 900);
	set_skill("blade", 900);
	set_skill("taiji_dao", 900);
	set_skill("taoism", 900);
	set_skill("literate", 900);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("blade", "taiji_dao");
	
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
	set_temp("apply/���־�",10+random(10));
	set_temp("apply/���־�",random(10));
	
	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 1250);
    set("apply/damage", 1120);

	set("chat_chance", 5);
    carry_object("changjian")->wield();

	set("family/family_name","�䵱��");
	
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
		return "�ŵ���Ǻ�һЦ����������ͷ����ɽ�ǳ�ս�۵���䶯��������������";
	case 1:
		return "�ŵ��������Ц�������Ҿ����Ĵ����֮�ס������ӯ������";
	case 2:
		return "�ŵ��㸺���ⲽ�������˵�������Ҳ��ʽ����Ƿ��Ѿ��ܶ����ˡ���";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * item = PresentName("changjian", IS_ITEM);
	if(query_weapon() == item && item)
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
	}
	else
	{
		switch(random(6))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("unarmed zhen", 1);
			break;
		case 2:
			perform_action("unarmed ji", 1);
			break;
		case 3:
			perform_action("unarmed zhenup",1);
			break;
		case 4:
			perform_action("unarmed zhan",1);
			break;
		case 5:
			perform_action("unarmed jielidali",1);
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>163 )
		{
			message_vision("$HIR$N��������������ˣ�������$n��������һ�����ˣ���", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level18"))
				me->set("18dy/level19",1);
			me->move(load_room("�߲��������"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
