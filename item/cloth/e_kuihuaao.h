//e_kuihuaao.h	����С��--����7����װ
//�ز� 2003-05-30

EQUIP_BEGIN(CIkuihuaao);

virtual void create(int nFlag = 0)	
{
	set_name( "����С��");	

	set("wield_position", WIELD_ARMOR);		
 	set_weight(9000);	
          
	set("unit", "��");
	set("value", 1);
	set("material", "leather");

	set("long", "�ۣ���ôƯ�����·�Ү����Ů���ˡ�");
	set("wield_msg", "$N����$n��������ɫ�ʽ������Ҳӳ�յ������ޱȡ�");
	set("unwield_msg", "$N��$n�����������㻹���Ǹ��㣬��Ȼû�䡣");

	set("index",5);//��װ֮�以������

	set("level",99);
	set("����", 150+random(251));
};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/e_7")||me->query("level")<query("level") ||
		(me->query_temp("apply/index")!=query("index") && me->query_temp("apply/index")))
		return 0;
	return 1;
};

static void do_zhuangbei(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	DTItemList * list = me->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(obj->is_character()) continue; 
		if(EQUALSTR(obj->querystr("base_name"), "kuihuaao") && obj->query("equipped")==WIELD_ARMOR )
		{
			me->set_temp("taozhuang/e_7",1);
			me->add_temp("taozhuang/e_count",1);
			me->set_temp("apply/index",obj->query("index"));
			me->set("max_hp",me->query_temp("max_hp")+3500);
			me->set("eff_hp",me->query("eff_hp")+3500);

			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", obj->query("����"));
			me->add_temp("apply/per", 5);

			me->set_temp("apply/no_ǧ���׹�",1);

			if(DIFFERSTR(me->querystr("add_skill/name2"),"kuihua_xinfa")&& EQUALSTR(me->querystr("add_skill/name2"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "�������"))
			{	
				me->add("add_skill/count",1);
				me->set("add_skill/name2","kuihua_xinfa");
				me->set("add_skill/level2",30);
				me->set_skill("kuihua_xinfa",me->query_skill("kuihua_xinfa", 1)+me->query("add_skill/level2"));
				me->FlushMySkill(me);
			}
			if(me->query_temp("taozhuang/e_count")==7 &&!me->query_temp("taozhuang/e"))
			{
				me->add_temp("apply/str",1);
				me->add_temp("apply/int",1);
				me->add_temp("apply/per",2);
				me->set_temp("apply/pro_��Ŀ",2);

				tell_object(me,"$HIR\n�㴩�������е�װ���������˱�������ޱȣ���������������������ġ�");
				tell_object(me,"������������ˣ�\n����ǻ������ˣ�\n������������ˣ�\n��Ĵ�Ŀ�����ˣ�");
				me->set_temp("taozhuang/e",1);
			}
			me->UpdateMe();
			
			break;
		}
	}
	me->enable_player();
}

static void do_xiexia(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	DTItemList * list = me->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(obj->is_character()) continue; 
		if(EQUALSTR(obj->querystr("base_name"), "kuihuaao") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/e_7");
			me->add_temp("taozhuang/e_count",-1);

			me->set("max_hp",me->query_temp("max_hp"));

			if(me->query("eff_hp")>me->query("max_hp"))
				me->set("eff_hp",me->query("max_hp"));
			else if(me->query("eff_hp")>3500)
				me->add("eff_hp",-3500);
			else
				me->add("eff_hp",-(me->query("eff_hp")-100));

			if(me->query("hp")>me->query("max_hp"))
				me->set("hp",me->query("max_hp"));
			else if(me->query("hp")>3500)
				me->add("hp",-3500);
			else
				me->add("hp",-(me->query("hp")-100));

			obj->del("owner");

			me->add_temp("apply/armor", -obj->query("����"));
			me->add_temp("apply/per", -5);

			me->delete_temp("apply/no_ǧ���׹�");

			if(EQUALSTR(me->querystr("add_skill/name2"),"kuihua_xinfa"))
			{
				me->set_skill("kuihua_xinfa",me->query_skill("kuihua_xinfa", 1)-me->query("add_skill/level2"));
				if(me->query_skill("kuihua_xinfa", 1)<1)me->delete_skill("kuihua_xinfa");
				me->add("add_skill/count",-1);
				me->del("add_skill/name2");
				me->del("add_skill/level2");
				me->FlushMySkill(me);
			}

			if(me->query_temp("taozhuang/e"))
			{
				me->delete_temp("taozhuang/e");
				me->add_temp("apply/str",-1);
				me->add_temp("apply/int",-1);
				me->add_temp("apply/per",-2);
				me->delete_temp("apply/pro_��Ŀ");
				tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
			}

			if(me->query_temp("taozhuang/e_count")<=0)
				me->delete_temp("apply/index");
			me->UpdateMe();
			break;
		}
	}
	me->enable_player();
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "wield") == 0 && !me->Query(CChar::CAN_EQUIPPED))
	{
		if(!me->query_temp("taozhuang/e_7") &&!me->is_busy())
		{
			me->disable_player("װ����");
			me->remove_call_out(do_zhuangbei);
			me->call_out(do_zhuangbei, 1);
		}
		else
		{
			tell_object(me,"�������޷�װ����");
			return 1;
		}
	}

	if(!strcmp(comm, "unwield")  )
	{
		if(me->query_temp("taozhuang/e_7") && EQUALSTR(querystr("base_name"), "kuihuaao") 
			&& query("equipped")==WIELD_ARMOR &&!me->is_busy())
		{
			me->disable_player("��ж��");
			me->remove_call_out(do_xiexia);
			me->call_out(do_xiexia, 1);
		}
	}
	if(!strcmp(comm, "drop") )
	{
		if(query("equipped"))
		{
			tell_object(me,"װ���еĵ����޷�������");
			return 1;
		}
	}
	return 0;
}

virtual void owner_is_killed(CChar *me)
{
	if(me)
		tell_object(me,"ֻ����ǰ���һ��...������.....");

	move((CContainer *)load_room("pk"));
} 

EQUIP_END;



