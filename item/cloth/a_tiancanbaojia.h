//a_tiancanbaojia.h ��ϱ���
//�ز� 2002-03-25

EQUIP_BEGIN(CItiancanbaojia);

virtual void create(int nFlag = 0)	
{
	set_name( "��ϱ���");	

	set("wield_position", WIELD_ARMOR);		
 	set_weight(10000);	
          
	set("unit", "��");
	set("value", 1);
	set("material", "leather");
	set("long", "���ǵ���Τ��ү�����ı��ף�������˵Τ��ү���ǿ�������׷����ô���ɫŮ�ӣ��Ƿ�����������������˵�ħ���أ�");
	set("wield_msg","$Nװ��$n������ȫ����һ��$N����Ҳ�ڱ��׵�ӳ���£���ù����ޱȡ�");
 	set("unwield_msg", "$N���ĵĽ�$n��������,����$N�����İ����˻᲻�ᷢ��$N����������Ϊ���$n��ħ��?");
	
	set("baobei",1);
	set("index",1);//��װ֮�以������

	set("level",45);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/a_2")||me->query("level")<query("level") || 
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
		if(EQUALSTR(obj->querystr("base_name"), "tiancanbaojia") && obj->query("equipped")==WIELD_ARMOR )
		{
			me->set_temp("taozhuang/a_2",1);
			me->add_temp("taozhuang/a_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));
			if(me->query("hp")>me->query("max_hp"))
				me->set("hp",me->query("max_hp"));
			me->add("hp",666);
			if(me->query("eff_hp")>me->query("max_hp"))
				me->set("eff_hp",me->query("max_hp"));
			me->add("eff_hp",666);
			me->add("max_hp",666);

			me->add_temp("apply/armor", 180);
			me->add_temp("apply/per", 10);
			me->add_temp("apply/mf",80);
			
			if(me->query_temp("taozhuang/a_1"))
			{
				tell_object(me,"$HIRΤ��ү�������������������ϣ��㻹��ʲô��\n������������ˣ�");
				me->add_temp("apply/damage",20);
				me->add_temp("apply/str",3);
				me->set_temp("taozhuang/a",1);
				break;
			}
			else if(me->query_temp("taozhuang/a_3"))
			{
				tell_object(me,"$HIR����ϸ�Ĺ۲�Τ��ү������������\n��ͻȻ����ԭ��������������Ȼ���ž��˵�ħ������ذ����������һЩ������������������Ѱ��ͼ��");
				me->add_temp("apply/armor",50);
				me->add_temp("apply/mf",370);
				me->add_temp("apply/chuantou",10);
				me->add_temp("apply/chuantou_df",10);
				me->set_temp("taozhuang/a",2);
				if(me->query("hp")>me->query("max_hp"))
					me->set("hp",me->query("max_hp"));
				me->add("hp",344);
				if(me->query("eff_hp")>me->query("max_hp"))
					me->set("eff_hp",me->query("max_hp"));
				me->add("eff_hp",344);
				me->add("max_hp",344);
				break;
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
		if(EQUALSTR(obj->querystr("base_name"), "tiancanbaojia") 
			&& !obj->query("equipped") && atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/a_2");
			me->add_temp("taozhuang/a_count",-1);
			me->add("max_hp",-666);
			if(me->query("eff_hp")>666)
				me->add("eff_hp",-666);
			else
				me->set("eff_hp",10);
			if(me->query("hp")>666)
				me->add("hp",-666);
			else
				me->set("hp",10);
			obj->del("owner");
			me->add_temp("apply/armor", -180);
			me->add_temp("apply/per", -10);
			me->add_temp("apply/mf",-80);
			if(me->query_temp("taozhuang/a")==1)
			{
				tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
				me->add_temp("apply/damage",-20);
				if(me->query_temp("apply/damage")<=0)me->delete_temp("apply/damage");
				me->add_temp("apply/str",-3);
				if(me->query_temp("apply/str")<=0)me->delete_temp("apply/str");
				me->delete_temp("taozhuang/a");
			}
			else if(me->query_temp("taozhuang/a")==2)
			{
				tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
				me->add("max_hp",-344);
				if(me->query("eff_hp")>344)
					me->add("eff_hp",-344);
				else
					me->set("eff_hp",10);
				if(me->query("hp")>344)
					me->add("hp",-344);
				else
					me->set("hp",10);
				me->add_temp("apply/armor",-50);
				if(me->query_temp("apply/armor")<=0)me->delete_temp("apply/armor");
				me->add_temp("apply/mf",-370);
				if(me->query_temp("apply/mf")<=0)me->delete_temp("apply/mf");
				me->add_temp("apply/chuantou",-10);
				if(me->query_temp("apply/chuantou")<=0)me->delete_temp("apply/chuantou");
				me->add_temp("apply/chuantou_df",-10);
				if(me->query_temp("apply/chuantou_df")<=0)me->delete_temp("apply/chuantou_df");
				me->delete_temp("taozhuang/a");
			}
			if(me->query_temp("taozhuang/a_count")<=0)
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
		if(!me->query_temp("taozhuang/a_2") &&!me->is_busy()) 
		{
			if(query("apply/damage"))del("apply/damage");
			if(query("apply/str"))del("apply/str");
			if(query("apply/mf")>80)set("apply/mf",80);
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
		if(me->query_temp("taozhuang/a_2") && EQUALSTR(querystr("base_name"), "tiancanbaojia") 
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



