//h_cangzuihu.h ����Ը�Ѿƺ�	�������5����װ
//�ز� 2003-6-24

EQUIP_BEGIN(CIcangzuihu);

virtual void create(int nFlag = 0)	
{
	set_name( "����Ը�Ѿƺ�");	
	set_weight(3000);		
    set("wield_position", WIELD_WAIST);		
	
	set("unit", "��");
	set("value", 1);
	set("material", "leather");

	set("long", "����������ͨ��һ���ƺ������е����ƺ������������յ�һ��������ֻ��һ���ǧ�");
	set("wield_msg", "$Nһ�ߵ�����������Ѱ��ǧ�ٶ�,��Ը����Ը�ѡ���һ��װ����$n��");
	set("unwield_msg", "$Nж��$n���ҳ�������������һ��,�������ѡ���");
	
	set("level",97);
	set("index",8);//��װ֮�以������

	set("����",5+random(5));

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/h_3")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "cangzuihu") && obj->query("equipped")==WIELD_WAIST  )
		{
			me->set_temp("taozhuang/h_3",1);
			me->add_temp("taozhuang/h_count",1);
			
			obj->set("owner",me->querystr("id"));
			me->set_temp("apply/index",obj->query("index"));

			me->add_temp("apply/damage", obj->query("����"));
			me->add_temp("apply/dex", 2);

			if(EQUALSTR(me->querystr("family/family_name"), "��ɽ��"))
				//1�����¾Ž����Ƽ�ʽ���Ʊ�ʽ����ǹʽ������ʽ������ʽ��Ϊͬʱ�����Է�ȫ��
				//2�����¾Ž����Ƶ�ʽ���ƽ�ʽ��Ϊͬʱ�����Է�ȫ��
				//3�����¾Ž������о��б�Ϊͬʱ�����Է�ȫ��
				me->set_temp("apply/Ⱥ_���¾Ž�",1);

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
		if(EQUALSTR(obj->querystr("base_name"), "cangzuihu") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/h_3");
			obj->del("owner");

			me->add_temp("apply/damage", -obj->query("����"));
			me->add_temp("apply/dex", -2);

			me->add_temp("taozhuang/h_count",-1);

			if(me->query_temp("apply/Ⱥ_���¾Ž�"))
				me->delete_temp("apply/Ⱥ_���¾Ž�");

			if(me->query_temp("taozhuang/h"))
			{
				me->delete_temp("taozhuang/h");
				tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
			}
			if(me->query_temp("taozhuang/h_count")<=0)
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
		if(!me->query_temp("taozhuang/h_3")  &&!me->is_busy())
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
		if(me->query_temp("taozhuang/h_3") && EQUALSTR(querystr("base_name"), "cangzuihu") 
			&& query("equipped")==WIELD_WAIST &&!me->is_busy()) 
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



