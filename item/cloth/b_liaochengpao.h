

//b_liaochengpao.h ��ȴ��Ե��-��ʦ̫5����װ
//�ز� 2002-04-01

EQUIP_BEGIN(CIliaochengpao);

virtual void create(int nFlag = 0)	
{
	set_name( "��ȴ��Ե��");	
	set_weight(3000);		//set item weight
	set("wield_position", WIELD_ARMOR);		
	set("unit", "��");
	set("value", 1);
	set("material", "leather");

	set("long", "��ˮ�仨��ȥҲ�������˼䡣ʩ����������������ӣ��������һ�о������޹��ˡ�");
	set("wield_msg","���¾볤�������³����С�$N��̾һ����������$n��");
 	set("unwield_msg", "������������������ɺ�����������������$N��Եδ�������ǲ�Ҫ��$n�ɡ�");
	
	set("����", random(101)+200);
	
	set("baobei",1);//�޷�������
	set("level",70);

	set("index",2);//��װ֮�以������

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/b_2")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "liaochengpao") && obj->query("equipped")==WIELD_ARMOR )
		{
			me->set("max_hp",me->query_temp("max_hp")+1500);
			me->set("eff_hp",me->query("max_hp"));
			obj->set("owner",me->querystr("id"));
			me->set_temp("taozhuang/b_2",1);
			me->add_temp("taozhuang/b_count",1);
			me->set_temp("apply/index",obj->query("index"));

			me->add_temp("apply/armor", obj->query("����"));
			me->add_temp("apply/int",1);

			if(DIFFERSTR(me->querystr("add_skill/name3"),"huifeng_jian") && EQUALSTR(me->querystr("add_skill/name3"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "������"))
			{	
				me->set_skill("huifeng_jian",me->query_skill("huifeng_jian", 1)+30);
				me->add("add_skill/count",1);
				me->set("add_skill/name3","huifeng_jian");
				me->set("add_skill/level3",30);
				me->FlushMySkill(me);
			}
			if(DIFFERSTR(me->querystr("add_skill/name4"),"yanxing_dao") && EQUALSTR(me->querystr("add_skill/name4"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "������"))
			{	
				me->set_skill("yanxing_dao",me->query_skill("yanxing_dao", 1)+30);
				me->add("add_skill/count",1);
				me->set("add_skill/name4","yanxing_dao");
				me->set("add_skill/level4",30);
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
		if(EQUALSTR(obj->querystr("base_name"), "liaochengpao") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/b_2");
			obj->del("owner");
			me->add_temp("taozhuang/b_count",-1);

			me->set("max_hp",me->query_temp("max_hp"));

			if(me->query("eff_hp")>me->query("max_hp"))
				me->set("eff_hp",me->query("max_hp"));
			else if(me->query("eff_hp")>1500)
				me->add("eff_hp",-1500);
			else
				me->add("eff_hp",-(me->query("eff_hp")-100));

			if(me->query("hp")>me->query("max_hp"))
				me->set("hp",me->query("max_hp"));
			else if(me->query("hp")>1500)
				me->add("hp",-1500);
			else
				me->add("hp",-(me->query("hp")-100));


			me->add_temp("apply/armor", -obj->query("����"));
			me->add_temp("apply/int",-1);
			
			if(EQUALSTR(me->querystr("add_skill/name3"),"huifeng_jian"))
			{
				me->set_skill("huifeng_jian",me->query_skill("huifeng_jian", 1)-30);
				if(me->query_skill("huifeng_jian", 1)<1)me->delete_skill("huifeng_jian");
				me->add("add_skill/count",-1);
				me->del("add_skill/name3");
				me->del("add_skill/level3");
				me->FlushMySkill(me);
			}
			if(EQUALSTR(me->querystr("add_skill/name4"),"yanxing_dao"))
			{
				me->set_skill("yanxing_dao",me->query_skill("yanxing_dao", 1)-30);
				if(me->query_skill("yanxing_dao", 1)<1)me->delete_skill("yanxing_dao");
				me->add("add_skill/count",-1);
				me->del("add_skill/name4");
				me->del("add_skill/level4");
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
		if(!me->query_temp("taozhuang/b_2") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/b_2") && EQUALSTR(querystr("base_name"), "liaochengpao") 
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



