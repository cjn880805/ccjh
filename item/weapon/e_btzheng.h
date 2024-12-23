//e_btzheng.h bt�廨��-����7����װ
//�ز� 2002-05-18

EQUIP_BEGIN(CIbtzheng);

virtual void create(int nFlag = 0)	
{
	set_name( "BT�廨��");	

    set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(1000);		//set item weight
	
	set("unit", "��");
	set("long", "һ���롣һ��ɱ�˵��롣һ��ɱ�˲���Ѫ���롣");
	set("value", 1);
	set("material", "steel");
	set("no_duo",1);//�����Զ���
	set("wield_msg", "$N������˿��������ʵ�ѽ�һ��$HIR$n$COM���������");
	set("unwield_msg", "$N����΢���������е�$HIR$n$COM��������ڡ�");
	set("����", 100+random(51));

	set("index",5);//��װ֮�以������

	set("level",50);

};

virtual int Can_Equip(CChar * me)
{
	if(DIFFERSTR(me->querystr("gender"), "����")||me->query_temp("taozhuang/e_1")||me->query("level")<query("level") 
		|| EQUALSTR(querystr("name"),"�ϵ���BT�廨��")
		|| (me->query_temp("apply/index")!=query("index") && me->query_temp("apply/index")))
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
			if(me->query_temp("taozhuang/e_1"))
			{
				me->delete_temp("taozhuang/e_1");
				me->add_temp("taozhuang/e_count",-1);
				
				if(me->query_temp("taozhuang/e_count")<=0)
					me->delete_temp("apply/index");
				ob->del("owner");
				
				me->add_temp("apply/damage", -ob->query("����"));
				me->add_temp("apply/str", 3);
				
				if(EQUALSTR(me->querystr("add_skill/name0"),"pixie_jian"))
				{
					me->set_skill("pixie_jian",me->query_skill("pixie_jian", 1)-me->query("add_skill/level0"));
					if(me->query_skill("pixie_jian", 1)<1)me->delete_skill("pixie_jian");
					me->add("add_skill/count",-1);
					me->del("add_skill/name0");
					me->del("add_skill/level0");
					me->FlushMySkill(me);
				}
				
				if(me->query_temp("taozhuang/e"))
				{
					me->delete_temp("taozhuang/e");
					me->add_temp("apply/str",-1);
					me->add_temp("apply/int",-1);
					me->add_temp("apply/per",-2);
					me->delete_temp("apply/pro_��Ŀ");
					tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
				}
				me->UpdateMe();
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
		if(EQUALSTR(obj->querystr("base_name"), "btzheng") && obj->query("equipped")==WIELD_RIGHT_HAND )
		{
			me->set_temp("taozhuang/e_1",1);
			me->add_temp("taozhuang/e_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/damage", obj->query("����"));
			me->add_temp("apply/str", -3);

			if(DIFFERSTR(me->querystr("add_skill/name0"),"pixie_jian")&& EQUALSTR(me->querystr("add_skill/name0"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "�������"))
			{	
				me->add("add_skill/count",1);
				me->set("add_skill/name0","pixie_jian");
				me->set("add_skill/level0",30);
				me->set_skill("pixie_jian",me->query_skill("pixie_jian", 1)+me->query("add_skill/level0"));
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
		if(EQUALSTR(obj->querystr("base_name"), "btzheng") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")))
		{
			me->delete_temp("taozhuang/e_1");
			me->add_temp("taozhuang/e_count",-1);

			if(me->query_temp("taozhuang/e_count")<=0)
				me->delete_temp("apply/index");
			obj->del("owner");

			me->add_temp("apply/damage", -obj->query("����"));
			me->add_temp("apply/str", 3);

			if(EQUALSTR(me->querystr("add_skill/name0"),"pixie_jian"))
			{
				me->set_skill("pixie_jian",me->query_skill("pixie_jian", 1)-me->query("add_skill/level0"));
				if(me->query_skill("pixie_jian", 1)<1)me->delete_skill("pixie_jian");
				me->add("add_skill/count",-1);
				me->del("add_skill/name0");
				me->del("add_skill/level0");
				me->FlushMySkill(me);
			}

			if(me->query_temp("taozhuang/e"))
			{
				me->delete_temp("taozhuang/e");
				tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
			}
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
		if(!me->query_temp("taozhuang/e_1") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/e_1") && EQUALSTR(querystr("base_name"), "btzheng") 
			&& query("equipped")==WIELD_RIGHT_HAND &&!me->is_busy())
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
	if(random(100)<5)
	{
		if(!victim->query_temp("disfigurement"))
		{
			message_vision("\n$HIR$N���е��廨����ͬ�������$n����һ�󼱴̣�$n��������һƬ��ʹ����\n$n���������ˡ�",me,victim);
			if(victim->query("per"))victim->add("per",-1);
			victim->add("disfigurement",1);//Ԥ�����ݼ�¼��ͨ�����ΤС�������ָ�����ʹ��
			victim->set_temp("disfigurement",1);
		}
	}
	return 0;
}

EQUIP_END;


