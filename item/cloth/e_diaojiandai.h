//e_diaojiandai.h С�ɰ������-����7����װ
//�ز� 2002-05-18

EQUIP_BEGIN(CIdiaojiandai);

virtual void create(int nFlag = 0)	
{
	set_name( "С�ɰ������");	

    set("wield_position", WIELD_MANTLE);		//set the position of wield
	set_weight(1000);		//set item weight
	set("unit", "��");
	set("value", 1);
	set("material", "cloth");

	set("long", "�����������𣿱���");
	set("wield_msg","$N˫������һ�ۣ��ѽ�$n������ȥ��");
   	set("unwield_msg", "$N�������һ�����ѽ�$n����������");
	
	set("index",5);//��װ֮�以������

	set("level",45);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/e_2")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "diaojiandai") && obj->query("equipped")==WIELD_MANTLE )
		{
			me->set_temp("taozhuang/e_2",1);
			me->add_temp("taozhuang/e_count",1);
			me->set_temp("apply/index",obj->query("index"));
			me->add("hp",-100);
			if(me->query("hp")<1)
				me->set("hp",1);
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", 1);
			me->add_temp("apply/per", 5);

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
		if(EQUALSTR(obj->querystr("base_name"), "diaojiandai") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/e_2");
			me->add_temp("taozhuang/e_count",-1);

			me->add("hp",100);
			if(me->query("hp")>me->query("max_hp"))
				me->set("hp",me->query("max_hp"));

			if(me->query_temp("taozhuang/e_count")<=0)
				me->delete_temp("apply/index");

			obj->del("owner");
			me->add_temp("apply/armor", -1);
			me->add_temp("apply/per", -5);
			me->UpdateMe();

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
		if(!me->query_temp("taozhuang/e_2") &&!me->is_busy())
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

	if(!strcmp(comm, "unwield") )
	{
		if(me->query_temp("taozhuang/e_2") && EQUALSTR(querystr("base_name"), "diaojiandai") 
			&& query("equipped")==WIELD_MANTLE &&!me->is_busy())
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



