//f_qinjianhun.h ����ʯ*��-����7����װ
//�ز� 2002-10-14

EQUIP_BEGIN(CIqinjianhun);

virtual void create(int nFlag = 0)	
{
	set_name( "����ʯ*��");	
	set("wield_position", WIELD_RING);		//set the position of wield
	set_weight(10000);	
	
	set("unit", "��");
	set("value", 1);
	set("material", "leather");
	set("long", "����һ����ɫ�Ľ�ָ����Ϊ�������䵱�����������ֵ�˼���������ò���˼��������");
	set("wield_msg","$N����$n��ͻȻ����ڤڤ����������$N�������գ�$N����ѧ����ﵽ��һ���µĸ߶ȡ�");
	set("unwield_msg","$NͻȻ��������һƬ���ң�֪�������æ��$nȡ��������");
	
	set("level",89);
	set("����",50+random(31));
	set("��Ѫ",1+random(3));
	set("Ѫ�ָ�",50+random(31));
	
	set("index",6);//��װ֮�以������

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/f_6")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "qinjianhun") && obj->query("equipped")==WIELD_RING )
		{
			me->set_temp("taozhuang/f_6",1);
			obj->set("owner",me->querystr("id"));
			me->add_temp("taozhuang/f_count",1);
			me->set_temp("apply/index",obj->query("index"));
			
			me->add_temp("apply/armor", obj->query("����"));
			me->set_temp("apply/��Ѫ", obj->query("��Ѫ"));
			me->set_temp("apply/Ѫ�ָ�", obj->query("Ѫ�ָ�"));
	
			if(DIFFERSTR(me->querystr("add_skill/name1"),"taiji_jian")&& EQUALSTR(me->querystr("add_skill/name1"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "�䵱��"))
			{	
				me->set_skill("taiji_jian",me->query_skill("taiji_jian", 1)+20);
				me->add("add_skill/count",1);
				me->set("add_skill/name1","taiji_jian");
				me->set("add_skill/level1",20);
				me->FlushMySkill(me);
			}

			me->UpdateMe();
			me->call_out(do_hphueifu, 2);
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
		if(EQUALSTR(obj->querystr("base_name"), "qinjianhun") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/f_6");
			obj->del("owner");

			me->add_temp("apply/armor", -obj->query("����"));
			me->delete_temp("apply/��Ѫ");
			me->delete_temp("apply/Ѫ�ָ�");

			me->add_temp("taozhuang/f_count",-1);

			if(EQUALSTR(me->querystr("add_skill/name1"),"taiji_jian"))
			{
				me->set_skill("taiji_jian",me->query_skill("taiji_jian", 1)-20);
				if(me->query_skill("taiji_jian", 1)<1)me->delete_skill("taiji_jian");
				me->add("add_skill/count",-1);
				me->del("add_skill/name1");
				me->del("add_skill/level1");
				me->FlushMySkill(me);
			}

			if(me->query_temp("taozhuang/f"))
			{
				me->delete_temp("taozhuang/f");
				tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
			}
			if(me->query_temp("taozhuang/f_count")<=0)
				me->delete_temp("apply/index");
			me->UpdateMe();
			break;
		}
	}
	me->enable_player();
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "wield") == 0 && !me->Query(CChar::CAN_EQUIPPED) )
	{
		if(!me->query_temp("taozhuang/f_6") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/f_6") && EQUALSTR(querystr("base_name"), "qinjianhun") 
			&& query("equipped")==WIELD_RING &&!me->is_busy()) 
		{
			me->remove_call_out(do_hphueifu);
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

static void do_hphueifu(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(me->query_temp("taozhuang/f_6"))
	{
		if(random(100)<= me->query_temp("apply/��Ѫ") && me->query_temp("fight/is_fighting"))
		{
			int effhp=me->query_temp("apply/Ѫ�ָ�");
			if(me->query("hp")<me->query("max_hp"))
			{
				me->add("hp",me->query("max_hp")*effhp/100);
				me->set("eff_hp",me->query("max_hp"));
				if(me->query("hp")>me->query("max_hp"))
					me->set("hp",me->query("max_hp"));
				message_vision("$HIR$N�ڽ���ʯ*��ıӻ��£������Ļָ���������",me);
				me->UpdateMe();
			}
		}
		me->call_out(do_hphueifu, 2);
	}
}

EQUIP_END;





