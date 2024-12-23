//d_haoseshan.h ���Ӻ�ɫ����	ŷ������4����װ
//�ز� 2002-03-26

EQUIP_BEGIN(CIhaoseshan);

virtual void create(int nFlag = 0)	
{
	set_name( "���Ӻ�ɫ����");	

    set("wield_position", WIELD_HAND);		//set the position of wield
	set("skill_type", "dagger");			//set the skill applied
	set_weight(1000);		//set item weight
	
	set("unit", "��");
	set("long", "��������Ϊ�����Ȳź�ɫ��������Ϊ��ɫ�����ȣ�");
	set("value", 1);
	set("material", "steel");
	set("no_duo",1);//�����Զ���
	set("wield_msg", "$N������һ����һ��$n�����֣���������֮����");
	set("unwield_msg", "ֻ��$NĿ����������֪ʲôʱ��$n�Ѿ����������䡣");
	
	set("index",4);//��װ֮�以������

	set("level",45);
	set("����",45);

};

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/d_1")||me->query("level")<query("level") 
		|| EQUALSTR(querystr("name"),"�ϵ��ľ��Ӻ�ɫ����")
		||(me->query_temp("apply/index")!=query("index") && me->query_temp("apply/index")) || me->query("repute")>-500000)
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
			if(me->query_temp("taozhuang/d_1"))
			{
				me->delete_temp("taozhuang/d_1");
				me->add_temp("taozhuang/d_count",-1);
				
				ob->del("owner");
				
				me->add_temp("apply/mf",-me->query("level"));
				me->add_temp("apply/damage", -45);
				me->add_temp("apply/per",-2);
				me->add_temp("apply/chuantou",-10);
				me->add_temp("apply/chuantou_df",-10);
				
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
				
				if(me->query_temp("taozhuang/d_count")<=0)
					me->delete_temp("apply/index");
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
		if(EQUALSTR(obj->querystr("base_name"), "haoseshan") 
			&& (obj->query("equipped")==8 ||obj->query("equipped")==7 ||obj->query("equipped")==6))
		{
			me->set_temp("taozhuang/d_1",1);
			me->add_temp("taozhuang/d_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));

			me->add_temp("apply/mf",me->query("level"));
			me->add_temp("apply/damage", 45);
			me->add_temp("apply/per",2);
			me->add_temp("apply/chuantou",10);
			me->add_temp("apply/chuantou_df",10);
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
		if(EQUALSTR(obj->querystr("base_name"), "haoseshan") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")))
		{
			me->delete_temp("taozhuang/d_1");
			me->add_temp("taozhuang/d_count",-1);
			
			obj->del("owner");

			me->add_temp("apply/mf",-me->query("level"));
			me->add_temp("apply/damage", -45);
			me->add_temp("apply/per",-2);
			me->add_temp("apply/chuantou",-10);
			me->add_temp("apply/chuantou_df",-10);
			
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
			
			if(me->query_temp("taozhuang/d_count")<=0)
				me->delete_temp("apply/index");
			break;
		}
	}
	me->enable_player();
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "wield") == 0 && !me->Query(CChar::CAN_EQUIPPED))
	{
		if(query("apply/mf"))del("apply/mf");
		if(!me->query_temp("taozhuang/d_1") &&!me->is_busy())
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
		if(me->query_temp("taozhuang/d_1") && EQUALSTR(querystr("base_name"), "haoseshan") 
			&& (query("equipped")==8 ||query("equipped")==7 ||query("equipped")==6)
			&&!me->is_busy())
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
	if(!random(100/me->query_temp("apply/chuantou")))
	{
		DTItemList * list = victim->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(obj->is_character()) continue; 
			if(obj->query("no_chuantou")!=1 && obj->query("equipped")==WIELD_ARMOR)
			{
				message_vision("$HIRֻ����������������Ŷ��ӣ�$N���һ����ȴ����װ�ױ����˸�����",victim);
				int df=victim->query("hp")*me->query_temp("apply/chuantou_df")/100;
				if(df>victim->query("hp")/2)df=victim->query("hp")/2;
				victim->receive_damage("hp", df);
				victim->receive_wound("hp", df/2);
				victim->UpdateMe();
				break;
			}
		}
	}
	return 0;
}

EQUIP_END;



