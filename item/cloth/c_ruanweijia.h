//c_ruanweijia.h ������⬼�-�ư���5����װ

EQUIP_BEGIN(CIruanweijia);

virtual void create(int nFlag = 0)	
{
	set_name( "������⬼�");	
	set("wield_position", WIELD_ARMOR);		
 	set_weight(9000);	
          
	set("unit", "��");
	set("value", 1);
	set("material", "leather");
	set("long", "����Ǵ�˵�е�����������������ǹ���룬���Ҽ����滹����൹�̣���Ҫ�ǿ������˴��ţ���Ҫ������˲�ȥ��Ŷ��");
	set("wield_msg","$Nװ��$n��ɲʱ$N�����Լ���Ѫ������װ��֮�У���Ϊһ�塣");
 	set("unwield_msg", "$N������$n��һ���ָֻ���������");

	set("����", random(151)+200);

	set("apply/fantan",30);

	set("level",90);
	set("index",3);//��װ֮�以������

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/c_3")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "ruanweijia") && obj->query("equipped")==WIELD_ARMOR )
		{
			if(obj->query("apply/mf"))obj->del("apply/mf");
			if(obj->query("apply/hp_hueifu"))obj->del("apply/hp_hueifu");
			if(obj->query("apply/no_����"))obj->del("apply/no_����");

			me->set_temp("taozhuang/c_3",1);
			me->add_temp("taozhuang/c_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", obj->query("����"));
						
			if(me->query_temp("taozhuang/c_count")==5 &&!me->query_temp("taozhuang/c"))
			{
				me->add_temp("apply/armor",150);
				me->add_temp("apply/mf",250);
				me->add_temp("apply/hp_hueifu", 5);
				me->add_temp("apply/no_����", 1);
				tell_object(me,"$HIR\n�㻻������ؤ����������ؤ���������������ĳ���װ����\n�Ӵ��Ժ����������ˡ�");
				me->set_temp("taozhuang/c",1);
			}
			me->UpdateMe();
			me->remove_call_out(do_armor);
			me->call_out(do_armor, 5);
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
		if(EQUALSTR(obj->querystr("base_name"), "ruanweijia") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/c_3");
			me->add_temp("taozhuang/c_count",-1);
			obj->del("owner");

			me->add_temp("apply/armor", -obj->query("����"));

			if(me->query_temp("taozhuang/c"))
			{
				me->add_temp("apply/armor",-150);
				if(me->query_temp("apply/armor")<=0)me->delete_temp("apply/armor");				
				me->add_temp("apply/mf",-250);
				if(me->query_temp("apply/mf")<=0)me->delete_temp("apply/mf");
				me->add_temp("apply/hp_hueifu", -5);
				if(me->query_temp("apply/hp_hueifu")<=0)me->delete_temp("apply/hp_hueifu");
				me->delete_temp("apply/no_����");
				me->delete_temp("taozhuang/c");
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
		if(!me->query_temp("taozhuang/c_3") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/c_3") && EQUALSTR(querystr("base_name"), "ruanweijia") 
			&& query("equipped")==WIELD_ARMOR &&!me->is_busy())
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
	if(me->is_fighting())
	{
		if(!me->query_temp("fantan/hp1"))
			me->set_temp("fantan/hp1",me->query("hp"));
		CFightRoom * obj=(CFightRoom *)me->environment();
		DTItemList * list = obj->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(! obj->is_character()) continue; 
			CChar * target = (CChar *)obj;  
//			if(!userp(target))	continue;
			if(me->is_fighting(target)!=me->is_fighting(me) && me->query("hp")<me->query_temp("fantan/hp1")
				&&!target->query_weapon()&&!random(2))
			{
				int fantan=me->query_temp("apply/fantan")*(me->query_temp("fantan/hp1")-me->query("hp"))/100;
				if(fantan<0)fantan=0;
				if(fantan>target->query("hp")/2)fantan=target->query("hp")/2;
				target->set("hp",target->query("hp")-fantan);
				message_vision("$HIR�����ĵ�һ�죬���ǡ���Ӵ��һ��������ֻ��$N������Ѫ���죬��ɫ�Ұס�", target);
				message_vision("$HIRԭ��$N��һ��������ȫ���������ָȫײ����⬼׵Ĵ��ϣ�ʮָ���ģ�ʹ��$N��Щ��ʱ���Ρ�", target);
				target->UpdateMe();
				break;
			}
		}	
		me->set_temp("fantan/hp1",me->query("hp"));
	}
	me->call_out(do_armor, 5);
}

EQUIP_END;



