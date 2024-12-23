//c_zidiaopifeng.h ��������-�ư���5����װ
//�ز� 2002-04-01

EQUIP_BEGIN(CIzidiaopifeng);

virtual void create(int nFlag = 0)	
{
	set_name( "��������");	
	set("wield_position", WIELD_MANTLE);		//set the position of wield
 	set_weight(2000);		//set item weight
	set("material", "cloth");
	set("unit", "��");
	set("value", 1);
	
	set("long", "����ʮ�㣬ֻ�ǹ�����ϡ���ﱣ��Э��᲻����������鷳��");
	set("wear_msg", "$N��$nһ˦����һ���ܿ���������������ϡ�");
	set("remove_msg", "����һ˦��$N�Ա�׼��ģ�����ƽ�$n�������ϡ�");
	
	set("level",55);
	set("index",3);//��װ֮�以������

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/c_5")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "zidiaopifeng") && obj->query("equipped")==WIELD_MANTLE )
		{
			me->set_temp("taozhuang/c_5",1);
			me->add_temp("taozhuang/c_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));
			
			me->add_temp("apply/armor", 30);
			me->add_temp("apply/mf", 100);
			me->set_temp("apply/no_��������", 1);
			me->add_temp("apply/hp_hueifu", 5);

			me->UpdateMe();
			me->remove_call_out(do_hphueifu);
			me->call_out(do_hphueifu, 60);
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
		if(EQUALSTR(obj->querystr("base_name"), "zidiaopifeng") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/c_5");
			me->add_temp("taozhuang/c_count",-1);
			obj->del("owner");

			me->add_temp("apply/armor", -30);
			me->add_temp("apply/mf", -100);
			me->delete_temp("apply/no_��������");
			me->add_temp("apply/hp_hueifu", -5);

			if(me->query_temp("taozhuang/c"))
			{
				me->delete_temp("taozhuang/c");
				me->add_temp("apply/armor",-150);
				if(me->query_temp("apply/armor")<=0)me->delete_temp("apply/armor");				
				me->add_temp("apply/mf",-250);
				if(me->query_temp("apply/mf")<=0)me->delete_temp("apply/mf");
				me->add_temp("apply/hp_hueifu", -5);
				if(me->query_temp("apply/hp_hueifu")<=0)me->delete_temp("apply/hp_hueifu");
				me->delete_temp("apply/no_����");
				tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
			}

			if(me->query_temp("taozhuang/c_count")<=0)
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
		if(!me->query_temp("taozhuang/c_5") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/c_5") && EQUALSTR(querystr("base_name"), "zidiaopifeng") 
			&& query("equipped")==WIELD_MANTLE &&!me->is_busy())
		{
			me->remove_call_out(do_hphueifu);
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

static void do_hphueifu(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(me->query_temp("apply/hp_hueifu"))
	{
		if(me->query("hp")<me->query("eff_hp"))
		{
			int hp_hueifu=me->query_temp("apply/hp_hueifu")*me->query("eff_hp")/100;
			if(me->query("eff_hp")<me->query("hp")+hp_hueifu && me->query("eff_hp")>=me->query("hp"))
				hp_hueifu=me->query("eff_hp")-me->query("hp");
			me->add("hp",hp_hueifu);
			tell_object(me,"$HIR������������ıӻ��£������Ļָ���������");
			me->UpdateMe();
		}
		if(me->query_temp("taozhuang/c_5"))
			me->call_out(do_hphueifu, 60);
	}
}

EQUIP_END;



