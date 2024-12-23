//e_fengyizhen.h ���¶���--����7����װ
//�ز� 2003-05-30

EQUIP_BEGIN(CIfengyizhen);

virtual void create(int nFlag = 0)	
{
	set_name( "���¶���");	
	set_weight(3000);		
    set("wield_position", WIELD_RING);		
	
	set("unit", "��");
	set("value", 1);
	set("material", "leather");

	set("long", "������ħ���ķ��¶��룬��˵�����ע��һλŮ�ӵ����а�Թ�����Ծ����Ų�ͬ���������������");
	set("wield_msg", "$N��ָһ�ۣ���һ��$n��������ָ�ϡ�");
	set("unwield_msg", "$N��ָһ����$n�����ֶ�����");
	
	set("level",85);
	set("index",5);//��װ֮�以������
	set("����", 50+random(51));

};

virtual int Can_Equip(CChar * me)
{
	if(DIFFERSTR(me->querystr("gender"), "����")||me->query_temp("taozhuang/e_5")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "fengyizhen") && obj->query("equipped")==WIELD_RING )
		{
			me->set_temp("taozhuang/e_5",1);
			me->add_temp("taozhuang/e_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", obj->query("����"));

			if(DIFFERSTR(me->querystr("add_skill/name1"),"pixie_jian")&& EQUALSTR(me->querystr("add_skill/name1"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "�������"))
			{	
				me->add("add_skill/count",1);
				me->set("add_skill/name1","pixie_jian");
				me->set("add_skill/level1",10);
				me->set_skill("pixie_jian",me->query_skill("pixie_jian", 1)+me->query("add_skill/level1"));
				me->FlushMySkill(me);
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
		if(EQUALSTR(obj->querystr("base_name"), "fengyizhen") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/e_5");
			me->add_temp("taozhuang/e_count",-1);

			if(me->query_temp("taozhuang/e_count")<=0)
				me->delete_temp("apply/index");
			obj->del("owner");

			me->add_temp("apply/armor", -obj->query("����"));

			if(EQUALSTR(me->querystr("add_skill/name1"),"pixie_jian"))
			{
				me->set_skill("pixie_jian",me->query_skill("pixie_jian", 1)-me->query("add_skill/level1"));
				if(me->query_skill("pixie_jian", 1)<1)me->delete_skill("pixie_jian");
				me->add("add_skill/count",-1);
				me->del("add_skill/name1");
				me->del("add_skill/level1");
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

			break;
		}
	}
	me->enable_player();
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "wield") == 0 && !me->Query(CChar::CAN_EQUIPPED))
	{
		if(!me->query_temp("taozhuang/e_5") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/e_5") && EQUALSTR(querystr("base_name"), "fengyizhen") 
			&& query("equipped")==WIELD_RING &&!me->is_busy())
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



