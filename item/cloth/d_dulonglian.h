//d_dulonglian.h ����������	ŷ������4����װ
//�ز� 2002-04-08

EQUIP_BEGIN(CIdulonglian);

virtual void create(int nFlag = 0)	
{
	set_name( "����������");	

    set("wield_position", WIELD_NECK);		//set the position of wield
	set("material", "steel");
	set("unit", "��");
	set("value", 1);

	set("long", "�ô��������ڵĶ�����ȡ�õ��������ƶ��ɣ����ž��˵�ħ����");
	set("wield_msg", "$N˫������һ£��һ���ܳ��$n�Ѿ���$N������ȥ��");
	set("unwield_msg", "�����ޣ�ʲô���������ѿ�ѽ����$Nһ��֮�½�$nȡ��������");

	set("index",4);//��װ֮�以������

	set("level",75);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/d_2")||me->query("level")<query("level") ||(me->query_temp("apply/index")!=query("index") 
		&& me->query_temp("apply/index")) || me->query("repute")>-500000)
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
		if(EQUALSTR(obj->querystr("base_name"), "dulonglian") && obj->query("equipped")==WIELD_NECK )
		{
			me->set_temp("taozhuang/d_2",1);
			me->add_temp("taozhuang/d_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", 100);
			me->add_temp("apply/con", 2);
			me->add_temp("apply/mf",75);

			if(me->query_temp("taozhuang/d_count")==4 &&!me->query_temp("taozhuang/d") )
			{
				me->add_temp("apply/mf",125);
				me->set_temp("apply/no_Ӣ����ʽ", 1);
				me->set_temp("apply/no_��������", 1);
				me->add_temp("apply/per",3);
				me->add("eff_hp",1500);
				me->add("max_hp",1500);
				me->add("mp",1500);
				tell_object(me,"$HIR\n�������һ����磬��һ���������ӵ����ˡ�\n");
				me->set_temp("taozhuang/d",1);
			}
			me->UpdateMe();
			me->remove_call_out(do_armor);
			me->call_out(do_armor, 15);
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
		if(EQUALSTR(obj->querystr("base_name"), "dulonglian") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/d_2");
			me->add_temp("taozhuang/d_count",-1);
			obj->del("owner");

			me->add_temp("apply/armor", -100);
			me->add_temp("apply/con", -2);
			me->add_temp("apply/mf",-75);

			if(me->query_temp("taozhuang/d"))
			{
				me->add("max_hp",-1500);
				if(me->query("eff_hp")>me->query("max_hp"))
					me->set("eff_hp",me->query("max_hp"));
				else if(me->query("eff_hp")>1500)
					me->add("eff_hp",-1500);
				else
					me->add("eff_hp",-(me->query("eff_hp")-100));

				if(me->query("hp")>me->query("eff_hp"))
					me->set("hp",me->query("eff_hp"));

				me->add("mp",-1500);
				if(me->query("mp")<0)
					me->set("mp",0l);

				me->delete_temp("apply/no_Ӣ����ʽ");
				me->delete_temp("apply/no_��������");
				me->add_temp("apply/per",-3);
				if(me->query_temp("apply/per")<=0)me->delete_temp("apply/per");
				me->add_temp("apply/mf",-125);
				if(me->query_temp("apply/mf")<=0)me->delete_temp("apply/mf");
				tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");

				me->delete_temp("taozhuang/d");
				me->UpdateMe();
			}
			if(me->query_temp("taozhuang/d_count")<=0)
				me->delete_temp("apply/index");
			
			break;
		}
	}
	me->enable_player();
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "wield") == 0 && !me->Query(CChar::CAN_EQUIPPED))
	{
		if(!me->query_temp("taozhuang/d_2")  &&!me->is_busy())
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
		if(me->query_temp("taozhuang/d_2") && EQUALSTR(querystr("base_name"), "dulonglian") 
			&& query("equipped")==WIELD_NECK &&!me->is_busy())
		{
			me->remove_call_out(do_armor);
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

static void do_armor(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(!me->is_fighting())
	{
		me->del("condition");
	}
	me->call_out(do_armor, 15);
}

EQUIP_END;



