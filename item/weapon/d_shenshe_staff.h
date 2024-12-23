//d_shenshe_staff.h �϶�������	ŷ������4����װ
//�ز� 2002-04-08

EQUIP_BEGIN(CIshenshe_staff);

virtual void create(int nFlag = 0)	
{
	set_name( "�϶�������");	

    set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "staff");
	set_weight(20000);		
	set("unit", "��");
	set("value", 1);
	set("material", "steel");
	set("no_duo",1);//�����Զ���

//	set("long", "�϶����ģ������������⣬Ϊ�˲��˷���Ƥ������������ö�������ɱ�������Σ����ң�ζ���ü��ˣ�");
	set("wield_msg", "$N�������$n����������Դ������㻹�Ҳ���˵�Լ�˧��");
	set("unwield_msg", "$N�������ŵĽ�$n���������");

	set("����",250);
	set("index",4);//��װ֮�以������

	set("level",90);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/d_3")||me->query("level")<query("level") ||(me->query_temp("apply/index")!=query("index") 
		&& me->query_temp("apply/index")) || me->query("repute")>-500000)
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
			if(me->query_temp("taozhuang/d_3"))
			{
				me->delete_temp("taozhuang/d_3");
				me->add_temp("taozhuang/d_count",-1);
				
				if(me->query_temp("taozhuang/d_count")<=0)
					me->delete_temp("apply/index");
				ob->del("owner");
				
				me->add_temp("apply/damage", -250);
				
				if(EQUALSTR(me->querystr("add_skill/name0"),"lingshe_zhangfa"))
				{
					me->set_skill("lingshe_zhangfa",me->query_skill("lingshe_zhangfa", 1)-me->query("add_skill/level0"));
					if(me->query_skill("lingshe_zhangfa", 1)<1)me->delete_skill("lingshe_zhangfa");
					me->add("add_skill/count",-1);
					me->del("add_skill/name0");
					me->del("add_skill/level0");
					me->FlushMySkill(me);
				}
				
				if(me->query_temp("taozhuang/d"))
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
				}
			}
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
		if(EQUALSTR(obj->querystr("base_name"), "shenshe_staff") && obj->query("equipped")==WIELD_RIGHT_HAND)
		{
			me->set_temp("taozhuang/d_3",1);
			me->add_temp("taozhuang/d_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/damage", 250);
			
			if(DIFFERSTR(me->querystr("add_skill/name0"),"lingshe_zhangfa")&& EQUALSTR(me->querystr("add_skill/name0"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "����ɽ��"))
			{	
				me->add("add_skill/count",1);
				me->set("add_skill/name0","lingshe_zhangfa");
				me->set("add_skill/level0",50);
				me->set_skill("lingshe_zhangfa",me->query_skill("lingshe_zhangfa", 1)+me->query("add_skill/level0"));
				me->FlushMySkill(me);
			}
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
		if(EQUALSTR(obj->querystr("base_name"), "shenshe_staff") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/d_3");
			me->add_temp("taozhuang/d_count",-1);

			if(me->query_temp("taozhuang/d_count")<=0)
				me->delete_temp("apply/index");
			obj->del("owner");

			me->add_temp("apply/damage", -250);

			if(EQUALSTR(me->querystr("add_skill/name0"),"lingshe_zhangfa"))
			{
				me->set_skill("lingshe_zhangfa",me->query_skill("lingshe_zhangfa", 1)-me->query("add_skill/level0"));
				if(me->query_skill("lingshe_zhangfa", 1)<1)me->delete_skill("lingshe_zhangfa");
				me->add("add_skill/count",-1);
				me->del("add_skill/name0");
				me->del("add_skill/level0");
				me->FlushMySkill(me);
			}

			if(me->query_temp("taozhuang/d"))
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
		if(!me->query_temp("taozhuang/d_3")&&  !me->is_busy())
		{
			me->disable_player("װ����");
			if(query("apple/per"))del("apply/per");
			if(query("apply/no_Ӣ����ʽ"))del("apply/no_Ӣ����ʽ");
			if(query("apply/no_��������"))del("apply/no_��������");
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
		if(me->query_temp("taozhuang/d_3") && EQUALSTR(querystr("base_name"), "shenshe_staff") 
			&& query("equipped")==WIELD_RIGHT_HAND && !me->is_busy())
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

const char * hit_ob(CChar *me, CChar *victim, LONG damage_bonus)
{
	if(random(100)<10)
	{
		if(!victim->query_temp("disfigurement"))
		{
			message_vision("\n$HIR$Nһ�ȴ���$n���ϣ���$n������˹�������\n",me,victim);
			if(victim->query("per"))victim->add("per",-1);
			victim->add("disfigurement",1);//Ԥ�����ݼ�¼��ͨ�����ΤС�������ָ�����ʹ��
			victim->set_temp("disfigurement",1);
		}
	}
	return 0;
}

EQUIP_END;



