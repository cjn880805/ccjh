//d_yinmopao.h ��ħ��	ŷ������4����װ
//�ز� 2002-04-08

EQUIP_BEGIN(CIyinmopao);

virtual void create(int nFlag = 0)	
{
	set_name( "��ħ��");	

	set("wield_position", WIELD_ARMOR);		
 	set_weight(9000);	
          
	set("unit", "��");
	set("value", 1);
	set("material", "leather");

	set("long", "��˵�еĺ�ɫ֮ͽ��ǿ��װ����ǧ�ɲ�Ҫ��ɫ�ǵõ�����");
	set("wield_msg", "ֻ��$N˫��һ˦���Էǳ�Ư�������ƽ�һ��$n���������ϡ�");
	set("unwield_msg", "$Nͷ��һ˦��������$n�����ڼ��ϡ�");

	set("index",4);//��װ֮�以������

	set("level",100);
};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/d_4")||me->query("level")<query("level") ||(me->query_temp("apply/index")!=query("index") 
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
		if(EQUALSTR(obj->querystr("base_name"), "yinmopao") && obj->query("equipped")==WIELD_ARMOR )
		{
			me->set_temp("taozhuang/d_4",1);
			me->add_temp("taozhuang/d_count",1);
			me->set_temp("apply/index",obj->query("index"));
			me->set("max_hp",me->query_temp("max_hp")+3500);
			me->set("eff_hp",me->query("max_hp"));

			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/armor", 350);
			me->add_temp("apply/mf", 45);
			me->set_temp("apply/no_��Ȼ����",1);
			me->set_temp("apply/no_��ȴǧ��",1);
			me->set_temp("apply/no_������",1);

			if(DIFFERSTR(me->querystr("add_skill/name1"),"hamagong")&& EQUALSTR(me->querystr("add_skill/name1"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "����ɽ��"))
			{	
				me->add("add_skill/count",1);
				me->set("add_skill/name1","hamagong");
				me->set("add_skill/level1",50);
				me->set_skill("hamagong",me->query_skill("hamagong", 1)+me->query("add_skill/level1"));
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
		if(EQUALSTR(obj->querystr("base_name"), "yinmopao") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/d_4");
			me->add_temp("taozhuang/d_count",-1);

			me->set("max_hp",me->query_temp("max_hp"));

			if(me->query("eff_hp")>me->query("max_hp"))
				me->set("eff_hp",me->query("max_hp"));
			else if(me->query("eff_hp")>3500)
				me->add("eff_hp",-3500);
			else
				me->add("eff_hp",-(me->query("eff_hp")-100));

			if(me->query("hp")>me->query("max_hp"))
				me->set("hp",me->query("max_hp"));
			else if(me->query("hp")>3500)
				me->add("hp",-3500);
			else
				me->add("hp",-(me->query("hp")-100));

			obj->del("owner");

			me->add_temp("apply/armor", -350);
			me->add_temp("apply/mf", -45);
			me->delete_temp("apply/no_��Ȼ����");
			me->delete_temp("apply/no_��ȴǧ��");
			me->delete_temp("apply/no_������");

			if(EQUALSTR(me->querystr("add_skill/name1"),"hamagong"))
			{
				me->set_skill("hamagong",me->query_skill("hamagong", 1)-me->query("add_skill/level1"));
				if(me->query_skill("hamagong", 1)<1)me->delete_skill("hamagong");
				me->add("add_skill/count",-1);
				me->del("add_skill/name1");
				me->del("add_skill/level1");
				me->FlushMySkill(me);
			}

			if(me->query_temp("taozhuang/d"))
			{
				DTItemList * list = me->Get_ItemList();  
				POSITION p = list->GetHeadPosition(); 
				while(p) 
				{ 
					CContainer * obj = list->GetNext(p);
					if(obj->is_character()) continue; 
					if(EQUALSTR(obj->querystr("base_name"), "dulonglian") && obj->query("equipped")==WIELD_NECK )
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

						me->delete_temp("taozhuang/d");
						me->delete_temp("apply/no_Ӣ����ʽ");
						me->delete_temp("apply/no_��������");
						me->add_temp("apply/per",-3);
						if(me->query_temp("apply/per")<=0)me->delete_temp("apply/per");
						me->add_temp("apply/mf",-125);
						if(me->query_temp("apply/mf")<=0)me->delete_temp("apply/mf");
						tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
						break;
					}
				}
			}
			if(me->query_temp("taozhuang/d_count")<=0)
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
		if(!me->query_temp("taozhuang/d_4") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/d_4") && EQUALSTR(querystr("base_name"), "yinmopao") 
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



