//a_38huoqiang.h �����˻�ǹ
//�ز� 2002-03-25

EQUIP_BEGIN(CI38huoqiang);

virtual void create(int nFlag = 0)	
{
	set_name( "�����˻�ǹ");	

	set("wield_position", WIELD_HAND);		//set the position of wield
	set("skill_type", "staff");			//set the skill applied
	set_weight(8000);		//set item weight
	
	set("unit", "֧");
	set("long", "���ǵ���Τ��үʹ�ù��Ļ�ǹ����������ڹ������⿴������֪�������Ǵ�Ʒ��");
	set("value", 1);
	set("material", "steel");
	set("no_duo",1);//�����Զ���
	set("wield_msg", "ֻ�����顱��һ����$N������������ָָ����ǹ֮�ˣ�ȴ�����Ż�ǹ�����ֲ������");
	set("unwield_msg", "$N���˴�ǹ����δɢ�������̣��������˱������䡣");

	set("index",1);//��װ֮�以������

	set("level",25);
	set("����",80);

};

int query_autoload()
{
	return 1;
}

virtual int Can_Equip(CChar * me)
{
	if(me->query_temp("taozhuang/a_1")||me->query("level")<query("level") || EQUALSTR(querystr("name"),"�ϵ��ĵ����˻�ǹ")||
		(me->query_temp("apply/index")!=query("index") && me->query_temp("apply/index")))
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
			if(me->query_temp("taozhuang/a_1"))
			{
				me->delete_temp("taozhuang/a_1");
				me->add_temp("taozhuang/a_count",-1);
				ob->del("owner");
				
				me->add_temp("apply/damage", -80);
				me->add_temp("apply/str",-2);
				me->add_temp("apply/jisuei",-20);
				
				if(me->query_temp("taozhuang/a")==1)
				{
					me->add_temp("apply/damage",-20);
					if(me->query_temp("apply/damage")<=0)me->delete_temp("apply/damage");
					me->add_temp("apply/str",-3);
					if(me->query_temp("apply/str")<=0)me->delete_temp("apply/str");
					me->delete_temp("taozhuang/a");
					tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
				}
				if(me->query_temp("taozhuang/a_count")<=0)
					me->delete_temp("apply/index");
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
		if(EQUALSTR(obj->querystr("base_name"), "38huoqiang") && (obj->query("equipped")==WIELD_RIGHT_HAND ||obj->query("equipped")==WIELD_LEFT_HAND) )
		
		{
			me->set_temp("taozhuang/a_1",1);
			me->add_temp("taozhuang/a_count",1);
			me->set_temp("apply/index",obj->query("index"));
			obj->set("owner",me->querystr("id"));
			
			me->add_temp("apply/damage", 80);
			me->add_temp("apply/str",2);
			me->add_temp("apply/jisuei",20);
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
		if(EQUALSTR(obj->querystr("base_name"), "38huoqiang") && !obj->query("equipped")
			&& atoi(obj->querystr("owner")) )
		{
			me->delete_temp("taozhuang/a_1");
			me->add_temp("taozhuang/a_count",-1);
			obj->del("owner");

			me->add_temp("apply/damage", -80);
			me->add_temp("apply/str",-2);
			me->add_temp("apply/jisuei",-20);

			if(me->query_temp("taozhuang/a")==1)
			{
				me->add_temp("apply/damage",-20);
				if(me->query_temp("apply/damage")<=0)me->delete_temp("apply/damage");
				me->add_temp("apply/str",-3);
				if(me->query_temp("apply/str")<=0)me->delete_temp("apply/str");
				me->delete_temp("taozhuang/a");
				tell_object(me,"$HIR\n�����ϵ���װж��һ��,��װ�ĸ��ӹ���Ҳ������ʧ�ˡ�\n");
			}
			if(me->query_temp("taozhuang/a_count")<=0)
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
		if(!me->query_temp("taozhuang/a_1")&& !me->is_busy() )
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
		if(me->query_temp("taozhuang/a_1") && (query("equipped")==WIELD_RIGHT_HAND 
			||query("equipped")==WIELD_LEFT_HAND) && !me->is_busy())
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
/*
const char * hit_ob(CChar *me, CChar *victim, LONG damage_bonus)
{
	if(random(100/query("apply/jisuei"))==1)
	{
		DTItemList * list = victim->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(obj->is_character()) continue; 
			if(obj->query("baobei")!=1 && obj->query("equipped")==WIELD_ARMOR)
			{
				destruct(obj);
				message_vision("$HIRֻ�����顱��һ����$N���ɵ���ʹ���ѣ�ȴԭ���ǿ��ױ������ˡ�",victim);
				break;
			}
		}
	}
	return 0;
}
*/
EQUIP_END;



