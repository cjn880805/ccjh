//dajianshi_lante ��ʦ����
//��Ȫ֮·BOSS

//wuqing 2001-11-29

BOSS_BEGIN(CNdajianshi_lante);

virtual void create()
{
	set_name("��ʦ����", "dajianshi lante");
	
	set("gender", "����");
	set("age", 58);
	set("long", "��������ǿ�ΰ����ʮ������ͣ�����ɫ�ɲ��ۣ���΢�����ã�Ũü���ۣ��߱����ڣ�һ���ķ��Ĺ����������з�˪֮ɫ������֮�ʣ��������ơ�");
    
	set("str", 55);
	set("int", 55);
	set("con", 55);
	set("dex", 55);
	set("per",28);
	set("level",130);

	set("chat_chance_combat", 30);		//����NPCʹ�þ��еļ���
	
	set_inquiry("�Ʒ�", "������Ҷ����ˣ������ڿɺã�");
	set_inquiry("���", "�����Ҵ�硣");	
	set_inquiry("����", "����Ʈ�����һ�ˡ�");
	set_inquiry("����", "���������硣");
	set_inquiry("�˽���", "�����ǰ��ֵ�һ�����ģ�");

	set("hp", 32000);
	set("max_hp", 32000);
	set("mp", 22000);
	set("max_mp", 22000);
	set("mp_factor", 500);
	
	set("combat_exp", 40000000);
	set("score", 500000);
	
	set_skill("force", 400);
    set_skill("dodge", 400);
    set_skill("parry", 400);
	set_skill("unarmed", 400);
    set_skill("jiuyang_shengong", 400);
	set_skill("lingfa", 400);
	set_skill("shenghuo_lingfa", 400);
	set_skill("qiankun_danuoyi", 400);
	set_skill("shenghuo_xinfa", 400);
	set_skill("huntian_qigong", 400);
	set_skill("xianglong_zhang", 400);

	map_skill("parry", "qiankun_danuoyi");
	map_skill("force", "jiuyang_shengong");
	map_skill("dodge", "qiankun_danuoyi");
	map_skill("lingfa", "shenghuo_lingfa");
	map_skill("unarmed", "xianglong_zhang");	//����NPC�Ļ���ȭ��װ��������
	
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

	set("apply/armor", 450);
    set("apply/damage", 320);

	set("chat_chance", 5);
	carry_object("shenghuo_ling")->wield();

	set("����/gaibang/wuhui",1);
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

virtual char * chat_msg()				//NPC�Զ�����
{
	switch(random(3))
	{
	case 0:
		return 	"��ʦ����̾�˿�������������....����������������������";
	case 1:
		return 	"��ʦ����˵�������ֵ��ǽ�����֪�ɺã���֪�����ֵܼ�ʱ����һ��Ⱦơ���";
	case 2:
		if(!random(100))
			return 	"��ʦ���������̣��ƺ��޷���Ҳ�޷���ס��̾�˿���������Τ�����ĵ���ʵ����������ͣ���λ�ֵܣ����ǧ��ҪΪ��ֻ��Ե���ʧȥ����ѽ����";
		else
			return 	"��ʦ����˵�������ֵ��ǽ�����֪�ɺã���֪�����ֵܼ�ʱ����һ��Ⱦơ���";
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
		switch(random(3))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("unarmed xianglong", 1);	//�����Ƶľ���
			break;
		case 2:
			perform_action("unarmed wuhuei", 1);	//�����Ƶľ���
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id")) && me->query("level")>105)
		{
			message_vision("$HIR$N�������ŵ�����$n��������������...��Ȼ�ܴ����..����δ˵���Ѿ����ض�����", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level1"))
				me->set("18dy/level2",1);
			me->move(load_room("�߲��κ���"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
