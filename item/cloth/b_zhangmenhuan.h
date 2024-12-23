//b_zhangmenhuan.h ������ָ��-��ʦ̫5����װ
//�ز� 2002-04-01

EQUIP_BEGIN(CIzhangmenhuan);

virtual void create(int nFlag = 0)	
{
	set_name( "������ָ��");	
	set("wield_position", WIELD_RING);		
 	set_weight(200);		
	set("unit", "ö");
	set("value", 1);
	set("material", "��ʯ");

	set("long", "���ѳ���׳��������");
	set("wear_msg", "��ȥ�껨���ϣ���������Բ������$N��ɫ���µĽ�$n������ȥ��");
	set("remove_msg", "�������Ը����Υ�������ⲻ��$N��$n������ȡ�����ɡ�");
	
	set("level",85);

	set("index",2);//��װ֮�以������

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/b_5")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "zhangmenhuan") && obj->query("equipped")==WIELD_RING )
		{
			me->set_temp("taozhuang/b_5",1);
			me->add_temp("taozhuang/b_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", 120);
			me->set_temp("apply/no_�ƺ�����",1);	
			me->set_temp("apply/no_����������",1);
			me->set_temp("apply/no_���־�",1);

			if(obj->query("apply/damage"))obj->del("apply/damage");
			if(obj->query("apply/str"))obj->del("apply/str");
			if(obj->query("apply/con"))obj->del("apply/con");
			if(obj->query("apply/dex"))obj->del("apply/dex");
			if(obj->query("apply/int"))obj->del("apply/int");
			if(obj->query("apply/per"))obj->del("apply/per");
			if(obj->query("apply/no_���־�"))obj->del("apply/no_���־�");
			if(obj->query("apply/no_�黨��Ѩ"))obj->del("apply/no_�黨��Ѩ");
			if(obj->query("apply/no_superkill"))obj->del("apply/no_superkill");

			if(DIFFERSTR(me->querystr("add_skill/name5"),"tiangang_zhi") && EQUALSTR(me->querystr("add_skill/name5"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "������"))
			{	
				me->set_skill("tiangang_zhi",me->query_skill("tiangang_zhi", 1)+30);
				me->add("add_skill/count",1);
				me->set("add_skill/name5","tiangang_zhi");
				me->set("add_skill/level5",30);
				me->FlushMySkill(me);
			}
			if(me->query_temp("taozhuang/b_count")==5 &&!me->query_temp("taozhuang/b"))
			{
				me->add_temp("apply/damage", 100);
				me->add_temp("apply/str",1);
				me->add_temp("apply/con",1);
				me->add_temp("apply/dex",1);
				me->add_temp("apply/int",1);
				me->add_temp("apply/per",1);
				me->set_temp("apply/no_���־�",1);
				me->set_temp("apply/no_�黨��Ѩ",1);
				me->set_temp("apply/no_superkill",1);
				tell_object(me,"$HIR\n������޺����⣿�����������ޣ�\n�㿴͸�����¸������ճ�������");
				me->set_temp("taozhuang/b",1);
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
		if(EQUALSTR(obj->querystr("base_name"), "zhangmenhuan") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/b_5");
			me->add_temp("taozhuang/b_count",-1);
			obj->del("owner");

			me->add_temp("apply/armor", -120);
			me->delete_temp("apply/no_�ƺ�����");	
			me->delete_temp("apply/no_����������");
			me->delete_temp("apply/no_���־�");

			if(EQUALSTR(me->querystr("add_skill/name5"),"tiangang_zhi"))
			{
				me->set_skill("tiangang_zhi",me->query_skill("tiangang_zhi", 1)-30);
				if(me->query_skill("tiangang_zhi", 1)<1)me->delete_skill("tiangang_zhi");
				me->add("add_skill/count",-1);
				me->del("add_skill/name5");
				me->del("add_skill/level5");
				me->FlushMySkill(me);
			}
			if(me->query_temp("taozhuang/b"))
			{
				me->delete_temp("taozhuang/b");
				me->add_temp("apply/damage", -100);
				if(me->query_temp("apply/damage")<=0)me->delete_temp("apply/damage");
				me->add_temp("apply/str",-1);
				if(me->query_temp("apply/str")<=0)me->delete_temp("apply/str");
				me->add_temp("apply/con",-1);
				if(me->query_temp("apply/con")<=0)me->delete_temp("apply/con");
				me->add_temp("apply/dex",-1);
				if(me->query_temp("apply/dex")<=0)me->delete_temp("apply/dex");
				me->add_temp("apply/int",-1);
				if(me->query_temp("apply/int")<=0)me->delete_temp("apply/int");
				me->add_temp("apply/per",-1);
				if(me->query_temp("apply/per")<=0)me->delete_temp("apply/per");
				me->delete_temp("apply/no_���־�");
				me->delete_temp("apply/no_�黨��Ѩ");
				me->delete_temp("apply/no_superkill");
				tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
			}

			if(me->query_temp("taozhuang/b_count")<=0)
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
		if(!me->query_temp("taozhuang/b_5") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/b_5") && EQUALSTR(querystr("base_name"), "zhangmenhuan") 
			&& query("equipped")==WIELD_RING &&!me->is_busy())
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



