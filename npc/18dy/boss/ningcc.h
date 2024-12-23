//ningcc ��CC 
//������ʮ����BOSS

BOSS_BEGIN(CNningcc);

virtual void create()
{	
	set_name("��CC", "ning cc");
	set("title", "�ٱ�����");
	set("gender", "Ů��");
	set("icon", old_nun);
	set("class", "bonze");
	set("age", 68);
	set("long",  "������ƮƮ����Ȼ���������鿴��˵�����ĺ�ƽ������");
		
	set("str", 119);
	set("int", 119);
	set("con", 119);
	set("dex", 95);
	set("per",35);
	set("level",220);
	set("repute",50000000);

	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
	
	set_inquiry("��ü", "��ü��Ҫ�����ڿ��׼��");
	set_inquiry("�����Ѳ�", "������ʮ��,�����������,����������");
	set_inquiry("��ͥ", "��ͥ�ǽ����������صİ���֮һ�����ŷ��ѩ������������ͥ�������ڡ�");

	set("hp", 162000);
	set("max_hp",162000);
	set("max_mp", 82000);
	set("mp", 82000);
	set("mp_factor", 500);
	
	set("combat_exp", 260000000);
	set("score", 500000);
	
	set_skill("persuading", 830);
	set_skill("force", 830);
	set_skill("dodge", 830);
	set_skill("finger", 830);
	set_skill("parry", 830);
	set_skill("strike", 830);
	set_skill("sword", 830);
	set_skill("literate", 830);
	set_skill("mahayana", 830);
	set_skill("buddhism", 830);
	set_skill("jinding_zhang", 830);
	set_skill("tiangang_zhi", 830);
	set_skill("huifeng_qijue", 830);
	set_skill("yanxing_dao", 830);
	set_skill("zhutian_bu", 830);
	set_skill("linji_zhuang", 830);
	set_skill("huifeng_jian", 830);

	map_skill("force","linji_zhuang");
	map_skill("finger","tiangang_zhi");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");
	map_skill("sword","huifeng_qijue");
	map_skill("blade","yanxing_dao");
	map_skill("parry","huifeng_jian");
	
	prepare_skill("finger","tiangang_zhi");
	prepare_skill("strike","jinding_zhang");
	
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
    carry_object("changjian")->wield();

	set("family/family_name","������");
	
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
		return "�������ĵ����𣺡������䣬��֮����˶ϳ�����";
	case 1:
		return "��CC��̾�����������粻֪���ɺã��� ";
	case 2:
		return "��CC�����˸е������»���ͥ��";
	case 3:
		return "����������ҹ�գ���̾�������ط��߾���඼��ɾ����ˡ���";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * item = PresentName("changjian", IS_ITEM);
	if(query_weapon() == item && item)
	{
		switch(random(5))
		{
		case 0:
			perform_action("sword mixhit", 1);
			break;
		case 1:
			perform_action("strike bashi", 1);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		case 3:
			perform_action("finger lingkong", 1);	
			break;
		case 4:
			perform_action("sword mie", 1);
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
			perform_action("finger lingkong", 1);	
			break;
		case 2:
			perform_action("strike bashi", 1);
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
			message_vision("$HIR$N��������Ȼ$n����ƶ�����,�Ǿ������㵽��һ��ȥ�ɣ���", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level15"))
				me->set("18dy/level16",1);
			me->move(load_room("�߲���������"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
