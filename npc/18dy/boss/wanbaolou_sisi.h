//wanbaolou_sisi ˼˼ 
//�κ���BOSS

//wuqing 2001-11-29

BOSS_BEGIN(CNwanbaolou_sisi);

virtual void create()
{
	set_name("˼˼", "si si");
	set("title", "��¥¥��");
	
	set("gender", "Ů��");
	set("age", 58);
	set("long", "�������߻�����,����ȴʼ�չ��ŵ���������,Ψ�в��������������ľ������˲���������");
	set("icon", young_woman1);
    
	set("str", 55);
	set("int", 55);
	set("con", 55);
	set("dex", 55);
	set("per",40);
	set("level",140);

	set("chat_chance_combat", 30);		//����NPCʹ�þ��еļ���
	
	set_inquiry("��¥", "��,���ڼ���̫��,����һ���һ����������");
	set_inquiry("�˼�����", "�������ǣ�˭����һ��ȥ�˼���");
	set_inquiry("��Ǯ", "�ұ�����������,�κ������չ������㾹Ȼ������ô�׵������Ҳ������ˡ�");

	set("hp", 42000);
	set("max_hp", 42000);
	set("mp", 32000);
	set("max_mp", 32000);
	set("mp_factor", 500);
	
	set("combat_exp", 60000000);
	set("score", 500000);
	
	set_skill("force", 500);
    set_skill("dodge", 500);
    set_skill("parry", 500);
	set_skill("finger", 500);
    set_skill("jiuyang_shengong", 500);
	set_skill("lingfa", 500);
	set_skill("shenghuo_lingfa", 500);
	set_skill("qiankun_danuoyi", 500);
	set_skill("shenghuo_xinfa", 500);
	set_skill("huntian_qigong", 500);
	set_skill("fengyu_wuqingzhi", 500);

	map_skill("parry", "qiankun_danuoyi");
	map_skill("force", "jiuyang_shengong");
	map_skill("dodge", "qiankun_danuoyi");
	map_skill("lingfa", "shenghuo_lingfa");
	map_skill("finger", "fengyu_wuqingzhi");

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

	set("apply/armor", 550);
    set("apply/damage", 420);

	set("chat_chance", 5);
	carry_object("shenghuo_ling")->wield();

	set("family/family_name","����");
	set("death_times",1);
	
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
		return "˼˼���ĵ�˵�������뵱������ò���ҽ���,����껪��ȥ�����ʽ򡣡�";
	case 1:
		return "˼˼��̾����֪����ν������,��֪����ν�Һ��� ";
	case 2:
		return "˼˼����������Զ����̾��������¥Ҳû����,��û����ǰ�ķ���ˡ���";
	case 3:
		return "˼˼̾�˿������������������ഺ��פ��ҩ������";
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id")) && me->query("level")>110 )
		{
			message_vision("$HIR$N�������ŵĿ���$n��������һ�����ڵģ���һ�����ڵģ���", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level2"))
				me->set("18dy/level3",1);
			me->move(load_room("�߲����Ź�"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
