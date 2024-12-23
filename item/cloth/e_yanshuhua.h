//e_yanshuhua.h ���״�컨-����7����װ
//�ز� 2002-07-08

EQUIP_BEGIN(CIyanshuhua);

virtual void create(int nFlag = 0)	
{
	set_name( "���״�컨");	
	set_weight(3000);		//set item weight
    set("wield_position", WIELD_HEAD);		//set the position of wield
	set("unit", "��");
	set("value", 1);
	set("material", "plant");
	
	set("long", "������һ�����ܣ���ǧ��Ҫ���߱��ˡ�����һ���컨��");
	set("wear_msg", "$N����ϲ�õĽ�$n������ͷ�ϣ���Χ���̱�һ��ϲ��֮������Χ��");
	set("remove_msg", "$Nȡ���˴���ͷ�ϵ�$n��");
	
	set("����", 10+random(6));

	set("index",5);//��װ֮�以������

	set("level",85);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/e_4")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "yanshuhua") && obj->query("equipped")==WIELD_HEAD )
		{
			me->set_temp("taozhuang/e_4",1);
			me->add_temp("taozhuang/e_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", obj->query("����"));
			me->add_temp("apply/per", 1);
			me->add_temp("apply/mp_hueifu", 100);

			me->UpdateMe();
			
			me->set_temp("disfigurement",1);
			me->remove_call_out(do_mphueifu);
			me->call_out(do_mphueifu, 30);
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
		if(EQUALSTR(obj->querystr("base_name"), "yanshuhua") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/e_4");
			me->add_temp("taozhuang/e_count",-1);
			me->delete_temp("disfigurement");

			if(me->query_temp("taozhuang/e_count")<=0)
				me->delete_temp("apply/index");
			obj->del("owner");

			me->add_temp("apply/armor", -obj->query("����"));
			me->add_temp("apply/per", -1);
			me->add_temp("apply/mp_hueifu", -100);

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
		if(!me->query_temp("taozhuang/e_4") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/e_4") && EQUALSTR(querystr("base_name"), "yanshuhua") 
			&& query("equipped")==WIELD_HEAD &&!me->is_busy())
		{
			me->remove_call_out(do_mphueifu);
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


static void do_mphueifu(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(me->query_temp("apply/mp_hueifu"))
	{
		if(me->query("mp")<me->query("max_mp"))
		{
			int mp_hueifu=me->query_temp("apply/mp_hueifu");
			if(me->query("max_mp")<me->query("mp")+me->query_temp("apply/mp_hueifu") && me->query("max_mp")>me->query("mp"))
				mp_hueifu=me->query("max_mp")-me->query("mp");
			
			me->add("mp",mp_hueifu);

			if(me->query("mp")>me->query("max_mp")*4)
				me->set("mp",me->query("max_mp")*4);

			tell_object(me,"$HIR�������״�컨�ıӻ��£���ɫԽ��Խ�������������ָ���");
			me->UpdateMe();
		}
		if(me->query_temp("taozhuang/e_4"))
			me->call_out(do_mphueifu, 30);
	}
}

EQUIP_END;



