//f_xuanwupao.h �������-����7����װ
//�ز� 2002-05-20

EQUIP_BEGIN(CIxuanwupao);

virtual void create(int nFlag = 0)	
{
	set_name( "�������");	
	set("wield_position", WIELD_ARMOR);		//set the position of wield
	set_weight(10000);	
	
	set("unit", "��");
	set("value", 1);
	set("material", "leather");
	set("long", "һ���ܾɵĵ��ۣ���ֵ�����ȴ��û����Ϊ�����Զ�����á�����ӡ�ŵĴ��İ���ͼ��֤����������Ӳ����򵥡�");
	set("wield_msg","$N��һ��$n�������ϣ�һʱ�����޷����裬���˲������ӡ�");
	set("unwield_msg", "��ʦү�Ķ����������£�$NС�ĵĽ�$n����������");
	
	set("baobei",1);
	set("level",99);
	set("����",80+random(41));
	
	set("index",6);//��װ֮�以������

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/f_4")||me->query("level")<query("level")  || me->query("repute")<1000000 ||
		me->query("max_hp")<5000||
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
		if(EQUALSTR(obj->querystr("base_name"), "xuanwupao") && obj->query("equipped")==WIELD_ARMOR  )
		{
			me->set_temp("taozhuang/f_4",1);
			obj->set("owner",me->querystr("id"));
			me->add_temp("taozhuang/f_count",1);
			me->set_temp("apply/index",obj->query("index"));
			
			int repute;
			if(me->query("repute")<1000000)
			{
				repute=me->query("repute")/20000;
			}
			else 
			{
				if(me->query("repute")>100000000)
					repute=999;
				else
					repute=(me->query("repute")-1000000)/100000+50;
			}
			obj->set("repute",repute);
			me->add_temp("apply/armor", obj->query("����")+repute);
			me->add_temp("apply/per", 1);

			me->set("max_hp",me->query_temp("max_hp")+5000);
			me->set("eff_hp",me->query("max_hp"));
			me->set("hp",me->query("max_hp"));

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
		if(EQUALSTR(obj->querystr("base_name"), "xuanwupao") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/f_4");
			obj->del("owner");

			me->add_temp("apply/armor", -(obj->query("����")+obj->query("repute")));
			me->add_temp("apply/per", -1);

			me->set("max_hp",me->query_temp("max_hp"));
			if(me->query("max_hp")<0)
				me->set("max_hp",100);
			
			if(me->query("eff_hp")>me->query("max_hp"))
				me->set("eff_hp",me->query("max_hp"));
			else if(me->query("eff_hp")>5000)
				me->add("eff_hp",-5000);
			else
				me->add("eff_hp",-(me->query("eff_hp")-100));

			if(me->query("hp")>me->query("max_hp"))
				me->set("hp",me->query("max_hp"));
			else if(me->query("hp")>5000)
				me->add("hp",-5000);
			else
				me->add("hp",-(me->query("hp")-100));

			me->add_temp("taozhuang/f_count",-1);

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
		if(!me->query_temp("taozhuang/f_4")  &&!me->is_busy())
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
		if(me->query_temp("taozhuang/f_4") && EQUALSTR(querystr("base_name"), "xuanwupao") 
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




