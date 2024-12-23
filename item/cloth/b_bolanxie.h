

//b_bolanxie.h ��������Ь-��ʦ̫5����װ
//�ز� 2002-04-01

EQUIP_BEGIN(CIbolanxie);

virtual void create(int nFlag = 0)	
{
	set_name( "��������Ь");	
	set("wield_position", WIELD_BOOT);		//set the position of wield
 	set_weight(800);		//set item weight
	set("material", "leather");
	set("unit", "˫");
	set("value", 1);

	set("long", "һ���ƣ�һ���ڣ�������ٯ�м��ˣ�����һ˫�ܻ������³�޵�Ь����˵�ǵ����ʦ̫�����");
	set("wield_msg","�����ಽ��ף��������Ь��������ʫ�⣬$N������$n��");
 	set("unwield_msg", "��Ƭ����ɨ���������������˹顱��$N����ֹˮ��������$n��");
	
	
	set("level",48);

	set("index",2);//��װ֮�以������

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/b_4")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "bolanxie") && obj->query("equipped")==WIELD_BOOT)
		{
			me->set_temp("taozhuang/b_4",1);
			obj->set("owner",me->querystr("id"));
			me->add_temp("taozhuang/b_count",1);
			me->set_temp("apply/index",obj->query("index"));

			me->add_temp("apply/armor", 40);

			if(DIFFERSTR(me->querystr("add_skill/name2"),"zhutian_bu") && EQUALSTR(me->querystr("add_skill/name2"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "������"))
			{	
				me->set_skill("zhutian_bu",me->query_skill("zhutian_bu", 1)+30);
				me->add("add_skill/count",1);
				me->set("add_skill/name2","zhutian_bu");
				me->set("add_skill/level2",30);
				me->FlushMySkill(me);
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
		if(EQUALSTR(obj->querystr("base_name"), "bolanxie") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")))
		{
			me->delete_temp("taozhuang/b_4");
			obj->del("owner");
			me->add_temp("taozhuang/b_count",-1);
			me->add_temp("apply/armor",-40);

			if(EQUALSTR(me->querystr("add_skill/name2"),"zhutian_bu"))
			{
				me->set_skill("zhutian_bu",me->query_skill("zhutian_bu", 1)-30);
				if(me->query_skill("zhutian_bu", 1)<1)me->delete_skill("zhutian_bu");
				me->add("add_skill/count",-1);
				me->del("add_skill/name2");
				me->del("add_skill/level2");
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
		if(!me->query_temp("taozhuang/b_4")  &&!me->is_busy())
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
		if(me->query_temp("taozhuang/b_4") && EQUALSTR(querystr("base_name"), "bolanxie") 
			&& query("equipped")==WIELD_BOOT &&!me->is_busy()) 
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



