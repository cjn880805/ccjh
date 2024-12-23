//fengyucansheng ������� 
//������ʮ����BOSS

BOSS_BEGIN(CNfengyucansheng);

virtual void create()
{	
	set_name("�������", "fengyu cansheng");
	set("title", "����Ʈ��");
	set("gender", "����");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "ֻ��һ�����ۻƹڵĵ��˸���վ��һ������£�����ưư����Ȼ���������鿴��˵�����ĺ�ƽ������");

	set("str", 121);
	set("int", 121);
	set("con", 121);
	set("dex", 95);
	set("per",35);
	set("level",220);
	set("repute",50000000);

	set("chat_chance_combat", 15);		//����NPCʹ�þ��еļ���
	
	set_inquiry("����", "�þ�û�������ˡ�");
	set_inquiry("���޶���", "��֪����ô����");
	set_inquiry("��ʿ", "��ʿҲ�ǿ��Խ��ġ�");

	set("hp", 177000);
	set("max_hp",177000);
	set("max_mp", 87000);
	set("mp", 87000);
	set("mp_factor", 500);
	
	set("combat_exp", 280000000);
	set("score", 500000);
	
	set_skill("throwing", 850);
	set_skill("feixing_shu", 850);        
	set_skill("force", 850);
	set_skill("huagong_dafa", 850);
	set_skill("dodge", 850);
	set_skill("zhaixinggong", 850);
	set_skill("strike",850);
	set_skill("xingxiu_duzhang", 850);
	set_skill("parry", 850);
	set_skill("literate", 850);
	set_skill("sanyin_wugongzhao", 850);
	set_skill("claw", 850);
	set_skill("poison", 850);
	set_skill("chousui_zhang", 850);

	map_skill("force", "huagong_dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui_zhang");
	map_skill("parry", "feixing_shu");
	map_skill("unarmed", "xingxiu_duzhang");
	map_skill("claw", "sanyin_wugongzhao");
        
	prepare_skill("strike", "chousui_zhang");
	prepare_skill("claw", "sanyin_wugongzhao");
	
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
	set_temp("apply/ʩ����",random(30)+20);
	
	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 1200);
    set("apply/damage", 1050);

	set("chat_chance", 5);

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
	switch(random(3))
	{
	case 0:
		return "����������������������Զ�����ƺ��ڵȴ���һ��˼���Ѿõ��ˡ�";
	case 1:
		return "��������ƺ�������ʲô��ͻȻ˵������˫ľ�ǻ�ɽ���ϴ󡣡�";
	case 2:
		return "�������ת���֣�����̾�����������������������أ���";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	
	switch(random(6))
	{
	case 0:
		perform_action("force recover", 0);
		break;
	case 1:
		carry_object("corpse_ob", 1);
		perform_action("strike throw", 1);	
		break;
	case 2:
		perform_action("force huo", 0);
		break;
	case 3:
		perform_action("force hpsuck", 1);
		break;
	case 4:
		perform_action("force suck", 1);
		break;
	case 5:
		perform_action("strike huoqiu", 1);	
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>163 )
		{
			message_vision("$HIR$N�������úú�,$nͨ����,���Խ���һ���ˣ���", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level16"))
				me->set("18dy/level17",1);
			me->move(load_room("�߲���ĥ����"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
