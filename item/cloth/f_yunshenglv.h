//f_yunshenglv.h ������-����7����װ
//�ز� 2002-05-20

EQUIP_BEGIN(CIyunshenglv);

virtual void create(int nFlag = 0)	
{
	set_name( "������");	
	set("wield_position", WIELD_BOOT);		//set the position of wield
	set_weight(10000);	
	
	set("unit", "˫");
	set("value", 1);
	set("material", "leather");
	set("long", "�п����ǡ��������͡����������������Ǹ�ѥ�ӣ�Ҳ�п�������ͬ��Ч����������ͬ����Ʒ����֮��һ�㣬��ѥ�Ӿ��Բ��򵥣�");
	set("wield_msg","$N�Ĵ��ɻ�Ľ�$n���ϣ�ͻȻ����һ�ᣬ���ڿն���");
	set("unwield_msg","$Nһ��С�ľ���$nŪ���ˣ����$N�Ӱ����ˤ����������һ���ûˤ����");
	
	set("level",51);
	set("����",15+random(6));
	
	set("index",6);//��װ֮�以������

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/f_5")||me->query("level")<query("level") ||
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
		if(EQUALSTR(obj->querystr("base_name"), "yunshenglv") && obj->query("equipped")==WIELD_BOOT )
		{
			me->set_temp("taozhuang/f_5",1);
			obj->set("owner",me->querystr("id"));
			me->add_temp("taozhuang/f_count",1);
			me->set_temp("apply/index",obj->query("index"));
			
			me->add_temp("apply/armor", obj->query("����"));
			me->add_temp("apply/dex", 1);

			if(DIFFERSTR(me->querystr("add_skill/name0"),"tiyunzong")&& EQUALSTR(me->querystr("add_skill/name0"),"")
				&& EQUALSTR(me->querystr("family/family_name"), "�䵱��"))
			{	
				me->set_skill("tiyunzong",me->query_skill("tiyunzong", 1)+25);
				me->add("add_skill/count",1);
				me->set("add_skill/name0","tiyunzong");
				me->set("add_skill/level0",25);
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
		if(EQUALSTR(obj->querystr("base_name"), "yunshenglv") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/f_5");
			obj->del("owner");

			me->add_temp("apply/armor", -obj->query("����"));
			me->add_temp("apply/dex", -1);
			me->add_temp("taozhuang/f_count",-1);

			if(EQUALSTR(me->querystr("add_skill/name0"),"tiyunzong"))
			{
				me->set_skill("tiyunzong",me->query_skill("tiyunzong", 1)-25);
				if(me->query_skill("tiyunzong", 1)<1)me->delete_skill("tiyunzong");
				me->add("add_skill/count",-1);
				me->del("add_skill/name0");
				me->del("add_skill/level0");
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
	if(strcmp(comm, "wield") == 0 && !me->Query(CChar::CAN_EQUIPPED))
	{
		if(!me->query_temp("taozhuang/f_5")  &&!me->is_busy())
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
		if(me->query_temp("taozhuang/f_5") && EQUALSTR(querystr("base_name"), "yunshenglv") 
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





