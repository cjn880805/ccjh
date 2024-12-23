//tudou ���� 
//������ʮһ��BOSS

BOSS_BEGIN(CNtudou);

virtual void create()
{	
	set_name("����", "tu dou");
	set("title", "����");
	set("gender", "����");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "�������������,����ȥһ��������������,�������ͱ��������ð��������н����˶���Ľ�ġ�");
	
	set("str", 117);
	set("int", 117);
	set("con", 117);
	set("dex", 95);
	set("per",25);
	set("level",220);
	set("repute",50000000);

	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
	
	set_inquiry("����", "�����Ǹ��������û���ˡ�");
	set_inquiry("MM", "������׼�������κ�MM");
	set_inquiry("������", "��֪��˭���ǵ�����һ");

	set("hp", 157000);
	set("max_hp",157000);
	set("max_mp", 80000);
	set("mp", 80000);
	set("mp_factor", 500);
	
	set("combat_exp", 250000000);
	set("score", 500000);
	
	set_skill("force", 825);
    set_skill("dodge", 825);
    set_skill("parry", 825);
	set_skill("strike", 825);
	set_skill("lingfa", 825);
	set_skill("shenghuo_lingfa", 825);
	set_skill("qiankun_danuoyi", 825);
	set_skill("shenghuo_xinfa", 825);
	set_skill("hanbing_mianzhang", 825);
	set_skill("shenghuo_shengong", 825);
	
	map_skill("parry", "qiankun_danuoyi");
	map_skill("force", "shenghuo_shengong");
	map_skill("dodge", "qiankun_danuoyi");
	map_skill("lingfa", "shenghuo_lingfa");
    map_skill("strike", "hanbing_mianzhang");
	
	prepare_skill("strike","hanbing_mianzhang");
	
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
    carry_object("shenghuo_ling")->wield();

	set("family/family_name","����");
	
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
		return "������ʤ�п���̾�������뵱�������ٷ�,���ȴ......��";
	case 1:
		return "����˵���������ź���¥�����ˡ��� ";
	case 2:
		return "�����ƺ��������˶����µĻ��䣬��Ĭ�˺ܾã������������������������������嶼�ۡ��ε�����ë���ʡ���";
	
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * ling = PresentName("shenghuo_ling", IS_ITEM);
	if(query_weapon() == ling && ling)
	{
		switch(random(3))
		{
		case 0:
			perform_action("lingfa duo", 1);
			break;
		case 1:
			perform_action("lingfa xiyanling", 1);
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
			perform_action("strike xixue", 1);
			break;
		case 1:
			perform_action("force recover", 0);	
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>162 )
		{
			message_vision("$HIR$N�������С��,�����Ҷ��Ҷ�,$n�͵�����ȥ�ҿ��İ��ұ���ɣ���", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level14"))
				me->set("18dy/level15",1);
			me->move(load_room("�߲����Ե���"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
