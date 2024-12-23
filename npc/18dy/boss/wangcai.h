//wangcai ���� 
//������ʮ�߲�BOSS

BOSS_BEGIN(CNwangcai);

virtual void create()
{	
	set_name("����", "wang cai");
	set("title", "��Ѫ��ʦ");
	set("gender", "����");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "����һֻ��Ȯ������ǿ׳��������壬ʮ�ֲֿ���");
		
	set("str", 140);
	set("int", 140);
	set("con", 140);
	set("dex", 95);
	set("per",25+random(10));
	set("level",220);
	set("repute",50000000);

	set("chat_chance_combat", 15);		//����NPCʹ�þ��еļ���
	
	set_inquiry("С�۷�", "��,�����Խ���,����������Ҳ��������MM�ˡ�");
	set_inquiry("����", "��˵�еĽ���ʮ������֮һ");
	set_inquiry("��Ѫ", "��ǵ���,��ʵ�Ǻܲп�ġ�");

	set("hp", 252000);
	set("max_hp",252000);
	set("max_mp", 10000);
	set("mp", 10000);
	set("mp_factor", 500);
	
	set("combat_exp", 380000000);
	set("score", 500000);
	
	set_skill("force", 970);
    set_skill("dodge", 970);
    set_skill("parry", 970);
    set_skill("sword", 970);
    set_skill("finger", 970);
	set_skill("kurong_changong", 970);
    set_skill("tiannan_step", 970);
    set_skill("duanjia_sword", 970);
    set_skill("liumai_shenjian", 970);
	set_skill("literate", 970);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("finger", "liumai_shenjian");
	map_skill("parry", "liumai_shenjian");
	map_skill("sword", "duanjia_sword");

	prepare_skill("finger", "liumai_shenjian");
	
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
	set_temp("apply/������һ",1);

	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 1400);
    set("apply/damage", 1200);

	set("chat_chance", 5);
    carry_object("changjian")->wield();

	set("family/family_name","����μ�");
	
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
		return "�����󿴿����ҿ������͵Ļ�ͷ�����ʵ����������������ô˧�Ĺ��𣿡�";
	case 1:
		return "������̾��������ʱ���ٴ�������������б�ţ���¥�����С�׳����������У������Ƶͣ���������硣�� ";
	case 2:
		return "���Ƴ���һ������̾��������������ȥ��������·����ѹߣ����ĵ�����Ȼ������˪�ޣ�һ�ν�ǰ��ε���������";
	case 3:
		return "�����������صĴյ�����ߣ�˵��������Щ������������Ҫ��ս���в��ϵ���������ſ������򡣡�";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	char msg[40];
	CContainer * item = PresentName("changjian", IS_ITEM);
	if(query_weapon() == item && item)
	{
		switch(random(4))
		{
		case 0:
			perform_action("sword jingtian", 1);
			break;
		case 1:
			perform_action("force recover",0);
			break;
		case 2:
			perform_action("sword fenglei", 1);
			break;
		case 3:
			command(snprintf(msg, 40, "unwield %ld", item->object_id()));
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
			perform_action("finger ci", 1);
			break;
		case 2:
			perform_action("finger feng", 1);
			break;
		case 3:
			perform_action("finger tan", 1);
			break;
		case 4:
			perform_action("finger guiyi", 1);
			break;
		case 5:
			if(item && ! query_weapon())
				command(snprintf(msg, 40, "wield %ld", item->object_id()));
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
			message_vision("$HIR$N����˼��ĵ�����������ô˧���Ĺ��㶼�µ����֣�$n�������ȥ���������Ŀֲ��ɣ�������������������������������������", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level20"))
				me->set("18dy/level21",1);
			me->move(load_room("�߲����ǵ���"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
