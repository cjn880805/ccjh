//shuizhizi ˮ���� 
//����������BOSS

BOSS_BEGIN(CNshuizhizi);

virtual void create()
{
	set_name("ˮ����", "shui zhi zi");
	set("title", "ҹ����");
	set("gender", "Ů��");
	set("icon", young_woman3);
	set("age", 38);
	set("long",  "����һλ��ĸ������ٸ��������ķ��߸������βʽ�����񻷿��ƣ�������������������Ҳ��������סü�ۣ����������ݡ�����ѩ�£�Ʈ�ݵ÷������ұ��µ���īˮ�ʣ�����������������ɡ�");

	set("per",39);
	set("str", 100);
	set("int", 100);
	set("con", 100);
	set("dex", 95);
	set("level",205);
	set("repute",50000000);

	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
	
	set_inquiry("����", "����ĳ��������վ��һ�������齨�ɵİ��ɡ�");
	set_inquiry("�Ắ��", "�������ﰡ�����������");
	set_inquiry("�����书", "�����书������ӯ��");

	set("hp", 112000);
	set("max_hp", 112000);
	set("mp", 62000);
	set("max_mp", 62000);
	set("mp_factor", 500);
	
	set("combat_exp", 190000000);
	set("score", 500000);
	
	set_skill("force", 740);
	set_skill("unarmed", 740);
	set_skill("dodge", 740);
	set_skill("parry", 740);
	set_skill("finger",740);
	set_skill("hand",740);
	set_skill("strike", 740);
    set_skill("sword",740);

	set_skill("zhemei_shou",740);
	set_skill("liuyang_zhang",740);
    set_skill("tianyu_qijian",740);
	set_skill("yueying_wubu",740);
	set_skill("bahuang_gong", 740);
	set_skill("rouqing_zhi",740);
	set_skill("beiming_shengong", 740);

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

	set("apply/armor", 950);
    set("apply/damage", 820);

	set("chat_chance", 5);

    carry_object("changjian")->wield();
 	carry_object("qingyi")->wear();
    carry_object("doupeng")->wear();

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
		return "ˮ����ת����ȥ������̾�������Ắ�ӣ��������������أ���";
	case 1:
		return "ˮ�������ĵ�̾��һ�������������������������Ӱ��춹,�����˼֪��֪����";
	case 2:
		return "ˮ����üͷһ����Ц������˵����������MM��Ƿ��һ�ٷ��ء���";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * ling = PresentName("changjian", IS_ITEM);
	if(query_weapon() == ling && ling)
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>145 )
		{
			message_vision("$HIR$N��̾�����������Ѿ���ͬ�绨ѩ��,$n����ȥ�ɣ���", this,me);
			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);
			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��������ȫȻİ����");
			if(me->query("18dy/level9"))
				me->set("18dy/level10",1);
			me->move(load_room("�߲���������"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
