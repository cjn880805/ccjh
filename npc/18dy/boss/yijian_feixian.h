//yijianfeixian һ������ 
//���Ź�BOSS

BOSS_BEGIN(CNyijian_feixian);

virtual void create()
{
	set_name("һ������", "yijian feixian");
	
	set("gender", "����");
	set("title", "���");
	set("age", 128);
	set("long", "��������룬��ɫ����֮��,���������϶�Ѭ���㣬ñ����׺��һ��������ϴ���ֻ���ָ��һ���������ӵĴ�硣�������ϵ��˼��������ŷ�ɥ����");
    
	set("str", 65);
	set("int", 65);
	set("con", 65);
	set("dex", 65);
	set("per",27);
	set("level",150);

	set("chat_chance_combat", 30);		//����NPCʹ�þ��еļ���
	
	set_inquiry("�������", "�������˲���ʧ,������˰���");
	set_inquiry("�ܼ�", "����Ҫ��,,,�������Ҫ��,,,�����ǲ�����...");
	set_inquiry("ľ�˾��ֲ�", "���ǵ����Һ��Ȼ�ˮ��Ц���ǽ����˴�ľ�ĵط�,���֪������˭�ڡ�");


	set("hp", 52000);
	set("max_hp", 52000);
	set("mp", 42000);
	set("max_mp", 42000);
	set("mp_factor", 500);
	
	set("combat_exp", 80000000);
	set("score", 500000);
	
	set_skill("force", 550);             // �����ڹ�
    set_skill("finger", 550);            // ����ָ��
    set_skill("unarmed", 550);           // ����ȭ��
    set_skill("dodge", 550);             // ��������
    set_skill("parry", 550);             // �����м�
    set_skill("sword", 550);             // ��������
    set_skill("pixie_jian", 550);        // ��а����
    set_skill("changquan", 550);         // ̫�泤ȭ
    set_skill("literate", 550);          // ����ʶ��
    set_skill("kuihua_xinfa", 550);      // �����ķ�
	
    map_skill("force", "kuihua_xinfa");
    map_skill("sword", "pixie_jian");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "pixie_jian");
    map_skill("parry", "pixie_jian");
	
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

	set("apply/armor", 700);
    set("apply/damage", 570);

	set("chat_chance", 5);
    carry_object("xiuhua")->wield();
    carry_object("yan_dress")->wear();

	set("family/family_name","�������");
	
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
		return "һ�����������˸еĿ��˿��㣬�����̾�˿�����";
	case 1:
		return "һ������̾�˿�������ƤЬƤЬ����ô����ô��ĥ�� ";
	case 2:
		return "һ����������˵����ľ��,ľ��,���İ���ľ������ôÿ�β����������";
	}
	return 0;	
}

virtual char * chat_msg_combat()
{
	CContainer * xiuhua = PresentName("xiuhua", IS_ITEM);
	if(query_weapon() == xiuhua && xiuhua)
	{
		switch(random(3))
		{
		case 0:
			perform_action("sword cimu", 1);
			break;
		case 1:
			perform_action("sword touzi", 1);
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
			carry_object("xiuhua")->wield();
			break;
		case 2:
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>115 )
		{
			message_vision("$HIR$N��Ȼ�������벻������ʮ��·��а������������޵���,���쾹Ȼ����$n����,�±߻����ֵ�Ϊ�ұ���ġ�", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level3"))
				me->set("18dy/level4",1);
			me->move(load_room("�߲��������"));
			break;
		}
	}

	CNbossnpc::die();
}

BOSS_END;
