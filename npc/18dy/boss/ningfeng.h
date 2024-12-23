//ningfeng
//wuqing 2001-12-2
//�Թ�BOSS

BOSS_BEGIN(CNningfeng);

virtual void create()
{	
	set_name("����", "ningfeng");
	set("title", "��ɽ����");
	set("gender", "����");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "������׷������ĵ����ɷ硣");
	
	set("str", 45);
	set("int", 45);
	set("con", 45);
	set("dex", 45);
	set("per",40);

	set("max_hp", 10000);
	set("max_mp", 8000);
	set("mp", 8000);
	set("mp_factor", 150); 
	set("level",120);
	
	set("combat_exp",  16000000);
	set("chat_chance",  10);
	set("chat_chance_combat", 20);
	
	set_inquiry("����", "�������ڵĽ������ң�ɱ�˷Ż�̫���ˣ���ϧ�Ҳ�����ն����ħ�ˡ�");
	set_inquiry("���е��Ǹ�MM", "�������ﰡ��������������������");
	set_inquiry("��ͥ", "��ͥ�ǽ����������صİ���֮һ�������Һ�ѩ������������ͥ�������ڡ�");
	
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("sword", 350);
	set_skill("literate", 300);
	set_skill("shenzhao_gong", 300);
	set_skill("piaoyibu", 300);
	set_skill("doomsword", 350);
    
	map_skill("force", "shenzhao_gong");
	map_skill("dodge", "piaoyibu");
	map_skill("sword", "doomsword");
	map_skill("parry", "doomsword");

	carry_object("changjian")->wield();

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

	set("apply/armor", 380);
    set("apply/damage", 200);

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
		return "�뵱�����ݺὭ����ʮ�أ�ɶ������û������";
	case 1:
		return "������̾�������ƽ��������ϣ������������� ";
	case 2:
		return "��ͥ������";
	case 3:
		return "��֪����ǰ��һ�����ֵ�������ô���ˣ���";
	}
	return 0;
	
}
virtual char * chat_msg_combat()			
{
	switch(random(2))
	{
	case 0:
		perform_action("sword doomsword", 1);	
		break;
	case 1:
		perform_action("force recover", 0);	
		break;
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id")) && me->query("level")>100)
		{
			message_vision("$HIR$N�͵��³�һ����Ѫ�����������Ȼ��ˣ�$n����������һ���µ���ȥ�ɣ���", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			me->set("18dy/level1",1);
			me->move(load_room("�߲���Ȫ֮·"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;