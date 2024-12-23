//h_lvzhuxiao.h ������	�������5����װ
//�ز� 2002-03-26

EQUIP_BEGIN(CIlvzhuxiao);

virtual void create(int nFlag = 0)	
{
	set_name( "������");	

    set("wield_position", WIELD_LEFT_HAND);		//set the position of wield
	set("skill_type", "music");
	set("music_type", "xiao");			//set the skill applied
	set_weight(1000);		//set item weight
	
	set("unit", "ֻ");
	set("long", "����һ�ܶ��ͨ����̣�ȴ�����������Σ���������ϵ�����ϣ�ֻȡ����Ȼ���ӡ�");
	set("value", 1);
	set("material", "bamboo");
	set("no_duo",1);//�����Զ���
	set("wield_msg", "$N����˫ü������������$n���´��г�������ڴ��ߣ�һ����ףӢ̨������������");
	set("unwield_msg", "$N��$n������ָ������һת���Ѳ������䡣");
	
	set("index",8);//��װ֮�以������

	set("level",70);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/h_1")||me->query("level")<query("level") 
		|| EQUALSTR(querystr("name"),"�ϵ���������")
		|| me->query_skill("music",1)<100
		||(me->query_temp("apply/index")!=query("index") && me->query_temp("apply/index")))
		return 0;
	return 1;
};

static void do_cheak(CContainer * ob, LONG param1, LONG param2)
{
	if(!ob->query("equipped") && ob->querystr("owner")[0])
	{
		CUser * me=find_online(ob->querystr("owner"));
		if(me)
		{
			me->delete_temp("taozhuang/h_1");
			me->add_temp("taozhuang/h_count",-1);
			
			ob->del("owner");

			me->add_temp("apply/armor", -50);
			me->add_temp("apply/int",-3);
			me->delete_temp("apply/��_��ȴǧ��");
			me->delete_temp("apply/��_����ɹ�");
			me->delete_temp("apply/��_�̺�����");
			me->delete_temp("apply/��_����ʨ�Ӻ�");
			me->delete_temp("apply/��_��Х");
			me->delete_temp("apply/��_��");
			
			if(me->query_temp("taozhuang/h"))
			{
				me->delete_temp("taozhuang/h");
				tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
			}
			
			if(me->query_temp("taozhuang/h_count")<=0)
				me->delete_temp("apply/index");
		}
	}
	else
		ob->call_out(do_cheak, 10);
}

static void do_zhuangbei(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	DTItemList * list = me->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(obj->is_character()) continue; 
		if(EQUALSTR(obj->querystr("base_name"), "lvzhuxiao") && obj->query("equipped")==WIELD_LEFT_HAND )
		{
			me->set_temp("taozhuang/h_1",1);
			me->add_temp("taozhuang/h_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", 50);
			me->add_temp("apply/int",3);
			//����Ч��
			me->set_temp("apply/��_��ȴǧ��",1);
			me->set_temp("apply/��_����ɹ�",1);
			me->set_temp("apply/��_�̺�����",1);
			me->set_temp("apply/��_����ʨ�Ӻ�",1);
			me->set_temp("apply/��_��Х",1);
			me->set_temp("apply/��_��",1);

			me->UpdateMe();
			obj->call_out(do_cheak, 10);
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
		if(EQUALSTR(obj->querystr("base_name"), "lvzhuxiao") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")))
		{
			me->delete_temp("taozhuang/h_1");
			me->add_temp("taozhuang/h_count",-1);
			
			obj->del("owner");

			me->add_temp("apply/armor", -50);
			me->add_temp("apply/int",-3);
			me->delete_temp("apply/��_��ȴǧ��");
			me->delete_temp("apply/��_����ɹ�");
			me->delete_temp("apply/��_�̺�����");
			me->delete_temp("apply/��_����ʨ�Ӻ�");
			me->delete_temp("apply/��_��Х");
			me->delete_temp("apply/��_��");
			
			if(me->query_temp("taozhuang/h"))
			{
				me->delete_temp("taozhuang/h");
				tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
			}
			
			if(me->query_temp("taozhuang/h_count")<=0)
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
		if(!me->query_temp("taozhuang/h_1") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/h_1") && EQUALSTR(querystr("base_name"), "lvzhuxiao") 
			&& query("equipped")==WIELD_LEFT_HAND &&!me->is_busy())
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



