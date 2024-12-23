//newyear1.h

//Sample for ITEM: �������

EQUIP_BEGIN(CInewyear1);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���̴���");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(10000);		//set item weight
          
	set("unit", "��");
	set("value", 30000);
	set("apply/per", 5);
	set("material", "leather");
	set("apply/armor", 100);
	set("long", "���ǽ�������˾������2002����������������������ʽ���ķ����¡�����Ҫע�⣬һ��ʹ������������������һ��Ҫ�������µ�½���ܷ�������������");
	set("wield_msg","$Nһ��$n�ϵİ�ť��$N��ȫ������������װ�װ���������");
   	set("unwield_msg", "$N�����Ķ���$n��ȥ�ˡ�");

	set("no_give", "���ˣ�������ĳ�����");
	set("no_put", "��ϧ���ɡ�");
	set("no_sell", 1);
	set("no_beg",1);
	set("baobei",1);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query("max_hp")<3001)
		return 0;
	if (DIFFERSTR(me->querystr("gender"), "����")) 
		return notify_fail("������ʿר�õ�������㻹�ǲ�Ҫ���˰ɣ���");
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
		if(EQUALSTR(obj->querystr("base_name"), "newyear1") && obj->query("equipped")==WIELD_ARMOR )
		{
			me->set("max_hp",me->query_temp("max_hp")+3000);
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
		if(EQUALSTR(obj->querystr("base_name"), "newyear1") && !obj->query("equipped") )
		{
			me->set("max_hp",me->query_temp("max_hp"));
			if(me->query("max_hp")<0)
				me->set("max_hp",100);
			if(me->query("eff_hp")>me->query("max_hp"))
				me->set("eff_hp",me->query("max_hp"));

			if(me->query("hp")>me->query("max_hp"))
				me->set("hp",me->query("max_hp"));
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
		if(!me->is_busy())
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
		if(EQUALSTR(querystr("base_name"), "newyear1") && query("equipped")==WIELD_ARMOR &&!me->is_busy()) 
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

	destruct(this);
} 

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp



