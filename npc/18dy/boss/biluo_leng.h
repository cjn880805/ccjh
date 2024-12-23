//yijianfeixian �� 
//������һ��BOSS

BOSS_BEGIN(CNbiluo_leng);

virtual void create()
{
	set_name("��", "leng");
	set("title", "�����Ȫ");
	set("gender", "Ů��");
	set("icon", young_woman3);
	set("age", 88);
	set("long",  "һ��������Ů�ӣ���֬������ˮ�۲���������ò֮���������ѩһ����Ʋ�ʳ�˼��̻��ģ����");
    
	set("str", 75);
	set("int", 75);
	set("con", 75);
	set("dex", 75);
	set("per",30);
	set("level",160);

	set("chat_chance_combat", 25);		//����NPCʹ�þ��еļ���
	
	set_inquiry("������", "�����˵��ֵ����ڶ������ﰡ��");
	set_inquiry("��", "�����Ҽ��ǿ���û���ĵ�,Ҳ�ǰ˽�������");
	set_inquiry("ն����", "���..���..����󴫸��˹��ŵ��ӿ���Ц���ˡ�");

	set("hp", 62000);
	set("max_hp", 62000);
	set("mp", 37000);
	set("max_mp", 37000);
	set("mp_factor", 500);
	
	set("combat_exp", 100000000);
	set("score", 500000);
	
	set_skill("zhanjiang_jue", 600);
	set_skill("blade", 600);
	set_skill("guimei_shenfa", 600);
	set_skill("dodge", 600);
	set_skill("hunyuan_yiqi", 600);
	set_skill("force", 600);
	set_skill("finger", 600);
	set_skill("fengyu_wuqingzhi", 600);
	set_skill("zhongpingqiang", 600);
	set_skill("wuhuduanmendao", 600);

	map_skill("blade", "zhanjiang_jue");
	map_skill("finger", "fengyu_wuqingzhi");
	map_skill("dodge", "guimei_shenfa");
	map_skill("force", "hunyuan_yiqi");
	map_skill("parry", "zhanjiang_jue");

	prepare_skill("finger","fengyu_wuqingzhi");
	
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
	
	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 650);
    set("apply/damage", 520);

	set("chat_chance", 5);
    carry_object("dadao")->wield();

	set("family/family_name","�һ���");
	
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
		return "������üͷ��̾������ն������Ҫ��������,��ϧ���ڵ��˶������ĺ�,�ҵĶ����书��Ҫʧ���ˡ���";
	case 1:
		return "����������»�Ȫ����һ��̾Ϣ��������������� ";
	case 2:
		return "��������Զ������ͷ˵��������������һ���Ͷ����İ��ɡ���";
	
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * ling = PresentName("dadao", IS_ITEM);
	if(query_weapon() == ling && ling)
	{
		switch(random(2))
		{
		case 0:
			perform_action("club killyou", 1);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		}
	}
	else
	{
		switch(random(2))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("finger rain", 1);
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>120 )
		{
			message_vision("$HIR$N���Ŷ��˵�ն�������������$n������û�뵽�书Ҳ�ǻ��˲��İ�����", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level4"))
				me->set("18dy/level5",1);
			me->move(load_room("�߲���ɽ����"));
			break;
		}
	}

	CNbossnpc::die();
}

BOSS_END;
