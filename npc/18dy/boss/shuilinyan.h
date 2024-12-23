//shuilinyan ˮ���� 
//������ʮ�Ĳ�BOSS

BOSS_BEGIN(CNshuilinyan);

virtual void create()
{	
	set_name("ˮ����", "shui lin yan");
	set("title", "�����ǳ�");
	set("gender", "Ů��");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "��һ������ü���续���º���ţ�����һ�������廪�����£���Ц��Ҳ�����ºͺͣ����������Ƶġ���");
		
	set("str", 123);
	set("int", 123);
	set("con", 123);
	set("dex", 95);
	set("per",38);
	set("level",220);
	set("repute",50000000);

	set("chat_chance_combat", 15);		//����NPCʹ�þ��еļ���
	
	set_inquiry("���ϰ�", "��֪�������������Ŀɺá�");
	set_inquiry("�轣", "�Ȼ���,�ٽ���,������ף�");
	set_inquiry("�����ǳ�", "�����ҵĴºš�");

	set("hp", 182000);
	set("max_hp",182000);
	set("max_mp", 92000);
	set("mp", 92000);
	set("mp_factor", 500);
	
	set("combat_exp", 290000000);
	set("score", 500000);
	
	set_skill("force", 870);
	set_skill("unarmed", 870);
	set_skill("dodge", 870);
	set_skill("parry", 870);
	set_skill("finger",870);
	set_skill("hand",870);
	set_skill("strike", 870);
    set_skill("sword",870);

	set_skill("zhemei_shou",870);
	set_skill("liuyang_zhang",870);
    set_skill("tianyu_qijian",870);
	set_skill("yueying_wubu",870);
	set_skill("bahuang_gong", 870);
	set_skill("rouqing_zhi",870);

	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
    map_skill("strike","liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
    map_skill("sword","tianyu_qijian");
	map_skill("finger","rouqing_zhi");

	if(random(2))
	{
		prepare_skill("strike","liuyang_zhang");
		prepare_skill("hand","zhemei_shou");
	}
	else
		prepare_skill("finger","rouqing_zhi");
	
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

	set("apply/armor", 1220);
    set("apply/damage", 1090);

	set("chat_chance", 5);
    carry_object("changjian")->wield();

	set("family/family_name","���չ�");
	
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
		return "ˮ����������֣����˷���ͷ���µļ�����˿������������������ˮ�����ӻ���Ӱ����ѵ���������";
	case 1:
		return "ˮ�����ƺ�������ʲô��ҡ��ҡͷ�������������ɴ���׷�䣬ֻ�ǵ�ʱ���Ȼ����";
	case 2:
		return "ˮ�������ĵ�ð��һ�䣬���绪������";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * item = PresentName("changjian", IS_ITEM);
	if(query_weapon() == item && item)
	{
		switch(random(3))
		{
		case 0:
			perform_action("sword san", 1);
			break;
		case 1:
			perform_action("sword kuangwu", 1);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		}
	}
	else
	{
		switch(random(4))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("strike zhong", 1);
			break;
		case 2:
			perform_action("finger caiyue", 1);
			break;
		case 3:
			perform_action("hand duo",1);
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
			message_vision("$HIR$N��������ϧ���ϰײ���,Ҫ��$n��ô���������ǵ�˫������", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level17"))
				me->set("18dy/level18",1);
			me->move(load_room("�߲�������"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
