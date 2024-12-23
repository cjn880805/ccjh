//f_xiantianyu.h �������̾���-����7����װ
//�ز� 2002-05-20

EQUIP_BEGIN(CIxiantianyu);

virtual void create(int nFlag = 0)	
{
	set_name( "�������̾���");	
	set("wield_position", WIELD_NECK);		//set the position of wield
 	set_weight(1000);		//set item weight
	set("material", "steel");
	set("unit", "��");
	set("value", 1);

	set("long", "����һ����������壬��Ө��͸��ͨ��͸¶��һ������֮���������������С�ˣ���Զ������");
	set("wield_msg","������ð�����������ˣ�$N������$n��");
 	set("unwield_msg", "$N����$n�����˿ڴ�����Ϊ$N��������ӵ���ߡ�");
	
	set("Ѱ��", 150+random(151));
	set("level",60);

	set("index",6);//��װ֮�以������

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/f_2")||me->query("level")<query("level")  || 
		(me->query_temp("apply/index")!=query("index") && me->query_temp("apply/index")))
		return 0;
	if( me->query("repute")<200000 ||me->querymap("couple") || me->query("max_atman")|| me->query("wench/sleep"))
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
		if(EQUALSTR(obj->querystr("base_name"), "xiantianyu") && obj->query("equipped")==WIELD_NECK )
		{
			me->set_temp("taozhuang/f_2",1);
			obj->set("owner",me->querystr("id"));
			me->add_temp("taozhuang/f_count",1);
			me->set_temp("apply/index",obj->query("index"));

			me->add_temp("apply/mf", obj->query("Ѱ��"));

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
		if(EQUALSTR(obj->querystr("base_name"), "xiantianyu") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/f_2");
			obj->del("owner");

			me->add_temp("apply/mf", -obj->query("Ѱ��"));
			me->add_temp("taozhuang/f_count",-1);

			if(me->query_temp("taozhuang/f"))
			{
				me->delete_temp("taozhuang/f");
				tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
			}
			if(me->query_temp("taozhuang/f_count")<=0)
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
		if(!me->query_temp("taozhuang/f_2")  &&!me->is_busy())
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
		if(me->query_temp("taozhuang/f_2") && EQUALSTR(querystr("base_name"), "xiantianyu") 
			&& query("equipped")==WIELD_NECK &&!me->is_busy()) 
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





