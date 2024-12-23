//h_rumengdai.h �ɻ����η���	�������5����װ
//�ز� 2003-6-24

EQUIP_BEGIN(CIrumengdai);

virtual void create(int nFlag = 0)	
{
	set_name( "�ɻ����η���");	

	set_weight(3000);		//set item weight
    set("wield_position", WIELD_HEAD);		//set the position of wield
	set("unit", "��");
	set("value", 1);
	set("material", "plant");

	set("long", "˿֯�ĳ�������˵��ʴ�²���ɽ����֮˿���ľ�ǧ��ʱ���֯�ɼ�֤�������ľ������¡�");
	set("wear_msg", "����������飬��������Ũ����$N�����ϵ��$n��");
	set("remove_msg", "�����¼��ɿգ�����һ���С���$N��̾һ���⿪��$n��");

	set("level",93);
	set("index",8);//��װ֮�以������

	set("����",20+random(21));

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/h_4")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "rumengdai") && obj->query("equipped")==WIELD_HEAD  )
		{
			me->set_temp("taozhuang/h_4",1);
			me->add_temp("taozhuang/h_count",1);
			
			obj->set("owner",me->querystr("id"));
			me->set_temp("apply/index",obj->query("index"));

			me->add_temp("apply/armor", obj->query("����"));

			if(EQUALSTR(me->querystr("family/family_name"), "��ɽ��"))
				me->set_temp("apply/��_��ϼ��",1);

			if(DIFFERSTR(me->querystr("add_skill/name0"),"lonely_sword") && EQUALSTR(me->querystr("add_skill/name0"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "��ɽ��"))
			{	
				if(me->query_skill("lonely_sword", 1)<400)
				{
					int level=400-me->query_skill("lonely_sword", 1);
					if(level>100)
						level=100;
					me->set_skill("lonely_sword",me->query_skill("lonely_sword", 1)+level);
					me->add("add_skill/count",1);
					me->set("add_skill/name0","lonely_sword");
					me->set("add_skill/level0",level);
					me->FlushMySkill(me);
				}
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
		if(EQUALSTR(obj->querystr("base_name"), "rumengdai") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/h_4");
			obj->del("owner");

			me->add_temp("apply/armor", -obj->query("����"));

			me->add_temp("taozhuang/h_count",-1);

			if(me->query_temp("apply/��_��ϼ��"))
				me->delete_temp("apply/��_��ϼ��");

			if(EQUALSTR(me->querystr("add_skill/name0"),"lonely_sword"))
			{
				me->set_skill("lonely_sword",me->query_skill("lonely_sword", 1)-me->query("add_skill/level0"));
				if(me->query_skill("lonely_sword", 1)<1)
					me->delete_skill("huifeng_jian");
				me->add("add_skill/count",-1);
				me->del("add_skill/name0");
				me->del("add_skill/level0");
				me->FlushMySkill(me);
			}

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
		if(!me->query_temp("taozhuang/h_4")  &&!me->is_busy())
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
		if(me->query_temp("taozhuang/h_4") && EQUALSTR(querystr("base_name"), "rumengdai") 
			&& query("equipped")==WIELD_HEAD &&!me->is_busy()) 
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



