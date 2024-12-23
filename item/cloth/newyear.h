//newyear.h

//Sample for ITEM: �������
EQUIP_BEGIN(CInewyear);


virtual void create(int nFlag = 0)		
{
	set_name( "�������");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(10000);		//set item weight
          
	set("unit", "��");
	set("value", 30000);
	set("apply/per", 5);
	set("material", "leather");
	set("apply/armor", 100);
	set("long", "���ǽ�������˾������2002���������Ů������ǽ��괺�������еĿ�ʽ������Ҫע�⣬һ��ʹ������������������һ��Ҫ�������µ�½���ܷ�������������");
	set("wield_msg","$N���ᴩ��$n����ʱ�޹����䡣");
   	set("unwield_msg", "$N����$n�������֮��Ȼʧɫ��");

	set("no_give", "���ˣ�������ĳ�����");
//	set("no_get", "ץС͵ѽ������");
	set("no_put", "��ϧ���ɡ�");
	set("no_sell", 1);
	set("no_beg",1);
	set("baobei",1);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query("max_hp")<3001)
		return 0;
	if (!DIFFERSTR(me->querystr("gender"), "����")) 
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
		if(EQUALSTR(obj->querystr("base_name"), "newyear") && obj->query("equipped")==WIELD_ARMOR )
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
		if(EQUALSTR(obj->querystr("base_name"), "newyear") && !obj->query("equipped") )
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
		if(EQUALSTR(querystr("base_name"), "newyear") && query("equipped")==WIELD_ARMOR &&!me->is_busy()) 
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

/*void init()
{
	add_action("do_wield", "wield");
	add_action("do_unwield", "unwield");
//	add_action("do_drop", "drop");
}

int do_wield(string arg)

{
    object me=this_player();
    object ob;

    if (!id(arg))   return notify_fail("��Ҫװ��ʲô��\n");

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped") )
		return notify_fail("���Ѿ�װ�����ˡ�\n");

	if( ob->wield() )
	{
		me->set_temp("newyear/cloth",1);
		me->add("max_hp",4000);
		return 1;
	}
	else
		return 0;
}

int do_unwield(string arg)
{ 
	object me=this_player();
	object ob;

    if (!id(arg))   return notify_fail("��Ҫ����ʲô��\n");

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped") )
		return notify_fail("���Ѿ������ˡ�\n");

	if( ob->unwield() ) 
	{
		me->delete_temp("newyear/cloth");
		me->add("max_hp",-4000);
		return 1;
	}
	else
		return 0;
}
*/
EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp


