//bingliang_bohe �������� 
//������ʮ��BOSS

BOSS_BEGIN(CNbingliang_bohe);

virtual void create()
{
	set_name("��������", "bingliang buhe");
	set("title", "�������");
	set("gender", "Ů��");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "��ü���续���º���ţ�Ц�����������֡�");
	
	set("str", 115);
	set("int", 115);
	set("con", 115);
	set("dex", 95);
	set("level",218);
	set("per",32);
	set("repute",50000000);

	set("chat_chance_combat", 15);		//����NPCʹ�þ��еļ���
	
	set_inquiry("˼˼", "�������ﰡ��");
	set_inquiry("�̽�", "����ׯ�����");

	set("hp", 152000);
	set("max_hp",152000);
	set("max_mp", 78000);
	set("mp", 78000);
	set("mp_factor", 500);
	
	set("combat_exp", 240000000);
	set("score", 500000);
	
	set_skill("force", 820);
	set_skill("unarmed", 820);
	set_skill("dodge", 820);
	set_skill("parry", 820);
	set_skill("hand",820);
	set_skill("staff", 820);
	set_skill("hamagong", 820);
	set_skill("chanchu_bufa", 820);
	set_skill("shexing_diaoshou", 820);
	set_skill("lingshe_zhangfa", 820);
	set_skill("xunshou_shu",820);
	set_skill("poison", 820);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	map_skill("unarmed", "shexing_diaoshou");
	map_skill("hand", "shexing_diaoshou");
	map_skill("parry", "lingshe_zhangfa");
	map_skill("staff", "lingshe_zhangfa");
	
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

	set("apply/armor", 1150);
    set("apply/damage", 1000);

	set("chat_chance", 5);
    carry_object("shezhang")->wield();

	set("family/family_name","����ɽ��");
	
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
		return "����������������������������ֲ�֪��������ȥ��MM�ˡ���";
	case 1:
		return "��������Ц������������˯��˯����Ȼ�ѣ���Ǯ�����ֳ���";
	case 2:
		return "�������������̾�˿������������û�����ǰ���ֵܽ����ڽ��������ӡ���";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * item = PresentName("shezhang", IS_ITEM);
	if(query_weapon() == item && item)
	{
		
		switch(random(4))
		{
		case 0:
			perform_action("staff pili", 1);
			break;
		case 1:
			perform_action("force powerup", 0);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		case 3:
			perform_action("unarmed wugu", 1);
			break;
		}
	}
	else
	{
		switch(random(3))
		{
		case 0:
			perform_action("force powerup", 0);
			break;
		case 1:
			perform_action("force recover", 0);
			break;
		case 2:
			perform_action("unarmed wugu", 1);
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>160 )
		{
			message_vision("$HIR$N����������������,�һؼ�ȥ�������ˣ���", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level13"))
				me->set("18dy/level14",1);
			me->move(load_room("�߲���Ƥ����"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
