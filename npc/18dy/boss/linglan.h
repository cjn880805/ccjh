//linglan ���� 

//������ʮ�˲�����BOSS



BOSS_BEGIN(CNlinglan);



virtual void create()

{	

	set_name("����", "ling lan");

	set("title", "̫����С�ٺ�");

	set("gender", "Ů��");

	set("icon", young_woman3);

	set("age", 68);

	set("long",  "�������续������������������,���˸о�������һ������ң���ɼ������¡�");

		

	set("str", 150);

	set("int", 150);

	set("con", 150);

	set("dex", 95);

	set("per",40);

	set("level",220);

	set("repute",50000000);



	set("chat_chance_combat", 15);		//����NPCʹ�þ��еļ���

	

	set_inquiry("����", "�Ҳ��ʽ����Ƿ��Ѿ��ܶ����ˡ�");

	set_inquiry("���", "�㲻֪������Ϊ���������·���");

	set_inquiry("BUG", "������������Ķ�����");

	set_inquiry("��ң��������", "��Թ��͵����䣬ֻ��ͨ������ſ��Խ⿪��");



	set("hp", 352000);

	set("max_hp",352000);

	set("max_mp", 12000);

	set("mp", 12000);

	set("mp_factor", 500);

	

	set("combat_exp", 450000000);

	set("score", 500000);

	

	set_skill("force", 1000);

	set_skill("beiming_shengong", 1000);

	set_skill("dodge", 1000);

	set_skill("lingboweibu", 1000);

	set_skill("strike", 1000);

	set_skill("liuyang_zhang", 1000);

	set_skill("parry", 1000);

	set_skill("blade", 1000);

	set_skill("xiaoyao_dao", 1000);

	set_skill("zhemei_shou", 1000);

	set_skill("hand", 1000);

	set_skill("literate", 1000);

	

	map_skill("force", "beiming_shengong");

	map_skill("dodge", "lingboweibu");

	map_skill("hand", "zhemei_shou");

	map_skill("strike", "liuyang_zhang");

	map_skill("parry", "xiaoyao_dao");

	map_skill("blade", "xiaoyao_dao");

	

	prepare_skill("hand","zhemei_shou");

	prepare_skill("strike","liuyang_zhang");

	

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

	set_temp("apply/����һЦ",1);

	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 1400);
    set("apply/damage", 1200);

    carry_object("gangdao")->wield();

	set("family/family_name","��ң��");

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



virtual char * chat_msg_combat()

{
	char msg[255];
	CContainer * item = PresentName("gangdao", IS_ITEM);
	if(query_weapon() == item && item)
	{
		switch(random(4))
		{
		case 0:
			perform_action("force maxsuck", 1);
			break;
		case 1:
			perform_action("force recover",0);
			break;
		case 2:
			perform_action("blade daoshenxiao", 1);
			break;
		case 3:
			perform_action("force neilisuck", 1);
			break;
		case 4:
			command(snprintf(msg, 40, "unwield %ld", item->object_id()));
			break;
		}
	}
	else
	{
		switch(random(5))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("force maxsuck", 1);
			break;
		case 2:
			perform_action("force neilisuck", 1);
			break;
		case 3:
			perform_action("strike zhong", 1);
			break;
		case 4:
			if(!item)
				carry_object("gangdao")->wield();
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
	char msg[255];

	while(p) 

	{ 

		CContainer * obj = list->GetNext(p);

		if(! obj->is_character()) continue; 

		me = (CChar *)obj;  

		if(!userp(me))	continue;

		//���һ���򵹵��˽���ý�����һ����ʸ�

		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>163 )

		{

			message_vision("$HIR$N��̾���������Ҷ��ܴ��,���֮���Ѿ�û������$n�Ķ����ˣ���", this,me);

			message_vision("\nֻ�����һ����$N�Ѿ���ʧ����Ӱ���١�", me);

			tell_object(me, "$HIY���Ȼһ��ͷ���ۻ���ֻ��һ�����Ƽ���㣬����һ��......");

			g_Channel.do_channel(&g_Channel, 0, "chat", 
				snprintf(msg, 255, "$HIC%s����%s(%s)$HIY����ǧ����࣬������սʮ�˵����ɹ���$COM",  me->querystr("family/family_name"),me->name(1),me->id(1)));

			if(me->query("18dy/level21"))

				me->set("18dy/level22",1);

			me->move(load_room("�߲���Ȫ֮·"));

			break;

		}

	}

	CNbossnpc::die();

}



BOSS_END;

